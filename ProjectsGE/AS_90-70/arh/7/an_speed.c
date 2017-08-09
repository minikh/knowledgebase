#include <stdio.h>
#include "math.h"     // математические функции
#include "PACRXPlc.h" //процедуры для контроллера PAC
//#include "plcc9070.h" //процедуры для контроллера 90-70
#include "structs.h"
float TSCAN;

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

///***************************************************** main **********************************************************
void GefMain(/*Входы*/IN, iFolt,
			/*Выходы*/ OUT,oFolt,SpeedBuf,Temp)
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
