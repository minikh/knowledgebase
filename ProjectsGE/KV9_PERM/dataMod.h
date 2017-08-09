//dataMod.h - ���� �������� � ��������������� ��� ������

// ��������� � ������� #define ���_��������� ��������_��������� //����������

#define VNA_DZ 0.2  // ���� ������������������ ������� ���, %
#define VNA_RATE 100.0  // �������� ��������� ������� ���, %/�
#define DUS_DZ 0.02  // ���� ������������������ ������� ���, ��
#define DUS_RATE 64.0  // �������� ��������� ������� ���, ��/�
#define J_N 0.161  // ������ ������� ��������
#define J_ST 2.23  // ������ ������� ��
#define POW_COEFF 0.0001  // ����������� ��� ���������� �������� ��������
#define afterBrkTime 0.5  // ����� �������������� ������ ����� ������
#define TtzapMax 1073.0  // �������� ��� ���������� ������� ���(��� ������������� �� ��), � �
#define maxDeltaTtStart 240.0  // ������� ��� ������������� �������� ������� Tt���, ��.����
#define minValTtStart -50.0  // ����������� ����� ��� ����������� �������� �� �������, ��.����
#define minValTtStartFire 60.0  // ����������� ����� ��� ����������� �������� ����� �������, ��.����
#define maxValTtStart 500.0  // ������������ ����� ��� ����������� �������� �� �������, ��.����
#define maxValTtStartFire 1200.0  // ������������ ����� ��� ����������� �������� ����� �������, ��.����
#define Ngg_MG 9440.0  // �������� ��� ���������� ������� �������� ������ ���
#define deltaNvdLow 300.0  // ��������� �������� ������� ���� �� 
#define Ngg_Max 10850.0  // �������� ��� ���������� ������� ������������ �������� ��
#define Ngg_Max_pr 11800.0  // �������� ��� ���������� ������� ������������ �������� ��
#define deltaNvd 200.0  // ���������� ��� ����. ��������� �� ��� ������
#define minValNvd 100.0  // ����������� Nvd ��� ����������� �������� ����� NvdTimerContr ����� �� ���, ��.����
#define minValNvdFire 1600.0  // ����������� Nvd ��� ����������� �������� ����� �������, ��.����
#define maxValNvd 13000.0  // ������������ Nvd ��� ����������� ��������, ��.����
#define maxDeltaNvd 240.0  // ������� ��� ������������� �������� ������� �������� ��
#define maxDeltaNvdTmp 500.0  // ������� ��� ��������� �������� ������� �������� ��
#define PkContr 0.16  // ���-�� ��, ���� ������� �������� ������������ � �������� ��������  Ngg, � ��� 
#define NvdTimerContr 25.0  // ���-�� ������� �������(����� �� ���), � ������� �������� min-� ���������� Ngg, ��� 
#define NstMax 7000.0  // ������� ��� ���������� ����������� �� ������������ �������� ��
#define deltaNst 200.0  // ���������� ��� ������������ ����. �������� �� ��� ��������������
#define NstAlarm 7500.0  // ��������-������� ������� �� (���������)
#define minValNst 100.0  // ����������� Nst ��� ����������� �������� ��� nvd>NvdContr, ��.����
#define minValNst1 1300.0  // ����������� Nst ��� ����������� �������� ��� nvd>NvdContr1, ��.����
#define maxValNst 9000.0  // ������������ Nst ��� ����������� ��������, ��.����
#define maxDeltaNst 240.0  // ������� ��� ������������� �������� ������� �������� ��
#define maxDeltaNstTmp 500.0  // ������� ��� ��������� �������� ������� �������� ��
#define NvdContr 5000.0  // ���-�� Nvd, ���� ������� �������� min-�, ������������ � �������� ��������  Nst 
#define NvdContr1 8000.0  // ���-�� Nvd, ���� ������� �������� ������ ����������� ���������� ��������  Nst 
#define Pk_ogr_max 1.83  // ������� ����������� �������� ������� �� ��� "������������ �����" � ���
#define Pk_ogr_nom 1.65  // ������� ����������� �������� ������� �� ��� "������������ �����" � ���
#define Pk_ogr_Alarm 2.2  // �������������� �� �������� ������� �� ���  � ���
#define TtMax 1011.0  // �������� ��� ���������� ������� ������������ �� �� ������, � �
#define DeltaTt1 30.0  // ���������� ��� ������������ �� ����. ��� ��������������
#define DeltaTt2 50.0  // ���������� ��� ������������ �� ����. ��� ���������� ��
#define DeltaTt3 60.0  // ���������� ��� ������������ �� ����. ��� ��
#define distortTtBrk 250.0  // ���������� �� �������� �������� �� ��� ���������� ��������, ��.����
#define minValTt -50.0  // ����������� �� ��� ����������� �������� �� �������, ��.����
#define minValTtFire 60.0  // ����������� �� ��� ����������� �������� ����� �������, ��.����
#define maxValTt 700.0  // ������������ �� ��� ����������� �������� �� �������, ��.����
#define maxValTtFire 1200.0  // ������������ �� ��� ����������� �������� ����� �������, ��.����
#define TstMax 817.0  // �������� ��� ���������� ������� ������������ ��� �� ������, �
#define DeltaTst1 15.0  // ���������� ��� ��� ����. ��� ��������������
#define DeltaTst2 25.0  // ���������� ��� ��� ����. ��� ���������� ��
#define DeltaTst3 30.0  // ���������� ��� ��� ����. ��� ��
#define distortTstBrk 50.0  // ���������� �� �������� �������� ��� ��� ���������� ��������
#define minValTst -50.0  // ����������� ��� ��� ����������� ��������, ��.����
#define maxValTst 650.0  // ������������ ��� ��� ����������� ��������, ��.����
#define minValTvh 223.0  // ����������� ��� ��� ����������� ��������, �
#define maxValTvh 323.0  // ������������ ��� ��� ����������� ��������, �
#define minValPk -0.05  // ����������� �� ��� ����������� ��������, ���
#define maxValPk 2.55  // ������������ �� ��� ����������� ��������, ���
#define minValPtgPdSk -0.05  // ����������� PtgPd, PtgSk ��� ����������� ��������, ���
#define maxValPtgPdSk 4.0  // ������������ �tg ��� ����������� ��������, ���
#define PtgAlarm 3.5  // ��������-������� �������� ���������� ���� ����� ��, ���
#define PtgMax 3.4  // ������� �������� ���������� ���� ����� ��, ���
#define PtgHigh 3.2  // ���������� �������� ���������� ���� ����� ��, ���
#define PtgLow 2.75  // ���������� �������� ���������� ���� ����� ��, ���
#define PtgMin 2.5  // ������ �������� ���������� ���� ����� ��, ���
#define PtgMinLim 2.0  // ��������-������ �������� ���������� ���� ����� ��, ���
#define PtgpdUTtgKS 0.59  // �������� ���������� ���� ����� �� ��� �������� ������
#define PosDGUTtgKS 1.0  // ��������� �������� ���� ��� �������� ������
#define TtgpdLow 0.0  // ���������� ����������� ���������� ���� ����� ��, C
#define TtgpdHigh 70.0  // ���������� ����������� ���������� ���� ����� ��, �
#define minValVNA -52.0  // ����������� �������� ��������� ��� ��� ����������� ��������, ����
#define maxValVNA 2.0  // ������������ �������� ��������� ��� ��� ����������� ��������, ����
#define DeltaVNAHigh 20.0  // ������������ ��������������� ��� � �������� �����
#define DeltaVNALow -7.0  // ������������ ��������������� ��� � �������� ����
#define nGGcontrVNA 4000.0  // �������, ���� ������� �������������� �������� ���
#define minValDUS -0.5  // ����������� �������� ��������� ��� ��� ����������� ��������, %
#define maxValDUS 100.0  // ������������ �������� ��������� ��� ��� ����������� ��������, %
#define maxDeltaDUS 6.0  // ����. ��������������� ��� � ��������, %
#define deltaNstSTBrk -75.0  // ������� ������� �������� ��� ����������� ������������� ��(�� 0.5  ���)
#define deltaTstSTBrk 50.0  // ������� ����� ����������� ��� ����������� ������������� ��(�� 0.5  ���)
#define NggSTBrk 9700.0  // ������� �� ��������� ������ "������������� ��"
#define PsuflHigh 40.0  // ���������� �������� ������������, ���
#define PsuflLim 50.0  // ������� �������� ������������, ���
#define nGGsuflcontr 8000.0  // ������� ��, ������� � ������� ������������� �������� ������������
#define nGGdeltaPvxcontr 9000.0  // ������� ��, ������� � ������� ������������� ������� ����� ����������
#define deltaPvxHigh 1.5  // ���������� ������� �������� �� ����� � ���������, ���
#define deltaPvxLim 2.0  // ������� ����� ��������� �������, ���
#define nGGPrpk 10000.0  // ������� ��, ������� � ������� ������������� �������� � ������������ ������� �����������
#define distortTtMax 100.0  // ������������ ��������������� ���� ��
#define distortTstMax 100.0  // ������������ ��������������� ���� ���
#define maxFST 0.256  // ������������ ������ ���� ��
#define NggmaxFST 10400.0  // ������� ��, ������� � ������� ������������� ���������� ������ ���� ��
#define NggTemperVal 8000.0  // ������� ��, ������� � ������� ������������� �� ���. (���� - � ���.)
#define maxPtgInGTU 5.9  // �����������-���������� �������� �� �� ����� ��� ��� �������� �� (�������� ������)
#define GGVybegHigh 1100.0  // ������� ������� �������� �� ��� �������� ������
#define GGVybegLow 100.0  // ������ ������� �������� �� ��� �������� ������
#define stopTimeGGHPMin 80.0  // ����������� ����� ������ �� ����� ��
#define stopTimeGGMin 100.0  // ����������-���������� ����� ������ ��
#define STVybegHigh 1100.0  // ������� ������� �������� �� ��� �������� ������
#define STVybegLow 100.0  // ������ ������� �������� �� ��� �������� ������
#define stopTimeSTMin 50.0  // ����������� ����� ������ ��
#define maxStartTime 310.0  // �����������-���������� ����� �������
#define nGGcontrKPV 6000.0  // �������, ���� ������� �������������� �������� ���
#define nvdOpenKPV 9450.0  // ��������� �������� �������� ���
#define nvdCloseKPV 9600.0  // ��������� �������� �������� ���
#define nvdOpenKPG 7900.0  // ��������� �������� �������� ����-���
#define nvdCloseKPG 8100.0  // ��������� �������� �������� ����-���
#define nvdCloseLow 1600.0  // ��������� ������ ������� ������� ��������, ���� ������� ����������� ��� �������
#define dTIgnition 70.0  // ���� �����������, �� �������� ������������ ���� �������
#define dNgg_SBROS -150.0  // �������� �������� �������� ��� �������� �� ���������� ��� ��
#define dNgg_UP 30.0  // �������� ��������� �������� ��� �������  ������ "������"
#define dNgg_DOWN -30.0  // �������� ��������� �������� ��� �������  ������ "������ "
#define HeatTime 120.0  // ����� �������� �� ����� ����
#define CoolTime 300.0  // ����� ���������� �� ����� ����
#define HPTime 60.5  // ����� ���������� �� (�� �� ���)
#define HPTimeHP 110.5  // ����� ���������� �� (�� �� ���) �� �������� ���������
#define PromTime 200.5  // ����� ���������� �������� (�� �� ���) 
#define FireTime 65.0  // ����� �������� � ������� ��� ��������� �� ��������
#define fireNgg 1600.0  // ������� �������� � ������� ��� ��������� �� ��������
#define ignitionTime 60.0  // ����� ��������� �� ��� ��������� �� ��������
#define NggIgnOff 4000.0  // ������� ���������� �� ��� �����
#define timeIgnitionOff 22.0  // ����� ������ �� �� �������
#define RateGG 6000.0  // ������� ��������� �� ���� ������� ������������ ������� �� 150 ���
#define NggStarterOff 7800.0  // ������� ���������� �������� ��� �����
#define NggGotovHPZP 100.0  // ������� ��� ������������ ����������� � �� ��� �������
#define timeStarterOff 165.0  // ����� ���������� �������� �� �����
#define longTime 230.0  // ����� ���������� ������� �������� ��� ������� ��������� �� ������� �������
#define longTimeHP 200.0  // ����� ���������� ������� �������� ��� ������� ��������� �� �������� ���������
#define maxFireTime 17.0  // ������������ �����, � ������� �������� ����������� ������.
#define Gt_roz_min 0.0  // ����������� ������ �� �������
#define Gt_roz_max 350.0  // ������������ ������ �� �������
#define Cycl_roz 1.0  // ���������� ������ ��������� ������� �� Gt_roZ_min �� Gt_roZ_max �� ������� (����� ���� 1 ��� 2). �������� =0 �������� ��� ��������� ������� �� ��������� =Gt_roZ + R_Gt_roZ
#define Gt_roz 220.0  // �������� ������� �� �������
#define GT_max 3000.0  // ������������ ������
#define KfNvd 0.3  // ����������� ������������ � ������� ���
#define Kp_st 0.05  // ����������� ������������������ �������  Nst
#define KpTt 0.25  // ����������� ������������������ �������  Tt
#define KpTst 0.25  // ����������� ������������������ �������  Tst
#define KpPk 400.0  // ����������� ������������������ ������� Pk
#define Kd_st 0.1  // 3
#define K1st 0.5  // 
#define K2st 1.0  // 
#define K3st 0.03  // 
#define PtgHarDoz 2.35  // �������� ��� ������ ���������� �������������� �������� (���)
#define Delta_doz 0.02  // 
#define TmvhDLow 0.0  // ������ ����������� ����� �� ����� � ���������, C
#define TmvhDHigh 65.0  // ������� ����������� ����� �� ����� � ���������, �
#define TmspKvdContr 8000.0  // ���-�� Nvd ��� �������� ����������� ����� �� ������ �� ����� �/� ���
#define TmspKvdHigh 127.0  // ���������� ����������� ����� �� ������ �� ����� �/� ���
#define TmspKvdMax 137.0  // ������� ����������� ����� �� ������ �� ����� �/� ���
#define TmspKvdAlarm 147.0  // ��������-������� ����������� ����� �� ������ �� ����� �/� ���
#define TmrpTvdContr 8000.0  // ���-�� Nvd ��� �������� ����������� ����� �� ������ �� ����� �/� ���
#define TmrpTvdHigh 132.0  // ���������� ����������� ����� �� ������ �� ����� �/� ���
#define TmrpTvdMax 142.0  // ������� ����������� ����� �� ������ �� ����� �/� ���
#define TmrpTvdAlarm 147.0  // ��������-������� ����������� ����� �� ������ �� ����� �/� ���
#define TmopStContr 8000.0  // ���-�� Nvd ��� �������� ����������� ����� �� ������ �� �� ���� ��
#define TmopStHigh 127.0  // ���������� ����������� ����� �� ������ �� �� ���� ��
#define TmopStMax 137.0  // ������� ����������� ����� �� ������ �� ���� ��
#define TmopStAlarm 147.0  // ��������-������� ����������� ����� �� ������ �� ���� ��
#define PmvhDMin 0.05  // ��� �������� ����� �� ����� � ���������(���)
#define PmvhDMinTimer 50.0  // ������ ��� ������ "��� �������� ����� �� ����� � ���������"
#define PmvhDLow 0.35  // ���������� �������� ����� �� ����� � ���������(���)
#define PmvhDMinLim 0.25  // ������ �������� ����� �� ����� � ���������(���)
#define PmvhDMinAlarm 0.16  // ��������-������ �������� ����� �� ����� � ���������(���)
#define PmvhDContr 8500.0  // ���-�� Nvd, �� ������� �������� �������� "��� �������� ����� �� ����� � ���������"
#define PgInStVLow 0.28  // �������� ���� ����� ��� ����, ���
#define PgInStVMin 0.16  // �������� ���� ����� ��� ���� � ������� 15 ��� � �������� �� ���, ���
#define PgInStVMinTimer 25.0  // ������ ��� ������ "�������� ���� ����� ��� ����" � �� ���
#define PgInStVHigh 0.7  // �������� ���� ����� ��� ������ �� 7200, ���
#define PgInStVAlarm 0.8  // �������� ���� ����� ��� ������ �� ���� �������, ���
#define PgInStVContr 7200.0  // ���-�� Nvd, �� ������� �������� �������� �������� ���� ����� ���
#define VibDContr  9700.0  // ���-�� Nvd ��� ���������� �������� ��������
#define VibDPpHigh 30.0  // ���������� �������� ��������� � ���� ��
#define VibDPpAlarm 50.0  // ������� �������� ���-������ � ���� ��
#define VibDZpHigh 30.0  // ���������� �������� ��������� � ���� ��
#define VibDZpAlarm 50.0  // ������� �������� ���-������ � ���� ��
#define NggHighTime 0.1  // �������� ������� - ������� ������� �������� ������ ��
#define NggHighLimTime 0.1  // �������� ������� - ��������-�������  ������� �������� ������ ��
#define NggLowTime 0.5  // �������� ������� - ��������-������  ������� �������� ������ ��
#define NstHighTime 0.1  // �������� ������� - ������� ������� �������� ������ ��
#define NstRaskrTime 0.03  // �������� ������� - ��������� ������ ��������� �������
#define NstObrRaskrTime 0.1  // �������� ������� - �������� ��������� ��
#define PsuflHighTime 1.0  // �������� ������� - ���������� �������� ������������
#define PsuflLimTime 5.0  // �������� ������� - ������� �������� ������������
#define PrpkTime 1.0  // �������� ������� -���������� �������� ������� � ������������ ������� �����������
#define TtstartLimTime 1.0  // �������� ������� -  ������� ����������� ���� �� �������(��)
#define TtstartHighLimTime 0.03  // �������� ������� -  ��������-������� ����������� ���� �� �������(��)
#define TtHighTime 1.0  // �������� ������� - ���������� ����������� ���� �� ��
#define TtHighAlarmTime 1.0  // �������� ������� - ������� ����������� ���� �� �� (��)
#define TtHighLimTime 0.03  // �������� ������� - ��������-�������  ����������� ���� �� �� (��)
#define TstHighTime 1.0  // �������� ������� - ���������� ����������� ���� �� ��
#define TstHighAlarmTime 1.0  // �������� ������� - ������� ����������� ���� �� �� (��)
#define TstHighLimTime 0.1  // �������� ������� - ��������-�������  ����������� ���� �� �� (��)
#define distortTtBrkTime 30.0  // �����, � ������� �������� ����������� ��������������� ���� �� ��� ���������� ��������
#define distortTstBrkTime 30.0  // �����, � ������� �������� ����������� ��������������� ���� ��� ��� ���������� ��������
#define distortTtTime 30.0  // ����� ������� ��������������� ���� ��
#define distortTstTime 30.0  // ����� ������� ��������������� ���� ���
#define PkLimTime 0.25  // �������� ������� -  ���������� �������� ������� �� ���
#define PtgLimTime 0.1  // �������� ������� - �������� ���������� ���� ��������-�������
#define PtgHighTime 5.0  // �������� ������� - �������� ���������� ���� �������
#define PtgAlarmTime 1.0  // �������� ������� - �������� ���������� ���� ����������
#define PtgLowTime 1.0  // �������� ������� - �������� ���������� ���� ����������
#define PtgMinTime 5.0  // �������� ������� - �������� ���������� ���� ������
#define PtgMinLimTime 0.1  // �������� ������� - �������� ���������� ���� ��������-������
#define maxDeltaVNAPosTime 0.1  // �������� ������� - ������������ ��������������� ��� � �������� �����
#define maxDeltaVNANegTime 0.1  // �������� ������� - ������������ ��������������� ��� � �������� ����
#define maxDeltaVNA12Time 7.0  // �������� ������� - ������������ ��������������� ���� �������� ��������� ���
#define maxTimeDeltaDUS 0.4  // ����. �����, � ������� �������� ����������� ��������������� ��� � ��������
#define KPVBrkTime 1.0  // �������� ������� -  ����������� ��� ����������
#define KPGBrkTime 1.0  // �������� ������� - ����������� ����-��� ����������
#define SKBrkOnTime 0.1  // �������� ������� - ���������������� �������� ��
#define SKBrkOffTime 0.1  // �������� ������� - ���������������� �������� ��
#define UtechkaTGTime 1.0  // �������� ������� - ������ ���������� ����
#define maxFSTTime 1.0  // �������� ������� - ���������� ������ ���� ������ ��
#define maxBrkTime 5.0  // �������� ������� -����� �������
#define setDUSBrkTime 0.1  // �������� ������� -������������� ���� ���������� ��������
#define mesDUSBrkTime 0.1  // �������� ������� -������������� ���� ��������� ��������
#define SKNotOnFireTime 1.0  // �������� ������� -����� �� �� �������
#define VibDMaxTime 3.0  // �������� ������� - ������� �������� ���������
#define VibDZPTime 0.02  // �������� ������� - �� ������ ������ "����", "����" �� ��������
#define VibDPPTime 0.02  // �������� ������� - �� ������ ������ "����", "����" �� ��������

// �������������� ������

// ��������� �������� � ������� #define ���_������� *ukaz, ������_�������, �����_�������
#define YdusMainToGt *ukaz,0,1
#define TtstartToNvd *ukaz,2,24
#define PkstartToNvd *ukaz,25,46
#define NststartToNvd *ukaz,47,68
#define Nvd0ToTst0 *ukaz,69,79
#define MktoNvd *ukaz,80,186
#define KdtoNvd *ukaz,187,344
#define Gt0ToNvd0 *ukaz,345,354
#define Nvd0ToGt0 *ukaz,355,364
#define MstToNvd0 *ukaz,365,374
#define ZsVSToNvd0 *ukaz,375,500
#define Gt0startToNvd0 *ukaz,501,626
#define Nvd0ToPow *ukaz,627,636
#define Nvd0ToTt0 *ukaz,637,646
#define Nvd0ToPk0 *ukaz,647,656
#define Nvd0ToTauvd0 *ukaz,657,666
#define Nvd0ToA1 *ukaz,667,676
#define Nvd0ToA2 *ukaz,677,686
#define Nvd0ToA3 *ukaz,687,696
#define Nvd0ToA4 *ukaz,697,701
#define Nvd0ToA5 *ukaz,702,706
#define Nvd0ToA6 *ukaz,707,711
#define YdusMainToGt *ukaz,712,713
#define TtstartToNvd *ukaz,714,736
#define PkstartToNvd *ukaz,737,758
#define NststartToNvd *ukaz,759,780
#define Nvd0ToTst0 *ukaz,781,791
#define MktoNvd *ukaz,792,898
#define KdtoNvd *ukaz,899,1056
#define Gt0ToNvd0 *ukaz,1057,1066
#define Nvd0ToGt0 *ukaz,1067,1076
#define MstToNvd0 *ukaz,1077,1086
#define ZsVSToNvd0 *ukaz,1087,1212
#define Gt0startToNvd0 *ukaz,1213,1338
#define Nvd0ToPow *ukaz,1339,1348
#define Nvd0ToTt0 *ukaz,1349,1358
#define Nvd0ToPk0 *ukaz,1359,1368
#define Nvd0ToTauvd0 *ukaz,1369,1378
#define Nvd0ToA1 *ukaz,1379,1388
#define Nvd0ToA2 *ukaz,1389,1398
#define Nvd0ToA3 *ukaz,1399,1408
#define Nvd0ToA4 *ukaz,1409,1413
#define Nvd0ToA5 *ukaz,1414,1418
#define Nvd0ToA6 *ukaz,1419,1423
// ����������� ����� � ������� = 1424
// ����������� ������ ��������� ������ = 44

struct point {float x;float y;float k;};
// ������ �������
struct point massiv[]={
{0.0,0.0,44.6},
{100.0,4460.0,44.6},
{0.0,24.76,0.00112},
{571.43,25.4,0.0},
{1117.22,25.4,-0.00156002},
{1527.47,24.76,0.00056361},
{2095.24,25.08,0.0008089},
{2490.84,25.4,0.00488321},
{3010.99,27.94,0.42524343},
{3560.44,261.59,0.13334733},
{3608.06,267.94,0.19051133},
{4014.65,345.4,0.22266505},
{4516.48,457.14,0.15899667},
{5003.66,534.6,0.0990599},
{5490.84,582.86,0.04834157},
{6029.3,608.89,0.02225677},
{6556.78,620.63,-0.02407211},
{7018.31,609.52,-0.02610322},
{7553.11,595.56,0.0092527},
{8032.97,600.0,-0.14918693},
{8100.0,590.0,-0.10253052},
{8435.9,555.56,-0.08086262},
{9091.58,502.54,-0.11707936},
{9509.16,453.65,-0.0283431},
{9710.62,447.94,0.04612888},
{0.0,0.099654,0.0},
{571.43,0.099654,0.0000114},
{1117.22,0.105876,0.00001517},
{1527.47,0.112098,0.00003288},
{2095.24,0.130764,0.00003146},
{2490.84,0.143208,0.00003589},
{3010.99,0.161874,0.00018137},
{3560.44,0.261528,0.00013066},
{3608.06,0.26775,0.00016858},
{4014.65,0.336294,0.00021098},
{4516.48,0.44217,0.00025564},
{5003.66,0.566712,0.00030672},
{5490.84,0.716142,0.00038151},
{6029.3,0.92157,0.0005078},
{6556.78,1.189422,0.0006071},
{7018.31,1.469616,0.0007219},
{7553.11,1.855686,0.00057094},
{8032.97,2.129658,0.0048528},
{8435.9,4.084998,0.00090227},
{9091.58,4.676598,0.00398151},
{9509.16,6.339198,0.00785126},
{9710.62,7.920912,0.0008157},
{0.0,0.0,0.0},
{571.43,0.0,0.0},
{1117.22,0.0,0.0},
{1527.47,0.0,0.0},
{2095.24,0.0,0.0},
{2490.84,0.0,0.0},
{3010.99,0.0,0.0},
{3560.44,0.0,3.44099118},
{3608.06,163.86,0.69369635},
{4014.65,445.91,0.70121356},
{4516.48,797.8,0.4631553},
{5003.66,1023.44,0.4190443},
{5490.84,1227.59,0.47392564},
{6029.3,1482.78,0.52453174},
{6556.78,1759.46,0.57038546},
{7018.31,2022.71,0.86894166},
{7553.11,2487.42,0.57099987},
{8032.97,2761.42,0.72665227},
{8435.9,3054.21,0.85624085},
{9091.58,3615.63,2.8304277},
{9509.16,4797.56,4.28010523},
{9710.62,5659.83,0.5828495},
{0.0,354.0,0.02897029},
{9527.0,630.0,0.08717949},
{9722.0,647.0,0.08888889},
{9857.0,659.0,0.09848485},
{9989.0,672.0,0.096},
{10114.0,684.0,0.09243697},
{10233.0,695.0,0.09565217},
{10348.0,706.0,0.13333333},
{10423.0,716.0,0.18181818},
{10489.0,728.0,0.24242424},
{10555.0,744.0,0.07048792},
{0.0,0.0,0.00199115},
{734.2,1.4619,0.0},
{743.6,1.4619,0.0},
{757.6,1.4619,0.13053488},
{761.9,2.0232,0.06003896},
{769.6,2.4855,-0.08423158},
{779.1,1.6853,0.01872308},
{785.6,1.807,0.07901449},
{792.5,2.3522,-0.04160674},
{801.4,1.9819,0.08106579},
{809.0,2.598,-0.00839394},
{818.9,2.5149,-0.15135417},
{828.5,1.0619,0.28246341},
{832.6,2.22,0.07389412},
{841.1,2.8481,0.01520183},
{852.0,3.0138,0.04405217},
{863.5,3.5204,-0.10579851},
{876.9,2.1027,0.08655556},
{885.0,2.8038,-0.03248598},
{895.7,2.4562,0.05963441},
{905.0,3.0108,-0.01841739},
{916.5,2.799,-0.06262617},
{927.2,2.1289,0.15682927},
{935.4,3.4149,0.0188},
{948.4,3.6593,-0.07123571},
{962.4,2.662,0.05839216},
{972.6,3.2576,-0.00371774},
{985.0,3.2115,0.07003252},
{997.3,4.0729,-0.02967742},
{1012.8,3.6129,0.03378986},
{1026.6,4.0792,-0.05846154},
{1042.2,3.1672,0.09634711},
{1054.3,4.333,-0.08748193},
{1070.9,2.8808,0.17773636},
{1081.9,4.8359,-0.1502663},
{1100.3,2.071,0.45494937},
{1108.2,5.6651,-0.02691705},
{1129.9,5.081,-0.11812371},
{1149.3,2.7894,0.14451887},
{1159.9,4.3213,0.06795758},
{1176.4,5.4426,-0.06819231},
{1197.2,4.0242,0.09701948},
{1212.6,5.5183,0.05430332},
{1233.7,6.6641,-0.01154724},
{1259.1,6.3708,-0.06839344},
{1283.5,4.702,-0.01721229},
{1301.4,4.3939,0.09028571},
{1318.2,5.9107,-0.00544248},
{1340.8,5.7877,0.00037104},
{1362.9,5.7959,0.01760633},
{1385.0,6.185,0.09624895},
{1408.7,8.4661,-0.0629257},
{1441.0,6.4336,-0.0619878},
{1465.6,4.9087,0.0981123},
{1484.3,6.7434,0.09664729},
{1510.1,9.2369,0.02973938},
{1545.4,10.2867,0.01173028},
{1584.7,10.7477,-0.01919455},
{1610.4,10.2544,-0.00164541},
{1649.6,10.1899,-0.04780808},
{1669.4,9.2433,0.09374788},
{1704.7,12.5526,-0.04309583},
{1752.7,10.484,-0.00479938},
{1785.1,10.3285,0.04914975},
{1824.5,12.265,-0.0487484},
{1871.4,9.9787,0.02849869},
{1909.5,11.0645,0.11882033},
{1951.8,16.0906,0.0002671},
{2013.2,16.107,0.01257485},
{2063.3,16.737,-0.00440329},
{2111.9,16.523,0.00023211},
{2163.6,16.535,0.07892786},
{2203.8,19.7079,0.0016494},
{2279.1,19.8321,-0.01087203},
{2354.9,19.008,0.12962143},
{2396.9,24.4521,0.00056638},
{2490.3,24.505,-0.00001217},
{2572.5,24.504,0.01345528},
{2621.7,25.166,0.04340297},
{2702.6,28.6773,0.01211598},
{2812.1,30.004,0.02246456},
{2903.8,32.064,0.01983209},
{3011.0,34.19,0.07525686},
{3153.1,44.884,0.00737895},
{3248.1,45.585,0.01002747},
{3357.3,46.68,0.00055067},
{3528.0,46.774,0.00686698},
{3676.1,47.791,0.00294079},
{3828.1,48.238,0.00890244},
{4008.5,49.844,0.08850438},
{4168.3,63.987,0.00953822},
{4450.9,66.6825,0.01274961},
{4705.7,69.9311,-0.00098502},
{4972.8,69.668,0.04313397},
{5223.6,80.486,0.05757606},
{5424.1,92.03,0.00790971},
{5806.2,95.0523,0.02257422},
{6169.3,103.249,0.11185349},
{6372.7,126.0,0.00907196},
{6873.0,130.5387,0.00876138},
{7371.7,134.908,0.22857416},
{7696.0,209.0346,-0.02940205},
{8494.4,185.56,0.02204364},
{9023.7,197.2277,0.00000305},
{9777.1,197.23,0.0},
{9780.2,197.23,0.0},
{9780.3,197.23,0.02016605},
{3162.9,0.0011,-0.0015},
{3163.1,0.0008,-0.002},
{3163.2,0.0006,0.0005},
{3163.4,0.0007,-0.001},
{3163.6,0.0005,0.0038},
{3169.6,0.0233,0.00238176},
{3228.8,0.1643,-0.00009059},
{3286.2,0.1591,-0.00066929},
{3337.0,0.1251,-0.00009658},
{3386.7,0.1203,-0.00005895},
{3432.5,0.1176,0.00007143},
{3475.9,0.1207,-0.00012879},
{3515.5,0.1156,-0.00000279},
{3551.4,0.1155,0.00017598},
{3587.2,0.1218,0.00013333},
{3621.7,0.1264,0.00021905},
{3653.2,0.1333,-0.00035275},
{3684.1,0.1224,-0.00007947},
{3714.3,0.12,-0.00002465},
{3742.7,0.1193,0.00010033},
{3772.6,0.1223,0.0002375},
{3804.6,0.1299,-0.00005903},
{3833.4,0.1282,0.0002243},
{3865.5,0.1354,0.00003846},
{3896.7,0.1366,-0.00042215},
{3925.6,0.1244,-0.00015035},
{3954.2,0.1201,0.00001311},
{3984.7,0.1205,0.00005466},
{4015.8,0.1222,0.00046795},
{4047.0,0.1368,0.00019178},
{4076.2,0.1424,0.00042857},
{4107.7,0.1559,0.00050464},
{4140.0,0.1722,0.0003003},
{4173.3,0.1822,-0.00024601},
{4204.6,0.1745,0.00002023},
{4239.2,0.1752,-0.0000848},
{4273.4,0.1723,-0.00012537},
{4306.9,0.1681,0.0},
{4342.9,0.1681,-0.00004959},
{4379.2,0.1663,-0.00008757},
{4414.6,0.1632,-0.00000267},
{4452.1,0.1631,-0.00010995},
{4490.3,0.1589,-0.000072},
{4527.8,0.1562,0.00000521},
{4566.2,0.1564,0.00007108},
{4607.0,0.1593,0.00006147},
{4649.3,0.1619,-0.00002358},
{4691.7,0.1609,-0.00021892},
{4728.7,0.1528,0.00004785},
{4770.5,0.1548,0.00003563},
{4815.4,0.1564,-0.00006828},
{4860.8,0.1533,-0.00003319},
{4906.0,0.1518,-0.00003326},
{4951.1,0.1503,-0.00000234},
{4993.9,0.1502,0.00017532},
{5040.1,0.1583,-0.00001296},
{5086.4,0.1577,0.00019318},
{5139.2,0.1679,0.00011708},
{5191.3,0.174,0.00008097},
{5240.7,0.178,0.00004615},
{5286.2,0.1801,0.000182},
{5337.3,0.1894,0.00016078},
{5388.3,0.1976,0.00010606},
{5447.7,0.2039,-0.00015649},
{5500.1,0.1957,-0.00001167},
{5551.5,0.1951,-0.00002672},
{5603.9,0.1937,0.00002139},
{5660.0,0.1949,-0.00002783},
{5713.9,0.1934,-0.00004668},
{5769.6,0.1908,-0.00000337},
{5829.0,0.1906,-0.00008029},
{5883.8,0.1862,0.00013505},
{5946.0,0.1946,0.00005351},
{6005.8,0.1978,-0.00001989},
{6061.1,0.1967,0.00009277},
{6124.7,0.2026,0.00001849},
{6184.2,0.2037,0.00018923},
{6245.5,0.2153,0.0002315},
{6309.0,0.23,0.00022762},
{6374.9,0.245,-0.00003161},
{6444.5,0.2428,-0.00014397},
{6508.4,0.2336,0.0000303},
{6574.4,0.2356,0.00005985},
{6642.9,0.2397,0.00005775},
{6713.9,0.2438,0.00004497},
{6789.5,0.2472,-0.00007203},
{6860.3,0.2421,0.00001085},
{6934.0,0.2429,-0.0000271},
{7007.8,0.2409,-0.00010172},
{7083.5,0.2332,0.00001812},
{7166.3,0.2347,0.00046406},
{7245.6,0.2715,-0.00004845},
{7319.9,0.2679,-0.00040566},
{7362.3,0.2507,0.00011419},
{7391.2,0.254,0.00036943},
{7422.6,0.2656,0.00031594},
{7457.1,0.2765,0.00017196},
{7494.9,0.283,0.00033254},
{7537.0,0.297,0.00033478},
{7583.0,0.3124,0.00029684},
{7630.5,0.3265,0.00037736},
{7683.5,0.3465,0.00011885},
{7742.4,0.3535,-0.00008966},
{7800.4,0.3483,-0.00010403},
{7860.0,0.3421,-0.00016294},
{7922.6,0.3319,-0.00024883},
{7986.5,0.316,-0.00009819},
{8052.7,0.3095,-0.00010847},
{8120.0,0.3022,0.0},
{8204.8,0.3022,0.00006082},
{8331.4,0.3099,0.00006117},
{8514.5,0.3211,-0.00001063},
{8683.9,0.3193,-0.00000789},
{8836.0,0.3181,-0.00000217},
{8974.2,0.3178,-0.00005164},
{9090.4,0.3118,-0.00017403},
{9167.4,0.2984,-0.00008929},
{9229.0,0.2929,-0.00029301},
{9266.2,0.282,-0.00016854},
{9292.9,0.2775,-0.00031579},
{9310.0,0.2721,-0.00023457},
{9326.2,0.2683,-0.00026277},
{9339.9,0.2647,-0.00011429},
{9353.9,0.2631,-0.00017791},
{9370.2,0.2602,-0.00028767},
{9384.8,0.256,-0.00024786},
{9396.5,0.2531,-0.00008},
{9409.0,0.2521,-0.00002703},
{9423.8,0.2517,-0.00009155},
{9438.0,0.2504,-0.00046847},
{9449.1,0.2452,-0.00044318},
{9457.9,0.2413,0.00011972},
{9472.1,0.243,-0.00035246},
{9484.3,0.2387,-0.00017857},
{9495.5,0.2367,-0.00008609},
{9510.6,0.2354,-0.00032456},
{9522.0,0.2317,-0.00002113},
{9536.2,0.2314,-0.00015079},
{9548.8,0.2295,-0.0001844},
{9562.9,0.2269,-0.00039535},
{9571.5,0.2235,-0.00033333},
{9577.2,0.2216,-0.00003797},
{9585.1,0.2213,0.0000155},
{9598.0,0.2215,-0.00042667},
{9605.5,0.2183,-0.00010345},
{9614.2,0.2174,-0.00006087},
{9625.7,0.2167,-0.00016327},
{9635.5,0.2151,-0.00007955},
{9644.3,0.2144,-0.00005682},
{9653.1,0.2139,-0.00005682},
{9661.9,0.2134,-0.00004494},
{9670.8,0.213,-0.00005682},
{9679.6,0.2125,-0.00005682},
{9688.4,0.212,-0.00004545},
{9697.2,0.2116,-0.00005682},
{9706.0,0.2111,-0.00005618},
{9714.9,0.2106,-0.00004545},
{9723.7,0.2102,0.00002162},
{0.0,0.0,11.33203632},
{771.0,8737.0,2.2},
{1071.0,9397.0,1.58666667},
{1371.0,9873.0,0.90333333},
{1671.0,10144.0,0.77},
{1971.0,10375.0,0.69},
{2271.0,10582.0,0.56666667},
{2571.0,10752.0,0.47333333},
{2871.0,10894.0,0.37333333},
{3171.0,11006.0,3.47082939},
{0.0,0.0,0.08824539},
{8737.0,771.0,0.45454545},
{9397.0,1071.0,0.6302521},
{9873.0,1371.0,1.10701107},
{10144.0,1671.0,1.2987013},
{10375.0,1971.0,1.44927536},
{10582.0,2271.0,1.76470588},
{10752.0,2571.0,2.11267606},
{10894.0,2871.0,2.67857143},
{11006.0,3171.0,0.28811557},
{0.0,0.0,0.0138},
{1000.0,13.8,0.0414},
{2000.0,55.2,0.0828},
{3000.0,138.0,0.1242},
{4000.0,262.2,0.4554},
{5000.0,717.6,0.5244},
{6000.0,1242.0,0.897},
{7000.0,2139.0,1.311},
{8000.0,3450.0,2.68},
{10000.0,8810.0,0.881},
{7.0,1.5,0.04576101},
{39.779,3.0,0.04735721},
{94.683,5.6001,0.05897492},
{186.5,11.015,0.05873457},
{326.69,19.249,0.05851217},
{507.49,29.828,0.0581222},
{726.15,42.537,0.05788581},
{973.81,56.873,0.04983914},
{1231.8,69.731,0.04822555},
{1485.4,81.961,0.04814784},
{1726.2,93.555,0.04831175},
{1942.4,104.0,0.03570332},
{2137.9,110.98,0.02790974},
{2306.3,115.68,0.02698962},
{2450.8,119.58,0.02735247},
{2576.2,123.01,0.02791587},
{2680.8,125.93,0.02772512},
{2765.2,128.27,0.02667598},
{2836.8,130.18,0.02885906},
{2896.4,131.9,0.02824742},
{2944.9,133.27,0.02691293},
{2982.8,134.29,0.02743902},
{3015.6,135.19,0.02692308},
{3039.0,135.82,0.01463415},
{3059.5,136.12,0.01301775},
{3076.4,136.34,0.02571429},
{3079.9,136.43,0.0375},
{3083.1,136.55,0.01538462},
{3084.4,136.57,-0.08888889},
{3085.3,136.49,0.01471631},
{3141.7,137.32,0.01669708},
{3251.3,139.15,0.01161665},
{3354.6,140.35,0.01639535},
{3440.6,141.76,0.01412894},
{3513.5,142.79,0.01545741},
{3576.9,143.77,0.01582734},
{3632.5,144.65,0.01341991},
{3678.7,145.27,0.01538462},
{3716.4,145.85,0.01417112},
{3753.8,146.38,0.01543408},
{3784.9,146.86,0.01428571},
{3810.1,147.22,0.01152263},
{3834.4,147.5,0.0127907},
{3851.6,147.72,0.012},
{3869.1,147.93,0.01383929},
{3891.5,148.24,0.01587838},
{3921.1,148.71,0.01266234},
{3951.9,149.1,0.01030303},
{3984.9,149.44,0.01016949},
{4020.3,149.8,0.01018519},
{4052.7,150.13,0.01070423},
{4088.2,150.51,0.00941828},
{4124.3,150.85,0.00994624},
{4161.5,151.22,0.01235294},
{4195.5,151.64,0.00955056},
{4231.1,151.98,0.01190476},
{4264.7,152.38,0.01132075},
{4301.8,152.8,0.0092545},
{4340.7,153.16,0.0127321},
{4378.4,153.64,0.00927318},
{4418.3,154.01,0.01226667},
{4455.8,154.47,0.00921053},
{4493.8,154.82,0.01271394},
{4534.7,155.34,0.00771144},
{4574.9,155.65,0.01099476},
{4613.1,156.07,0.01312336},
{4651.2,156.57,0.01276596},
{4693.5,157.11,0.00964126},
{4738.1,157.54,0.01285714},
{4780.1,158.08,0.01398601},
{4823.0,158.68,0.00842572},
{4868.1,159.06,0.01045752},
{4914.0,159.54,0.01002278},
{4957.9,159.98,0.00926724},
{5004.3,160.41,0.01008772},
{5049.9,160.87,0.01361702},
{5096.9,161.51,0.0092},
{5146.9,161.97,0.0078629},
{5196.5,162.36,0.00916335},
{5246.7,162.82,0.01084337},
{5296.5,163.36,0.01128107},
{5348.8,163.95,0.00912477},
{5402.5,164.44,0.01117424},
{5455.3,165.03,0.01224138},
{5513.3,165.74,0.00980392},
{5569.4,166.29,0.00979381},
{5627.6,166.86,0.01077739},
{5684.2,167.47,0.01001616},
{5746.1,168.09,0.01008696},
{5803.6,168.67,0.00308943},
{5865.1,168.86,-0.00077882},
{5929.3,168.81,-0.00639344},
{5990.3,168.42,-0.00280374},
{6054.5,168.24,-0.00277778},
{6122.9,168.05,-0.00782209},
{6188.1,167.54,-0.00520984},
{6257.2,167.18,-0.00281065},
{6324.8,166.99,-0.00436681},
{6393.5,166.69,-0.00731364},
{6464.6,166.17,-0.0035461},
{6535.1,165.92,0.00040377},
{6609.4,165.95,-0.0067867},
{6681.6,165.46,-0.00326975},
{6755.0,165.22,-0.01192412},
{6828.8,164.34,-0.01513067},
{6901.5,163.24,-0.01653226},
{6975.9,162.01,-0.01744341},
{7051.0,160.7,-2.09791123},
{7127.6,0.0,0.0},
{7166.6,0.0,0.0},
{7182.8,0.0,0.0},
{7288.6,0.0,0.0},
{7437.7,0.0,0.0},
{7601.0,0.0,0.0},
{7769.8,0.0,0.0},
{7946.6,0.0,0.0},
{8130.8,0.0,0.0},
{8567.7,0.0,0.0},
{9003.5,0.0,0.0},
{9257.7,0.0,0.0},
{9394.0,0.0,0.0},
{9488.8,0.0,0.0},
{9488.9,0.0,0.0},
{9501.8,0.0,0.0},
{9503.8,0.0,0.0},
{9506.7,0.0,0.0},
{10.0,0.37,0.0},
{39.779,0.37,0.0},
{94.683,0.37,0.0},
{186.5,0.37,0.0},
{326.69,0.37,0.0},
{507.49,0.37,0.0},
{726.15,0.37,0.0},
{973.81,0.37,0.0},
{1231.8,0.37,0.0},
{1485.4,0.37,0.0},
{1726.2,0.37,0.0},
{1942.4,0.37,0.0},
{2137.9,0.37,0.0},
{2306.3,0.37,0.0},
{2450.8,0.37,0.0},
{2576.2,0.37,0.0},
{2680.8,0.37,0.0},
{2765.2,0.37,0.0},
{2836.8,0.37,0.0},
{2896.4,0.37,0.0},
{2944.9,0.37,0.0},
{2982.8,0.37,0.0},
{3015.6,0.37,0.0},
{3039.0,0.37,0.0},
{3059.5,0.37,0.0},
{3076.4,0.37,0.0},
{3079.9,0.37,0.0},
{3083.1,0.37,0.0},
{3084.4,0.37,0.0},
{3084.6,0.37,0.0},
{3085.3,0.37,-0.0001195},
{3141.7,0.36326,0.00010119},
{3251.3,0.37435,-0.00006128},
{3354.6,0.36802,-0.00009349},
{3440.6,0.35998,0.00016337},
{3513.5,0.37189,0.00004953},
{3576.9,0.37503,0.00031313},
{3632.5,0.39244,0.00113463},
{3678.7,0.44486,-0.00057109},
{3716.4,0.42333,0.00084947},
{3753.8,0.4551,0.00162283},
{3784.9,0.50557,-0.00097897},
{3810.1,0.4809,0.00120864},
{3834.4,0.51027,-0.00018372},
{3851.6,0.50711,0.00169714},
{3869.1,0.53681,-0.00017679},
{3891.5,0.53285,0.00244561},
{3921.1,0.60524,0.0023487},
{3951.9,0.67758,0.0007503},
{3984.9,0.70234,0.00000932},
{4020.3,0.70267,0.00156512},
{4052.7,0.75338,0.00076986},
{4088.2,0.78071,0.0015277},
{4124.3,0.83586,0.00111532},
{4161.5,0.87735,0.00112265},
{4195.5,0.91552,0.00154916},
{4231.1,0.97067,-0.00052143},
{4264.7,0.95315,0.0018504},
{4301.8,1.0218,0.00082005},
{4340.7,1.0537,0.00054907},
{4378.4,1.0744,0.00443108},
{4418.3,1.2512,-0.000824},
{4455.8,1.2203,0.00074474},
{4493.8,1.2486,0.00200489},
{4534.7,1.3306,0.00179851},
{4574.9,1.4029,0.00027225},
{4613.1,1.4133,-0.00131234},
{4651.2,1.3633,0.00291726},
{4693.5,1.4867,0.00011883},
{4738.1,1.492,0.0006619},
{4780.1,1.5198,0.001669},
{4823.0,1.5914,0.00090466},
{4868.1,1.6322,0.00181481},
{4914.0,1.7155,-0.00048975},
{4957.9,1.694,0.00148707},
{5004.3,1.763,-0.00078509},
{5049.9,1.7272,0.00155106},
{5096.9,1.8001,0.001178},
{5146.9,1.859,0.00157661},
{5196.5,1.9372,-0.00006175},
{5246.7,1.9341,-0.00046586},
{5296.5,1.9109,0.0011587},
{5348.8,1.9715,0.00054935},
{5402.5,2.001,0.0010928},
{5455.3,2.0587,0.00005862},
{5513.3,2.0621,0.00078253},
{5569.4,2.106,0.00054124},
{5627.6,2.1375,0.00072615},
{5684.2,2.1786,0.0009273},
{5746.1,2.236,-0.00044522},
{5803.6,2.2104,0.0008878},
{5865.1,2.265,0.00131931},
{5929.3,2.3497,0.00052951},
{5990.3,2.382,0.00103583},
{6054.5,2.4485,0.00054532},
{6122.9,2.4858,0.00038497},
{6188.1,2.5109,0.00156729},
{6257.2,2.6192,0.00103254},
{6324.8,2.689,0.00124309},
{6393.5,2.7744,0.00099297},
{6464.6,2.845,0.00119574},
{6535.1,2.9293,0.00104038},
{6609.4,3.0066,0.00072022},
{6681.6,3.0586,0.00098229},
{6755.0,3.1307,0.00084417},
{6828.8,3.193,0.00096974},
{6901.5,3.2635,0.00073925},
{6975.9,3.3185,0.000747},
{7051.0,3.3746,0.00371018},
{7127.6,3.6588,-0.00449231},
{7166.6,3.4836,-0.02137654},
{7182.8,3.1373,0.000431},
{7288.6,3.1829,0.00109658},
{7437.7,3.3464,0.00084752},
{7601.0,3.4848,0.00073578},
{7769.8,3.609,0.00091346},
{7946.6,3.7705,0.00083496},
{8130.8,3.9243,0.00231746},
{8567.7,4.9368,0.00157343},
{9003.5,5.6225,0.00119394},
{9257.7,5.926,0.00051577},
{9394.0,5.9963,0.00003903},
{9488.8,6.0,0.0},
{9501.8,6.0,0.0},
{9503.8,6.0,0.0},
{9506.7,6.0,0.00063113},
{0.0,0.0,0.0188852},
{8737.0,165.0,0.4469697},
{9397.0,460.0,0.8487395},
{9873.0,864.0,2.59409594},
{10144.0,1567.0,2.11255411},
{10375.0,2055.0,2.35748792},
{10582.0,2543.0,2.83529412},
{10752.0,3025.0,3.3943662},
{10894.0,3507.0,4.19642857},
{11006.0,3977.0,0.36134836},
{0.0,354.0,0.05585441},
{8737.0,842.0,0.03181818},
{9397.0,863.0,0.03361345},
{9873.0,879.0,-0.099631},
{10144.0,852.0,0.15151515},
{10375.0,887.0,0.15942029},
{10582.0,920.0,0.18823529},
{10752.0,952.0,0.22535211},
{10894.0,984.0,0.30357143},
{11006.0,1018.0,0.092495},
{0.0,0.0,0.00064668},
{8737.0,5.65,0.00310606},
{9397.0,7.7,0.00409664},
{9873.0,9.65,0.01151292},
{10144.0,12.77,0.00709957},
{10375.0,14.41,0.00743961},
{10582.0,15.95,0.00841176},
{10752.0,17.38,0.00950704},
{10894.0,18.73,0.01080357},
{11006.0,19.94,0.00181174},
{0.0,20.0,-0.00210828},
{8737.0,1.58,-0.0012},
{9397.0,0.788,-0.00055252},
{9873.0,0.525,-0.00047601},
{10144.0,0.396,-0.00024242},
{10375.0,0.34,-0.00021256},
{10582.0,0.296,-0.00012941},
{10752.0,0.274,-0.00006338},
{10894.0,0.265,-0.00007143},
{11006.0,0.257,0.00002335},
{0.0,0.0,0.02861394},
{8737.0,250.0,0.51515152},
{9397.0,590.0,0.96638655},
{9873.0,1050.0,1.43911439},
{10144.0,1440.0,0.95238095},
{10375.0,1660.0,1.20772947},
{10582.0,1910.0,1.94117647},
{10752.0,2240.0,2.88732394},
{10894.0,2650.0,1.875},
{11006.0,2860.0,0.25985826},
{0.0,0.0,0.00016024},
{8737.0,1.4,0.00055909},
{9397.0,1.769,0.00109454},
{9873.0,2.29,0.00151292},
{10144.0,2.7,0.00155411},
{10375.0,3.059,0.00168599},
{10582.0,3.408,0.00205294},
{10752.0,3.757,0.00295775},
{10894.0,4.177,0.00121429},
{11006.0,4.313,0.00039188},
{0.0,0.0,0.04852924},
{8737.0,424.0,0.00909091},
{9397.0,430.0,0.0210084},
{9873.0,440.0,0.02214022},
{10144.0,446.0,0.01731602},
{10375.0,450.0,0.04830918},
{10582.0,460.0,0.17647059},
{10752.0,490.0,0.35211268},
{10894.0,540.0,0.0},
{11006.0,540.0,0.04906415},
{0.0,0.0,0.0},
{8400.0,0.0,-0.01},
{9600.0,-12.0,-0.01181818},
{10700.0,-25.0,-0.01},
{12000.0,-38.0,-0.00316667},
{0.0,0.0,0.0},
{8600.0,0.0,0.00005},
{9600.0,0.05,0.00006818},
{10700.0,0.125,0.00007308},
{12000.0,0.22,0.00001833},
{0.0,0.0,0.0},
{8000.0,0.0,-0.001875},
{9600.0,-3.0,-0.00181818},
{10700.0,-5.0,-0.00192308},
{12000.0,-7.5,-0.000625},
// ����� �������
struct point *ukaz[]={massiv};

float harakt (struct point *ukaz,int l,int h, float arg){
int y,low,high;
low = l;
high = h;
while(low !=high)
{y = (low + high)/2;
if (arg>=(ukaz+y)->x) low = y + 1;
else high = y;}
y = low - 1;
return (arg - (ukaz+y)->x)*(ukaz+y)->k + (ukaz+y)->y;};

