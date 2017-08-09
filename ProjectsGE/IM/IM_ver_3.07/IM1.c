#include "math.h"     // математические функции
#include "PACRXPlc.h" //процедуры для контроллера
#include "Structs.h"  //Структура
#include "defvars.h"; 

float TSCAN;
	

//******************************************* Катушка Coil ***************************************************	
T_BOOLEAN Coil(T_BOOLEAN IN)
{
T_BOOLEAN out;
if (IN == 1) out= 1;
else out= 0;
return out;
}

//******************************************* Timer ***************************************************
//Таймер 
T_BOOLEAN Timer(T_REAL32 *Time, T_REAL32 Ust)
{
T_BOOLEAN out;
		if (*Time < Ust)
			{
			out= 0;
			*Time= *Time + TSCAN;
			}
		else
			out= 1;
return out;
}


//******************************************* main ***************************************************
void GefMain(IM, iTSCAN, ON_IMIT)
IM_STR *IM;
T_REAL32 *iTSCAN;
T_WORD *ON_IMIT;


{

T_BOOLEAN Rep_ON, Rep_OF, Tmax_ON, Tmax_OF, u_notMove_ON, u_notMove_OF, u_notON, u_notOF;
T_BOOLEAN Press_ON, Press_OF;
T_BOOLEAN IM_0_1 = 0, IM_1_1 = 0, IM_c1_1 = 0, IM_1_2 = 0, IM_c1_2 = 0, IM_2_1 = 0, IM_2_2 = 0;

//Версия программы
ST_Ver = 3.07;

ALG_ON_IMIT = Coil(*ON_IMIT);

//Сброс массива ошибок
PS_ERR[0] = 0;
PS_ERR[1] = 0;

//--------------- ошибки конфигурирования ------------------------------------
//Значение уставки "Время между подачей повторных команд" (T_Block) мало
if (CFG_T_Block == 0) 
	PS_ERR[0] |= (1<<1);
	
//Значение уставки "Время контроля цепей управления" (T_KCU) не корректно
if ((CFG_T_KCU == 0) || (CFG_T_KCU > CFG_T_NotCO) ||(CFG_T_KCU > CFG_T_Alarm))
	PS_ERR[0] |= (1<<2);

//Значение уставки "Время формирования сигнала "нестрагивание" (T_NotMove) не корректно
if ((CFG_T_NotMove == 0) || (CFG_T_NotMove > CFG_T_NotCO) || (CFG_T_NotMove > CFG_T_Alarm))
	PS_ERR[0] |= (1<<3);
	
//Значение уставки "Время формирования сигналов "не открыт, не закрыт" (T_NotCO) не корректно
if ((CFG_T_NotCO == 0) || (CFG_T_NotCO < CFG_T_NotMove) || (CFG_T_NotCO > CFG_T_Alarm))
	PS_ERR[0] |= (1<<4);

//Значение уставки таймера на перестановку (T_Alarm) мало
if ((CFG_T_Alarm == 0) || (CFG_T_Alarm < CFG_T_NotCO) || (CFG_T_Alarm < CFG_T_NotMove) || (CFG_T_Alarm < CFG_T_KCU))
	PS_ERR[0] |= (1<<5);
	
// ------------------------------------------------------------------------------	
	
if (!CFG_Disable)
	{
	//присваиваем вход глобальной переменной
	TSCAN= *iTSCAN;
	
	

	ST_TYPE_IM = CFG_TYPE_IM;
	switch (CFG_TYPE_IM)
		{
		case 1: // 0x1
			//имитируем концевики
			DI_ON = DO_ON;
			DI_OF = !DI_ON;
			IM_0_1 = 1;
			break;
		
		case 2: // 1x1	(концевик - открыто)
			//имитируем концевик закрыто
			DI_OF = !DI_ON;
			IM_1_1 = 1;
			break;

		case 3: // c1x1 (концевик - закрыто)
			//имитируем концевик открыто
			DI_ON = !DI_OF;
			IM_c1_1 = 1;
			break;

		case 4: // 1x2	(концевик - открыто)
			//имитируем концевик закрыто
			DI_OF = !DI_ON;
			IM_1_2 = 1;
			break;
		
		case 5: // с1x2 (концевик - закрыто)
			//имитируем концевик открыто
			DI_ON = !DI_OF;
			IM_c1_2 = 1;
			break;

		case 6: // 2x1	
			IM_2_1 = 1;
			break;
		
		case 7: // 2x2
			IM_2_2 = 1;
			break;	
		default:
			//выставить бит "не выбран тип блока" 
			//IM->PS.ERR[0] |= (1);
			PS_ERR[0] |= (1);
		}	//swith (CFG_TYPE)

		
	//Контроль исправности концевиков
	//Если (нет МУК и одновременно оба концевика в 1) или (МУК и одновременно оба концевика в 0 и тип ИМ с 2-мя концевиками) то фолт
	if ((!CFG_MUK && DI_ON && DI_OF) || (CFG_MUK && !DI_ON && !DI_OF && (IM_2_1 || IM_2_2)))
		PS_KV_FLT= 1;
	//иначе нет фолта
	else
		PS_KV_FLT= 0;	
		
	//Если пришла команда автоматического управления, то вводим запрет ручного управления
	if (AVT_ON || AVT_OF)
		ALG_RU_Ban = 1;
	//Если ушла команда автоматического управления, то снимаем запрет ручного управления
	if ((!AVT_ON && TMP_AVT_ON) || (!AVT_OF && TMP_AVT_OF))
		ALG_RU_Ban = 0;

	//Если пришла команда автоматического управления или есть запрет ручного управления, то переводим систему в автоматический режим
	if ((AVT_ON != TMP_AVT_ON) || (AVT_OF != TMP_AVT_OF) || ALG_RU_Ban)
		BTN_RU = 0;
		
	//Если произошло переключение в автоматический режим или перешли на приоритет автоматического
	if ((!BTN_RU && ST_RUs && !CFG_PRIORITY_RU) || (!BTN_RU && !CFG_PRIORITY_RU&& TMP_PRIORITY_RU))
		{
		//то переводим в состояние которое было до перехода в ручной
		TMP_Open = Coil(TMP_AUpr);
		TMP_Close = Coil(!TMP_AUpr);
		}
		
	// ручное управление
	if (!TMP_MUpr)
		{
		// если (автоматический режим и есть команда открыть) или нажата кнопка открыть
		if ((!BTN_RU && AVT_ON) || BTN_ON)
			//то бит ручного управления в 1
			TMP_MUpr = 1;
		}
	else
		{
		// (если автоматический режим и есть команда закрыть) или нажата кнопка закрыть
		if ((!BTN_RU && AVT_OF) || BTN_OF)
			//то бит ручного управления в 1
			TMP_MUpr = 0;
		}
			
			
	// автоматическое управление
	if (!TMP_AUpr)
		{
		// если автоматический режим и есть команда открыть
		if (!BTN_RU && AVT_ON)
			//то бит автоматическое управления в 1
			TMP_AUpr = 1;
		}
	else
		{
	// если автоматический режим и есть команда закрыть 
		if (!BTN_RU && AVT_OF)
			//то бит автоматическое управления в 1
			TMP_AUpr = 0;
		}


	if (!TMP_AVT_ON 
					|| (AVT_ON && !AVT_OF)) //приоритет последней команды
		{
		// если (автоматический режим и есть команда открыть) или (ручной режим и нажата кнопка открыть)
		if ((!BTN_RU && AVT_ON) || (BTN_RU && BTN_ON))
			{
			TMP_Open = 1;
			TMP_Close = 0;
			}
		}

	if (!TMP_AVT_OF 
					|| (AVT_OF && !AVT_ON))	 //приоритет последней команды
		{
		// если (автоматический режим и есть команда закрыть) или (ручной режим и нажата кнопка закрыть)
		if ((!BTN_RU && AVT_OF) || (BTN_RU && BTN_OF))
			{
			TMP_Open = 0;
			TMP_Close = 1;	
			}
		}

	//Команда "Стоп"
	if (BTN_STOP && BTN_RU && (IM_1_2 || IM_c1_2 || IM_2_2))
		{
		TMP_Open = 0;
		TMP_Close = 0;
		}
		
	//Таймер повтора команды открытия
	if (!DO_ON)		
		TMP_T_Block_ON_EN = Timer(&TMP_T_Block_ON, CFG_T_Block);
	else
		{
		TMP_T_Block_ON_EN = 0;
		TMP_T_Block_ON = 0;	
		}	
		
	//Таймер повтора команды закрытия
	if (!DO_OF)		
		TMP_T_Block_OF_EN = Timer(&TMP_T_Block_OF, CFG_T_Block);
	else
		{
		TMP_T_Block_OF_EN = 0;
		TMP_T_Block_OF = 0;	
		}	

	// Повтор команды открытия разрешен
	Rep_ON = Coil (TMP_T_Block_ON_EN && BTN_ON && (PS_notON || PS_notMove_ON || PS_SPOF));
	// Повтор команды закрытия разрешен
	Rep_OF = Coil (TMP_T_Block_OF_EN && BTN_OF && (PS_notOF || PS_notMove_OF || PS_SPON));	
		
	//Формирование сигнала "Отказ открытия"
	if (TMP_Open && !Rep_ON)	
		Tmax_ON = Timer(&TMP_T_Move_ON, CFG_T_Alarm);
	else
		{
		Tmax_ON = 0;
		TMP_T_Move_ON = 0;	
		}		
		
	//Формирование сигнала "Отказ закрытия"
	if (TMP_Close && !Rep_OF)	
		Tmax_OF = Timer(&TMP_T_Move_OF, CFG_T_Alarm);
	else
		{
		Tmax_OF = 0;
		TMP_T_Move_OF = 0;	
		}			
		
	// формирование условия для сигнала "не страгивание на открытие"	
	u_notMove_ON = Coil(TMP_Open && !PS_FLT && !DI_ON && (TMP_T_Move_ON >= CFG_T_NotMove));
	// формирование сигнала "не страгивание на открытие"
	PS_notMove_ON = Coil(DI_OF && u_notMove_ON);

	// формирование условия для сигнала "не страгивание на закрытие"	
	u_notMove_OF = Coil(TMP_Close && !PS_FLT && !DI_OF && (TMP_T_Move_OF >= CFG_T_NotMove));
	// формирование сигнала "не страгивание на закрытие"
	PS_notMove_OF = Coil(DI_ON && u_notMove_OF);
		
		
	// формирование условия для сигнала "не открыт"		
	u_notON	= Coil(TMP_Open && (TMP_T_Move_ON >= CFG_T_NotCO));
	// формирование сигнала "не открыт"		
	PS_notON = Coil(TMP_Open && !DI_ON && u_notON && !PS_SPOF);

	// формирование условия для сигнала "не закрыт"		
	u_notOF	= Coil(TMP_Close && (TMP_T_Move_OF >= CFG_T_NotCO));
	// формирование сигнала "не закрыт"		
	PS_notOF = Coil(TMP_Close && !DI_OF && u_notOF && !PS_SPON);	
		
	// Дожим на открытие	
	if (TMP_Open && DI_ON)	
		TMP_T_Press_ON_EN = Timer(&TMP_T_Press_ON, CFG_T_Press);
	else
		{
		TMP_T_Press_ON_EN = 0;
		TMP_T_Press_ON = 0;	
		}	
	Press_ON = Coil(TMP_T_Press_ON_EN);

	// Дожим на закрытие	
	if (TMP_Close && DI_OF)	
		TMP_T_Press_OF_EN = Timer(&TMP_T_Press_OF, CFG_T_Press);
	else
		{
		TMP_T_Press_OF_EN = 0;
		TMP_T_Press_OF = 0;	
		}	
	Press_OF = Coil(TMP_T_Press_OF_EN);	
		
	//формирование условия для сигнала "самопроизвольное закрытие"		
	if (TMP_Open && Press_ON && Tmax_ON) 
		TMP_u_SPOF = 1;
	//Снятие условия для сигнала "самопроизвольное закрытие"	
	if (TMP_Close)	
		TMP_u_SPOF = 0; 
	//формирование сигнала "самопроизвольное закрытие"		
	PS_SPOF	= Coil(TMP_Open && !DI_ON && TMP_u_SPOF);
		
	//формирование условия для сигнала "самопроизвольное открытие"		
	if (TMP_Close && Press_OF && Tmax_OF) 
		TMP_u_SPON = 1;
	//Снятие условия для сигнала "самопроизвольное открытие"	
	if (TMP_Open)	
		TMP_u_SPON = 0; 
	//формирование сигнала "самопроизвольное открытие"		
	PS_SPON	= Coil(TMP_Close && !DI_OF && TMP_u_SPON);
		
	
	if (IM_2_1 || IM_1_1 || IM_0_1 || IM_c1_1)
		{
		Press_ON = 0;
		Tmax_ON = 0;
		}
	
	//Открыть 	
	DO_ON = Coil(!ALG_DO_Ban && TMP_Open && !Press_ON && !Tmax_ON);
	//Форсировка дополнительного выхода для открытия
	if (CFG_ONForceEN && DO_ON)
		{
		TMP_T_Force_ON_EN = Timer(&TMP_T_Force_ON, CFG_T_Force);
		DO_ONForce = !TMP_T_Force_ON_EN;
		}
	else
		{
		TMP_T_Force_ON_EN = 0;
		TMP_T_Force_ON = 0;
		DO_ONForce = 0;
		}
		
		
	//Закрыть 
	DO_OF = Coil(!ALG_DO_Ban && TMP_Close && !Press_OF && !Tmax_OF);
	//Форсировка дополнительного выхода для закрытия
	if (CFG_OFForceEN && DO_OF)
		{
		TMP_T_Force_OF_EN = Timer(&TMP_T_Force_OF, CFG_T_Force);
		DO_OFForce = !TMP_T_Force_OF_EN;
		}
	else
		{
		TMP_T_Force_OF_EN = 0;
		TMP_T_Force_OF = 0;
		DO_OFForce = 0;
		}

		
	//Контроль цепей управления открытия
	//Если включен контроль цепей открытия и тип ИМ с концевиком "открыт", то
	if (CFG_KCU_ON_EN && (IM_1_1 || IM_1_2 || IM_2_1 || IM_2_2))
		{
		//Если тип контроля КЦУ по входу который всегда в 1
		if (CFG_TYPE_KCU)
			//Если нет на входе КЦУ 1
			if (!DI_KCU_ON)
				//запускаем таймер и выдаем фолт
				PS_KCU_ON_FLT= Timer(&TMP_T_KCU_ON, CFG_T_KCU);
			else
				{
				//иначе сброс фолта и таймера
				PS_KCU_ON_FLT= 0;
				TMP_T_KCU_ON = 0;
				}
		//Если тип контроля КЦУ по входу у которого DI = 0 при DO =1 и DI = 1 при DO =0
		else
			// если DI = 0 при DO =1 или DI = 1 при DO = 0
			if ((DI_KCU_ON && DO_ON) || (!DI_KCU_ON && !DO_ON && !DO_OF))
				PS_KCU_ON_FLT= Timer(&TMP_T_KCU_ON, CFG_T_KCU);
			else
				{
				PS_KCU_ON_FLT= 0;
				TMP_T_KCU_ON = 0;
				}
		}
	//Если выключен контроль цепей открытия, то сброс ПС
	else
		PS_KCU_ON_FLT= 0;


	//Контроль цепей управления закрытия
	//Если включен контроль цепей закрытия и тип ИМ с концевиком "закрыт", то
	if (CFG_KCU_OF_EN && (IM_c1_1 || IM_c1_2 || IM_2_1 || IM_2_2))
		{
		//Если тип контроля КЦУ по входу который всегда в 1
		if (CFG_TYPE_KCU)
			//Если нет на входе КЦУ 1
			if (!DI_KCU_OF)
				//запускаем таймер и выдаем фолт
				PS_KCU_OF_FLT= Timer(&TMP_T_KCU_OF, CFG_T_KCU);
			else
				{
				//иначе сброс фолта
				PS_KCU_OF_FLT= 0;
				TMP_T_KCU_OF = 0;
				}
		//Если тип контроля КЦУ по входу у которого DI = 0 при DO =1 и DI = 1 при DO =0
		else
			// если DI = 0 при DO =1 или DI = 1 при DO = 0
			if ((DI_KCU_OF && DO_OF) || (!DI_KCU_OF && !DO_OF && !DO_ON))
				PS_KCU_OF_FLT= Timer(&TMP_T_KCU_OF, CFG_T_KCU);
			else
				{
				PS_KCU_OF_FLT= 0;
				TMP_T_KCU_OF = 0;
				}
		}
	else
	//Если выключен контроль цепей закрытия, то сброс ПСelse
		PS_KCU_OF_FLT= 0;


	// ---------------------------------------------------- Имитатор ----------------------------------------

	//Если включен имитатор
	if (ALG_ON_IMIT) 
		{
		//Если пришла команда включить имитатор, то 
		if (!TMP_ON_IMIT)
			{
			//Если последняя команда было открыть
			if (TMP_AUpr)
				{
				//имитируем состояние открыто
				DI_ON= 1;
				DI_OF= 0;
				}
			//Если последняя команда было закрыть
			else
				{
				//имитируем состояние закрыто
				DI_ON= 0;
				DI_OF= 1;
				}
			}

		
		//Чтобы не было фолта по КЦУ
		DI_KCU_ON= 1;
		DI_KCU_OF= 1;
		//если есть команда открыть, то запускаем Таймер 
		if (DO_ON) 
			TMP_T_Imit_ON_EN= Timer(&TMP_T_Imit_ON, CFG_T_Imit);
		else
			{
			TMP_T_Imit_ON_EN = 0;
			TMP_T_Imit_ON= 0;
			}
			
		//если есть команда закрыть, то запускаем Таймер 
		if (DO_OF) 
			TMP_T_Imit_OF_EN= Timer(&TMP_T_Imit_OF, CFG_T_Imit);
		else
			{
			TMP_T_Imit_OF_EN = 0;
			TMP_T_Imit_OF= 0;
			}			

		//Если открываем
		if (DO_ON)
			{
			//Переключаем для контроля цепи 
			if (!CFG_TYPE_KCU) 
				DI_KCU_ON= 0;
				
			//Если время больше 0,5 сек, то снять концевик "закрыт"
			if (TMP_T_Imit_ON >= 0.5)
				DI_OF= 0;
			
			//Если время вышло, то включить концевик "открыт"
			if (TMP_T_Imit_ON_EN) 
				DI_ON= 1;
			}
		else
			//Переключаем для контроля цепи если не открываем
			DI_KCU_ON= 1;
		
		//Если закрываем
		if (DO_OF)
			{
			//Переключаем для контроля цепи 
			if (!CFG_TYPE_KCU) 
				DI_KCU_OF= 0;
			
			//Если время больше 0,5 сек, то снять концевик "открыт"
			if (TMP_T_Imit_OF >= 0.5)
				DI_ON= 0;

			//Если время вышло, то включить концевик "закрыт"
			if (TMP_T_Imit_OF_EN)
				DI_OF= 1;
			}
		else
			//Переключаем для контроля цепи если не закрываем
			DI_KCU_OF= 1;
			
		} //if (ALG_ON_IMIT) 
		
		//запоминаем текущее значение 
		
		

			
	//Наработка
	if (DI_ON)		
		{
		ST_Narab += (TSCAN / 3600);
		//Наработка
		if (!TMP_DI_ON)
			ST_Num ++;
		}
		
	//Сброс наработки	
	if (CFG_NarabReset)
		{
		ST_Narab = 0;
		ST_Num = 0;
		CFG_NarabReset = 0;
		}
	
	//ПСы
	PS_M_Mufft = Coil(DI_M_Mufft);
	PS_Vibr = Coil(DI_Vibr);
	PS_Loil = Coil(DI_Loil);
	PS_U_OF = Coil(DI_U_OF);
	PS_Poil = Coil(DI_Poil);
		
	//запоминаем текущее значение входа
	TMP_AVT_ON = Coil(AVT_ON);
	TMP_AVT_OF = Coil(AVT_OF);
	TMP_ON_IMIT = Coil(ALG_ON_IMIT);
	TMP_DI_ON = Coil(DI_ON);
	TMP_PRIORITY_RU = Coil(CFG_PRIORITY_RU);
}
//если блок выключен, то снимаем все сигналы
else //if (CFG_Disable)
	{
	if (ALG_ON_IMIT)
		{
		DI_ON = 0; DI_OF = 0; 
		}
	DO_ON = 0; DO_OF = 0;
	PS_notMove_ON = 0; PS_notMove_OF = 0; PS_KCU_ON_FLT = 0; PS_KCU_OF_FLT = 0;
	PS_notON = 0; PS_notOF = 0; PS_M_Mufft = 0; PS_SPON =0; PS_SPOF = 0; PS_KV_FLT = 0;
	}
	
//Обобщенный сигнал аварии
if (PS_notMove_ON || PS_notMove_OF || PS_KCU_ON_FLT || PS_KCU_OF_FLT || 
	PS_notON || PS_notOF || PS_M_Mufft || PS_SPON || PS_SPOF || PS_KV_FLT ||
	PS_Vibr || PS_Loil || PS_U_OF || PS_Poil || (PS_ERR[0]>0) || (PS_ERR[1]>0))
		PS_FLT = 1;
else
		PS_FLT = 0;

//Если тип ИМ с одним выходом, то блокируем второй выход
if (IM_2_1 || IM_1_1 || IM_0_1 || IM_c1_1) 
	DO_OF = 0;	// ---------------------------------------		
		
//для HMI
ST_DI_ON = Coil(DI_ON);
ST_DI_OF = Coil(DI_OF);
ST_FLT = Coil(PS_FLT);
ST_DO_ON = Coil(DO_ON);
ST_DO_OF = Coil(DO_OF);
//взводим флаг ручного режима
ST_RUs = Coil(BTN_RU);
//Перемещение механизма
ST_Move = Coil((!CFG_MUK && !DI_ON && !DI_OF) || (CFG_MUK && DI_ON && DI_OF) || DI_Move);

//Сброс кнопок
BTN_OF = 0;
BTN_ON = 0;
BTN_STOP = 0;


}
