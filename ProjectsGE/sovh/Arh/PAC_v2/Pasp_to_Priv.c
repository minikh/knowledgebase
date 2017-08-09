#include "math.h"     // �������������� �������
#include "PACRXPlc.h" //��������� ��� ����������� PAC
//#include "plcc9070.h" //��������� ��� ����������� 90-70

#include "init.h"  //�������������

#include "syst_char.h" // �������� ������������




void GefMain(/*�����*/IN, 
			 /*������*/ OUT, 
			 /*���������*/ Const)
float *IN;
float *OUT;
float *Const;

//void GefMain(/*�����*/float N,float *P_IN, float *P_OUT, float *T_IN, 
//				/*������*/ float *Ky, float *Q_35ata,  float *Q_pr,
//				/*���������*/ float Nnom, float *Q_min, float *p_g, float *B)

/*
#define Nnom 22300 	//����������� ������� �����������
#define Q_min 12.3  	//����� �� �������
#define p_g 0.68 		// ��������� ���� ��/�3
#define B 750		// ��������������� �������� ��.��.��
*/
//main() // ��� 90-70
{
//syst_char(Rc, *Xn, *Yn, number, Xtype, *Q_35ata,  *fault);   //syst_char(T_REAL32 X, T_REAL32 *Xn, T_REAL32 *Yn, T_INT16 number, T_INT16 Xtype, T_REAL32 *Y, T_REAL32  *fault)

float Xn[16], Yn[16], B_, Pin, Tin, p_, R, Tkr, Tpr, Pkr, Ppr, Zin, p_in, /*Q_pr,*/ Q, Rc;
int number, Xtype, fault;
float N,P_IN,P_OUT,T_IN, Ky, Q_35ata, Q_pr, Nnom, Q_min, p_g, B;

N= IN[0];
P_IN= IN[1];
P_OUT= IN[2];
T_IN= IN[3];
Q_35ata = IN[4];

Nnom= Const[0];
Q_min= Const[1];
p_g= Const[2];
B= Const[3];



//������� ������
Rc = P_OUT / P_IN;	
	


//��������������� ��������, (ks/cm2)
B_= B * 1.0332/760.0;

//�������� �� ����� � �����������, (ks/cm2)
Pin= P_IN /* * 0.010197*/ + B_;
if (Pin == 0.0) Pin= 0.0000001; 

//����������� �� ����� � �����������, (grK)
Tin= T_IN+273.2;

//������������� ��������� ����
p_= p_g/1.205;

//������� ����������
if (p_!= 0.0) R= 29.27/p_;
else R= 1;

//����������������� �����������
Tkr= 162.8 * (0.613+p_);

//����������������� ��������
Pkr= 47.9-p_;
if (Pkr == 0.0) Pkr= 0.0001; 

//���������� �����������
if (Tkr != 0.0) Tpr= Tin/Tkr;
else Tpr= 1;
if (Tpr == 0.0) Tpr= 0.01; 

//���������� ��������
Ppr= Pin/Pkr;
if (Ppr == 0.0) Ppr= 0.0001; 


//����������� �����������
Zin= 1.0 - (((0.41 / (Tpr*Tpr*Tpr)) - (0.061/Tpr)) * Ppr)-(0.04 * (Tpr*Tpr)/(Tpr*Tpr*Tpr));	


	
//��������� �� ����� � �����������	
if (Zin * Tin * R != 0) p_in = (Pin * 10000) / (Zin * Tin * R);
else p_in= 1;
if (p_in == 0.0) p_in= 0.0001; 

//������������������ (�3/���)
Q = (Q_35ata * p_g) / (0.00144 * p_in);
//����������� ������������������ (�3/���)	
if (N != 0) Q_pr = 	Q * (Nnom / N);
else Q_pr= 0;
//����� �� ������� %
if (Q_min != 0) Ky = 100 * (Q_pr - Q_min) / Q_min;
else Ky = 0;

OUT[0]= Ky;
OUT[2]= Q_pr;
	
//return GEF_EXECUTION_OK;
//return(OK); // ��� 90-70
}
