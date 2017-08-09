//��������� 2012.07.10
//��������� 2012.07.11

#include <stdio.h>
#include "math.h"     // �������������� �������
#include "PACRXPlc.h" //��������� ��� ����������� PAC
//#include "plcc9070.h" //��������� ��� ����������� 90-70
#include "structs.h"

static float TON_ARRAY[100];
//extern struct DSEL;
static short TRIG_ARRAY[100];
int deriv_samples = 12;    // ����� ������� ��� ����������� �������� ��������� ����������
//float Temp_F1[100];
float TSCAN;
static DSEL as_MStruct;

#include "sig_sel_1.c"
#include "as_lib.h"


///***************************************************** main **********************************************************
void GefMain(/*�����*/IN, INb,
			/*���������*/ Const,
			/*����� �������������*/ Line,
			/*������*/ OUT,OUTb,oLine,
			Temp_F )/* ,Temp_I) ,as_MStruct1)*/
float *IN;
short *INb;
float *Const;
float *Line;
float *OUT;
short *OUTb;
float *oLine;
float *Temp_F;
//short *Temp_I;
//DSEL *as_MStruct1;
{	

//���������� ���� Boolean � �������
static short Prod_On,Set_LowLim,APR_MA,ON_GUARD,MA_AS,Sensor_OK,MD_PROD,MD_STOP,MD_RUN,MD_ZAGR,MD_RAZGR,On_RUN,On_RUN1,MA_AS1;
static short APK_ON_const,dDev,TEST_SO1,SO_Start,XLOPOK,XLOPOK1,OFF_Tim,dSO1,MAN_ON1,POC_PD_On1,POC_PS_On1;
static short dRT, dRT1,dRT_On,dSO,end_RT,RTvar2,Produv,up_CV,up_CV1,end_PD,end_PS,OnTimRT1,OnTimRT,SR1;


//���������� ���� Real � �������
static float LineRegR,Q_min,pl_g,dP,dP1,Tin,HlopTimerTP1[3],HlopTimerTP2[3],StepTimeTP[3],LineSP,CV_RegBuff[4];
static float KyBuff[4],KySpeed,dSP_SpeedAlm,Dev_off,dDev_SP,SP_Ky,NumHlopAO,dSO_Reg;
static float RT_var,CV_RT,CV_AS,SP_M_Current,CV_R, POC_PD_var, POC_PS_var;
static float dPd_max[2], Time_PD, CV_PD, dPs_max[2], Time_PS, CV_PS,NumHlop,P_IN1,P_OUT1,Ky;
static float Pin_SpeedBuf[6], Pin_Temp[3], Pout_SpeedBuf[6], Pout_Temp[3];

float LineSO,LineRT,LineTS,LineReg,LineSpeed,LineEndZagr;
float ON,NST,P_IN,P_OUT,T_IN,T_OUT,DP,PL_G,B,TS_dP;
float Nnom,KKN,numPoint,LO_LIM,HI_LIM,SP_M;
float LINE_SURGE,LINE_SAFETY,LINE_STEP,LINE_REG,LINE_NOT_OPEN,LINE_END_ZAGR,LINE_SPEED;
float hiLim,loLim,NotOpenLim,APK_ON_constUst;
float  Rc,Q_pr,Q,KySpeedMax,dSP_Kd,Ni,G;
short oAO,POC_PS=0,POC_PD=0,Q_OK;
short MOR,MAN_ON,iAO,SR,PRODUV_ON,APK_O,APK_C,MD_MAG,MD_RING,DIFF_OF,PS_OF,PD_OF,RES_SO;
short RES_HLOP,TEST_SO,TEST_RT,TEST_DIFF;
float LS_MAN_UP,LS_MAN_DN,LS_STOP_RAZGR,LS_RUN_ZAGR,LS_AO,LS_PRODUV_OPEN,LS_PRODUV_CLOSE,LS_SP_DN,LS_DN;
short P_IN_F,P_OUT_F,T_IN_F,DP_F,NST_F,Act[3];
float SpeedKyUst,LineSafety_TimeSet,LineSafety_Shift,LineSafety_UST,LineSafety_TimeRes;
//float ASR_Man_UP, ASR_Man_DN;
float dKy,dKy_abs;
float Scale_Kp_lt_0[4],Scale_Kp_gt_0[4],Scale_Ki_lt_0[4],Scale_Ki_gt_0[4],CV_Reg;
float PV[3],SP[3],P_out_Lim_SP,Rc_Lim_SP,CVRegSpeed,Step_First_var,StepTime,Step_Second_var;
short Contur_ON[3],Ky_Act,P_out_Act,Rc_Act,Usl_OF;
short Pin_F,Pout_F;
float SpeedUP_Pd_TS, SpeedUP_dPd, SpeedUP_Pd_Ku, SpeedDN_Ps_TS, SpeedDN_dPs, SpeedDN_Ps_Ku;
float CV_POC, CV_MAX, PV_Scale[4], AS_Ki[3],AS_Kp[3];
float Pin, Pout, Pin_SpeedLim, Pout_SpeedLim, Pin_MaxSpeed, Pout_MaxSpeed;

//������ ��
float ver= 3.0;

//�������������
NST= IN[0];		//������� ��
P_IN= IN[1];	//�������� ���� �� ����� �����������
P_OUT= IN[2];	//�������� ���� �� ������ �����������
T_IN= IN[3];	//����������� ���� �� ����� �����������
T_OUT= IN[4];	//����������� ���� �� ������ �����������
DP= IN[5];		//������� ���� �� ��������� �����������
PL_G= IN[6];	//��������� ����
B= IN[7];		//��������������� ��������
SP_M= IN[8];
TSCAN= IN[9];


ON= 		INb[0]>>0 &1;		//��������
MOR= 		INb[0]>>1 &1;
MAN_ON= 	INb[0]>>2 &1;
iAO= 		INb[0]>>3 &1;
SR= 		INb[0]>>4 &1;
PRODUV_ON= 	INb[0]>>5 &1;
APK_O= 		INb[0]>>6 &1;
APK_C= 		INb[0]>>7 &1;
MD_MAG= 	INb[0]>>8 &1;
MD_RING= 	INb[0]>>9 &1;
DIFF_OF= 	INb[0]>>10 &1;
PS_OF= 		INb[0]>>11 &1;
PD_OF= 		INb[0]>>12 &1;
RES_SO= 	INb[0]>>13 &1;
RES_HLOP= 	INb[0]>>14 &1;
TEST_SO= 	INb[0]>>15 &1;
TEST_RT= 	INb[1]>>0 &1;
TEST_DIFF= 	INb[1]>>1 &1;

NST_F= 		INb[1]>>2 &1;
P_IN_F= 	INb[1]>>3 &1;
P_OUT_F= 	INb[1]>>4 &1;
T_IN_F= 	INb[1]>>5 &1;
DP_F= 		INb[1]>>6 &1;



Nnom= Const[0];
//Const[1]; // Q_min
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
LS_SP_DN= Const[30];
//ASR_Man_UP = Const[31];
//ASR_Man_DN= Const[32];
Scale_Kp_lt_0[0]= Const[33]; //0
Scale_Kp_lt_0[1]= Const[34]; //0.4
Scale_Kp_lt_0[2]= Const[35]; //10
Scale_Kp_lt_0[3]= Const[36]; //0.5

Scale_Kp_gt_0[0]= Scale_Kp_lt_0[0]; //0
Scale_Kp_gt_0[1]= Scale_Kp_lt_0[1]; //0.4
Scale_Kp_gt_0[2]= Const[37]; //20
Scale_Kp_gt_0[3]= Const[38]; //0.65

Scale_Ki_lt_0[0]= Const[39]; //0
Scale_Ki_lt_0[1]= Const[40]; //0.03
Scale_Ki_lt_0[2]= Const[41]; //10
Scale_Ki_lt_0[3]= Const[42]; //0.04

Scale_Ki_gt_0[0]= Scale_Ki_lt_0[0]; //0
Scale_Ki_gt_0[1]= Scale_Ki_lt_0[1]; //0.03
Scale_Ki_gt_0[2]= Const[43]; //20
Scale_Ki_gt_0[3]= Const[44]; //0.1

P_out_Lim_SP= Const[45];
Rc_Lim_SP= Const[46];
Step_First_var= Const[47];
StepTime= Const[48];
Step_Second_var= Const[49];

SpeedUP_Pd_TS= Const[50];
SpeedUP_dPd= Const[51];
SpeedUP_Pd_Ku= Const[52];

SpeedDN_Ps_TS= Const[53];
SpeedDN_dPs= Const[54];
SpeedDN_Ps_Ku= Const[55];

PV_Scale[0]= Const[56];
PV_Scale[1]= Const[57];
PV_Scale[2]= Const[58];
PV_Scale[3]= Const[59];

AS_Kp[1]= Const[60];
AS_Ki[1]= Const[61];

AS_Kp[2]= Const[62];
AS_Ki[2]= Const[63];

Pin_SpeedLim= Const[64];
Pout_SpeedLim= Const[65];

LINE_SURGE = Line[0];		//����� �������
LINE_SAFETY = Line[1];	//����� ������
LINE_STEP = Line[2];		//����� ������������ �������� ���
LINE_REG = Line[3];		//����� �������������
LINE_NOT_OPEN = Line[4];	//����� �������� �������� ���
LINE_END_ZAGR = Line[5];	//����� ��������� ��������
LINE_SPEED = Line[6];		//����� ��������� �� �������� �����������

Rc= OUT[0];				//������� ������
KySpeedMax= OUT[11];
dPs_max[0]= OUT[12];
dPd_max[0]= OUT[13];
Pin_MaxSpeed= OUT[15];
Pout_MaxSpeed= OUT[16];
//*************************
//��������
Produv= PRODUV_ON;
//void AI_SPEED(/*�����*/float AI, float SpeedLim, short iFolt,
//			/*������*/ float *OUT, float *MaxSpeed, short *oFolt, float *SpeedBuf, float *Temp)

//�������� AI �� �������� ��������� �������
AI_SPEED(P_IN,Pin_SpeedLim, P_IN_F, &Pin, &Pin_MaxSpeed, &Pin_F, Pin_SpeedBuf, Pin_Temp);
AI_SPEED(P_OUT,Pout_SpeedLim, P_OUT_F, &Pout, &Pout_MaxSpeed, &Pout_F, Pout_SpeedBuf, Pout_Temp);

if (SR!=SR1) MA_AS= 0;

///������ Q_min � ����������� �� E(������� ������) �� ��������������
Q_min= CHARAKT(Rc, &Const[4], numPoint);
///��������� ������
ON_GUARD = (ON && !Prod_On);

///���������� ����� ������ � �������������
//����� �������
//LINE_SURGE = 0;
//����� ������
LineSO= LINE_SURGE - LINE_SAFETY;
//����� ������������ ��������
LineRT= LineRegR - LINE_STEP;
//����� �������� �������� ���
LineTS= LineRegR + LINE_NOT_OPEN;
//����� �������������
LineReg= LINE_SURGE + LINE_REG;
//����� ��������� �� �������� �����������
LineSpeed= LineRegR + LINE_SPEED;
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
	loLim= LO_LIM;
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
	{
	LIM_SPEED_2_1 (APK_ON_constUst, 5, 0,&SP_M);
	}

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
Q_OK= !((T_IN_F && (P_IN_F || DP_F)) || (P_IN_F && DP_F) || DP_F);
//��� ������ ���� �������� ������� ��� �� ���������� ���������� �������
APK_ON_const = (DP_F || !Q_OK);	
//������� � �����
Sensor_OK= (!P_IN_F && !P_OUT_F && !DP_F);
//���������
LIM_SPEED_2_1 (PL_G, 0.01, -0.01,&pl_g);
if (pl_g <0.4) pl_g = 0.4;
else if (pl_g > 1) pl_g = 1;

//��������������� ��������
if (B<700) B= 700;
else if(B>770) B = 770;
//������� ���� �� ���������. ���������� � �������� ����������� �������
INT_R (DP, TS_dP, &dP);
//������ ��� ����������� �������� �� ������
//� ������ ������ ����� ��������� ���������� ��������
if (!DP_F) INT_R (DP, 5, &dP1);
else dP = dP1;
//������ ��� ����������� �������� �� ������
//� ������ ������ ����� ��������� ���������� ��������
if (!T_IN_F) INT_R (T_IN, 5, &Tin);
else T_IN = Tin;
	
///������ ����������� �� ���� �������
MASS(Q_OK,NST,Pin,Pout,T_IN,T_OUT,dP,pl_g,B, //�����
     Nnom,Q_min,KKN,	//���������
	 &Rc,&Q_pr,&Q,&Ky,&Ni,&G);	//������
	 
///��������� ������ SO � ���������������� (�� �������� ����������� � ������� �������)
//������������ �������� ��������� ��
KySpeed= SPEED (Ky,KyBuff);
KySpeed*= -1;

//���������� ������������ �������� (��� �������)
if (KySpeed > KySpeedMax) KySpeedMax = KySpeed;
if (KySpeedMax > 100000) KySpeedMax= 100000;

//�������� ���������� SP ���������� ��� ����������� �������� ����������� � ������� �������
dSP_SpeedAlm= KySpeed * dSP_Kd;
//���� �������� ������ ���
if (ON_GUARD)
	{
	//���� �� �������� ������ �������� � �������� ���� �������..
	if (ON_GUARD && (TEST_DIFF ||((Ky<=LineSpeed) && !Dev_off && (KySpeed>SpeedKyUst))))
		{
		//�������� ��������� (�������� ������)
		if (TEST_DIFF) dSP_SpeedAlm = 0.005;
		//��� ������������ ������
		dDev = 1;
		//������ �������� � ����������� �� ��������
		dDev_SP += dSP_SpeedAlm;
		}
	//���� �������� ������ ��� = ������� �� ����� ���������� � 0
	if (!TEST_DIFF && (KySpeed < SpeedKyUst)) dDev_SP= 0;
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
	{
	MA_AS = 0;
	}

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
LIM_SPEED_2_1 (LineSP, 0, LS_SP_DN,&SP_Ky);
	
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
//SP_M= 50;
	
//� ������ ������ ������������ �������� ��������� SP_M	
if (APR_MA) 
	LIM_SPEED_2_1 (SP_M, LS_MAN_UP, LS_MAN_DN,&SP_M_Current);
	
///���� �������� Kp, Ki, � ����������� �� ����������� ����� �� ����� �������������
//����������� ����� �� ����� �������������
dKy= Ky - SP_Ky;
//���������� ��������
dKy_abs= fabs(dKy);

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
	AS_Kp[0]= Scale_Kp_lt_0[1];
	AS_Ki[0]= Scale_Ki_lt_0[1];
	}
	
	
///��� ��������� ���
//��������
PV[0]= Ky; 
PV[1]= Pout; 
PV[2]= Rc; 

SP[0]= SP_Ky;
SP[1]= P_out_Lim_SP;
SP[2]= Rc_Lim_SP;

Contur_ON[0]= 1;
Contur_ON[1]= !P_OUT_F;
Contur_ON[2]= (!P_IN_F && !P_OUT_F);
//void REG_PID_SEL(*PV, *SP, *Contur_ON, APR_MA, M_SP, *Kp, *Ki, loLimOut,*CV,*Act,*as_MStruct)	
///*************************************************************************************************************************************
REG_PID_SEL(PV,SP,PV_Scale,&Contur_ON,APR_MA,SP_M_Current,AS_Kp,AS_Ki,loLim,&CV_Reg,&Act,&as_MStruct);

Ky_Act= Act[0];
P_out_Act= Act[1];
Rc_Act= Act[2];

//�������� ��������� CV � ��������
INT_R (SPEED_ABS (CV_Reg, CV_RegBuff), 6.0, &CVRegSpeed);
//�����������
if (CVRegSpeed<0) CVRegSpeed= 0;
///******************************************************* STEP *****************	
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
if ((!TEST_RT && (Ky >= LineRegR)) || (!ON_GUARD)) dRT_On= 0;	
//if (!TEST_RT && (Ky >= LineEndZagr)) dRT_On= 0;	

Usl_OF= ((Ky<=SP_Ky) || !Sensor_OK || P_out_Act || Rc_Act);
	
//���� ��������� ���� ������ �� �������� � ������� ����� ��������� �� ����� �������������, �� ����� ����������� RT ���������
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
	as_MStruct.cv = CV_R;
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
OnTimRT= dRT_On && !RTvar2;
RTvar2 = TP(OnTimRT,StepTime,StepTimeTP);
OnTimRT= dRT_On && !RTvar2;
//�������� ������� ���������� CV
if (OnTimRT && !OnTimRT1)	
	{
	RT_var+= Step_Second_var; 
	}
//����������� �������� ���������� CV
if (RT_var>100) RT_var= 100;

///POC Pd
//POC (PS, ON,OFF, IN, TS, IN_F, Usl_OF, SpeedUP_dP, SpeedUP_P_Ku,CVRegSpeed,*dP_max, *MA_AS, *POC_P, *Time, *end_POC, *CV_P,*POC_P_On1)
POC(0, ON_GUARD,PD_OF, Pout, &P_OUT1, SpeedUP_Pd_TS, P_OUT_F, Usl_OF, SpeedUP_dPd, SpeedUP_Pd_Ku,CVRegSpeed,
	dPd_max, &MA_AS, &POC_PD, &Time_PD, &end_PD, &CV_PD, &POC_PD_On1, &POC_PD_var); 


if (end_PD)
	{
	///�� ����� PID ������� �������� CV_R
	as_MStruct.cv = CV_R;
	end_PD= 0;
	}

///POC Ps
//POC(PS, ON,OFF,IN, TS, IN_F, Usl_OF, SpeedUP_dP, SpeedUP_P_Ku,CVRegSpeed,*dP_max, *MA_AS, *POC_P, *Time, *end_POC, *CV_P,*POC_P_On1);
POC(1, ON_GUARD,PS_OF, Pin, &P_IN1, SpeedDN_Ps_TS, P_IN_F, Usl_OF, SpeedDN_dPs, SpeedDN_Ps_Ku,CVRegSpeed,
	dPs_max, &MA_AS, &POC_PS, &Time_PS, &end_PS, &CV_PS, &POC_PS_On1, &POC_PS_var); 

if (end_PS)
	{
	///�� ����� PID ������� �������� CV_R
	as_MStruct.cv = CV_R;
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
	LIM_SPEED_2_1 (CV_MAX, 0, LS_DN, &CV_R);

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
	{
	///�� ����� PID ������� �������� CV_R
	as_MStruct.cv = CV_R;
	}

///�������� (������� ���)
//����� ������ ������� �������� ������� ��� ���������	
if (Produv) // && SR)
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
OnTimRT1= OnTimRT;
SR1= SR;


//������
OUT[0]= Rc;
OUT[1]= Q_pr;
OUT[2]= Q;
OUT[3]= Ky;
OUT[4]= CV_R;
OUT[5]= SP_M_Current;
OUT[6]= NumHlop;
OUT[7]= as_MStruct.loop_selected;
OUT[8]= as_MStruct.pid_struct[1].dI_part;
OUT[9]= as_MStruct.pid_struct[2].err;
OUT[10]= as_MStruct.pid_struct[3].err;
OUT[11]= KySpeedMax; 
OUT[12]= dPs_max[0];
OUT[13]= dPd_max[0];
OUT[14]= Q_min;
OUT[15]= Pin_MaxSpeed;
OUT[16]= Pout_MaxSpeed;
OUT[17]= Ni;
OUT[18]= G;

//�������� ������
OUTb[0]= OUTb[1]= 0;
//���������� ������

OUTb[0] |= APR_MA<<0;
OUTb[0] |= oAO<<1;
OUTb[0] |= dSO<<2;
OUTb[0] |= dRT<<3;
OUTb[0] |= POC_PS<<4;
OUTb[0] |= POC_PD<<5;
OUTb[0] |= MD_PROD<<6;
OUTb[0] |= MD_STOP<<7;
OUTb[0] |= MD_RUN<<8;
OUTb[0] |= MD_ZAGR<<9;
OUTb[0] |= MD_RAZGR<<10;
OUTb[0] |= Ky_Act<<11;
OUTb[0] |= P_out_Act<<12;
OUTb[0] |= Rc_Act<<13;
OUTb[0] |= as_MStruct.pid_struct[1].active<<14;
OUTb[0] |= as_MStruct.pid_struct[2].active<<15;
OUTb[1] |= as_MStruct.pid_struct[3].active<<0;
OUTb[1] |= dDev<<1;


///���������� ����� ������ � �������������
//����� ������
oLine[1]= LineSO;
//����� ������������ ��������
oLine[2]= LineRT;
//����� �������������
oLine[3]= LineRegR;
//����� �������� �������� ���
oLine[4]= LineTS;
//����� ��������� ��������
oLine[5]= LineSP;
//����� ��������� �� �������� �����������
oLine[6]= LineSpeed;
//����� ��������� ��������
oLine[7]= LineEndZagr;


//���������� ����� ����� ����������� ����� ����
MAN_ON = MA_AS;
if (MAN_ON) INb[0] |= (1<<2);
else if ((INb[0]>>2)&1) INb[0] ^= (1<<2);
IN[8]= SP_M;

//*as_MStruct1= as_MStruct;

///***********
Temp_F[0]= ver;	
Temp_F[1]= RT_var;	
Temp_F[2]= CV_RT;	
Temp_F[3]= CV_Reg;	
Temp_F[4]= CV_AS;	
Temp_F[5]= CV_MAX;	
Temp_F[6]= CV_PD;
Temp_F[7]= CV_PS;
Temp_F[8]= CV_POC;
Temp_F[9]= CV_R;	


}
