#pragma pack(2)

typedef struct
{
    // ����� �������������� ��������� ��� (��� �������� ��������)
    T_REAL32 POS_TS;
    // ������ ������ ��������� ���
    T_REAL32 POS_LO;
    // ������� ������ ��������� ���
    T_REAL32 POS_HI;
    // ������ ������ dP ��������������� ������� ��������� ���
    T_REAL32 dP_pos_LO;
    // ������� ������ dP ��������������� ������� ��������� ���
    T_REAL32 dP_pos_HI;
    // �������� dP �� POS
    T_REAL32 POS_off;
    // ������ ������ Pout
    T_REAL32 Pout_LO;
    // ������� ������ Pout
    T_REAL32 Pout_HI;
    // ������ ������ dP ��������������� ������� ������� Pout
    T_REAL32 dP_Pout_LO;
    // ������ ������ dP ��������������� �������� ������� Pout
    T_REAL32 dP_Pout_HI;
    // �������� dP �� Pout
    T_REAL32 Pout_off;
    // ��������� �������
    T_REAL32 surge;	
    // dP, ���
    T_REAL32 dPimit;	
} AS_Imit;

typedef struct
{
    // �������� �������� ��� � ������ ���������, % � ���
    T_REAL32 ASR_StopRazgr;
    // �������� �������� ��� � ������ ��������, % � ���
    T_REAL32 ASR_RunZagr;
    // �������� �������� ��� � ������ AO, % � ���
    T_REAL32 ASR_AO;
    // �������� �������� ��� � ������ ��������, % � ���
    T_REAL32 ASR_Produv_Open;
    // �������� �������� ��� � ������ ��������, % � ���
    T_REAL32 ASR_Produv_Close;
    // �������� ���������� ������� ����������
    T_REAL32 ASR_SP_DN;
    // �������� ���������� ������� �������, % � ��� 
    T_REAL32 ASR_Man_UP;
    // �������� ���������� ������� �������, % � ��� 
    T_REAL32 ASR_Man_DN;
    // ����������� �������� �������� �������, % � ��� 
    T_REAL32 ASR_DN;
    // ����� �������� ��������� Pin (�������� ������)
    T_REAL32 Pin_SpeedLim;
    // ����� �������� ��������� Pout (�������� ������)
    T_REAL32 Pout_SpeedLim;
    // ����� �������� ��������� Tin (�������� ������)
    T_REAL32 Tin_SpeedLim;
    // ����� �������� ��������� Tout (�������� ������)
    T_REAL32 Tout_SpeedLim;	
} AS_ConstLS;

typedef struct
{
    // ����������� ������� �������� �����������, ��/���
    T_REAL32 Nnom;
    // ����������� ��������� �����������
    T_REAL32 KKH;
    // ���������� ������� ������� ������� "������� �� ���������"
    T_REAL32 TS_dP;
} AS_ConstNag;

typedef struct
{
    // �������� �������� ������
    T_REAL32 H_LIM;
    // �������� ������� ������
    T_REAL32 L_LIM;
    // ���� ������������������
    T_REAL32 Ky_DB;
    T_REAL32 Pout_Kp;
    T_REAL32 Pout_Ki;
    // ���� ������������������
    T_REAL32 Pout_DB;
    // ������� ��������� Pout
    T_REAL32 Pout_HI;
    // ������ ��������� Pout
    T_REAL32 Pout_LO;
    T_REAL32 RY04_Kp;
    T_REAL32 RY04_Ki;
    // ���� ������������������
    T_REAL32 RY04_DB;
    // ������� ��������� E
    T_REAL32 RY04_HI;
    // ������ ��������� E
    T_REAL32 RY04_LO;
    T_REAL32 Scale_Kp_gt_0[10];
    T_REAL32 Scale_Kp_lt_0[10];
    T_REAL32 Scale_Ki_gt_0[10];
    T_REAL32 Scale_Ki_lt_0[10];
    // ���������� ����� �� � ������������� �������
    T_REAL32 Points_Kp_gt_0;
    // ���������� ����� �� � ������������� �������
    T_REAL32 Points_Kp_lt_0;
    // ���������� ����� �� � ������������� �������
    T_REAL32 Points_Ki_gt_0;
    // ���������� ����� �� � ������������� �������
    T_REAL32 Points_Ki_lt_0;
} AS_ConstReg;

typedef struct
{
    // ������� ��������� ��� ��� ������ ��������
    T_REAL32 APK_O_const;
    // ����� �������������, %
    T_REAL32 Line_Reg;
    // ����� ������������ �������� ���, %
    T_REAL32 Line_Step;
    // �������� ������� ���������� SP_M, %
    T_REAL32 Step_First_var;
    // �������� ������� ���������� SP_M, %
    T_REAL32 Step_Second_var;
    // ������������ ��������� SP_M ��� ����������� ����� LineStep, msec
    T_REAL32 Step_Time;
    // ����� �������������� ������ Step �����������. ��� ������ �������, ��� ��������� �������
    T_REAL32 Step_TS;
    // �������� ��������������� �������
    T_REAL32 Dead_In_dop;
    // ����� ������������ ��������� �� �������� ����������� � ������� �������
    T_REAL32 Line_Speed;
    T_REAL32 Line_EndZagr;
    // ������������ �������� �������� ����������� � ������� �������
    T_REAL32 Speed_RY03_Alm;
    // �������� ���������� SP ���������� ��� ����������� �������� ����������� � ������� �������
    T_REAL32 dSP_SpeedAlm;
    // ����������� ����������������� ���������� "�������� ��������� SP"
    T_REAL32 dSP_Kd;
    // ����� ������, %
    T_REAL32 Line_Safety;
    // �������� ��������, %
    T_REAL32 LineSafety_Shift;
    // ������� ���������� ����������� ����� Line_Safety
    T_REAL32 LineSafety_Ust;
    // ����� ����� "��������", msec
    T_REAL32 LineSafety_TimeSet;
    // ����� ����� �������� ��������, msec
    T_REAL32 LineSafety_TimeReset;
    // ����� �������� ��������, %
    T_REAL32 Line_NotOpen;
    // ����������� ������� ������� ���, %
    T_REAL32 NotOpen_Lim;
    // ����� ������� �������
    T_REAL32 Line_Surge;
    // ��������� �������� ��������� ��������� SpeedUP Pd
    T_REAL32 SpeedUP_dPd;
    // ��������� �������� ��������� ��������� SpeedDN Ps
    T_REAL32 SpeedDN_dPs;
    // ����������� �������� ��������� SpeedUP Pd
    T_REAL32 SpeedUP_Pd_Ku;
    // ����������� �������� ��������� SpeedDN Ps
    T_REAL32 SpeedDN_Ps_Ku;
    // ����� �������������� ������� SpeedUP Pd
    T_REAL32 SpeedUP_Pd_TS;
    // ����� �������������� ������� SpeedDN Ps
    T_REAL32 SpeedDN_Ps_TS;
    // ����� �������������� ������ SpeedUP Pd �����������. ��� ������ �������, ��� ��������� �������
    T_REAL32 SpeedUP_TS;
    // ����� �������������� ������ SpeedDN Ps �����������. ��� ������ �������, ��� ��������� �������
    T_REAL32 SpeedDN_TS;
    // ������� ����������� �������� ���� �� ������ �����������
    T_REAL32 P_out_Lim_SP;
    // ������� ����������� ������� ������
    T_REAL32 RY04_Lim_SP;
    // ����� �������
    T_REAL32 SurgeArray[6];
    // ���������� ��������� �����
    T_REAL32 Num_surge_point;
} AS_ConstSurge;

typedef struct
{
    // ������� ��� ��������� Step
    T_REAL32 RT_var;
    // ����� ��������� Step
    T_REAL32 CV_RT;
    // ����� ��� �������
    T_REAL32 CV_Reg;
    // CV_RT + CV_Reg
    T_REAL32 CV_AS;
    // ����� POC Pd
    T_REAL32 CV_PD;
    // ����� POC Ps
    T_REAL32 CV_PS;
    // ����� POC
    T_REAL32 CV_POC;
    // �������� ���������
    T_REAL32 CV_MAX;
    // ����� ���
    T_REAL32 oCV_R;
} AS_CV;

typedef struct
{
    // ������� ������
    T_REAL32 R_c;
    // ��������������� ��������, (ks/cm2)
    T_REAL32 B_;
    // �������� �� ����� � �����������, (ks/cm2)
    T_REAL32 Pin;
    // �������� �� ������ �� �����������, (ks/cm2)
    T_REAL32 Pout;
    // ����������� �� ����� � �����������, (��K)
    T_REAL32 Tin;
    // ����������� �� ������ �� ������������, (��K)
    T_REAL32 Tout;
    // ������������� ��������� ���� �� �������
    T_REAL32 p_;
    // ������� ����������, ���/���
    T_REAL32 R;
    // ������� �����������
    T_REAL32 Tsr;
    // ������� ��������
    T_REAL32 Psr;
    // ����������� ����������� �� �����
    T_REAL32 Zin;
    T_REAL32 Zout;
    // ����������� ����������� �� ������
    T_REAL32 Zsr;
    // ������������� ���������� ���������
    T_REAL32 mt;
    // ���������� ����������������
    T_REAL32 k;
    // ��������� �� ����� � �����������
    T_REAL32 p_N;
    // val= d_P*p_N
    T_REAL32 val;
    // Q = KKN * sqrt(val);
    T_REAL32 Q;
    // �������� ������ ����. G = KKN * sqrt(val1)/60;
    T_REAL32 G;
    // ����������� ������������������ (�3/���). Q_pr = Q * (Nnom/N);
    T_REAL32 Q_pr;
    // ����� �� ������� %. Ky = 100 * (*Q_pr - Q_min) / Q_min
    T_REAL32 Ky;
    // �������� ������������ ���
    T_REAL32 Ni;
    // ����������� �������� ���
    T_REAL32 Ne;
    // ����������� ���
    T_REAL32 KPD;
} AS_MASS;
 
typedef struct 
{
    // ������ ��
    T_REAL32 ver;
    // ����������� �������� ������ CV, %
    T_REAL32 hiLim;
    // ����������� ������� ������ CV, %
    T_REAL32 loLim;
    // ����������� ������ ���� ����� ��������������
    T_REAL32 Q_min;
    // ���������� ���������� ������
    T_INT16 Q_OK;
    // ���������� ���������� ������ ��� ����� ������� dP
    T_INT16 APK_ON_const;
    // ���� = 1, �� ��� �������� � ��������� 50%
    T_INT16 On_RUN;
    // ������� � �����
    T_INT16 Sensor_OK;
    // ��������� ���� � �������
    T_REAL32 PL_Gi;
    // ��������� ���� � ������� ����� �������
    T_REAL32 pl_g;
    // Pin �� ����� AI_SPEED
    T_REAL32 P_IN;
    // Pin ����� ����� AI_SPEED
    T_REAL32 Pin;
    // Pout �� ����� AI_SPEED
    T_REAL32 P_OUT;
    // Pout ����� ����� AI_SPEED
    T_REAL32 Pout;
    // ������� ���� �� ��������� � �������
    T_REAL32 DPi;
    // ������� ���� �� ��������� ����� �������
    T_REAL32 dP;
    // ������� ���� �� ��������� ����� ������� ��� ������
    T_REAL32 dP1;
    // ����������� ���� �� ����� � �������
    T_REAL32 T_IN;
    // ����������� ���� �� ����� ����� ������� ��� ������
    T_REAL32 Tin;
    // �������� ��������� ��
    T_REAL32 KySpeed;
    // ������������ �������� Ky
    T_REAL32 Ky_SpeedMax;
    // �������� ���������� SP ���������� ��� ����������� �������� ����������� � ������� �������
    T_REAL32 dSP_SpeedAlm;
    // ������ �������� � ����������� �� �������� Ky
    T_REAL32 dDev_SP;
    T_INT16 dDev;
    // ����� � ���� �������
    T_INT16 SO_Start;
    // ������ ��������� SO
    T_INT16 dSO;
    // ���� �������� �������� SO, �� ��������� ������
    T_INT16 XLOPOK;
    // �������� � ����� �������������
    T_REAL32 dSO_Reg;
    // ������ ������� ���������
    T_REAL32 oSP_M;
    // ������ ������� ��������� � ������������ �� �������� ���������
    T_REAL32 oSP_M_Current;
	T_INT16 MA_AS;
    // �������� �������� �� ��������� ���
    T_REAL32 dP_1;
    // �������� �������� �� Pout
    T_REAL32 dP_2;	
} AS_Temp;

typedef struct
{
    // ����� ������
    T_REAL32 LineSO;
    // ����� ������������ ��������
    T_REAL32 LineRT;
    // ����� �������� �������� ���
    T_REAL32 LineTS;
    // ����� �������������
    T_REAL32 LineReg;
    T_REAL32 LineRegR;
    // ����� ��������� �� �������� �����������
    T_REAL32 LineSpeed;
    // ����� ������� ��� ��� �������
    T_REAL32 LineSP;
    // ����� ��������� ��������
    T_REAL32 LineEndZagr;
} AS_oLine;

typedef struct
{
    // ������� ��
    T_REAL32 NST;
    // �������� ���� �� ����� �����������, ���
    T_REAL32 P_IN;
    // �������� ���� �� ������ �����������, ���
    T_REAL32 P_OUT;
    // ����������� ���� �� ����� �����������, ���
    T_REAL32 T_IN;
    // ����������� ���� �� ������ �����������, ���
    T_REAL32 T_OUT;
    // ������� ���� �� ��������� �����������, ���
    T_REAL32 DP;
    // ��������� ����
    T_REAL32 PL_G;
    // ��������������� ��������, ���
    T_REAL32 B;
    // ������� ��������� ��� (������ �������), %
    T_REAL32 SP_M;
    // ����� ����� ���, ���
    T_REAL32 TSCAN;
    // ��������� ���
    T_REAL32 POS;	
} AS_IN;
 
typedef struct
{
    // �������� ������ ���
    T_INT16 ON;
    // ������ � ������ ������ ��� ����������� �� ������ �������
    T_INT16 MOR;
    // ������ - 1 / ������� - 0
    T_INT16 MAN_ON;
    // ������ �� (������ ���������� �������� ���)
    T_INT16 iAO;
    // Stop - 1 / Run - 0
    T_INT16 SR;
    // �������� (���������� �������� ���)
    T_INT16 PRODUV_ON;
    // ��� ������
    T_INT16 APK_O;
    // ��� ������
    T_INT16 APK_C;
    // ����� "����������"
    T_INT16 MD_MAG;
    // ����� "������"
    T_INT16 MD_RING;
    // ��������� �������� ����������� �� �������� ����������� � ���� ������� �������� 
    T_INT16 DIFF_OF;
    // ��������� �������� POC Ps
    T_INT16 PS_OF;
    // ��������� �������� POC Pd
    T_INT16 PD_OF;
    // ����� SO
    T_INT16 RES_SO;
    // ����� �������� �������
    T_INT16 RES_HLOP;
    // ���� ��������� SO (�������� ��)
    T_INT16 TEST_SO;
    // ���� ��������� Step
    T_INT16 TEST_RT;
    // ���� ��������� Diff
    T_INT16 TEST_DIFF;
    T_INT16 NST_F;
    // �������� ���� �� ����� �����������. ������������� ������
    T_INT16 P_IN_F;
    // �������� ���� �� ������ �����������. ������������� ������
    T_INT16 P_OUT_F;
    // ����������� ���� �� ����� �����������. ������������� ������
    T_INT16 T_IN_F;
    // ����������� ���� �� ������ �����������. ������������� ������
    T_INT16 T_OUT_F;	
    // ������� �� ���������. ������������� ������
    T_INT16 DP_F;
    // �������� �������
    T_INT16 OnImit;	
} AS_INb; 
 
typedef struct
{
    // ������� ������ �����������
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
    // ����������� �������� ���
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
    // ����� ����������
    AS_IN AS_IN;
    // ����� ����������
    AS_INb AS_INb;
    // ������ ����������
    AS_OUT AS_OUT;
    // ������ ����������
    AS_OUTb AS_OUTb;
    // ��������� �����������
    AS_ConstNag ConstNag;
    // ��������� �� ����������
    AS_ConstReg ConstReg;
    // ����� �������������
    AS_ConstLS ConstLS;
    // ��������� ���
    AS_ConstSurge ConstSurge;
    // ��� �������
    AS_Temp AS_Temp;
    // ��� �������
    AS_MASS AS_MASS;
    // ��� �������
    AS_CV AS_CV;
    // ����� ����� ���������
    AS_oLine AS_oLine;
    // �������� dP
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
  

