#ifndef _structs_h_
#define _structs_h_
#pragma pack(2)

// Команды из алгоритма
typedef struct
{
    // Запрет выхода
    T_BYTE DO_Ban: 1;
    // Запрет РУ
    T_BYTE RU_Ban: 1;
 //   T_BYTE filler1[1];
} IM_ALG;

// Команды автоматические
typedef struct
{
    // Открыть/включить
    T_BYTE ON: 1;
    // Закрыть/выключить
    T_BYTE OF: 1;
 //   T_BYTE filler1[1];
} IM_AVT;

// Кнопки
typedef struct
{
    // Кнопка открыть / включить 
    T_WORD ON;
    // Кнопка закрыть / выключить
    T_WORD OF;
    // Ручное /автоматическое управление
    T_WORD RU;
    // Остановить
    T_WORD STOP;
} IM_BTN;

// Настройки
typedef struct
{
    // Отключение обработки блока
    T_BYTE Disable: 1;
//    T_BYTE filler1[1];
    // Время до срабатывания аварии
    T_REAL32 T_Alarm;
    // Время контроля цепей управления
    T_REAL32 T_KCU;
    // Время формирования сигнала "нестрагивание"
    T_REAL32 T_NotMove;
    // Время формирования сигналов "не открыт, не закрыт"
    T_REAL32 T_NotCO;
    // Время дожима
    T_REAL32 T_Press;
    // Таймер форсировки
    T_REAL32 T_Force;
    // Время между подачей повторных команд
    T_REAL32 T_Block;
    // Время перестановки в режиме имитации 
    T_REAL32 T_Imit;
    // Тип КЦУ (с переключением входа при выдаче выхода или без переключения)
    T_BYTE TYPE_KCU: 1;
    // Дожим при самопроизвольной перестановке
    T_BYTE Come_Back: 1;
    // Инициализация при включении (перемещать / не перемещать)
    T_BYTE INIT: 1;
    // Использование управления с МУК
    T_BYTE MUK: 1;
    // Включить форсировку открытия
    T_BYTE ONForceEN: 1;
    // Включить форсировку закрытия
    T_BYTE OFForceEN: 1;
    // Включить КЦУ команды ON
    T_BYTE KCU_ON_EN: 1;
    // Включить КЦУ команды OFF
    T_BYTE KCU_OF_EN: 1;
    // Сбросить счетчик включений / наработку
    T_BYTE NarabReset: 1;
    // Тип блока
    T_WORD TYPE_IM;
    // Приоритет ручного
    T_BYTE PRIORITY_RU: 1;		
} IM_CFG;

// Дискретные входы
typedef struct
{
    // Открыт/включен
    T_BYTE ON: 1;
    // Закрыт/выключен
    T_BYTE OF: 1;
    // Контроль цепи открытия
    T_BYTE KCU_ON: 1;
    // Контроль цепи закрытия
    T_BYTE KCU_OF: 1;
    // Перемещение
    T_BYTE Move: 1;
    // Срабатывание муфты ограничения момента
    T_BYTE M_Mufft: 1;
    // Вибрация
    T_BYTE Vibr: 1;
    // Низкий уровень масла
    T_BYTE Loil: 1;
    // Отсутствие напряжения
    T_BYTE U_OF: 1;
    // Низкое давление масла
    T_BYTE Poil: 1;
 //   T_BYTE filler1[1];
} IM_DI;

// Дискретные выходы
typedef struct
{
    // Открыть/включить
    T_BYTE ON: 1;
    // Закрыть/выключить
    T_BYTE OF: 1;
    // Остановить
    T_BYTE STOP: 1;
    // Форсировать открытие
    T_BYTE ONForce: 1;
    // Форсировать закрытие
    T_BYTE OFForce: 1;
 //   T_BYTE filler1[1];
} IM_DO;

// Предупреждения
typedef struct
{
    // Срабатывание муфты ограничения момента
    T_WORD M_Mufft;
    // Не открыт/не включен
    T_WORD notON;
    // Не закрыт/не выключен
    T_WORD notOF;
    // Самопроизвольное открытие / включение
    T_WORD SPON;
    // Самопроизвольное закрытие / выключение
    T_WORD SPOF;
    // Неисправность конечных выключателей
    T_WORD KV_FLT;
    // Открыть: ЦУ неисправна
    T_WORD KCU_ON_FLT;
    // Закрыть: ЦУ неисправна
    T_WORD KCU_OF_FLT;
    // Нестрагивание на открытие
    T_WORD notMove_ON;
    // Нестрагивание на закрытие
    T_WORD notMove_OF;
    // Вибрация
    T_WORD Vibr;
    // Низкий уровень масла
    T_WORD Loil;
    // Отсутствие напряжения
    T_WORD U_OF;
    // Низкое давление масла
    T_WORD Poil;
    // Не выбран тип блока
    T_WORD TYPE_IM_FLT;
    // Значение уставки "Время между подачей повторных команд" (T_Block) мало
    T_WORD T_Block_FLT;
    // Значение уставки "Время контроля цепей управления" (T_KCU) не корректно
    T_WORD T_KCU_FLT;
    // Значение уставки "Время формирования сигнала "нестрагивание" (T_NotMove) не корректно
    T_WORD T_NotMove_FLT;
    // Значение уставки "Время формирования сигналов "не открыт, не закрыт" (T_NotCO) не корректно
    T_WORD T_NotCO_FLT;
    // Значение уставки таймера на  перестановку (T_Alarm) мало
    T_WORD T_Alarm_FLT;
} IM_PS;

typedef struct
{
    // Время контроля цепей управления открытия
    T_REAL32 T_KCU_ON;
    // Время контроля цепей управления закрытия
    T_REAL32 T_KCU_OF;
    // Время формирования сигнала "нестрагивание"
    T_REAL32 T_NotMove;
    // Время формирования сигналов "не открыт, не закрыт"
    T_REAL32 T_NotCO;
    // Время дожима открытия
    T_REAL32 T_Press_ON;
    // Время дожима закрытия
    T_REAL32 T_Press_OF;
    // Таймер форсировки открытия
    T_REAL32 T_Force_ON;
    // Таймер форсировки закрытия
    T_REAL32 T_Force_OF;
    // Время между подачей повторных команд открытия
    T_REAL32 T_Block_ON;
    // Время между подачей повторных команд закрытия
    T_REAL32 T_Block_OF;
    // Время открытия в режиме имитации 
    T_REAL32 T_Imit_ON;
    // Время закрытия в режиме имитации 
    T_REAL32 T_Imit_OF;
    T_REAL32 T_Move_ON;
    T_REAL32 T_Move_OF;
    // Время до срабатывания аварии. Конец счета
    T_BYTE T_Alarm_EN: 1;
    // Время дожима открытия. Конец счета
    T_BYTE T_Press_ON_EN: 1;
    // Время дожима закрытия. Конец счета
    T_BYTE T_Press_OF_EN: 1;
    // Таймер форсировки открытия. Конец счета
    T_BYTE T_Force_ON_EN: 1;
    // Таймер форсировки закрытия. Конец счета
    T_BYTE T_Force_OF_EN: 1;
    // Время между подачей повторных команд открытия. Конец счета
    T_BYTE T_Block_ON_EN: 1;
    // Время между подачей повторных команд закрытия. Конец счета
    T_BYTE T_Block_OF_EN: 1;
    // Время открытия в режиме имитации. Конец счета
    T_BYTE T_Imit_ON_EN: 1;
    // Время закрытия в режиме имитации. Конец счета
    T_BYTE T_Imit_OF_EN: 1;
    T_BYTE AVT_ON1: 1;
    T_BYTE AVT_OF1: 1;
    T_BYTE AUpr: 1;
    T_BYTE MUpr: 1;
    T_BYTE T_Move_ON_EN: 1;
    T_BYTE T_Move_OF_EN: 1;
	T_BYTE ON_IMIT: 1;
    T_REAL32 MR[10];
    T_WORD MB[10];
    // Флаг открыть
    T_BYTE Open: 1;
    // Флаг закрыть
    T_BYTE Close: 1;
    // условия для сигнала "самопроизвольное открытие"
    T_BYTE u_SPON: 1;
    // условия для сигнала "самопроизвольное закрытие"
    T_BYTE u_SPOF: 1;
    T_BYTE DI_ON1: 1;
	T_BYTE PRIORITY_RU: 1;
} IM_TMP;


// Статусы
typedef struct
{
    // Версия блока
    T_REAL32 Ver;
    // Время наработки, ч / количество открытий
    T_REAL32 Narab;
	// Количество открытий
    T_REAL32 Num;
	// Имитатор включен
    T_WORD ON_IMIT;
    // Обобщенная неисправность
    T_WORD FLT;
    // Ручное управление сигнализация
    T_WORD RUs;
	// Запрет РУ
    T_WORD RU_Ban;
    // Происходит перемещение ИМ
    T_WORD Move;
	//ИМ в промежуточном положении
	T_WORD MID;
    // Открыт
    T_WORD DI_ON1;
    // Закрыт
    T_WORD DI_OF1;
    // Открыть
    T_WORD DO_ON1;
    // Закрыть
    T_WORD DO_OF1;
    // Открыт по алгоритму
    T_WORD AVT_ON2;
    // Закрыт по алгоритму
    T_WORD AVT_OF2;
    // Открыт с АРМ
    T_WORD BTN_ON2;
    // Закрыт с АРМ
    T_WORD BTN_OF2;	
    // Тип ИМ
    T_INT16 TYPE_IM;	
} IM_ST;


typedef struct
{
    // Дискретные входы
    IM_DI DI;
    // Дискретные выходы
    IM_DO DO;
    // Команды автоматические
    IM_AVT AVT;
    // Кнопки
    IM_BTN BTN;
    // Команды из алгоритма
    IM_ALG ALG;
    // Настройки
    IM_CFG CFG;
    // Статусы
    IM_ST ST;
    // Предупреждения
    IM_PS PS;
    IM_TMP TMP;
} IM_STR;

#pragma pack()

#endif
