


#include "PACRXPlc.h"
#include "math.h"
#include "data.h"//

//		Вспомогательные								//!! RF (1301)...RF(1499) 	РЕЗЕРВ
#define cycle				RF(1301)				//*Время цикла (в секундах)
#define Nst_Ust				RF(1303)				//*Уставка частоты свободной турбины
#define manual_setDOZ		RF(1305)				//*Ручное задание на дозатор
#define manual_setVNA		RF(1307)				//*Ручное задание на ВНА

//		Выходные аналоговые сигналы						// RF (1501)...RF(1599) 	РЕЗЕРВ
#define setDoz				RF(1501)				//*Заданние на дозатор 0...100%
#define set_VNA				RF(1503)				//*Задание на ВНА -50…5 угл. град.
#define Gt_tek				RF(1505)				//*Расход топлива на выходе из регулятора топлива
//		Расчетные (отфильтрованные) значения					
#define nvd					RF(1511)				//*Частота вращения ротора газогенератора после обработки в СВК
#define nvdNorm				RF(1513)				//*Приведенная частота вращения ротора газогенератора после обработки в СВК
#define nst					RF(1515)				//*Частота вращения ротора свободной турбины
#define Tvh					RF(1517)				//*Температура на входе в двигатель
#define Ttzap				RF(1519)				//*Полная температура газа за турбиной газогенератора на запуске –50…1000 ?С
#define Tt					RF(1521)				//*Полная температура газа за турбиной газогенератора
#define Tst					RF(1523)				//*Полная температура газа за свободной турбиной
#define Tpdtg	    		RF(1525)				//!!!Т топливного газа перед дозатором(-55...155 град С = -550...1550 и.е.)
#define Pkvd				RF(1527)				//*Давление воздуха за компрессором от СВК
#define Ptg					RF(1529)				//*Давление топливного газа перед СК
#define Ptgpd				RF(1531)				//*Давление топливного газа перед дозатором
#define Metka				RI(1539)				//*Метка контура
#define condition			RI(1541)				//*Состояние системы
#define HPTimer				RF(1543)				//**Таймер холодной прокрутки
#define startTimer			RF(1545)				//**Таймер времени запуска
#define heatTimer			RF(1547)				//**Таймер времени прогрева
#define coolTimer			RF(1549)				//**Таймер охлаждения двигателя
#define VibegGGTimer		RF(1551)				//Таймер времени выбега ГГ
#define VibegSTTimer		RF(1553)				//Таймер времени выбега СТ
#define	promTimer			RF(1555)				//Таймер промывки
/*
#define P2                  				RF(1557)         		 	//Расчетное давление топливного газа после дозатора
#define b                   				RF(1559)               			//Коэффициент для расчета Р2
#define K						RF(1561)				//Коэффициент для поправки по температуре и давлению топливного газа
#define fo						RF(1563)				//Поправочный коэффициент по давлению
*/
#define	nnd					RF(1565)				//Частота вращения ротора КНД после обработки в СВК
#define VibegKNDTimer		RF(1567)				//Таймер времени выбега КНД

#define measureVNA1 		RF(1011)				//Положение ВНА 1-ый датчик
#define posDOZ				RF(1009)				//Положение исполнительного элемента дозатора 0...100%
#define PgInStV    			RF(1087)				//Давление пускового газа перед СтВ 0...1.0 МПа
#define set_VNAr			RF(1569)

//		Уставки ограничительных контуров и контуров регулирования	//	RF (1601)...RF(1699) 	РЕЗЕРВ
#define	Gt_roz_ust			RF(1601)				//*Уставка расхода топливного газа в КС на розжиге
#define	dGt_ogr_zap_ust		RF(1603)				//*Уставка ограничения скорости увеличения расхода топливного газа на разгоне dGt
#define	Ttzap_ogr_ust       RF(1605)                //*Уставка прекращения запуска по предельной Т газа за ГГ, К
#define Pk_ogr_ust			RF(1607)				//*Уставка ограничения давления воздуха за компрессором
#define Ngg_MG_ust			RF(1609)				//*Уставка малого газа
#define Ngg_max_ust			RF(1611)				//*Уставка максимальных оборотов Nvd
#define Nst_ogr_ust			RF(1613)				//*Уставка ограничения максимального Nst 
//#define Tt_ogr_ust			RF(1615)				//*Уставка ограничения температуры газа за турбиной ГГ на режимах
#define Tst_ogr_ust			RF(1617)				//Уставка ограничения температуры газа за турбиной СТ на режимах
#define Gt_ogr_ust			RF(1619)				//*Уставка ограничения расхода на основных режимах
#define GtPk_ogr_ust		RF(1621)				//*Уставка ограничения Gt/Pк
#define KPV_OFF_ust			RF(1625)				//*Уставка закрытия КПВ
#define KPV_ON_ust			RF(1627)				//*Уставка открытия КПВ
#define KPG_OFF_ust			RF(1629)				//*Уставка закрытия КПГ и КПВЗ 
#define KPG_ON_ust			RF(1631)				//*Уставка открытия КПГ и КПВЗ 
#define Usk_ST_ust			RF(1633)				//*Уставка ускорения со стартером
#define Usk_ust				RF(1635)				//*Уставка ускорения без стартера
#define Gt_roz_min_ust		RF(1637)				//*Уставка начального расхода на розжиге
#define Gt_roz_max_ust		RF(1639)				//*Уставка конечного расхода на розжиге
//#define dGt_ogr_zap_ust		RF(1641)				//*dGt
#define Nnd_max_ust			RF(1641)				//*Уставка максимальной частоты вращения ротора НД
#define ZPV1_OFF_ust		RF(1643)				//*Уставка закрытия ЗПВ КНД 1-й группы 
#define ZPV1_ON_ust			RF(1645)				//*Уставка открытия ЗПВ КНД 1-й группы 
#define ZPV2_OFF_ust		RF(1647)				//*Уставка закрытия ЗПВ КНД 2-й группы
#define ZPV2_ON_ust			RF(1649)				//*Уставка открытия ЗПВ КНД 2-й группы 


//		Регулировки									//	RF (1939)...RF(1999) 	РЕЗЕРВ
#define Reg_Gt_RozN_u		RF(1901)				//Регулировка начального расхода на розжиге
#define Reg_Gt_RozK_u		RF(1903)				//Регулировка конечного расхода на розжиге
#define Reg_Gt_roz_u		RF(1905)				//*Регулировка расхода на розжиге
#define Reg_Usk_ST_u		RF(1907)				//Регулировка ускорения на запуске со стартером
#define Reg_Usk_u			RF(1909)				//Регулировка ускорения на запуске без стартера
#define Reg_dGt_ogr_zap_u	RF(1911)				//*Регулировка ограничения скорости увеличения расхода топливного газа на разгоне dGt
#define Reg_KPV_OFF_u		RF(1919)				//*Регулировка закрытия КПВ
#define Reg_KPV_ON_u		RF(1921)				//*Регулировка открытия КПВ
#define Reg_KPG_OFF_u		RF(1923)				//*Регулировка закрытия КПГ и КПВЗ
#define Reg_KPG_ON_u		RF(1925)				//*Регулировка открытия КПГ и КПВЗ
#define Reg_Gt_ogr_u		RF(1935)				//*Регулировка максимальной величины расхода топливного газа
#define Reg_GtPk_ogr_u  	RF(1937)				//*Регулировка ограничения Gt/Pk

//#define Reg_dG_Zap_u		RF(1943)				//Регулировка скорости изменения ограничения расхода на запуске
#define Reg_Nnd_Max_u		RF(1941)				//Регулировка максимальной частоты вращения ротора НД
#define Reg_ZPV1_OFF_u		RF(1943)				//Регулировка закрытия ЗПВ КНД 1-й группы
#define Reg_ZPV1_ON_u		RF(1945)				//Регулировка открытия ЗПВ КНД 1-й группы
#define Reg_ZPV2_OFF_u		RF(1947)				//Регулировка закрытия ЗПВ КНД 2-й группы
#define Reg_ZPV2_ON_u		RF(1949)				//Регулировка открытия ЗПВ КНД 2-й группы





//		Входные дискретные сигналы						// RF (3001)...RF(3050) 	РЕЗЕРВ
#define SK_OFF_tst			BIT_TST_M(3003)			//Стопорный клапан «Закрыт»

//		Управляющие команды							
#define externAO			BIT_TST_M(3701)			//*внешний сигнал АО
#define init_tst			BIT_TST_M(3702)			//*Инициализациа
#define init_clr			BIT_CLR_M(3702)			//*Инициализация
#define updateTun			BIT_TST_M(3703)			//*Обновление настроек
#define check				BIT_TST_M(3704)			//*Проверка защит
#define startHP				BIT_TST_M(3705)			//*команда старта ХП
#define start				BIT_TST_M(3706)			//*команда запуска двигателя
#define stop				BIT_TST_M(3707)			//*команда нормального останова
#define externDeblock		BIT_TST_M(3708)			//*внешняя команда деблокировки аварии
#define stabST_on			BIT_TST_M(3709)			//*Команда на включение стабилизации СТ (иначе стабилизация ГГ)!!!Отключено для 184 стенда
#define up					BIT_TST_M(3710)			//*Команда на увеличение режима
#define down				BIT_TST_M(3711)			//*Команда на снижение режима
#define maxReg				BIT_TST_M(3712)			//*Признак максимального режима
#define longZAP				0//BIT_TST_M(3736)			//*длинный запуск
#define up_VNA				BIT_TST_M(3713)			//*Команда поворота ВНА (вверх) 
#define down_VNA            BIT_TST_M(3714)			//*Команда поворота ВНА (вниз)
#define startProm			BIT_TST_M(3737)			//*команда Режим Промывка

//		Информационные сигналы							//	RF (3468)...RF(3500) 	РЕЗЕРВ
#define HP_set				BIT_SET_M(3451)			//*Установка флага "Холодная прокрутка идет"
#define HP_clr				BIT_CLR_M(3451)			//*Сброс флага "Холодная прокрутка идет"
#define HP_tst				BIT_TST_M(3451)			//*Проверка флага "Холодная прокрутка идет"

#define endHP_set			BIT_SET_M(3452)			//*Установка флага "Конец ХП"
#define endHP_clr			BIT_CLR_M(3452)			//*Сброс флага "Конец ХП" !
#define endHP_tst			BIT_TST_M(3452)			//*Проверка флага "Конец ХП"

#define notFire_set			BIT_SET_M(3453)			//*Установка флага "Нет розжига"
#define notFire_clr			BIT_CLR_M(3453)			//*Сброс флага "Нет розжига"
#define notFire_tst			BIT_TST_M(3453)			//*Проверка флага "Нет розжига"

#define notRateGG_set		BIT_SET_M(3454)			//*Установка флага "Нет разгона"
#define notRateGG_clr		BIT_CLR_M(3454)			//*Сброс флага "Нет разгона"
#define notRateGG_tst		BIT_TST_M(3454)			//*Проверка флага "Нет разгона"

#define TimeZapHigh_set		BIT_SET_M(3645)			//*Установка флага "Время запуска велико"
#define TimeZapHigh_clr		BIT_CLR_M(3645)			//*Сброс флага "Время запуска велико"
#define TimeZapHigh_tst		BIT_TST_M(3645)			//*Проверка флага "Время запуска велико"

#define startEngine_set		BIT_SET_M(3455)			//*Установка флага "Старт двигателя"
#define startEngine_clr		BIT_CLR_M(3455)			//*Сброс флага "Старт двигателя"
#define startEngine_tst		BIT_TST_M(3455)			//*Проверка флага "Старт двигателя"

#define engineStarted_set	BIT_SET_M(3456)			//*Установка флага "Двигатель работает"
#define engineStarted_clr	BIT_CLR_M(3456)			//*Сброс флага "Двигатель работает"
#define engineStarted_tst	BIT_TST_M(3456)			//*Проверка флага "Двигатель работает"

#define heat_set			BIT_SET_M(3457)			//*Установка флага "Прогрев"
#define heat_clr			BIT_CLR_M(3457)			//*Сброс флага "Прогрев"
#define heat_tst			BIT_TST_M(3457)			//*Проверка флага "Прогрев"

#define NO_set				BIT_SET_M(3458)			//*Установка флага нормальный останов идет
#define NO_clr				BIT_CLR_M(3458)			//*Сброс флага нормальный останов идет
#define NO_tst				BIT_TST_M(3458)			//*Проверка флага нормальный останов идет

#define firePresent_set		BIT_SET_M(3459)			//*Установка флага "Розжиг"
#define firePresent_clr		BIT_CLR_M(3459)			//*Сброс флага "Розжиг"
#define firePresent_tst		BIT_TST_M(3459)			//*Проверка флага "Розжиг"

#define redyStart_set		BIT_SET_M(3460)			//*Установка флага "Готовность к запуску"
#define redyStart_clr		BIT_CLR_M(3460)			//*Сброс флага "Готовность к запуску"
#define redyStart_tst		BIT_TST_M(3460)			//*Проверка флага "Готовность к запуску"

#define redyHP_set			BIT_SET_M(3461)			//*Установка флага "Готовность к ХП"
#define redyHP_clr			BIT_CLR_M(3461)			//*Сброс флага "Готовность к ХП"
#define redyHP_tst			BIT_TST_M(3461)			//*Проверка флага "Готовность к ХП"

#define readyClear_set		BIT_SET_M(3462)			//*Установка флага "Готовность к промывке"
#define readyClear_clr		BIT_CLR_M(3462)			//*Сброс флага "Готовность к промывке"
#define readyClear_tst		BIT_TST_M(3462)			//*Проверка флага "Готовность к промывке"

#define R_raskStV_set		BIT_SET_M(3463)			//*Установка флага "Раскрутка на стартере"
#define R_raskStV_clr		BIT_CLR_M(3463)			//*Сброс флага "Раскрутка на стартере"
#define R_raskStV_tst		BIT_TST_M(3463)			//*Проверка флага "Раскрутка на стартере"

#define R_fire_set			BIT_SET_M(3464)			//*Установка флага "Режим розжиг"
#define R_fire_clr			BIT_CLR_M(3464)			//*Сброс флага "Режим розжиг"
#define R_fire_tst			BIT_TST_M(3464)			//*Проверка флага "Режим розжиг"

#define R_rate_set			BIT_SET_M(3465)			//*Установка флага "Режим разгона"
#define R_rate_clr			BIT_CLR_M(3465)			//*Сброс флага "Режим разгона"
#define R_rate_tst			BIT_TST_M(3465)			//*Проверка флага "Режим разгона"

#define R_promGo_set		BIT_SET_M(3466)			//*Установка флага "Промывка идет"
#define R_promGo_clr		BIT_CLR_M(3466)			//*Сброс флага "Промывка идет"
#define R_promGo_tst		BIT_TST_M(3466)			//*Проверка флага "Промывка идет"

#define R_promEnd_set		BIT_SET_M(3467)			//*Установка флага "Конец Промывки"
#define R_promEnd_clr		BIT_CLR_M(3467)			//*Сброс флага "Конец Промывки"
#define R_promEnd_tst		BIT_CLR_M(3467)			//*Проверка флага "Конец Промывки"

#define R_kt_stabST_set		BIT_SET_M(3468)			//*Установка флага "Контур стабилизации оборотов СТ"
#define R_kt_stabST_clr		BIT_CLR_M(3468)			//*Сброс флага "Контур стабилизации оборотов СТ"

#define R_kt_heatMG_set		BIT_SET_M(3469)			//*Установка флага "Контур прогрева на минимальном режиме"
#define R_kt_heatMG_clr		BIT_CLR_M(3469)			//*Сброс флага "Контур прогрева на минимальном режиме"

#define R_kt_GG_set			BIT_SET_M(3470)			//*Установка флага "Контур стабилизации оборотов ГГ"
#define R_kt_GG_clr			BIT_CLR_M(3470)			//*Сброс флага "Контур стабилизации оборотов ГГ"

#define R_kt_ogrMG_set		BIT_SET_M(3471)			//*Установка флага "Контур ограничения nvd на минимальном режиме"
#define R_kt_ogrMG_clr		BIT_CLR_M(3471)			//*Сброс флага "Контур ограничения nvd на минимальном режиме"

#define R_kt_sbros_set		BIT_SET_M(3472)			//*Установка флага "Контур сброса на минимальный режим"
#define R_kt_sbros_clr		BIT_CLR_M(3472)			//*Сброс флага "Контур сброса на минимальный режим"

#define R_kt_down_set		BIT_SET_M(3473)			//*Установка флага "Контур ограничения приемистости снизу или кнопка "меньше""
#define R_kt_down_clr		BIT_CLR_M(3473)			//*Сброс флага "Контур ограничения приемистости снизу или кнопка "меньше""

#define R_kt_Nvdogr_up_set	BIT_SET_M(3474)			//*Установка флага "Контур ограничения Nvd сверху"
#define R_kt_Nvdogr_up_clr	BIT_CLR_M(3474)			//*Сброс флага "Контур ограничения Nvd сверху"

#define R_kt_Nstogr_down_set	BIT_SET_M(3475)		//*Установка флага "Контур ограничения Nst снизу"
#define R_kt_Nstogr_down_clr	BIT_CLR_M(3475)		//*Сброс флага "Контур ограничения Nst снизу"

#define R_kt_Nstogr_up_set	BIT_SET_M(3476)			//*Установка флага "Контур ограничения Nst сверху"
#define R_kt_Nstogr_up_clr	BIT_CLR_M(3476)			//*Сброс флага "Контур ограничения Nst сверху"

#define R_kt_n_point_set	BIT_SET_M(3477)			//*Установка флага "Контур n с точкой на запуске"
#define R_kt_n_point_clr	BIT_CLR_M(3477)			//*Сброс флага "Контур n с точкой на запуске"

#define R_kt_up_set			BIT_SET_M(3478)			//*Установка флага "Контур ограничения приемистости сверху или кнопка "больше""
#define R_kt_up_clr			BIT_CLR_M(3478)			//*Сброс флага "Контур ограничения приемистости сверху или кнопка "больше""

#define R_kt_fire_set		BIT_SET_M(3479)			//*Установка флага "Контур розжига"
#define R_kt_fire_clr		BIT_CLR_M(3479)			//*Сброс флага "Контур розжига"

#define R_kt_ogrGt_zap_set	BIT_SET_M(3480)			//*Установка флага "Контур ограничения расхода топлива на запуске"
#define R_kt_ogrGt_zap_clr	BIT_CLR_M(3480)			//*Сброс флага "Контур ограничения расхода топлива на запуске"

#define R_kt_ogrdGt_zap_set	BIT_SET_M(3481)			//*Установка флага "Контур ограничения скорости увеличения расхода топлива на запуске"
#define R_kt_ogrdGt_zap_clr	BIT_CLR_M(3481)			//*Сброс флага "Контур ограничения скорости увеличения расхода топлива на запуске"

#define R_kt_ogrGt_osn_set	BIT_SET_M(3482)			//*Установка флага "Контур ограничения расхода топлива на основных режимах"
#define R_kt_ogrGt_osn_clr	BIT_CLR_M(3482)			//*Сброс флага "Контур ограничения расхода топлива на основных режимах"

#define R_kt_Pk_set			BIT_SET_M(3483)			//*Установка флага "Контур ограничения Pк"
#define R_kt_Pk_clr			BIT_CLR_M(3483)			//*Сброс флага "Контур ограничения Pк"

//#define R_kt_Tt_set		BIT_SET_M(3484)			//*Установка флага "Контур ограничения Tt"
//#define R_kt_Tt_clr		BIT_CLR_M(3484)			//*Сброс флага "Контур ограничения Tt"

#define R_kt_Tst_set		BIT_SET_M(3484)			//*Установка флага "Контур ограничения Nnd"
#define R_kt_Tst_clr		BIT_CLR_M(3484)			//*Сброс флага "Контур ограничения  Nnd

#define R_kt_GtPk_set		BIT_SET_M(3485)			//*Установка флага "Контур ограничения Gt/Pk"
#define R_kt_GtPk_clr		BIT_CLR_M(3485)			//*Сброс флага "Контур ограничения Gt/Pk"

#define R_kt_Nndogr_up_set		BIT_SET_M(3486)			//*Установка флага "Контур ограничения Nnd"
#define R_kt_Nndogr_up_clr		BIT_CLR_M(3486)			//*Сброс флага "Контур ограничения  Nnd


//Контур ого\о

#define downDI				0 //BIT_TST_M(3023)			//*Команда на уменьшение режима дискретный сигнал - физическая линия 
                                                                      
//Коэффициенты
//#define Kp_Tt			RF(1271)				//Коэффициент пропорциональный контура Тт
#define Kp_Tst			RF(1281)				//Коэффициент пропорциональный контура Тст
#define Kp_Pk			RF(1273)				//Коэффициент пропорциональный контура Pk
#define K1_st			RF(1275)				//Коэффициент 1 СТ
#define K2_st			RF(1277)				//Коэффициент 2 СТ
#define K3_st			RF(1279)				//Коэффициент 3 СТ
#define Kp_dop			RF(1793)				//Дополнительный коэфициент пропорциональный Nvd
#define Ki_dop			RF(1795)				//Дополнительный коэфициент интегральный Nvd

//		Выходные дискретные сигналы топливного регулятора		//	RF (3410)...RF(3450) 	РЕЗЕРВ
#define setSK_ON_set		BIT_SET_M(3401)			//*Открыть СК
#define setSK_ON_clr		BIT_CLR_M(3401)			//*Открыть СК
#define setSK_ON_tst		BIT_TST_M(3401)			//*Открыть СК

#define KPV_ON				BIT_SET_M(3402)			//*Открыть КПВ
#define KPV_OFF				BIT_CLR_M(3402)			//*Закрыть КПВ
#define KPV_ON_tst	 		BIT_TST_M(3402)			//*Открыть/Закрыть  КПВ

#define KPG_ON				BIT_SET_M(3403)			//*Открыть КПГ и КПВЗ
#define KPG_OFF				BIT_CLR_M(3403)			//*Закрыть КПГ и КПВЗ
#define KPG_ON_tst			BIT_TST_M(3403)			//*Открыть/Закрыть  КПГ и КПВЗ

#define Nstart_set				BIT_SET_M(3404)			//*Включить электростартер
#define Nstart_clr				BIT_CLR_M(3404)			//*Выключить электростартер
#define Nstart_tst				BIT_TST_M(3404)			//*Включен ли электростартер

#define PNstart_set				BIT_SET_M(3405)			//*Включить повышенную мощность электростартера
#define PNstart_clr				BIT_CLR_M(3405)			//*Выключить повышенную мощность электростартера
#define PNstart_tst				BIT_TST_M(3405)			//*Включена ли повышенная мощность электростартера
/*
#define SZ_set				BIT_SET_M(3404)			//*Открыть стендовую заслонку
#define SZ_clr				BIT_CLR_M(3404)			//*Закрыть стендовую заслонку
#define SZ_tst				BIT_TST_M(3404)			//*Проверка команды на стендовую заслонку

#define VZ_set				BIT_SET_M(3405)			//*Открыть воздушную заслонку
#define VZ_clr				BIT_CLR_M(3405)			//*Закрыть воздушную заслонку
#define VZ_tst				BIT_TST_M(3405)			//*Проверка команды на воздушную заслонку
*/
#define AZ1_set				BIT_SET_M(3406)			//*Включить агрегат зажигания 1
#define AZ1_clr				BIT_CLR_M(3406)			//*Выключить агрегат зажигания 1
#define AZ1_tst				BIT_TST_M(3406)			//*Включен ли агрегат зажигания 1

#define AZ2_set				BIT_SET_M(3407)			//*Включить агрегат зажигания 2
#define AZ2_clr				BIT_CLR_M(3407)			//*Выключить агрегат зажигания 2
#define AZ2_tst				BIT_TST_M(3407)			//*Включен ли агрегат зажигания 2

#define A_common_set		BIT_SET_M(3408)			//*Установка флага "Общая авария от СВК"
#define A_common_clr		BIT_CLR_M(3408)			//*Сброс флага "Общая авария от СВК"
#define A_common_tst		BIT_TST_M(3408)			//*Проверка флага "Общая авария от СВК"

#define N_common_set		BIT_SET_M(3409)			//*Установка флага "Общий сигнал нормального останова от СВК"
#define N_common_clr		BIT_CLR_M(3409)			//*Сброс флага "Общий сигнал нормального останова от СВК"
#define N_common_tst		BIT_TST_M(3409)			//*Проверка флага "Общий сигнал нормального останова от СВК"

/*
#define setSK_OFF_set		BIT_SET_M(3410)			//*Закрыть СК
#define setSK_OFF_clr			BIT_CLR_M(3410)			//*Закрыть СК
#define setSK_OFF_tst			BIT_TST_M(3410)			//*Закрыть СК

#define setSK_ON1_set		BIT_SET_M(3411)			//*Открыть СК
#define setSK_ON1_clr		BIT_CLR_M(3411)			//*Открыть СК
#define setSK_ON1_tst		BIT_TST_M(3411)			//*Открыть СК
*/

#define ZPV1_ON				BIT_SET_M(3411)			//*Открыть ЗПВ 1-ой группы
#define ZPV1_OFF			BIT_CLR_M(3411)			//*Закрыть ЗПВ 1-ой группы
#define ZPV1_ON_tst 		BIT_TST_M(3411)			//*Открыть/Закрыть ЗПВ 1-ой группы

#define ZPV2_ON				BIT_SET_M(3412)			//*Открыть ЗПВ 2-ой группы
#define ZPV2_OFF			BIT_CLR_M(3412)			//*Закрыть ЗПВ 2-ой группы
#define ZPV2_ON_tst			BIT_TST_M(3412)			//*Открыть/Закрыть ЗПВ 2-ой группы

#define POS_ON				BIT_SET_M(3413)			//*Открыть ПОС
#define POS_OFF				BIT_CLR_M(3413)			//*Закрыть ПОС
#define POS_ON_tst			BIT_TST_M(3413)			//*Открыть/Закрыть ПОС

#define compKND_ON			BIT_SET_M(3414)			//*Включить компрессор КНД
#define compKND_OFF			BIT_CLR_M(3414)			//*Выключить компрессор КНД
#define compKND_ON_tst		BIT_TST_M(3414)			//*Включить/Выключить компрессор КНД


// Для ручного управления исполнительными механизмами
#define manual_upr_VNA_tst 		BIT_TST_M(3713)			//*Ручное/Автоматическое управление ВНА
#define manual_upr_VNA_clr 		BIT_CLR_M(3713)			//*Ручное/Автоматическое управление ВНА

#define manual_upr_DOZ_tst 		BIT_TST_M(3714)			//*Ручное/Автоматическое управление ТРК
#define manual_upr_DOZ_clr 		BIT_CLR_M(3714)			//*Ручное/Автоматическое управление ТРК

#define manual_upr_SK_tst 		BIT_TST_M(3715)			//*Ручное/Автоматическое управление СК
#define manual_upr_SK_clr 		BIT_CLR_M(3715)			//*Ручное/Автоматическое управление СК
#define manual_SK_ON_tst 		BIT_TST_M(3716)			//*Открыть СК с ПУ
#define manual_SK_OF_tst 		BIT_TST_M(3717)			//*Закрыть СК с ПУ

#define manual_upr_KPV_tst 		BIT_TST_M(3718)			//*Ручное/Автоматическое управление КПВ КВД
#define manual_upr_KPV_clr 		BIT_CLR_M(3718)			//*Ручное/Автоматическое управление КПВ КВД
#define manual_KPV_ON_tst 		BIT_TST_M(3719)			//*Открыть КПВ КВД с ПУ
#define manual_KPV_OF_tst 		BIT_TST_M(3720)			//*Закрыть КПВ КВД с ПУ

#define manual_upr_KPG_tst		BIT_TST_M(3721)			//*Ручное/Автоматическое управление КПВЗ КПГ
#define manual_upr_KPG_clr		BIT_CLR_M(3721)			//*Ручное/Автоматическое управление КПВЗ КПГ
#define manual_KPG_ON_tst 		BIT_TST_M(3722)			//*Открыть КПВЗ КПГ с ПУ
#define manual_KPG_OF_tst 		BIT_TST_M(3723)			//*Закрыть КПВЗ КПГ с ПУ

#define manual_upr_ZPV1_tst 	BIT_TST_M(3724)			//*Ручное/Автоматическое управление ЗПВ1
#define manual_upr_ZPV1_clr 	BIT_CLR_M(3724)			//*Ручное/Автоматическое управление ЗПВ1
#define manual_ZPV1_ON_tst 		BIT_TST_M(3725)			//*Открыть ЗПВ1 с ПУ
#define manual_ZPV1_OF_tst 		BIT_TST_M(3726)			//*Закрыть ЗПВ1 с ПУ

#define manual_upr_ZPV2_tst 	BIT_TST_M(3727)			//*Ручное/Автоматическое управление ЗПВ2
#define manual_upr_ZPV2_clr 	BIT_CLR_M(3727)			//*Ручное/Автоматическое управление ЗПВ2
#define manual_ZPV2_ON_tst 		BIT_TST_M(3728)			//*Открыть ЗПВ2 с ПУ
#define manual_ZPV2_OF_tst 		BIT_TST_M(3729)			//*Закрыть ЗПВ2 с ПУ
/*
#define manual_upr_SZ_tst 		BIT_TST_M(3724)			//*Ручное/Автоматическое управление СЗ СтВ
#define manual_upr_SZ_clr 		BIT_CLR_M(3724)			//*Ручное/Автоматическое управление СЗ СтВ
#define manual_SZ_ON_tst 		BIT_TST_M(3725)			//*Открыть СЗ СтВ с ПУ
#define manual_SZ_OF_tst 		BIT_TST_M(3726)			//*Закрыть СЗ СтВ с ПУ

#define manual_upr_VZ_tst 		BIT_TST_M(3727)			//*Ручное/Автоматическое управление ВЗ СтВ
#define manual_upr_VZ_clr 		BIT_CLR_M(3727)			//*Ручное/Автоматическое управление ВЗ СтВ
#define manual_VZ_ON_tst 		BIT_TST_M(3728)			//*Открыть ВЗ СтВ с ПУ
#define manual_VZ_OF_tst 		BIT_TST_M(3729)			//*Закрыть ВЗ СтВ с ПУ
*/
#define manual_upr_AZ1_tst 		BIT_TST_M(3730)			//*Ручное/Автоматическое управление АЗ №1
#define manual_upr_AZ1_clr 		BIT_CLR_M(3730)			//*Ручное/Автоматическое управление АЗ №1
#define manual_AZ1_ON_tst 		BIT_TST_M(3731)			//*Включить АЗ №1 с ПУ
#define manual_AZ1_OF_tst 		BIT_TST_M(3732)			//*Выключить АЗ №1 с ПУ

#define manual_upr_AZ2_tst 		BIT_TST_M(3733)			//*Ручное/Автоматическое управление АЗ №2
#define manual_upr_AZ2_clr 		BIT_CLR_M(3733)			//*Ручное/Автоматическое управление АЗ №2
#define manual_AZ2_ON_tst 		BIT_TST_M(3734)			//*Включить АЗ №2 с ПУ
#define manual_AZ2_OF_tst 		BIT_TST_M(3735)			//*Выключить АЗ №2 с ПУ



//
//#define KPG_ON2				BIT_SET_M(3412)			//*Открыть КПГ и КПВЗ штоковая
//#define KPG_OFF2				BIT_CLR_M(3412)			//*Закрыть КПГ и КПВЗ штоковая
#define P_PtgHigh_set		BIT_SET_M(3517)			//*Установка флага "Давление топливного газа высокое"
#define P_PtgHigh_clr		BIT_CLR_M(3517)			//*Сброс флага "Давление топливного газа высокое"
#define P_PtgHigh_tst		BIT_TST_M(3517)			//*Проверка флага "Давление топливного газа высокое"
#define P_PtgLow_set		BIT_SET_M(3514)			//*Установка флага "Давление топливного газа низкое"
#define P_PtgLow_clr		BIT_CLR_M(3514)			//*Сброс флага "Давление топливного газа низкое"
#define P_PtgLow_tst		BIT_TST_M(3514)			//*Проверка флага "Давление топливного газа низкое"

//
//#define Delta_GtPk			RF(1627)			//Величина разности ограничения и текущего расхода Gt/Pk для вывода на Парус

#define fireTimer			RF(1655)				//**Таймер времени с момента открытия СК
#define integOut			RF(1661)				//**Значение интегратора в выходном каскаде (кг/ч)
#define IntegNvd			RF(1663)				//**Интегратор Nvd
#define CTvhNvd				RF(1665)				//**Коэффициент коррекции nvd по Твх
#define nvd_ust				RF(1669)				//Уставка контура nvd 
#define DeltaVNA			RF(1791)				//Величина добавки по ВНА руками ввели


////Внутренние определения
//Возможные состояния
#define CND_STOP			1		//Двигатель остановлен
#define CND_STARTER			2		//Прокрутка стартером
#define CND_FIRE			3		//Розжиг камеры сгорания
#define CND_RATE			4		//Разгон до малого газа
#define CND_STAB			5		//Режим работы двигателя
#define CND_AO				6		//Аварийный останов

//Определения контуров регулирования
#define kt_stabST			195		//Контур стабилизации оборотов СТ
#define kt_heatMG			120		//Контур прогрева на минимальном режиме
#define kt_GG				145		//Контур стабилизации оборотов ГГ
#define kt_ogrMG			122		//Контур ограничения nvd на минимальном режиме
#define kt_sbros			130		//Контур сброса на минимальный режим
#define kt_down				140		//Контур ограничения приемистости снизу или кнопка "меньше"
#define kt_Nvdogr_up		150		//Контур ограничения Nkvd сверху
#define kt_Nvdogr_up_pr		151		//Контур ограничения Nkvd сверху приведенное
#define kt_Nndogr_up		160		//Контур ограничения Nknd сверху
#define kt_Nstogr_down		196		//Контур ограничения Nst снизу
#define kt_Nstogr_up		197		//Контур ограничения Nst сверху
#define kt_n_point			170		//Контур n с точкой на запуске
#define kt_up				190		//Контур ограничения приемистости сверху или кнопка "больше"
#define kt_fire				200		//Контур розжига
#define kt_ogrGt_zap		300		//Контур ограничения расхода топлива на запуске
#define kt_ogrdGt_zap		350		//Контур ограничения скорости увеличения расхода топлива на запуске
#define kt_ogrGt_osn		400		//Контур ограничения расхода топлива на основных режимах
#define kt_Pk				500		//Контур ограничения Pк
#define kt_Tt				600		//Контур ограничения Tt
#define kt_GtPk				700		//Контур ограничения Gt/Pk
#define kt_Tst				900		//Контур ограничения Tst



#define Kdot				0.3		//Коэффициент дотяжки
#define K_d_VNA				1		//Коэффициент для вычисления ВНА,

//дискретные сигналы по управлению ВНА
//

/*#define VTshtoka1_set			BIT_SET_M(3418)			//Уст-ка "втягивание штока 1-ого электродвигателя ВНА (в 0)"
#define VTshtoka1_clr			BIT_CLR_M(3418)			//Сброс  "втягивание штока 1-ого электродвигателя ВНА (в 0)"

#define VITshtoka1_set			BIT_SET_M(3419)			//Уст-ка "вытягивание штока 1-ого электродвигателя ВНА (в -45)"
#define VITshtoka1_clr			BIT_CLR_M(3419)			//Сброс  "вытягивание штока 1-ого электродвигателя ВНА (в -45)"

#define VTshtoka2_set			BIT_SET_M(3413)			//Уст-ка "втягивание штока 2-ого электродвигателя ВНА (в 0)"
#define VTshtoka2_clr			BIT_CLR_M(3413)			//Сброс  "втягивание штока 2-ого электродвигателя ВНА (в 0)"

#define VITshtoka2_set			BIT_SET_M(3415)			//Уст-ка "вытягивание штока 2-ого электродвигателя ВНА (в -45)"
#define VITshtoka2_clr			BIT_CLR_M(3415)			//Сброс  "вытягивание штока 2-ого электродвигателя ВНА (в -45)"
*/

/*
void TRegDoz (float Ptopl)//Функция коррекции расхода и определения тока выходного
{setDoz =0.068306*(Gt_tek*sqrt((Tpdtg+273)/293)/Ptopl-22.67);
if (setDoz<0) setDoz = 0;
if (setDoz>97) setDoz = 97;}
*/

/*
void TRegDoz (float Ptopl)//Функция коррекции расхода и определения тока выходного
{
if (Ptopl < 1.9) Ptopl = 1.9;
	else if (Ptopl > 4.1) Ptopl = 4.1;

b = ( (1.43 * posDOZ/100.0) / ( 1 + 1.43*posDOZ/100.0)) * ( (1.43 * posDOZ/100.0) / ( 1 + 1.43*posDOZ/100.0))
 * ( (1.43 * posDOZ/100.0) / ( 1 + 1.43*posDOZ/100.0));  
P2 = b * (Ptopl - Pkvd) + Pkvd;
fo = harakt(K_IoutDoz,P2/Ptopl);
K = 1/(5.65685 * (Ptopl/sqrt(Tpdtg + 273)) * fo);
setDoz = harakt(IoutDoz, K*Gt_tek);
if (setDoz<0) setDoz = 0;
if (setDoz>97) setDoz = 97;}
*/
 
 void TRegDoz (float Ptopl)//Функция коррекции расхода и определения тока выходного
{
if (Ptopl < 1.5) Ptopl = 1.5;
	else if (Ptopl > 5.0) Ptopl = 5.0;
setDoz = harakt(IoutDoz, Gt_tek);
if (setDoz<0) setDoz = 0;
if (setDoz>97) setDoz = 97;}


int GefMain(void)
{



//ЛОКАЛЬНЫЕ ДАННЫЕ//

int I,i,war;	
static char	gotoStopToStarter;				// возможные переходы
static char	gotoToAO;
static char	gotoStarterToStop;
static char	gotoStarterToFire;
static char	gotoFireToRate;
static char	gotoRateToStab;
static char	gotoStabToStop;
static char	gotoAOToStop;
//static char	Slow_Wna;
static float	temperPrev;	//надо сделать static//Температура на запусковых термопарах до розжига
static float	TempRoz;						//Скорость изменения расхода на розжиге
static float	n_point;						//Значение ускорения на разгоне
static float	Out_fire;						//Значение на выходе контура розжига
static float	Out_kt_Nvd;						//Выход контура Nvd (всего первого селектора)
//static float	Out_kt_ogrGtzap;							//Значение контура ограничения расхода на запуске
static float	Out_kt_ogrdGtzap;				//Значение контура ограничения скорости роста расхода на запуске
static float	Out_sel1;						//Выход селектора 1
static float	Out_sel2;						//Выход селектора 2
static float	Kprop_Nvd;						//Коэффициент пропорциональности Nvd
static char		up_old;					     	//Значение кнопки "больше" на предыдущем цикле
static char		down_old;		        		//Значение кнопки "меньше" на предыдущем цикле
static char 	st_old;			        		//Значение кнопки "меньше" на предыдущем цикле
//static float		nvd_ust;							//Уставка контура nvd
static float	Out_sel1_min;					//Выход селектора минимума в селекторе Nvd
static int		Metka_sel1_min;					//Метка контура Выход селектора минимума в селекторе Nvd
static float	Out_Pk;							//Выход контура Pк
//static float	Out_Tt;								//Выход контура Тт
static float	Out_Tst;						//Выход контура Тст
static float	Out_GtPk;						//Выход контура Gt/Pk
static float	nst_ust_min;					//Уставка контура ст в контуре минимума
static float	integr_ST;						//Интегратор контура СТ
static float	dST;							//Внутренняя переменная в контуре СТ
static float	Out_ST;							//Выход контура СТ

static float	dNnd;							//Внутренняя переменная в контуре КНД
static float	Out_Nnd;						//Выход контура КНД

static float	Out_kt_MG;
static float	Out_MG;
static float	IntegNvdMG;
/*static float    delta_VNA;						//величина регулировки положением ВНА (в пределах от 0...7)
static float	deltVNA1,deltVNA2,deltVNA3,deltVNA4;		//переменные для фильтрации deltVNA
static float	pr_deltVNA;						//приращение deltVNA
static float    kor_deltVNA;						//коррекция deltVNA	
static float	rasVNA;							//величина для вычисления зоны нечувствительности ВНА
static float	rasVNA_f;							//величина для вычисления зоны нечувствительности ВНА фильтрованная
static float    deltVNA;							//дельта для управления ВНА (разность между заданием и средним значением положения на ВНА) 
static float	sravVNA;							//величина для сравнения ВНА 
static float    srmeasureVNA;						//среднее значение ВНА (по 2-ум датчикам ДБСКТ)
*/

static float Reg_VNA;						//*Регулировка программы ВНА (параллельное смещение программы по оси nвд пр)
static float Reg_KPV_ON;					//*Регулировка открытия КПВ
static float Reg_KPV_OFF;					//*Регулировка закрытия КПВ
static float Reg_KPG_ON;					//*Регулировка открытия КПГ и КПВЗ
static float Reg_KPG_OFF;					//*Регулировка закрытия КПГ и КПВЗ
static float Reg_ZPV1_OFF;				//Регулировка закрытия ЗПВ КНД 1-й группы
static float Reg_ZPV1_ON;				//Регулировка открытия ЗПВ КНД 1-й группы
static float Reg_ZPV2_OFF;				//Регулировка закрытия ЗПВ КНД 2-й группы
static float Reg_ZPV2_ON;				//Регулировка открытия ЗПВ КНД 2-й группы
static float Reg_Gt_roz;					//*Регулировка расхода на розжиге
//static float Reg_Gt_ogr_zap;				//*Регулировка ограничения расхода на разгоне
static float Reg_Gt_ogr;					//*Регулировка максимальной величины расхода топливного газа
static float Reg_GtPk_ogr;  				//*Регулировка ограничения Gt/Pk
static float Reg_Usk_ST;					//Регулировка ускорения со стартером
static float Reg_Usk;						//Регулировка ускорения без стартера
static float Reg_Gt_RozN;					//Регулировка начального расхода на розжиге
static float Reg_Gt_RozK;					//Регулировка конечного расхода на розжиге
static float Reg_dG_Zap;					//Регулировка скорости изменения ограничения расхода на запуске
static int 	Starter_Old;					//Стартер старое значение

static float nvd_nd_pr;							//*частота вращения низкого давления приведенная
static float nvd0;								//*частота вращения ноликовая
static float Tknd;								//*температура компрессора низкого давления 


static float AZ1timer;
static float AZ2timer;						
static char	manual_SK_ON;
static char	manual_KPV_ON;
static char	manual_KPG_ON;
//static char	manual_SZ_ON;
//static char	manual_VZ_ON;
static char	manual_AZ1_ON;
static char	manual_AZ2_ON;
//static float setSK_ON_timer;
//static float setSK_OF_timer;
static char manual_ZPV1_ON;
static char manual_ZPV2_ON;
if (condition == 0) condition = 1;

//Механизм ввода регулировок
if (updateTun) {

Reg_VNA= 0.0;

if ((Reg_KPV_ON_u >= -1000.0)&&(Reg_KPV_ON_u <= 1000.0)) 		Reg_KPV_ON = Reg_KPV_ON_u;			//Регулировка открытия КПВ
if ((Reg_KPV_OFF_u >= -1000.0)&&(Reg_KPV_OFF_u <= 1000.0)) 		Reg_KPV_OFF = Reg_KPV_OFF_u;		//Регулировка закрытия КПВ
if ((Reg_KPG_ON_u >= -1000.0)&&(Reg_KPG_ON_u <= 1000.0)) 		Reg_KPG_ON = Reg_KPG_ON_u;			//Регулировка открытия КПГ и КПВЗ
if ((Reg_KPG_OFF_u >= -1000.0)&&(Reg_KPG_OFF_u <= 1000.0)) 		Reg_KPG_OFF = Reg_KPG_OFF_u;		//Регулировка закрытия КПГ и КПВЗ	

if ((Reg_ZPV1_ON_u >= -1000.0)&&(Reg_ZPV1_ON_u <= 1000.0)) 		Reg_ZPV1_ON = Reg_ZPV1_ON_u;		//Регулировка открытия ЗПВ1
if ((Reg_ZPV1_OFF_u >= -1000.0)&&(Reg_ZPV1_OFF_u <= 1000.0)) 	Reg_ZPV1_OFF = Reg_ZPV1_OFF_u;		//Регулировка закрытия ЗПВ1
if ((Reg_ZPV2_ON_u >= -1000.0)&&(Reg_ZPV2_ON_u <= 1000.0)) 		Reg_ZPV2_ON = Reg_ZPV2_ON_u;		//Регулировка открытия ЗПВ2
if ((Reg_ZPV2_OFF_u >= -1000.0)&&(Reg_ZPV2_OFF_u <= 1000.0)) 	Reg_ZPV2_OFF = Reg_ZPV2_OFF_u;		//Регулировка закрытия ЗПВ2	

if ((Reg_Gt_roz_u >= -220.0)&&(Reg_Gt_roz_u <= 130.0)) 			Reg_Gt_roz = Reg_Gt_roz_u;			//Регулировка  расхода на розжиге
//if ((Reg_Gt_ogr_zap_u >= -300.0)&&(Reg_Gt_ogr_zap_u <= 300.0)) 	Reg_Gt_ogr_zap = Reg_Gt_ogr_zap_u;							//Регулировка ограничения расхода на запуске 
if ((Reg_Gt_ogr_u >= -500.0)&&(Reg_Gt_ogr_u <= 500.0)) 			Reg_Gt_ogr = Reg_Gt_ogr_u;			//Регулировка величины максимального расхода топливного газа
if ((Reg_GtPk_ogr_u >= -1.5)&&(Reg_GtPk_ogr_u <= 1.5)) 			Reg_GtPk_ogr = Reg_GtPk_ogr_u;		//Регулировка величины ограничения Gт/Рк (параллельное смещение программы по оси Gт/Рк)
if ((Reg_Usk_ST_u >= -0.5)&&(Reg_Usk_ST_u <= 0.5)) 				Reg_Usk_ST = Reg_Usk_ST_u;			// Регулировка ускорения на запуске со стартером
if ((Reg_Usk_u >= -0.5)&&(Reg_Usk_u <= 0.5)) 					Reg_Usk = Reg_Usk_u;				// Регулировка ускорения на запуске без стартера	
if ((Reg_Gt_RozN_u >= 0.0)&&(Reg_Gt_RozN_u <=350.0))			Reg_Gt_RozN = Reg_Gt_RozN_u;		//Регулировка начального расхода на розжиге
if ((Reg_Gt_RozK_u >= -350.0)&&(Reg_Gt_RozK_u <=100.0))			Reg_Gt_RozK = Reg_Gt_RozK_u;		//Регулировка конечного расхода на розжиге

//if ((Reg_dG_Zap_u >= -0.9)&&(Reg_dG_Zap_u <=5.0))				Reg_dG_Zap = Reg_dG_Zap_u;			//Регулировка скорости изменения ограничения расхода на запуске


}
Gt_roz_ust = Gt_roz + Reg_Gt_roz;
Gt_ogr_ust = Reg_Gt_ogr + GT_max;
GtPk_ogr_ust = sqrt(Tvh/288.134)*harakt(GtdivPk,nvdNorm)*(1+Reg_GtPk_ogr)*Pkvd;
KPV_ON_ust = nvdOpenKPV + Reg_KPV_ON;
KPV_OFF_ust = nvdCloseKPV + Reg_KPV_OFF;
KPG_ON_ust = nvdOpenKPG + Reg_KPG_ON;
KPG_OFF_ust = nvdCloseKPG + Reg_KPG_OFF;
ZPV1_OFF_ust = nvdCloseZPV1 + Reg_ZPV1_OFF;				//*Уставка закрытия ЗПВ КНД 1-й группы 
ZPV1_ON_ust	= nvdOpenZPV1 + Reg_ZPV1_ON;				//*Уставка открытия ЗПВ КНД 1-й группы 
ZPV2_OFF_ust =  nvdCloseZPV2 + Reg_ZPV2_OFF;			//*Уставка закрытия ЗПВ КНД 2-й группы
ZPV2_ON_ust = nvdOpenZPV2 + Reg_ZPV2_ON;				//*Уставка открытия ЗПВ КНД 2-й группы 
Usk_ST_ust = harakt(NvdTodNvd_STV,nvd)*(1+Reg_Usk_ST);
Usk_ust = harakt(NvdTodNvd,nvd)*(1+Reg_Usk);
Gt_roz_min_ust = Gt_roz_min + Reg_Gt_RozN;
Gt_roz_max_ust = Gt_roz_max + Reg_Gt_RozK;
dGt_ogr_zap_ust = (1+Reg_dG_Zap)*harakt(dGt_zap,nvdNorm);


if (Metka==195) R_kt_stabST_set; else R_kt_stabST_clr;				//*Установка флага "Контур стабилизации оборотов СТ"

if (Metka==120) R_kt_heatMG_set; else R_kt_heatMG_clr;				//*Установка флага "Контур прогрева на минимальном режиме"

if (Metka==145) R_kt_GG_set; else R_kt_GG_clr;						//*Установка флага "Контур стабилизации оборотов ГГ"

if (Metka==122) R_kt_ogrMG_set; else R_kt_ogrMG_clr;				//*Установка флага "Контур ограничения nvd на минимальном режиме"

if (Metka==130) R_kt_sbros_set; else R_kt_sbros_clr;				//*Установка флага "Контур сброса на минимальный режим"

if (Metka==140) R_kt_down_set; else R_kt_down_clr;					//*Установка флага "Контур ограничения приемистости снизу или кнопка "меньше""

if (Metka==150) R_kt_Nvdogr_up_set; else R_kt_Nvdogr_up_clr;		//*Установка флага "Контур ограничения Nvd сверху"

if (Metka==160) R_kt_Nndogr_up_set; else R_kt_Nndogr_up_clr;		//*Установка флага "Контур ограничения Nvd сверху"

if (Metka==196) R_kt_Nstogr_down_set; else R_kt_Nstogr_down_clr;	//*Установка флага "Контур ограничения Nst снизу"

if (Metka==197) R_kt_Nstogr_up_set; else R_kt_Nstogr_up_clr;		//*Установка флага "Контур ограничения Nst сверху"

if (Metka==170) R_kt_n_point_set; else R_kt_n_point_clr;			//*Установка флага "Контур n с точкой на запуске"

if (Metka==190) R_kt_up_set; else R_kt_up_clr;						//*Установка флага "Контур ограничения приемистости сверху или кнопка "больше""

if (Metka==200) R_kt_fire_set; else R_kt_fire_clr;					//*Установка флага "Контур розжига"

if (Metka==300) R_kt_ogrGt_zap_set; else R_kt_ogrGt_zap_clr;		//*Установка флага "Контур ограничения расхода топлива на запуске"

if (Metka==350) R_kt_ogrdGt_zap_set; else R_kt_ogrdGt_zap_clr;		//*Установка флага "Контур ограничения скорости увеличения расхода топлива на запуске"

if (Metka==400) R_kt_ogrGt_osn_set; else R_kt_ogrGt_osn_clr;		//*Установка флага "Контур ограничения расхода топлива на основных режимах"

if (Metka==500) R_kt_Pk_set; else R_kt_Pk_clr;						//*Установка флага "Контур ограничения Pк"

//if (Metka==600) R_kt_Tt_set; else R_kt_Tt_clr;					//*Установка флага "Контур ограничения Tt"

if (Metka==700) R_kt_GtPk_set; else R_kt_GtPk_clr;					//*Установка флага "Контур ограничения Gt/Pk"

if (Metka==900) R_kt_Tst_set; else R_kt_Tst_clr;					//*Установка флага "Контур ограничения Tst"



//МЕХАНИЗАЦИЯ КОМПРЕССОРА
	if init_tst {
		KPV_OFF;
		KPG_OFF;
		//KPG_OFF2;
		set_VNA = harakt(setVNA,0);}
	else {
		if (nvd0 <= KPV_ON_ust) KPV_ON;
		if ((nvd0 >= KPV_OFF_ust)||(nvd < nvdCloseLow)) KPV_OFF;
		//Для одновременного управления КПВЗ
		if (nvdNorm <= KPG_ON_ust) KPG_ON;
		if ((nvdNorm >= KPG_OFF_ust)||(nvd < nvdCloseLow)) KPG_OFF;
		//Управление ЗПВ1,ЗПВ2
		if (nvdNorm <= ZPV1_ON_ust) ZPV1_ON;
		if ((nvdNorm >= ZPV1_OFF_ust)||(nvd < nvdCloseLow)) ZPV1_OFF;
		if (nvdNorm <= ZPV2_ON_ust) ZPV2_ON;
		if ((nvdNorm >= ZPV2_OFF_ust)||(nvd < nvdCloseLow)) ZPV2_OFF;

		// вычисление приведенных оборотов ротора низкого давления
		nvd_nd_pr = nst*sqrt(288/Tvh);
		// график зависимости из конфигуратора
		set_VNAr = harakt(setVNAr,nvd_nd_pr);
		// вычисление температуры за компрессором низкого давления
		Tknd = set_VNAr*Tvh;
	    // вычисление оборотов от которых находиться угол ВНА 
		nvd0 = nvd*sqrt(288/Tknd);
 
 
		//Для проверки ВНА в режиме проверки защит и состоянии "AO" и""СТОП
		if (!(check&&(nvd<100)&&((condition == CND_AO)||(condition == CND_STOP)))) set_VNA = harakt(setVNA,nvd0 + Reg_VNA);
		//set_VNA = harakt(setVNA,nvdNorm + Reg_VNA);
//Проверка ВНА на ХП!
/* 6.12.2010
		if ((HP_tst) && (HPTimer>=40) && (HPTimer<70))
		{
		if ((HP_tst) && (HPTimer>=40) && (HPTimer<50)) set_VNA = -45.0 + 45.0/10.0*(HPTimer - 40);//Для прверки ВНА на ХП
		else if ((HP_tst) && (HPTimer>=50) && (HPTimer<55)) set_VNA = 0.0;
		else if ((HP_tst) && (HPTimer>=55) && (HPTimer<65)) set_VNA = 0.0 - 45.0/10.0*(HPTimer - 55);
		else set_VNA = harakt(setVNA,nvdNorm + Reg_VNA);}
		else if ((HP_tst) && (HPTimer>=70) && (HPTimer<95)) {
		if ((HP_tst) && (HPTimer>=70) && (HPTimer<80)) set_VNA = -45.0 + 45.0/10.0*(HPTimer - 70);//Для прверки ВНА на ХП
		else if ((HP_tst) && (HPTimer>=80) && (HPTimer<85)) set_VNA = 0.0;
		else if ((HP_tst) && (HPTimer>=85) && (HPTimer<95)) set_VNA = 0.0 - 45.0/10.0*(HPTimer - 85);
		else set_VNA = harakt(setVNA,nvdNorm + Reg_VNA);}

		if ((R_promGo_tst) && (promTimer>=0) && (promTimer<200))
		{ 
		if ((R_promGo_tst) && (promTimer>=0) && (promTimer<25)) set_VNA = -45.0;//Для прверки ВНА на промывке
		else if ((R_promGo_tst) && (promTimer>=25) && (promTimer<40)) set_VNA = -45.0 + 45.0/15.0*(promTimer - 25);
		else if ((R_promGo_tst) && (promTimer>=40) && (promTimer<50)) set_VNA = 0.0;
		else if ((R_promGo_tst) && (promTimer>=50) && (promTimer<60)) set_VNA = 0.0 - 30.0/10.0*(promTimer - 50);
		else if ((R_promGo_tst) && (promTimer>=60) && (promTimer<70)) set_VNA = - 30.0;
		else if ((R_promGo_tst) && (promTimer>=70) && (promTimer<80)) set_VNA = -30.0 + 30.0/10.0*(promTimer - 70);
		else if ((R_promGo_tst) && (promTimer>=80) && (promTimer<195)) set_VNA = 0.0;
		else if ((R_promGo_tst) && (promTimer>=195) && (promTimer<200)) set_VNA = 0.0 - 45.0/5.0*(promTimer - 195);
		else set_VNA = -45.0;
		}
		else set_VNA = harakt(setVNA,nvdNorm + Reg_VNA);
*/
		}

	if (condition == CND_AO) {
		if (!(check&&(nvd<100)))set_VNA = harakt(setVNA,0);//!Для проверки ВНА в режиме проверки защит и состоянии "AO" и""СТОП
		KPV_ON;
		KPG_ON;
		if (nvd < nvdCloseLow) {
			KPV_OFF;
			KPG_OFF;
			}
	}
// На режиме Промывка перемещение ВНА и закрытие КПГ, КПВЗ и КПВ
	if R_promGo_tst {
		KPV_OFF; 
		KPG_OFF;
		if (Nstart_tst) promTimer+=cycle;
		set_VNA = harakt(PromVNA,promTimer);}
	else set_VNA = harakt(setVNA,nvd0 + Reg_VNA);	

//ИНИЦИАЛИЗАЦИЯ
	if (init_tst) {
		//инициализация dNgg_Select

		//инициализация selektor_Gt
		//инициализация regDoz
		R_promEnd_clr;
		R_promGo_clr;
		endHP_clr;
		HP_clr;
		engineStarted_clr;
		NO_clr;
		condition = CND_STOP;
		HPTimer = 0;
		startTimer = 0;
		fireTimer = 0;
		heatTimer = 0;
		coolTimer = 0;
		promTimer = 0;
		setDoz = 0;//Выдаем задание на полное закрытие дозатора, без контуров регулирования
		integr_ST = 0;
		setSK_ON_clr;
		Nstart_clr;
		PNstart_clr;
		//SZ_clr;
		//VZ_clr;
		AZ1_clr;
		AZ2_clr;
//		Kp_Tt = KpTt;
		Kp_Tst = KpTst;
        Kp_Pk = KpPk;
		K1_st = K1st;
		K2_st = K2st;
		K3_st = K3st;
}
	else {




	
//ОСНОВНАЯ ПРОГРАММА//

//Формирование признака нет розжига
if 	((((fireTimer > maxFireTime) && (condition == CND_FIRE)) || notFire_tst) && (! externDeblock)) notFire_set; else notFire_clr;
//Формирование признака нет ускорения
if (longZAP)
{if ((((nvd <= RateGG) && startEngine_tst && (startTimer >= (timeStarterOff + longTime))) || notRateGG_tst) && (! externDeblock)) notRateGG_set; else notRateGG_clr;}
else {if ((((nvd <= RateGG) && (startTimer >= timeStarterOff)) || notRateGG_tst) && (! externDeblock)&& (condition == CND_RATE)) notRateGG_set; else notRateGG_clr;}

//Формирование признака "Время запуска велико"
if (startTimer >= 301.0) TimeZapHigh_set;
	else {if (externDeblock) TimeZapHigh_clr;}

//Формирование общей аварии в диспетчере
if (A_common_tst || notFire_tst || notRateGG_tst || TimeZapHigh_tst) A_common_set; else A_common_clr;
//Формирование признака холодная прокрутка идет
if (((startHP && start && redyHP_tst && !startEngine_tst && !engineStarted_tst) || HP_tst) && (!endHP_tst)) HP_set; else HP_clr;
//Формирование признака промывка идет
if (((startProm && start && readyClear_tst && !startEngine_tst && !engineStarted_tst) || R_promGo_tst) && (!R_promEnd_tst)) R_promGo_set; else R_promGo_clr;
//Формирование признака запуска двигателя
if (((start && !startHP && redyStart_tst && !startProm && !R_promGo_tst && !HP_tst) || startEngine_tst) && !(engineStarted_tst))  startEngine_set; else startEngine_clr;

//if (P_PtgHigh_tst || P_PtgLow_tst) BIT_SET_M(3713);

//Формирование признака прогрева двигателя
if (engineStarted_tst && (condition == CND_RATE)) heat_set; else heat_clr;
//Защита от повторного включения стартера
if ((startEngine_tst || HP_tst || R_promGo_tst) && (nvd < 100)) gotoStopToStarter = 1; else gotoStopToStarter = 0;
//if ((startHP || start) && (nvd < 100)) BIT_SET_M(3713); //else BIT_CLR_M(3713);

if (A_common_tst || externAO) gotoToAO = 1; else {if externDeblock gotoToAO = 0;}

if (longZAP) 
{if (HP_tst && (HPTimer > (HPTimeHP + longTimeHP)))  {gotoStarterToStop = 1; HP_clr; endHP_set;} }
else {if (HP_tst && (HPTimer > HPTimeHP)&& !R_promGo_tst)  {gotoStarterToStop = 1; HP_clr; endHP_set;} }

if (R_promGo_tst && (promTimer > PromTime)&& !HP_tst)  {gotoStarterToStop = 1; R_promGo_clr; R_promEnd_set;} 

if (longZAP)
{if (startEngine_tst && (((startTimer > (FireTime + longTime)) || (startTimer > (ignitionTime + longTime))) && (nvd > fireNgg))) gotoStarterToFire = 1; else gotoStarterToFire = 0;}
else {if (startEngine_tst && (((startTimer > FireTime) || (startTimer > ignitionTime)) && (nvd > fireNgg))) gotoStarterToFire = 1; else gotoStarterToFire = 0;}

if (firePresent_tst && (Gt_tek>=Gt_roz_ust)) gotoFireToRate = 1; else gotoFireToRate = 0;//разгон начинается, когда есть розжиг и дошли до уставки розжига

if (heat_tst && (heatTimer >= HeatTime)) gotoRateToStab = 1; else gotoRateToStab = 0;

if (coolTimer >= CoolTime) gotoStabToStop = 1; else gotoStabToStop = 0;

if (stop || N_common_tst) NO_set;//Устанвливаем режим нормального останова

if ((condition == CND_AO) && SK_OFF_tst && (nvd < 100) && (Pkvd < 2) && !gotoToAO) gotoAOToStop = 1; else gotoAOToStop = 0;

if (condition == 2) R_raskStV_set; else R_raskStV_clr;
if (condition == 3) R_fire_set; else R_fire_clr;
if (condition == 4) R_rate_set; else R_rate_clr;


	switch (condition) {
     case CND_STOP:
		 //dNgg_Select
		 //selektor_Gt
		 //regDoz
		 //RegNvd

		 firePresent_clr;
		 Metka = 0;
		 Gt_tek = 0;
		 HPTimer = 0;
		 startTimer = 0;
		 fireTimer = 0;
		 heatTimer = 0;
		 coolTimer = 0;
		 promTimer = 0;
		 Nst_Ust = 0;
		 if (!(check)) setDoz = 0;//Для проверки дозатора в режиме проверки защит и состоянии "СТОП"
		 //setDoz = 0;//Для проверки дозатора в режиме проверки защит и состоянии "СТОП"
		 setSK_ON_clr;//закрыть СК
		 if (nvd < 50) {R_promEnd_clr; endHP_clr;}//чтобы не было необходимости подавать init перед ХП
		 gotoStarterToStop = 0;
		 engineStarted_clr;
		 NO_clr;
		 BIT_SET_M(3713);
		 temperPrev = 0;
		 Nstart_clr;
		 PNstart_clr;
		 //SZ_clr;
		 //VZ_clr;
		 AZ1_clr;
		 AZ2_clr;
         Kp_dop = 25.0;
		 Ki_dop = 1.0;
//		 Kp_Tt = KpTt;
		 Kp_Tst = KpTst;
         Kp_Pk = KpPk;
		 K1_st = K1st;
		 K2_st = K2st;
		 K3_st = K3st;
		 if (gotoToAO) condition = CND_AO; 
		 else {
			 if (gotoStopToStarter) {
				 HPTimer = 0;
				 startTimer = 0;
				 promTimer = 0;
				 condition = CND_STARTER;
			 }
		 }
		 
	 break;	 
     case CND_STARTER:
		 if (HPTimer < 1000000) HPTimer += cycle;
		 if (startTimer < 1000000) startTimer = startTimer + cycle;
		 //SZ_set;
		 //if (startTimer > 10) VZ_set;
		 Nstart_set;
		 setDoz = 0;//выдаем задание на полное закрытие дозатора
		 if (gotoToAO) {//переход к АО
			Nstart_clr;
			PNstart_clr;
			 //SZ_clr;
			 //VZ_clr;
			 endHP_set;
			 R_promEnd_set;
			 condition = CND_AO;
		     HP_clr;
			 R_promGo_clr;//выключить стартер. ДУС и СК закроются при появлении CND_AO
			 gotoStarterToStop = 0;}
		 if (gotoStarterToStop) {//переход к стопу
			 Nstart_clr;
			 PNstart_clr;
			 //SZ_clr;
			 //VZ_clr;
			 condition = CND_STOP;
		     HP_clr;
			 R_promGo_clr;
			 gotoStarterToStop = 0;}
		 if (gotoStarterToFire) {//переход к розжигу
			 temperPrev = Ttzap;//запомнили температуру, предшествующую розжигу
			 Metka = kt_fire;
			 TempRoz = (Gt_roz_max_ust - Gt_roz_min_ust)/(maxFireTime - 2);
			 condition = CND_FIRE;
			 fireTimer = 0.0;} 

	 break;
	 case CND_FIRE:
		 if (startTimer < 1000000) startTimer += cycle;//продолжаем считать время запуска
		 
		if (longZAP)
		 {if ((startTimer > (ignitionTime + longTime)) && (fireTimer < timeIgnitionOff )) {
			 AZ1_set;
			 AZ2_set;}
		 else {
			 AZ1_clr;
			 AZ2_clr;}
		 if (startTimer < (FireTime + longTime)) temperPrev = temperPrev/*Ttzap*/;//запомнили температуру, предшествующую розжигу
		 else {
			 if (fireTimer < 1000000) fireTimer += cycle;//считаем время с момента открытия СК
			 setSK_ON_set;//открываем СК
			 //
			 if ((Ttzap - temperPrev) > dTIgnition) firePresent_set;//факт зажигания определяется по росту температуры по сравнению с температурой в начале розжига
			 if (fireTimer < (maxFireTime - 2.0)) Gt_tek = TempRoz*fireTimer + Gt_roz_min_ust;//увеличиваем плавно расход по алгоритму
			 if (fireTimer > 3) TRegDoz (Ptgpd); else TRegDoz (Ptg);//для коррекции расхода по Pтг первые 3 секунды используем давление перед СК
		 }}
		else {if ((startTimer > ignitionTime) && (fireTimer < timeIgnitionOff )) {
			 AZ1_set;
			 AZ2_set;}
		 else {
			 AZ1_clr;
			 AZ2_clr;}
		 if (startTimer < FireTime) temperPrev = temperPrev/*Ttzap*/;//запомнили температуру, предшествующую розжигу
		 else {
			 if (fireTimer < 1000000) fireTimer += cycle;//считаем время с момента открытия СК
			 setSK_ON_set;//открываем СК
			 if ((Ttzap - temperPrev) > dTIgnition) firePresent_set;//факт зажигания определяется по росту температуры по сравнению с температурой в начале розжига
			 if (fireTimer < (maxFireTime - 2.0)) Gt_tek = TempRoz*fireTimer + Gt_roz_min_ust;//увеличиваем плавно расход по алгоритму
			 if (fireTimer > 3) TRegDoz (Ptgpd); else TRegDoz (Ptg);//для коррекции расхода по Pтг первые 3 секунды используем давление перед СК
		 }}


		 if (gotoToAO) {
			 AZ1_clr;
			 AZ2_clr;
	 		 Nstart_clr;
			 PNstart_clr;
			 //SZ_clr;
			 //VZ_clr;
			 //выключить стартер и АЗ. ДУС и СК закроютсяпри появлении CND_AO
			 condition = CND_AO;
		 }
		 if (gotoFireToRate) {
			 PNstart_set;
			 //инициализация регулятора перед разгоном
			 IntegNvd = nvd;
			 Gt_tek = Gt_roz_ust;
			 integOut = Gt_tek;
			 condition = CND_RATE;
			 }
		 
	 break;	 
     case CND_RATE:
		 //
		 if (startTimer < 1000000) startTimer += cycle;//продолжаем считать время запуска!
		 if AZ1_tst fireTimer += cycle;
		 if ((nvd > NggIgnOff) || (fireTimer >= timeIgnitionOff )) {AZ1_clr;AZ2_clr;}//отключаем АЗ если Ngg>4000 или время работы АЗ > 20с
		 
		if (longZAP)
		 {if ((nvd > NggStarterOff) || (startTimer >= (timeStarterOff + longTime))) {
			 Nstart_clr;
			 PNstart_clr;
			 //SZ_clr;
			 //VZ_clr;
			 n_point = Usk_ust*harakt(dNggToVTZ,Ttzap_ogr_ust-Tt);}
		 else n_point = Usk_ST_ust*harakt(dNggToVTZ,Ttzap_ogr_ust-Tt);}
		else {if ((nvd > NggStarterOff) || (startTimer >= timeStarterOff)) {
			 Nstart_clr;
			 PNstart_clr;
			 //SZ_clr;
			 //VZ_clr;
			 n_point = Usk_ust*harakt(dNggToVTZ,Ttzap_ogr_ust-Tt);}
		 else n_point = Usk_ST_ust*harakt(dNggToVTZ,Ttzap_ogr_ust-Tt);}

		 //Селекция контуров
		 Out_sel1 = (Ngg_MG_ust - IntegNvd)*Kdot;
		 Metka = kt_heatMG;
		 if (Out_sel1 < n_point) Metka = kt_heatMG;
		 else {
			 Out_sel1 = n_point;
			 Metka = kt_n_point;}
		 
		 if ((Starter_Old == 1) && !(Nstart_tst)) IntegNvd = nvd;
			else IntegNvd += Out_sel1*cycle;
		 
		 //IntegNvd += Out_sel1*cycle;
		 Out_fire = Gt_roz_ust - Gt_tek;
		 Kprop_Nvd = harakt(KpropNvd,nvd);
		 Out_sel2 = (Out_sel1*KfNvd + IntegNvd - nvd)*Kprop_Nvd;
		 //Out_kt_ogrGtzap = (harakt(Gt_zap,nvdNorm) + Reg_Gt_ogr_zap)*(1 + harakt(KtGtTinZap,Tvh))*sqrt(Tvh/288.134) - Gt_tek;
		 Out_kt_ogrdGtzap = harakt(dNggToVTZ,Ttzap_ogr_ust-Tt)*dGt_ogr_zap_ust;
		 if (Out_fire > Out_sel2) {
			 Metka = kt_fire;
			 Out_sel2 = Out_fire;
			 IntegNvd = nvd + Out_sel2/Kprop_Nvd - Out_sel1*KfNvd;
		 }
		/* if (Out_kt_ogrGtzap < Out_sel2) {
			 Metka = kt_ogrGt_zap;
			 Out_sel2 = Out_kt_ogrGtzap;
			 IntegNvd = nvd + Out_sel2/Kprop_Nvd - Out_sel1*KfNvd;
		 }
		 */
		 if (Out_kt_ogrdGtzap < Out_sel2) {
			 Metka = kt_ogrdGt_zap;
			 Out_sel2 = Out_kt_ogrdGtzap;
			 IntegNvd = nvd + Out_sel2/Kprop_Nvd - Out_sel1*KfNvd;
		 }
		 //RF(8003) = Out_sel1;
		 //rf(1671) = IntegNvd;
		 //RF(1641) = Out_sel2;
		 integOut +=  cycle*Out_sel2*harakt(KintegDoz,nvd);
		 Gt_tek = integOut + Out_sel2;
		 if (fireTimer > 3) TRegDoz (Ptgpd); else TRegDoz (Ptg);//для коррекции расхода по Pтг первые 3 секунды используем давление перед СК
		 if ((nvd >= 8000) || (nst >= 2700))  engineStarted_set;
		 //if ((Ngg_MG_ust - nvd) < 20) engineStarted_set;
		 if ((heatTimer < 1000000) && heat_tst) heatTimer += cycle;
		 if (gotoToAO) {
			 AZ1_clr;
			 AZ2_clr;
	 		 Nstart_clr;
			 PNstart_clr;
			 //SZ_clr;
			 //VZ_clr;
			 //выключить стартер и АЗ. ДУС и СК закроютсяпри появлении CND_AO
			 condition = CND_AO;
		 }
		 if (gotoRateToStab) {
			 condition = CND_STAB;
			 up_old = 1;
			 down_old = 1;
			 st_old=1;
			 nvd_ust = nvd/CTvhNvd;
			 
		 }
		 

	 break;
	 case CND_STAB:
		 //Вычисление уставки nvd
		 if ((up_old && !up) || (down_old && !(down || downDI)) || (st_old && !stabST_on)) nvd_ust = nvd/CTvhNvd;// для проверки 25 двигателя без /CTvhNvd;
		 up_old = up;
		 down_old = down;
		 st_old = stabST_on;

		 //Уставка Nст

		  if (stabST_on && !NO_tst) {
			 nst_ust_min = Nst_Ust;
			 if (Nst_Ust < minValNst1) nst_ust_min = minValNst1;
			 if (Nst_Ust > Nst_ogr_ust) nst_ust_min = Nst_ogr_ust;
			 dST = nst_ust_min - nst - integr_ST;
		 if (Metka != kt_stabST) integr_ST = 0;
		 else integr_ST += K1_st*cycle*dST;
		 Out_ST = K3_st*(integr_ST + K2_st*dST);		  
		  }
		  else {nst_ust_min = Nst_ogr_ust;
			dST = nst_ust_min - nst;
			integr_ST += Kd_st*cycle*(dST*Kp_st-integr_ST);
			Out_ST = 18*dST*Kp_st - integr_ST;}

		 //Селектор nгг
		 
		 Out_sel1_min = (Ngg_max_ust - IntegNvd)*Kdot;
		 Metka_sel1_min = kt_Nvdogr_up;
		 
		 //Ограничение Nнд сверху
		dNnd = Nnd_max_ust - nnd;		 
		Out_Nnd = 0.5*dNnd;
		if (Out_sel1_min > Out_Nnd) {
			Out_sel1_min = Out_Nnd;
			Metka_sel1_min = kt_Nndogr_up;}
		 
		if (Out_sel1_min > dNgg_UP) {
			 Out_sel1_min = dNgg_UP;
			 Metka_sel1_min = kt_up;}
     	if ((!stabST_on)&&(Out_sel1_min > Out_ST)) {
			 Out_sel1_min = Out_ST;
			 Metka_sel1_min = kt_Nstogr_up;}


		 if (((!up)&&(!stabST_on))||(((nst_ust_min - nst) <0)&&(stabST_on)) || NO_tst) {
			 //Out_sel1 = (Ngg_MG_ust - IntegNvd)*Kdot;
			 //Metka = kt_ogrMG;

			 if NO_tst Out_sel1 = dNgg_SBROS;
			 else Out_sel1 = dNgg_DOWN;//{
				 //if (Out_sel1 < dNgg_SBROS) {
				//	 Out_sel1 = dNgg_SBROS;
				//	 Metka = kt_down;}}
			 //else {
			//	 if (Out_sel1 < dNgg_DOWN) {
			//		 Out_sel1 = dNgg_DOWN;
					 Metka = kt_down;//}}
			 if (!(down||downDI) && !NO_tst && !stabST_on && (Out_sel1 < (nvd_ust*CTvhNvd/* для проверки 25 двигателя без *CTvhNvd */ - IntegNvd)*Kdot)) {
				 Out_sel1 = (nvd_ust*CTvhNvd - IntegNvd)*Kdot;
				 Metka = kt_GG;}
			 if (Out_sel1_min < Out_sel1) {
				 Out_sel1 = Out_sel1_min;
				 Metka = Metka_sel1_min;}
			 else Metka_sel1_min = Metka;}
		 else {
			 Out_sel1 = Out_sel1_min;
			 Metka = Metka_sel1_min;}
		 
		// RF(1785)=Metka;
		 Out_MG = (Ngg_MG_ust - IntegNvd)*Kdot;
		 IntegNvdMG = IntegNvd + Out_MG*cycle;

		 IntegNvd += Out_sel1*cycle;
		 Kprop_Nvd = Kp_dop*harakt(KpropNvd,nvd);
		 Out_kt_Nvd = (Out_sel1*KfNvd + IntegNvd - nvd)*Kprop_Nvd;
		 Out_kt_MG = (Out_MG*KfNvd + IntegNvdMG - nvd)*Kprop_Nvd;
		

		 




		 //Второй селектор
		 
//Контур Nст
		
//RF(1783)=Out_ST;
//RF(1785)=Out_kt_Nvd;

Out_sel2 = Out_kt_Nvd;
if (stabST_on && !NO_tst) {


		 if ((nst_ust_min - nst) <0) {

if (Out_ST > Out_kt_Nvd) {
			 Out_sel2 = Out_ST;
			 Metka = kt_stabST;
			 }
}
else {

if (Out_ST < Out_kt_Nvd) {
			 Out_sel2 = Out_ST;
			 Metka = kt_stabST;
			 }
}}

    
//Контур ограничения расхода топлива
		 
		 if ((Gt_ogr_ust - Gt_tek) < Out_sel2) {
			 Out_sel2 = Gt_ogr_ust - Gt_tek;
			 Metka = kt_ogrGt_osn;}
/*
		 //Контур ограничения Тт
		 Out_Tt = (Tt_ogr_ust - Tt)*Kp_Tt;
		 if (Out_Tt < Out_sel2) {
			 Out_sel2 = Out_Tt;

			 Metka = kt_Tt;}
*/
		 //Контур ограничения Тст
		 Out_Tst = (Tst_ogr_ust - Tst)*Kp_Tst;
		 if (Out_Tst < Out_sel2) {
			 Out_sel2 = Out_Tst;

			 Metka = kt_Tst;}
			 
		 //Контур ограничения Pk
		 Out_Pk = (Pk_ogr_ust - Pkvd)*Kp_Pk;
		 if (Out_Pk < Out_sel2) {
			 Out_sel2 = Out_Pk;
			 Metka = kt_Pk;}
		 
		 //Контур ограничения Gt/Pk
		 Out_GtPk = GtPk_ogr_ust - Gt_tek;
		 if (Out_GtPk < Out_sel2) {
			 Out_sel2 = Out_GtPk;
			 Metka = kt_GtPk;}

//         Delta_GtPk = Out_GtPk; 
		 
RF(1781)=Out_Tst;
RF(1783)=Metka;
RF(1785)=Gt_tek;
RF(1787)=GtPk_ogr_ust;
RF(1789)=Out_Pk;


		 //||Селектор максимума
		 if (Out_kt_MG > Out_sel2) {
			 Out_sel2 = Out_kt_MG;
			 Metka = kt_ogrMG;
			 IntegNvd = IntegNvdMG;}

		 //Установка интегратора для безударного перехода с контура на контур!
		 if (Metka > kt_up) {
			 IntegNvd = nvd;// + Out_sel2/Kprop_Nvd - Out_sel1*KfNvd;
			 
		 }


		 //Вычисление расхода
		// RF(1789)=Out_sel2;

		 integOut +=  cycle*Out_sel2*Ki_dop*harakt(KintegDoz,nvd);
		 Gt_tek = integOut + Out_sel2;
		 TRegDoz (Ptgpd);

		 if ((coolTimer < 1000000) && NO_tst) coolTimer += cycle;

		 if (gotoStabToStop) 
		 {condition = CND_STOP;
		 firePresent_clr;
		 Metka = 0;
		 Gt_tek = 0;
		 HPTimer = 0;
		 startTimer = 0;
		 HP_clr;

		 fireTimer = 0;
		 heatTimer = 0;
		 coolTimer = 0;
		 Nst_Ust = 0;
		 setDoz = 0;
		 NO_clr;
		 setSK_ON_clr;//закрыть СК
		 if (nvd < 50) endHP_clr;//чтобы не было необходимости подавать init перед ХП
		 engineStarted_clr;
		 startEngine_clr;
		 heat_clr;}


		 if (gotoToAO) {condition = CND_AO;setDoz = 0;}

	 break;
	 case CND_AO:
		 firePresent_clr;
		 Metka = 0;
		 Gt_tek = 0;
		 HPTimer = 0;
		 startTimer = 0;
		 HP_clr;
 		 Nstart_clr;
		 PNstart_clr;
		 //SZ_clr;
		 //VZ_clr;
		 AZ1_clr;
		 AZ2_clr;
		 fireTimer = 0;
		 heatTimer = 0;
		 coolTimer = 0;
		 promTimer = 0;
		 Nst_Ust = 0;
		 if (!(check&&(nvd<100))) setDoz = 0;//Для проверки дозатора в режиме проверки защит и состоянии "АО"
		 //setDoz = 0;//Для проверки дозатора в режиме проверки защит и состоянии "АО"
		 NO_clr;
		 setSK_ON_clr;//закрыть СК
		 if (nvd < 50) {endHP_clr; R_promEnd_clr;}//чтобы не было необходимости подавать init перед ХП
		 gotoStarterToStop = 0;
		 engineStarted_clr;
		 startEngine_clr;
		 heat_clr;
		 
		 if (gotoAOToStop) condition = CND_STOP;	 
	 break;}

}
if (gotoStopToStarter) {VibegGGTimer=0; VibegSTTimer=0;VibegKNDTimer=0;}

RF(1517) = RF(1517) - 273;

RF(1519) = RF(1519) - 273;

RF(1521) = RF(1521) - 273;

RF(1523) = RF(1523) - 273;

if (Nstart_tst) Starter_Old = 1;
	else Starter_Old = 0;

	
		// !Ручное управление исполнительными механизмами
// Ручное управление дозатором
if (!(((condition == CND_STOP)||(condition == CND_AO))&&(nvd<100)&& check &&(Ptgpd<0.03)&& SK_OFF_tst)) manual_upr_DOZ_clr;
if (manual_upr_DOZ_tst) setDoz = manual_setDOZ;
	else manual_setDOZ = 0;
	
	// Ручное управление ВНА
if (!(((condition == CND_STOP)||(condition == CND_AO))&&(nvd<100)&& check &&(Ptgpd<0.03)&& SK_OFF_tst)) manual_upr_VNA_clr;
if (manual_upr_VNA_tst) set_VNA = manual_setVNA;
	else manual_setVNA = -45.0;
	
	
	
	

// Ручное управление СК
if (!(((condition == CND_STOP)||(condition == CND_AO))&&(nvd<100)&& check &&(Ptg<0.03)&&(posDOZ<0.5))) manual_upr_SK_clr;
if (manual_upr_SK_tst)
	{if (manual_SK_ON_tst) manual_SK_ON = 1;
	 if (manual_SK_OF_tst) manual_SK_ON = 0;
	 if (manual_SK_ON) setSK_ON_set;
		else setSK_ON_clr;
	}
/*
if (!(((condition == CND_STOP)||(condition == CND_AO))&&(nvd<100)&& check &&(Ptg<0.03)&&(posDOZ<0.5))) manual_upr_SK_clr;
if (manual_upr_SK_tst)
	{if (manual_SK_ON_tst) manual_SK_ON = 1;
	 if (manual_SK_OF_tst) manual_SK_ON = 0;
	 if (manual_SK_ON) setSK_ON1_set;
		else setSK_ON1_clr;
	}
	
if (setSK_ON1_tst) setSK_ON_timer += cycle;
if (setSK_ON_timer > 10.0) setSK_ON_timer = 10.0; 
if (!setSK_ON1_tst) setSK_OF_timer += cycle;
if (setSK_OF_timer > 10.0) setSK_OF_timer = 10.0; 

if (setSK_ON1_tst && (setSK_ON_timer < 10.0)) {setSK_ON_set; setSK_OF_timer = 0.0;}
	else setSK_ON_clr;
if ((!setSK_ON1_tst) && (setSK_OF_timer < 10.0)) {setSK_OFF_set; setSK_ON_timer = 0.0;}
	else setSK_OFF_clr;
*/
	
// Ручное управление КПВ	
if (!(((condition == CND_STOP)||(condition == CND_AO))&&(nvd<100)&& check)) manual_upr_KPV_clr;
if (manual_upr_KPV_tst)
	{if (manual_KPV_ON_tst) manual_KPV_ON = 1;
	 if (manual_KPV_OF_tst) manual_KPV_ON = 0;
	 if (manual_KPV_ON) KPV_ON;
		else KPV_OFF;
	}

	// Ручное управление КПВЗ
if (!(((condition == CND_STOP)||(condition == CND_AO))&&(nvd<100)&& check)) manual_upr_KPG_clr;
if (manual_upr_KPG_tst)
	{if (manual_KPG_ON_tst) manual_KPG_ON = 1;
	 if (manual_KPG_OF_tst) manual_KPG_ON = 0;
	 if (manual_KPG_ON) KPG_ON;
		else KPG_OFF;
	}

// Ручное управление ЗПВ1	
if (!(((condition == CND_STOP)||(condition == CND_AO))&&(nvd<100)&& check)) manual_upr_ZPV1_clr;
if (manual_upr_ZPV1_tst)
	{if (manual_ZPV1_ON_tst) manual_ZPV1_ON = 1;
	 if (manual_ZPV1_OF_tst) manual_ZPV1_ON = 0;
	 if (manual_ZPV1_ON) ZPV1_ON;
		else ZPV1_OFF;
	}
	
	// Ручное управление ЗПВ2	
if (!(((condition == CND_STOP)||(condition == CND_AO))&&(nvd<100)&& check)) manual_upr_ZPV2_clr;
if (manual_upr_ZPV2_tst)
	{if (manual_ZPV2_ON_tst) manual_ZPV2_ON = 1;
	 if (manual_ZPV2_OF_tst) manual_ZPV2_ON = 0;
	 if (manual_ZPV2_ON) ZPV2_ON;
		else ZPV2_OFF;
	}
/*
	// Ручное управление СЗ
if (!(((condition == CND_STOP)||(condition == CND_AO))&&(nvd<100)&& check &&(PgInStV<0.03)&&(!VZ_tst))) manual_upr_SZ_clr;
if (manual_upr_SZ_tst)
	{if (manual_SZ_ON_tst) manual_SZ_ON = 1;
	 if (manual_SZ_OF_tst) manual_SZ_ON = 0;
	 if (manual_SZ_ON) SZ_set;
		else SZ_clr;
	}

	// Ручное управление ВЗ
if (!(((condition == CND_STOP)||(condition == CND_AO))&&(nvd<100)&& check &&(PgInStV<0.03)&&(!SZ_tst))) manual_upr_VZ_clr;
if (manual_upr_VZ_tst)
	{if (manual_VZ_ON_tst) manual_VZ_ON = 1;
	 if (manual_VZ_OF_tst) manual_VZ_ON = 0;
	 if (manual_VZ_ON) VZ_set;
		else VZ_clr;
	}
*/
	// Ручное управление АЗ1
if (!(((condition == CND_STOP)||(condition == CND_AO))&&(nvd<100)&& check &&(AZ1timer < 30.0))) manual_upr_AZ1_clr;
if (manual_upr_AZ1_tst)
	{if (manual_AZ1_ON_tst) manual_AZ1_ON = 1;
	 if (manual_AZ1_OF_tst) manual_AZ1_ON = 0;
	 if (manual_AZ1_ON) AZ1_set;
		else AZ1_clr;
	}
if (AZ1_tst) AZ1timer += cycle;
		else AZ1timer = 0.0;
if (AZ1timer > 30.0) AZ1timer = 30.0;
	
// Ручное управление АЗ2
if (!(((condition == CND_STOP)||(condition == CND_AO))&&(nvd<100)&& check &&(AZ2timer < 30.0))) manual_upr_AZ2_clr;
if (manual_upr_AZ2_tst)
	{if (manual_AZ2_ON_tst) manual_AZ2_ON = 1;
	 if (manual_AZ2_OF_tst) manual_AZ2_ON = 0;
	 if (manual_AZ2_ON) AZ2_set;
		else AZ2_clr;
	}
if (AZ2_tst) AZ2timer += cycle;
		else AZ2timer = 0.0;
if (AZ2timer > 30.0) AZ2timer = 30.0;

return GEF_EXECUTION_OK;
}
