#include <stdio.h>
#include "math.h"     // �������������� �������
#include "PACRXPlc.h" //��������� ��� ����������� PAC
//#include "plcc9070.h" //��������� ��� ����������� 90-70
#include "structs.h"

static T_REAL32 TON_ARRAY[100];
//extern struct DSEL;
static T_BOOLEAN TRIG_ARRAY[100];
T_INT16 deriv_samples = 12;    // ����� ������� ��� ����������� �������� ��������� ����������

float TSCAN;

#include "sig_sel_1.c"
#include "as_lib.h"


///***************************************************** main **********************************************************
void GefMain(/*�����*/IN, Folt, INb,
			/*���������*/ Const,
			/*����� �������������*/ Line,
			/*������*/ OUT,OUTb,
			Temp_F,Temp_I,as_MStruct)
float *IN;
short *INb;
short *Folt;
float *Const;
float *Line;
float *OUT;
short *OUTb;
float *Temp_F;
short *Temp_I;
DSEL *as_MStruct;
{	

//���������� ���� Boolean � �������
static short Prod_On,Set_LowLim,APR_MA,ON_GUARD,MA_AS,Sensor_OK,MD_PROD,MD_STOP,MD_RUN,MD_ZAGR,MD_RAZGR,On_RUN,On_RUN1,MA_AS1;
static short APK_ON_const,dDev,TEST_SO1,SO_Start,XLOPOK,XLOPOK1,OFF_Tim,dSO1,MAN_ON1,POC_PD_On1,POC_PS_On1;
static short dRT, dRT1,dRT_On,dSO,end_RT,RTvar2,Produv,up_CV,up_CV1;

//DSEL *as_MStruct;

//���������� ���� Real � �������
static float LineRegR,Q_min,pl_g,dP,HlopTimerTP1[3],HlopTimerTP2[3],StepTimeTP[3],LineSP,CV_RegBuff[4];
static float KyBuff[4],KySpeed,dSP_SpeedAlm,Dev_off,dDev_SP,SP_Ky,NumHlopAO,dSO_Reg;
static float RT_var,CV_RT,CV_AS;
static float dPd_max, Time_PD, CV_PD, dPs_max, Time_PS, CV_PS;

float LineSO,LineRT,LineTS,LineReg,LineSpeed,LineEndZagr;
float ON,NST,P_IN,P_OUT,T_IN,DP,PL_G,B,TS_dP;
float Nnom,KKN,numPoint,LO_LIM,HI_LIM,CV_R,SP_M,SP_M_Current,NumHlop;
float LINE_SURGE,LINE_SAFETY,LINE_STEP,LINE_REG,LINE_NOT_OPEN,LINE_END_ZAGR,LINE_SPEED;
float hiLim,loLim,NotOpenLim,APK_ON_constUst;
float  Rc,Q_pr,Q,Ky,KySpeedMax,dSP_Kd;
short PID_MAN,oAO,POC_PS,POC_PD,P_IN_ACT,P_OUT_ACT,Q_OK;
short MOR,MAN_ON,iAO,SR,PRODUV_ON,APK_O,APK_C,MD_MAG,MD_RING,DIFF_OF,PS_OF,PD_OF,RES_SO;
short RES_HLOP,TEST_SO,TEST_RT,TEST_DIFF;
float LS_MAN_UP,LS_MAN_DN,LS_STOP_RAZGR,LS_RUN_ZAGR,LS_AO,LS_PRODUV_OPEN,LS_PRODUV_CLOSE,LS_SP_DN,LS_DN;
short P_IN_F,P_OUT_F,T_IN_F,DP_F,NST_F,Act[3];
float SpeedKyUst,LineSafety_TimeSet,LineSafety_Shift,LineSafety_UST,LineSafety_TimeRes,ASR_SP_DN;
float ASR_Man_UP, ASR_Man_DN,dKy,dKy_abs;
float Scale_Kp_lt_0[4],Scale_Kp_gt_0[4],Scale_Ki_lt_0[4],Scale_Ki_gt_0[4],CV_Reg;
float PV[3],SP[3],P_out_Lim_SP,Rc_Lim_SP,CVRegSpeed,Step_First_var,StepTime,Step_Second_var;
short Contur_ON[3],P_out_Act,Rc_Act,Usl_OF,end_PD,end_PS;
float SpeedDN_Pd_TS, SpeedUP_dPd, SpeedUP_Pd_Ku, SpeedDN_Ps_TS, SpeedUP_dPs, SpeedUP_Ps_Ku;
float CV_POC, CV_MAX, PV_Scale[4], AS_Ki[3],AS_Kp[3];

//�������������
NST= IN[0];		//������� ��
NST_F= Folt[0];
P_IN= IN[1];	//�������� ���� �� ����� �����������
P_IN_F= Folt[1];
P_OUT= IN[2];	//�������� ���� �� ������ �����������
P_OUT_F= Folt[2];
T_IN= IN[3];	//����������� ���� �� ����� �����������
T_IN_F= Folt[3];
DP= IN[4];		//������� ���� �� ��������� �����������
DP_F= Folt[4];
PL_G= IN[5];	//��������� ����
B= IN[6];		//��������������� ��������
SP_M= IN[7];
TSCAN= IN[8];

ON= INb[0];		//��������
MOR= INb[1];
MAN_ON= INb[2];
iAO= INb[3];
SR= INb[4];
PRODUV_ON= INb[5];
APK_O= INb[6];
APK_C= INb[7];
MD_MAG= INb[8];
MD_RING= INb[9];
DIFF_OF= INb[10];
PS_OF= INb[11];
PD_OF= INb[12];
RES_SO= INb[13];
RES_HLOP= INb[14];
TEST_SO= INb[15];
TEST_RT= INb[16];
TEST_DIFF= INb[17];

Nnom= Const[0];

KKN= Const[2];
numPoint= Const[3];
//Const[4...9] ������
LO_LIM = Const[10];
HI_LIM = Const[11];
NotOpenLim = Const[12];
LS_MAN_UP= Const[13];
LS_MAN_DN= Const[14];
LS_STOP_RAZGR= Const[15];
LS_RUN_ZAGR= Const[16];
LS_AO= Const[17];
LS_PRODUV_OPEN= Const[18];
LS_PRODUV_CLOSE= Const[19];
LS_SP_DN= Const[20];
LS_DN= Const[21];
APK_ON_constUst= Const[22];
TS_dP = Const[23];
dSP_Kd=  Const[24];
SpeedKyUst=  Const[25];
LineSafety_TimeSet= Const[26];
LineSafety_TimeRes= Const[27];
LineSafety_Shift= Const[28];
LineSafety_UST= Const[29];
ASR_SP_DN= Const[30];
ASR_Man_UP = Const[31];
ASR_Man_DN= Const[32];
Scale_Kp_lt_0[0]= Const[33];
Scale_Kp_lt_0[1]= Const[34];
Scale_Kp_lt_0[2]= Const[35];
Scale_Kp_lt_0[3]= Const[36];

Scale_Kp_gt_0[0]= Scale_Kp_lt_0[0];
Scale_Kp_gt_0[1]= Scale_Kp_lt_0[1];
Scale_Kp_gt_0[2]= Const[37];
Scale_Kp_gt_0[3]= Const[38];

Scale_Ki_lt_0[0]= Const[39];
Scale_Ki_lt_0[1]= Const[40];
Scale_Kp_lt_0[2]= Const[41];
Scale_Kp_lt_0[3]= Const[42];

Scale_Ki_gt_0[0]= Scale_Ki_lt_0[0];
Scale_Ki_gt_0[1]= Scale_Ki_lt_0[1];
Scale_Ki_gt_0[2]= Const[43];
Scale_Ki_gt_0[3]= Const[44];

P_out_Lim_SP= Const[45];
Rc_Lim_SP= Const[46];
Step_First_var= Const[47];
StepTime= Const[48];
Step_Second_var= Const[49];

SpeedDN_Pd_TS= Const[50];
SpeedUP_dPd= Const[51];
SpeedUP_Pd_Ku= Const[52];

SpeedDN_Ps_TS= Const[53];
SpeedUP_dPs= Const[54];
SpeedUP_Ps_Ku= Const[55];

PV_Scale[0]= Const[56];
PV_Scale[1]= Const[57];
PV_Scale[2]= Const[58];
PV_Scale[3]= Const[59];

AS_Kp[1]= Const[60];
AS_Ki[1]= Const[61];

AS_Kp[2]= Const[62];
AS_Ki[2]= Const[63];

LINE_SURGE = Line[0];		//����� �������
LINE_SAFETY = Line[1];	//����� ������
LINE_STEP = Line[2];		//����� ������������ �������� ���
LINE_REG = Line[3];		//����� �������������
LINE_NOT_OPEN = Line[4];	//����� �������� �������� ���
LINE_END_ZAGR = Line[5];	//����� ��������� ��������
LINE_SPEED = Line[6];		//����� ��������� �� �������� �����������

KySpeedMax= Temp_F[0];

Rc= OUT[0];				//������� ������


///������ Q_min � ����������� �� E(������� ������) �� ��������������
Q_min= CHARAKT(Rc, &Const[4], numPoint);
///��������� ������
if (ON && !Prod_On) ON_GUARD = 1;
else ON_GUARD = 0;

///���������� ����� ������ � �������������
//����� �������
LINE_SURGE = 0;
//����� ������
LineSO= LINE_SURGE - LINE_SAFETY;
//����� ������������ ��������
LineRT= LineRegR - LINE_STEP;
//����� �������� �������� ���
LineTS= LineRegR + LINE_NOT_OPEN;
//����� �������������
LineReg= LINE_SURGE + LINE_REG;
//����� ��������� �� �������� �����������
LineSpeed= LINE_SURGE + LINE_SPEED;
//����� ��������� ��������
LineEndZagr= LineRegR + LINE_END_ZAGR;

///����������� �������� � ������� �������
hiLim= HI_LIM;
loLim= LO_LIM;

///����� �������� ���������
//���� ����� �� ������� ������ �������� LineReg � AS � ��������, 
//�� ������ ����������� �� �������� ������� TSL_Lim %
if (!MA_AS && !Prod_On &&((Ky<=LineRegR) || Set_LowLim))
	{
	loLim= NotOpenLim;
	Set_LowLim= 1;
	}
//���� ����� �� ������� ������ �������� LineTS ��� AS � ������ ������, 
//�� ���������� �������� ����������� �� �������� ������� 
if (MA_AS || Prod_On || (Ky>LineTS))
	{
	loLim= 0;
	Set_LowLim= 0;	
	}
///������ ������ AS
//��� � RUN
//���� ��� �������� � ��� �� � ������� � �������..
if(!Prod_On && !iAO && Sensor_OK)
	{
	//���� ��� �������� � ��� �� � ������� � �������..
	//� ���� ���� ������� �������� � ��� � �������� � ��� ��������� ������
	if (!SR && !MA_AS && !MD_RUN)
		{
		//�������� ����� "��������"
		MD_ZAGR= 1;
		MD_STOP= 0;
		MD_RAZGR= 0;
		}
	//���� ��� �������� � ��� �� � ������� � �������..
	//� ���� ����� "��������"
	if (MD_ZAGR)
		{
		//�������� ��������� ������� � �������� ��������� (�������� �������������)
		Ramp(LS_RUN_ZAGR,&SP_M);
		//��������� ��� � ������ �����
		APR_MA= 1;
		//���� ����� ������ ������� ��� ��� ��������, �� ..
		if ((Ky<=LineEndZagr) || APK_C)
			{
			//�������� ����� "� ������"
			MD_RUN = 1;
			MD_ZAGR = 0;
			}
		}
	//���� ��� �������� � ��� �� � ������� � �������..
	//� ���� ���� ������� �������� � �������� ��� � ������ ����� 
	if (!SR && ((MA_AS && !MA_AS1) || (On_RUN && !On_RUN1)))
		{
		//�������� ����� "� ������"
		MD_RUN = 1;
		MD_ZAGR = 0;		
		}
	//���� ��� �������� � ��� �� � ������� � �������..
	//� ����� "������" � ��� � ��������
	if (MD_RUN && !MA_AS) 
		//�� ��������� � �������
		APR_MA=0;
	}

///��������� ��� �� �������� ������� �������� ��� ������� ������ ��������
On_RUN= (!Prod_On && !iAO && !SR && !MA_AS && (MD_RUN || MD_ZAGR) && APK_ON_const);
if (On_RUN) APR_MA= 1;
if (On_RUN && (CV_R<=APK_ON_constUst))
	LIM_SPEED_2_1 (APK_ON_constUst, 5, 0,&SP_M);


///��� � STOP. ��������� ��� 
if(!Prod_On && !iAO)
	{
	if (SR && !MA_AS && !MD_STOP)
		{
		MD_RAZGR= 1;
		MD_RUN= 0;
		MD_ZAGR= 0;
		}
	if (MD_RAZGR)
		{
		APR_MA= 1;
		Ramp(LS_STOP_RAZGR,&SP_M);
		if (CV_R>=100)
			{
			MD_STOP= 1;
			MD_RAZGR= 0;
			}
		}
	if (SR && (MA_AS && !MA_AS1))
		{
		MD_STOP= 1;
		MD_RAZGR= 0;			
		}
	if (MD_STOP) APR_MA= 1;
	}

///� ������ � �������������� ������ ��� �������
if (!Prod_On && !iAO && SR && !MA_AS && MD_STOP && (!ON_GUARD || MD_RING))
	{
	APR_MA= 1;
	Ramp(LS_STOP_RAZGR,&SP_M);
	}

///��������� �������
if (iAO && !Prod_On)
	{
	Ramp(LS_AO,&SP_M);
	APR_MA= 1;
	MA_AS= 0;
	MD_RUN= 0;
	MD_STOP= 0;
	MD_RAZGR= 0;
	MD_ZAGR= 0;
	}

///���������� ��������
//���������� ���������� ������
Q_OK= ((!T_IN_F && (!P_IN_F || DP_F)) || (P_IN_F && DP_F));
//��� ������ ���� �������� ������� ��� �� ���������� ���������� �������
APK_ON_const = (DP_F || !Q_OK);	
//���������
LIM_SPEED_2_1 (PL_G, 0.01, -0.01,&pl_g);
if (pl_g <0.4) pl_g = 0.4;
else if (pl_g > 1) pl_g = 1;
	Temp_F[1]= PL_G;
	Temp_F[2]= pl_g;
//��������������� ��������
if (B<700) B= 700;
else if(B>770) B = 770;
//������� ���� �� ���������. ���������� � �������� ����������� �������
INT_R (DP, TS_dP, &dP);
	
///������ ����������� �� ���� �������
MASS(Q_OK,NST,P_IN,P_OUT,T_IN,dP,pl_g,B, //�����
     Nnom,Q_min,KKN,	//���������
	 &Rc,&Q_pr,&Q,&Ky);	//������
	 
///��������� ������ SO � ���������������� (�� �������� ����������� � ������� �������)
//������������ �������� ��������� ��
KySpeed= SPEED (Ky,KyBuff);
KySpeed*= -1;

//���������� ������������ �������� (��� �������)
if (KySpeed > KySpeedMax) KySpeedMax = KySpeed;
Temp_F[0]= KySpeedMax;
//�������� ���������� SP ���������� ��� ����������� �������� ����������� � ������� �������
dSP_SpeedAlm= KySpeedMax * dSP_Kd;
//���� �������� ������ ���
if (ON_GUARD)
	{
	//���� �� �������� ������ �������� � �������� ���� �������..
	if (ON_GUARD && (TEST_DIFF ||((Ky<=LineSpeed) && !Dev_off && (KySpeed>SpeedKyUst))))
		{
		//�������� ��������� (�������� ������)
		if (TEST_DIFF) KySpeed = SpeedKyUst + 0.1;
		//��� ������������ ������
		dDev = 1;
		//������ �������� � ����������� �� ��������
		dDev_SP += dSP_SpeedAlm;
		}
	//���� �������� ������ ��� = ������� �� ����� ���������� � 0
	if (!TEST_DIFF && (KySpeed < LineSpeed)) dDev_SP= 0;
	//���� ������� ����� ������������� ��� ������ ����� �������������, �� �������� ��� ������������
	if (SP_Ky <= LineReg) dDev = 0;
	}
if (dDev_SP > LINE_SPEED) dDev_SP = LINE_SPEED;
else if (dDev_SP < 0) dDev_SP = 0;

///������������ "������"
if (ON_GUARD)
	{
	if ((Ky < LineSO) || (TEST_SO && !TEST_SO1))
		{
		SO_Start = 1;
		dSO = 1;
		}
	else SO_Start = 0;
	}

//���� �������� �������� SO, �� ��������� ������
//��� ��������� ����� ����� ��������
//short TP (short EN, float Ust, short *T,float *Time)
XLOPOK = TP(SO_Start && !XLOPOK,LineSafety_TimeSet,HlopTimerTP1);

//��������� ������� ������� �� 1
if (XLOPOK && !XLOPOK1)
	{
	NumHlop += 1;
	NumHlopAO += 1;
	//�������� � ����� �������������
	dSO_Reg+= LineSafety_Shift;
	//����������� ��������
	if (dSO_Reg<0) dSO_Reg = 0;
	else if (dSO_Reg>100) dSO_Reg= 100;
	}

//����� �������� �������
if (RES_HLOP) NumHlop = 0;
if (RES_SO || !OFF_Tim) NumHlopAO = 0;

//���� �������� �������� SO, �� ��������� ������
//��� ��������� ����� �� ������ ��������� SO
//short TP (short EN, float Ust, short *T,float *Time)
OFF_Tim = TP(SO_Start && !OFF_Tim,LineSafety_TimeRes,HlopTimerTP2);

//���� �� ����� LineSafety_TimeRes ��������� LineSafety_UST �������, ����� ��
oAO= (OFF_Tim && (NumHlopAO >= LineSafety_UST));

//�����
if (RES_SO) 
	{
	dSO_Reg = 0;
	dSO = 0;
	}

//��������� ��������� � ������� ��� ����������� ����� SO (������)
if (((ON_GUARD && MA_AS && (Ky<=LineSO)) || (dSO && !dSO1)) && !MOR)
	MA_AS = 0;

///������������� ������ - �������
//�������� ����� ������� MAN_ON
if (!MAN_ON && MAN_ON1)
	//��� � �������
	MA_AS = 0;

//������ ����� ������� MAN_ON
if (MAN_ON && !MAN_ON1)
	{
	//��� � ������
	MA_AS = 1;
	APR_MA = 1;
	}
	
///������������ �������. ������ ����������� �������� ��������� �������	
//����������� ����� �������������
LineRegR= LineReg + dSO_Reg;
if (LineRegR > 100)	LineRegR= 100;

//LineSP
LineSP= LineRegR + dDev_SP;
if (LineSP > 100)	LineSP= 100;
//����������� �������� ��������� ������� ����������
LIM_SPEED_2_1 (LineSP, 0, ASR_SP_DN,&SP_Ky);
	
//��� ������������� ��� � ������, �������� �� SP �������� �������
if(MA_AS && !MA_AS1) SP_Ky = LineSP;
//����������� SP
if (SP_Ky>100) SP_Ky= 100;
else if (SP_Ky<0) SP_Ky= 0;

//���������� ������������ �������� �� �������� � ������
if (!APR_MA || Prod_On || (MA_AS && !MA_AS1) || (!MA_AS && MA_AS1))	
	{
	SP_M= CV_R;
	SP_M_Current= SP_M;
	}
//����������� MAN
if(SP_M >hiLim) SP_M= hiLim;
else if (SP_M<loLim) SP_M= loLim;
	
//� ������ ������ ������������ �������� ��������� SP_M	
if (APR_MA) 
	LIM_SPEED_2_1 (SP_M, ASR_Man_UP, ASR_Man_DN,&SP_M_Current);
	
///���� �������� Kp, Ki, � ����������� �� ����������� ����� �� ����� �������������
//����������� ����� �� ����� �������������
dKy= Ky - SP_Ky;
//���������� ��������
dKy_abs= fabsf(dKy);
//������������� �� ��������������
//float CHARAKT(float E, float *Array, float num)	
if (dKy>3)
	{
	AS_Kp[0]= CHARAKT(dKy_abs, Scale_Kp_gt_0, 2);
	AS_Ki[0]= CHARAKT(dKy_abs, Scale_Ki_gt_0, 2);
	}
else if (dKy<-3)
	{
	AS_Kp[0]= CHARAKT(dKy_abs, Scale_Kp_lt_0, 2);
	AS_Ki[0]= CHARAKT(dKy_abs, Scale_Ki_lt_0, 2);
	}
else 
	{
	AS_Kp[0]= Scale_Kp_gt_0[1];
	AS_Ki[0]= Scale_Ki_gt_0[1];
	}
	
///��� ��������� ���
//��������
PV[0]= Ky; 
PV[1]= P_OUT; 
PV[2]= Rc; 

SP[0]= SP_Ky;
SP[1]= P_out_Lim_SP;
SP[2]= Rc_Lim_SP;

Contur_ON[0]= 1;
Contur_ON[1]= !P_OUT_F;
Contur_ON[2]= (!P_IN_F && !P_OUT_F);
//void REG_PID_SEL(*PV, *SP, *Contur_ON, APR_MA, M_SP, *Kp, *Ki, loLimOut,*CV,*Act,*as_MStruct)	
REG_PID_SEL(PV,SP,PV_Scale,&Contur_ON,APR_MA,SP_M_Current,AS_Kp,AS_Ki,&loLim,&CV_Reg,&Act,as_MStruct);

P_out_Act= Act[1];
Rc_Act= Act[2];

//�������� ��������� CV � ��������
INT_R (SPEED (CV_Reg, CV_RegBuff), 6.0, &CVRegSpeed);
//�����������
if (CVRegSpeed<0) CVRegSpeed= 0;
	
///�������� ������������ ���������� �� ���
//���� ����������� �� ������� ������� ������ LineRT, ��������� ��� ��������� � ������ ����� � ��������� �������� 
//SP_M ������ ����� RT_var_First � �������� ������������ ����������� �� ������ � ����������� SP_M �� �������� RT_var_Second � ���������� 
//RT_Time �� ��� ���, ���� �� ����� ������ �� ����� Line_RT	
if (((ON_GUARD && (Ky<=LineRT)) || TEST_RT) && !MOR)
	{
	dRT= 1;
	dRT_On= 1;
	}
if (dRT && !dRT1)
	{
	RT_var= Step_First_var;
	if (!MOR) MA_AS= 0;
	}
	
//����� ������� � �����, �� ��������� ����� RT �����������
if (!TEST_RT && (Ky >= LineEndZagr)) dRT_On= 0;	
	
//���� ��������� ���� ������ �� �������� � ������� ����� ��������� �� ����� �������������, �� ����� ����������� RT ���������
Usl_OF= ((Ky<=SP_Ky) || !Sensor_OK || P_out_Act || Rc_Act);
if (dRT && !dRT_On && (CVRegSpeed>=0))	
	{
	if(Usl_OF)
		end_RT= 1;
	}

//��������� RT
if ((dRT && (CV_RT<=0)) || MA_AS || !ON_GUARD || end_RT)
	dRT= 0;
if (end_RT)	
	{
	///�� ����� PID ������� �������� CV_R
	as_MStruct->cv = CV_R;
	end_RT= 0;
	}
	
//��� ���������� RT
if (!dRT_On) RT_var= -6;
//�������������� �� �������
INT_R_ON(dRT && !dRT_On, RT_var, 150, &CV_RT);
//����������� 
if (CV_RT < 0) CV_RT= 0;
//��������
CV_AS= CV_RT + CV_Reg;	
//����� ����� ������������ CV
RTvar2 = TP(dRT_On && !RTvar2,StepTime,StepTimeTP);
//�������� ������� ���������� CV
if (dRT_On && !RTvar2)	
	RT_var+= Step_Second_var; 
//����������� �������� ���������� CV
if (RT_var>100) RT_var= 100;

///POC Pd
//POC (PS, ON,OFF, IN, TS, IN_F, Usl_OF, SpeedUP_dP, SpeedUP_P_Ku,CVRegSpeed,*dP_max, *MA_AS, *POC_P, *Time, *end_POC, *CV_P,*POC_P_On1)
POC(0, ON_GUARD,PD_OF, P_OUT, SpeedDN_Pd_TS, P_OUT_F, Usl_OF, SpeedUP_dPd, SpeedUP_Pd_Ku,CVRegSpeed,
	&dPd_max, &MA_AS, &POC_PD, &Time_PD, &end_PD, &CV_PD, &POC_PD_On1); 
if (end_PD)
	{
	///�� ����� PID ������� �������� CV_R
	as_MStruct->cv = CV_R;
	end_PD= 0;
	}

///POC Ps
//POC(PS, ON,OFF,-1 * IN, TS, IN_F, Usl_OF, SpeedUP_dP, SpeedUP_P_Ku,CVRegSpeed,*dP_max, *MA_AS, *POC_P, *Time, *end_POC, *CV_P,*POC_P_On1);
POC(1, ON_GUARD,PS_OF, P_IN, SpeedDN_Ps_TS, P_IN_F, Usl_OF, SpeedUP_dPs, SpeedUP_Ps_Ku,CVRegSpeed,
	&dPs_max, &MA_AS, &POC_PS, &Time_PS, &end_PS, &CV_PS, &POC_PS_On1); 
if (end_PS)
	{
	///�� ����� PID ������� �������� CV_R
	as_MStruct->cv = CV_R;
	end_PS= 0;
	}

//�������� POC
CV_POC= CV_PD + CV_PS;
//�������� ���������
if (CV_POC>=CV_AS) CV_MAX= CV_POC;
if (CV_POC<CV_AS) CV_MAX= CV_AS;

//����������� �������� ��������
if (!Produv && !Prod_On)
	{
	LIM_SPEED_2_1 (CV_MAX, 0, ASR_Man_DN,&CV_R);
	if (CVRegSpeed>=0)
		{
		//���� ��������� ���� ������ �� ��������, �� CV ��� ���������� ������� = CV ������
		if ((CV_Reg+1) < CV_R) up_CV= 1;
		else up_CV= 0;
		}
	else up_CV= 0;
	}
else up_CV= 0;
	
if (up_CV && !up_CV1)
	///�� ����� PID ������� �������� CV_R
	as_MStruct->cv = CV_R;
	

///�������� (������� ���)
//����� ������ ������� �������� ������� ��� ���������	
if (Produv && SR)
	{
	Ramp(LS_PRODUV_CLOSE,&CV_R);
	Prod_On= 1;
	APR_MA= 1;
	MA_AS= 0;
	}
if (!Produv && Prod_On)
	{
	Ramp(LS_PRODUV_OPEN,&CV_R);
	APR_MA= 1;
	MD_STOP= 1;
	}
if 	(!Produv && (CV_R>=100))
	{
	Prod_On= 0;
	MD_PROD= 0;
	}
	
//��������
if (Prod_On)	
	{
	MD_PROD= 1;
	MD_RUN= 0;
	MD_STOP= 0;
	MD_RAZGR= 0;
	MD_ZAGR= 0;
	}
//����������� 
if (CV_R<loLim) CV_R= loLim;
else if (CV_R>hiLim) CV_R= hiLim;


	
	

///********************************** ������ ******************************************
//��� ������ ������������ �������� ������� ��������
On_RUN1= On_RUN;
MA_AS1= MA_AS;
TEST_SO1 = TEST_SO;
XLOPOK1= XLOPOK;
dSO1= dSO;
MAN_ON1 = MAN_ON;
dRT1= dRT;
up_CV1= up_CV;

//������
OUT[0]= Rc;
OUT[1]= Q_pr;
OUT[2]= Q;
OUT[3]= Ky;
OUT[4]= CV_R;
OUT[5]= SP_M_Current;
OUT[6]= NumHlop;

OUTb[0]= PID_MAN;
OUTb[1]= oAO;
OUTb[2]= dSO;
OUTb[3]= dRT;
OUTb[4]= POC_PS;
OUTb[5]= POC_PD;
OUTb[6]= MD_PROD;
OUTb[7]= MD_STOP;
OUTb[8]= MD_RUN;
OUTb[9]= MD_ZAGR;
OUTb[10]= MD_RAZGR;
OUTb[11]= P_IN_ACT;
OUTb[12]= P_OUT_ACT;

Const[1]= Q_min;

//���������� ����� ����� ����������� ����� ����
MAN_ON = MA_AS;
INb[2] = MAN_ON;
IN[7]= SP_M;

Temp_I[9]= 2;
}
