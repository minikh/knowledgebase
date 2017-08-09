#ifndef _structs_h_
#define _structs_h_
#pragma pack(2)

// Команды из алгоритма
typedef struct
{
    // Имитатор
    T_BYTE ON_IMIT: 1;
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
    T_BYTE ON: 1;
    // Кнопка закрыть / выключить
    T_BYTE OF: 1;
    // Ручное /автоматическое управление
    T_BYTE RU: 1;
    // Остановить
    T_BYTE STOP: 1;
 //   T_BYTE filler1[1];
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
 //   T_BYTE filler2[1];
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
    T_BYTE MOVE: 1;
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

// Ошибки
typedef struct
{
    // Ошибки ИМ упакованные в WORD
    T_WORD Err[2];
} IM_ERR;

typedef struct
{
    // Время до срабатывания аварии
    T_REAL32 T_Alarm;
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
    // Таймер форсировки
    T_REAL32 T_Force;
    // Время между подачей повторных команд открытия
    T_REAL32 T_Block_ON;
    // Время между подачей повторных команд закрытия
    T_REAL32 T_Block_OF;
    // Время перестановки в режиме имитации 
    T_REAL32 T_Imit;
    T_REAL32 T_Move_ON;
    T_REAL32 T_Move_OF;
    // Время до срабатывания аварии. Конец счета
    T_BYTE T_Alarm_EN: 1;
    // Время дожима открытия. Конец счета
    T_BYTE T_Press_ON_EN: 1;
    // Время дожима закрытия. Конец счета
    T_BYTE T_Press_OF_EN: 1;
    // Таймер форсировки. Конец счета
    T_BYTE T_Force_EN: 1;
    // Время между подачей повторных команд открытия. Конец счета
    T_BYTE T_Block_ON_EN: 1;
    // Время между подачей повторных команд закрытия. Конец счета
    T_BYTE T_Block_OF_EN: 1;
    // Время перестановки в режиме имитации. Конец счета
    T_BYTE T_Imit_EN: 1;
    T_BYTE AVT_ON1: 1;
    T_BYTE AVT_OF1: 1;
    T_BYTE AUpr: 1;
    T_BYTE MUpr: 1;
    T_BYTE T_Move_ON_EN: 1;
    T_BYTE T_Move_OF_EN: 1;
	T_BYTE ON_IMIT: 1;
    T_REAL32 MR[10];
    T_WORD MB[10];
} IM_TMP;

// Тип ИМ
typedef struct
{
    // 0 входов, 1 выход
    T_BYTE IM_0x1: 1;
    // 1 вход, 1 выход
    T_BYTE IM_1x1: 1;
    // 1 вход, 2 выхода
    T_BYTE IM_1x2: 1;
    // 2 входа, 1 выход
    T_BYTE IM_2x1: 1;
    // 2 входа, 2 выхода
    T_BYTE IM_2x2: 1;
 //   T_BYTE filler1[1];
} IM_TYPE;

// Статусы
typedef struct
{
    // Версия блока
    T_REAL32 Ver;
    // Обобщенная неисправность
    T_BYTE FLT: 1;
    // Срабатывание муфты ограничения момента
    T_BYTE M_Mufft: 1;
    // Не открыт/не включен
    T_BYTE notON: 1;
    // Не закрыт/не выключен
    T_BYTE notOF: 1;
    // Самопроизвольное открытие / включение
    T_BYTE SPON: 1;
    // Самопроизвольное закрытие / выключение
    T_BYTE SPOF: 1;
    // Неисправность конечных выключателей
    T_BYTE KV_FLT: 1;
    // Открыть: ЦУ неисправна
    T_BYTE KCU_ON_FLT: 1;
    // Закрыть: ЦУ неисправна
    T_BYTE KCU_OF_FLT: 1;
    // Нестрагивание на открытие
    T_BYTE notMove_ON: 1;
    // Нестрагивание на закрытие
    T_BYTE notMove_OF: 1;
    // Ручное управление сигнализация
    T_BYTE RUs: 1;
    // Время наработки, ч / количество открытий
    T_REAL32 Narab;
    // Происходит перемещение ИМ
    T_BYTE Move: 1;
 //   T_BYTE filler1[1];
    // Статусы ИМ упакованные в WORD
    T_WORD Stat[2];
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
    // Тип ИМ
    IM_TYPE TYPE;
 //   T_BYTE filler1[1];
    // Статусы
    IM_ST ST;
    // Ошибки
    IM_ERR ERR;
    IM_TMP TMP;
} IM_STR;

#pragma pack()

#endif
