#ifndef _structs_h_
#define _structs_h_
#pragma pack(2)

// ������� �� ���������
typedef struct
{
    // ��������
    T_BYTE ON_IMIT: 1;
    // ������ ������
    T_BYTE DO_Ban: 1;
    // ������ ��
    T_BYTE RU_Ban: 1;
 //   T_BYTE filler1[1];
} IM_ALG;

// ������� ��������������
typedef struct
{
    // �������/��������
    T_BYTE ON: 1;
    // �������/���������
    T_BYTE OF: 1;
 //   T_BYTE filler1[1];
} IM_AVT;

// ������
typedef struct
{
    // ������ ������� / �������� 
    T_BYTE ON: 1;
    // ������ ������� / ���������
    T_BYTE OF: 1;
    // ������ /�������������� ����������
    T_BYTE RU: 1;
    // ����������
    T_BYTE STOP: 1;
 //   T_BYTE filler1[1];
} IM_BTN;

// ���������
typedef struct
{
    // ���������� ��������� �����
    T_BYTE Disable: 1;
//    T_BYTE filler1[1];
    // ����� �� ������������ ������
    T_REAL32 T_Alarm;
    // ����� �������� ����� ����������
    T_REAL32 T_KCU;
    // ����� ������������ ������� "�������������"
    T_REAL32 T_NotMove;
    // ����� ������������ �������� "�� ������, �� ������"
    T_REAL32 T_NotCO;
    // ����� ������
    T_REAL32 T_Press;
    // ������ ����������
    T_REAL32 T_Force;
    // ����� ����� ������� ��������� ������
    T_REAL32 T_Block;
    // ����� ������������ � ������ �������� 
    T_REAL32 T_Imit;
    // ��� ��� (� ������������� ����� ��� ������ ������ ��� ��� ������������)
    T_BYTE TYPE_KCU: 1;
    // ����� ��� ���������������� ������������
    T_BYTE Come_Back: 1;
    // ������������� ��� ��������� (���������� / �� ����������)
    T_BYTE INIT: 1;
    // ������������� ���������� � ���
    T_BYTE MUK: 1;
    // �������� ���������� ��������
    T_BYTE ONForceEN: 1;
    // �������� ���������� ��������
    T_BYTE OFForceEN: 1;
    // �������� ��� ������� ON
    T_BYTE KCU_ON_EN: 1;
    // �������� ��� ������� OFF
    T_BYTE KCU_OF_EN: 1;
    // �������� ������� ��������� / ���������
    T_BYTE NarabReset: 1;
    // ��� �����
    T_WORD TYPE_IM;
    // ��� ����������: 1 ������� / 2 �������
    T_WORD TYPE_CMD;
    // ��������� �������
    T_BYTE PRIORITY_RU: 1;		
} IM_CFG;

// ���������� �����
typedef struct
{
    // ������/�������
    T_BYTE ON: 1;
    // ������/��������
    T_BYTE OF: 1;
    // �������� ���� ��������
    T_BYTE KCU_ON: 1;
    // �������� ���� ��������
    T_BYTE KCU_OF: 1;
    // �����������
    T_BYTE MOVE: 1;
    // ������������ ����� ����������� �������
    T_BYTE M_Mufft: 1;
    // ��������
    T_BYTE Vibr: 1;
    // ������ ������� �����
    T_BYTE Loil: 1;
    // ���������� ����������
    T_BYTE U_OF: 1;
    // ������ �������� �����
    T_BYTE Poil: 1;
 //   T_BYTE filler1[1];
} IM_DI;

// ���������� ������
typedef struct
{
    // �������/��������
    T_BYTE ON: 1;
    // �������/���������
    T_BYTE OF: 1;
    // ����������
    T_BYTE STOP: 1;
    // ����������� ��������
    T_BYTE ONForce: 1;
    // ����������� ��������
    T_BYTE OFForce: 1;
 //   T_BYTE filler1[1];
} IM_DO;

// ��������������
typedef struct
{
    // ���������� �������������
    T_WORD FLT;
    // ������������ ����� ����������� �������
    T_WORD M_Mufft;
    // �� ������/�� �������
    T_WORD notON;
    // �� ������/�� ��������
    T_WORD notOF;
    // ���������������� �������� / ���������
    T_WORD SPON;
    // ���������������� �������� / ����������
    T_WORD SPOF;
    // ������������� �������� ������������
    T_WORD KV_FLT;
    // �������: �� ����������
    T_WORD KCU_ON_FLT;
    // �������: �� ����������
    T_WORD KCU_OF_FLT;
    // ������������� �� ��������
    T_WORD notMove_ON;
    // ������������� �� ��������
    T_WORD notMove_OF;
    // ������ ������������
    T_WORD ERR[2];
} IM_PS;

typedef struct
{
    // ����� �� ������������ ������
    T_REAL32 T_Alarm;
    // ����� �������� ����� ���������� ��������
    T_REAL32 T_KCU_ON;
    // ����� �������� ����� ���������� ��������
    T_REAL32 T_KCU_OF;
    // ����� ������������ ������� "�������������"
    T_REAL32 T_NotMove;
    // ����� ������������ �������� "�� ������, �� ������"
    T_REAL32 T_NotCO;
    // ����� ������ ��������
    T_REAL32 T_Press_ON;
    // ����� ������ ��������
    T_REAL32 T_Press_OF;
    // ������ ����������
    T_REAL32 T_Force;
    // ����� ����� ������� ��������� ������ ��������
    T_REAL32 T_Block_ON;
    // ����� ����� ������� ��������� ������ ��������
    T_REAL32 T_Block_OF;
    // ����� ������������ � ������ �������� 
    T_REAL32 T_Imit;
    T_REAL32 T_Move_ON;
    T_REAL32 T_Move_OF;
    // ����� �� ������������ ������. ����� �����
    T_BYTE T_Alarm_EN: 1;
    // ����� ������ ��������. ����� �����
    T_BYTE T_Press_ON_EN: 1;
    // ����� ������ ��������. ����� �����
    T_BYTE T_Press_OF_EN: 1;
    // ������ ����������. ����� �����
    T_BYTE T_Force_EN: 1;
    // ����� ����� ������� ��������� ������ ��������. ����� �����
    T_BYTE T_Block_ON_EN: 1;
    // ����� ����� ������� ��������� ������ ��������. ����� �����
    T_BYTE T_Block_OF_EN: 1;
    // ����� ������������ � ������ ��������. ����� �����
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
    // ���� �������
    T_BYTE Open: 1;
    // ���� �������
    T_BYTE Close: 1;
    // ������� ��� ������� "���������������� ��������"
    T_BYTE u_SPON: 1;
    // ������� ��� ������� "���������������� ��������"
    T_BYTE u_SPOF: 1;
} IM_TMP;


// �������
typedef struct
{
    // ������ �����
    T_REAL32 Ver;
    // ����� ���������, � / ���������� ��������
    T_REAL32 Narab;
    // ���������� �������������
    T_WORD FLT;
    // ������ ���������� ������������
    T_WORD RUs;
    // ���������� ����������� ��
    T_WORD Move;
    // ������
    T_WORD DI_ON;
    // ������
    T_WORD DI_OF;
    // �������
    T_WORD DO_ON;
    // �������
    T_WORD DO_OF;
} IM_ST;


typedef struct
{
    // ���������� �����
    IM_DI DI;
    // ���������� ������
    IM_DO DO;
    // ������� ��������������
    IM_AVT AVT;
    // ������
    IM_BTN BTN;
    // ������� �� ���������
    IM_ALG ALG;
    // ���������
    IM_CFG CFG;
    // �������
    IM_ST ST;
    // ��������������
    IM_PS PS;
    IM_TMP TMP;
} IM_STR;

#pragma pack()

#endif
