#include "math.h"     // �������������� �������
//#include "PACRXPlc.h" //��������� ��� ����������� PAC
#include "plcc9070.h" //��������� ��� ����������� 90-70

#include "init.h"  //�������������



int syst_char(T_REAL32 X, T_REAL32 *Xn, T_REAL32 *Yn, T_INT16 number, T_INT16 Xtype, T_REAL32 *Y)
{
int num, fault;

 fault=0;
if (number<1 || number>16)  fault=1; 

num=number-1;
if (Xtype==1) 
		{
		if (X <= Xn[0]) *Y=Yn[0]; 
		if (X >= Xn[num])  *Y=Yn[num]; 
		}
else
		{
		if (X >= Xn[0]) *Y=Yn[0]; 
		if (X <= Xn[num])  *Y=Yn[num]; 
		}


switch (number) 
{
case 1: 
	*Y=Yn[0]; break;
case 2: 
	if (Xn[1] != Xn[0]) 
		*Y=(X-Xn[0])*(Yn[1]-Yn[0])/(Xn[1]-Xn[0])+Yn[0]; 
	else  fault=1; 
	break;
	
case 3: 
	if ((Xn[1] != Xn[0]) && (Xn[2] != Xn[1]) )
			{
			if (Xtype==1) 
					{
					if ((X>Xn[0]) && (X<=Xn[1])) *Y=(X-Xn[0])*(Yn[1]-Yn[0])/(Xn[1]-Xn[0])+Yn[0]; 
 					if ((X>Xn[1]) && (X<Xn[2]))  *Y=(X-Xn[1])*(Yn[2]-Yn[1])/(Xn[2]-Xn[1])+Yn[1]; 
					}
 			else
					{
 					if ((X<Xn[0]) && (X>=Xn[1])) *Y=(X-Xn[0])*(Yn[1]-Yn[0])/(Xn[1]-Xn[0])+Yn[0]; 
 					if ((X<Xn[1]) && (X>Xn[2]))  *Y=(X-Xn[1])*(Yn[2]-Yn[1])/(Xn[2]-Xn[1])+Yn[1]; 
					}
 			}
	else fault=1;
	break;
		
case 4: 
	if ((Xn[1] != Xn[0]) && (Xn[2] != Xn[1]) && (Xn[3] != Xn[2]))
			{
			if (Xtype==1)
					{
					if ((X>Xn[0]) && (X<=Xn[1])) *Y=(X-Xn[0])*(Yn[1]-Yn[0])/(Xn[1]-Xn[0])+Yn[0]; 
 					if ((X>Xn[1]) && (X<=Xn[2])) *Y=(X-Xn[1])*(Yn[2]-Yn[1])/(Xn[2]-Xn[1])+Yn[1]; 
 					if ((X>Xn[2]) && (X<Xn[3]))  *Y=(X-Xn[2])*(Yn[3]-Yn[2])/(Xn[3]-Xn[2])+Yn[2]; 
					}
 			else
					{
 					if ((X<Xn[0]) && (X>=Xn[1])) *Y=(X-Xn[0])*(Yn[1]-Yn[0])/(Xn[1]-Xn[0])+Yn[0]; 
 					if ((X<Xn[1]) && (X>=Xn[2])) *Y=(X-Xn[1])*(Yn[2]-Yn[1])/(Xn[2]-Xn[1])+Yn[1]; 
 					if ((X<Xn[2]) && (X>Xn[3]))  *Y=(X-Xn[2])*(Yn[3]-Yn[2])/(Xn[3]-Xn[2])+Yn[2]; 
					}
 			}
	else fault=1;
	break;
		
case 5: 
	if ((Xn[1] != Xn[0]) && (Xn[2] != Xn[1]) && (Xn[3] != Xn[2]) && (Xn[4] != Xn[3]))
			{
			if (Xtype==1)
					{  
					if ((X>Xn[0]) && (X<=Xn[1])) *Y=(X-Xn[0])*(Yn[1]-Yn[0])/(Xn[1]-Xn[0])+Yn[0]; 
 					if ((X>Xn[1]) && (X<=Xn[2])) *Y=(X-Xn[1])*(Yn[2]-Yn[1])/(Xn[2]-Xn[1])+Yn[1]; 
 					if ((X>Xn[2]) && (X<=Xn[3])) *Y=(X-Xn[2])*(Yn[3]-Yn[2])/(Xn[3]-Xn[2])+Yn[2]; 
 					if ((X>Xn[3]) && (X<Xn[4]))  *Y=(X-Xn[3])*(Yn[4]-Yn[3])/(Xn[4]-Xn[3])+Yn[3]; 
					}
 			else
					{
 					if ((X<Xn[0]) && (X>=Xn[1])) *Y=(X-Xn[0])*(Yn[1]-Yn[0])/(Xn[1]-Xn[0])+Yn[0]; 
 					if ((X<Xn[1]) && (X>=Xn[2])) *Y=(X-Xn[1])*(Yn[2]-Yn[1])/(Xn[2]-Xn[1])+Yn[1]; 
 					if ((X<Xn[2]) && (X>=Xn[3])) *Y=(X-Xn[2])*(Yn[3]-Yn[2])/(Xn[3]-Xn[2])+Yn[2]; 
 					if ((X<Xn[3]) && (X>Xn[4]))  *Y=(X-Xn[3])*(Yn[4]-Yn[3])/(Xn[4]-Xn[3])+Yn[3]; 
					}
 			}
	else fault=1;
	break;
		
case 6: 
	if ((Xn[1] != Xn[0]) && (Xn[2] != Xn[1]) && (Xn[3] != Xn[2]) && (Xn[4] != Xn[3]) && (Xn[5] != Xn[4]))
			{
			if (Xtype==1)
					{ 
					if ((X>Xn[0]) && (X<=Xn[1])) *Y=(X-Xn[0])*(Yn[1]-Yn[0])/(Xn[1]-Xn[0])+Yn[0]; 
 					if ((X>Xn[1]) && (X<=Xn[2])) *Y=(X-Xn[1])*(Yn[2]-Yn[1])/(Xn[2]-Xn[1])+Yn[1]; 
 					if ((X>Xn[2]) && (X<=Xn[3])) *Y=(X-Xn[2])*(Yn[3]-Yn[2])/(Xn[3]-Xn[2])+Yn[2]; 
 					if ((X>Xn[3]) && (X<=Xn[4])) *Y=(X-Xn[3])*(Yn[4]-Yn[3])/(Xn[4]-Xn[3])+Yn[3]; 
 					if ((X>Xn[4]) && (X<Xn[5]))  *Y=(X-Xn[4])*(Yn[5]-Yn[4])/(Xn[5]-Xn[4])+Yn[4]; 
					}
 			else
 					{
					if ((X<Xn[0]) && (X>=Xn[1])) *Y=(X-Xn[0])*(Yn[1]-Yn[0])/(Xn[1]-Xn[0])+Yn[0]; 
 					if ((X<Xn[1]) && (X>=Xn[2])) *Y=(X-Xn[1])*(Yn[2]-Yn[1])/(Xn[2]-Xn[1])+Yn[1]; 
 					if ((X<Xn[2]) && (X>=Xn[3])) *Y=(X-Xn[2])*(Yn[3]-Yn[2])/(Xn[3]-Xn[2])+Yn[2]; 
 					if ((X<Xn[3]) && (X>=Xn[4])) *Y=(X-Xn[3])*(Yn[4]-Yn[3])/(Xn[4]-Xn[3])+Yn[3]; 
 					if ((X<Xn[4]) && (X>Xn[5]))  *Y=(X-Xn[4])*(Yn[5]-Yn[4])/(Xn[5]-Xn[4])+Yn[4]; 
					}
 			}
	else fault=1;
	break;
		
case 7: 
	if ((Xn[1] != Xn[0]) && (Xn[2] != Xn[1]) && (Xn[3] != Xn[2]) && (Xn[4] != Xn[3]) && (Xn[5] != Xn[4]) && (Xn[6] != Xn[5]))
			{
			if (Xtype==1)
					{
					if ((X>Xn[0]) && (X<=Xn[1])) *Y=(X-Xn[0])*(Yn[1]-Yn[0])/(Xn[1]-Xn[0])+Yn[0]; 
 					if ((X>Xn[1]) && (X<=Xn[2])) *Y=(X-Xn[1])*(Yn[2]-Yn[1])/(Xn[2]-Xn[1])+Yn[1]; 
 					if ((X>Xn[2]) && (X<=Xn[3])) *Y=(X-Xn[2])*(Yn[3]-Yn[2])/(Xn[3]-Xn[2])+Yn[2]; 
 					if ((X>Xn[3]) && (X<=Xn[4])) *Y=(X-Xn[3])*(Yn[4]-Yn[3])/(Xn[4]-Xn[3])+Yn[3]; 
 					if ((X>Xn[4]) && (X<=Xn[5])) *Y=(X-Xn[4])*(Yn[5]-Yn[4])/(Xn[5]-Xn[4])+Yn[4]; 
 					if ((X>Xn[5]) && (X<Xn[6]))  *Y=(X-Xn[5])*(Yn[6]-Yn[5])/(Xn[6]-Xn[5])+Yn[5]; 
					}
 			else
					{
 					if ((X<Xn[0]) && (X>=Xn[1])) *Y=(X-Xn[0])*(Yn[1]-Yn[0])/(Xn[1]-Xn[0])+Yn[0]; 
 					if ((X<Xn[1]) && (X>=Xn[2])) *Y=(X-Xn[1])*(Yn[2]-Yn[1])/(Xn[2]-Xn[1])+Yn[1]; 
 					if ((X<Xn[2]) && (X>=Xn[3])) *Y=(X-Xn[2])*(Yn[3]-Yn[2])/(Xn[3]-Xn[2])+Yn[2]; 
 					if ((X<Xn[3]) && (X>=Xn[4])) *Y=(X-Xn[3])*(Yn[4]-Yn[3])/(Xn[4]-Xn[3])+Yn[3]; 
 					if ((X<Xn[4]) && (X>=Xn[5])) *Y=(X-Xn[4])*(Yn[5]-Yn[4])/(Xn[5]-Xn[4])+Yn[4]; 
 					if ((X<Xn[5]) && (X>Xn[6]))  *Y=(X-Xn[5])*(Yn[6]-Yn[5])/(Xn[6]-Xn[5])+Yn[5]; 
					}
 			}
	else fault=1;
	break;
		
case 8: 
	if ((Xn[1] != Xn[0]) && (Xn[2] != Xn[1]) && (Xn[3] != Xn[2]) && (Xn[4] != Xn[3]) && (Xn[5] != Xn[4]) && (Xn[6] != Xn[5]) && (Xn[7] != Xn[6]))
			{
			if (Xtype==1)
					{
					if ((X>Xn[0]) && (X<=Xn[1]))   *Y=(X-Xn[0])*(Yn[1]-Yn[0])/(Xn[1]-Xn[0])+Yn[0]; 
 					if ((X>Xn[1]) && (X<=Xn[2]))   *Y=(X-Xn[1])*(Yn[2]-Yn[1])/(Xn[2]-Xn[1])+Yn[1]; 
 					if ((X>Xn[2]) && (X<=Xn[3]))   *Y=(X-Xn[2])*(Yn[3]-Yn[2])/(Xn[3]-Xn[2])+Yn[2]; 
 					if ((X>Xn[3]) && (X<=Xn[4]))   *Y=(X-Xn[3])*(Yn[4]-Yn[3])/(Xn[4]-Xn[3])+Yn[3]; 
 					if ((X>Xn[4]) && (X<=Xn[5]))   *Y=(X-Xn[4])*(Yn[5]-Yn[4])/(Xn[5]-Xn[4])+Yn[4]; 
 					if ((X>Xn[5]) && (X<=Xn[6]))   *Y=(X-Xn[5])*(Yn[6]-Yn[5])/(Xn[6]-Xn[5])+Yn[5]; 
 					if ((X>Xn[6]) && (X<=Xn[7]))   *Y=(X-Xn[6])*(Yn[7]-Yn[6])/(Xn[7]-Xn[6])+Yn[6]; 
					}
 			else
					{
 					if ((X<Xn[0]) && (X>=Xn[1]))   *Y=(X-Xn[0])*(Yn[1]-Yn[0])/(Xn[1]-Xn[0])+Yn[0]; 
 					if ((X<Xn[1]) && (X>=Xn[2]))   *Y=(X-Xn[1])*(Yn[2]-Yn[1])/(Xn[2]-Xn[1])+Yn[1]; 
 					if ((X<Xn[2]) && (X>=Xn[3]))   *Y=(X-Xn[2])*(Yn[3]-Yn[2])/(Xn[3]-Xn[2])+Yn[2]; 
 					if ((X<Xn[3]) && (X>=Xn[4]))   *Y=(X-Xn[3])*(Yn[4]-Yn[3])/(Xn[4]-Xn[3])+Yn[3]; 
 					if ((X<Xn[4]) && (X>=Xn[5]))   *Y=(X-Xn[4])*(Yn[5]-Yn[4])/(Xn[5]-Xn[4])+Yn[4]; 
 					if ((X<Xn[5]) && (X>=Xn[6]))   *Y=(X-Xn[5])*(Yn[6]-Yn[5])/(Xn[6]-Xn[5])+Yn[5]; 
 					if ((X<Xn[6]) && (X>=Xn[7]))   *Y=(X-Xn[6])*(Yn[7]-Yn[6])/(Xn[7]-Xn[6])+Yn[6]; 
					}
 			}
	else fault=1;
	break;
	
case 9: 
	if ((Xn[1] != Xn[0]) && (Xn[2] != Xn[1]) && (Xn[3] != Xn[2]) && (Xn[4] != Xn[3]) && (Xn[5] != Xn[4]) && (Xn[6] != Xn[5]) && (Xn[7] != Xn[6]) && (Xn[8] != Xn[7]))
			{
			if (Xtype==1)
					{
					if ((X>Xn[0]) && (X<=Xn[1]))   *Y=(X-Xn[0])*(Yn[1]-Yn[0])/(Xn[1]-Xn[0])+Yn[0]; 
 					if ((X>Xn[1]) && (X<=Xn[2]))   *Y=(X-Xn[1])*(Yn[2]-Yn[1])/(Xn[2]-Xn[1])+Yn[1]; 
 					if ((X>Xn[2]) && (X<=Xn[3]))   *Y=(X-Xn[2])*(Yn[3]-Yn[2])/(Xn[3]-Xn[2])+Yn[2]; 
 					if ((X>Xn[3]) && (X<=Xn[4]))   *Y=(X-Xn[3])*(Yn[4]-Yn[3])/(Xn[4]-Xn[3])+Yn[3]; 
 					if ((X>Xn[4]) && (X<=Xn[5]))   *Y=(X-Xn[4])*(Yn[5]-Yn[4])/(Xn[5]-Xn[4])+Yn[4]; 
 					if ((X>Xn[5]) && (X<=Xn[6]))   *Y=(X-Xn[5])*(Yn[6]-Yn[5])/(Xn[6]-Xn[5])+Yn[5]; 
 					if ((X>Xn[6]) && (X<=Xn[7]))   *Y=(X-Xn[6])*(Yn[7]-Yn[6])/(Xn[7]-Xn[6])+Yn[6]; 
 					if ((X>Xn[7]) && (X<=Xn[8]))   *Y=(X-Xn[7])*(Yn[8]-Yn[7])/(Xn[8]-Xn[7])+Yn[7]; 
					}
 			else
					{
 					if ((X<Xn[0]) && (X>=Xn[1]))   *Y=(X-Xn[0])*(Yn[1]-Yn[0])/(Xn[1]-Xn[0])+Yn[0]; 
 					if ((X<Xn[1]) && (X>=Xn[2]))   *Y=(X-Xn[1])*(Yn[2]-Yn[1])/(Xn[2]-Xn[1])+Yn[1]; 
 					if ((X<Xn[2]) && (X>=Xn[3]))   *Y=(X-Xn[2])*(Yn[3]-Yn[2])/(Xn[3]-Xn[2])+Yn[2]; 
 					if ((X<Xn[3]) && (X>=Xn[4]))   *Y=(X-Xn[3])*(Yn[4]-Yn[3])/(Xn[4]-Xn[3])+Yn[3]; 
 					if ((X<Xn[4]) && (X>=Xn[5]))   *Y=(X-Xn[4])*(Yn[5]-Yn[4])/(Xn[5]-Xn[4])+Yn[4]; 
 					if ((X<Xn[5]) && (X>=Xn[6]))   *Y=(X-Xn[5])*(Yn[6]-Yn[5])/(Xn[6]-Xn[5])+Yn[5]; 
 					if ((X<Xn[6]) && (X>=Xn[7]))   *Y=(X-Xn[6])*(Yn[7]-Yn[6])/(Xn[7]-Xn[6])+Yn[6]; 
 					if ((X<Xn[7]) && (X>=Xn[8]))   *Y=(X-Xn[7])*(Yn[8]-Yn[7])/(Xn[8]-Xn[7])+Yn[7]; 
					}
 			}
	else fault=1;
	break;
	
case 10: 
	if ((Xn[1] != Xn[0]) && (Xn[2] != Xn[1]) && (Xn[3] != Xn[2]) && (Xn[4] != Xn[3]) && (Xn[5] != Xn[4]) && (Xn[6] != Xn[5]) && (Xn[7] != Xn[6]) && (Xn[8] != Xn[7]) && (Xn[9] != Xn[8]))
			{
			if (Xtype==1)
					{
					if ((X>Xn[0]) && (X<=Xn[1]))   *Y=(X-Xn[0])*(Yn[1]-Yn[0])/(Xn[1]-Xn[0])+Yn[0]; 
 					if ((X>Xn[1]) && (X<=Xn[2]))   *Y=(X-Xn[1])*(Yn[2]-Yn[1])/(Xn[2]-Xn[1])+Yn[1]; 
 					if ((X>Xn[2]) && (X<=Xn[3]))   *Y=(X-Xn[2])*(Yn[3]-Yn[2])/(Xn[3]-Xn[2])+Yn[2]; 
 					if ((X>Xn[3]) && (X<=Xn[4]))   *Y=(X-Xn[3])*(Yn[4]-Yn[3])/(Xn[4]-Xn[3])+Yn[3]; 
 					if ((X>Xn[4]) && (X<=Xn[5]))   *Y=(X-Xn[4])*(Yn[5]-Yn[4])/(Xn[5]-Xn[4])+Yn[4]; 
 					if ((X>Xn[5]) && (X<=Xn[6]))   *Y=(X-Xn[5])*(Yn[6]-Yn[5])/(Xn[6]-Xn[5])+Yn[5]; 
 					if ((X>Xn[6]) && (X<=Xn[7]))   *Y=(X-Xn[6])*(Yn[7]-Yn[6])/(Xn[7]-Xn[6])+Yn[6]; 
 					if ((X>Xn[7]) && (X<=Xn[8]))   *Y=(X-Xn[7])*(Yn[8]-Yn[7])/(Xn[8]-Xn[7])+Yn[7]; 
 					if ((X>Xn[8]) && (X<=Xn[9]))   *Y=(X-Xn[8])*(Yn[9]-Yn[8])/(Xn[9]-Xn[8])+Yn[8]; 
					}
 			else
					{
 					if ((X<Xn[0]) && (X>=Xn[1]))   *Y=(X-Xn[0])*(Yn[1]-Yn[0])/(Xn[1]-Xn[0])+Yn[0]; 
 					if ((X<Xn[1]) && (X>=Xn[2]))   *Y=(X-Xn[1])*(Yn[2]-Yn[1])/(Xn[2]-Xn[1])+Yn[1]; 
 					if ((X<Xn[2]) && (X>=Xn[3]))   *Y=(X-Xn[2])*(Yn[3]-Yn[2])/(Xn[3]-Xn[2])+Yn[2]; 
 					if ((X<Xn[3]) && (X>=Xn[4]))   *Y=(X-Xn[3])*(Yn[4]-Yn[3])/(Xn[4]-Xn[3])+Yn[3]; 
 					if ((X<Xn[4]) && (X>=Xn[5]))   *Y=(X-Xn[4])*(Yn[5]-Yn[4])/(Xn[5]-Xn[4])+Yn[4]; 
 					if ((X<Xn[5]) && (X>=Xn[6]))   *Y=(X-Xn[5])*(Yn[6]-Yn[5])/(Xn[6]-Xn[5])+Yn[5]; 
 					if ((X<Xn[6]) && (X>=Xn[7]))   *Y=(X-Xn[6])*(Yn[7]-Yn[6])/(Xn[7]-Xn[6])+Yn[6]; 
 					if ((X<Xn[7]) && (X>=Xn[8]))   *Y=(X-Xn[7])*(Yn[8]-Yn[7])/(Xn[8]-Xn[7])+Yn[7]; 
 					if ((X<Xn[8]) && (X>=Xn[9]))   *Y=(X-Xn[8])*(Yn[9]-Yn[8])/(Xn[9]-Xn[8])+Yn[8]; 
					}
 			}
	else fault=1;
	break;
	
case 11: 
	if ((Xn[1] != Xn[0]) && (Xn[2] != Xn[1]) && (Xn[3] != Xn[2]) && (Xn[4] != Xn[3]) && (Xn[5] != Xn[4]) && (Xn[6] != Xn[5]) && (Xn[7] != Xn[6]) && (Xn[8] != Xn[7]) && (Xn[9] != Xn[8]) && (Xn[10] != Xn[9]))
			{
			if (Xtype==1)
					{
					if ((X>Xn[0]) && (X<=Xn[1]))   *Y=(X-Xn[0])*(Yn[1]-Yn[0])/(Xn[1]-Xn[0])+Yn[0]; 
 					if ((X>Xn[1]) && (X<=Xn[2]))   *Y=(X-Xn[1])*(Yn[2]-Yn[1])/(Xn[2]-Xn[1])+Yn[1]; 
 					if ((X>Xn[2]) && (X<=Xn[3]))   *Y=(X-Xn[2])*(Yn[3]-Yn[2])/(Xn[3]-Xn[2])+Yn[2]; 
 					if ((X>Xn[3]) && (X<=Xn[4]))   *Y=(X-Xn[3])*(Yn[4]-Yn[3])/(Xn[4]-Xn[3])+Yn[3]; 
 					if ((X>Xn[4]) && (X<=Xn[5]))   *Y=(X-Xn[4])*(Yn[5]-Yn[4])/(Xn[5]-Xn[4])+Yn[4]; 
 					if ((X>Xn[5]) && (X<=Xn[6]))   *Y=(X-Xn[5])*(Yn[6]-Yn[5])/(Xn[6]-Xn[5])+Yn[5]; 
 					if ((X>Xn[6]) && (X<=Xn[7]))   *Y=(X-Xn[6])*(Yn[7]-Yn[6])/(Xn[7]-Xn[6])+Yn[6]; 
 					if ((X>Xn[7]) && (X<=Xn[8]))   *Y=(X-Xn[7])*(Yn[8]-Yn[7])/(Xn[8]-Xn[7])+Yn[7]; 
 					if ((X>Xn[8]) && (X<=Xn[9]))   *Y=(X-Xn[8])*(Yn[9]-Yn[8])/(Xn[9]-Xn[8])+Yn[8]; 
 					if ((X>Xn[9]) && (X<=Xn[10]))  *Y=(X-Xn[9])*(Yn[10]-Yn[9])/(Xn[10]-Xn[9])+Yn[9]; 
					}
 			else
					{
 					if ((X<Xn[0]) && (X>=Xn[1]))   *Y=(X-Xn[0])*(Yn[1]-Yn[0])/(Xn[1]-Xn[0])+Yn[0]; 
 					if ((X<Xn[1]) && (X>=Xn[2]))   *Y=(X-Xn[1])*(Yn[2]-Yn[1])/(Xn[2]-Xn[1])+Yn[1]; 
 					if ((X<Xn[2]) && (X>=Xn[3]))   *Y=(X-Xn[2])*(Yn[3]-Yn[2])/(Xn[3]-Xn[2])+Yn[2]; 
 					if ((X<Xn[3]) && (X>=Xn[4]))   *Y=(X-Xn[3])*(Yn[4]-Yn[3])/(Xn[4]-Xn[3])+Yn[3]; 
 					if ((X<Xn[4]) && (X>=Xn[5]))   *Y=(X-Xn[4])*(Yn[5]-Yn[4])/(Xn[5]-Xn[4])+Yn[4]; 
 					if ((X<Xn[5]) && (X>=Xn[6]))   *Y=(X-Xn[5])*(Yn[6]-Yn[5])/(Xn[6]-Xn[5])+Yn[5]; 
 					if ((X<Xn[6]) && (X>=Xn[7]))   *Y=(X-Xn[6])*(Yn[7]-Yn[6])/(Xn[7]-Xn[6])+Yn[6]; 
 					if ((X<Xn[7]) && (X>=Xn[8]))   *Y=(X-Xn[7])*(Yn[8]-Yn[7])/(Xn[8]-Xn[7])+Yn[7]; 
 					if ((X<Xn[8]) && (X>=Xn[9]))   *Y=(X-Xn[8])*(Yn[9]-Yn[8])/(Xn[9]-Xn[8])+Yn[8]; 
 					if ((X<Xn[9]) && (X>=Xn[10]))  *Y=(X-Xn[9])*(Yn[10]-Yn[9])/(Xn[10]-Xn[9])+Yn[9]; 
					}
 			}
	else fault=1;
	break;
	
case 12: 
	if ((Xn[1] != Xn[0]) && (Xn[2] != Xn[1]) && (Xn[3] != Xn[2]) && (Xn[4] != Xn[3]) && (Xn[5] != Xn[4]) && (Xn[6] != Xn[5]) && (Xn[7] != Xn[6]) && (Xn[8] != Xn[7]) && (Xn[9] != Xn[8]) && (Xn[10] != Xn[9]) && (Xn[11] != Xn[10]))
			{
			if (Xtype==1)
					{
					if ((X>Xn[0]) && (X<=Xn[1]))   *Y=(X-Xn[0])*(Yn[1]-Yn[0])/(Xn[1]-Xn[0])+Yn[0]; 
 					if ((X>Xn[1]) && (X<=Xn[2]))   *Y=(X-Xn[1])*(Yn[2]-Yn[1])/(Xn[2]-Xn[1])+Yn[1]; 
 					if ((X>Xn[2]) && (X<=Xn[3]))   *Y=(X-Xn[2])*(Yn[3]-Yn[2])/(Xn[3]-Xn[2])+Yn[2]; 
 					if ((X>Xn[3]) && (X<=Xn[4]))   *Y=(X-Xn[3])*(Yn[4]-Yn[3])/(Xn[4]-Xn[3])+Yn[3]; 
 					if ((X>Xn[4]) && (X<=Xn[5]))   *Y=(X-Xn[4])*(Yn[5]-Yn[4])/(Xn[5]-Xn[4])+Yn[4]; 
 					if ((X>Xn[5]) && (X<=Xn[6]))   *Y=(X-Xn[5])*(Yn[6]-Yn[5])/(Xn[6]-Xn[5])+Yn[5]; 
 					if ((X>Xn[6]) && (X<=Xn[7]))   *Y=(X-Xn[6])*(Yn[7]-Yn[6])/(Xn[7]-Xn[6])+Yn[6]; 
 					if ((X>Xn[7]) && (X<=Xn[8]))   *Y=(X-Xn[7])*(Yn[8]-Yn[7])/(Xn[8]-Xn[7])+Yn[7]; 
 					if ((X>Xn[8]) && (X<=Xn[9]))   *Y=(X-Xn[8])*(Yn[9]-Yn[8])/(Xn[9]-Xn[8])+Yn[8]; 
 					if ((X>Xn[9]) && (X<=Xn[10]))  *Y=(X-Xn[9])*(Yn[10]-Yn[9])/(Xn[10]-Xn[9])+Yn[9]; 
 					if ((X>Xn[10]) && (X<=Xn[11])) *Y=(X-Xn[10])*(Yn[11]-Yn[10])/(Xn[11]-Xn[10])+Yn[10]; 
					}
 			else
					{
 					if ((X<Xn[0]) && (X>=Xn[1]))   *Y=(X-Xn[0])*(Yn[1]-Yn[0])/(Xn[1]-Xn[0])+Yn[0]; 
 					if ((X<Xn[1]) && (X>=Xn[2]))   *Y=(X-Xn[1])*(Yn[2]-Yn[1])/(Xn[2]-Xn[1])+Yn[1]; 
 					if ((X<Xn[2]) && (X>=Xn[3]))   *Y=(X-Xn[2])*(Yn[3]-Yn[2])/(Xn[3]-Xn[2])+Yn[2]; 
 					if ((X<Xn[3]) && (X>=Xn[4]))   *Y=(X-Xn[3])*(Yn[4]-Yn[3])/(Xn[4]-Xn[3])+Yn[3]; 
 					if ((X<Xn[4]) && (X>=Xn[5]))   *Y=(X-Xn[4])*(Yn[5]-Yn[4])/(Xn[5]-Xn[4])+Yn[4]; 
 					if ((X<Xn[5]) && (X>=Xn[6]))   *Y=(X-Xn[5])*(Yn[6]-Yn[5])/(Xn[6]-Xn[5])+Yn[5]; 
 					if ((X<Xn[6]) && (X>=Xn[7]))   *Y=(X-Xn[6])*(Yn[7]-Yn[6])/(Xn[7]-Xn[6])+Yn[6]; 
 					if ((X<Xn[7]) && (X>=Xn[8]))   *Y=(X-Xn[7])*(Yn[8]-Yn[7])/(Xn[8]-Xn[7])+Yn[7]; 
 					if ((X<Xn[8]) && (X>=Xn[9]))   *Y=(X-Xn[8])*(Yn[9]-Yn[8])/(Xn[9]-Xn[8])+Yn[8]; 
 					if ((X<Xn[9]) && (X>=Xn[10]))  *Y=(X-Xn[9])*(Yn[10]-Yn[9])/(Xn[10]-Xn[9])+Yn[9]; 
 					if ((X<Xn[10]) && (X>=Xn[11])) *Y=(X-Xn[10])*(Yn[11]-Yn[10])/(Xn[11]-Xn[10])+Yn[10]; 
					}
 			}
	else fault=1;
	break;
	
case 13: 
	if ((Xn[1] != Xn[0]) && (Xn[2] != Xn[1]) && (Xn[3] != Xn[2]) && (Xn[4] != Xn[3]) && (Xn[5] != Xn[4]) && (Xn[6] != Xn[5]) && (Xn[7] != Xn[6]) && (Xn[8] != Xn[7]) && (Xn[9] != Xn[8]) && (Xn[10] != Xn[9]) && (Xn[11] != Xn[10]) && (Xn[12] != Xn[11]))
			{
			if (Xtype==1)
					{
					if ((X>Xn[0]) && (X<=Xn[1]))   *Y=(X-Xn[0])*(Yn[1]-Yn[0])/(Xn[1]-Xn[0])+Yn[0]; 
 					if ((X>Xn[1]) && (X<=Xn[2]))   *Y=(X-Xn[1])*(Yn[2]-Yn[1])/(Xn[2]-Xn[1])+Yn[1]; 
 					if ((X>Xn[2]) && (X<=Xn[3]))   *Y=(X-Xn[2])*(Yn[3]-Yn[2])/(Xn[3]-Xn[2])+Yn[2]; 
 					if ((X>Xn[3]) && (X<=Xn[4]))   *Y=(X-Xn[3])*(Yn[4]-Yn[3])/(Xn[4]-Xn[3])+Yn[3]; 
 					if ((X>Xn[4]) && (X<=Xn[5]))   *Y=(X-Xn[4])*(Yn[5]-Yn[4])/(Xn[5]-Xn[4])+Yn[4]; 
 					if ((X>Xn[5]) && (X<=Xn[6]))   *Y=(X-Xn[5])*(Yn[6]-Yn[5])/(Xn[6]-Xn[5])+Yn[5]; 
 					if ((X>Xn[6]) && (X<=Xn[7]))   *Y=(X-Xn[6])*(Yn[7]-Yn[6])/(Xn[7]-Xn[6])+Yn[6]; 
 					if ((X>Xn[7]) && (X<=Xn[8]))   *Y=(X-Xn[7])*(Yn[8]-Yn[7])/(Xn[8]-Xn[7])+Yn[7]; 
 					if ((X>Xn[8]) && (X<=Xn[9]))   *Y=(X-Xn[8])*(Yn[9]-Yn[8])/(Xn[9]-Xn[8])+Yn[8]; 
 					if ((X>Xn[9]) && (X<=Xn[10]))  *Y=(X-Xn[9])*(Yn[10]-Yn[9])/(Xn[10]-Xn[9])+Yn[9]; 
 					if ((X>Xn[10]) && (X<=Xn[11])) *Y=(X-Xn[10])*(Yn[11]-Yn[10])/(Xn[11]-Xn[10])+Yn[10]; 
 					if ((X>Xn[11]) && (X<=Xn[12])) *Y=(X-Xn[11])*(Yn[12]-Yn[11])/(Xn[12]-Xn[11])+Yn[11]; 
					}
 			else
					{
 					if ((X<Xn[0]) && (X>=Xn[1]))   *Y=(X-Xn[0])*(Yn[1]-Yn[0])/(Xn[1]-Xn[0])+Yn[0]; 
 					if ((X<Xn[1]) && (X>=Xn[2]))   *Y=(X-Xn[1])*(Yn[2]-Yn[1])/(Xn[2]-Xn[1])+Yn[1]; 
 					if ((X<Xn[2]) && (X>=Xn[3]))   *Y=(X-Xn[2])*(Yn[3]-Yn[2])/(Xn[3]-Xn[2])+Yn[2]; 
 					if ((X<Xn[3]) && (X>=Xn[4]))   *Y=(X-Xn[3])*(Yn[4]-Yn[3])/(Xn[4]-Xn[3])+Yn[3]; 
 					if ((X<Xn[4]) && (X>=Xn[5]))   *Y=(X-Xn[4])*(Yn[5]-Yn[4])/(Xn[5]-Xn[4])+Yn[4]; 
 					if ((X<Xn[5]) && (X>=Xn[6]))   *Y=(X-Xn[5])*(Yn[6]-Yn[5])/(Xn[6]-Xn[5])+Yn[5]; 
 					if ((X<Xn[6]) && (X>=Xn[7]))   *Y=(X-Xn[6])*(Yn[7]-Yn[6])/(Xn[7]-Xn[6])+Yn[6]; 
 					if ((X<Xn[7]) && (X>=Xn[8]))   *Y=(X-Xn[7])*(Yn[8]-Yn[7])/(Xn[8]-Xn[7])+Yn[7]; 
 					if ((X<Xn[8]) && (X>=Xn[9]))   *Y=(X-Xn[8])*(Yn[9]-Yn[8])/(Xn[9]-Xn[8])+Yn[8]; 
 					if ((X<Xn[9]) && (X>=Xn[10]))  *Y=(X-Xn[9])*(Yn[10]-Yn[9])/(Xn[10]-Xn[9])+Yn[9]; 
 					if ((X<Xn[10]) && (X>=Xn[11])) *Y=(X-Xn[10])*(Yn[11]-Yn[10])/(Xn[11]-Xn[10])+Yn[10]; 
 					if ((X<Xn[11]) && (X>=Xn[12])) *Y=(X-Xn[11])*(Yn[12]-Yn[11])/(Xn[12]-Xn[11])+Yn[11]; 
					}
 			}
	else fault=1;
	break;
			
case 14: 
	if ((Xn[1] != Xn[0]) && (Xn[2] != Xn[1]) && (Xn[3] != Xn[2]) && (Xn[4] != Xn[3]) && (Xn[5] != Xn[4]) && (Xn[6] != Xn[5]) && (Xn[7] != Xn[6]) && (Xn[8] != Xn[7]) && (Xn[9] != Xn[8]) && (Xn[10] != Xn[9]) && (Xn[11] != Xn[10]) && (Xn[12] != Xn[11]) && (Xn[13] != Xn[12]))
			{
			if (Xtype==1)
					{
					if ((X>Xn[0]) && (X<=Xn[1]))   *Y=(X-Xn[0])*(Yn[1]-Yn[0])/(Xn[1]-Xn[0])+Yn[0]; 
 					if ((X>Xn[1]) && (X<=Xn[2]))   *Y=(X-Xn[1])*(Yn[2]-Yn[1])/(Xn[2]-Xn[1])+Yn[1]; 
 					if ((X>Xn[2]) && (X<=Xn[3]))   *Y=(X-Xn[2])*(Yn[3]-Yn[2])/(Xn[3]-Xn[2])+Yn[2]; 
 					if ((X>Xn[3]) && (X<=Xn[4]))   *Y=(X-Xn[3])*(Yn[4]-Yn[3])/(Xn[4]-Xn[3])+Yn[3]; 
 					if ((X>Xn[4]) && (X<=Xn[5]))   *Y=(X-Xn[4])*(Yn[5]-Yn[4])/(Xn[5]-Xn[4])+Yn[4]; 
 					if ((X>Xn[5]) && (X<=Xn[6]))   *Y=(X-Xn[5])*(Yn[6]-Yn[5])/(Xn[6]-Xn[5])+Yn[5]; 
 					if ((X>Xn[6]) && (X<=Xn[7]))   *Y=(X-Xn[6])*(Yn[7]-Yn[6])/(Xn[7]-Xn[6])+Yn[6]; 
 					if ((X>Xn[7]) && (X<=Xn[8]))   *Y=(X-Xn[7])*(Yn[8]-Yn[7])/(Xn[8]-Xn[7])+Yn[7]; 
 					if ((X>Xn[8]) && (X<=Xn[9]))   *Y=(X-Xn[8])*(Yn[9]-Yn[8])/(Xn[9]-Xn[8])+Yn[8]; 
 					if ((X>Xn[9]) && (X<=Xn[10]))  *Y=(X-Xn[9])*(Yn[10]-Yn[9])/(Xn[10]-Xn[9])+Yn[9]; 
 					if ((X>Xn[10]) && (X<=Xn[11])) *Y=(X-Xn[10])*(Yn[11]-Yn[10])/(Xn[11]-Xn[10])+Yn[10]; 
 					if ((X>Xn[11]) && (X<=Xn[12])) *Y=(X-Xn[11])*(Yn[12]-Yn[11])/(Xn[12]-Xn[11])+Yn[11]; 
 					if ((X>Xn[12]) && (X<=Xn[13])) *Y=(X-Xn[12])*(Yn[13]-Yn[12])/(Xn[13]-Xn[12])+Yn[12]; 
					}
 			else
					{
 					if ((X<Xn[0]) && (X>=Xn[1]))   *Y=(X-Xn[0])*(Yn[1]-Yn[0])/(Xn[1]-Xn[0])+Yn[0]; 
 					if ((X<Xn[1]) && (X>=Xn[2]))   *Y=(X-Xn[1])*(Yn[2]-Yn[1])/(Xn[2]-Xn[1])+Yn[1]; 
 					if ((X<Xn[2]) && (X>=Xn[3]))   *Y=(X-Xn[2])*(Yn[3]-Yn[2])/(Xn[3]-Xn[2])+Yn[2]; 
 					if ((X<Xn[3]) && (X>=Xn[4]))   *Y=(X-Xn[3])*(Yn[4]-Yn[3])/(Xn[4]-Xn[3])+Yn[3]; 
 					if ((X<Xn[4]) && (X>=Xn[5]))   *Y=(X-Xn[4])*(Yn[5]-Yn[4])/(Xn[5]-Xn[4])+Yn[4]; 
 					if ((X<Xn[5]) && (X>=Xn[6]))   *Y=(X-Xn[5])*(Yn[6]-Yn[5])/(Xn[6]-Xn[5])+Yn[5]; 
 					if ((X<Xn[6]) && (X>=Xn[7]))   *Y=(X-Xn[6])*(Yn[7]-Yn[6])/(Xn[7]-Xn[6])+Yn[6]; 
 					if ((X<Xn[7]) && (X>=Xn[8]))   *Y=(X-Xn[7])*(Yn[8]-Yn[7])/(Xn[8]-Xn[7])+Yn[7]; 
 					if ((X<Xn[8]) && (X>=Xn[9]))   *Y=(X-Xn[8])*(Yn[9]-Yn[8])/(Xn[9]-Xn[8])+Yn[8]; 
 					if ((X<Xn[9]) && (X>=Xn[10]))  *Y=(X-Xn[9])*(Yn[10]-Yn[9])/(Xn[10]-Xn[9])+Yn[9]; 
 					if ((X<Xn[10]) && (X>=Xn[11])) *Y=(X-Xn[10])*(Yn[11]-Yn[10])/(Xn[11]-Xn[10])+Yn[10]; 
 					if ((X<Xn[11]) && (X>=Xn[12])) *Y=(X-Xn[11])*(Yn[12]-Yn[11])/(Xn[12]-Xn[11])+Yn[11]; 
 					if ((X<Xn[12]) && (X>=Xn[13])) *Y=(X-Xn[12])*(Yn[13]-Yn[12])/(Xn[13]-Xn[12])+Yn[12]; 
					}
 			}
	else fault=1;
	break;
		
case 15: 
	if ((Xn[1] != Xn[0]) && (Xn[2] != Xn[1]) && (Xn[3] != Xn[2]) && (Xn[4] != Xn[3]) && (Xn[5] != Xn[4]) && (Xn[6] != Xn[5]) && (Xn[7] != Xn[6]) && (Xn[8] != Xn[7]) && (Xn[9] != Xn[8]) && (Xn[10] != Xn[9]) && (Xn[11] != Xn[10]) && (Xn[12] != Xn[11]) && (Xn[13] != Xn[12]) && (Xn[14] != Xn[13]))
			{
			if (Xtype==1)
					{
					if ((X>Xn[0]) && (X<=Xn[1]))   *Y=(X-Xn[0])*(Yn[1]-Yn[0])/(Xn[1]-Xn[0])+Yn[0]; 
 					if ((X>Xn[1]) && (X<=Xn[2]))   *Y=(X-Xn[1])*(Yn[2]-Yn[1])/(Xn[2]-Xn[1])+Yn[1]; 
 					if ((X>Xn[2]) && (X<=Xn[3]))   *Y=(X-Xn[2])*(Yn[3]-Yn[2])/(Xn[3]-Xn[2])+Yn[2]; 
 					if ((X>Xn[3]) && (X<=Xn[4]))   *Y=(X-Xn[3])*(Yn[4]-Yn[3])/(Xn[4]-Xn[3])+Yn[3]; 
 					if ((X>Xn[4]) && (X<=Xn[5]))   *Y=(X-Xn[4])*(Yn[5]-Yn[4])/(Xn[5]-Xn[4])+Yn[4]; 
 					if ((X>Xn[5]) && (X<=Xn[6]))   *Y=(X-Xn[5])*(Yn[6]-Yn[5])/(Xn[6]-Xn[5])+Yn[5]; 
 					if ((X>Xn[6]) && (X<=Xn[7]))   *Y=(X-Xn[6])*(Yn[7]-Yn[6])/(Xn[7]-Xn[6])+Yn[6]; 
 					if ((X>Xn[7]) && (X<=Xn[8]))   *Y=(X-Xn[7])*(Yn[8]-Yn[7])/(Xn[8]-Xn[7])+Yn[7]; 
 					if ((X>Xn[8]) && (X<=Xn[9]))   *Y=(X-Xn[8])*(Yn[9]-Yn[8])/(Xn[9]-Xn[8])+Yn[8]; 
 					if ((X>Xn[9]) && (X<=Xn[10]))  *Y=(X-Xn[9])*(Yn[10]-Yn[9])/(Xn[10]-Xn[9])+Yn[9]; 
 					if ((X>Xn[10]) && (X<=Xn[11])) *Y=(X-Xn[10])*(Yn[11]-Yn[10])/(Xn[11]-Xn[10])+Yn[10]; 
 					if ((X>Xn[11]) && (X<=Xn[12])) *Y=(X-Xn[11])*(Yn[12]-Yn[11])/(Xn[12]-Xn[11])+Yn[11]; 
 					if ((X>Xn[12]) && (X<=Xn[13])) *Y=(X-Xn[12])*(Yn[13]-Yn[12])/(Xn[13]-Xn[12])+Yn[12]; 
 					if ((X>Xn[13]) && (X<=Xn[14])) *Y=(X-Xn[13])*(Yn[14]-Yn[13])/(Xn[14]-Xn[13])+Yn[13];
					}
 			else
					{
 					if ((X<Xn[0]) && (X>=Xn[1]))   *Y=(X-Xn[0])*(Yn[1]-Yn[0])/(Xn[1]-Xn[0])+Yn[0]; 
 					if ((X<Xn[1]) && (X>=Xn[2]))   *Y=(X-Xn[1])*(Yn[2]-Yn[1])/(Xn[2]-Xn[1])+Yn[1]; 
 					if ((X<Xn[2]) && (X>=Xn[3]))   *Y=(X-Xn[2])*(Yn[3]-Yn[2])/(Xn[3]-Xn[2])+Yn[2]; 
 					if ((X<Xn[3]) && (X>=Xn[4]))   *Y=(X-Xn[3])*(Yn[4]-Yn[3])/(Xn[4]-Xn[3])+Yn[3]; 
 					if ((X<Xn[4]) && (X>=Xn[5]))   *Y=(X-Xn[4])*(Yn[5]-Yn[4])/(Xn[5]-Xn[4])+Yn[4]; 
 					if ((X<Xn[5]) && (X>=Xn[6]))   *Y=(X-Xn[5])*(Yn[6]-Yn[5])/(Xn[6]-Xn[5])+Yn[5]; 
 					if ((X<Xn[6]) && (X>=Xn[7]))   *Y=(X-Xn[6])*(Yn[7]-Yn[6])/(Xn[7]-Xn[6])+Yn[6]; 
 					if ((X<Xn[7]) && (X>=Xn[8]))   *Y=(X-Xn[7])*(Yn[8]-Yn[7])/(Xn[8]-Xn[7])+Yn[7]; 
 					if ((X<Xn[8]) && (X>=Xn[9]))   *Y=(X-Xn[8])*(Yn[9]-Yn[8])/(Xn[9]-Xn[8])+Yn[8]; 
 					if ((X<Xn[9]) && (X>=Xn[10]))  *Y=(X-Xn[9])*(Yn[10]-Yn[9])/(Xn[10]-Xn[9])+Yn[9]; 
 					if ((X<Xn[10]) && (X>=Xn[11])) *Y=(X-Xn[10])*(Yn[11]-Yn[10])/(Xn[11]-Xn[10])+Yn[10]; 
 					if ((X<Xn[11]) && (X>=Xn[12])) *Y=(X-Xn[11])*(Yn[12]-Yn[11])/(Xn[12]-Xn[11])+Yn[11]; 
 					if ((X<Xn[12]) && (X>=Xn[13])) *Y=(X-Xn[12])*(Yn[13]-Yn[12])/(Xn[13]-Xn[12])+Yn[12]; 
 					if ((X<Xn[13]) && (X>=Xn[14])) *Y=(X-Xn[13])*(Yn[14]-Yn[13])/(Xn[14]-Xn[13])+Yn[13]; 
					}
 			}
	else fault=1;
	break;
		
		
case 16: 
	if ((Xn[1] != Xn[0]) && (Xn[2] != Xn[1]) && (Xn[3] != Xn[2]) && (Xn[4] != Xn[3]) && (Xn[5] != Xn[4]) && (Xn[6] != Xn[5]) && (Xn[7] != Xn[6]) && (Xn[8] != Xn[7]) && (Xn[9] != Xn[8]) && (Xn[10] != Xn[9]) && (Xn[11] != Xn[10]) && (Xn[12] != Xn[11]) && (Xn[13] != Xn[12]) && (Xn[14] != Xn[13]) && (Xn[15] != Xn[14]))
			{
			if (Xtype==1)
					{
					if ((X>Xn[0]) && (X<=Xn[1]))   *Y=(X-Xn[0])*(Yn[1]-Yn[0])/(Xn[1]-Xn[0])+Yn[0]; 
 					if ((X>Xn[1]) && (X<=Xn[2]))   *Y=(X-Xn[1])*(Yn[2]-Yn[1])/(Xn[2]-Xn[1])+Yn[1]; 
 					if ((X>Xn[2]) && (X<=Xn[3]))   *Y=(X-Xn[2])*(Yn[3]-Yn[2])/(Xn[3]-Xn[2])+Yn[2]; 
 					if ((X>Xn[3]) && (X<=Xn[4]))   *Y=(X-Xn[3])*(Yn[4]-Yn[3])/(Xn[4]-Xn[3])+Yn[3]; 
 					if ((X>Xn[4]) && (X<=Xn[5]))   *Y=(X-Xn[4])*(Yn[5]-Yn[4])/(Xn[5]-Xn[4])+Yn[4]; 
 					if ((X>Xn[5]) && (X<=Xn[6]))   *Y=(X-Xn[5])*(Yn[6]-Yn[5])/(Xn[6]-Xn[5])+Yn[5]; 
 					if ((X>Xn[6]) && (X<=Xn[7]))   *Y=(X-Xn[6])*(Yn[7]-Yn[6])/(Xn[7]-Xn[6])+Yn[6]; 
 					if ((X>Xn[7]) && (X<=Xn[8]))   *Y=(X-Xn[7])*(Yn[8]-Yn[7])/(Xn[8]-Xn[7])+Yn[7]; 
 					if ((X>Xn[8]) && (X<=Xn[9]))   *Y=(X-Xn[8])*(Yn[9]-Yn[8])/(Xn[9]-Xn[8])+Yn[8]; 
 					if ((X>Xn[9]) && (X<=Xn[10]))  *Y=(X-Xn[9])*(Yn[10]-Yn[9])/(Xn[10]-Xn[9])+Yn[9]; 
 					if ((X>Xn[10]) && (X<=Xn[11])) *Y=(X-Xn[10])*(Yn[11]-Yn[10])/(Xn[11]-Xn[10])+Yn[10]; 
 					if ((X>Xn[11]) && (X<=Xn[12])) *Y=(X-Xn[11])*(Yn[12]-Yn[11])/(Xn[12]-Xn[11])+Yn[11]; 
 					if ((X>Xn[12]) && (X<=Xn[13])) *Y=(X-Xn[12])*(Yn[13]-Yn[12])/(Xn[13]-Xn[12])+Yn[12]; 
 					if ((X>Xn[13]) && (X<=Xn[14])) *Y=(X-Xn[13])*(Yn[14]-Yn[13])/(Xn[14]-Xn[13])+Yn[13]; 
 					if ((X>Xn[14]) && (X<Xn[15]))  *Y=(X-Xn[14])*(Yn[15]-Yn[14])/(Xn[15]-Xn[14])+Yn[14]; 
					}
 			else
					{
 					if ((X<Xn[0]) && (X>=Xn[1]))   *Y=(X-Xn[0])*(Yn[1]-Yn[0])/(Xn[1]-Xn[0])+Yn[0]; 
 					if ((X<Xn[1]) && (X>=Xn[2]))   *Y=(X-Xn[1])*(Yn[2]-Yn[1])/(Xn[2]-Xn[1])+Yn[1]; 
 					if ((X<Xn[2]) && (X>=Xn[3]))   *Y=(X-Xn[2])*(Yn[3]-Yn[2])/(Xn[3]-Xn[2])+Yn[2]; 
 					if ((X<Xn[3]) && (X>=Xn[4]))   *Y=(X-Xn[3])*(Yn[4]-Yn[3])/(Xn[4]-Xn[3])+Yn[3]; 
 					if ((X<Xn[4]) && (X>=Xn[5]))   *Y=(X-Xn[4])*(Yn[5]-Yn[4])/(Xn[5]-Xn[4])+Yn[4]; 
 					if ((X<Xn[5]) && (X>=Xn[6]))   *Y=(X-Xn[5])*(Yn[6]-Yn[5])/(Xn[6]-Xn[5])+Yn[5]; 
 					if ((X<Xn[6]) && (X>=Xn[7]))   *Y=(X-Xn[6])*(Yn[7]-Yn[6])/(Xn[7]-Xn[6])+Yn[6]; 
 					if ((X<Xn[7]) && (X>=Xn[8]))   *Y=(X-Xn[7])*(Yn[8]-Yn[7])/(Xn[8]-Xn[7])+Yn[7]; 
 					if ((X<Xn[8]) && (X>=Xn[9]))   *Y=(X-Xn[8])*(Yn[9]-Yn[8])/(Xn[9]-Xn[8])+Yn[8]; 
 					if ((X<Xn[9]) && (X>=Xn[10]))  *Y=(X-Xn[9])*(Yn[10]-Yn[9])/(Xn[10]-Xn[9])+Yn[9]; 
 					if ((X<Xn[10]) && (X>=Xn[11])) *Y=(X-Xn[10])*(Yn[11]-Yn[10])/(Xn[11]-Xn[10])+Yn[10]; 
 					if ((X<Xn[11]) && (X>=Xn[12])) *Y=(X-Xn[11])*(Yn[12]-Yn[11])/(Xn[12]-Xn[11])+Yn[11]; 
 					if ((X<Xn[12]) && (X>=Xn[13])) *Y=(X-Xn[12])*(Yn[13]-Yn[12])/(Xn[13]-Xn[12])+Yn[12]; 
 					if ((X<Xn[13]) && (X>=Xn[14])) *Y=(X-Xn[13])*(Yn[14]-Yn[13])/(Xn[14]-Xn[13])+Yn[13]; 
 					if ((X<Xn[14]) && (X>Xn[15]))  *Y=(X-Xn[14])*(Yn[15]-Yn[14])/(Xn[15]-Xn[14])+Yn[14]; 
					}
 			}
	else fault=1;
	break;
		
} //switch

return fault;
}

// ****************************************************** main **********************************************************************************************


//void GefMain(/*�����*/T_REAL32 *N,T_REAL32 *Rc, T_REAL32 *Ps, T_REAL32 *Ts, /*������*/ T_REAL32 *Q_35ata, T_REAL32 *Q)
main(/*�����*/T_REAL32 *N,T_REAL32 *Rc, T_REAL32 *Ps, T_REAL32 *Ts, /*������*/ T_REAL32 *Q_35ata, T_REAL32 *Q) // ��� 90-70
{
//syst_char(Rc, *Xn, *Yn, number, Xtype, *Q_35ata,  *fault);   //syst_char(T_REAL32 X, T_REAL32 *Xn, T_REAL32 *Yn, T_INT16 number, T_INT16 Xtype, T_REAL32 *Y, T_REAL32  *fault)


T_REAL32 Xn[16];
T_REAL32 Yn[16];
T_INT16 number; 
T_INT16 Xtype;
T_INT16 fault;


if ((*N>=14000.0)&&(*N<15000.0))
	{
	Xtype=char14000_Xtype;
	number=char14000_number;
	Xn[0]=char14000_Xn[0]+(*N-14000.0)*0.00014642857;
	Xn[1]=char14000_Xn[1]+(*N-14000.0)*0.00014642857;
	Xn[2]=char14000_Xn[2]+(*N-14000.0)*0.00014642857;
	Xn[3]=char14000_Xn[3]+(*N-14000.0)*0.00014642857;
	Xn[4]=char14000_Xn[4]+(*N-14000.0)*0.00014642857;
	Xn[5]=char14000_Xn[5]+(*N-14000.0)*0.00014642857;
	Xn[6]=char14000_Xn[6]+(*N-14000.0)*0.00014642857;
	Xn[7]=char14000_Xn[7]+(*N-14000.0)*0.00014642857;
	Xn[8]=char14000_Xn[8]+(*N-14000.0)*0.00014642857;
	Xn[9]=char14000_Xn[9]+(*N-14000.0)*0.00014642857;
	Xn[10]=char14000_Xn[10]+(*N-14000.0)*0.00014642857;
	Xn[11]=char14000_Xn[11]+(*N-14000.0)*0.00014642857;
	Xn[12]=char14000_Xn[12]+(*N-14000.0)*0.00014642857;
	Xn[13]=char14000_Xn[13]+(*N-14000.0)*0.00014642857;
	Xn[14]=char14000_Xn[14]+(*N-14000.0)*0.00014642857;
	Xn[15]=char14000_Xn[15]+(*N-14000.0)*0.00014642857;

	Yn[0]=char14000_Yn[0];
	Yn[1]=char14000_Yn[1];
	Yn[2]=char14000_Yn[2];
	Yn[3]=char14000_Yn[3];
	Yn[4]=char14000_Yn[4];
	Yn[5]=char14000_Yn[5];
	Yn[6]=char14000_Yn[6];
	Yn[7]=char14000_Yn[7];
	Yn[8]=char14000_Yn[8];
	Yn[9]=char14000_Yn[9];
	Yn[10]=char14000_Yn[10];
	Yn[11]=char14000_Yn[11];
	Yn[12]=char14000_Yn[12];
	Yn[13]=char14000_Yn[13];
	Yn[14]=char14000_Yn[14];
	Yn[15]=char14000_Yn[15];
	}

if ((*N>=15000.0)&&(*N<16000.0))
	{
	Xtype=char15000_Xtype;
	number=char15000_number;
	Xn[0]=char15000_Xn[0]+(*N-15000.0)*0.00016428571;
	Xn[1]=char15000_Xn[1]+(*N-15000.0)*0.00016428571;
	Xn[2]=char15000_Xn[2]+(*N-15000.0)*0.00016428571;
	Xn[3]=char15000_Xn[3]+(*N-15000.0)*0.00016428571;
	Xn[4]=char15000_Xn[4]+(*N-15000.0)*0.00016428571;
	Xn[5]=char15000_Xn[5]+(*N-15000.0)*0.00016428571;
	Xn[6]=char15000_Xn[6]+(*N-15000.0)*0.00016428571;
	Xn[7]=char15000_Xn[7]+(*N-15000.0)*0.00016428571;
	Xn[8]=char15000_Xn[8]+(*N-15000.0)*0.00016428571;
	Xn[9]=char15000_Xn[9]+(*N-15000.0)*0.00016428571;
	Xn[10]=char15000_Xn[10]+(*N-15000.0)*0.00016428571;
	Xn[11]=char15000_Xn[11]+(*N-15000.0)*0.00016428571;
	Xn[12]=char15000_Xn[12]+(*N-15000.0)*0.00016428571;
	Xn[13]=char15000_Xn[13]+(*N-15000.0)*0.00016428571;
	Xn[14]=char15000_Xn[14]+(*N-15000.0)*0.00016428571;
	Xn[15]=char15000_Xn[15]+(*N-15000.0)*0.00016428571;

	Yn[0]=char15000_Yn[0];
	Yn[1]=char15000_Yn[1];
	Yn[2]=char15000_Yn[2];
	Yn[3]=char15000_Yn[3];
	Yn[4]=char15000_Yn[4];
	Yn[5]=char15000_Yn[5];
	Yn[6]=char15000_Yn[6];
	Yn[7]=char15000_Yn[7];
	Yn[8]=char15000_Yn[8];
	Yn[9]=char15000_Yn[9];
	Yn[10]=char15000_Yn[10];
	Yn[11]=char15000_Yn[11];
	Yn[12]=char15000_Yn[12];
	Yn[13]=char15000_Yn[13];
	Yn[14]=char15000_Yn[14];
	Yn[15]=char15000_Yn[15];
	}


if ((*N>=16000.0)&&(*N<17000.0))
	{
	Xtype=char16000_Xtype;
	number=char16000_number;
	Xn[0]=char16000_Xn[0]+(*N-16000.0)*0.00017142857;
	Xn[1]=char16000_Xn[1]+(*N-16000.0)*0.00017142857;
	Xn[2]=char16000_Xn[2]+(*N-16000.0)*0.00017142857;
	Xn[3]=char16000_Xn[3]+(*N-16000.0)*0.00017142857;
	Xn[4]=char16000_Xn[4]+(*N-16000.0)*0.00017142857;
	Xn[5]=char16000_Xn[5]+(*N-16000.0)*0.00017142857;
	Xn[6]=char16000_Xn[6]+(*N-16000.0)*0.00017142857;
	Xn[7]=char16000_Xn[7]+(*N-16000.0)*0.00017142857;
	Xn[8]=char16000_Xn[8]+(*N-16000.0)*0.00017142857;
	Xn[9]=char16000_Xn[9]+(*N-16000.0)*0.00017142857;
	Xn[10]=char16000_Xn[10]+(*N-16000.0)*0.00017142857;
	Xn[11]=char16000_Xn[11]+(*N-16000.0)*0.00017142857;
	Xn[12]=char16000_Xn[12]+(*N-16000.0)*0.00017142857;
	Xn[13]=char16000_Xn[13]+(*N-16000.0)*0.00017142857;
	Xn[14]=char16000_Xn[14]+(*N-16000.0)*0.00017142857;
	Xn[15]=char16000_Xn[15]+(*N-16000.0)*0.00017142857;

	Yn[0]=char16000_Yn[0];
	Yn[1]=char16000_Yn[1];
	Yn[2]=char16000_Yn[2];
	Yn[3]=char16000_Yn[3];
	Yn[4]=char16000_Yn[4];
	Yn[5]=char16000_Yn[5];
	Yn[6]=char16000_Yn[6];
	Yn[7]=char16000_Yn[7];
	Yn[8]=char16000_Yn[8];
	Yn[9]=char16000_Yn[9];
	Yn[10]=char16000_Yn[10];
	Yn[11]=char16000_Yn[11];
	Yn[12]=char16000_Yn[12];
	Yn[13]=char16000_Yn[13];
	Yn[14]=char16000_Yn[14];
	Yn[15]=char16000_Yn[15];
	}

if ((*N>=17000.0)&&(*N<18000.0))
	{
	Xtype=char17000_Xtype;
	number=char17000_number;
	Xn[0]=char17000_Xn[0]+(*N-17000.0)*0.00021071429;
	Xn[1]=char17000_Xn[1]+(*N-17000.0)*0.00021071429;
	Xn[2]=char17000_Xn[2]+(*N-17000.0)*0.00021071429;
	Xn[3]=char17000_Xn[3]+(*N-17000.0)*0.00021071429;
	Xn[4]=char17000_Xn[4]+(*N-17000.0)*0.00021071429;
	Xn[5]=char17000_Xn[5]+(*N-17000.0)*0.00021071429;
	Xn[6]=char17000_Xn[6]+(*N-17000.0)*0.00021071429;
	Xn[7]=char17000_Xn[7]+(*N-17000.0)*0.00021071429;
	Xn[8]=char17000_Xn[8]+(*N-17000.0)*0.00021071429;
	Xn[9]=char17000_Xn[9]+(*N-17000.0)*0.00021071429;
	Xn[10]=char17000_Xn[10]+(*N-17000.0)*0.00021071429;
	Xn[11]=char17000_Xn[11]+(*N-17000.0)*0.00021071429;
	Xn[12]=char17000_Xn[12]+(*N-17000.0)*0.00021071429;
	Xn[13]=char17000_Xn[13]+(*N-17000.0)*0.00021071429;
	Xn[14]=char17000_Xn[14]+(*N-17000.0)*0.00021071429;
	Xn[15]=char17000_Xn[15]+(*N-17000.0)*0.00021071429;

	Yn[0]=char17000_Yn[0];
	Yn[1]=char17000_Yn[1];
	Yn[2]=char17000_Yn[2];
	Yn[3]=char17000_Yn[3];
	Yn[4]=char17000_Yn[4];
	Yn[5]=char17000_Yn[5];
	Yn[6]=char17000_Yn[6];
	Yn[7]=char17000_Yn[7];
	Yn[8]=char17000_Yn[8];
	Yn[9]=char17000_Yn[9];
	Yn[10]=char17000_Yn[10];
	Yn[11]=char17000_Yn[11];
	Yn[12]=char17000_Yn[12];
	Yn[13]=char17000_Yn[13];
	Yn[14]=char17000_Yn[14];
	Yn[15]=char17000_Yn[15];
	}

if ((*N>=18000.0)&&(*N<19000.0))
	{
	Xtype=char18000_Xtype;
	number=char18000_number;
	Xn[0]=char18000_Xn[0]+(*N-18000.0)*0.00021071429;
	Xn[1]=char18000_Xn[1]+(*N-18000.0)*0.00021071429;
	Xn[2]=char18000_Xn[2]+(*N-18000.0)*0.00021071429;
	Xn[3]=char18000_Xn[3]+(*N-18000.0)*0.00021071429;
	Xn[4]=char18000_Xn[4]+(*N-18000.0)*0.00021071429;
	Xn[5]=char18000_Xn[5]+(*N-18000.0)*0.00021071429;
	Xn[6]=char18000_Xn[6]+(*N-18000.0)*0.00021071429;
	Xn[7]=char18000_Xn[7]+(*N-18000.0)*0.00021071429;
	Xn[8]=char18000_Xn[8]+(*N-18000.0)*0.00021071429;
	Xn[9]=char18000_Xn[9]+(*N-18000.0)*0.00021071429;
	Xn[10]=char18000_Xn[10]+(*N-18000.0)*0.00021071429;
	Xn[11]=char18000_Xn[11]+(*N-18000.0)*0.00021071429;
	Xn[12]=char18000_Xn[12]+(*N-18000.0)*0.00021071429;
	Xn[13]=char18000_Xn[13]+(*N-18000.0)*0.00021071429;
	Xn[14]=char18000_Xn[14]+(*N-18000.0)*0.00021071429;
	Xn[15]=char18000_Xn[15]+(*N-18000.0)*0.00021071429;

	Yn[0]=char18000_Yn[0];
	Yn[1]=char18000_Yn[1];
	Yn[2]=char18000_Yn[2];
	Yn[3]=char18000_Yn[3];
	Yn[4]=char18000_Yn[4];
	Yn[5]=char18000_Yn[5];
	Yn[6]=char18000_Yn[6];
	Yn[7]=char18000_Yn[7];
	Yn[8]=char18000_Yn[8];
	Yn[9]=char18000_Yn[9];
	Yn[10]=char18000_Yn[10];
	Yn[11]=char18000_Yn[11];
	Yn[12]=char18000_Yn[12];
	Yn[13]=char18000_Yn[13];
	Yn[14]=char18000_Yn[14];
	Yn[15]=char18000_Yn[15];
	}

if ((*N>=19000.0)&&(*N<20000.0))
	{
	Xtype=char19000_Xtype;
	number=char19000_number;
	Xn[0]=char19000_Xn[0]+(*N-19000.0)*0.00024285714;
	Xn[1]=char19000_Xn[1]+(*N-19000.0)*0.00024285714;
	Xn[2]=char19000_Xn[2]+(*N-19000.0)*0.00024285714;
	Xn[3]=char19000_Xn[3]+(*N-19000.0)*0.00024285714;
	Xn[4]=char19000_Xn[4]+(*N-19000.0)*0.00024285714;
	Xn[5]=char19000_Xn[5]+(*N-19000.0)*0.00024285714;
	Xn[6]=char19000_Xn[6]+(*N-19000.0)*0.00024285714;
	Xn[7]=char19000_Xn[7]+(*N-19000.0)*0.00024285714;
	Xn[8]=char19000_Xn[8]+(*N-19000.0)*0.00024285714;
	Xn[9]=char19000_Xn[9]+(*N-19000.0)*0.00024285714;
	Xn[10]=char19000_Xn[10]+(*N-19000.0)*0.00024285714;
	Xn[11]=char19000_Xn[11]+(*N-19000.0)*0.00024285714;
	Xn[12]=char19000_Xn[12]+(*N-19000.0)*0.00024285714;
	Xn[13]=char19000_Xn[13]+(*N-19000.0)*0.00024285714;
	Xn[14]=char19000_Xn[14]+(*N-19000.0)*0.00024285714;
	Xn[15]=char19000_Xn[15]+(*N-19000.0)*0.00024285714;

	Yn[0]=char19000_Yn[0];
	Yn[1]=char19000_Yn[1];
	Yn[2]=char19000_Yn[2];
	Yn[3]=char19000_Yn[3];
	Yn[4]=char19000_Yn[4];
	Yn[5]=char19000_Yn[5];
	Yn[6]=char19000_Yn[6];
	Yn[7]=char19000_Yn[7];
	Yn[8]=char19000_Yn[8];
	Yn[9]=char19000_Yn[9];
	Yn[10]=char19000_Yn[10];
	Yn[11]=char19000_Yn[11];
	Yn[12]=char19000_Yn[12];
	Yn[13]=char19000_Yn[13];
	Yn[14]=char19000_Yn[14];
	Yn[15]=char19000_Yn[15];
	}

if ((*N>=20000.0)&&(*N<21000.0))
	{
	Xtype=char20000_Xtype;
	number=char20000_number;
	Xn[0]=char20000_Xn[0]+(*N-20000.0)*0.00027142857;
	Xn[1]=char20000_Xn[1]+(*N-20000.0)*0.00027142857;
	Xn[2]=char20000_Xn[2]+(*N-20000.0)*0.00027142857;
	Xn[3]=char20000_Xn[3]+(*N-20000.0)*0.00027142857;
	Xn[4]=char20000_Xn[4]+(*N-20000.0)*0.00027142857;
	Xn[5]=char20000_Xn[5]+(*N-20000.0)*0.00027142857;
	Xn[6]=char20000_Xn[6]+(*N-20000.0)*0.00027142857;
	Xn[7]=char20000_Xn[7]+(*N-20000.0)*0.00027142857;
	Xn[8]=char20000_Xn[8]+(*N-20000.0)*0.00027142857;
	Xn[9]=char20000_Xn[9]+(*N-20000.0)*0.00027142857;
	Xn[10]=char20000_Xn[10]+(*N-20000.0)*0.00027142857;
	Xn[11]=char20000_Xn[11]+(*N-20000.0)*0.00027142857;
	Xn[12]=char20000_Xn[12]+(*N-20000.0)*0.00027142857;
	Xn[13]=char20000_Xn[13]+(*N-20000.0)*0.00027142857;
	Xn[14]=char20000_Xn[14]+(*N-20000.0)*0.00027142857;
	Xn[15]=char20000_Xn[15]+(*N-20000.0)*0.00027142857;

	Yn[0]=char20000_Yn[0];
	Yn[1]=char20000_Yn[1];
	Yn[2]=char20000_Yn[2];
	Yn[3]=char20000_Yn[3];
	Yn[4]=char20000_Yn[4];
	Yn[5]=char20000_Yn[5];
	Yn[6]=char20000_Yn[6];
	Yn[7]=char20000_Yn[7];
	Yn[8]=char20000_Yn[8];
	Yn[9]=char20000_Yn[9];
	Yn[10]=char20000_Yn[10];
	Yn[11]=char20000_Yn[11];
	Yn[12]=char20000_Yn[12];
	Yn[13]=char20000_Yn[13];
	Yn[14]=char20000_Yn[14];
	Yn[15]=char20000_Yn[15];
	}

if ((*N>=21000.0)&&(*N<22000.0))
	{
	Xtype=char21000_Xtype;
	number=char21000_number;
	Xn[0]=char21000_Xn[0]+(*N-21000.0)*0.00029285714;
	Xn[1]=char21000_Xn[1]+(*N-21000.0)*0.00029285714;
	Xn[2]=char21000_Xn[2]+(*N-21000.0)*0.00029285714;
	Xn[3]=char21000_Xn[3]+(*N-21000.0)*0.00029285714;
	Xn[4]=char21000_Xn[4]+(*N-21000.0)*0.00029285714;
	Xn[5]=char21000_Xn[5]+(*N-21000.0)*0.00029285714;
	Xn[6]=char21000_Xn[6]+(*N-21000.0)*0.00029285714;
	Xn[7]=char21000_Xn[7]+(*N-21000.0)*0.00029285714;
	Xn[8]=char21000_Xn[8]+(*N-21000.0)*0.00029285714;
	Xn[9]=char21000_Xn[9]+(*N-21000.0)*0.00029285714;
	Xn[10]=char21000_Xn[10]+(*N-21000.0)*0.00029285714;
	Xn[11]=char21000_Xn[11]+(*N-21000.0)*0.00029285714;
	Xn[12]=char21000_Xn[12]+(*N-21000.0)*0.00029285714;
	Xn[13]=char21000_Xn[13]+(*N-21000.0)*0.00029285714;
	Xn[14]=char21000_Xn[14]+(*N-21000.0)*0.00029285714;
	Xn[15]=char21000_Xn[15]+(*N-21000.0)*0.00029285714;

	Yn[0]=char21000_Yn[0];
	Yn[1]=char21000_Yn[1];
	Yn[2]=char21000_Yn[2];
	Yn[3]=char21000_Yn[3];
	Yn[4]=char21000_Yn[4];
	Yn[5]=char21000_Yn[5];
	Yn[6]=char21000_Yn[6];
	Yn[7]=char21000_Yn[7];
	Yn[8]=char21000_Yn[8];
	Yn[9]=char21000_Yn[9];
	Yn[10]=char21000_Yn[10];
	Yn[11]=char21000_Yn[11];
	Yn[12]=char21000_Yn[12];
	Yn[13]=char21000_Yn[13];
	Yn[14]=char21000_Yn[14];
	Yn[15]=char21000_Yn[15];
	}

fault = syst_char(*Rc, Xn, Yn, number, Xtype, Q_35ata);   //syst_char(T_REAL32 X, T_REAL32 *Xn, T_REAL32 *Yn, T_INT16 number, T_INT16 Xtype, T_REAL32 *Y, T_REAL32  *fault)

if (*Ts != 0.0) 
	*Q = (*Q_35ata * *Ps/35.0)/(*Ts/288.0); 
else *Q = 0;

//return GEF_EXECUTION_OK;
//return(OK); // ��� 90-70
}
