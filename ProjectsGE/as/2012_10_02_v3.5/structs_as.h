#pragma pack(2)

typedef struct
{
    // Время интегрирования положения АПК (для имитации задержки)
    T_REAL32 POS_TS;
    // Нижний предел положения АПК
    T_REAL32 POS_LO;
    // Верхний предел положения АПК
    T_REAL32 POS_HI;
    // Нижний предел dP соответствующий нижнему положению АПК
    T_REAL32 dP_pos_LO;
    // Верхний предел dP соответствующий нижнему положению АПК
    T_REAL32 dP_pos_HI;
    // Смещение dP по POS
    T_REAL32 POS_off;
    // Нижний предел Pout
    T_REAL32 Pout_LO;
    // Верхний предел Pout
    T_REAL32 Pout_HI;
    // Нижний предел dP соответствующий нижнему пределу Pout
    T_REAL32 dP_Pout_LO;
    // Нижний предел dP соответствующий верхнему пределу Pout
    T_REAL32 dP_Pout_HI;
    // Смещение dP по Pout
    T_REAL32 Pout_off;
    // Иммитация помпажа
    T_REAL32 surge;	
    // dP, кПа
    T_REAL32 dPimit;	
} AS_Imit;

typedef struct
{
    // Скорость открытия АПК в режиме Разгрузки, % в сек
    T_REAL32 ASR_StopRazgr;
    // Скорость закрытия АПК в режиме Загрузки, % в сек
    T_REAL32 ASR_RunZagr;
    // Скорость открытия АПК в режиме AO, % в сек
    T_REAL32 ASR_AO;
    // Скорость открытия АПК в режиме Продувки, % в сек
    T_REAL32 ASR_Produv_Open;
    // Скорость закрытия АПК в режиме Продувки, % в сек
    T_REAL32 ASR_Produv_Close;
    // Скорость уменьшения задания регулятору
    T_REAL32 ASR_SP_DN;
    // Скорость увеличения ручного задания, % в сек 
    T_REAL32 ASR_Man_UP;
    // Скорость уменьшения ручного задания, % в сек 
    T_REAL32 ASR_Man_DN;
    // Ограничение скорости закрытия клапана, % в сек 
    T_REAL32 ASR_DN;
    // Порог скорости изменения Pin (контроль обрыва)
    T_REAL32 Pin_SpeedLim;
    // Порог скорости изменения Pout (контроль обрыва)
    T_REAL32 Pout_SpeedLim;
    // Порог скорости изменения Tin (контроль обрыва)
    T_REAL32 Tin_SpeedLim;
    // Порог скорости изменения Tout (контроль обрыва)
    T_REAL32 Tout_SpeedLim;	
} AS_ConstLS;

typedef struct
{
    // Номинальная частота вращения нагнетателя, об/мин
    T_REAL32 Nnom;
    // Коэффициент конфузора нагнетателя
    T_REAL32 KKH;
    // Постоянная времени фильтра датчика "Перепад на конфузоре"
    T_REAL32 TS_dP;
} AS_ConstNag;

typedef struct
{
    // Фиксатор верхнего уровня
    T_REAL32 H_LIM;
    // Фиксатор нижнего уровня
    T_REAL32 L_LIM;
    // Зона нечувствительности
    T_REAL32 Ky_DB;
    T_REAL32 Pout_Kp;
    T_REAL32 Pout_Ki;
    // Зона нечувствительности
    T_REAL32 Pout_DB;
    // Верхний диаппазон Pout
    T_REAL32 Pout_HI;
    // Нижний диаппазон Pout
    T_REAL32 Pout_LO;
    T_REAL32 RY04_Kp;
    T_REAL32 RY04_Ki;
    // Зона нечувствительности
    T_REAL32 RY04_DB;
    // Верхний диаппазон E
    T_REAL32 RY04_HI;
    // Нижний диаппазон E
    T_REAL32 RY04_LO;
    T_REAL32 Scale_Kp_gt_0[10];
    T_REAL32 Scale_Kp_lt_0[10];
    T_REAL32 Scale_Ki_gt_0[10];
    T_REAL32 Scale_Ki_lt_0[10];
    // Количество точек Кп в положительную сторону
    T_REAL32 Points_Kp_gt_0;
    // Количество точек Кп в отрицательную сторону
    T_REAL32 Points_Kp_lt_0;
    // Количество точек Ки в положительную сторону
    T_REAL32 Points_Ki_gt_0;
    // Количество точек Ки в отрицательную сторону
    T_REAL32 Points_Ki_lt_0;
} AS_ConstReg;

typedef struct
{
    // Процент положения АПК при обрыве датчиков
    T_REAL32 APK_O_const;
    // Линия регулирования, %
    T_REAL32 Line_Reg;
    // Линия ступенчатого открытия АПК, %
    T_REAL32 Line_Step;
    // Величина первого приращения SP_M, %
    T_REAL32 Step_First_var;
    // Величина второго приращения SP_M, %
    T_REAL32 Step_Second_var;
    // Дискретность изменения SP_M При пересечении линии LineStep, msec
    T_REAL32 Step_Time;
    // Время интегрирования снятия Step воздействия. Чем больше уставка, тем медленнее возврат
    T_REAL32 Step_TS;
    // Значение дополнительного сигнала
    T_REAL32 Dead_In_dop;
    // Линия срабатывания алгоритма по скорости приближения к границе помпажа
    T_REAL32 Line_Speed;
    T_REAL32 Line_EndZagr;
    // Максимальная величина скорости приближения к границе помпажа
    T_REAL32 Speed_RY03_Alm;
    // Величина приращения SP регулятора при критической скорости приближения к границе помпажа
    T_REAL32 dSP_SpeedAlm;
    // Коэффициент Дифференцирования переменной "Скорость изменения SP"
    T_REAL32 dSP_Kd;
    // Линия Защиты, %
    T_REAL32 Line_Safety;
    // Величина смещения, %
    T_REAL32 LineSafety_Shift;
    // Задание количества пересечений линии Line_Safety
    T_REAL32 LineSafety_Ust;
    // Время между "Хлопками", msec
    T_REAL32 LineSafety_TimeSet;
    // Время сброс счетчика “Хлопков”, msec
    T_REAL32 LineSafety_TimeReset;
    // Линия плотного закрытия, %
    T_REAL32 Line_NotOpen;
    // Ограничение нижнего предела АПК, %
    T_REAL32 NotOpen_Lim;
    // Линия границы помпажа
    T_REAL32 Line_Surge;
    // Пороговое значение включения алгоритма SpeedUP Pd
    T_REAL32 SpeedUP_dPd;
    // Пороговое значение включения алгоритма SpeedDN Ps
    T_REAL32 SpeedDN_dPs;
    // Коэффициент усиления алгоритма SpeedUP Pd
    T_REAL32 SpeedUP_Pd_Ku;
    // Коэффициент усиления алгоритма SpeedDN Ps
    T_REAL32 SpeedDN_Ps_Ku;
    // Время интегрирования фильтра SpeedUP Pd
    T_REAL32 SpeedUP_Pd_TS;
    // Время интегрирования фильтра SpeedDN Ps
    T_REAL32 SpeedDN_Ps_TS;
    // Время интегрирования снятия SpeedUP Pd воздействия. Чем больше уставка, тем медленнее возврат
    T_REAL32 SpeedUP_TS;
    // Время интегрирования снятия SpeedDN Ps воздействия. Чем больше уставка, тем медленнее возврат
    T_REAL32 SpeedDN_TS;
    // Задание ограничения давления газа на выходе нагнетателя
    T_REAL32 P_out_Lim_SP;
    // Задание ограничения степени сжатия
    T_REAL32 RY04_Lim_SP;
    // Линия помпажа
    T_REAL32 SurgeArray[6];
    // Количество помпажных точек
    T_REAL32 Num_surge_point;
} AS_ConstSurge;

typedef struct
{
    // Задание для алгоритма Step
    T_REAL32 RT_var;
    // Выход алгоритма Step
    T_REAL32 CV_RT;
    // Выход ПИД контура
    T_REAL32 CV_Reg;
    // CV_RT + CV_Reg
    T_REAL32 CV_AS;
    // Выход POC Pd
    T_REAL32 CV_PD;
    // Выход POC Ps
    T_REAL32 CV_PS;
    // Выход POC
    T_REAL32 CV_POC;
    // Селектор максимума
    T_REAL32 CV_MAX;
    // Выход АПР
    T_REAL32 oCV_R;
} AS_CV;

typedef struct
{
    // Степень сжатия
    T_REAL32 R_c;
    // Барометрическое давление, (ks/cm2)
    T_REAL32 B_;
    // Давление на входе в нагнетатель, (ks/cm2)
    T_REAL32 Pin;
    // Давление на выходе из нагнетателя, (ks/cm2)
    T_REAL32 Pout;
    // Температура на входе в нагнетатель, (грK)
    T_REAL32 Tin;
    // Температура на выходе из нагнетателяь, (грK)
    T_REAL32 Tout;
    // Относительная плотность газа по воздуху
    T_REAL32 p_;
    // Газовая постоянная, кГм/кгК
    T_REAL32 R;
    // Средняя температура
    T_REAL32 Tsr;
    // Среднее давление
    T_REAL32 Psr;
    // Коэффициент сжимаемости по входу
    T_REAL32 Zin;
    T_REAL32 Zout;
    // Коэффициент сжимаемости по выходу
    T_REAL32 Zsr;
    // Температурный показатель политропы
    T_REAL32 mt;
    // Показатель псевдоизоэнтропы
    T_REAL32 k;
    // Плотность на входе в нагнетатель
    T_REAL32 p_N;
    // val= d_P*p_N
    T_REAL32 val;
    // Q = KKN * sqrt(val);
    T_REAL32 Q;
    // Массовый расход газа. G = KKN * sqrt(val1)/60;
    T_REAL32 G;
    // Приведенная производительность (м3/час). Q_pr = Q * (Nnom/N);
    T_REAL32 Q_pr;
    // Запас по помпажу %. Ky = 100 * (*Q_pr - Q_min) / Q_min
    T_REAL32 Ky;
    // Мощность потребляемая ЦБК
    T_REAL32 Ni;
    // Эффективная мощность ЦКБ
    T_REAL32 Ne;
    // политропный КПД
    T_REAL32 KPD;
} AS_MASS;
 
typedef struct 
{
    // Версия ПО
    T_REAL32 ver;
    // Ограничение верхнего уровня CV, %
    T_REAL32 hiLim;
    // Ограничение нижнего уровня CV, %
    T_REAL32 loLim;
    // Минимальный расход газа после характерайзера
    T_REAL32 Q_min;
    // Невозможно рассчитать расход
    T_INT16 Q_OK;
    // Невозможно рассчитать расход или обрыв датчика dP
    T_INT16 APK_ON_const;
    // если = 1, то АПК перейдет в положение 50%
    T_INT16 On_RUN;
    // Датчики в норме
    T_INT16 Sensor_OK;
    // Плотность газа с датчика
    T_REAL32 PL_Gi;
    // Плотность газа с датчика после фильтра
    T_REAL32 pl_g;
    // Pin до блока AI_SPEED
    T_REAL32 P_IN;
    // Pin после блока AI_SPEED
    T_REAL32 Pin;
    // Pout до блока AI_SPEED
    T_REAL32 P_OUT;
    // Pout после блока AI_SPEED
    T_REAL32 Pout;
    // Перепад газа на конфузоре с датчика
    T_REAL32 DPi;
    // Перепад газа на конфузоре после фильтра
    T_REAL32 dP;
    // Перепад газа на конфузоре после фильтра при обрыве
    T_REAL32 dP1;
    // Температура газа на входе с датчика
    T_REAL32 T_IN;
    // Температура газа на входе после фильтра при обрыве
    T_REAL32 Tin;
    // Скорость изменения Ку
    T_REAL32 KySpeed;
    // Максимальное значение Ky
    T_REAL32 Ky_SpeedMax;
    // Величина приращения SP регулятора при критической скорости приближения к границе помпажа
    T_REAL32 dSP_SpeedAlm;
    // Меняем значение в зависимости от скорости Ky
    T_REAL32 dDev_SP;
    T_INT16 dDev;
    // Заход в зону помпажа
    T_INT16 SO_Start;
    // Работа алгоритма SO
    T_INT16 dSO;
    // Если сработал алгоритм SO, то запускаем таймер
    T_INT16 XLOPOK;
    // Поправка к линии регулирования
    T_REAL32 dSO_Reg;
    // Ручное задание положения
    T_REAL32 oSP_M;
    // Ручное задание положения с ограничением по скорости изменения
    T_REAL32 oSP_M_Current;
	T_INT16 MA_AS;
    // Имитация перепада по положению АПК
    T_REAL32 dP_1;
    // Имитация перепада по Pout
    T_REAL32 dP_2;	
} AS_Temp;

typedef struct
{
    // Линия защиты
    T_REAL32 LineSO;
    // Линия ступенчатого открытия
    T_REAL32 LineRT;
    // Линия плотного закрытия АПК
    T_REAL32 LineTS;
    // Линия регулирования
    T_REAL32 LineReg;
    T_REAL32 LineRegR;
    // Линия алгоритма по скорости приближения
    T_REAL32 LineSpeed;
    // Линия уставки для ПИД контура
    T_REAL32 LineSP;
    // Линия окончания загрузки
    T_REAL32 LineEndZagr;
} AS_oLine;

typedef struct
{
    // Обороты СТ
    T_REAL32 NST;
    // Давление газа на входе нагнетателя, кПа
    T_REAL32 P_IN;
    // Давление газа на выходе нагнетателя, кПа
    T_REAL32 P_OUT;
    // Температура газа на входе нагнетателя, грС
    T_REAL32 T_IN;
    // Температура газа на выходе нагнетателя, грС
    T_REAL32 T_OUT;
    // Перепад газа на конфузоре нагнетателя, кПа
    T_REAL32 DP;
    // Плотность газа
    T_REAL32 PL_G;
    // Барометрическое давление, кПа
    T_REAL32 B;
    // Задание положения АПР (ручноя уставка), %
    T_REAL32 SP_M;
    // Время цикла ПЛК, сек
    T_REAL32 TSCAN;
    // Положение АПК
    T_REAL32 POS;	
} AS_IN;
 
typedef struct
{
    // Включить защиты АПР
    T_INT16 ON;
    // Работа в ручном режиме без ограничения по запасу помпажа
    T_INT16 MOR;
    // Ручной - 1 / Автомат - 0
    T_INT16 MAN_ON;
    // Сигнал АО (полное мгновенное открытие АПК)
    T_INT16 iAO;
    // Stop - 1 / Run - 0
    T_INT16 SR;
    // Продувка (Мгновенное закрытие АПК)
    T_INT16 PRODUV_ON;
    // АПК открыт
    T_INT16 APK_O;
    // АПК закрыт
    T_INT16 APK_C;
    // Режим "Магистраль"
    T_INT16 MD_MAG;
    // Режим "Кольцо"
    T_INT16 MD_RING;
    // Выключить алгоритм ограничения по скорости приближения к зоне помпажа скорости 
    T_INT16 DIFF_OF;
    // Выключить алгоритм POC Ps
    T_INT16 PS_OF;
    // Выключить алгоритм POC Pd
    T_INT16 PD_OF;
    // Сброс SO
    T_INT16 RES_SO;
    // Сброс счетчика Хлопков
    T_INT16 RES_HLOP;
    // Тест алгоритма SO (возможен АО)
    T_INT16 TEST_SO;
    // Тест алгоритма Step
    T_INT16 TEST_RT;
    // Тест алгоритма Diff
    T_INT16 TEST_DIFF;
    T_INT16 NST_F;
    // Давление газа на входе нагнетателя. Неисправность канала
    T_INT16 P_IN_F;
    // Давление газа на выходе нагнетателя. Неисправность канала
    T_INT16 P_OUT_F;
    // Температура газа на входе нагнетателя. Неисправность канала
    T_INT16 T_IN_F;
    // Температура газа на выходе нагнетателя. Неисправность канала
    T_INT16 T_OUT_F;	
    // Перепад на конфузоре. Неисправность канала
    T_INT16 DP_F;
    // Имитатор включен
    T_INT16 OnImit;	
} AS_INb; 
 
typedef struct
{
    // Степень сжатия нагнетателя
    T_REAL32 Rc;
    T_REAL32 Q_pr;
    T_REAL32 Q;
    T_REAL32 Ky;
    T_REAL32 CV_R;
    T_REAL32 SP_M_Current;
    T_REAL32 NumHlop;
    T_REAL32 loop_selected;
    T_REAL32 KySpeedMax;
    T_REAL32 dPs_max[2];
    T_REAL32 dPd_max[2];
    T_REAL32 Q_min;
    T_REAL32 Pin_MaxSpeed;
    T_REAL32 Pout_MaxSpeed;
    T_REAL32 Tin_MaxSpeed;
    T_REAL32 Tout_MaxSpeed;	
    T_REAL32 Ni;
    // Эффективная мощность ЦКБ
    T_REAL32 Ne;	
    T_REAL32 G;
	T_REAL32 KPD;
    T_REAL32 dI_part1;
    T_REAL32 err2;
    T_REAL32 err3;
} AS_OUT;

typedef struct
{
    T_INT16 APR_MA;
    T_INT16 oAO;
    T_INT16 dSO;
    T_INT16 dRT;
    T_INT16 POC_PS;
    T_INT16 POC_PD;
    T_INT16 MD_PROD;
    T_INT16 MD_STOP;
    T_INT16 MD_RUN;
    T_INT16 MD_ZAGR;
    T_INT16 MD_RAZGR;
    T_INT16 Ky_Act;
    T_INT16 P_out_Act;
    T_INT16 Rc_Act;
    T_INT16 pid_struct_1_active;
    T_INT16 pid_struct_2_active;
    T_INT16 pid_struct_3_active;
    T_INT16 dDev;
} AS_OUTb;


typedef struct
{
    // Входы аналоговые
    AS_IN AS_IN;
    // Входы дискретные
    AS_INb AS_INb;
    // Выходы аналоговые
    AS_OUT AS_OUT;
    // Выходы дискретные
    AS_OUTb AS_OUTb;
    // Константы нагнетателя
    AS_ConstNag ConstNag;
    // Константы ПИ регулятора
    AS_ConstReg ConstReg;
    // Линии регулирования
    AS_ConstLS ConstLS;
    // Константы АПР
    AS_ConstSurge ConstSurge;
    // Для наладки
    AS_Temp AS_Temp;
    // Для наладки
    AS_MASS AS_MASS;
    // Для наладки
    AS_CV AS_CV;
    // Линии защит расчетные
    AS_oLine AS_oLine;
    // Имитатор dP
    AS_Imit AS_Imit;	
} AS_Struct;

//****************************
typedef struct
{
    T_REAL32 Pin_SpeedBuf[6];
    T_REAL32 Pout_SpeedBuf[6];
    T_REAL32 Tin_SpeedBuf[6];
    T_REAL32 Tout_SpeedBuf[6];	
    T_REAL32 pl_g_tmp;
    T_REAL32 dP_tmp;
    T_REAL32 dP1_tmp;
    T_REAL32 Tin_tmp;
    T_REAL32 KyBuff[4];
    T_REAL32 SP_Ky;
    T_REAL32 CVRegSpeed;
    T_INT16 On_RUN1;
    T_INT16 MA_AS1;
    T_INT16 TEST_SO1;
    T_INT16 XLOPOK1;
    T_INT16 dSO1;
    T_INT16 MAN_ON1;
    T_INT16 dRT1;
    T_INT16 up_CV1;
    T_INT16 OnTimRT1;
    T_INT16 SR1;
    T_REAL32 P_IN1;
    T_REAL32 P_OUT1;
    T_REAL32 POC_PS_var;
    T_REAL32 POC_PD_var;	
    T_INT16 MA_AS_fp;
    T_INT16 MA_AS_fn;
    T_INT16 On_RUN_fp;
	T_REAL32 POS_tmp;
} AS_swop;
 

#pragma pack()
  

