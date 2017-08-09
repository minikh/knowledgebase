
int syst_char(float X, float *Xn, float *Yn, int number, int Xtype, float *Y)
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

