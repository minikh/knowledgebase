#include "math.h"     // математические функции
#include "PACRXPlc.h" //процедуры для контроллера
static float num[] = { 0.006, 0.011, 0.022, 0.044, 0.088, 0.176, 0.352, 0.703, 1.406, 2.813, 5.625, 11.25, 22.5, 45.0, 90.0, 180.0 };

short int int_my( double par )
{
	short int zn;
	zn = (short int)par;
	if( (( par - zn ) * 100000) >= 44445 )
	{
		zn++;
	}
	return zn;
}


//int GefMain( unsigned int *in, float *res)
int GefMain( unsigned int *in, float *out1, float *out2)
{
	int i;
	double an, pe;
	double x6, x5, x4, x3, x2, x1;

	//*res = 0;
	x1 = 0;
	for( i = 0; i < 16; i++)
	{
		if( *in>>i & 0x01 )
		{
			//*res += num[i];
			x1 += num[i];
		}
	}
	
	//обработка сигнала с датчика ДБСКТ
	//x1 = RF(999);
	if( x1 >= 0.0 && x1 < 320 )
	{
		x1 = x1/3.0;
	}
	else
	{
		x1 = (x1-360.0)/3.0;
	}

	x2 = x1*x1;
	x3 = x2*x1;
	x4 = x2*x2;
	x5 = x4*x1;
	x6 = x3*x3;
	an =	(-0.0000000000775716234064434)*x6 + 
			(0.0000000177727826726853)*x5 + 
			(-0.00000119224447024393)*x4 + 
			(-0.0000126231840450915)*x3 + 
			(0.00427493334764372)*x2 + 
			(0.377244245538523)*x1 + 
			(-44.9730241507935);
	if( an > 0.0 ) 
	{
		an = 0.0; 
	}
	if( an < -45.0 ) 
	{
		an = -45.0; 
	}
	an = (45.0/45.0)*an; 						 
	*out1 = an; 		

	//RI(1593)= int_my(an*100.0);			
	//RF(1599)= an; //запоминаем у нас
	
	pe = (((an)+45.0)/45.0)*100.0; 
	if( pe > 100.0 )
	{
		pe = 100.0;
	}
	if( pe < 0.0 )
	{
		pe = 0.0;
	}
	//RI(1597)= int_my(pe*100.0);
	*out2 = int_my(pe*100.0);
	
	return GEF_EXECUTION_OK;
}