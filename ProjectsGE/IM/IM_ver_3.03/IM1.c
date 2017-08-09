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
#define	CFG_TYPE_IM			IM->CFG.TYPE_IM
#define	CFG_TYPE_CMD			IM->CFG.TYPE_CMD
#define	CFG_PRIORITY_RU			IM->CFG.PRIORITY_RU
				
				
				
				
//�������				
#define	ST_Ver			IM->ST.Ver
#define	ST_Narab			IM->ST.Narab
#define	ST_FLT			IM->ST.FLT
#define	ST_RUs			IM->ST.RUs
#define	ST_Move			IM->ST.Move
#define	ST_DI_ON			IM->ST.DI_ON
#define	ST_DI_OF			IM->ST.DI_OF
#define	ST_DO_ON			IM->ST.DO_ON
#define	ST_DO_OF			IM->ST.DO_OF
				
				
//������				
#define	PS_FLT			IM->PS.FLT
#define	PS_M_Mufft			IM->PS.M_Mufft
#define	PS_notON			IM->PS.notON
#define	PS_notOF			IM->PS.notOF
#define	PS_SPON			IM->PS.SPON
#define	PS_SPOF			IM->PS.SPOF
#define	PS_KV_FLT			IM->PS.KV_FLT
#define	PS_KCU_ON_FLT			IM->PS.KCU_ON_FLT
#define	PS_KCU_OF_FLT			IM->PS.KCU_OF_FLT
#define	PS_notMove_ON			IM->PS.notMove_ON
#define	PS_notMove_OF			IM->PS.notMove_OF
#define	PS_ERR			IM->PS.ERR
				
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
#define	TMP_MR			IM->TMP.MR
#define	TMP_MB			IM->TMP.MB
#define	TMP_Open			IM->TMP.Open
#define	TMP_Close			IM->TMP.Close
#define	TMP_u_SPON			IM->TMP.u_SPON
#define	TMP_u_SPOF			IM->TMP.u_SPOF






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
T_BOOLEAN Rep_ON, Rep_OF, Tmax_ON, Tmax_OF, u_notMove_ON, u_notMove_OF, u_notON, u_notOF;
T_BOOLEAN Press_ON, Press_OF;

//������ ���������
ST_Ver = 3.02;
//����������� ���� ���������� ����������
TSCAN= *iTSCAN;

switch (CFG_TYPE_IM)
	{
	
	case 1: // 0x1
		DI_ON = DO_ON;
		DI_OF = !DI_ON;
		break;
	
	case 2: // 1x1
		DI_OF = !DI_ON;
		break;
	
	case 3: // 1x2
		DI_OF = !DI_ON;
		break;
	
	case 4: // 2x1
		
		break;
	
	case 5: // 2x2
		
		break;	
	}	//swith (CFG_TYPE)

//���� ������ ������� ��������������� ����������, �� ������ ������ ������� ����������
ALG_RU_Ban = Coil(AVT_ON || AVT_OF);

//���� ������ ������� ��������������� ����������, �� ��������� ������� � �������������� �����
if ((AVT_ON != TMP_AVT_ON) || (AVT_OF != TMP_AVT_OF))
	BTN_RU = 0;

//������� ���� ������� ������
ST_RUs = Coil(BTN_RU);
	
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
//Open = Coil((BTN_RU && TMP_MUpr) || (!BTN_RU && TMP_AUpr));


if (!TMP_AVT_ON || (AVT_ON && !AVT_OF)) 
	{
	// ���� (�������������� ����� � ���� ������� �������) ��� (������ ����� � ������ ������ �������)
	if ((!BTN_RU && AVT_ON) || (BTN_RU && BTN_ON))
		{
		TMP_Open = 1;
		TMP_Close = 0;
		}
	}

if (!TMP_AVT_OF || (AVT_OF && !AVT_ON))	
	{
	// ���� (�������������� ����� � ���� ������� �������) ��� (������ ����� � ������ ������ �������)
	if ((!BTN_RU && AVT_OF) || (BTN_RU && BTN_OF))
		{
		TMP_Open = 0;
		TMP_Close = 1;	
		}
	}

if (BTN_STOP && ST_RUs)
	{
	TMP_Open = 0;
	TMP_Close = 0;
	}
	
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
Rep_ON = Coil (TMP_T_Block_ON_EN && BTN_ON && (PS_notON || PS_notMove_ON || PS_SPOF));
// ������ ������� �������� ��������
Rep_OF = Coil (TMP_T_Block_OF_EN && BTN_OF && (PS_notOF || PS_notMove_OF || PS_SPON));	
	
//������������ ������� "����� ��������"
if (TMP_Open && !Rep_ON)	
	Tmax_ON = Timer(&TMP_T_Move_ON, CFG_T_Alarm);
else
	{
	Tmax_ON = 0;
	TMP_T_Move_ON = 0;	
	}		
	
//������������ ������� "����� ��������"
if (TMP_Close && !Rep_OF)	
	Tmax_OF = Timer(&TMP_T_Move_OF, CFG_T_Alarm);
else
	{
	Tmax_OF = 0;
	TMP_T_Move_OF = 0;	
	}			
	
// ������������ ������� ��� ������� "�� ����������� �� ��������"	
u_notMove_ON = Coil(TMP_Open && (TMP_T_Move_ON >= CFG_T_NotMove));
// ������������ ������� "�� ����������� �� ��������"
PS_notMove_ON = Coil(TMP_Open && DI_OF && u_notMove_ON);

// ������������ ������� ��� ������� "�� ����������� �� ��������"	
u_notMove_OF = Coil(TMP_Close && (TMP_T_Move_OF >= CFG_T_NotMove));
// ������������ ������� "�� ����������� �� ��������"
PS_notMove_OF = Coil(TMP_Close && DI_ON && u_notMove_OF);
	
	
// ������������ ������� ��� ������� "�� ������"		
u_notON	= Coil(TMP_Open && (TMP_T_Move_ON >= CFG_T_NotCO));
// ������������ ������� "�� ������"		
PS_notON = Coil(TMP_Open && !DI_ON && u_notON && !PS_SPOF);

// ������������ ������� ��� ������� "�� ������"		
u_notOF	= Coil(TMP_Close && (TMP_T_Move_OF >= CFG_T_NotCO));
// ������������ ������� "�� ������"		
PS_notOF = Coil(TMP_Close && !DI_OF && u_notOF && !PS_SPON);	
	
// ����� �� ��������	
if (TMP_Open && DI_ON)	
	TMP_T_Press_ON_EN = Timer(&TMP_T_Press_ON, CFG_T_Press);
else
	{
	TMP_T_Press_ON_EN = 0;
	TMP_T_Press_ON = 0;	
	}	
Press_ON = Coil(TMP_T_Press_ON_EN);

// ����� �� ��������	
if (TMP_Close && DI_OF)	
	TMP_T_Press_OF_EN = Timer(&TMP_T_Press_OF, CFG_T_Press);
else
	{
	TMP_T_Press_OF_EN = 0;
	TMP_T_Press_OF = 0;	
	}	
Press_OF = Coil(TMP_T_Press_OF_EN);	
	
//������������ ������� ��� ������� "���������������� ��������"		
if (TMP_Open && Press_ON && Tmax_ON) 
	TMP_u_SPOF = 1;
//������ ������� ��� ������� "���������������� ��������"	
if (TMP_Close)	
	TMP_u_SPOF = 0; 
//������������ ������� "���������������� ��������"		
PS_SPOF	= Coil(TMP_Open && !DI_ON && TMP_u_SPOF);
	
//������������ ������� ��� ������� "���������������� ��������"		
if (TMP_Close && Press_OF && Tmax_OF) 
	TMP_u_SPON = 1;
//������ ������� ��� ������� "���������������� ��������"	
if (TMP_Open)	
	TMP_u_SPON = 0; 
//������������ ������� "���������������� ��������"		
PS_SPON	= Coil(TMP_Close && !DI_OF && TMP_u_SPON);
	
//������� 
DO_ON = Coil(TMP_Open && !Press_ON && !Tmax_ON && !ALG_DO_Ban);

//������� 
DO_OF = Coil(TMP_Close && !Press_OF && !Tmax_OF && !ALG_DO_Ban);

	

//�������� ����������� ����������
//���� ������������ ��� ��������� � 1 �� ����
if (DI_ON && DI_OF)
	PS_KV_FLT= 1;
//����� ��� �����
else
	PS_KV_FLT= 0;


//�������� ����� ���������� ��������
//���� ��� �������� ��� �� ����� ������� ������ � 1
if (CFG_TYPE_KCU)
	//���� ��� �� ����� ��� 1
	if (!DI_KCU_ON)
		//��������� ������ � ������ ����
		PS_KCU_ON_FLT= Timer(&TMP_T_KCU_ON, CFG_T_KCU);
	else
		{
		//����� ����� ����� � �������
		PS_KCU_ON_FLT= 0;
		TMP_T_KCU_ON = 0;
		}
//���� ��� �������� ��� �� ����� � �������� DI = 0 ��� DO =1 � DI = 1 ��� DO =0
else
	// ���� DI = 0 ��� DO =1 ��� DI = 1 ��� DO = 0
	if ((DI_KCU_ON && DO_ON) || (!DI_KCU_ON && !DO_ON && !DO_OF))
		PS_KCU_ON_FLT= Timer(&TMP_T_KCU_ON, CFG_T_KCU);
	else
		{
		PS_KCU_ON_FLT= 0;
		TMP_T_KCU_ON = 0;
		}

//�������� ����� ���������� ��������
//���� ��� �������� ��� �� ����� ������� ������ � 1
if (CFG_TYPE_KCU)
	//���� ��� �� ����� ��� 1
	if (!DI_KCU_OF)
		//��������� ������ � ������ ����
		PS_KCU_OF_FLT= Timer(&TMP_T_KCU_OF, CFG_T_KCU);
	else
		{
		//����� ����� �����
		PS_KCU_OF_FLT= 0;
		TMP_T_KCU_OF = 0;
		}
//���� ��� �������� ��� �� ����� � �������� DI = 0 ��� DO =1 � DI = 1 ��� DO =0
else
	// ���� DI = 0 ��� DO =1 ��� DI = 1 ��� DO = 0
	if ((DI_KCU_OF && DO_OF) || (!DI_KCU_OF && !DO_OF && !DO_ON))
		PS_KCU_OF_FLT= Timer(&TMP_T_KCU_OF, CFG_T_KCU);
	else
		{
		PS_KCU_OF_FLT= 0;
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
if (PS_notMove_ON || PS_notMove_OF || PS_KCU_ON_FLT || PS_KCU_OF_FLT || 
	PS_notON || PS_notOF || PS_M_Mufft || PS_SPON || PS_SPOF || PS_KV_FLT)
		{
		ST_FLT = 1;
		PS_FLT = 1;
		}
else
		{
		ST_FLT = 0;
		PS_FLT = 0;
		}
		
//���������� ������� �������� �����
TMP_AVT_ON = Coil(AVT_ON);
TMP_AVT_OF = Coil(AVT_OF);
}
