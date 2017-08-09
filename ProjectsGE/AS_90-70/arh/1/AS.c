#include "math.h"     // �������������� �������
#include "PACRXPlc.h" //��������� ��� ����������� PAC
//#include "plcc9070.h" //��������� ��� ����������� 90-70
#include "as_lib.h"

float TSCAN;

///**************************** MASS ********************************************
void MASS (/*�����*/ON_Calc,N,P_IN,P_OUT,T_IN,dP,p_g,B,
			/*���������*/Nnom,Q_min,KKN,
			/*������*/Rc,Q_pr,Q,Ky)
float ON_Calc;
float N;
float P_IN; 	//���/��2
float P_OUT;	//���/��2
float T_IN;	//��.�
float dP;
float Nnom;
float Q_min;
float p_g;
float B;
float KKN;

float *Rc;
float *Q_pr;
float *Q;
float *Ky;
{
float B_, Pin, Tin, p_, R, Tkr, Tpr, Pkr, Ppr, Zin, p_N;
//float N,P_IN,P_OUT,T_IN, Ky, Q_pr, Nnom, Q_min, p_g, B, ON_Calc;

ON_Calc= 1;
//���� ������ �������, �� ����������
if (ON_Calc == 1)
	{
	//������� ������
	if (P_IN != 0) 
		*Rc = P_OUT / P_IN;	
	else
		*Rc = 1;
	
	//��������������� ��������, (ks/cm2)
	B_= B * 1.0332/760.0;

	//�������� �� ����� � �����������, (ks/cm2)
	Pin= (P_IN * 0.010197) + B_;
	if (Pin == 0.0) Pin= 0.0000001; 

	//����������� �� ����� � �����������, (��K)
	Tin= T_IN+273.2;

	//������������� ��������� ����
	p_= p_g/1.205;

	//������� ����������
	if (p_!= 0.0) 
		R= 29.27/p_;
	else 
		R= 1;

	//����������������� �����������
	Tkr= 162.8 * (0.613+p_);

	//����������������� ��������
	Pkr= 47.9-p_;
	if (Pkr == 0.0) Pkr= 0.0001; 

	//���������� �����������
	if (Tkr != 0.0) 
		Tpr= Tin/Tkr;
	else 
		Tpr= 1;
	
	if (Tpr == 0.0) 
		Tpr= 0.01; 

	//���������� ��������
	Ppr= Pin/Pkr;
	if (Ppr == 0.0) Ppr= 0.0001; 


	//����������� �����������
	Zin= 1.0 - (((0.41 / (Tpr*Tpr*Tpr)) - (0.061/Tpr)) * Ppr)-(0.04 * (Tpr*Tpr)/(Tpr*Tpr*Tpr));	
		
	//��������� �� ����� � �����������	
	if (Zin * Tin * R != 0) 
		p_N = (Pin * 10000) / (Zin * Tin * R);
	else 
		p_N= 1;
	
	if (p_N == 0.0) p_N= 0.0001; 

	//������������������ (�3/���)
	float val = (13.6 * dP * 0.010197 * 735.0)/p_N;
	

	if (val >0) 
		*Q = KKN * sqrtf(val);
	else *Q = 0;
		
	//����������� ������������������ (�3/���)	
	if (N != 0) 
		*Q_pr = *Q * (Nnom/N);
	else 
		*Q_pr= 0;
	
	//����� �� ������� %
	if (Q_min != 0) 
		*Ky = 100 * (*Q_pr - Q_min) / Q_min;
	else 
		*Ky = 0;

	if (*Ky < -10.0)
		*Ky= -10.0;
	else if (*Ky > 200.0)
		*Ky= 200.0; 	


	} // if (ON_Calc == 1)
//���� ������ ��������, �� ���������� ������� ��������
else 
	{
	*Ky = 0;
	*Rc = 1;
	*Q = 0;
	*Q_pr = 0;
	}
} 

/// ********************************** Mashtab *************************************************
float Mashtab (float In, float Isl, float Ish, float Osl, float Osh)
{
float Out;
if ((Ish-Isl)!= 0)
	Out= (((Osh-Osl)*(In-Isl))/(Ish-Isl))+Osl;
else
	Out= Osl;
return Out;
} 

/// ********************************** SurgeLineSet *************************************************
//������� ������� - �������� ����������� �������
float SurgeLineSet(float E, float *Array, float num)
{
int i,n,k;
float Out=0;
n= num*2-2;

//���� E < ������������ ��������
if (E <= Array[0])
	Out= Array[1];
//���� E > ������������� ��������
else if (E > Array[n])
	{
	k= n+1;
	//�� ��������� ������������ ��������
	Out= Array[k];
	}
else
	{
	//��������� ������
	for (i= 0; i <= (n-1); i+=2) 
		{
		k= i+2;
		if ((E > Array[i]) && (E <= Array[k]))
			Out= Mashtab(E, Array[i], Array[i+2], Array[i+1], Array[i+3]);
		}
	} 	
return Out;	
}

///***************************************************** RAMP **********************************************************
void Ramp (float Speed, float *Out)
{
//���� �������� != 0, �� �������� ��������� ������
if (Speed != 0) 
	*Out+= Speed * TSCAN;
} 			

///***************************************************** LIM_SPEED_2_1 **********************************************************
void LIM_SPEED_2_1 (float in, float max, float min,float *Out)
{
float prir,maxzikl,minzikl;
//���� �������� != 0, �� �������� ��������� ������
 if (in!= *Out)
	{
	prir = in- *Out;
	if ((max>0) && (prir>0))
		{
		maxzikl= max*TSCAN;
		if (prir>maxzikl)
			*Out+=maxzikl;
		}
		
	if ((min<0) && (prir<0))
		{
		minzikl= min*TSCAN;
		if (prir<minzikl)
			*Out+=minzikl;
		}		
	}
} 	

///***************************************************** INT_R **********************************************************
void INT_R (float IN, float TS, float *Out)
{
// �������������� �����: OU=IN/(1+TS)
// TS ������ � ���.
// ���� (IN) � ����� (OU) ������ � %
// ��� �������� � REAL
// ��� ����������� ���������� � %P37 ������ ���� ��������� ����� 
// ������������ ��������� � ���.
float PRIR,PRIRABS,KOEF;
PRIR= IN - *Out;

PRIRABS= fabsf(PRIR);
if (PRIRABS <= 1.000000e-007)
	*Out= IN;
else
	{
	KOEF= TSCAN/(TSCAN + TS);
	*Out+= (PRIR*KOEF);
	}
}

///***************************************************** SPEED **********************************************************
float SPEED (float IN, float *Buff)
{
float Out;
Buff[3] = Buff[2];
Buff[2] = Buff[1];
Buff[1] = Buff[0];
Buff[0] = IN;

return Out= (fabs(Buff[0]-Buff[2]) + fabs(Buff[1]-Buff[3]))/TSCAN/4;
}

///***************************************************** Timer Pulse **********************************************************
short TP (float *Time, float Ust, short EN, short *T)
// *Time ������� ����� �������
// Ust ������� �������
// EN ������ �������
{
short out;
//���� ������ �������, �� �������
if (EN) T[0]=1;

if (EN && (EN != T[1])) 
	T[0] = 0;

if (T[0])
	{
	//���� ������� ����� ������ �������, ��
	if (*Time < Ust) 
		{
		//����� ������� � 0
		out= 1;
		//��������� ������� ����� �� ����� �����
		*Time += TSCAN;
		}
	//���� ������� ����� ������ �������, �� ����� ������� � 1
	else
		{
		out= 0;	
		T[0]= 0;
		}
	}
//���� ������ ��������, �� 
else
	{
	//����� ������� = 0
	*Time = 0;
	//������� ����� = 0
	out = 0;
	}
T[1] = EN;
return out;
}

///***************************************************** main **********************************************************
void GefMain(/*�����*/IN, Folt, INb,
			/*���������*/ Const,
			/*����� �������������*/ Line,
			/*������*/ OUT,OUTb,
			Temp_F,Temp_I)
float *IN;
short *INb;
short *Folt;
float *Const;
float *Line;
float *OUT;
short *OUTb;
float *Temp_F;
short *Temp_I;
//				IN    0	1   2     3    4   5  6  7
//    main (/*�����*/ON,N,P_IN,P_OUT,T_IN,dP,PL_G,B,
//				Const	  0     1    2      3      4...9
//			/*���������*/Nnom,Q_min,KKN,numPoint,����� ����� �������
//				OUT	   0  1   2  3
//			/*������*/Rc,Q_pr,Q,Ky) 
{
//���������� ���� Boolean � �������
static short Prod_On,Set_LowLim,APR_MA,ON_GUARD,MA_AS,Sensor_OK,MD_PROD,MD_STOP,MD_RUN,MD_ZAGR,MD_RAZGR,On_RUN,On_RUN1,MA_AS1;
static short APK_ON_const,dDev,TEST_SO1,SO_Start;
//���������� ���� Real � �������
static float LineRegR,Q_min,pl_g,dP,HlopTimerTP[2];
static float *KyBuff[4],KySpeed,dSP_SpeedAlm,Dev_off,dDev_SP,SP_Ky;

float LineSO,LineRT,LineTS,LineReg,LineSpeed,LineEndZagr;
float ON,NST,P_IN,P_OUT,T_IN,DP,PL_G,B,TS_dP;
float Nnom,KKN,numPoint,LO_LIM,HI_LIM,CV_R,SP_M,SP_M_Current,NumHlop;
float LINE_SURGE,LINE_SAFETY,LINE_STEP,LINE_REG,LINE_NOT_OPEN,LINE_END_ZAGR,LINE_SPEED;
float hiLim,loLim,NotOpenLim,APK_ON_constUst;
float  Rc,Q_pr,Q,Ky,KySpeedMax,dSP_Kd;
short PID_MAN,oAO,dSO,dRT,POC_PS,POC_PD,P_IN_ACT,P_OUT_ACT,Q_OK;
short MOR,MAN_ON,iAO,SR,PRODUV_ON,APK_O,APK_C,MD_MAG,MD_RING,DIFF_OF,PS_OF,PD_OF,RES_SO;
short RES_HLOP,TEST_SO,TEST_RT,TEST_DIFF,var_1;
float LS_MAN_UP,LS_MAN_DN,LS_STOP_RAZGR,LS_RUN_ZAGR,LS_AO,LS_PRODUV_OPEN,LS_PRODUV_CLOSE,LS_SP_DN,LS_DN;
short P_IN_F,P_OUT_F,T_IN_F,DP_F,NST_F;
float SpeedKyUst;

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
Q_min= SurgeLineSet(Rc, &Const[4], numPoint);
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
	Temp_F[3]= DP;
	Temp_F[4]= dP;
///������ ����������� �� ���� �������
MASS(/*�����*/ON,NST,P_IN,P_OUT,T_IN,dP,pl_g,B,
     /*���������*/Nnom,Q_min,KKN,
	 /*������*/&Rc,&Q_pr,&Q,&Ky);
	 
///��������� ������ SO � ���������������� (�� �������� ����������� � ������� �������)
//������������ �������� ��������� ��
KySpeed= SPEED (Ky,&KyBuff);
KySpeed*= -1;

//���������� ������������ �������� (��� �������)
if (KySpeed > KySpeedMax) KySpeedMax = KySpeed;
Temp_F[0]= KySpeedMax;
//�������� ���������� SP ���������� ��� ����������� �������� ����������� � ������� �������
dSP_SpeedAlm= KySpeedMax * dSP_Kd;
//���� �������� ������ ���
if (ON)
	{
	//���� �� �������� ������ �������� � �������� ���� �������..
	if (ON && (TEST_DIFF ||((Ky<=LineSpeed) && !Dev_off && (KySpeed>SpeedKyUst))))
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
if (ON)
	{
	if ((Ky < LineSO) || (TEST_SO && (TEST_SO != TEST_SO1)))
		{
		SO_Start = 1;
		dSO = 1;
		}
	else SO_Start = 0;
	}

//short TP (float *Time, float Ust, short EN, short T)
//Temp_I[0] = TP(&Temp_F[5],Temp_F[6],Temp_I[1],&Temp_I[2]);
Temp_I[0] = TP(&Temp_F[5],Temp_F[6],Temp_I[1],&HlopTimerTP);





//��� ������ ������������ �������� ������� ��������
On_RUN1= On_RUN;
MA_AS1= MA_AS;
TEST_SO1 = TEST_SO;

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
}
