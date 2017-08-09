///**************************** MASS ********************************************
void MASS (/*Входы*/ON_Calc,N,P_IN,P_OUT,T_IN,dP,p_g,B,
			/*Константы*/Nnom,Q_min,KKN,
			/*Выходы*/Rc,Q_pr,Q,Ky)
float ON_Calc;
float N;
float P_IN; 	//кгс/см2
float P_OUT;	//кгс/см2
float T_IN;	//гр.С
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
//Если расчет включен, то продолжаем
if (ON_Calc == 1)
	{
	//Степень сжатия
	if (P_IN != 0) 
		*Rc = P_OUT / P_IN;	
	else
		*Rc = 1;
	
	//Барометрическое давление, (ks/cm2)
	B_= B * 1.0332/760.0;

	//Давление на входе в нагнетатель, (ks/cm2)
	Pin= (P_IN * 0.010197) + B_;
	if (Pin == 0.0) Pin= 0.0000001; 

	//Температура на входе в нагнетатель, (грK)
	Tin= T_IN+273.2;

	//Относительная плотность газа
	p_= p_g/1.205;

	//Газовая постоянная
	if (p_!= 0.0) 
		R= 29.27/p_;
	else 
		R= 1;

	//Псевдокритическая температура
	Tkr= 162.8 * (0.613+p_);

	//Псевдокритическое давление
	Pkr= 47.9-p_;
	if (Pkr == 0.0) Pkr= 0.0001; 

	//Предельная температура
	if (Tkr != 0.0) 
		Tpr= Tin/Tkr;
	else 
		Tpr= 1;
	
	if (Tpr == 0.0) 
		Tpr= 0.01; 

	//Предельное давление
	Ppr= Pin/Pkr;
	if (Ppr == 0.0) Ppr= 0.0001; 


	//Коэффициент сжимаемости
	Zin= 1.0 - (((0.41 / (Tpr*Tpr*Tpr)) - (0.061/Tpr)) * Ppr)-(0.04 * (Tpr*Tpr)/(Tpr*Tpr*Tpr));	
		
	//Плотность на входе в нагнетатель	
	if (Zin * Tin * R != 0) 
		p_N = (Pin * 10000) / (Zin * Tin * R);
	else 
		p_N= 1;
	
	if (p_N == 0.0) p_N= 0.0001; 

	//Производительность (м3/час)
	float val = (13.6 * dP * 0.010197 * 735.0)/p_N;
	

	if (val >0) 
		*Q = KKN * sqrtf(val);
	else *Q = 0;
		
	//Приведенная производительность (м3/час)	
	if (N != 0) 
		*Q_pr = *Q * (Nnom/N);
	else 
		*Q_pr= 0;
	
	//Запас по помпажу %
	if (Q_min != 0) 
		*Ky = 100 * (*Q_pr - Q_min) / Q_min;
	else 
		*Ky = 0;

	if (*Ky < -10.0)
		*Ky= -10.0;
	else if (*Ky > 200.0)
		*Ky= 200.0; 	


	} // if (ON_Calc == 1)
//Если расчет выключен, то возвращаем нулевые значения
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
//Функция линейно - кусочной зависимости графика
float SurgeLineSet(float E, float *Array, float num)
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
// Апериодическое звено: OU=IN/(1+TS)
// TS задано в сек.
// Вход (IN) и Выход (OU) заданы в %
// Все задается в REAL
// Для правильного выполнения в %P37 должно быть вычислено время 
// сканирования программы в сек.
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
// *Time текущее время таймера
// Ust уставка таймера
// EN запуск таймера
{
short out;
//если таймер включен, то считаем
if (EN) T[0]=1;

if (EN && (EN != T[1])) 
	T[0] = 0;

if (T[0])
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
		T[0]= 0;
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
T[1] = EN;
return out;
}