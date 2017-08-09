//изменение 2012.06.27 09:01
//изменение 2012.07.12 09:57
//изменение 2012.07.17
//изменение 2012.09.27 17:20


//ver 3.5
///**************************** MASS ********************************************
void MASS (/*Входы*/ON,N,P_IN,P_OUT,T_IN,T_OUT,d_P,p_g,B,
			/*Константы*/Nnom,Q_min,KKN,
			/*Для наладки*/as_mass,
			/*Выходы*/R_c,Q_pr,Q,Ky,Ni,Ne,G,KPD)
short ON;
float N;
float P_IN; 	//кПа
float P_OUT;	//кПа
float T_IN;		//гр.С
float T_OUT;	//гр.С
float d_P;
float Nnom;
float Q_min;
float p_g;
float B;		//кПа
float KKN;
AS_MASS *as_mass;

float *R_c;
float *Q_pr;
float *Q;
float *Ky;
float *Ni;
float *Ne;
float *G;
float *KPD;
{

float B_,Pin,Pout,Tin,Tout,p_,R, Tsr, Psr, Zin, Zout, Zsr, p_N,k,mt;
float val,val1;
//Если расчет включен, то продолжаем

if (ON == 1)
	{
	//Барометрическое давление, (ks/cm2)
	//B_= B * 1.0332/760.0;
	B_= B * 0.010197;

	//Давление на входе в нагнетатель, (ks/cm2)
	Pin= (P_IN * 0.010197) + B_;
	if (Pin == 0.0) Pin= 0.0000001; 
	
	//Давление на выходе из нагнетателя, (ks/cm2)
	Pout= (P_OUT * 0.010197) + B_;
	if (Pout == 0.0) Pout= 0.0000001; 

	//Степень сжатия
	if (Pin != 0.0) 
		*R_c = Pout / Pin;	
	else
		*R_c = 1.0;
	
	if (*R_c <1.0) *R_c= 1.0;

	//Температура на входе в нагнетатель, (грK)
	Tin= T_IN+273.15;

	//Температура на выходе из нагнетателяь, (грK)
	Tout= T_OUT+273.15;
	
	//Относительная плотность газа по воздуху
	p_= p_g/1.205;

	//Газовая постоянная
	if (p_!= 0.0) 
		{
		R= 0.287/p_;	//кДж/кгК
		}
	else 
		{
		R= 1.0;
		}

	//Средняя температура
	Tsr= 0.5 * (Tin + Tout); 

	//Среднее давление
	Psr= 0.5 * (Pin + Pout);

	//Коэффициент сжимаемости
	Zin= 1.0 - (((Pin-6.0)*(0.00345*p_-0.000446)+0.015)*(1.3-0.0144*(Tin-283.15)));
	Zout= 1.0 - (((Pout-6.0)*(0.00345*p_-0.000446)+0.015)*(1.3-0.0144*(Tout-283.15)));
	Zsr= 0.5 * (Zin + Zout);
	
	//Температурный показатель политропы
	if (Pin!=0.0)
		{
		if (log10(Pout/Pin)>0.0) mt= log10(Tout/Tin) / log10(Pout/Pin);
		else mt= 0.001;
		}
	else mt= 0.001;
		

	//показатель псевдоизоэнтропы
	k= 4.16+0.0041*(Tsr-283.15)+3.93*(p_-0.55)+5.0*(mt-0.3);	
	
	//Плотность на входе в нагнетатель	
	if ((Zin * Tin * R) != 0.0) 
		{
		p_N = (Pin / 0.010197) / (Zin * Tin * R);
		}
	else 
		p_N= 1.0;
	
	if (p_N == 0.0) p_N= 0.0001; 

	//Производительность (м3/час)
	val= d_P*p_N;

	if (val1 >0.0) 
		*G = KKN * sqrt(val)/60.0;
		//*G = *Q * p_N/60;
	else *G = 0.0;
	
	if (p_N!=0.0) 
		*Q = *G * 60.0 / p_N;
	else *Q = 0.0;

		
	//Приведенная производительность (м3/час)	
	if (N != 0.0) 
		*Q_pr = *Q * (Nnom/N);
	else 
		*Q_pr= 0.0;
	
	//Запас по помпажу %
	if (Q_min != 0) 
		*Ky = 100 * (*Q_pr - Q_min) / Q_min;
	else 
		*Ky = 100 * (*Q_pr - Q_min);

	if (*Ky < -10.0)
		*Ky= -10.0;
	else if (*Ky > 10000.0)
		*Ky= 10000.0; 	

	//Мощность, потребляемая ЦБК, кВт
	*Ni = k*Zsr*R*(Tout-Tin)* *G;	

	//Эффективная мощность ЦБК, кВт
	*Ne = *Ni / 0.98;	


	//политропный КПД компрессора
	if ((k!= 0.0) && (mt!=0.0)) *KPD= 1.0/k/mt;
	else *KPD = 0.0;	

	} // if (ON_Calc == 1)
//Для наладки
as_mass->R_c= *R_c;	
as_mass->B_ = B_;
as_mass->Pin = Pin;
as_mass->Pout = Pout;
as_mass->Tin = Tin;
as_mass->Tout = Tout;
as_mass->p_ = p_;
as_mass->R = R;
as_mass->Tsr = Tsr;
as_mass->Psr = Psr;
as_mass->Zin = Zin;
as_mass->Zout = Zout;
as_mass->Zsr = Zsr;
as_mass->mt = mt;
as_mass->k = k;
as_mass->p_N = p_N;
as_mass->val = val;
as_mass->Q = *Q;
as_mass->G = *G;
as_mass->Q_pr = *Q_pr;
as_mass->Ky = *Ky;
as_mass->Ni = *Ni;
as_mass->Ne = *Ne;
as_mass->KPD = *KPD;	
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
//Характерайзер
float CHARAKT(float E, float *Array, float num)
{
int i,n,k;
float Out=0;
n= num*2-2;

//Если E < минимального значения
if (E <= Array[0])
	Out= Array[1];
//Если E > максимального значения
else if (E > Array[n])
	{
	k= n+1;
	//то присвоить максимальное значение
	Out= Array[k];
	}
else
	{
	//Сканируем массив
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
//Если скорость != 0, то начинаем изменение выхода
if (Speed != 0) 
	*Out+= Speed * TSCAN;
} 			

///***************************************************** LIM_SPEED_2_1 **********************************************************
void LIM_SPEED_2_1 (float in, float max, float min,float *Out)
{
float prir,maxzikl,minzikl;
//Если скорость != 0, то начинаем изменение выхода
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
// Апериодическое звено: OU=IN/(1+TS)
// TS задано в сек.
// Вход (IN) и Выход (OU) заданы в %
// Все задается в REAL
// Для правильного выполнения в %P37 должно быть вычислено время 
// сканирования программы в сек.
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
// Апериодическое звено: OU=IN/(1+TS)
// TS задано в сек.
// Вход (IN) и Выход (OU) заданы в %
// Все задается в REAL
// Для правильного выполнения в %P37 должно быть вычислено время 
// сканирования программы в сек.
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
// *Time текущее время таймера
// Ust уставка таймера
// EN запуск таймера
{
short out;
float On, EN1, Time;
Time = T[0];
On= T[1];
EN1= T[2];
//если таймер включен, то считаем
//if (EN) On=1;

if (EN && !EN1) 
	On = 1;

if (On)
	{
	//Если текущее время меньше уставки, то
	if (Time < Ust) 
		{
		//выход таймера в 0
		out= 1;
		//увеличить текущее время на время скана
		Time += TSCAN;
		}
	//Если текущее время больше уставки, то выход таймера в 0
	else
		{
		out= 0;	
		Time= 0;
		On= 0;
		}
	}
//если таймер выключен, то 
else
	{
	//текущее время = 0
	Time = 0;
	//выход таймера = 0
	out = 0;
	}
T[0] = Time;
T[1] = On;
T[2] = EN;
return out;
}

///******************************************* Timer TON1 ***************************************************
//	Таймер 
// *Time текущее время таймера
// Ust уставка таймера
// EN запуск таймера
short TON1(short EN, float Ust, float *Time)
{
short out;
//если таймер включен, то считаем
if (EN)
	{
	//Если текущее время меньше уставки, то
	if (*Time < Ust) 
		{
		//выход таймера в 0
		out= 0;
		//увеличить текущее время на время скана
		*Time += TSCAN;
		}
	//Если текущее время больше уставки, то выход таймера в 1
	else
		{
		out= 1;	
		}
	}
//если таймер выключен, то 
else
	{
	//выход таймера = 0
	*Time = 0;
	//текущее время = 0
	out = 0;
	}
return out;
}

///******************************************* Timer TOF ***************************************************
//	Таймер 
// *Time текущее время таймера
// Ust уставка таймера
// EN запуск таймера
short TOF(short EN, float Ust, float *Time)
{
short out;
short ON, EN1;
ON= Time[1];
EN1= Time[2];

//если таймер включен, то 
if (EN)
	{
	//текущее время = 0
	*Time = 0;
	//выход таймера = 0
	out = 1;
	ON= 0;
	}

//Если EN стал = 0, то начинаем счет
if (!EN != EN1)
	ON=1;

//считаем
if (ON)
	{
	//Если текущее время меньше уставки, то
	if (*Time < Ust) 
		{
		//выход таймера в 0
		out= 1;
		//увеличить текущее время на время скана
		*Time += TSCAN;
		}
	//Если текущее время больше уставки, то выход таймера в 1
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

/// *******************************************  алгритм POC ******************************************* 
//Определение скорости увеличения давления на нагненание
void  POC (PS, ON,OFF, IN, IN1, TS, IN_F, Usl_OF, SpeedUP_dP, SpeedUP_P_Ku,CV_RegSpeed,dP_max, 
			MA_AS, POC_P, Time, end_POC, CV_P,POC_P_On1,POC_P_var, Speed_TS)
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
float CV_RegSpeed;
float *dP_max;
short *MA_AS;
short *POC_P;
float *Time;
short *end_POC;
float *CV_P;
short *POC_P_On1;
float *POC_P_var;


{
float d_P;
short T_On,POC_P_On=0;
//Задерживаем сигнал
INT_R (IN, TS, IN1);

//Если алгоритм POC Ps, то инвертируем d_P
if (PS) d_P= *IN1 - IN; 	//разница
else d_P= IN - *IN1;		//разница

//максимальное значение
if (d_P> dP_max[0]) dP_max[0]= d_P;

if (!OFF && !IN_F && ON && (d_P>SpeedUP_dP)) 
	{
	if (d_P> dP_max[1]) dP_max[1]= d_P;
	//void LIM_SPEED_2_1 (float in, float max, float min,float *Out)
	LIM_SPEED_2_1(SpeedUP_P_Ku * (d_P-SpeedUP_dP), 0, -0.01, POC_P_var);
	*POC_P= 1;
	POC_P_On= 1;
	}
else POC_P_On= 0;

if (POC_P_On && !*POC_P_On1) *MA_AS= 0;
//Ограничение
if (*POC_P_var > 100) *POC_P_var= 100;
//Если регулятор дает сигнал на открытие и рабочая точка находится на линии регулирования, 
//то снять воздействие POC_Pd алгоритма
T_On= (*POC_P && !POC_P_On && (CV_RegSpeed >= 0) && Usl_OF);
*end_POC= TON1(T_On, 0.1, Time);
//Отключаем POC
if ((*POC_P && (*CV_P <=0)) || *MA_AS || !ON || *end_POC)
	*POC_P= 0;

//Когда выходим в право, то разрешаем снять POC_Pd воздействие
INT_R_ON (*POC_P && !POC_P_On, *POC_P_var, Speed_TS, CV_P);

if (!POC_P_On) *POC_P_var= -6;
if (*CV_P<0) *CV_P= 0;
else if (*CV_P>100) *CV_P= 100;

*POC_P_On1= POC_P_On;

}

///***************************************************** REG_PID_SEL **********************************************************
//Селектор
//REG_PID_SEL(PV,SP,PV_Scale,&Contur_ON,APR_MA,SP_M_Current,AS_Kp,AS_Ki,loLim,hiLim,&CV_Reg,&Act,as_MStruct);
void REG_PID_SEL(/*Входы*/PV, SP, PV_Scale, ON, APR_MA, M_SP, Kp, Ki, DB, loLim, hiLim,
				/*Выходы*/CV,Act,as_MStruct)

float *PV;
float *SP; 
float *PV_Scale;
short *ON; 
short APR_MA;
float M_SP;
float *Kp;
float *Ki;
float *DB;
float loLim;
float hiLim;
float *CV; 
short *Act; //Номер активного контура Act[3];
DSEL *as_MStruct;
{
T_INT16 test_reg[20];
float PV1, PV2, PV3, SP1, SP2, SP3,d_pd;
static float PD_prev;
int a;
//Нижний лимит
as_MStruct->low_clamp= loLim;
as_MStruct->high_clamp= hiLim;

//Ограничение PV1
if (PV[0]<0.0) PV[0]= 0.0;
else if (PV[0]>100.0) PV[0]= 100.0;
//Ограничение SP1
if (SP[0]<0.0) SP[1]= 0.0;
else if(SP[0]>100.0) SP[0]= 100.0;

//Ограничение PV2
if (PV[1]<PV_Scale[0]) PV[1]= PV_Scale[0];
else if (PV[1]>PV_Scale[1]) PV[1]= PV_Scale[1];
//Ограничение SP2
if (SP[1]<PV_Scale[0]) SP[1]= PV_Scale[0];
else if(SP[1]>PV_Scale[1]) SP[1]= PV_Scale[1];

//Ограничение PV3
if (PV[2]<PV_Scale[2]) PV[2]= PV_Scale[2];
else if(PV[2]>PV_Scale[3]) PV[2]= PV_Scale[3];
//Ограничение SP2
if (SP[2]<PV_Scale[2]) SP[2]= PV_Scale[2];
else if(SP[2]>PV_Scale[3]) SP[2]= PV_Scale[3];


///*******************************************************************************************
as_MStruct->auto_man= 1; //!APR_MA; ////******************

//Масштабировние
//float Mashtab (float In, float Isl, float Ish, float Osl, float Osh)
PV1= PV[0];
SP1= SP[0];
PV2= Mashtab (PV[1], PV_Scale[0], PV_Scale[1], 0.0, 100.0);
SP2= Mashtab (SP[1], PV_Scale[0], PV_Scale[1], 0.0, 100.0);
PV3= Mashtab (PV[2], PV_Scale[2], PV_Scale[3], 0.0, 100.0);
SP3= Mashtab (SP[2], PV_Scale[2], PV_Scale[3], 0.0, 100.0);

//Контур регулирования расхода (основной)
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
as_MStruct->pid_struct[1].DB = DB[0]; //0;//1.0;

//Контур ограничения давления газа на выходе нагнетателя (ограничение)
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
as_MStruct->pid_struct[2].DB = DB[1]; //0.1;

//Контур ограничения степени сжатия нагнетателя (ограничение)
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
as_MStruct->pid_struct[3].DB = DB[2];  //0.0;


d_pd = as_MStruct->PplusD_selected - PD_prev;

if (as_MStruct->dI_selected < -0.5*TSCAN)
	as_MStruct->dI_selected = -0.5*TSCAN;
if ((d_pd + as_MStruct->dI_selected) < -0.5*TSCAN)
	d_pd = -0.5*TSCAN - as_MStruct->dI_selected; 


PD_prev = PD_prev + d_pd;

as_MStruct->cv = as_MStruct->cv + d_pd + as_MStruct->dI_selected;

if (as_MStruct->cv < as_MStruct->low_clamp)
	as_MStruct->cv = as_MStruct->low_clamp; 
/*if (as_MStruct->cv > 100.0)
	as_MStruct->cv = 100.0; */
if (as_MStruct->cv > as_MStruct->high_clamp)
	as_MStruct->cv = as_MStruct->high_clamp; 



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
//Контроль AI по скорости изменения сигнала
void AI_SPEED(/*Входы*/float AI, float SpeedLim, short iFolt,
			/*Выходы*/ float *OUT, float *MaxSpeed, short *oFolt, float *SpeedBuf,float *Temp)

{
float Speed;
short SpeedFlt= 0, Folt= 0;


//Набиваем буфер
SpeedBuf[4] = SpeedBuf[3];
SpeedBuf[3] = SpeedBuf[2];
SpeedBuf[2] = SpeedBuf[1];
SpeedBuf[1] = SpeedBuf[0];
SpeedBuf[0] = AI;
	
	// ---------- Скорость изменения значения ------------------------------

if (SpeedLim > 0.0)	{	
		
	// вычисляем среднюю из 4х
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



