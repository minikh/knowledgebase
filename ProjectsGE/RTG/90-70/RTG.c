#include "math.h"     // �������������� �������
#include "plcc9070.h" //��������� ��� �����������


//int GefMain( unsigned int *in, float *res)
main(/*�����*/float *IN_Ro_s, float *IN_X_a, float *IN_X_u, float *IN_Dcu_20, float *IN_D_20, float *IN_R_sh, float *IN_Alfa_cu,float *IN_Alfa_t, float *IN_r_n, float *IN_Tau_t, float *IN_t, float *IN_P_iz, float *IN_P_at, float *IN_dP, unsigned int *IN_ContractTime, int *IN_dP_F, /*������*/float *raschet_q_c, float *raschet_q_v, float *raschet_q_m, int *raschet_Fault, unsigned int *raschet_Error)
{
float Beta, K_cu, Dcu, K_t, D, E, a, r_k, K_p, P, P_MPa, TT, Z_c, P_pk, T_pk, Z, P_a, T_a, dT_a, F, Tu_1;
float Tu_0, B_1, B_0, B_2, K, Ro, P_p, T_p, denominator, Mu_t, C_mu, Mu, K_ad, ee, idint, L_1, L_2, Re;
float M_2, R_a, c1, c2, A0, A1, A2, M_1, aa, c, R_amax, R_amin, A_sh, k_D, k_R, exp1, exp2, exp3, Lam1, Lam2, K_sh;
float prom1, prom2, prom3, prom4, prom5, prom6, prom7, prom8, prom9, prom10, prom11, prom12, prom13, prom14;
float prom15, prom16, prom17, prom18, prom19, prom20, prom22, prom23, prom24;
float A_0[16], A_1[16], A_2[16];
int i, j, prom21;


//����� ������
  *raschet_Error=0;
  *raschet_Fault=0;

// �������� ������ 

//1 ������� ��������� ��������� ��� ����������� 20 ��, �. 
// *IN_Dcu_20

// ����������� �� �������� ��������� ��
if (*IN_Dcu_20 < 0.0125) 
	 {
	 *IN_Dcu_20 = 0.0125;
	 *raschet_Error |= (1<<1);//�������� �������� �������� ��������� (��)
	 }
else if  (*IN_Dcu_20 > 0.09)
	 {
	 *IN_Dcu_20 = 0.09;
	 *raschet_Error |= (1<<1);//�������� �������� �������� ��������� (��)
	 }



//2 ���������� ������� �� ��� ����������� 20 ��, �. 
// *IN_D_20

//����������� �� �������� �������������� ������������
if  (*IN_D_20 < 0.05)
	 {
	 *IN_D_20=0.05;
	 *raschet_Error |= (1<<2);//�������� �������� �������� �������������� ������������
	 }
else if  (*IN_D_20 > 1.0)
	{
	*IN_D_20 = 1.0;
	*raschet_Error |= (1<<2);//�������� �������� �������� �������������� ������������
	}


//3 ������� �������������� ���������� ������� ������������� �� 
// *IN_R_sh

// ����������� �� R_sh
if ((*IN_R_sh < 0.0) || (*IN_R_sh > 0.01))
	 {
	 *IN_R_sh = 0.0003;
	 *raschet_Error |= (1<<3);//�� ������ �������� ������� �������������� ���������� ������� ������������� ��
	 }
 

//4 ��������, �� �������� ����������� ���������. ������������� ����������� ��������� ���������� ��������� ��
// *IN_Alfa_cu 

//����������� �� ����. ��������� ���������� ������� �� (���������) 
if ((*IN_Alfa_cu < 0.0) || (*IN_Alfa_cu>0.0005))
 {
 *IN_Alfa_cu=0.0000184;
 *raschet_Error |= (1<<4); //�� ������ �������� ����. ��������� ���������� ������� �� (���������)
 }


//5 ��������, �� �������� ���������� ��.������������� ����������� ��������� ���������� ��������� ��
//  *IN_Alfa_t

//����������� �� ����. ��������� ���������� ������� �� (�������������� ������������)
if ((*IN_Alfa_t < 0.0) || (*IN_Alfa_t>0.0005))
	{
	*IN_Alfa_t=0.0000184;
	*raschet_Error |= (1<<5); //�� ������ �������� ����. ��������� ���������� ������� �� (�������������� ������������)
	}


//6 ��������� ������ ������� ������ ���������, �
// *IN_r_n

// ����������� �� r_n
if ((*IN_r_n < 0.0) || (*IN_r_n>0.01))
	{
	*IN_r_n=0.00004;
	*raschet_Error |= (1<<6);//�� ������ �������� ���������� ������� ������� ������ ���������
	}


//7 ������� �����   ������������ ��������� � ������� ����������� �������� ���������� ������� ������� ������ ���������, ���
// *IN_Tau_t

if ((*IN_Tau_t < 0.0) || (*IN_Tau_t > 1.0))
	{ 
	*IN_Tau_t = 0.0;
	*raschet_Error |= (1<<7); //�� ������ �������� ��� ������� ���� ��������� � ������� ����������� �������� �������. ������� ������� ������
	}


//8 ���������� ����������� ���� � ��������� ����
// *IN_X_u
// ����������� �� Xu
if ((*IN_X_u < 0.0) || (*IN_X_u>0.16))
	{ 
	*IN_X_u=0.0147;
	*raschet_Error |= (1<<8);//�� ������ �������� ���������� ����������� ���� � ��������� ����
	}


//9 ���������� ����� � ��������� ����
// *IN_X_a
// ����������� �� Xa
if (( *IN_X_a < 0.0) || ( *IN_X_a>0.16))
	{
	*IN_X_a=0.0088;
	*raschet_Error |= (1<<9);// �� ������ �������� ���������� ����� � ��������� ����
	}



//10 ��������� ���������� ���� ��� ����������� ��������, ��/�^3 
// *IN_Ro_s
// ����������� �� ��������� ����
if (( *IN_Ro_s<0.6) || ( *IN_Ro_s>0.8))
	{
	*IN_Ro_s=0.735;
	*raschet_Error |= (1<<10);//�� ������ �������� ��������� ���������� ���� ��� ����������� ��������
	}


//11 ������������� ��������� ���������� ����, %

//12 ������� �������� �� ���������, ��
// *IN_dP
	if (*IN_dP_F) *raschet_Error |= (1<<11);


//13 ���������� ��������, ��
// *IN_P_iz
if  (*IN_P_iz < 0.0) *IN_P_iz = 0.0;


//14 ����������� ��������, ��
// *IN_P_at

if  (*IN_P_at > 140000.0) *IN_P_at = 140000.0;
else if  (*IN_P_at < 70000.0) *IN_P_at = 70000.0;

//15 ����������� ���������� ����, ��
// *IN_t

//����������� �����
if  (*IN_ContractTime < 0) *IN_ContractTime = 0;
else if  (*IN_ContractTime> 23) *IN_ContractTime = 23;



//�������� ������� ����������� ���������� �������
if  (*IN_P_iz <150000.0 ||  *IN_P_iz > 4000000.0 
	||   *IN_t < -20.0 ||  *IN_t > 80.0 
	||  *IN_dP < 20.0 ||  *IN_dP > 100000.0 ||  *IN_dP_F)  *raschet_Fault =1;




if (*raschet_Fault == 0) 
 {
	//���� 8.586-2005
	//GAV
	//1 �����������, ����������� ��������� �������� ��������� ���������, ��������� ����������� ����������� ���������� ���� �� 20 ��
	//���� 8.586.1 ������� (5.6)
	K_cu = 1.0 +  *IN_Alfa_cu * ( *IN_t - 20.0);

	//2 ������� ��������� ��������� ��� ������� �����������, �
	//���� 8.586.1 ������� (5.4)
	Dcu =   *IN_Dcu_20 * K_cu;
	//3 �����������, ����������� ��������� �������� ��, ��������� ����������� ����������� ���������� ���� �� 20 ��
	//���� 8.586.1 ������� (5.7)
	K_t = 1.0 +  *IN_Alfa_t * ( *IN_t - 20.0);
	//4 ���������� ������� �� ��� ������� ����������� ���������� ����, �
	//���� 8.586.1 [������� (5.5)]
	D =    *IN_D_20 * K_t;
	// 5 ������������� ������� ��������� ��������� Beta
	//���� 8.586.1 [������� (3.1)]

	//����������� �� ��������� ��������� �� � ��
	//����������� �� Beta
	Beta = Dcu/D;
	if (Beta < 0.1) 
		{
		Beta = 0.1;
		*raschet_Error |= (1<<12);//�� ���������� ��������� �������� ��������� (��) � �������� ��
		}
	else if (Beta > 0.75) 
		{  
	  	Beta =0.75;
		*raschet_Error |= (1<<12);//�� ���������� ��������� �������� ��������� (��) � �������� ��
		}
	

	//6 ����������� �������� �����
	//     8.586.1 [        (3.6)] E=1 / sqrt(1-(Beta ^ 4));
	//prom3 = 1.0-(Beta ^ 4.0);
	prom3 = 1.0-(pow(Beta, 4.0));
	prom4 = sqrt(prom3);
	E=1.0 /prom4 ;
	//7 ����������� �����������, ����������� ����������� ������� ������ ��������� K_p
	//���� 8.586.2 [������� (5.13)]
	a=0.000195;//  - ��������, ����������� ��� ���������� �����, ������� ��������� ������ 0,00019 ��� �������� 0,000195  ��� ���� � 0,0002  ��� ����;
	//r_k = a - (a -  *IN_r_n) * 2.718282 ^ (- *IN_Tau_t / 3.0);//������ ������� ������ ���������
	r_k = a - (a -  *IN_r_n) * pow(2.718282, (- *IN_Tau_t / 3.0));//������ ������� ������ ���������
	if (r_k < 0.0004 * D) K_p = 1.0;
	else K_p = 0.9826 + pow((r_k / Dcu + 0.0007773), 0.6);
	

	//8 ���������� �������� ���������� ���� ����� ����������, ��
	//���� 8.586.5 [������� (6.2)]
	//
	P =  *IN_P_at +  *IN_P_iz;
	P_MPa = P/1000000.0 ;//��� �������� �� ���� 30319


	//9 ����������������� ����������� ���������� ����, K
	//���� 8.586.5 [������� (6.3)]
	//
	//����������� �� � ����
	if  (*IN_t < -50.0)
		 {
		 *IN_t = -50.0;
		 *raschet_Error |= (1<<13);
		 }
	else if  (*IN_t > 150.0) 
		 {
		 *IN_t = 150.0;
		 *raschet_Error |= (1<<13);
		 }
	

	TT =  *IN_t + 273.15;


	//10 ������ ����������� ���������� ���� ��� ����������� ��������
	//� ��������� ��������� ���������� ���� ��� ����������� �������� � ���������� � ��� ����� � �������� ��������, �.�. �� �������
	//���� 30319.1 [������� (24)] 
	// �������� � ���� 30319 � �������� �������� ���������� � ���
	//Z_c
	Z_c = 1.0 - pow((0.0741 *  *IN_Ro_s - 0.006 - 0.063 *  *IN_X_a - 0.0575 *  *IN_X_u), 2.0);
	//11 ������ ����������� ���������� ���� ��� ������� ��������
	//���� 30319.2 [������� (6)]
	//Z
	P_pk= 2.9585 * (1.608 - 0.05994 *  *IN_Ro_s +  *IN_X_u - 0.392 *  *IN_X_a);//���
	T_pk= 88.25*(0.9915+1.759* *IN_Ro_s-  *IN_X_u-1.681*  *IN_X_a);

	if (P_pk <= 0.0 || T_pk <= 0.0)
		 {
		 *raschet_Error |= (1<<14);//������ � ������� ������� ����������� ��� ������� ��������
		 Z= Z_c;//������������ ������ ����������  ��� ������� �������� � �������� ��� ���������� ��������
		 }
	else
		{
		P_a= 0.6714 * (P_MPa / P_pk) + 0.0147;//���
		T_a= 0.71892*(TT/T_pk)+0.0007;
		dT_a = T_a - 1.09;
		// ^  ^  ^  ^  ^  ^  ^  ^  ^  ^  ^  ^ 
		//����������� �� dT_a
		if (dT_a > 0.3) dT_a =0.3;
		else if (dT_a<-0.25) dT_a = -0.25;
		// ^  ^  ^  ^  ^  ^  ^  ^  ^  ^  ^ *

		if (P_a >= 0.0 && P_a <= 2.0 && dT_a >= 0.0 && dT_a <= 0.3) 
			F=(75.0 * pow(10.0,(-5)) * pow(P_a,2.3)) / pow(2.718282,(20.0 * dT_a)) + 11.0 * pow(10.0,-4) * pow(dT_a,0.5)* (P_a * pow(2.17 - P_a + 1.4 * pow(dT_a, 0.5), 2.0));
		
		if (P_a >= 0.0 && P_a < 1.3 && dT_a >= -0.25 && dT_a < 0.0) 
			F=(75.0 * pow(10.0 , -5) * pow(P_a , 2.3) * (2.0 - pow(2.718282 , (20.0 * dT_a))) + 1.317 * P_a * (1.69 - pow(P_a , 2))* pow(dT_a , 4));
		
		if (P_a >= 1.3 && P_a < 2.0 && dT_a >= -0.25 && dT_a < 0.0)  
			F=(75.0 * pow(10.0 , -5) * pow(P_a , 2.3) * (2.0 - pow(2.718282 , (20.0 * dT_a))) + 0.455 * P_a * (1.3 - P_a) * (1.69 * pow(2.0 , 1.25) - pow(P_a , 2)) * (dT_a * (0.03249 + 18.028 * pow(dT_a ,  2)) + pow(dT_a , 2) * (2.0167 + pow(dT_a , 2) * (42.844 + 200.0 * pow(dT_a , 2))))); 
		

		Tu_1= pow(T_a , 5) / (pow(T_a , 2) * (6.60756 * T_a - 4.42646) + 3.22706);
		Tu_0=((pow(T_a , 2) * (1.77218 - 0.8879 * T_a) + 0.305131) * Tu_1) /pow(T_a , 4);

		B_1=(2.0 * Tu_1 / 3.0) - pow(Tu_0 , 2);
		B_0=Tu_0 * (Tu_1 - pow(Tu_0 , 2)) + 0.1 * Tu_1 * P_a * (F - 1.0);
		B_2 = pow(B_0 + pow(pow(B_0 , 2)+ pow(B_1 , 3) , 0.5) , 0.333333);


		Z=((pow(1.0 + (0.00132) / pow(T_a , 3.25) , 2) / (B_1 / B_2 - B_2 + Tu_0)) * (P_a / 10.0));
	}

	//12 ����������� ����������� ���������� ����
	//���� 30319.1 [������� (7)]
	//K
	K= Z/Z_c;
	//13 ��������� ���������� ����, ��/� 
	//���� 30319.1 [������� (6)] ����
	//��������� � ������� �������� (����������� ������� t =293.15 ���� � � � = 0.101325 ���)

	Ro= *IN_Ro_s * P_MPa * 293.15/ (0.101325 * TT * K);


	//14 ������������ �������� ���������� ����
	//���� 30319.1 [������� (44) � (45)]
	//����������������� �������� (���) � ����������� ���� 30319.2 ������� 17 � 18 



	if  (*raschet_Error & (1<<14)) //*raschet_Error.X[14] = 1 then //*******************************************************************
		  *raschet_Error |= (1<<15); //������ � ������� ������������ �������� ���������� ����
	else
		{
		//���������� �������� � �����������
		P_p=P_MPa/P_pk;
		T_p=TT/T_pk;
		//������������ �������� ���������� ���� � ������ ��� �����������, ��������� �� �����������, ��� ��������� �� 0,5 ��� , ����?�
		denominator = pow(*IN_Ro_s , 0.5)+2.08-1.5*( *IN_X_a+ *IN_X_u);
		if (denominator > 0.0)
			{
			Mu_t=3.24*(pow(TT , 0.5)+1.37-9.09* pow(*IN_Ro_s , 0.125))/denominator;
				//�������� ��� ���������� ��������� (�� 12 ���) ��� ���������� ���� ��������� �� �������
				denominator = 30.0*(T_p-1.0);
				if (denominator != 0.0)
					{
					C_mu=1.0+(pow(P_p , 2)/ denominator);
					Mu=Mu_t*C_mu * 0.000001;//�������� � ��*�
					}
				else *raschet_Error |= (1<<15); //������ � ������� ������������ �������� ���������� ����
			}
		else *raschet_Error |= (1<<15); //������ � ������� ������������ �������� ���������� ����
		
		}

	if   (*raschet_Error & (1<<15))//*raschet_Error.X[15] = 1 then   //********************************************************************
		Mu= 0.0000111315;// Fallback ��� ������ � �������� ������������ ��������
	
	//15 ���������� �������� ���������� ����
	//���� 30319.1 [������� (28)]

	K_ad=1.556 * (1.0 + 0.074 *  *IN_X_a) - 3.9 * pow(10.0 , -4) * TT * (1.0 - 0.68 *  *IN_X_a) - 0.208 *  *IN_Ro_s + pow((P_MPa / TT) , 1.43) * (384.0 * (1.0 -  *IN_X_a) * pow((P_MPa / TT), 0.8) + 26.4 *  *IN_X_a);


	//16 ����������� ����������
	//���� 8.586.2 [������� (5.7)]
	if  (*IN_dP/P > 0.025 && K_ad == 0.0)
		{
		*raschet_Error |= (1<<16); //������ � ������� ����������� ����������
		ee= 1.0; //Fallback ��� ������������ ����������
		}
	else
		ee= 1.0 - (0.351 + 0.256 * pow(Beta , 4) + 0.93 * pow(Beta , 8)) * (    1.0 - pow((1.0 -  *IN_dP / P) , (1.0 / K_ad))   );
	



	//������ ������� ���������� ����,
	 c2= 1.0;
	 c1= 0.0;
	idint =0.0;

	L_1=0.0; // �������� ������� ������  ��������
	L_2=0.0;

	if (D < 0.07112) M_2=0.011*(0.75-Beta)*(2.8-D/0.0254);
	
	if (D >= 0.07112) M_2=0.0;
	

	///1 ��������� �������� ����� ����������
	Re = 1000000.0;
	
	// ������� �������������, ������������ ��� ������� ������������ ������������, ������������ ������������� ���������� ����������� ��
	A_0[0]=8.87; A_0[1]=-3.7114; A_0[2]=0.41841; A_0[3]=0.0; A_0[4]=27.23; A_0[5]=-11.458; 
	A_0[6]=1.6117; A_0[7]=-0.07567; A_0[8]=16.5416; A_0[9]=-6.60709; A_0[10]=0.88147; A_0[11]=-0.039226;
	A_1[0]=6.7307; A_1[1]=-5.5844; A_1[2]=0.732485; A_1[3]=0.0; A_1[4]=-25.928; A_1[5]=12.426; 
	A_1[6]=-2.09397; A_1[7]=0.106143; A_1[8]=322.594; A_1[9]=-132.2; A_1[10]=17.795; A_1[11]=-0.799765;
	A_2[0]=-10.244; A_2[1]=5.7094; A_2[2]=0.76477; A_2[3]=0.0; A_2[4]=1.7622; A_2[5]=-3.8765; A_2[6]=1.05567;
	A_2[7]=-0.076764; A_2[8]=-92.029; A_2[9]=37.935; A_2[10]=-5.1885; A_2[11]=0.23583;

	R_a= *IN_R_sh/3.141592;
	
	prom2 = (( c2 -  c1) /  c2);
	
	prom1 = abs(prom2);
	
while  (prom1 > 0.00001 && idint <10.0) //����������� �� �������� � ���-�� ��������
	{
		idint = idint +1.0;

	// ������ ����������� ���������
	//���� 8.586.2 [������� (5.6)]
		A0=0.0;
		A1=0.0;
		A2=0.0;
		 c1=  c2;
		M_1= 2.0 * L_2 / (1.0 - Beta);
		aa= pow((19000.0 * Beta / Re) , 0.8);
	//2 ����������� ���������
	//���� 8.586.2 [������� (5.6)]
		c=0.5961 + 0.026 * pow(Beta , 2) - 0.216 * pow(Beta , 8)+0.000521* pow((pow(10.0 , 6) * Beta / Re) , 0.7)+ 	(0.0188+0.0063*aa)*pow(Beta , 3.5) * pow((pow(10.0 , 6)/Re) , 0.3)+(0.043+0.08* pow(2.718282 , (-10.0 * L_1)) - 0.123 * pow(2.718282 , (-7.0*L_1))) * (1.0 -0.11*aa)*pow(Beta , 4)/(1.0 -pow(Beta , 4))-0.031 * (M_1 - 0.8 * pow(M_1 , 1.1)) * pow(Beta , 1.3) + M_2;
	// 3 ����������� �����������, ����������� ������������� ���������� ����������� ��
	//���� 8.586.2 [������� (5.11)]
		//����������� ����. �� ������������� �� �.5.11 ���� 8.586.2-2005

	// ���������� Ra_max
		j=0;
		if (Re > pow(10.0 , 4) && Re <= pow(10.0 , 5)) j= 0;
		
		if (Re > pow(10.0 , 5) && Re <= 3.0* pow(10.0 , 6)) j= 4;
		
		if (Re > 3.0* pow(10.0 , 6) && Re <= pow(10.0 , 8)) j= 8;
		
		for (i= 0; i<4; i++) //; i != 4; i++)
			{
			prom20 = log10(Re); //log10_REAL(Re, );
			prom5 = pow(prom20 , i);
			prom21 = i+j;
			A0=A0 + A_0[prom21] *(prom5);
			A1=A1 + A_1[prom21] *(prom5);
			A2=A2 + A_2[prom21] *(prom5);
			}
		
		if (Re <= pow(10.0 , 4)) R_amax= 0.718866 * pow(Beta , -3.887) + 0.364;
		
		if (Re > pow(10.0 , 4) && Beta < 0.65) R_amax=A0 * pow(Beta , A1) + A2;
		
		if (Re > pow(10.0 , 4) && Beta >= 0.65) R_amax=A0 * pow(0.65 , A1) + A2;
		


		if (R_amax >= 15.0) R_amax=(15.0* pow(10.0 , -4)) * D;
		else R_amax = R_amax * D * 0.0001;

		

	// ���������� Ra_min

		prom6 = log10(Re);
		if (Beta < 0.65) R_amin=7.1592 - 12.387 * Beta - (2.0118 - 3.469 * Beta) * prom6 + (0.1382 - 0.23762 * Beta) * pow(prom6 , 2);
		
		if (Beta >= 0.65) R_amin=-0.892353 + 0.24308 * prom6 - 0.0162562 * pow(prom6 , 2);
		
		if (R_amin <= 0.0 || Re < 3.0* pow(10.0 , 6)) R_amin= 0.0;
		
		//	R_amin

		A_sh= 3.141592 *R_a;               
		k_D= (0.26954 * 3.141592 * R_a) / D; 
		k_R= 5.035 / Re;      
		
		prom7 = k_D + 3.3333 * k_R;	
		prom8 = log10(prom7);
		exp1 = k_R * prom8;

		if (exp1 > k_D) 
			  *raschet_Error |= (1<<17); //O����� � ������� ������������ ������������, ����������� ������������� ���������� ����������� ��
		else
			{
			prom9 = k_D - exp1;
			prom10 = log10(prom9);
			exp2 = (2.0 * A_sh / D) - (37.36 * prom10 / Re);
			if (exp2 < 0.0)
				{
				*raschet_Error=1;//O����� � ������� ������������ ������������, ����������� ������������� ���������� ����������� ��
				Lam1= 0.0001;
				}
			else
				{
				prom11 = log10(exp2);
				Lam1= pow((1.74 - 2.0 * prom11) , -2);
   	   
				if (R_a > R_amax) 
					{
					A_sh= 3.141592*R_amax;
					k_D= 0.26954 *3.141592* R_amax/D;
					}
				
				if (R_a < R_amin) 
					{
					A_sh=3.141592*R_amin;
					k_D= 0.26954 * 3.141592 * R_amin/D;
					}
				}
			
			prom12 = (k_D + 3.3333 * k_R);
			prom13 = log10 (prom12);
			exp1 = k_R * prom13;
			if (exp1 > k_D)
				  *raschet_Error |= (1<<17); //O����� � ������� ������������ ������������, ����������� ������������� ���������� ����������� ��
			else
				{
				prom14 =(k_D - exp1);
				prom15 = log10(prom14);
				exp2 = (2.0 * A_sh / D) - (37.36 * prom15/ Re);
				if (exp2 < 0.0) 
					{
					*raschet_Error |= (1<<17); //O����� � ������� ������������ ������������, ����������� ������������� ���������� ����������� ��
					Lam2= 0.0001;
					}
				else
					{
					prom16 = log10(exp2);
					Lam2= pow((1.74 - 2.0 * prom16) , -2);
					}
				}
			}
	// �������� �� �������-��!!!

		if  (*raschet_Error & (1<<17)) //*raschet_Error.X[17]=1 then //***********************************************************
			K_sh = 1.0;
		else
			K_sh=1.0 + 5.22 * pow(Beta , 3.5) * (Lam1 - Lam2);
		

	//4 �������� ������ ���������� ����, ����������� � ����������� ��������,  ��� � /�
	//���� 8.586.5 [������� (5.8)]
		exp3 = 0.25 *3.141592 * pow(Dcu , 2) * c * E * K_sh * K_p * ee ;
		prom22 = 2.0 *  *IN_dP * (( P * 293.15) / ( *IN_Ro_s * 101325.0 *TT* K));
		prom17 = sqrt(prom22);
		 c2= exp3 * prom17;

	//5 ���������� �������� ����� ����������
	//���� 8.586.5 [������� (5.11)]
		Re=(4.0 *  c2 *  *IN_Ro_s) / (3.141592* D * Mu); 
	
	} //while  (prom1 > 0.00001 && idint <10.0) //����������� �� �������� � ���-�� ��������

	  *raschet_q_c =  c2;
	  prom23 = 2.0 *  *IN_dP *  *IN_Ro_s * P * 293.15 / (101325.0 * TT * K);
	  prom18 = sqrt( prom23);
	  *raschet_q_m = exp3 * prom18;
	  prom24=  2.0 *  *IN_dP * 101325.0 * TT * K / ( *IN_Ro_s * 293.15 *P );
	  prom19 = sqrt(prom24);
	  *raschet_q_v = exp3 * prom19;
  
 }
else
	  {
	  *raschet_q_c = 0.0;
	  *raschet_q_m = 0.0;
	  *raschet_q_v = 0.0;
	  }




	return(OK);
}