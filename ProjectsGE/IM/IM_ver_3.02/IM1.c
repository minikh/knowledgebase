#include "math.h"     // математические функции
#include "PACRXPlc.h" //процедуры для контроллера
#include "Structs.h"  //Структура

float TSCAN;
	
//Дискретные входы				
#define	DI_ON			IM->DI.ON
#define	DI_OF			IM->DI.OF
#define	DI_KCU_ON			IM->DI.KCU_ON
#define	DI_KCU_OF			IM->DI.KCU_OF
#define	DI_Move			IM->DI.Move
#define	DI_M_Mufft			IM->DI.M_Mufft
#define	DI_Vibr			IM->DI.Vibr
#define	DI_Loil			IM->DI.Loil
#define	DI_U_OF			IM->DI.U_OF
#define	DI_Poil			IM->DI.Poil
				
				
//Дискретные выходы				
#define	DO_ON			IM->DO.ON
#define	DO_OF			IM->DO.OF
#define	DO_STOP			IM->DO.STOP
#define	DO_ONForce			IM->DO.ONForce
#define	DO_OFForce			IM->DO.OFForce
				
				
//Команды автоматические				
#define	AVT_ON			IM->AVT.ON
#define	AVT_OF			IM->AVT.OF
				
				
//Кнопки				
#define	BTN_ON			IM->BTN.ON
#define	BTN_OF			IM->BTN.OF
#define	BTN_RU			IM->BTN.RU
#define	BTN_STOP			IM->BTN.STOP
				
				
//Команды из алгоритма				
#define	ALG_ON_IMIT			IM->ALG.ON_IMIT
#define	ALG_DO_Ban			IM->ALG.DO_Ban
#define	ALG_RU_Ban			IM->ALG.RU_Ban
				
//Настройки				
#define	CFG_Disable			IM->CFG.Disable
#define	CFG_T_Alarm			IM->CFG.T_Alarm
#define	CFG_T_KCU			IM->CFG.T_KCU
#define	CFG_T_NotMove			IM->CFG.T_NotMove
#define	CFG_T_NotCO			IM->CFG.T_NotCO
#define	CFG_T_Press			IM->CFG.T_Press
#define	CFG_T_Force			IM->CFG.T_Force
#define	CFG_T_Block			IM->CFG.T_Block
#define	CFG_T_Imit			IM->CFG.T_Imit
#define	CFG_TYPE_KCU			IM->CFG.TYPE_KCU
#define	CFG_Come_Back			IM->CFG.Come_Back
#define	CFG_Init			IM->CFG.Init
#define	CFG_MUK			IM->CFG.MUK
#define	CFG_ONForceEN			IM->CFG.ONForceEN
#define	CFG_OFForceEN			IM->CFG.OFForceEN
#define	CFG_KCU_ON_EN			IM->CFG.KCU_ON_EN
#define	CFG_KCU_OF_EN			IM->CFG.KCU_OF_EN
#define	CFG_NarabReset			IM->CFG.NarabReset
#define	CFG_TYPE_IM			IM->CFG.TYPE_IM
#define	CFG_TYPE_CMD			IM->CFG.TYPE_CMD
#define	CFG_PRIORITY_RU			IM->CFG.PRIORITY_RU
				
				
				
				
//Статусы				
#define	ST_Ver			IM->ST.Ver
#define	ST_Narab			IM->ST.Narab
#define	ST_FLT			IM->ST.FLT
#define	ST_RUs			IM->ST.RUs
#define	ST_Move			IM->ST.Move
#define	ST_DI_ON			IM->ST.DI_ON
#define	ST_DI_OF			IM->ST.DI_OF
#define	ST_DO_ON			IM->ST.DO_ON
#define	ST_DO_OF			IM->ST.DO_OF
				
				
//Ошибки				
#define	PS_FLT			IM->PS.FLT
#define	PS_M_Mufft			IM->PS.M_Mufft
#define	PS_notON			IM->PS.notON
#define	PS_notOF			IM->PS.notOF
#define	PS_SPON			IM->PS.SPON
#define	PS_SPOF			IM->PS.SPOF
#define	PS_KV_FLT			IM->PS.KV_FLT
#define	PS_KCU_ON_FLT			IM->PS.KCU_ON_FLT
#define	PS_KCU_OF_FLT			IM->PS.KCU_OF_FLT
#define	PS_notMove_ON			IM->PS.notMove_ON
#define	PS_notMove_OF			IM->PS.notMove_OF
#define	PS_ERR			IM->PS.ERR
				
//Служебная область				
#define	TMP_T_Alarm			IM->TMP.T_Alarm
#define	TMP_T_Alarm_EN			IM->TMP.T_Alarm_EN
#define	TMP_T_KCU_ON			IM->TMP.T_KCU_ON
#define	TMP_T_KCU_OF			IM->TMP.T_KCU_OF
#define	TMP_T_NotMove			IM->TMP.T_NotMove
#define	TMP_T_NotMove_EN			IM->TMP.T_NotMove_EN
#define	TMP_T_NotCO			IM->TMP.T_NotCO
#define	TMP_T_NotCO_EN			IM->TMP.T_NotCO_EN
#define	TMP_T_Press_ON			IM->TMP.T_Press_ON
#define	TMP_T_Press_OF			IM->TMP.T_Press_OF
#define	TMP_T_Press_ON_EN			IM->TMP.T_Press_ON_EN
#define	TMP_T_Press_OF_EN			IM->TMP.T_Press_OF_EN
#define	TMP_T_Force			IM->TMP.T_Force
#define	TMP_T_Force_EN			IM->TMP.T_Force_EN
#define	TMP_T_Block_ON			IM->TMP.T_Block_ON
#define	TMP_T_Block_OF			IM->TMP.T_Block_OF
#define	TMP_T_Block_ON_EN			IM->TMP.T_Block_ON_EN
#define	TMP_T_Block_OF_EN			IM->TMP.T_Block_OF_EN
#define	TMP_T_Imit			IM->TMP.T_Imit
#define	TMP_T_Imit_EN			IM->TMP.T_Imit_EN
#define	TMP_AVT_ON			IM->TMP.AVT_ON1
#define	TMP_AVT_OF			IM->TMP.AVT_OF1
#define	TMP_MUpr			IM->TMP.MUpr
#define	TMP_AUpr			IM->TMP.AUpr
#define	TMP_T_Move_ON			IM->TMP.T_Move_ON
#define	TMP_T_Move_OF			IM->TMP.T_Move_OF
#define	TMP_T_Move_ON_EN			IM->TMP.T_Move_ON_EN
#define	TMP_T_Move_OF_EN			IM->TMP.T_Move_OF_EN
#define	TMP_ON_IMIT			IM->TMP.ON_IMIT
#define	TMP_MR			IM->TMP.MR
#define	TMP_MB			IM->TMP.MB
#define	TMP_Open			IM->TMP.Open
#define	TMP_Close			IM->TMP.Close
#define	TMP_u_SPON			IM->TMP.u_SPON
#define	TMP_u_SPOF			IM->TMP.u_SPOF






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
void GefMain(IM, iTSCAN)
IM_STR *IM;
float *iTSCAN;


{
T_BOOLEAN Rep_ON, Rep_OF, Tmax_ON, Tmax_OF, u_notMove_ON, u_notMove_OF, u_notON, u_notOF;
T_BOOLEAN Press_ON, Press_OF;

//Версия программы
ST_Ver = 3.02;
//присваиваем вход глобальной переменной
TSCAN= *iTSCAN;

switch (CFG_TYPE_IM)
	{
	
	case 1: // 0x1
		DI_ON = DO_ON;
		DI_OF = !DI_ON;
		break;
	
	case 2: // 1x1
		DI_OF = !DI_ON;
		break;
	
	case 3: // 1x2
		DI_OF = !DI_ON;
		break;
	
	case 4: // 2x1
		
		break;
	
	case 5: // 2x2
		
		break;	
	}	//swith (CFG_TYPE)

//Если пришла команда автоматического управления, то вводим запрет ручного управления
ALG_RU_Ban = Coil(AVT_ON || AVT_OF);

//Если пришла команда автоматического управления, то переводим систему в автоматический режим
if ((AVT_ON != TMP_AVT_ON) || (AVT_OF != TMP_AVT_OF))
	BTN_RU = 0;

//взводим флаг ручного режима
ST_RUs = Coil(BTN_RU);
	
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

//Флаг отктыть / закрыть
//Open = Coil((BTN_RU && TMP_MUpr) || (!BTN_RU && TMP_AUpr));


if (!TMP_AVT_ON || (AVT_ON && !AVT_OF)) 
	{
	// если (автоматический режим и есть команда открыть) или (ручной режим и нажата кнопка открыть)
	if ((!BTN_RU && AVT_ON) || (BTN_RU && BTN_ON))
		{
		TMP_Open = 1;
		TMP_Close = 0;
		}
	}

if (!TMP_AVT_OF || (AVT_OF && !AVT_ON))	
	{
	// если (автоматический режим и есть команда закрыть) или (ручной режим и нажата кнопка закрыть)
	if ((!BTN_RU && AVT_OF) || (BTN_RU && BTN_OF))
		{
		TMP_Open = 0;
		TMP_Close = 1;	
		}
	}

if (BTN_STOP && ST_RUs)
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
u_notMove_ON = Coil(TMP_Open && (TMP_T_Move_ON >= CFG_T_NotMove));
// формирование сигнала "не страгивание на открытие"
PS_notMove_ON = Coil(TMP_Open && DI_OF && u_notMove_ON);

// формирование условия для сигнала "не страгивание на закрытие"	
u_notMove_OF = Coil(TMP_Close && (TMP_T_Move_OF >= CFG_T_NotMove));
// формирование сигнала "не страгивание на закрытие"
PS_notMove_OF = Coil(TMP_Close && DI_ON && u_notMove_OF);
	
	
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
	
//Открыть 
DO_ON = Coil(TMP_Open && !Press_ON && !Tmax_ON && !ALG_DO_Ban);

//Закрыть 
DO_OF = Coil(TMP_Close && !Press_OF && !Tmax_OF && !ALG_DO_Ban);

	

//Контроль исправности концевиков
//Если одновременно оба концевика в 1 то фолт
if (DI_ON && DI_OF)
	PS_KV_FLT= 1;
//иначе нет фолта
else
	PS_KV_FLT= 0;


//Контроль цепей управления открытия
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

//Контроль цепей управления закрытия
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



//Имитатор

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
	//если есть команда открыть или закрыть, то запускаем Таймер 
	if (DO_ON || DO_OF) 
		TMP_T_Imit_EN= Timer(&TMP_T_Imit, CFG_T_Imit);
	else
		{
		TMP_T_Imit_EN = 0;
		TMP_T_Imit= 0;
		}

	//Если открываем
	if (DO_ON)
		{
		//Переключаем для контроля цепи 
		if (!CFG_TYPE_KCU) 
			DI_KCU_ON= 0;
			
		//Если время больше 0,5 сек, то снять концевик "закрыт"
		if (TMP_T_Imit >= 0.5)
			DI_OF= 0;
		
		//Если время вышло, то включить концевик "открыт"
		if (TMP_T_Imit_EN) 
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
		if (TMP_T_Imit >= 0.5)
			DI_ON= 0;

		//Если время вышло, то включить концевик "закрыт"
		if (TMP_T_Imit_EN)
			DI_OF= 1;
		}
	else
		//Переключаем для контроля цепи если не закрываем
		DI_KCU_OF= 1;
		
	} //if (ALG_ON_IMIT) 
	
	//запоминаем текущее значение 
	TMP_ON_IMIT = Coil(ALG_ON_IMIT);
	
//Обобщенный сигнал аварии
if (PS_notMove_ON || PS_notMove_OF || PS_KCU_ON_FLT || PS_KCU_OF_FLT || 
	PS_notON || PS_notOF || PS_M_Mufft || PS_SPON || PS_SPOF || PS_KV_FLT)
		{
		ST_FLT = 1;
		PS_FLT = 1;
		}
else
		{
		ST_FLT = 0;
		PS_FLT = 0;
		}
		
//запоминаем текущее значение входа
TMP_AVT_ON = Coil(AVT_ON);
TMP_AVT_OF = Coil(AVT_OF);
}
