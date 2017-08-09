#include "math.h"     // �������������� �������
#include "PACRXPlc.h" //��������� ��� �����������
#include "Structs.h"  //���������

float TSCAN;
	
//���������� �����				
#define	DI_ON			IM->DI.ON
#define	DI_OF			IM->DI.OF
#define	DI_KCU_ON			IM->DI.KCU_ON
#define	DI_KCU_OF			IM->DI.KCU_OF
#define	DI_Move			IM->DI.Move
#define	DI_M_Mufft			IM->DI.M_Mufft
#define	DI_Vibr			IM->DI.Vibr
#define	DI_Loil			IM->DI.Loil
#define	DI_U_OF			IM->DI.U_OF
#define	DI_Poil			IM->DI.Poil
				
				
//���������� ������				
#define	DO_ON			IM->DO.ON
#define	DO_OF			IM->DO.OF
#define	DO_STOP			IM->DO.STOP
#define	DO_ONForce			IM->DO.ONForce
#define	DO_OFForce			IM->DO.OFForce
				
				
//������� ��������������				
#define	AVT_ON			IM->AVT.ON
#define	AVT_OF			IM->AVT.OF
				
				
//������				
#define	BTN_ON			IM->BTN.ON
#define	BTN_OF			IM->BTN.OF
#define	BTN_RU			IM->BTN.RU
#define	BTN_STOP			IM->BTN.STOP
				
				
//������� �� ���������				
#define	ALG_ON_IMIT			IM->ALG.ON_IMIT
#define	ALG_DO_Ban			IM->ALG.DO_Ban
#define	ALG_RU_Ban			IM->ALG.RU_Ban
				
				
//���������				
#define	CFG_Disable			IM->CFG.Disable
#define	CFG_T_Alarm			IM->CFG.T_Alarm
#define	CFG_T_KCU			IM->CFG.T_KCU
#define	CFG_T_NotMove			IM->CFG.T_NotMove
#define	CFG_T_NotCO			IM->CFG.T_NotCO
#define	CFG_T_Press			IM->CFG.T_Press
#define	CFG_T_Force			IM->CFG.T_Force
#define	CFG_T_Block			IM->CFG.T_Block
#define	CFG_T_Imit			IM->CFG.T_Imit
#define	CFG_TYPE_KCU			IM->CFG.TYPE_KCU
#define	CFG_Come_Back			IM->CFG.Come_Back
#define	CFG_Init			IM->CFG.Init
#define	CFG_MUK			IM->CFG.MUK
#define	CFG_ONForceEN			IM->CFG.ONForceEN
#define	CFG_OFForceEN			IM->CFG.OFForceEN
#define	CFG_KCU_ON_EN			IM->CFG.KCU_ON_EN
#define	CFG_KCU_OF_EN			IM->CFG.KCU_OF_EN
#define	CFG_NarabReset			IM->CFG.NarabReset
				
				
//��� ��				
#define	TYPE_IM_0x1			IM->TYPE.IM_0x1
#define	TYPE_IM_1x1			IM->TYPE.IM_1x1
#define	TYPE_IM_1x2			IM->TYPE.IM_1x2
#define	TYPE_IM_2x1			IM->TYPE.IM_2x1
#define	TYPE_IM_2x2			IM->TYPE.IM_2x2
				
				
//�������				
#define	ST_Ver			IM->ST.Ver
#define	ST_FLT			IM->ST.FLT
#define	ST_M_Mufft			IM->ST.M_Mufft
#define	ST_notON			IM->ST.notON
#define	ST_notOF			IM->ST.notOF
#define	ST_SPON			IM->ST.SPON
#define	ST_SPOF			IM->ST.SPOF
#define	ST_KV_FLT			IM->ST.KV_FLT
#define	ST_KCU_ON_FLT			IM->ST.KCU_ON_FLT
#define	ST_KCU_OF_FLT			IM->ST.KCU_OF_FLT
#define	ST_notMove_ON			IM->ST.notMove_ON
#define	ST_notMove_OF			IM->ST.notMove_OF
#define	ST_RUs			IM->ST.RUs
#define	ST_Narab			IM->ST.Narab
#define	ST_Move			IM->ST.Move
#define	ST_Stat			IM->ST.Stat
#define	ST_ON			IM->ST.ON
#define	ST_OF			IM->ST.OF
				
//������				
#define	Err_Err			IM->Err.Err
				
				
//��������� �������				
#define	TMP_T_Alarm			IM->TMP.T_Alarm
#define	TMP_T_Alarm_EN			IM->TMP.T_Alarm_EN
#define	TMP_T_KCU_ON			IM->TMP.T_KCU_ON
#define	TMP_T_KCU_OF			IM->TMP.T_KCU_OF
#define	TMP_T_NotMove			IM->TMP.T_NotMove
#define	TMP_T_NotMove_EN			IM->TMP.T_NotMove_EN
#define	TMP_T_NotCO			IM->TMP.T_NotCO
#define	TMP_T_NotCO_EN			IM->TMP.T_NotCO_EN
#define	TMP_T_Press_ON			IM->TMP.T_Press_ON
#define	TMP_T_Press_OF			IM->TMP.T_Press_OF
#define	TMP_T_Press_ON_EN			IM->TMP.T_Press_ON_EN
#define	TMP_T_Press_OF_EN			IM->TMP.T_Press_OF_EN
#define	TMP_T_Force			IM->TMP.T_Force
#define	TMP_T_Force_EN			IM->TMP.T_Force_EN
#define	TMP_T_Block_ON			IM->TMP.T_Block_ON
#define	TMP_T_Block_OF			IM->TMP.T_Block_OF
#define	TMP_T_Block_ON_EN			IM->TMP.T_Block_ON_EN
#define	TMP_T_Block_OF_EN			IM->TMP.T_Block_OF_EN
#define	TMP_T_Imit			IM->TMP.T_Imit
#define	TMP_T_Imit_EN			IM->TMP.T_Imit_EN
#define	TMP_AVT_ON			IM->TMP.AVT_ON1
#define	TMP_AVT_OF			IM->TMP.AVT_OF1
#define	TMP_MUpr			IM->TMP.MUpr
#define	TMP_AUpr			IM->TMP.AUpr
#define	TMP_T_Move_ON			IM->TMP.T_Move_ON
#define	TMP_T_Move_OF			IM->TMP.T_Move_OF
#define	TMP_T_Move_ON_EN			IM->TMP.T_Move_ON_EN
#define	TMP_T_Move_OF_EN			IM->TMP.T_Move_OF_EN
#define	TMP_ON_IMIT			IM->TMP.ON_IMIT


//******************************************* ������� Coil ***************************************************	
T_BOOLEAN Coil(T_BOOLEAN IN)
{
T_BOOLEAN out;
if (IN == 1) out= 1;
else out= 0;
return out;
}

//******************************************* Timer ***************************************************
//������ 
T_BOOLEAN Timer(T_REAL32 *Time, T_REAL32 Ust)
{
T_BOOLEAN out;
		if (*Time < Ust)
			{
			out= 0;
			*Time= *Time + TSCAN;
			}
		else
			out= 1;
return out;
}


//******************************************* main ***************************************************
void GefMain(IM, iTSCAN)
IM_STR *IM;
float *iTSCAN;


{
T_BOOLEAN Open, Rep_ON, Rep_OF, Tmax_ON, Tmax_OF, u_notMove_ON, u_notMove_OF, u_notON, u_notOF;
T_BOOLEAN Press_ON, Press_OF, u_SPON, u_SPOF;

//������ ���������
ST_Ver = 3.01;
//����������� ���� ���������� ����������
TSCAN= *iTSCAN;


//���� ������ ������� ��������������� ����������, �� ������ ������ ������� ����������
ALG_RU_Ban = Coil(AVT_ON || AVT_OF);


//���� ������ ������� ��������������� ����������, �� ��������� ������� � �������������� �����
if ((AVT_ON != TMP_AVT_ON) || (AVT_OF != TMP_AVT_OF))
	BTN_RU = 0;

//������� ���� ������� ������
ST_RUs = Coil(BTN_RU);
	
//���������� ������� �������� �����
TMP_AVT_ON = Coil(AVT_ON);
TMP_AVT_OF = Coil(AVT_OF);

// ������ ����������
if (!TMP_MUpr)
	{
	// ���� (�������������� ����� � ���� ������� �������) ��� ������ ������ �������
	if ((!BTN_RU && AVT_ON) || BTN_ON)
		//�� ��� ������� ���������� � 1
		TMP_MUpr = 1;
	}
else
	{
	// (���� �������������� ����� � ���� ������� �������) ��� ������ ������ �������
	if ((!BTN_RU && AVT_OF) || BTN_OF)
		//�� ��� ������� ���������� � 1
		TMP_MUpr = 0;
	}
		
// �������������� ����������
if (!TMP_AUpr)
	{
	// ���� �������������� ����� � ���� ������� �������
	if (!BTN_RU && AVT_ON)
		//�� ��� �������������� ���������� � 1
		TMP_AUpr = 1;
	}
else
	{
// ���� �������������� ����� � ���� ������� ������� 
	if (!BTN_RU && AVT_OF)
		//�� ��� �������������� ���������� � 1
		TMP_AUpr = 0;
	}

//���� ������� / �������
Open = Coil((BTN_RU && TMP_MUpr) || (!BTN_RU && TMP_AUpr));
		
		
//������ ������� ������� ��������
if (!DO_ON)		
	TMP_T_Block_ON_EN = Timer(&TMP_T_Block_ON, CFG_T_Block);
else
	{
	TMP_T_Block_ON_EN = 0;
	TMP_T_Block_ON = 0;	
	}	
	
//������ ������� ������� ��������
if (!DO_OF)		
	TMP_T_Block_OF_EN = Timer(&TMP_T_Block_OF, CFG_T_Block);
else
	{
	TMP_T_Block_OF_EN = 0;
	TMP_T_Block_OF = 0;	
	}	

// ������ ������� �������� ��������
Rep_ON = Coil (TMP_T_Block_ON_EN && BTN_ON && (ST_notON || ST_notMove_ON || ST_SPOF));
// ������ ������� �������� ��������
Rep_OF = Coil (TMP_T_Block_OF_EN && BTN_OF && (ST_notOF || ST_notMove_OF || ST_SPON));	
	
//������������ ������� "����� ��������"
if (Open && !Rep_ON)	
	Tmax_ON = Timer(&TMP_T_Move_ON, CFG_T_Alarm);
else
	{
	Tmax_ON = 0;
	TMP_T_Move_ON = 0;	
	}		
	
//������������ ������� "����� ��������"
if (!Open && !Rep_OF)	
	Tmax_OF = Timer(&TMP_T_Move_OF, CFG_T_Alarm);
else
	{
	Tmax_OF = 0;
	TMP_T_Move_OF = 0;	
	}			
	
// ������������ ������� ��� ������� "�� ����������� �� ��������"	
u_notMove_ON = Coil(Open && (TMP_T_Move_ON >= CFG_T_NotMove));
// ������������ ������� "�� ����������� �� ��������"
ST_notMove_ON = Coil(Open && DI_OF && u_notMove_ON);

// ������������ ������� ��� ������� "�� ����������� �� ��������"	
u_notMove_OF = Coil(!Open && (TMP_T_Move_OF >= CFG_T_NotMove));
// ������������ ������� "�� ����������� �� ��������"
ST_notMove_OF = Coil(!Open && DI_ON && u_notMove_OF);
	
	
// ������������ ������� ��� ������� "�� ������"		
u_notON	= Coil(Open && (TMP_T_Move_ON >= CFG_T_NotCO));
// ������������ ������� "�� ������"		
ST_notON = Coil(Open && !DI_ON && u_notON && !ST_SPOF);

// ������������ ������� ��� ������� "�� ������"		
u_notOF	= Coil(!Open && (TMP_T_Move_OF >= CFG_T_NotCO));
// ������������ ������� "�� ������"		
ST_notOF = Coil(!Open && !DI_OF && u_notOF && !ST_SPON);	
	
// ����� �� ��������	
if (Open && DI_ON)	
	TMP_T_Press_ON_EN = Timer(&TMP_T_Press_ON, CFG_T_Press);
else
	{
	TMP_T_Press_ON_EN = 0;
	TMP_T_Press_ON = 0;	
	}	
Press_ON = Coil(TMP_T_Press_ON_EN);

// ����� �� ��������	
if (!Open && DI_OF)	
	TMP_T_Press_OF_EN = Timer(&TMP_T_Press_OF, CFG_T_Press);
else
	{
	TMP_T_Press_OF_EN = 0;
	TMP_T_Press_OF = 0;	
	}	
Press_OF = Coil(TMP_T_Press_OF_EN);	
	
//������������ ������� ��� ������� "���������������� ��������"		
if (Open && Press_ON && Tmax_ON) 
	u_SPOF = 1;
//������������ ������� "���������������� ��������"		
ST_SPOF	= Coil(Open && !DI_ON && u_SPOF);
//������ ������� ��� ������� "���������������� ��������"	
if (!Open)	
	u_SPOF = 0; 
	
//������������ ������� ��� ������� "���������������� ��������"		
if (!Open && Press_OF && Tmax_OF) 
	u_SPON = 1;
//������������ ������� "���������������� ��������"		
ST_SPON	= Coil(!Open && !DI_OF && u_SPON);
//������ ������� ��� ������� "���������������� ��������"	
if (Open)	
	u_SPON = 0; 

//������� 
DO_ON = Coil(Open && !Press_ON && !Tmax_ON && !ALG_DO_Ban);

//������� 
DO_OF = Coil(!Open && !Press_OF && !Tmax_OF && !ALG_DO_Ban);

	

//�������� ����������� ����������
//���� ������������ ��� ��������� � 1 �� ����
if (DI_ON && DI_OF)
	ST_KV_FLT= 1;
//����� ��� �����
else
	ST_KV_FLT= 0;


//�������� ����� ���������� ��������
//���� ��� �������� ��� �� ����� ������� ������ � 1
if (CFG_TYPE_KCU)
	//���� ��� �� ����� ��� 1
	if (!DI_KCU_ON)
		//��������� ������ � ������ ����
		ST_KCU_ON_FLT= Timer(&TMP_T_KCU_ON, CFG_T_KCU);
	else
		{
		//����� ����� ����� � �������
		ST_KCU_ON_FLT= 0;
		TMP_T_KCU_ON = 0;
		}
//���� ��� �������� ��� �� ����� � �������� DI = 0 ��� DO =1 � DI = 1 ��� DO =0
else
	// ���� DI = 0 ��� DO =1 ��� DI = 1 ��� DO = 0
	if ((DI_KCU_ON && DO_ON) || (!DI_KCU_ON && !DO_ON && !DO_OF))
		ST_KCU_ON_FLT= Timer(&TMP_T_KCU_ON, CFG_T_KCU);
	else
		{
		ST_KCU_ON_FLT= 0;
		TMP_T_KCU_ON = 0;
		}

//�������� ����� ���������� ��������
//���� ��� �������� ��� �� ����� ������� ������ � 1
if (CFG_TYPE_KCU)
	//���� ��� �� ����� ��� 1
	if (!DI_KCU_OF)
		//��������� ������ � ������ ����
		ST_KCU_OF_FLT= Timer(&TMP_T_KCU_OF, CFG_T_KCU);
	else
		{
		//����� ����� �����
		ST_KCU_OF_FLT= 0;
		TMP_T_KCU_OF = 0;
		}
//���� ��� �������� ��� �� ����� � �������� DI = 0 ��� DO =1 � DI = 1 ��� DO =0
else
	// ���� DI = 0 ��� DO =1 ��� DI = 1 ��� DO = 0
	if ((DI_KCU_OF && DO_OF) || (!DI_KCU_OF && !DO_OF && !DO_ON))
		ST_KCU_OF_FLT= Timer(&TMP_T_KCU_OF, CFG_T_KCU);
	else
		{
		ST_KCU_OF_FLT= 0;
		TMP_T_KCU_OF = 0;
		}



//��������

//���� ������� ��������
if (ALG_ON_IMIT) 
	{
	//���� ������ ������� �������� ��������, �� 
	if (!TMP_ON_IMIT)
		{
		//���� ��������� ������� ���� �������
		if (TMP_AUpr)
			{
			//��������� ��������� �������
			DI_ON= 1;
			DI_OF= 0;
			}
		//���� ��������� ������� ���� �������
		else
			{
			//��������� ��������� �������
			DI_ON= 0;
			DI_OF= 1;
			}
		}

	
	//����� �� ���� ����� �� ���
	DI_KCU_ON= 1;
	DI_KCU_OF= 1;
	//���� ���� ������� ������� ��� �������, �� ��������� ������ 
	if (DO_ON || DO_OF) 
		TMP_T_Imit_EN= Timer(&TMP_T_Imit, CFG_T_Imit);
	else
		{
		TMP_T_Imit_EN = 0;
		TMP_T_Imit= 0;
		}

	//���� ���������
	if (DO_ON)
		{
		//����������� ��� �������� ���� 
		if (!CFG_TYPE_KCU) 
			DI_KCU_ON= 0;
			
		//���� ����� ������ 0,5 ���, �� ����� �������� "������"
		if (TMP_T_Imit >= 0.5)
			DI_OF= 0;
		
		//���� ����� �����, �� �������� �������� "������"
		if (TMP_T_Imit_EN) 
			DI_ON= 1;
		}
	else
		//����������� ��� �������� ���� ���� �� ���������
		DI_KCU_ON= 1;
	
	//���� ���������
	if (DO_OF)
		{
		//����������� ��� �������� ���� 
		if (!CFG_TYPE_KCU) 
			DI_KCU_OF= 0;
		
		//���� ����� ������ 0,5 ���, �� ����� �������� "������"
		if (TMP_T_Imit >= 0.5)
			DI_ON= 0;

		//���� ����� �����, �� �������� �������� "������"
		if (TMP_T_Imit_EN)
			DI_OF= 1;
		}
	else
		//����������� ��� �������� ���� ���� �� ���������
		DI_KCU_OF= 1;
		
	} //if (ALG_ON_IMIT) 
	
	//���������� ������� �������� 
	TMP_ON_IMIT = Coil(ALG_ON_IMIT);
	
//���������� ������ ������
if (ST_notMove_ON || ST_notMove_OF || ST_KCU_ON_FLT || ST_KCU_OF_FLT || 
	ST_notON || ST_notOF || ST_M_Mufft || ST_SPON || ST_SPOF || ST_KV_FLT)
		ST_FLT = 1;
else
		ST_FLT = 0;
		
		
}
