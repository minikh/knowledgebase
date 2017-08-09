#include "math.h"     // �������������� �������
#include "PACRXPlc.h" //��������� ��� �����������
#include "Structs.h"  //���������
#include "defvars.h"; 

float TSCAN;
	

///******************************************* Timer ***************************************************
//	������ 
// *Time ������� ����� �������
// Ust ������� �������
// EN ������ �������
T_BOOLEAN Timer(T_REAL32 *Time, T_REAL32 Ust, T_BOOLEAN EN)
{
T_BOOLEAN out;
//���� ������ �������, �� �������
if (EN)
	{
	//���� ������� ����� ������ �������, ��
	if (*Time < Ust) 
		{
		//����� ������� � 0
		out= 0;
		//��������� ������� ����� �� ����� �����
		*Time += TSCAN;
		}
	//���� ������� ����� ������ �������, �� ����� ������� � 1
	else
		out= 1;	
	}
//���� ������ ��������, �� 
else
	{
	//����� ������� = 0
	*Time = 0;
	//������� ����� = 0
	out = 0;
	}
return out;
}


///******************************************* main ***************************************************
void GefMain(IM, iTSCAN, ON_IMIT)
IM_STR *IM;
T_REAL32 *iTSCAN;
T_WORD *ON_IMIT;

{

T_BOOLEAN Rep_ON, Rep_OF, Tmax_ON, Tmax_OF, u_notMove_ON, u_notMove_OF, u_notON, u_notOF;
T_BOOLEAN IM_0_1 = 0, IM_1_1 = 0, IM_c1_1 = 0, IM_1_2 = 0, IM_c1_2 = 0, IM_2_1 = 0, IM_2_2 = 0;

//������ ���������
ST_Ver = 3.08;

//�������� ��� ��������� ��������� �� ����� � ���������
ALG_ON_IMIT = *ON_IMIT;

//����� ������� ������
PS_ERR[0] = 0;
PS_ERR[1] = 0;

//--------------- ������ ���������������� ------------------------------------
//�������� ������� "����� ����� ������� ��������� ������" (T_Block) ����
if (CFG_T_Block == 0) 
	PS_ERR[0] |= (1<<1);
	
//�������� ������� "����� �������� ����� ����������" (T_KCU) �� ���������
if ((CFG_T_KCU == 0) || (CFG_T_KCU > CFG_T_NotCO) ||(CFG_T_KCU > CFG_T_Alarm))
	PS_ERR[0] |= (1<<2);

//�������� ������� "����� ������������ ������� "�������������" (T_NotMove) �� ���������
if ((CFG_T_NotMove == 0) || (CFG_T_NotMove > CFG_T_NotCO) || (CFG_T_NotMove > CFG_T_Alarm))
	PS_ERR[0] |= (1<<3);
	
//�������� ������� "����� ������������ �������� "�� ������, �� ������" (T_NotCO) �� ���������
if ((CFG_T_NotCO == 0) || (CFG_T_NotCO < CFG_T_NotMove) || (CFG_T_NotCO > CFG_T_Alarm))
	PS_ERR[0] |= (1<<4);

//�������� ������� ������� �� ������������ (T_Alarm) ����
if ((CFG_T_Alarm == 0) || (CFG_T_Alarm < CFG_T_NotCO) || (CFG_T_Alarm < CFG_T_NotMove) || (CFG_T_Alarm < CFG_T_KCU))
	PS_ERR[0] |= (1<<5);
	
// ------------------------------------------------------------------------------	
//���� ���� �������, �� 	
if (!CFG_Disable)
	{
	//����������� ���� ���������� ����������
	TSCAN= *iTSCAN;
	
	

	ST_TYPE_IM = CFG_TYPE_IM;
	switch (CFG_TYPE_IM)
		{
		case 1: // 0x1
			//��������� ���������
			DI_ON = DO_ON;
			DI_OF = !DI_ON;
			IM_0_1 = 1;
			break;
		
		case 2: // 1x1	(�������� - �������)
			//��������� �������� �������
			DI_OF = !DI_ON;
			IM_1_1 = 1;
			break;

		case 3: // c1x1 (�������� - �������)
			//��������� �������� �������
			DI_ON = !DI_OF;
			IM_c1_1 = 1;
			break;

		case 4: // 1x2	(�������� - �������)
			//��������� �������� �������
			DI_OF = !DI_ON;
			IM_1_2 = 1;
			break;
		
		case 5: // �1x2 (�������� - �������)
			//��������� �������� �������
			DI_ON = !DI_OF;
			IM_c1_2 = 1;
			break;

		case 6: // 2x1	
			IM_2_1 = 1;
			break;
		
		case 7: // 2x2
			IM_2_2 = 1;
			break;	
		default:
			//��������� ��� "�� ������ ��� �����" 
			//IM->PS.ERR[0] |= (1);
			PS_ERR[0] |= (1);
		}	//swith (CFG_TYPE)

		
	//�������� ����������� ����������
	//���� (��� ��� � ������������ ��� ��������� � 1) ��� (��� � ������������ ��� ��������� � 0 � ��� �� � 2-�� �����������) �� ����
	if ((!CFG_MUK && DI_ON && DI_OF) || (CFG_MUK && !DI_ON && !DI_OF && (IM_2_1 || IM_2_2)))
		PS_KV_FLT= 1;
	//����� ��� �����
	else
		PS_KV_FLT= 0;	
		
	//���� ������ ������� ��������������� ����������, �� ������ ������ ������� ����������
	if (AVT_ON || AVT_OF)
		ALG_RU_Ban = 1;
	//���� ���� ������� ��������������� ����������, �� ������� ������ ������� ����������
	if ((!AVT_ON && TMP_AVT_ON) || (!AVT_OF && TMP_AVT_OF))
		ALG_RU_Ban = 0;

	//���� ������ ������� ��������������� ���������� ��� ���� ������ ������� ����������, �� ��������� ������� � �������������� �����
	if ((AVT_ON != TMP_AVT_ON) || (AVT_OF != TMP_AVT_OF) || ALG_RU_Ban)
		BTN_RU = 0;
		
	//���� ��������� ������������ � �������������� ����� ��� ������� �� ��������� ���������������
	if ((!BTN_RU && ST_RUs && !CFG_PRIORITY_RU) || (!BTN_RU && !CFG_PRIORITY_RU&& TMP_PRIORITY_RU))
		{
		//�� ��������� � ��������� ������� ���� �� �������� � ������
		TMP_Open = TMP_AUpr;
		TMP_Close = !TMP_AUpr;
		}
		
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


	if (!TMP_AVT_ON 
					|| (AVT_ON && !AVT_OF)) //��������� ��������� �������
		{
		// ���� (�������������� ����� � ���� ������� �������) ��� (������ ����� � ������ ������ �������)
		if ((!BTN_RU && AVT_ON) || (BTN_RU && BTN_ON))
			{
			TMP_Open = 1;
			TMP_Close = 0;
			}
		}

	if (!TMP_AVT_OF 
					|| (AVT_OF && !AVT_ON))	 //��������� ��������� �������
		{
		// ���� (�������������� ����� � ���� ������� �������) ��� (������ ����� � ������ ������ �������)
		if ((!BTN_RU && AVT_OF) || (BTN_RU && BTN_OF))
			{
			TMP_Open = 0;
			TMP_Close = 1;	
			}
		}

	//������� "����"
	if (BTN_STOP && BTN_RU && (IM_1_2 || IM_c1_2 || IM_2_2))
		{
		TMP_Open = 0;
		TMP_Close = 0;
		}
		
	//������ ������� ������� ��������
	TMP_T_Block_ON_EN = Timer(&TMP_T_Block_ON, CFG_T_Block, !DO_ON);

		
	//������ ������� ������� ��������
	TMP_T_Block_OF_EN = Timer(&TMP_T_Block_OF, CFG_T_Block, !DO_OF);


	// ������ ������� �������� ��������
	Rep_ON = TMP_T_Block_ON_EN && BTN_ON && (PS_notON || PS_notMove_ON || PS_SPOF);
	// ������ ������� �������� ��������
	Rep_OF = TMP_T_Block_OF_EN && BTN_OF && (PS_notOF || PS_notMove_OF || PS_SPON);	
		
	//������������ ������� "����� ��������"
	Tmax_ON = Timer(&TMP_T_Move_ON, CFG_T_Alarm, TMP_Open && !Rep_ON);
		
	//������������ ������� "����� ��������"
	Tmax_OF = Timer(&TMP_T_Move_OF, CFG_T_Alarm, TMP_Close && !Rep_OF);
		
	// ������������ ������� ��� ������� "�� ����������� �� ��������"	
	u_notMove_ON = TMP_Open && !PS_FLT && !DI_ON && (TMP_T_Move_ON >= CFG_T_NotMove);
	// ������������ ������� "�� ����������� �� ��������"
	PS_notMove_ON = DI_OF && u_notMove_ON;

	// ������������ ������� ��� ������� "�� ����������� �� ��������"	
	u_notMove_OF = TMP_Close && !PS_FLT && !DI_OF && (TMP_T_Move_OF >= CFG_T_NotMove);
	// ������������ ������� "�� ����������� �� ��������"
	PS_notMove_OF = DI_ON && u_notMove_OF;
		
		
	// ������������ ������� ��� ������� "�� ������"		
	u_notON	= TMP_Open && (TMP_T_Move_ON >= CFG_T_NotCO);
	// ������������ ������� "�� ������"		
	PS_notON = TMP_Open && !DI_ON && u_notON && !PS_SPOF;

	// ������������ ������� ��� ������� "�� ������"		
	u_notOF	= TMP_Close && (TMP_T_Move_OF >= CFG_T_NotCO);
	// ������������ ������� "�� ������"		
	PS_notOF = TMP_Close && !DI_OF && u_notOF && !PS_SPON;	
		
	// ����� �� ��������	
	TMP_T_Press_ON_EN = Timer(&TMP_T_Press_ON, CFG_T_Press, TMP_Open && DI_ON);

	// ����� �� ��������	
	TMP_T_Press_OF_EN = Timer(&TMP_T_Press_OF, CFG_T_Press, TMP_Close && DI_OF);
		
	//������������ ������� ��� ������� "���������������� ��������"		
	if (TMP_Open && TMP_T_Press_ON_EN && Tmax_ON) 
		TMP_u_SPOF = 1;
	//������ ������� ��� ������� "���������������� ��������"	
	if (TMP_Close)	
		TMP_u_SPOF = 0; 
	//������������ ������� "���������������� ��������"		
	PS_SPOF	= TMP_Open && !DI_ON && TMP_u_SPOF;
		
	//������������ ������� ��� ������� "���������������� ��������"		
	if (TMP_Close && TMP_T_Press_OF_EN && Tmax_OF) 
		TMP_u_SPON = 1;
	//������ ������� ��� ������� "���������������� ��������"	
	if (TMP_Open)	
		TMP_u_SPON = 0; 
	//������������ ������� "���������������� ��������"		
	PS_SPON	= TMP_Close && !DI_OF && TMP_u_SPON;
		
	
	if (IM_2_1 || IM_1_1 || IM_0_1 || IM_c1_1)
		{
		TMP_T_Press_ON_EN = 0;
		Tmax_ON = 0;
		}
	
	//������� 	
	DO_ON = !ALG_DO_Ban && TMP_Open && !TMP_T_Press_ON_EN && !Tmax_ON;
	//���������� ��������������� ������ ��� ��������
	TMP_T_Force_ON_EN = Timer(&TMP_T_Force_ON, CFG_T_Force, CFG_ONForceEN && DO_ON);
	DO_ONForce = !TMP_T_Force_ON_EN && CFG_ONForceEN && DO_ON;
		
		
	//������� 
	DO_OF = !ALG_DO_Ban && TMP_Close && !TMP_T_Press_OF_EN && !Tmax_OF;
	//���������� ��������������� ������ ��� ��������
	TMP_T_Force_OF_EN = Timer(&TMP_T_Force_OF, CFG_T_Force, CFG_OFForceEN && DO_OF);
	DO_OFForce = !TMP_T_Force_OF_EN && CFG_OFForceEN && DO_OF;

		
	//�������� ����� ���������� ��������
	//���� ������� �������� ����� �������� � ��� �� � ���������� "������", ��
	if (CFG_KCU_ON_EN && (IM_1_1 || IM_1_2 || IM_2_1 || IM_2_2))
		{
		//���� ��� �������� ��� �� ����� ������� ������ � 1
		if (CFG_TYPE_KCU)
			//���� ��� �� ����� ��� 1
			//��������� ������ � ������ ����
			PS_KCU_ON_FLT= Timer(&TMP_T_KCU_ON, CFG_T_KCU, !DI_KCU_ON);

		//���� ��� �������� ��� �� ����� � �������� DI = 0 ��� DO =1 � DI = 1 ��� DO =0
		else
			// ���� DI = 0 ��� DO =1 ��� DI = 1 ��� DO = 0
			PS_KCU_ON_FLT= Timer(&TMP_T_KCU_ON, CFG_T_KCU, (DI_KCU_ON && DO_ON) || (!DI_KCU_ON && !DO_ON && !DO_OF));
		}
	else
		//���� �������� �������� ����� ��������, �� ����� ��
		PS_KCU_ON_FLT= 0;


	//�������� ����� ���������� ��������
	//���� ������� �������� ����� �������� � ��� �� � ���������� "������", ��
	if (CFG_KCU_OF_EN && (IM_c1_1 || IM_c1_2 || IM_2_1 || IM_2_2))
		{
		//���� ��� �������� ��� �� ����� ������� ������ � 1
		if (CFG_TYPE_KCU)
			//���� ��� �� ����� ��� 1
			//��������� ������ � ������ ����
			PS_KCU_OF_FLT= Timer(&TMP_T_KCU_OF, CFG_T_KCU, !DI_KCU_OF);

		//���� ��� �������� ��� �� ����� � �������� DI = 0 ��� DO =1 � DI = 1 ��� DO =0
		else
			// ���� DI = 0 ��� DO =1 ��� DI = 1 ��� DO = 0
			PS_KCU_OF_FLT= Timer(&TMP_T_KCU_OF, CFG_T_KCU, (DI_KCU_OF && DO_OF) || (!DI_KCU_OF && !DO_OF && !DO_ON));
		}
	else
		//���� �������� �������� ����� ��������, �� ����� ��
		PS_KCU_OF_FLT= 0;


	// ---------------------------------------------------- �������� ----------------------------------------

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
		//���� ���� ������� �������, �� ��������� ������ 
		TMP_T_Imit_ON_EN= Timer(&TMP_T_Imit_ON, CFG_T_Imit, DO_ON);

			
		//���� ���� ������� �������, �� ��������� ������ 
		TMP_T_Imit_OF_EN= Timer(&TMP_T_Imit_OF, CFG_T_Imit, DO_OF);

		//���� ���������
		if (DO_ON)
			{
			//����������� ��� �������� ���� 
			if (!CFG_TYPE_KCU) 
				DI_KCU_ON= 0;
				
			//���� ����� ������ 0,5 ���, �� ����� �������� "������"
			if (TMP_T_Imit_ON >= 0.5)
				DI_OF= 0;
			
			//���� ����� �����, �� �������� �������� "������"
			if (TMP_T_Imit_ON_EN) 
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
			if (TMP_T_Imit_OF >= 0.5)
				DI_ON= 0;

			//���� ����� �����, �� �������� �������� "������"
			if (TMP_T_Imit_OF_EN)
				DI_OF= 1;
			}
		else
			//����������� ��� �������� ���� ���� �� ���������
			DI_KCU_OF= 1;
			
		} //if (ALG_ON_IMIT) 
		
		//���������� ������� �������� 
		
		

			
	//���������
	if (DI_ON)		
		{
		ST_Narab += (TSCAN / 3600);
		//���������
		if (!TMP_DI_ON)
			ST_Num ++;
		}
		
	//����� ���������	
	if (CFG_NarabReset)
		{
		ST_Narab = 0;
		ST_Num = 0;
		CFG_NarabReset = 0;
		}
	
	//���
	PS_M_Mufft = DI_M_Mufft;
	PS_Vibr = DI_Vibr;
	PS_Loil = DI_Loil;
	PS_U_OF = DI_U_OF;
	PS_Poil = DI_Poil;
		
	//���������� ������� �������� �����
	TMP_AVT_ON = AVT_ON;
	TMP_AVT_OF = AVT_OF;
	TMP_ON_IMIT = ALG_ON_IMIT;
	TMP_DI_ON = DI_ON;
	TMP_PRIORITY_RU = CFG_PRIORITY_RU;
}
//���� ���� ��������, �� ������� ��� �������
else //if (CFG_Disable)
	{
	if (ALG_ON_IMIT)
		{
		DI_ON = 0; DI_OF = 0; 
		}
	DO_ON = 0; DO_OF = 0;
	PS_notMove_ON = 0; PS_notMove_OF = 0; PS_KCU_ON_FLT = 0; PS_KCU_OF_FLT = 0;
	PS_notON = 0; PS_notOF = 0; PS_M_Mufft = 0; PS_SPON =0; PS_SPOF = 0; PS_KV_FLT = 0;
	}
	
//���������� ������ ������
if (PS_notMove_ON || PS_notMove_OF || PS_KCU_ON_FLT || PS_KCU_OF_FLT || 
	PS_notON || PS_notOF || PS_M_Mufft || PS_SPON || PS_SPOF || PS_KV_FLT ||
	PS_Vibr || PS_Loil || PS_U_OF || PS_Poil || (PS_ERR[0]>0) || (PS_ERR[1]>0))
		PS_FLT = 1;
else
		PS_FLT = 0;

//���� ��� �� � ����� �������, �� ��������� ������ �����
if (IM_2_1 || IM_1_1 || IM_0_1 || IM_c1_1) 
	DO_OF = 0;	// ---------------------------------------		
		
//��� HMI
ST_DI_ON = DI_ON;
ST_DI_OF = DI_OF;
ST_FLT = PS_FLT;
ST_DO_ON = DO_ON;
ST_DO_OF = DO_OF;
ST_RU_Ban = ALG_RU_Ban;
//������� ���� ������� ������
ST_RUs = BTN_RU;
//����������� ���������
ST_Move = (!CFG_MUK && !DI_ON && !DI_OF) || (CFG_MUK && DI_ON && DI_OF) || DI_Move;

//����� ������
BTN_OF = 0;
BTN_ON = 0;
BTN_STOP = 0;


}
