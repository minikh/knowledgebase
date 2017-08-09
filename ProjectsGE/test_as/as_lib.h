///**************************** MASS ********************************************
void MASS (/*�����*/ON,N,P_IN,P_OUT,T_IN,dP,p_g,B,
			/*���������*/Nnom,Q_min,KKN,
			/*������*/Rc,Q_pr,Q,Ky)
short ON;
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
float val;
//float N,P_IN,P_OUT,T_IN, Ky, Q_pr, Nnom, Q_min, p_g, B, ON_Calc;
//*Temp= 10;
//���� ������ �������, �� ����������

if (ON == 1)
	{
	//������� ������
	if (P_IN != 0) 
		*Rc = P_OUT / P_IN;	
	else
		*Rc = 1;
	
	if (*Rc <1) *Rc= 1;
	
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
	val = (13.6 * dP * 0.010197 * 735.0)/p_N;
	

	if (val >0) 
		*Q = KKN * sqrt(val);
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

/// ********************************** CHARAKT *************************************************
//�������������
float CHARAKT(float E, float *Array, float num)
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
			{
			*Out+=maxzikl;
			return;
			}
		}
		
	if ((min<0) && (prir<0))
		{
		minzikl= min*TSCAN;
		if (prir<minzikl)
			{
			*Out+=minzikl;
			return;
			}
		}
	*Out= in;
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

PRIRABS= fabs(PRIR);
if (PRIRABS <= 1.000000e-007)
	*Out= IN;
else
	{
	KOEF= TSCAN/(TSCAN + TS);
	*Out+= (PRIR*KOEF);
	}
}

///***************************************************** INT_R_ON **********************************************************
void INT_R_ON (short ON, float IN, float TS, float *Out)
{
// �������������� �����: OU=IN/(1+TS)
// TS ������ � ���.
// ���� (IN) � ����� (OU) ������ � %
// ��� �������� � REAL
// ��� ����������� ���������� � %P37 ������ ���� ��������� ����� 
// ������������ ��������� � ���.
float PRIR,PRIRABS,KOEF;
if (ON)
	{
	PRIR= IN - *Out;

	PRIRABS= fabs(PRIR);
	if (PRIRABS <= 1.000000e-007)
		*Out= IN;
	else
		{
		KOEF= TSCAN/(TSCAN + TS);
		*Out+= (PRIR*KOEF);
		}
	}
else *Out= IN;
}

///***************************************************** SPEED **********************************************************
float SPEED (float IN, float *Buff) //Buff[4]
{
float Out;
Buff[3] = Buff[2];
Buff[2] = Buff[1];
Buff[1] = Buff[0];
Buff[0] = IN;

return Out= ((Buff[0]-Buff[2]) + (Buff[1]-Buff[3]))/TSCAN/4;
}

///***************************************************** SPEED_ABS **********************************************************
float SPEED_ABS (float IN, float *Buff) //Buff[4]
{
float Out;
Buff[3] = Buff[2];
Buff[2] = Buff[1];
Buff[1] = Buff[0];
Buff[0] = IN;

return Out= (fabs(Buff[0]-Buff[2]) + fabs(Buff[1]-Buff[3]))/TSCAN/4;
}

///***************************************************** Timer Pulse **********************************************************
short TP (short EN, float Ust, float *T)
//On = TP(EN,Ust,&HlopTimerTP);
// *Time ������� ����� �������
// Ust ������� �������
// EN ������ �������
{
short out;
float On, EN1, Time;
Time = T[0];
On= T[1];
EN1= T[2];
//���� ������ �������, �� �������
//if (EN) On=1;

if (EN && !EN1) 
	On = 1;

if (On)
	{
	//���� ������� ����� ������ �������, ��
	if (Time < Ust) 
		{
		//����� ������� � 0
		out= 1;
		//��������� ������� ����� �� ����� �����
		Time += TSCAN;
		}
	//���� ������� ����� ������ �������, �� ����� ������� � 0
	else
		{
		out= 0;	
		Time= 0;
		On= 0;
		}
	}
//���� ������ ��������, �� 
else
	{
	//������� ����� = 0
	Time = 0;
	//����� ������� = 0
	out = 0;
	}
T[0] = Time;
T[1] = On;
T[2] = EN;
return out;
}

///******************************************* Timer TON1 ***************************************************
//	������ 
// *Time ������� ����� �������
// Ust ������� �������
// EN ������ �������
short TON1(short EN, float Ust, float *Time)
{
short out;
//���� ������ �������, �� �������
if (EN)
	{
	//���� ������� ����� ������ �������, ��
	if (*Time < Ust) 
		{
		//����� ������� � 0
		out= 0;
		//��������� ������� ����� �� ����� �����
		*Time += TSCAN;
		}
	//���� ������� ����� ������ �������, �� ����� ������� � 1
	else
		out= 1;	
	}
//���� ������ ��������, �� 
else
	{
	//����� ������� = 0
	*Time = 0;
	//������� ����� = 0
	out = 0;
	}
return out;
}

///******************************************* Timer TOF ***************************************************
//	������ 
// *Time ������� ����� �������
// Ust ������� �������
// EN ������ �������
short TOF(short EN, float Ust, float *Time)
{
short out;
short ON, EN1;
ON= Time[1];
EN1= Time[2];

//���� ������ �������, �� 
if (EN)
	{
	//������� ����� = 0
	*Time = 0;
	//����� ������� = 0
	out = 1;
	ON= 0;
	}

//���� EN ���� = 0, �� �������� ����
if (!EN != EN1)
	ON=1;

//�������
if (ON)
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
		ON= 0;
		}
	}
EN1= EN;
Time[1]= ON;
Time[2]= EN1;
return out;
}

/// *******************************************  ������� POC ******************************************* 
//����������� �������� ���������� �������� �� ����������
void  POC (PS, ON,OFF, IN, IN1, TS, IN_F, Usl_OF, SpeedUP_dP, SpeedUP_P_Ku,CVRegSpeed,dP_max, 
			MA_AS, POC_P, Time, end_POC, CV_P,POC_P_On1,POC_P_var)
short PS;
short ON;
short OFF;
float IN;
float *IN1;
float TS;
short IN_F;
short Usl_OF;
float SpeedUP_dP;
float SpeedUP_P_Ku;
float CVRegSpeed;
float *dP_max;
short *MA_AS;
short *POC_P;
float *Time;
short *end_POC;
float *CV_P;
short *POC_P_On1;
float *POC_P_var;


{
float dP;
short T_On,POC_P_On=0;
//����������� ������
INT_R (IN, TS, IN1);

//���� �������� POC Ps, �� ����������� dP
if (PS) dP= *IN1 - IN; 	//�������
else dP= IN - *IN1;		//�������

//������������ ��������
if (dP> dP_max[0]) dP_max[0]= dP;

if (!OFF && !IN_F && ON && (dP>SpeedUP_dP)) 
	{
	if (dP> dP_max[1]) dP_max[1]= dP;
	//void LIM_SPEED_2_1 (float in, float max, float min,float *Out)
	LIM_SPEED_2_1(SpeedUP_P_Ku * (dP-SpeedUP_dP), 0, -0.01, POC_P_var);
	*POC_P= 1;
	POC_P_On= 1;
	}
else POC_P_On= 0;

if (POC_P_On && !*POC_P_On1) *MA_AS= 0;
//�����������
if (*POC_P_var > 100) *POC_P_var= 100;
//���� ��������� ���� ������ �� �������� � ������� ����� ��������� �� ����� �������������, 
//�� ����� ����������� POC_Pd ���������
T_On= (*POC_P && !POC_P_On && (CVRegSpeed >= 0) && Usl_OF);
*end_POC= TON1(T_On, 0.1, Time);
//��������� POC
if ((*POC_P && (*CV_P <=0)) || *MA_AS || !ON || *end_POC)
	*POC_P= 0;

//����� ������� � �����, �� ��������� ����� POC_Pd �����������
INT_R_ON (*POC_P && !POC_P_On, *POC_P_var, 200, CV_P);

if (!POC_P_On) *POC_P_var= -6;
if (*CV_P<0) *CV_P= 0;
else if (*CV_P>100) *CV_P= 100;

*POC_P_On1= POC_P_On;

}

///***************************************************** REG_PID_SEL **********************************************************
//��������
//REG_PID_SEL(PV,SP,PV_Scale,&Contur_ON,APR_MA,SP_M_Current,AS_Kp,AS_Ki,loLim,&CV_Reg,&Act,as_MStruct);
void REG_PID_SEL(/*�����*/PV, SP, PV_Scale, ON, APR_MA, M_SP, Kp, Ki, loLim,
					/*������*/CV,Act,as_MStruct)

float *PV;
float *SP; 
float *PV_Scale;
short *ON; 
short APR_MA;
float M_SP;
float *Kp;
float *Ki;
float loLim;
float *CV; 
short *Act; //����� ��������� ������� Act[3];
DSEL *as_MStruct;
{
T_INT16 test_reg[30];
float PV1, PV2, PV3, SP1, SP2, SP3,d_pd;
static float PD_prev;
int a;
//������ �����
as_MStruct->low_clamp= loLim;
/*
//����������� PV2
if (PV[1]<PV_Scale[0]) PV[1]= PV_Scale[0];
else if (PV[1]>PV_Scale[1]) PV[1]= PV_Scale[1];
//����������� SP2
if (SP[1]<PV_Scale[0]) SP[1]= PV_Scale[0];
else if(SP[1]>PV_Scale[1]) SP[1]= PV_Scale[1];

//����������� PV3
if (PV[2]<PV_Scale[2]) PV[2]= PV_Scale[2];
else if(PV[2]>PV_Scale[3]) PV[2]= PV_Scale[3];
//����������� SP2
if (SP[2]<PV_Scale[2]) SP[2]= PV_Scale[2];
else if(SP[2]>PV_Scale[3]) SP[2]= PV_Scale[3];
*/
//������ �����
///*******************************************************************************************
as_MStruct->auto_man= 1; //!APR_MA; ////******************

//��������������
//float Mashtab (float In, float Isl, float Ish, float Osl, float Osh)
PV1= PV[0];
SP1= SP[0];
PV2= PV[1];//Mashtab (PV[1], PV_Scale[0], PV_Scale[1], 0.0, 100.0);
SP2= 15;//Mashtab (SP[1], PV_Scale[0], PV_Scale[1], 0.0, 100.0);
PV3= PV[2];//Mashtab (PV[2], PV_Scale[2], PV_Scale[3], 0.0, 100.0);
SP3= 60;//Mashtab (SP[2], PV_Scale[2], PV_Scale[3], 0.0, 100.0);

//������ ������������� ������� (��������)
as_MStruct->pid_struct[1].loop_type = 0;
as_MStruct->pid_struct[1].loop_num = 1;
as_MStruct->pid_struct[1].loop_enable = 1;
as_MStruct->pid_struct[1].loop_valid = 1;
as_MStruct->pid_struct[1].auto_man = 1;
as_MStruct->pid_struct[1].loop_direct = 1;

as_MStruct->pid_struct[1].act_SP = SP1;
as_MStruct->pid_struct[1].PV = PV1;
as_MStruct->pid_struct[1].KP = Kp[0];
as_MStruct->pid_struct[1].KI = Ki[0];
as_MStruct->pid_struct[1].KD = 0.0; //AS_Kd;
as_MStruct->pid_struct[1].delt_t = TSCAN;
as_MStruct->pid_struct[1].DB = 0;//1.0;

//������ ����������� �������� ���� �� ������ ����������� (�����������)
as_MStruct->pid_struct[2].loop_type = 1;
as_MStruct->pid_struct[2].loop_num = 2;
as_MStruct->pid_struct[2].loop_enable = 1;
as_MStruct->pid_struct[2].loop_valid = ON[1]; 
as_MStruct->pid_struct[2].auto_man = 1;
as_MStruct->pid_struct[2].loop_direct = 0;

as_MStruct->pid_struct[2].act_SP = SP2;
as_MStruct->pid_struct[2].PV = PV2;
as_MStruct->pid_struct[2].KP = Kp[1];
as_MStruct->pid_struct[2].KI = Ki[1];
as_MStruct->pid_struct[2].KD = 0.0;
as_MStruct->pid_struct[2].delt_t = TSCAN;
as_MStruct->pid_struct[2].DB = 0.1;

//������ ����������� ������� ������ ����������� (�����������)
as_MStruct->pid_struct[3].loop_type = 1;
as_MStruct->pid_struct[3].loop_num = 3;
as_MStruct->pid_struct[3].loop_enable = 1;
as_MStruct->pid_struct[3].loop_valid = ON[2]; 
as_MStruct->pid_struct[3].auto_man = 1;
as_MStruct->pid_struct[3].loop_direct = 0;

as_MStruct->pid_struct[3].act_SP = SP3;
as_MStruct->pid_struct[3].PV = PV3;
as_MStruct->pid_struct[3].KP = Kp[2];
as_MStruct->pid_struct[3].KI = Ki[2];
as_MStruct->pid_struct[3].KD = 0.0;
as_MStruct->pid_struct[3].delt_t = TSCAN;
as_MStruct->pid_struct[3].DB = 0.0;


d_pd = as_MStruct->PplusD_selected - PD_prev;

if (as_MStruct->dI_selected < -0.5*TSCAN)
	as_MStruct->dI_selected = -0.5*TSCAN;
if ((d_pd + as_MStruct->dI_selected) < -0.5*TSCAN)
	d_pd = -0.5*TSCAN - as_MStruct->dI_selected; 


PD_prev = PD_prev + d_pd;

as_MStruct->cv = as_MStruct->cv + d_pd + as_MStruct->dI_selected;

if (as_MStruct->cv < as_MStruct->low_clamp)
	as_MStruct->cv = as_MStruct->low_clamp; 
if (as_MStruct->cv > 100.0)
	as_MStruct->cv = 100.0; 



as_MStruct->main_loop = 1;
as_MStruct->N_loops = 3;

a= SIG_SEL(as_MStruct, test_reg);

if (!as_MStruct->auto_man)
	as_MStruct->cv= M_SP;
*CV= as_MStruct->cv;

Act[0]= (as_MStruct->pid_struct[1].active && (as_MStruct->loop_selected==1) && (as_MStruct->pid_struct[1].err>=-0.01));
Act[1]= (as_MStruct->pid_struct[2].active && (as_MStruct->loop_selected==2) && (as_MStruct->pid_struct[2].err>=-0.01));
Act[2]= as_MStruct->pid_struct[3].active && (as_MStruct->loop_selected==3) && (as_MStruct->pid_struct[3].err>=-1);
}


///***************************************************** AI_SPEED **********************************************************
//�������� AI �� �������� ��������� �������
void AI_SPEED(/*�����*/float AI, float SpeedLim, short iFolt,
			/*������*/ float *OUT, float *MaxSpeed, short *oFolt, float *SpeedBuf,float *Temp)

{
float Speed;
short SpeedFlt= 0, Folt= 0;


//�������� �����
SpeedBuf[4] = SpeedBuf[3];
SpeedBuf[3] = SpeedBuf[2];
SpeedBuf[2] = SpeedBuf[1];
SpeedBuf[1] = SpeedBuf[0];
SpeedBuf[0] = AI;
	
	// ---------- �������� ��������� �������� ------------------------------

if (SpeedLim > 0.0)	{	
		
	// ��������� ������� �� 4�
	Speed = (( fabs(SpeedBuf[2] - SpeedBuf[0]) + fabs(SpeedBuf[3] - SpeedBuf[1])) / 4.0) / TSCAN;
	

	SpeedFlt = (Speed > SpeedLim);
	if (*MaxSpeed < Speed) {
		*MaxSpeed = Speed;
	}
}
Folt= SpeedFlt || iFolt;
*oFolt = TOF(Folt,5,Temp);	
if (*oFolt){
	AI = SpeedBuf[5];
}
else {
	SpeedBuf[5] = SpeedBuf[4];	
}

*OUT= AI;
}



