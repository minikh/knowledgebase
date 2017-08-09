#include <stdio.h>
#include "math.h"     // �������������� �������
#include "PACRXPlc.h" //��������� ��� ����������� PAC
//#include "plcc9070.h" //��������� ��� ����������� 90-70
#include "structs.h"
float TSCAN;

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

///***************************************************** main **********************************************************
void GefMain(/*�����*/IN, iFolt,
			/*������*/ OUT,oFolt,SpeedBuf,Temp)
float *IN; //3
short *iFolt; //1
float *OUT; //2
short *oFolt; //1
float *SpeedBuf; //6
float *Temp;

{
float AI, SpeedLim, Speed, MaxSpeed;
short SpeedFlt= 0, Folt= 0;

AI= IN[0];
SpeedLim= IN[1];
TSCAN= IN[2];

MaxSpeed= OUT[1];

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
	if (MaxSpeed < Speed) {
		MaxSpeed = Speed;
	}
}
Folt= SpeedFlt || *iFolt;
*oFolt = TOF(Folt,5,Temp);	
if (*oFolt){
	AI = SpeedBuf[5];
}
else {
	SpeedBuf[5] = SpeedBuf[4];	
}

OUT[0]= AI;
}
