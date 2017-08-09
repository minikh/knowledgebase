//��������� 2012.07.10
//��������� 2012.07.11
//��������� 2012.07.16
//��������� 2012.07.17
//��������� 2012.07.19

#include <stdio.h>
#include "math.h"     // �������������� �������
#include "PACRXPlc.h" //��������� ��� ����������� PAC
//#include "plcc9070.h" //��������� ��� ����������� 90-70
#include "structs.h"
#include "structs_as.h"
#include "defvars.h" 

static float TON_ARRAY[100];
static short TRIG_ARRAY[100];
int deriv_samples = 12;    // ����� ������� ��� ����������� �������� ��������� ����������

float TSCAN;
static DSEL as_MStruct;

#include "sig_sel_1.c"
#include "as_lib.h"


///***************************************************** main **********************************************************
void GefMain(/*�����*/as_struct, as_swop) // ,as_MStruct1) //, IN, INb
			///*���������*/ Const,
			///*����� �������������*/ Line,
			///*������*/ OUT,OUTb,oLine)// ,as_MStruct1)
AS_Struct *as_struct;
AS_swop *as_swop;
//float *IN;
//short *INb;
//float *Const;
//float *Line;
//float *OUT;
//short *OUTb;
//float *oLine;
//DSEL *as_MStruct1;
{	

//���������� ���� Boolean � �������
static short APK_ON_const,On_RUN,Sensor_OK,dDev,SO_Start,dSO,XLOPOK;

static short Set_LowLim,ON_GUARD,MA_AS;
static short OFF_Tim,POC_PD_On1,POC_PS_On1;
static short dRT_On,end_RT,RTvar2,Produv,up_CV,end_PD,end_PS,OnTimRT;
//static short On_RUN1,MA_AS1,TEST_SO1,XLOPOK1,dSO1,MAN_ON1,dRT1,up_CV1,OnTimRT1,SR1;
static short Prod_On,APR_MA,MD_PROD,MD_STOP,MD_RUN,MD_ZAGR,MD_RAZGR,dRT;
//static short MA_AS_fp,MA_AS_fn,On_RUN_fp;

//���������� ���� Real � �������
static float KySpeed,dSP_SpeedAlm,dDev_SP,dSO_Reg,Q_min;
//static float pl_g,dP,Tin,SP_M_Current;

static float LineRegR,HlopTimerTP1[3],HlopTimerTP2[3],StepTimeTP[3],LineSP,CV_RegBuff[4];
static float Dev_off,NumHlopAO;
//static float KyBuff[4],SP_Ky,CV_R,POC_PD_var, POC_PS_var,P_IN1,P_OUT1;
static float RT_var,CV_RT,CV_AS;
static float Time_PD, Time_PS, NumHlop,Ky;
//static float dPd_max[2], dPs_max[2], CV_PD,CV_PS;
static float Pin_Temp[3], Pout_Temp[3],Tin_Temp[3], Tout_Temp[3];
//static float Pin_SpeedBuf[6], Pout_SpeedBuf[6];

float hiLim,loLim,ver,PL_G,P_IN,Pin,P_OUT,Pout,DP,T_IN;
//float SP_M,KySpeedMax;
short Q_OK;

float pl_g,dP,Tin,Tout;
float LineSO,LineRT,LineTS,LineReg,LineSpeed,LineEndZagr;
float ON,NST,T_OUT,B,TS_dP;
float Nnom,KKN,numPoint,LO_LIM,HI_LIM;
float LINE_SURGE,LINE_SAFETY,LINE_STEP,LINE_REG,LINE_NOT_OPEN,LINE_END_ZAGR,LINE_SPEED;
float NotOpenLim,APK_ON_constUst;
float Q_pr,Q,dSP_Kd,Ni,G,Ne;
//float Rc;
short oAO,POC_PS=0,POC_PD=0;
short MOR,iAO,SR,PRODUV_ON,APK_O,APK_C,MD_MAG,MD_RING,DIFF_OF,PS_OF,PD_OF,RES_SO;
//short MAN_ON;
short RES_HLOP,TEST_SO,TEST_RT,TEST_DIFF;
float LS_MAN_UP,LS_MAN_DN,LS_STOP_RAZGR,LS_RUN_ZAGR,LS_AO,LS_PRODUV_OPEN,LS_PRODUV_CLOSE,LS_SP_DN,LS_DN;
short P_IN_F,P_OUT_F,T_IN_F,T_OUT_F,DP_F,NST_F,Act[3],OnImit;
float SpeedKyUst,LineSafety_TimeSet,LineSafety_Shift,LineSafety_UST,LineSafety_TimeRes;
float dKy,dKy_abs;
float Scale_Kp_lt_0[4],Scale_Kp_gt_0[4],Scale_Ki_lt_0[4],Scale_Ki_gt_0[4],CV_Reg;
float PV[3],SP[3],P_out_Lim_SP,Rc_Lim_SP,Step_First_var,StepTime,Step_Second_var;
//float CVRegSpeed;
short Contur_ON[3],Ky_Act,P_out_Act,Rc_Act,Usl_OF;
short Pin_F,Pout_F,Tin_F,Tout_F;
float SpeedUP_Pd_TS, SpeedUP_dPd, SpeedUP_Pd_Ku, SpeedDN_Ps_TS, SpeedDN_dPs, SpeedDN_Ps_Ku;
float CV_POC, CV_MAX, PV_Scale[4], AS_Ki[3],AS_Kp[3],AS_DB[3];
float Pin_SpeedLim, Pout_SpeedLim,Tin_SpeedLim, Tout_SpeedLim;
//float Pin_MaxSpeed, Pout_MaxSpeed;
float SurgeArray[6];
float Ky_DB, Pout_DB, Rc_DB, KPD, POS, dP_1, dP_2;
float POS_TS,POS_LO,POS_HI,dP_pos_LO,dP_pos_HI,POS_off,Pout_LO,Pout_HI,dP_Pout_LO,dP_Pout_HI,Pout_off;
float Step_TS,SpeedUP_TS,SpeedDN_TS;

//������ ��
ver= 3.1;

//�������������
NST= as_struct->AS_IN.NST ;						//IN[0];	//������� ��
P_IN= as_struct->AS_IN.P_IN ;					//IN[1];	//�������� ���� �� ����� �����������
P_OUT= as_struct->AS_IN.P_OUT ;					//IN[2];	//�������� ���� �� ������ �����������
T_IN= as_struct->AS_IN.T_IN ;					//IN[3];	//����������� ���� �� ����� �����������
T_OUT= as_struct->AS_IN.T_OUT ;					//IN[4];	//����������� ���� �� ������ �����������
DP= as_struct->AS_IN.DP ;						//IN[5];	//������� ���� �� ��������� �����������
PL_G= as_struct->AS_IN.PL_G ;					//IN[6];	//��������� ����
B= as_struct->AS_IN.B ;							//IN[7];	//��������������� ��������
//SP_M= as_struct->AS_IN.SP_M ;					//IN[8];
TSCAN= as_struct->AS_IN.TSCAN ;					//IN[9];
POS= as_struct->AS_IN.POS;


ON= 		as_struct->AS_INb.ON;			//INb[0]>>0 &1;		//��������
MOR= 		as_struct->AS_INb.MOR;			//INb[0]>>1 &1;
//MAN_ON= 	as_struct->AS_INb.MAN_ON;			//INb[0]>>2 &1;
iAO= 		as_struct->AS_INb.iAO;			//INb[0]>>3 &1;
SR= 		as_struct->AS_INb.SR;			//INb[0]>>4 &1;
PRODUV_ON= 	as_struct->AS_INb.PRODUV_ON;			//INb[0]>>5 &1;
APK_O= 		as_struct->AS_INb.APK_O;			//INb[0]>>6 &1;
APK_C= 		as_struct->AS_INb.APK_C;			//INb[0]>>7 &1;
MD_MAG= 	as_struct->AS_INb.MD_MAG;			//INb[0]>>8 &1;
MD_RING= 	as_struct->AS_INb.MD_RING;			//INb[0]>>9 &1;
DIFF_OF= 	as_struct->AS_INb.DIFF_OF;			//INb[0]>>10 &1;
PS_OF= 		as_struct->AS_INb.PS_OF;			//INb[0]>>11 &1;
PD_OF= 		as_struct->AS_INb.PD_OF;			//INb[0]>>12 &1;
RES_SO= 	as_struct->AS_INb.RES_SO;			//INb[0]>>13 &1;
RES_HLOP= 	as_struct->AS_INb.RES_HLOP;			//INb[0]>>14 &1;
TEST_SO= 	as_struct->AS_INb.TEST_SO;			//INb[0]>>15 &1;
TEST_RT= 	as_struct->AS_INb.TEST_RT;			//INb[1]>>0 &1;
TEST_DIFF= 	as_struct->AS_INb.TEST_DIFF;			//INb[1]>>1 &1;

NST_F= 		as_struct->AS_INb.NST_F;			//INb[1]>>2 &1;
P_IN_F= 	as_struct->AS_INb.P_IN_F;			//INb[1]>>3 &1;
P_OUT_F= 	as_struct->AS_INb.P_OUT_F;			//INb[1]>>4 &1;
T_IN_F= 	as_struct->AS_INb.T_IN_F;			//INb[1]>>5 &1;
T_OUT_F= 	as_struct->AS_INb.T_OUT_F;
DP_F= 		as_struct->AS_INb.DP_F;			//INb[1]>>6 &1;
OnImit= 	as_struct->AS_INb.OnImit;


Nnom= as_struct->ConstNag.Nnom; 						//Const[0];
														//Const[1];
KKN= as_struct->ConstNag.KKH;							//Const[2];
numPoint= as_struct->ConstSurge.Num_surge_point; 		//Const[3];
SurgeArray[0]= as_struct->ConstSurge.SurgeArray[0];		//Const[4];
SurgeArray[1]= as_struct->ConstSurge.SurgeArray[1];		//Const[5];
SurgeArray[2]= as_struct->ConstSurge.SurgeArray[2];		//Const[6];
SurgeArray[3]= as_struct->ConstSurge.SurgeArray[3];		//Const[7];
SurgeArray[4]= as_struct->ConstSurge.SurgeArray[4];		//Const[8];
SurgeArray[5]= as_struct->ConstSurge.SurgeArray[5];		//Const[9];
LO_LIM = as_struct->ConstReg.L_LIM;						//Const[10];
HI_LIM = as_struct->ConstReg.H_LIM;						//Const[11];
NotOpenLim = as_struct->ConstSurge.NotOpen_Lim;			//Const[12];
LS_MAN_UP= as_struct->ConstLS.ASR_Man_UP;				//Const[13];
LS_MAN_DN= as_struct->ConstLS.ASR_Man_DN;				//Const[14];
LS_STOP_RAZGR= as_struct->ConstLS.ASR_StopRazgr;		//Const[15];
LS_RUN_ZAGR= as_struct->ConstLS.ASR_RunZagr;			//Const[16];
LS_AO= as_struct->ConstLS.ASR_AO;						//Const[17];
LS_PRODUV_OPEN= as_struct->ConstLS.ASR_Produv_Open;		//Const[18];
LS_PRODUV_CLOSE= as_struct->ConstLS.ASR_Produv_Close;	//Const[19];
//														//Const[20];
LS_DN= as_struct->ConstLS.ASR_DN;						//Const[21];
APK_ON_constUst= as_struct->ConstSurge.APK_O_const;		//Const[22];
TS_dP = as_struct->ConstNag.TS_dP;						//Const[23];
dSP_Kd=  as_struct->ConstSurge.dSP_Kd;					//Const[24];
SpeedKyUst=  as_struct->ConstSurge.Speed_RY03_Alm;		//Const[25];
LineSafety_TimeSet= as_struct->ConstSurge.LineSafety_TimeSet;			//Const[26];
LineSafety_TimeRes= as_struct->ConstSurge.LineSafety_TimeReset;			//Const[27];
LineSafety_Shift= as_struct->ConstSurge.LineSafety_Shift;				//Const[28];
LineSafety_UST= as_struct->ConstSurge.LineSafety_Ust;	//Const[29];
LS_SP_DN= as_struct->ConstLS.ASR_SP_DN;					//Const[30];
														//Const[31];
														//Const[32];
Scale_Kp_lt_0[0]= as_struct->ConstReg.Scale_Kp_lt_0[0];	//Const[33]; //0
Scale_Kp_lt_0[1]= as_struct->ConstReg.Scale_Kp_lt_0[1];	//Const[34]; //0.4
Scale_Kp_lt_0[2]= as_struct->ConstReg.Scale_Kp_lt_0[2];	//Const[35]; //10
Scale_Kp_lt_0[3]= as_struct->ConstReg.Scale_Kp_lt_0[3];	//Const[36]; //0.5

Scale_Kp_gt_0[0]= Scale_Kp_lt_0[0]; //0
Scale_Kp_gt_0[1]= Scale_Kp_lt_0[1]; //0.4
Scale_Kp_gt_0[2]= as_struct->ConstReg.Scale_Kp_gt_0[0];	//Const[37]; //20
Scale_Kp_gt_0[3]= as_struct->ConstReg.Scale_Kp_gt_0[1];	//Const[38]; //0.65

Scale_Ki_lt_0[0]= as_struct->ConstReg.Scale_Ki_lt_0[0];	//Const[39]; //0
Scale_Ki_lt_0[1]= as_struct->ConstReg.Scale_Ki_lt_0[1];	//Const[40]; //0.03
Scale_Ki_lt_0[2]= as_struct->ConstReg.Scale_Ki_lt_0[2];	//Const[41]; //10
Scale_Ki_lt_0[3]= as_struct->ConstReg.Scale_Ki_lt_0[3];	//Const[42]; //0.04

Scale_Ki_gt_0[0]= Scale_Ki_lt_0[0]; //0
Scale_Ki_gt_0[1]= Scale_Ki_lt_0[1]; //0.03
Scale_Ki_gt_0[2]= as_struct->ConstReg.Scale_Ki_gt_0[0];	//Const[43]; //20
Scale_Ki_gt_0[3]= as_struct->ConstReg.Scale_Ki_gt_0[1];	//Const[44]; //0.1

P_out_Lim_SP= as_struct->ConstSurge.P_out_Lim_SP;		//Const[45];
Rc_Lim_SP= as_struct->ConstSurge.RY04_Lim_SP;			//Const[46];
Step_First_var= as_struct->ConstSurge.Step_First_var;	//Const[47];
StepTime= as_struct->ConstSurge.Step_Time;				//Const[48];
Step_Second_var= as_struct->ConstSurge.Step_Second_var;	//Const[49];

SpeedUP_Pd_TS= as_struct->ConstSurge.SpeedUP_Pd_TS;		//Const[50];
SpeedUP_dPd= as_struct->ConstSurge.SpeedUP_dPd;			//Const[51];
SpeedUP_Pd_Ku= as_struct->ConstSurge.SpeedUP_Pd_Ku;		//Const[52];

SpeedDN_Ps_TS= as_struct->ConstSurge.SpeedDN_Ps_TS;		//Const[53];
SpeedDN_dPs= as_struct->ConstSurge.SpeedDN_dPs;			//Const[54];
SpeedDN_Ps_Ku= as_struct->ConstSurge.SpeedDN_Ps_Ku;		//Const[55];

PV_Scale[0]= as_struct->ConstReg.Pout_LO;				//Const[56];
PV_Scale[1]= as_struct->ConstReg.Pout_HI;				//Const[57];
PV_Scale[2]= as_struct->ConstReg.RY04_LO;				//Const[58];
PV_Scale[3]= as_struct->ConstReg.RY04_HI;				//Const[59];

AS_Kp[1]= as_struct->ConstReg.Pout_Kp;					//Const[60];
AS_Ki[1]= as_struct->ConstReg.Pout_Ki;					//Const[61];

AS_Kp[2]= as_struct->ConstReg.RY04_Kp;					//Const[62];
AS_Ki[2]= as_struct->ConstReg.RY04_Ki;					//Const[63];

Pin_SpeedLim= as_struct->ConstLS.Pin_SpeedLim;			//Const[64];
Pout_SpeedLim= as_struct->ConstLS.Pout_SpeedLim;		//Const[65];
Tin_SpeedLim= as_struct->ConstLS.Tin_SpeedLim;			
Tout_SpeedLim= as_struct->ConstLS.Tout_SpeedLim;		


Ky_DB= as_struct->ConstReg.Ky_DB;
Pout_DB= as_struct->ConstReg.Pout_DB;
Rc_DB= as_struct->ConstReg.RY04_DB;

if (as_struct->ConstSurge.Step_TS<10.0) as_struct->ConstSurge.Step_TS= 10.0;
Step_TS= as_struct->ConstSurge.Step_TS;
if (as_struct->ConstSurge.SpeedUP_TS<20.0) as_struct->ConstSurge.SpeedUP_TS= 20.0;
SpeedUP_TS= as_struct->ConstSurge.SpeedUP_TS;
if (as_struct->ConstSurge.SpeedDN_TS<20.0) as_struct->ConstSurge.SpeedDN_TS= 20.0;
SpeedDN_TS= as_struct->ConstSurge.SpeedDN_TS;


//��������� ��������� dP
POS_TS = as_struct->AS_Imit.POS_TS;
POS_LO = as_struct->AS_Imit.POS_LO;
POS_HI = as_struct->AS_Imit.POS_HI;
dP_pos_LO = as_struct->AS_Imit.dP_pos_LO;
dP_pos_HI = as_struct->AS_Imit.dP_pos_HI;
POS_off = as_struct->AS_Imit.POS_off;
Pout_LO = as_struct->AS_Imit.Pout_LO;
Pout_HI = as_struct->AS_Imit.Pout_HI;
dP_Pout_LO = as_struct->AS_Imit.dP_Pout_LO;
dP_Pout_HI = as_struct->AS_Imit.dP_Pout_HI;
Pout_off = as_struct->AS_Imit.Pout_off;

//*************************
LINE_SURGE = as_struct->ConstSurge.Line_Surge;			//Line[0];		//����� �������
LINE_SAFETY = as_struct->ConstSurge.Line_Safety;		//Line[1];	//����� ������
LINE_STEP = as_struct->ConstSurge.Line_Step;			//Line[2];		//����� ������������ �������� ���
LINE_REG = as_struct->ConstSurge.Line_Reg;				//Line[3];		//����� �������������
LINE_NOT_OPEN = as_struct->ConstSurge.Line_NotOpen;		//Line[4];	//����� �������� �������� ���
LINE_END_ZAGR = as_struct->ConstSurge.Line_EndZagr;		//Line[5];	//����� ��������� ��������
LINE_SPEED = as_struct->ConstSurge.Line_Speed;			//Line[6];		//����� ��������� �� �������� �����������

//********************
//Rc= as_struct->AS_OUT.Rc;								//OUT[0];				//������� ������
//KySpeedMax= as_struct->AS_OUT.KySpeedMax; 			//OUT[11];
//dPs_max[0]= as_struct->AS_OUT.dPs_max;					//OUT[12];
//dPd_max[0]= as_struct->AS_OUT.dPd_max;					//OUT[13];
//Pin_MaxSpeed= as_struct->AS_OUT.Pin_MaxSpeed;			//OUT[15];
//Pout_MaxSpeed= as_struct->AS_OUT.Pout_MaxSpeed;		//OUT[16];
//*************************
//��������
Produv= PRODUV_ON;
//void AI_SPEED(/*�����*/float AI, float SpeedLim, short iFolt,
//			/*������*/ float *OUT, float *MaxSpeed, short *oFolt, float *SpeedBuf, float *Temp)

//�������� AI �� �������� ��������� �������
AI_SPEED(P_IN,Pin_SpeedLim, P_IN_F, &Pin, &Pin_MaxSpeed, &Pin_F, Pin_SpeedBuf, Pin_Temp);
AI_SPEED(P_OUT,Pout_SpeedLim, P_OUT_F, &Pout, &Pout_MaxSpeed, &Pout_F, Pout_SpeedBuf, Pout_Temp);
AI_SPEED(T_IN,Tin_SpeedLim, T_IN_F, &Tin, &Tin_MaxSpeed, &Tin_F, Tin_SpeedBuf, Tin_Temp);
AI_SPEED(T_OUT,Tout_SpeedLim, T_OUT_F, &Tout, &Tout_MaxSpeed, &Tout_F, Tout_SpeedBuf, Tout_Temp);

//�������� dP
if (OnImit == 1.0)
	{
	//������ ��������� ��� ��� �������� �������� ��������
	INT_R (POS, POS_TS, &POS_tmp);
	//������ �������� � ����������� �� ��������� ���
	dP_1= Mashtab(POS_tmp,POS_LO,POS_HI,dP_pos_LO,dP_pos_HI) + POS_off;
	if (dP_1 < 0.0) dP_1= 0.0;
	//������ �������� � ����������� �� Pout
	dP_2= Mashtab(Pout,Pout_LO,Pout_HI,dP_Pout_LO,dP_Pout_HI) + Pout_off;
	if (dP_2 < 0.0) dP_2= 0.0;
	//��������� ��������
	DP= dP_1 + dP_2;
	//�����������
	if (DP < 0.0) DP= 0.0;
	//�������� �������
	DP= DP - as_struct->AS_Imit.surge;
	//����� ��������
    as_struct->AS_Imit.dPimit= DP;
	}
else
	dP_1= dP_2= 0.0;


if (SR!=SR1) MA_AS= 0;

///������ Q_min � ����������� �� E(������� ������) �� ��������������
Q_min= CHARAKT(Rc, &SurgeArray[0], numPoint);
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
	//if (!SR && ((MA_AS && !MA_AS1) || (On_RUN && !On_RUN1)))
	if (!SR && (MA_AS_fp || On_RUN_fp))
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
	if (SR && (MA_AS_fp))
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
LIM_SPEED_2_1 (PL_G, 0.01, -0.01,&pl_g_tmp);
pl_g= pl_g_tmp;
if (pl_g <0.4) pl_g = 0.4;
else if (pl_g > 1) pl_g = 1;

//����������� ��������, ���
if (B<90.0) B= 90.0;
else if(B>105.0) B = 105.0;
//������� ���� �� ���������. ���������� � �������� ����������� �������
INT_R (DP, TS_dP, &dP_tmp);
dP= dP_tmp;
//������ ��� ����������� �������� �� ������
//� ������ ������ ����� ��������� ���������� ��������
if (!DP_F) INT_R (DP, 5, &dP1_tmp);
else dP = dP1_tmp;
	
///������ ����������� �� ���� �������
MASS(Q_OK,NST,Pin,Pout,Tin,Tout,dP,pl_g,B, //�����
     Nnom,Q_min,KKN,	//���������
	 &as_struct->AS_MASS, //��� �������
	 &Rc,&Q_pr,&Q,&Ky,&Ni,&Ne,&G,&KPD);	//������
	 
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
LIM_SPEED_2_1 (LineSP, LS_SP_DN, LS_SP_DN,&SP_Ky);
	
//��� ������������� ��� � ������, �������� �� SP �������� �������
if(MA_AS_fp) SP_Ky = LineSP;
//����������� SP
if (SP_Ky>100) SP_Ky= 100;
else if (SP_Ky<0) SP_Ky= 0;

//���������� ������������ �������� �� �������� � ������
if (!APR_MA || Prod_On || MA_AS_fp || MA_AS_fn)	
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
if (dKy>0.0)
	{
	AS_Kp[0]= CHARAKT(dKy_abs, Scale_Kp_gt_0, 2.0);
	AS_Ki[0]= CHARAKT(dKy_abs, Scale_Ki_gt_0, 2.0);
	}
else if (dKy<0.0)
	{
	AS_Kp[0]= CHARAKT(dKy_abs, Scale_Kp_lt_0, 2.0);
	AS_Ki[0]= CHARAKT(dKy_abs, Scale_Ki_lt_0, 2.0);
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

AS_DB[0]= Ky_DB;
AS_DB[1]= Pout_DB;
AS_DB[2]= Rc_DB;

Contur_ON[0]= 1;
Contur_ON[1]= !P_OUT_F;
Contur_ON[2]= (!P_IN_F && !P_OUT_F);

//���� ��������� ������� �� Pout ��� Rc, �� ��������� ��� ������ � �������
if (((Pout>=(P_out_Lim_SP-Pout_DB)) || (Rc>=(Rc_Lim_SP-Rc_DB))) && (!MD_RAZGR)) APR_MA = 0;
//void REG_PID_SEL(*PV, *SP, *Contur_ON, APR_MA, M_SP, *Kp, *Ki, loLimOut,*CV,*Act,*as_MStruct)	
///*************************************************************************************************************************************
REG_PID_SEL(PV,SP,PV_Scale,&Contur_ON,APR_MA,SP_M_Current,AS_Kp,AS_Ki,AS_DB,loLim,&CV_Reg,&Act,&as_MStruct);

Ky_Act= Act[0];
P_out_Act= Act[1] && (Pout>=(P_out_Lim_SP-Pout_DB));
Rc_Act= Act[2] && (Rc>=(Rc_Lim_SP-Rc_DB));

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
INT_R_ON(dRT && !dRT_On, RT_var, Step_TS, &CV_RT);
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
	dPd_max, &MA_AS, &POC_PD, &Time_PD, &end_PD, &CV_PD, &POC_PD_On1, &POC_PD_var, SpeedUP_TS); 


if (end_PD)
	{
	///�� ����� PID ������� �������� CV_R
	as_MStruct.cv = CV_R;
	end_PD= 0;
	}

///POC Ps
//POC(PS, ON,OFF,IN, TS, IN_F, Usl_OF, SpeedUP_dP, SpeedUP_P_Ku,CVRegSpeed,*dP_max, *MA_AS, *POC_P, *Time, *end_POC, *CV_P,*POC_P_On1);
POC(1, ON_GUARD,PS_OF, Pin, &P_IN1, SpeedDN_Ps_TS, P_IN_F, Usl_OF, SpeedDN_dPs, SpeedDN_Ps_Ku,CVRegSpeed,
	dPs_max, &MA_AS, &POC_PS, &Time_PS, &end_PS, &CV_PS, &POC_PS_On1, &POC_PS_var, SpeedDN_TS); 

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

//������
//OUT[0]= Rc;
//as_struct->AS_OUT.Rc = Rc;
//OUT[1]= Q_pr;
as_struct->AS_OUT.Q_pr = Q_pr;
//OUT[2]= Q;
as_struct->AS_OUT.Q= Q;
//OUT[3]= Ky;
as_struct->AS_OUT.Ky= Ky;
//OUT[4]= CV_R;
//as_struct->AS_OUT.CV_R= CV_R;
//OUT[5]= SP_M_Current;
//as_struct->AS_OUT.SP_M_Current= SP_M_Current;
//OUT[6]= NumHlop;
as_struct->AS_OUT.NumHlop= NumHlop;
//OUT[7]= as_MStruct.loop_selected;
as_struct->AS_OUT.loop_selected= as_MStruct.loop_selected;
//OUT[8]= as_MStruct.pid_struct[1].dI_part;
as_struct->AS_OUT.dI_part1= as_MStruct.pid_struct[1].dI_part;
//OUT[9]= as_MStruct.pid_struct[2].err;
as_struct->AS_OUT.err2= as_MStruct.pid_struct[2].err;
//OUT[10]= as_MStruct.pid_struct[3].err;
as_struct->AS_OUT.err3= as_MStruct.pid_struct[3].err;
//OUT[11]= KySpeedMax; 
//as_struct->AS_OUT.KySpeedMax= KySpeedMax;
//OUT[12]= dPs_max[0];
//as_struct->AS_OUT.dPs_max= dPs_max[0];
//OUT[13]= dPd_max[0];
//as_struct->AS_OUT.dPd_max= dPd_max[0]; 
//OUT[14]= Q_min;
as_struct->AS_OUT.Q_min= Q_min;
//OUT[15]= Pin_MaxSpeed;
//as_struct->AS_OUT.Pin_MaxSpeed= Pin_MaxSpeed;
//OUT[16]= Pout_MaxSpeed;
//as_struct->AS_OUT.Pout_MaxSpeed= Pout_MaxSpeed;
//OUT[17]= Ni;
as_struct->AS_OUT.Ni= Ni;
as_struct->AS_OUT.Ne= Ne;
//OUT[18]= G;
as_struct->AS_OUT.G= G;
as_struct->AS_OUT.KPD= KPD;

//�������� ������
//OUTb[0]= OUTb[1]= 0;
//���������� ������
//OUTb[0] |= APR_MA<<0;
as_struct->AS_OUTb.APR_MA= APR_MA;
//OUTb[0] |= oAO<<1;
as_struct->AS_OUTb.oAO= oAO;
//OUTb[0] |= dSO<<2;
as_struct->AS_OUTb.dSO= dSO;
//OUTb[0] |= dRT<<3;
as_struct->AS_OUTb.dRT= dRT;
//OUTb[0] |= POC_PS<<4;
as_struct->AS_OUTb.POC_PS= POC_PS;
//OUTb[0] |= POC_PD<<5;
as_struct->AS_OUTb.POC_PD= POC_PD;
//OUTb[0] |= MD_PROD<<6;
as_struct->AS_OUTb.MD_PROD= MD_PROD;
//OUTb[0] |= MD_STOP<<7;
as_struct->AS_OUTb.MD_STOP= MD_STOP;
//OUTb[0] |= MD_RUN<<8;
as_struct->AS_OUTb.MD_RUN= MD_RUN;
//OUTb[0] |= MD_ZAGR<<9;
as_struct->AS_OUTb.MD_ZAGR= MD_ZAGR;
//OUTb[0] |= MD_RAZGR<<10;
as_struct->AS_OUTb.MD_RAZGR= MD_RAZGR;
//OUTb[0] |= Ky_Act<<11;
as_struct->AS_OUTb.Ky_Act= Ky_Act;
//OUTb[0] |= P_out_Act<<12;
as_struct->AS_OUTb.P_out_Act= P_out_Act;
//OUTb[0] |= Rc_Act<<13;
as_struct->AS_OUTb.Rc_Act= Rc_Act;
//OUTb[0] |= as_MStruct.pid_struct[1].active<<14;
as_struct->AS_OUTb.pid_struct_1_active= as_MStruct.pid_struct[1].active;
//OUTb[0] |= as_MStruct.pid_struct[2].active<<15;
as_struct->AS_OUTb.pid_struct_2_active= as_MStruct.pid_struct[2].active;
//OUTb[1] |= as_MStruct.pid_struct[3].active<<0;
as_struct->AS_OUTb.pid_struct_3_active= as_MStruct.pid_struct[3].active;
//OUTb[1] |= dDev<<1;
as_struct->AS_OUTb.dDev= dDev;


///���������� ����� ������ � �������������
//����� ������
//oLine[1]= LineSO;
as_struct->AS_oLine.LineSO= LineSO;
//����� ������������ ��������
//oLine[2]= LineRT;
as_struct->AS_oLine.LineRT= LineRT;
//����� �������������
//oLine[3]= LineRegR;
as_struct->AS_oLine.LineRegR= LineRegR;
//����� �������� �������� ���
//oLine[4]= LineTS;
as_struct->AS_oLine.LineTS= LineTS;
//����� ��������� ��������
//oLine[5]= LineSP;
as_struct->AS_oLine.LineSP= LineSP;
//����� ��������� �� �������� �����������
//oLine[6]= LineSpeed;
as_struct->AS_oLine.LineSpeed= LineSpeed;
//����� ��������� ��������
//oLine[7]= LineEndZagr;
as_struct->AS_oLine.LineEndZagr= LineEndZagr;

as_struct->AS_oLine.LineReg= LineReg;

//���������� ����� ����� ����������� ����� ����
MAN_ON = MA_AS;
//as_struct->AS_INb.MAN_ON= MAN_ON;
/*if (MAN_ON) INb[0] |= (1<<2);
else if ((INb[0]>>2)&1) INb[0] ^= (1<<2);*/

//as_struct->AS_IN.SP_M= SP_M;			//IN[8]= SP_M;

//*as_MStruct1= as_MStruct;

///***********
as_struct->AS_CV.RT_var= RT_var;	
as_struct->AS_CV.CV_RT= CV_RT;	
as_struct->AS_CV.CV_Reg= CV_Reg;	
as_struct->AS_CV.CV_AS= CV_AS;	
as_struct->AS_CV.CV_MAX= CV_MAX;	
//as_struct->AS_CV.CV_PD= CV_PD;
//as_struct->AS_CV.CV_PS= CV_PS;
as_struct->AS_CV.CV_POC= CV_POC;
as_struct->AS_CV.oCV_R= CV_R;



as_struct->AS_Temp.ver = ver;	
as_struct->AS_Temp.hiLim= hiLim;
as_struct->AS_Temp.loLim= loLim;
as_struct->AS_Temp.Q_min= Q_min;
as_struct->AS_Temp.Q_OK= Q_OK;
as_struct->AS_Temp.APK_ON_const= APK_ON_const;
as_struct->AS_Temp.On_RUN= On_RUN;
as_struct->AS_Temp.Sensor_OK= Sensor_OK;
as_struct->AS_Temp.PL_Gi= PL_G;
as_struct->AS_Temp.pl_g= pl_g;
as_struct->AS_Temp.P_IN= P_IN;
as_struct->AS_Temp.Pin= Pin;
as_struct->AS_Temp.P_OUT= P_OUT;
as_struct->AS_Temp.Pout= Pout;
as_struct->AS_Temp.DPi= DP;
as_struct->AS_Temp.dP= dP;
as_struct->AS_Temp.dP1= dP1_tmp;
as_struct->AS_Temp.T_IN= T_IN;
as_struct->AS_Temp.Tin= Tin;
as_struct->AS_Temp.KySpeed= KySpeed;
as_struct->AS_Temp.Ky_SpeedMax= KySpeedMax;
as_struct->AS_Temp.dSP_SpeedAlm= dSP_SpeedAlm;
as_struct->AS_Temp.dDev_SP= dDev_SP;
as_struct->AS_Temp.dDev= dDev;
as_struct->AS_Temp.SO_Start= SO_Start;
as_struct->AS_Temp.dSO= dSO;
as_struct->AS_Temp.XLOPOK= XLOPOK;
as_struct->AS_Temp.dSO_Reg= dSO_Reg;
as_struct->AS_Temp.oSP_M= SP_M;
as_struct->AS_Temp.oSP_M_Current= SP_M_Current;
as_struct->AS_Temp.MA_AS= MA_AS;
as_struct->AS_Temp.dP_1= dP_1;
as_struct->AS_Temp.dP_2= dP_2;


//��� ������ ������������ �������� ������� ��������
MA_AS_fp = (MA_AS && !MA_AS1);
MA_AS_fn = (!MA_AS && MA_AS1);
MA_AS1= MA_AS;

On_RUN_fp = (On_RUN && !On_RUN1);
On_RUN1= On_RUN;


TEST_SO1 = TEST_SO;
XLOPOK1= XLOPOK;
dSO1= dSO;
MAN_ON1 = MAN_ON;
dRT1= dRT;
up_CV1= up_CV;
OnTimRT1= OnTimRT;
SR1= SR;
}
