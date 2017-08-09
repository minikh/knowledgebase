


#include "PACRXPlc.h"
#include "math.h"
#include "data.h"//

//		���������������								//!! RF (1301)...RF(1499) 	������
#define cycle				RF(1301)				//*����� ����� (� ��������)
#define Nst_Ust				RF(1303)				//*������� ������� ��������� �������
#define manual_setDOZ		RF(1305)				//*������ ������� �� �������
#define manual_setVNA		RF(1307)				//*������ ������� �� ���

//		�������� ���������� �������						// RF (1501)...RF(1599) 	������
#define setDoz				RF(1501)				//*�������� �� ������� 0...100%
#define set_VNA				RF(1503)				//*������� �� ��� -50�5 ���. ����.
#define Gt_tek				RF(1505)				//*������ ������� �� ������ �� ���������� �������
//		��������� (���������������) ��������					
#define nvd					RF(1511)				//*������� �������� ������ �������������� ����� ��������� � ���
#define nvdNorm				RF(1513)				//*����������� ������� �������� ������ �������������� ����� ��������� � ���
#define nst					RF(1515)				//*������� �������� ������ ��������� �������
#define Tvh					RF(1517)				//*����������� �� ����� � ���������
#define Ttzap				RF(1519)				//*������ ����������� ���� �� �������� �������������� �� ������� �50�1000 ?�
#define Tt					RF(1521)				//*������ ����������� ���� �� �������� ��������������
#define Tst					RF(1523)				//*������ ����������� ���� �� ��������� ��������
#define Tpdtg	    		RF(1525)				//!!!� ���������� ���� ����� ���������(-55...155 ���� � = -550...1550 �.�.)
#define Pkvd				RF(1527)				//*�������� ������� �� ������������ �� ���
#define Ptg					RF(1529)				//*�������� ���������� ���� ����� ��
#define Ptgpd				RF(1531)				//*�������� ���������� ���� ����� ���������
#define Metka				RI(1539)				//*����� �������
#define condition			RI(1541)				//*��������� �������
#define HPTimer				RF(1543)				//**������ �������� ���������
#define startTimer			RF(1545)				//**������ ������� �������
#define heatTimer			RF(1547)				//**������ ������� ��������
#define coolTimer			RF(1549)				//**������ ���������� ���������
#define VibegGGTimer		RF(1551)				//������ ������� ������ ��
#define VibegSTTimer		RF(1553)				//������ ������� ������ ��
#define	promTimer			RF(1555)				//������ ��������
#define P2                  RF(1557)         		 //��������� �������� ���������� ���� ����� ��������
#define b                   RF(1559)               //����������� ��� ������� �2
#define K					RF(1561)				//����������� ��� �������� �� ����������� � �������� ���������� ����
#define fo					RF(1563)				//����������� ����������� �� ��������
#define measureVNA1 		RF(1011)				//��������� ��� 1-�� ������
#define posDOZ				RF(1009)				//��������� ��������������� �������� �������� 0...100%
#define PgInStV    			RF(1087)				//�������� ��������� ���� ����� ��� 0...1.0 ���


//		������� ��������������� �������� � �������� �������������	//	RF (1601)...RF(1699) 	������
#define	Gt_roz_ust			RF(1601)				//*������� ������ ���������� ���� � �� �� �������
#define	Gt_ogr_zap_ust		RF(1603)				//*������� ����������� ������� ���������� ���� �� �������
#define	Ttzap_ogr_ust       RF(1605)                //*������� ����������� ������� �� ���������� � ���� �� ��, �
#define Pk_ogr_ust			RF(1607)				//*������� ����������� �������� ������� �� ������������
#define Ngg_MG_ust			RF(1609)				//*������� ������ ����
#define Ngg_max_ust			RF(1611)				//*������� ������������ �������� Nvd
#define Nst_ogr_ust			RF(1613)				//*������� ����������� ������������� Nst 
#define Tt_ogr_ust			RF(1615)				//*������� ����������� ����������� ���� �� �������� �� �� �������
#define Gt_ogr_ust			RF(1619)				//*������� ����������� ������� �� �������� �������
#define GtPk_ogr_ust		RF(1621)				//*������� ����������� Gt/P�
#define KPV_OFF_ust			RF(1625)				//*������� �������� ���
#define KPV_ON_ust			RF(1627)				//*������� �������� ���
#define KPG_OFF_ust			RF(1629)				//*������� �������� ��� � ���� 
#define KPG_ON_ust			RF(1631)				//*������� �������� ��� � ���� 
#define Usk_ST_ust			RF(1633)				//*������� ��������� �� ���������
#define Usk_ust				RF(1635)				//*������� ��������� ��� ��������
#define Gt_roz_min_ust		RF(1637)				//*������� ���������� ������� �� �������
#define Gt_roz_max_ust		RF(1639)				//*������� ��������� ������� �� �������
#define dGt_ogr_zap_ust		RF(1641)				//*dGt
//		�����������									//	RF (1939)...RF(1999) 	������
#define Reg_Gt_RozN_u		RF(1901)				//����������� ���������� ������� �� �������
#define Reg_Gt_RozK_u		RF(1903)				//����������� ��������� ������� �� �������
#define Reg_Gt_roz_u		RF(1905)				//*����������� ������� �� �������
#define Reg_Usk_ST_u		RF(1907)				//����������� ��������� �� ������� �� ���������
#define Reg_Usk_u			RF(1909)				//����������� ��������� �� ������� ��� ��������
//#define Reg_Gt_ogr_zap_u	RF(1911)				//*����������� ����������� ������� �� �������
#define Reg_KPV_OFF_u		RF(1919)				//*����������� �������� ���
#define Reg_KPV_ON_u		RF(1921)				//*����������� �������� ���
#define Reg_KPG_OFF_u		RF(1923)				//*����������� �������� ��� � ����
#define Reg_KPG_ON_u		RF(1925)				//*����������� �������� ��� � ����
#define Reg_Gt_ogr_u		RF(1935)				//*����������� ������������ �������� ������� ���������� ����
#define Reg_GtPk_ogr_u  	RF(1937)				//*����������� ����������� Gt/Pk

#define Reg_dG_Zap_u		RF(1943)				//����������� �������� ��������� ����������� ������� �� �������


//		������� ���������� �������						// RF (3001)...RF(3050) 	������
#define SK_OFF_tst			BIT_TST_M(3003)			//��������� ������ �������

//		����������� �������							
#define externAO			BIT_TST_M(3701)			//*������� ������ ��
#define init_tst			BIT_TST_M(3702)			//*�������������
#define init_clr			BIT_CLR_M(3702)			//*�������������
#define updateTun			BIT_TST_M(3703)			//*���������� ��������
#define check				BIT_TST_M(3704)			//*�������� �����
#define startHP				BIT_TST_M(3705)			//*������� ������ ��
#define start				BIT_TST_M(3706)			//*������� ������� ���������
#define stop				BIT_TST_M(3707)			//*������� ����������� ��������
#define externDeblock		BIT_TST_M(3708)			//*������� ������� ������������ ������
#define stabST_on			BIT_TST_M(3709)			//*������� �� ��������� ������������ �� (����� ������������ ��)!!!��������� ��� 184 ������
#define up					BIT_TST_M(3710)			//*������� �� ���������� ������
#define down				BIT_TST_M(3711)			//*������� �� �������� ������
#define maxReg				BIT_TST_M(3712)			//*������� ������������� ������
#define longZAP				0//BIT_TST_M(3736)			//*������� ������
#define up_VNA				BIT_TST_M(3713)			//*������� �������� ��� (�����) 
#define down_VNA            BIT_TST_M(3714)			//*������� �������� ��� (����)
#define startProm			BIT_TST_M(3737)			//*������� ����� ��������

//		�������������� �������							//	RF (3468)...RF(3500) 	������
#define HP_set				BIT_SET_M(3451)			//*��������� ����� "�������� ��������� ����"
#define HP_clr				BIT_CLR_M(3451)			//*����� ����� "�������� ��������� ����"
#define HP_tst				BIT_TST_M(3451)			//*�������� ����� "�������� ��������� ����"

#define endHP_set			BIT_SET_M(3452)			//*��������� ����� "����� ��"
#define endHP_clr			BIT_CLR_M(3452)			//*����� ����� "����� ��" !
#define endHP_tst			BIT_TST_M(3452)			//*�������� ����� "����� ��"

#define notFire_set			BIT_SET_M(3453)			//*��������� ����� "��� �������"
#define notFire_clr			BIT_CLR_M(3453)			//*����� ����� "��� �������"
#define notFire_tst			BIT_TST_M(3453)			//*�������� ����� "��� �������"

#define notRateGG_set		BIT_SET_M(3454)			//*��������� ����� "��� �������"
#define notRateGG_clr		BIT_CLR_M(3454)			//*����� ����� "��� �������"
#define notRateGG_tst		BIT_TST_M(3454)			//*�������� ����� "��� �������"

#define TimeZapHigh_set		BIT_SET_M(3645)			//*��������� ����� "����� ������� ������"
#define TimeZapHigh_clr		BIT_CLR_M(3645)			//*����� ����� "����� ������� ������"
#define TimeZapHigh_tst		BIT_TST_M(3645)			//*�������� ����� "����� ������� ������"

#define startEngine_set		BIT_SET_M(3455)			//*��������� ����� "����� ���������"
#define startEngine_clr		BIT_CLR_M(3455)			//*����� ����� "����� ���������"
#define startEngine_tst		BIT_TST_M(3455)			//*�������� ����� "����� ���������"

#define engineStarted_set	BIT_SET_M(3456)			//*��������� ����� "��������� ��������"
#define engineStarted_clr	BIT_CLR_M(3456)			//*����� ����� "��������� ��������"
#define engineStarted_tst	BIT_TST_M(3456)			//*�������� ����� "��������� ��������"

#define heat_set			BIT_SET_M(3457)			//*��������� ����� "�������"
#define heat_clr			BIT_CLR_M(3457)			//*����� ����� "�������"
#define heat_tst			BIT_TST_M(3457)			//*�������� ����� "�������"

#define NO_set				BIT_SET_M(3458)			//*��������� ����� ���������� ������� ����
#define NO_clr				BIT_CLR_M(3458)			//*����� ����� ���������� ������� ����
#define NO_tst				BIT_TST_M(3458)			//*�������� ����� ���������� ������� ����

#define firePresent_set		BIT_SET_M(3459)			//*��������� ����� "������"
#define firePresent_clr		BIT_CLR_M(3459)			//*����� ����� "������"
#define firePresent_tst		BIT_TST_M(3459)			//*�������� ����� "������"

#define redyStart_set		BIT_SET_M(3460)			//*��������� ����� "���������� � �������"
#define redyStart_clr		BIT_CLR_M(3460)			//*����� ����� "���������� � �������"
#define redyStart_tst		BIT_TST_M(3460)			//*�������� ����� "���������� � �������"

#define redyHP_set			BIT_SET_M(3461)			//*��������� ����� "���������� � ��"
#define redyHP_clr			BIT_CLR_M(3461)			//*����� ����� "���������� � ��"
#define redyHP_tst			BIT_TST_M(3461)			//*�������� ����� "���������� � ��"

#define readyClear_set		BIT_SET_M(3462)			//*��������� ����� "���������� � ��������"
#define readyClear_clr		BIT_CLR_M(3462)			//*����� ����� "���������� � ��������"
#define readyClear_tst		BIT_TST_M(3462)			//*�������� ����� "���������� � ��������"

#define R_raskStV_set		BIT_SET_M(3463)			//*��������� ����� "��������� �� ��������"
#define R_raskStV_clr		BIT_CLR_M(3463)			//*����� ����� "��������� �� ��������"
#define R_raskStV_tst		BIT_TST_M(3463)			//*�������� ����� "��������� �� ��������"

#define R_fire_set			BIT_SET_M(3464)			//*��������� ����� "����� ������"
#define R_fire_clr			BIT_CLR_M(3464)			//*����� ����� "����� ������"
#define R_fire_tst			BIT_TST_M(3464)			//*�������� ����� "����� ������"

#define R_rate_set			BIT_SET_M(3465)			//*��������� ����� "����� �������"
#define R_rate_clr			BIT_CLR_M(3465)			//*����� ����� "����� �������"
#define R_rate_tst			BIT_TST_M(3465)			//*�������� ����� "����� �������"

#define R_promGo_set		BIT_SET_M(3466)			//*��������� ����� "�������� ����"
#define R_promGo_clr		BIT_CLR_M(3466)			//*����� ����� "�������� ����"
#define R_promGo_tst		BIT_TST_M(3466)			//*�������� ����� "�������� ����"

#define R_promEnd_set		BIT_SET_M(3467)			//*��������� ����� "����� ��������"
#define R_promEnd_clr		BIT_CLR_M(3467)			//*����� ����� "����� ��������"
#define R_promEnd_tst		BIT_CLR_M(3467)			//*�������� ����� "����� ��������"

#define R_kt_stabST_set		BIT_SET_M(3468)			//*��������� ����� "������ ������������ �������� ��"
#define R_kt_stabST_clr		BIT_CLR_M(3468)			//*����� ����� "������ ������������ �������� ��"

#define R_kt_heatMG_set		BIT_SET_M(3469)			//*��������� ����� "������ �������� �� ����������� ������"
#define R_kt_heatMG_clr		BIT_CLR_M(3469)			//*����� ����� "������ �������� �� ����������� ������"

#define R_kt_GG_set			BIT_SET_M(3470)			//*��������� ����� "������ ������������ �������� ��"
#define R_kt_GG_clr			BIT_CLR_M(3470)			//*����� ����� "������ ������������ �������� ��"

#define R_kt_ogrMG_set		BIT_SET_M(3471)			//*��������� ����� "������ ����������� nvd �� ����������� ������"
#define R_kt_ogrMG_clr		BIT_CLR_M(3471)			//*����� ����� "������ ����������� nvd �� ����������� ������"

#define R_kt_sbros_set		BIT_SET_M(3472)			//*��������� ����� "������ ������ �� ����������� �����"
#define R_kt_sbros_clr		BIT_CLR_M(3472)			//*����� ����� "������ ������ �� ����������� �����"

#define R_kt_down_set		BIT_SET_M(3473)			//*��������� ����� "������ ����������� ������������ ����� ��� ������ "������""
#define R_kt_down_clr		BIT_CLR_M(3473)			//*����� ����� "������ ����������� ������������ ����� ��� ������ "������""

#define R_kt_Nvdogr_up_set	BIT_SET_M(3474)			//*��������� ����� "������ ����������� Nvd ������"
#define R_kt_Nvdogr_up_clr	BIT_CLR_M(3474)			//*����� ����� "������ ����������� Nvd ������"

#define R_kt_Nstogr_down_set	BIT_SET_M(3475)		//*��������� ����� "������ ����������� Nst �����"
#define R_kt_Nstogr_down_clr	BIT_CLR_M(3475)		//*����� ����� "������ ����������� Nst �����"

#define R_kt_Nstogr_up_set	BIT_SET_M(3476)			//*��������� ����� "������ ����������� Nst ������"
#define R_kt_Nstogr_up_clr	BIT_CLR_M(3476)			//*����� ����� "������ ����������� Nst ������"

#define R_kt_n_point_set	BIT_SET_M(3477)			//*��������� ����� "������ n � ������ �� �������"
#define R_kt_n_point_clr	BIT_CLR_M(3477)			//*����� ����� "������ n � ������ �� �������"

#define R_kt_up_set			BIT_SET_M(3478)			//*��������� ����� "������ ����������� ������������ ������ ��� ������ "������""
#define R_kt_up_clr			BIT_CLR_M(3478)			//*����� ����� "������ ����������� ������������ ������ ��� ������ "������""

#define R_kt_fire_set		BIT_SET_M(3479)			//*��������� ����� "������ �������"
#define R_kt_fire_clr		BIT_CLR_M(3479)			//*����� ����� "������ �������"

#define R_kt_ogrGt_zap_set	BIT_SET_M(3480)			//*��������� ����� "������ ����������� ������� ������� �� �������"
#define R_kt_ogrGt_zap_clr	BIT_CLR_M(3480)			//*����� ����� "������ ����������� ������� ������� �� �������"

#define R_kt_ogrdGt_zap_set	BIT_SET_M(3481)			//*��������� ����� "������ ����������� �������� ���������� ������� ������� �� �������"
#define R_kt_ogrdGt_zap_clr	BIT_CLR_M(3481)			//*����� ����� "������ ����������� �������� ���������� ������� ������� �� �������"

#define R_kt_ogrGt_osn_set	BIT_SET_M(3482)			//*��������� ����� "������ ����������� ������� ������� �� �������� �������"
#define R_kt_ogrGt_osn_clr	BIT_CLR_M(3482)			//*����� ����� "������ ����������� ������� ������� �� �������� �������"

#define R_kt_Pk_set			BIT_SET_M(3483)			//*��������� ����� "������ ����������� P�"
#define R_kt_Pk_clr			BIT_CLR_M(3483)			//*����� ����� "������ ����������� P�"

#define R_kt_Tt_set			BIT_SET_M(3484)			//*��������� ����� "������ ����������� Tt"
#define R_kt_Tt_clr			BIT_CLR_M(3484)			//*����� ����� "������ ����������� Tt"

#define R_kt_GtPk_set		BIT_SET_M(3485)			//*��������� ����� "������ ����������� Gt/Pk"
#define R_kt_GtPk_clr		BIT_CLR_M(3485)			//*����� ����� "������ ����������� Gt/Pk"
//

#define downDI				0 //BIT_TST_M(3023)			//*������� �� ���������� ������ ���������� ������ - ���������� ����� 
                                                                      
//������������
#define Kp_Tt			RF(1271)				//����������� ���������������� ������� ��
#define Kp_Pk			RF(1273)				//����������� ���������������� ������� Pk
#define K1_st			RF(1275)				//����������� 1 ��
#define K2_st			RF(1277)				//����������� 2 ��
#define K3_st			RF(1279)				//����������� 3 ��
#define Kp_dop			RF(1793)				//�������������� ���������� ���������������� Nvd
#define Ki_dop			RF(1795)				//�������������� ���������� ������������ Nvd

//		�������� ���������� ������� ���������� ����������		//	RF (3410)...RF(3450) 	������
#define setSK_ON_set		BIT_SET_M(3401)			//*������� ��
#define setSK_ON_clr		BIT_CLR_M(3401)			//*������� ��
#define setSK_ON_tst		BIT_TST_M(3401)			//*������� ��

#define KPV_ON				BIT_SET_M(3402)			//*������� ���
#define KPV_OFF				BIT_CLR_M(3402)			//*������� ���
#define KPV_ON_tst	 		BIT_TST_M(3402)			//*�������/�������  ���

#define KPG_ON				BIT_SET_M(3403)			//*������� ��� � ����
#define KPG_OFF				BIT_CLR_M(3403)			//*������� ��� � ����
#define KPG_ON_tst			BIT_TST_M(3403)			//*�������/�������  ��� � ����

#define SZ_set				BIT_SET_M(3404)			//*������� ��������� ��������
#define SZ_clr				BIT_CLR_M(3404)			//*������� ��������� ��������
#define SZ_tst				BIT_TST_M(3404)			//*�������� ������� �� ��������� ��������

#define VZ_set				BIT_SET_M(3405)			//*������� ��������� ��������
#define VZ_clr				BIT_CLR_M(3405)			//*������� ��������� ��������
#define VZ_tst				BIT_TST_M(3405)			//*�������� ������� �� ��������� ��������

#define AZ1_set				BIT_SET_M(3406)			//*�������� ������� ��������� 1
#define AZ1_clr				BIT_CLR_M(3406)			//*��������� ������� ��������� 1
#define AZ1_tst				BIT_TST_M(3406)			//*������� �� ������� ��������� 1

#define AZ2_set				BIT_SET_M(3407)			//*�������� ������� ��������� 2
#define AZ2_clr				BIT_CLR_M(3407)			//*��������� ������� ��������� 2
#define AZ2_tst				BIT_TST_M(3407)			//*������� �� ������� ��������� 2

#define A_common_set		BIT_SET_M(3408)			//*��������� ����� "����� ������ �� ���"
#define A_common_clr		BIT_CLR_M(3408)			//*����� ����� "����� ������ �� ���"
#define A_common_tst		BIT_TST_M(3408)			//*�������� ����� "����� ������ �� ���"

#define N_common_set		BIT_SET_M(3409)			//*��������� ����� "����� ������ ����������� �������� �� ���"
#define N_common_clr		BIT_CLR_M(3409)			//*����� ����� "����� ������ ����������� �������� �� ���"
#define N_common_tst		BIT_TST_M(3409)			//*�������� ����� "����� ������ ����������� �������� �� ���"

#define setSK_OFF_set		BIT_SET_M(3410)			//*������� ��
#define setSK_OFF_clr		BIT_CLR_M(3410)			//*������� ��
#define setSK_OFF_tst		BIT_TST_M(3410)			//*������� ��

#define setSK_ON1_set		BIT_SET_M(3411)			//*������� ��
#define setSK_ON1_clr		BIT_CLR_M(3411)			//*������� ��
#define setSK_ON1_tst		BIT_TST_M(3411)			//*������� ��

// ��� ������� ���������� ��������������� �����������
#define manual_upr_VNA_tst 		BIT_TST_M(3713)			//*������/�������������� ���������� ���
#define manual_upr_VNA_clr 		BIT_CLR_M(3713)			//*������/�������������� ���������� ���

#define manual_upr_DOZ_tst 		BIT_TST_M(3714)			//*������/�������������� ���������� ���
#define manual_upr_DOZ_clr 		BIT_CLR_M(3714)			//*������/�������������� ���������� ���

#define manual_upr_SK_tst 		BIT_TST_M(3715)			//*������/�������������� ���������� ��
#define manual_upr_SK_clr 		BIT_CLR_M(3715)			//*������/�������������� ���������� ��
#define manual_SK_ON_tst 		BIT_TST_M(3716)			//*������� �� � ��
#define manual_SK_OF_tst 		BIT_TST_M(3717)			//*������� �� � ��

#define manual_upr_KPV_tst 		BIT_TST_M(3718)			//*������/�������������� ���������� ��� ���
#define manual_upr_KPV_clr 		BIT_CLR_M(3718)			//*������/�������������� ���������� ��� ���
#define manual_KPV_ON_tst 		BIT_TST_M(3719)			//*������� ��� ��� � ��
#define manual_KPV_OF_tst 		BIT_TST_M(3720)			//*������� ��� ��� � ��

#define manual_upr_KPG_tst		BIT_TST_M(3721)			//*������/�������������� ���������� ���� ���
#define manual_upr_KPG_clr		BIT_CLR_M(3721)			//*������/�������������� ���������� ���� ���
#define manual_KPG_ON_tst 		BIT_TST_M(3722)			//*������� ���� ��� � ��
#define manual_KPG_OF_tst 		BIT_TST_M(3723)			//*������� ���� ��� � ��

#define manual_upr_SZ_tst 		BIT_TST_M(3724)			//*������/�������������� ���������� �� ���
#define manual_upr_SZ_clr 		BIT_CLR_M(3724)			//*������/�������������� ���������� �� ���
#define manual_SZ_ON_tst 		BIT_TST_M(3725)			//*������� �� ��� � ��
#define manual_SZ_OF_tst 		BIT_TST_M(3726)			//*������� �� ��� � ��

#define manual_upr_VZ_tst 		BIT_TST_M(3727)			//*������/�������������� ���������� �� ���
#define manual_upr_VZ_clr 		BIT_CLR_M(3727)			//*������/�������������� ���������� �� ���
#define manual_VZ_ON_tst 		BIT_TST_M(3728)			//*������� �� ��� � ��
#define manual_VZ_OF_tst 		BIT_TST_M(3729)			//*������� �� ��� � ��

#define manual_upr_AZ1_tst 		BIT_TST_M(3730)			//*������/�������������� ���������� �� �1
#define manual_upr_AZ1_clr 		BIT_CLR_M(3730)			//*������/�������������� ���������� �� �1
#define manual_AZ1_ON_tst 		BIT_TST_M(3731)			//*�������� �� �1 � ��
#define manual_AZ1_OF_tst 		BIT_TST_M(3732)			//*��������� �� �1 � ��

#define manual_upr_AZ2_tst 		BIT_TST_M(3733)			//*������/�������������� ���������� �� �2
#define manual_upr_AZ2_clr 		BIT_CLR_M(3733)			//*������/�������������� ���������� �� �2
#define manual_AZ2_ON_tst 		BIT_TST_M(3734)			//*�������� �� �2 � ��
#define manual_AZ2_OF_tst 		BIT_TST_M(3735)			//*��������� �� �2 � ��



//
//#define KPG_ON2				BIT_SET_M(3412)			//*������� ��� � ���� ��������
//#define KPG_OFF2				BIT_CLR_M(3412)			//*������� ��� � ���� ��������
#define P_PtgHigh_set		BIT_SET_M(3517)			//*��������� ����� "�������� ���������� ���� �������"
#define P_PtgHigh_clr		BIT_CLR_M(3517)			//*����� ����� "�������� ���������� ���� �������"
#define P_PtgHigh_tst		BIT_TST_M(3517)			//*�������� ����� "�������� ���������� ���� �������"
#define P_PtgLow_set		BIT_SET_M(3514)			//*��������� ����� "�������� ���������� ���� ������"
#define P_PtgLow_clr		BIT_CLR_M(3514)			//*����� ����� "�������� ���������� ���� ������"
#define P_PtgLow_tst		BIT_TST_M(3514)			//*�������� ����� "�������� ���������� ���� ������"

//
//#define Delta_GtPk			RF(1627)			//�������� �������� ����������� � �������� ������� Gt/Pk ��� ������ �� �����

#define fireTimer			RF(1655)				//**������ ������� � ������� �������� ��
#define integOut			RF(1661)				//**�������� ����������� � �������� ������� (��/�)
#define IntegNvd			RF(1663)				//**���������� Nvd
#define CTvhNvd				RF(1665)				//**����������� ��������� nvd �� ���
#define nvd_ust				RF(1669)				//������� ������� nvd 
#define DeltaVNA			RF(1791)				//�������� ������� �� ��� ������ �����


////���������� �����������
//��������� ���������
#define CND_STOP			1		//��������� ����������
#define CND_STARTER			2		//��������� ���������
#define CND_FIRE			3		//������ ������ ��������
#define CND_RATE			4		//������ �� ������ ����
#define CND_STAB			5		//����� ������ ���������
#define CND_AO				6		//��������� �������

//����������� �������� �������������
#define kt_stabST			195		//������ ������������ �������� ��
#define kt_heatMG			120		//������ �������� �� ����������� ������
#define kt_GG				145		//������ ������������ �������� ��
#define kt_ogrMG			122		//������ ����������� nvd �� ����������� ������
#define kt_sbros			130		//������ ������ �� ����������� �����
#define kt_down				140		//������ ����������� ������������ ����� ��� ������ "������"
#define kt_Nvdogr_up		150		//������ ����������� Nvd ������
#define kt_Nvdogr_up_pr		151		//������ ����������� Nvd ������ �����������
#define kt_Nstogr_down		196		//������ ����������� Nst �����
#define kt_Nstogr_up		197		//������ ����������� Nst ������
#define kt_n_point			170		//������ n � ������ �� �������
#define kt_up				190		//������ ����������� ������������ ������ ��� ������ "������"
#define kt_fire				200		//������ �������
#define kt_ogrGt_zap		300		//������ ����������� ������� ������� �� �������
#define kt_ogrdGt_zap		350		//������ ����������� �������� ���������� ������� ������� �� �������
#define kt_ogrGt_osn		400		//������ ����������� ������� ������� �� �������� �������
#define kt_Pk				500		//������ ����������� P�
#define kt_Tt				600		//������ ����������� Tt
#define kt_GtPk				700		//������ ����������� Gt/Pk



#define Kdot				0.3		//����������� �������
#define K_d_VNA				1		//����������� ��� ���������� ���,

//���������� ������� �� ���������� ���
//

/*#define VTshtoka1_set			BIT_SET_M(3418)			//���-�� "���������� ����� 1-��� ���������������� ��� (� 0)"
#define VTshtoka1_clr			BIT_CLR_M(3418)			//�����  "���������� ����� 1-��� ���������������� ��� (� 0)"

#define VITshtoka1_set			BIT_SET_M(3419)			//���-�� "����������� ����� 1-��� ���������������� ��� (� -45)"
#define VITshtoka1_clr			BIT_CLR_M(3419)			//�����  "����������� ����� 1-��� ���������������� ��� (� -45)"

#define VTshtoka2_set			BIT_SET_M(3413)			//���-�� "���������� ����� 2-��� ���������������� ��� (� 0)"
#define VTshtoka2_clr			BIT_CLR_M(3413)			//�����  "���������� ����� 2-��� ���������������� ��� (� 0)"

#define VITshtoka2_set			BIT_SET_M(3415)			//���-�� "����������� ����� 2-��� ���������������� ��� (� -45)"
#define VITshtoka2_clr			BIT_CLR_M(3415)			//�����  "����������� ����� 2-��� ���������������� ��� (� -45)"
*/

/*
void TRegDoz (float Ptopl)//������� ��������� ������� � ����������� ���� ���������
{setDoz =0.068306*(Gt_tek*sqrt((Tpdtg+273)/293)/Ptopl-22.67);
if (setDoz<0) setDoz = 0;
if (setDoz>97) setDoz = 97;}
*/

void TRegDoz (float Ptopl)//������� ��������� ������� � ����������� ���� ���������
{
if (Ptopl < 1.9) Ptopl = 1.9;
	else if (Ptopl > 4.1) Ptopl = 4.1;

b = ( (1.43 * posDOZ/100.0) / ( 1 + 1.43*posDOZ/100.0)) * ( (1.43 * posDOZ/100.0) / ( 1 + 1.43*posDOZ/100.0))
 * ( (1.43 * posDOZ/100.0) / ( 1 + 1.43*posDOZ/100.0));  
P2 = b * (Ptopl - Pkvd) + Pkvd;
fo = harakt(K_IoutDoz,P2/Ptopl);
K = 1/(5.65685 * (Ptopl/sqrt(Tpdtg + 273)) * fo);
setDoz = harakt(IoutDoz, K*Gt_tek);
if (setDoz<0) setDoz = 0;
if (setDoz>97) setDoz = 97;}

 


int GefMain(void)
{



//��������� ������//

int I,i,war;	
static char	gotoStopToStarter;				// ��������� ��������
static char	gotoToAO;
static char	gotoStarterToStop;
static char	gotoStarterToFire;
static char	gotoFireToRate;
static char	gotoRateToStab;
static char	gotoStabToStop;
static char	gotoAOToStop;
//static char	Slow_Wna;
static float	temperPrev;	//���� ������� static//����������� �� ���������� ���������� �� �������
static float	TempRoz;						//�������� ��������� ������� �� �������
static float	n_point;						//�������� ��������� �� �������
static float	Out_fire;						//�������� �� ������ ������� �������
static float	Out_kt_Nvd;						//����� ������� Nvd (����� ������� ���������)
//static float	Out_kt_ogrGtzap;							//�������� ������� ����������� ������� �� �������
static float	Out_kt_ogrdGtzap;				//�������� ������� ����������� �������� ����� ������� �� �������
static float	Out_sel1;						//����� ��������� 1
static float	Out_sel2;						//����� ��������� 2
static float	Kprop_Nvd;						//����������� ������������������ Nvd
static char		up_old;					     	//�������� ������ "������" �� ���������� �����
static char		down_old;		        		//�������� ������ "������" �� ���������� �����
static char 	st_old;			        		//�������� ������ "������" �� ���������� �����
//static float		nvd_ust;							//������� ������� nvd
static float	Out_sel1_min;					//����� ��������� �������� � ��������� Nvd
static int		Metka_sel1_min;					//����� ������� ����� ��������� �������� � ��������� Nvd
static float	Out_Pk;							//����� ������� P�
static float	Out_Tt;							//����� ������� ��
static float	Out_GtPk;						//����� ������� Gt/Pk
static float	nst_ust_min;					//������� ������� �� � ������� ��������
static float	integr_ST;						//���������� ������� ��
static float	dST;							//���������� ���������� � ������� ��
static float	Out_ST;							//����� ������� ��
static float	Out_kt_MG;
static float	Out_MG;
static float	IntegNvdMG;
/*static float    delta_VNA;						//�������� ����������� ���������� ��� (� �������� �� 0...7)
static float	deltVNA1,deltVNA2,deltVNA3,deltVNA4;		//���������� ��� ���������� deltVNA
static float	pr_deltVNA;						//���������� deltVNA
static float    kor_deltVNA;						//��������� deltVNA	
static float	rasVNA;							//�������� ��� ���������� ���� ������������������ ���
static float	rasVNA_f;							//�������� ��� ���������� ���� ������������������ ��� �������������
static float    deltVNA;							//������ ��� ���������� ��� (�������� ����� �������� � ������� ��������� ��������� �� ���) 
static float	sravVNA;							//�������� ��� ��������� ��� 
static float    srmeasureVNA;						//������� �������� ��� (�� 2-�� �������� �����)
*/

static float Reg_VNA;						//*����������� ��������� ��� (������������ �������� ��������� �� ��� n�� ��)
static float Reg_KPV_ON;					//*����������� �������� ���
static float Reg_KPV_OFF;					//*����������� �������� ���
static float Reg_KPG_ON;					//*����������� �������� ��� � ����
static float Reg_KPG_OFF;					//*����������� �������� ��� � ����
static float Reg_Gt_roz;					//*����������� ������� �� �������
//static float Reg_Gt_ogr_zap;				//*����������� ����������� ������� �� �������
static float Reg_Gt_ogr;					//*����������� ������������ �������� ������� ���������� ����
static float Reg_GtPk_ogr;  				//*����������� ����������� Gt/Pk
static float Reg_Usk_ST;					//����������� ��������� �� ���������
static float Reg_Usk;						//����������� ��������� ��� ��������
static float Reg_Gt_RozN;					//����������� ���������� ������� �� �������
static float Reg_Gt_RozK;					//����������� ��������� ������� �� �������
static float Reg_dG_Zap;					//����������� �������� ��������� ����������� ������� �� �������
static int 	Starter_Old;					//������� ������ ��������



static float AZ1timer;
static float AZ2timer;						
static char	manual_SK_ON;
static char	manual_KPV_ON;
static char	manual_KPG_ON;
static char	manual_SZ_ON;
static char	manual_VZ_ON;
static char	manual_AZ1_ON;
static char	manual_AZ2_ON;
static float setSK_ON_timer;
static float setSK_OF_timer;

if (condition == 0) condition = 1;

//�������� ����� �����������
if (updateTun) {

Reg_VNA= 0.0;

if ((Reg_KPV_ON_u >= -1000.0)&&(Reg_KPV_ON_u <= 1000.0)) 		Reg_KPV_ON = Reg_KPV_ON_u;			//����������� �������� ���
if ((Reg_KPV_OFF_u >= -1000.0)&&(Reg_KPV_OFF_u <= 1000.0)) 		Reg_KPV_OFF = Reg_KPV_OFF_u;		//����������� �������� ���
if ((Reg_KPG_ON_u >= -1000.0)&&(Reg_KPG_ON_u <= 1000.0)) 		Reg_KPG_ON = Reg_KPG_ON_u;			//����������� �������� ��� � ����
if ((Reg_KPG_OFF_u >= -1000.0)&&(Reg_KPG_OFF_u <= 1000.0)) 		Reg_KPG_OFF = Reg_KPG_OFF_u;		//����������� �������� ��� � ����	
if ((Reg_Gt_roz_u >= -220.0)&&(Reg_Gt_roz_u <= 130.0)) 			Reg_Gt_roz = Reg_Gt_roz_u;			//�����������  ������� �� �������
//if ((Reg_Gt_ogr_zap_u >= -300.0)&&(Reg_Gt_ogr_zap_u <= 300.0)) 	Reg_Gt_ogr_zap = Reg_Gt_ogr_zap_u;							//����������� ����������� ������� �� ������� 
if ((Reg_Gt_ogr_u >= -500.0)&&(Reg_Gt_ogr_u <= 500.0)) 			Reg_Gt_ogr = Reg_Gt_ogr_u;			//����������� �������� ������������� ������� ���������� ����
if ((Reg_GtPk_ogr_u >= -1.5)&&(Reg_GtPk_ogr_u <= 1.5)) 			Reg_GtPk_ogr = Reg_GtPk_ogr_u;		//����������� �������� ����������� G�/�� (������������ �������� ��������� �� ��� G�/��)
if ((Reg_Usk_ST_u >= -0.5)&&(Reg_Usk_ST_u <= 0.5)) 				Reg_Usk_ST = Reg_Usk_ST_u;			// ����������� ��������� �� ������� �� ���������
if ((Reg_Usk_u >= -0.5)&&(Reg_Usk_u <= 0.5)) 					Reg_Usk = Reg_Usk_u;				// ����������� ��������� �� ������� ��� ��������	
if ((Reg_Gt_RozN_u >= 0.0)&&(Reg_Gt_RozN_u <=350.0))			Reg_Gt_RozN = Reg_Gt_RozN_u;		//����������� ���������� ������� �� �������
if ((Reg_Gt_RozK_u >= -350.0)&&(Reg_Gt_RozK_u <=100.0))			Reg_Gt_RozK = Reg_Gt_RozK_u;		//����������� ��������� ������� �� �������

if ((Reg_dG_Zap_u >= -0.9)&&(Reg_dG_Zap_u <=5.0))				Reg_dG_Zap = Reg_dG_Zap_u;			//����������� �������� ��������� ����������� ������� �� �������


}
Gt_roz_ust = Gt_roz + Reg_Gt_roz;
Gt_ogr_ust = Reg_Gt_ogr + GT_max;
GtPk_ogr_ust = sqrt(Tvh/288.134)*harakt(GtdivPk,nvdNorm)*(1+Reg_GtPk_ogr)*Pkvd;
KPV_ON_ust = nvdOpenKPV + Reg_KPV_ON;
KPV_OFF_ust = nvdCloseKPV + Reg_KPV_OFF;
KPG_ON_ust = nvdOpenKPG + Reg_KPG_ON;
KPG_OFF_ust = nvdCloseKPG + Reg_KPG_OFF;
Usk_ST_ust = harakt(NvdTodNvd_STV,nvd)*(1+Reg_Usk_ST);
Usk_ust = harakt(NvdTodNvd,nvd)*(1+Reg_Usk);
Gt_roz_min_ust = Gt_roz_min + Reg_Gt_RozN;
Gt_roz_max_ust = Gt_roz_max + Reg_Gt_RozK;
dGt_ogr_zap_ust = (1+Reg_dG_Zap)*harakt(dGt_zap,nvdNorm);

//����������� �����������
	if init_tst {
		KPV_OFF;
		KPG_OFF;
		//KPG_OFF2;
		set_VNA = harakt(setVNA,0);}
	else {
		if (nvdNorm <= KPV_ON_ust) KPV_ON;
		if ((nvdNorm >= KPV_OFF_ust)||(nvd < nvdCloseLow)) KPV_OFF;
		//��� �������������� ���������� ����
		if (nvdNorm <= KPG_ON_ust) KPG_ON;
		if ((nvdNorm >= KPG_OFF_ust)||(nvd < nvdCloseLow)) KPG_OFF;
		
 
		//��� �������� ��� � ������ �������� ����� � ��������� "AO" �""����
		if (!(check&&(nvd<100)&&((condition == CND_AO)||(condition == CND_STOP)))) set_VNA = harakt(setVNA,nvdNorm + Reg_VNA);
		//set_VNA = harakt(setVNA,nvdNorm + Reg_VNA);
//�������� ��� �� ��!
		if ((HP_tst) && (HPTimer>=40) && (HPTimer<70))
		{
		if ((HP_tst) && (HPTimer>=40) && (HPTimer<50)) set_VNA = -45.0 + 45.0/10.0*(HPTimer - 40);//��� ������� ��� �� ��
		else if ((HP_tst) && (HPTimer>=50) && (HPTimer<55)) set_VNA = 0.0;
		else if ((HP_tst) && (HPTimer>=55) && (HPTimer<65)) set_VNA = 0.0 - 45.0/10.0*(HPTimer - 55);
		else set_VNA = harakt(setVNA,nvdNorm + Reg_VNA);}
		else if ((HP_tst) && (HPTimer>=70) && (HPTimer<95)) {
		if ((HP_tst) && (HPTimer>=70) && (HPTimer<80)) set_VNA = -45.0 + 45.0/10.0*(HPTimer - 70);//��� ������� ��� �� ��
		else if ((HP_tst) && (HPTimer>=80) && (HPTimer<85)) set_VNA = 0.0;
		else if ((HP_tst) && (HPTimer>=85) && (HPTimer<95)) set_VNA = 0.0 - 45.0/10.0*(HPTimer - 85);
		else set_VNA = harakt(setVNA,nvdNorm + Reg_VNA);}

	}

	if (condition == CND_AO) {
		if (!(check&&(nvd<100)))set_VNA = harakt(setVNA,0);//!��� �������� ��� � ������ �������� ����� � ��������� "AO" �""����
		KPV_ON;
		KPG_ON;
		if (nvd < nvdCloseLow) {
			KPV_OFF;
			KPG_OFF;
			}
	}
// �� ������ �������� ����������� ��� � �������� ���, ���� � ���
	if R_promGo_tst {
		KPV_OFF; 
		KPG_OFF;
		if (VZ_tst) promTimer+=cycle;
		set_VNA = harakt(PromVNA,promTimer);
	}
//�������������
	if (init_tst) {
		//������������� dNgg_Select

		//������������� selektor_Gt
		//������������� regDoz
		R_promEnd_clr;
		R_promGo_clr;
		endHP_clr;
		HP_clr;
		engineStarted_clr;
		NO_clr;
		condition = CND_STOP;
		HPTimer = 0;
		startTimer = 0;
		fireTimer = 0;
		heatTimer = 0;
		coolTimer = 0;
		promTimer = 0;
		setDoz = 0;//������ ������� �� ������ �������� ��������, ��� �������� �������������
		integr_ST = 0;
		setSK_ON1_clr;
		SZ_clr;
		VZ_clr;
		AZ1_clr;
		AZ2_clr;
		Kp_Tt = KpTt;
        Kp_Pk = KpPk;
		K1_st = K1st;
		K2_st = K2st;
		K3_st = K3st;
}
	else {




	
//�������� ���������//

//������������ �������� ��� �������
if 	((((fireTimer > maxFireTime) && (condition == CND_FIRE)) || notFire_tst) && (! externDeblock)) notFire_set; else notFire_clr;
//������������ �������� ��� ���������
if (longZAP)
{if ((((nvd <= RateGG) && startEngine_tst && (startTimer >= (timeStarterOff + longTime))) || notRateGG_tst) && (! externDeblock)) notRateGG_set; else notRateGG_clr;}
else {if ((((nvd <= RateGG) && (startTimer >= timeStarterOff)) || notRateGG_tst) && (! externDeblock)) notRateGG_set; else notRateGG_clr;}

//������������ �������� "����� ������� ������"
if (startTimer >= 310.0) TimeZapHigh_set;
	else {if (externDeblock) TimeZapHigh_clr;}

//������������ ����� ������ � ����������
if (A_common_tst || notFire_tst || notRateGG_tst || TimeZapHigh_tst) A_common_set; else A_common_clr;
//������������ �������� �������� ��������� ����
if (((startHP && start && redyHP_tst && !startEngine_tst && !engineStarted_tst) || HP_tst) && (!endHP_tst)) HP_set; else HP_clr;
//������������ �������� �������� ����
if (((startProm && start && readyClear_tst && !startEngine_tst && !engineStarted_tst) || R_promGo_tst) && (!R_promEnd_tst)) R_promGo_set; else R_promGo_clr;
//������������ �������� ������� ���������
if (((start && !startHP && redyStart_tst && !startProm && !R_promGo_tst && !HP_tst) || startEngine_tst) && !(engineStarted_tst))  startEngine_set; else startEngine_clr;

//if (P_PtgHigh_tst || P_PtgLow_tst) BIT_SET_M(3713);

//������������ �������� �������� ���������
if (engineStarted_tst && (condition == CND_RATE)) heat_set; else heat_clr;
//������ �� ���������� ��������� ��������
if ((startEngine_tst || HP_tst || R_promGo_tst) && (nvd < 100)) gotoStopToStarter = 1; else gotoStopToStarter = 0;
//if ((startHP || start) && (nvd < 100)) BIT_SET_M(3713); //else BIT_CLR_M(3713);

if (A_common_tst || externAO) gotoToAO = 1; else {if externDeblock gotoToAO = 0;}

if (longZAP) 
{if (HP_tst && (HPTimer > (HPTimeHP + longTimeHP)))  {gotoStarterToStop = 1; HP_clr; endHP_set;} else gotoStarterToStop = 0;}
else {if (HP_tst && (HPTimer > HPTimeHP))  {gotoStarterToStop = 1; HP_clr; endHP_set;} else gotoStarterToStop = 0;}

//if (R_promGo_tst && (promTimer > PromTime))  {gotoStarterToStop = 1; R_promGo_clr; R_promEnd_set;}  else gotoStarterToStop = 0;

if (longZAP)
{if (startEngine_tst && (((startTimer > (FireTime + longTime)) || (startTimer > (ignitionTime + longTime))) && (nvd > fireNgg))) gotoStarterToFire = 1; else gotoStarterToFire = 0;}
else {if (startEngine_tst && (((startTimer > FireTime) || (startTimer > ignitionTime)) && (nvd > fireNgg))) gotoStarterToFire = 1; else gotoStarterToFire = 0;}

if (firePresent_tst && (Gt_tek>=Gt_roz_ust)) gotoFireToRate = 1; else gotoFireToRate = 0;//������ ����������, ����� ���� ������ � ����� �� ������� �������

if (heat_tst && (heatTimer >= HeatTime)) gotoRateToStab = 1; else gotoRateToStab = 0;

if (coolTimer >= CoolTime) gotoStabToStop = 1; else gotoStabToStop = 0;

if (stop || N_common_tst) NO_set;//������������ ����� ����������� ��������

if ((condition == CND_AO) && SK_OFF_tst && (nvd < 100) && (Pkvd < 2) && !gotoToAO) gotoAOToStop = 1; else gotoAOToStop = 0;

if (condition == 2) R_raskStV_set; else R_raskStV_clr;
if (condition == 3) R_fire_set; else R_fire_clr;
if (condition == 4) R_rate_set; else R_rate_clr;


	switch (condition) {
     case CND_STOP:
		 //dNgg_Select
		 //selektor_Gt
		 //regDoz
		 //RegNvd

		 firePresent_clr;
		 Metka = 0;
		 Gt_tek = 0;
		 HPTimer = 0;
		 startTimer = 0;
		 fireTimer = 0;
		 heatTimer = 0;
		 coolTimer = 0;
		 promTimer = 0;
		 Nst_Ust = 0;
		 if (!(check)) setDoz = 0;//��� �������� �������� � ������ �������� ����� � ��������� "����"
		 //setDoz = 0;//��� �������� �������� � ������ �������� ����� � ��������� "����"
		 setSK_ON1_clr;//������� ��
		 if (nvd < 50) endHP_clr;//����� �� ���� ������������� �������� init ����� ��
		 engineStarted_clr;
		 NO_clr;
		 BIT_SET_M(3713);
		 temperPrev = 0;
		 SZ_clr;
		 VZ_clr;
		 AZ1_clr;
		 AZ2_clr;
         Kp_dop = 25.0;
		 Ki_dop = 1.0;
		 Kp_Tt = KpTt;
         Kp_Pk = KpPk;
		 K1_st = K1st;
		 K2_st = K2st;
		 K3_st = K3st;
		 if (gotoToAO) condition = CND_AO; 
		 else {
			 if (gotoStopToStarter) {
				 HPTimer = 0;
				 startTimer = 0;
				 promTimer = 0;
				 condition = CND_STARTER;
			 }
		 }
		 
	 break;	 
     case CND_STARTER:
		 if (HPTimer < 1000000) HPTimer += cycle;
		 if (startTimer < 1000000) startTimer = startTimer + cycle;
		 SZ_set;
		 if (startTimer > 10) VZ_set;
		 setDoz = 0;//������ ������� �� ������ �������� ��������
		 if (gotoToAO) {//������� � ��
			 SZ_clr;
			 VZ_clr;
			 endHP_set;
			 R_promEnd_set;
			 condition = CND_AO;
		     HP_clr;
			 R_promGo_clr;}//��������� �������. ��� � �� ��������� ��� ��������� CND_AO
		 if (gotoStarterToStop) {//������� � �����
			 SZ_clr;
			 VZ_clr;
			 condition = CND_STOP;
		     HP_clr;
			 R_promGo_clr;}
		 if (gotoStarterToFire) {//������� � �������
			 temperPrev = Ttzap;//��������� �����������, �������������� �������
			 Metka = kt_fire;
			 TempRoz = (Gt_roz_max_ust - Gt_roz_min_ust)/(maxFireTime - 2);
			 condition = CND_FIRE;
			 fireTimer = 0.0;} 

	 break;
	 case CND_FIRE:
		 if (startTimer < 1000000) startTimer += cycle;//���������� ������� ����� �������
		 
		if (longZAP)
		 {if ((startTimer > (ignitionTime + longTime)) && (fireTimer < timeIgnitionOff )) {
			 AZ1_set;
			 AZ2_set;}
		 else {
			 AZ1_clr;
			 AZ2_clr;}
		 if (startTimer < (FireTime + longTime)) temperPrev = temperPrev/*Ttzap*/;//��������� �����������, �������������� �������
		 else {
			 if (fireTimer < 1000000) fireTimer += cycle;//������� ����� � ������� �������� ��
			 setSK_ON1_set;//��������� ��
			 //
			 if ((Ttzap - temperPrev) > dTIgnition) firePresent_set;//���� ��������� ������������ �� ����� ����������� �� ��������� � ������������ � ������ �������
			 if (fireTimer < (maxFireTime - 2.0)) Gt_tek = TempRoz*fireTimer + Gt_roz_min_ust;//����������� ������ ������ �� ���������
			 if (fireTimer > 3) TRegDoz (Ptgpd); else TRegDoz (Ptg);//��� ��������� ������� �� P�� ������ 3 ������� ���������� �������� ����� ��
		 }}
		else {if ((startTimer > ignitionTime) && (fireTimer < timeIgnitionOff )) {
			 AZ1_set;
			 AZ2_set;}
		 else {
			 AZ1_clr;
			 AZ2_clr;}
		 if (startTimer < FireTime) temperPrev = temperPrev/*Ttzap*/;//��������� �����������, �������������� �������
		 else {
			 if (fireTimer < 1000000) fireTimer += cycle;//������� ����� � ������� �������� ��
			 setSK_ON1_set;//��������� ��
			 if ((Ttzap - temperPrev) > dTIgnition) firePresent_set;//���� ��������� ������������ �� ����� ����������� �� ��������� � ������������ � ������ �������
			 if (fireTimer < (maxFireTime - 2.0)) Gt_tek = TempRoz*fireTimer + Gt_roz_min_ust;//����������� ������ ������ �� ���������
			 if (fireTimer > 3) TRegDoz (Ptgpd); else TRegDoz (Ptg);//��� ��������� ������� �� P�� ������ 3 ������� ���������� �������� ����� ��
		 }}


		 if (gotoToAO) {
			 AZ1_clr;
			 AZ2_clr;
			 SZ_clr;
			 VZ_clr;
			 //��������� ������� � ��. ��� � �� ������������ ��������� CND_AO
			 condition = CND_AO;
		 }
		 if (gotoFireToRate) {
			 //������������� ���������� ����� ��������
			 IntegNvd = nvd;
			 Gt_tek = Gt_roz_ust;
			 integOut = Gt_tek;
			 condition = CND_RATE;
			 }
		 
	 break;	 
     case CND_RATE:
		 //
		 if (startTimer < 1000000) startTimer += cycle;//���������� ������� ����� �������!
		 if AZ1_tst fireTimer += cycle;
		 if ((nvd > NggIgnOff) || (fireTimer >= timeIgnitionOff )) {AZ1_clr;AZ2_clr;}//��������� �� ���� Ngg>4000 ��� ����� ������ �� > 20�
		 
		if (longZAP)
		 {if ((nvd > NggStarterOff) || (startTimer >= (timeStarterOff + longTime))) {
			 SZ_clr;
			 VZ_clr;
			 n_point = Usk_ust*harakt(dNggToVTZ,Ttzap_ogr_ust-Tt);}
		 else n_point = Usk_ST_ust*harakt(dNggToVTZ,Ttzap_ogr_ust-Tt);}
		else {if ((nvd > NggStarterOff) || (startTimer >= timeStarterOff)) {
			 SZ_clr;
			 VZ_clr;
			 n_point = Usk_ust*harakt(dNggToVTZ,Ttzap_ogr_ust-Tt);}
		 else n_point = Usk_ST_ust*harakt(dNggToVTZ,Ttzap_ogr_ust-Tt);}

		 //�������� ��������
		 Out_sel1 = (Ngg_MG_ust - IntegNvd)*Kdot;
		 Metka = kt_heatMG;
		 if (Out_sel1 < n_point) Metka = kt_heatMG;
		 else {
			 Out_sel1 = n_point;
			 Metka = kt_n_point;}
		 
		 if ((Starter_Old == 1) && !(VZ_tst)) IntegNvd = nvd;
			else IntegNvd += Out_sel1*cycle;
		 
		 //IntegNvd += Out_sel1*cycle;
		 Out_fire = Gt_roz_ust - Gt_tek;
		 Kprop_Nvd = harakt(KpropNvd,nvd);
		 Out_sel2 = (Out_sel1*KfNvd + IntegNvd - nvd)*Kprop_Nvd;
		 //Out_kt_ogrGtzap = (harakt(Gt_zap,nvdNorm) + Reg_Gt_ogr_zap)*(1 + harakt(KtGtTinZap,Tvh))*sqrt(Tvh/288.134) - Gt_tek;
		 Out_kt_ogrdGtzap = harakt(dNggToVTZ,Ttzap_ogr_ust-Tt)*dGt_ogr_zap_ust;
		 if (Out_fire > Out_sel2) {
			 Metka = kt_fire;
			 Out_sel2 = Out_fire;
			 IntegNvd = nvd + Out_sel2/Kprop_Nvd - Out_sel1*KfNvd;
		 }
		/* if (Out_kt_ogrGtzap < Out_sel2) {
			 Metka = kt_ogrGt_zap;
			 Out_sel2 = Out_kt_ogrGtzap;
			 IntegNvd = nvd + Out_sel2/Kprop_Nvd - Out_sel1*KfNvd;
		 }
		 */
		 if (Out_kt_ogrdGtzap < Out_sel2) {
			 Metka = kt_ogrdGt_zap;
			 Out_sel2 = Out_kt_ogrdGtzap;
			 IntegNvd = nvd + Out_sel2/Kprop_Nvd - Out_sel1*KfNvd;
		 }
		 //RF(8003) = Out_sel1;
		 //rf(1671) = IntegNvd;
		 //RF(1641) = Out_sel2;
		 integOut +=  cycle*Out_sel2*harakt(KintegDoz,nvd);
		 Gt_tek = integOut + Out_sel2;
		 if (fireTimer > 3) TRegDoz (Ptgpd); else TRegDoz (Ptg);//��� ��������� ������� �� P�� ������ 3 ������� ���������� �������� ����� ��
		 if ((nvd >= 8000) || (nst >= 2700))  engineStarted_set;
		 //if ((Ngg_MG_ust - nvd) < 20) engineStarted_set;
		 if ((heatTimer < 1000000) && heat_tst) heatTimer += cycle;
		 if (gotoToAO) {
			 AZ1_clr;
			 AZ2_clr;
			 SZ_clr;
			 VZ_clr;
			 //��������� ������� � ��. ��� � �� ������������ ��������� CND_AO
			 condition = CND_AO;
		 }
		 if (gotoRateToStab) {
			 condition = CND_STAB;
			 up_old = 1;
			 down_old = 1;
			 st_old=1;
			 nvd_ust = nvd/CTvhNvd;
			 
		 }
		 

	 break;
	 case CND_STAB:
		 //���������� ������� nvd
		 if ((up_old && !up) || (down_old && !(down || downDI)) || (st_old && !stabST_on)) nvd_ust = nvd/CTvhNvd;// ��� �������� 25 ��������� ��� /CTvhNvd;
		 up_old = up;
		 down_old = down;
		 st_old = stabST_on;

		 //������� N��

		  if (stabST_on && !NO_tst) {
			 nst_ust_min = Nst_Ust;
			 if (Nst_Ust < minValNst1) nst_ust_min = minValNst1;
			 if (Nst_Ust > Nst_ogr_ust) nst_ust_min = Nst_ogr_ust;
			 dST = nst_ust_min - nst - integr_ST;
		 if (Metka != kt_stabST) integr_ST = 0;
		 else integr_ST += K1_st*cycle*dST;
		 Out_ST = K3_st*(integr_ST + K2_st*dST);		  
		  }
		  else {nst_ust_min = Nst_ogr_ust;
			dST = nst_ust_min - nst;
			integr_ST += Kd_st*cycle*(dST*Kp_st-integr_ST);
			Out_ST = 15*dST*Kp_st - integr_ST;}

		 //�������� n��
		 
		 Out_sel1_min = (Ngg_max_ust - IntegNvd)*Kdot;
		 Metka_sel1_min = kt_Nvdogr_up;
		 if (Out_sel1_min > dNgg_UP) {
			 Out_sel1_min = dNgg_UP;
			 Metka_sel1_min = kt_up;}
     	if ((!stabST_on)&&(Out_sel1_min > Out_ST)) {
			 Out_sel1_min = Out_ST;
			 Metka_sel1_min = kt_Nstogr_up;}


		 if (((!up)&&(!stabST_on))||(((nst_ust_min - nst) <0)&&(stabST_on)) || NO_tst) {
			 //Out_sel1 = (Ngg_MG_ust - IntegNvd)*Kdot;
			 //Metka = kt_ogrMG;

			 if NO_tst Out_sel1 = dNgg_SBROS;
			 else Out_sel1 = dNgg_DOWN;//{
				 //if (Out_sel1 < dNgg_SBROS) {
				//	 Out_sel1 = dNgg_SBROS;
				//	 Metka = kt_down;}}
			 //else {
			//	 if (Out_sel1 < dNgg_DOWN) {
			//		 Out_sel1 = dNgg_DOWN;
					 Metka = kt_down;//}}
			 if (!(down||downDI) && !NO_tst && !stabST_on && (Out_sel1 < (nvd_ust*CTvhNvd/* ��� �������� 25 ��������� ��� *CTvhNvd */ - IntegNvd)*Kdot)) {
				 Out_sel1 = (nvd_ust*CTvhNvd - IntegNvd)*Kdot;
				 Metka = kt_GG;}
			 if (Out_sel1_min < Out_sel1) {
				 Out_sel1 = Out_sel1_min;
				 Metka = Metka_sel1_min;}
			 else Metka_sel1_min = Metka;}
		 else {
			 Out_sel1 = Out_sel1_min;
			 Metka = Metka_sel1_min;}
		 
		// RF(1785)=Metka;
		 Out_MG = (Ngg_MG_ust - IntegNvd)*Kdot;
		 IntegNvdMG = IntegNvd + Out_MG*cycle;

		 IntegNvd += Out_sel1*cycle;
		 Kprop_Nvd = Kp_dop*harakt(KpropNvd,nvd);
		 Out_kt_Nvd = (Out_sel1*KfNvd + IntegNvd - nvd)*Kprop_Nvd;
		 Out_kt_MG = (Out_MG*KfNvd + IntegNvdMG - nvd)*Kprop_Nvd;
		

		 




		 //������ ��������
		 
//������ N��
		
//RF(1783)=Out_ST;
//RF(1785)=Out_kt_Nvd;

Out_sel2 = Out_kt_Nvd;
if (stabST_on && !NO_tst) {


		 if ((nst_ust_min - nst) <0) {

if (Out_ST > Out_kt_Nvd) {
			 Out_sel2 = Out_ST;
			 Metka = kt_stabST;
			 }
}
else {

if (Out_ST < Out_kt_Nvd) {
			 Out_sel2 = Out_ST;
			 Metka = kt_stabST;
			 }
}}

    
//������ ����������� ������� �������
		 
		 if ((Gt_ogr_ust - Gt_tek) < Out_sel2) {
			 Out_sel2 = Gt_ogr_ust - Gt_tek;
			 Metka = kt_ogrGt_osn;}

		 //������ ����������� ��
		 Out_Tt = (Tt_ogr_ust - Tt)*Kp_Tt;
		 if (Out_Tt < Out_sel2) {
			 Out_sel2 = Out_Tt;

			 Metka = kt_Tt;}

		 //������ ����������� Pk
		 Out_Pk = (Pk_ogr_ust - Pkvd)*Kp_Pk;
		 if (Out_Pk < Out_sel2) {
			 Out_sel2 = Out_Pk;
			 Metka = kt_Pk;}
		 
		 //������ ����������� Gt/Pk
		 Out_GtPk = GtPk_ogr_ust - Gt_tek;
		 if (Out_GtPk < Out_sel2) {
			 Out_sel2 = Out_GtPk;
			 Metka = kt_GtPk;}

//         Delta_GtPk = Out_GtPk; 
		 
RF(1781)=Out_Tt;
RF(1783)=Metka;
RF(1785)=Gt_tek;
RF(1787)=GtPk_ogr_ust;
RF(1789)=Out_Pk;


		 //||�������� ���������
		 if (Out_kt_MG > Out_sel2) {
			 Out_sel2 = Out_kt_MG;
			 Metka = kt_ogrMG;
			 IntegNvd = IntegNvdMG;}

		 //��������� ����������� ��� ����������� �������� � ������� �� ������!
		 if (Metka > kt_up) {
			 IntegNvd = nvd;// + Out_sel2/Kprop_Nvd - Out_sel1*KfNvd;
			 
		 }


		 //���������� �������
		// RF(1789)=Out_sel2;

		 integOut +=  cycle*Out_sel2*Ki_dop*harakt(KintegDoz,nvd);
		 Gt_tek = integOut + Out_sel2;
		 TRegDoz (Ptgpd);

		 if ((coolTimer < 1000000) && NO_tst) coolTimer += cycle;

		 if (gotoStabToStop) 
		 {condition = CND_STOP;
		 firePresent_clr;
		 Metka = 0;
		 Gt_tek = 0;
		 HPTimer = 0;
		 startTimer = 0;
		 HP_clr;

		 fireTimer = 0;
		 heatTimer = 0;
		 coolTimer = 0;
		 Nst_Ust = 0;
		 setDoz = 0;
		 NO_clr;
		 setSK_ON1_clr;//������� ��
		 if (nvd < 50) endHP_clr;//����� �� ���� ������������� �������� init ����� ��
		 engineStarted_clr;
		 startEngine_clr;
		 heat_clr;}


		 if (gotoToAO) {condition = CND_AO;setDoz = 0;}

	 break;
	 case CND_AO:
		 firePresent_clr;
		 Metka = 0;
		 Gt_tek = 0;
		 HPTimer = 0;
		 startTimer = 0;
		 HP_clr;
		 SZ_clr;
		 VZ_clr;
		 AZ1_clr;
		 AZ2_clr;
		 fireTimer = 0;
		 heatTimer = 0;
		 coolTimer = 0;
		 promTimer = 0;
		 Nst_Ust = 0;
		 if (!(check&&(nvd<100))) setDoz = 0;//��� �������� �������� � ������ �������� ����� � ��������� "��"
		 //setDoz = 0;//��� �������� �������� � ������ �������� ����� � ��������� "��"
		 NO_clr;
		 setSK_ON1_clr;//������� ��
		 if (nvd < 50) endHP_clr;//����� �� ���� ������������� �������� init ����� ��
		 engineStarted_clr;
		 startEngine_clr;
		 heat_clr;
		 
		 if (gotoAOToStop) condition = CND_STOP;	 
	 break;}

}
if (gotoStopToStarter) {VibegGGTimer=0; VibegSTTimer=0;}

RF(1517) = RF(1517) - 273;

RF(1519) = RF(1519) - 273;

RF(1521) = RF(1521) - 273;

RF(1523) = RF(1523) - 273;

if (VZ_tst) Starter_Old = 1;
	else Starter_Old = 0;

	
		// !������ ���������� ��������������� �����������
// ������ ���������� ���������
if (!(((condition == CND_STOP)||(condition == CND_AO))&&(nvd<100)&& check &&(Ptgpd<0.03)&& SK_OFF_tst)) manual_upr_DOZ_clr;
if (manual_upr_DOZ_tst) setDoz = manual_setDOZ;
	else manual_setDOZ = 0;
	
	// ������ ���������� ���
if (!(((condition == CND_STOP)||(condition == CND_AO))&&(nvd<100)&& check &&(Ptgpd<0.03)&& SK_OFF_tst)) manual_upr_VNA_clr;
if (manual_upr_VNA_tst) set_VNA = manual_setVNA;
	else manual_setVNA = -45.0;
	
	
	
	

// ������ ���������� ��
if (!(((condition == CND_STOP)||(condition == CND_AO))&&(nvd<100)&& check &&(Ptg<0.03)&&(posDOZ<0.5))) manual_upr_SK_clr;
if (manual_upr_SK_tst)
	{if (manual_SK_ON_tst) manual_SK_ON = 1;
	 if (manual_SK_OF_tst) manual_SK_ON = 0;
	 if (manual_SK_ON) setSK_ON1_set;
		else setSK_ON1_clr;
	}
if (setSK_ON1_tst) setSK_ON_timer += cycle;
if (setSK_ON_timer > 10.0) setSK_ON_timer = 10.0; 
if (!setSK_ON1_tst) setSK_OF_timer += cycle;
if (setSK_OF_timer > 10.0) setSK_OF_timer = 10.0; 

if (setSK_ON1_tst && (setSK_ON_timer < 10.0)) {setSK_ON_set; setSK_OF_timer = 0.0;}
	else setSK_ON_clr;
if ((!setSK_ON1_tst) && (setSK_OF_timer < 10.0)) {setSK_OFF_set; setSK_ON_timer = 0.0;}
	else setSK_OFF_clr;
	
// ������ ���������� ���	
if (!(((condition == CND_STOP)||(condition == CND_AO))&&(nvd<100)&& check)) manual_upr_KPV_clr;
if (manual_upr_KPV_tst)
	{if (manual_KPV_ON_tst) manual_KPV_ON = 1;
	 if (manual_KPV_OF_tst) manual_KPV_ON = 0;
	 if (manual_KPV_ON) KPV_ON;
		else KPV_OFF;
	}

	// ������ ���������� ����
if (!(((condition == CND_STOP)||(condition == CND_AO))&&(nvd<100)&& check)) manual_upr_KPG_clr;
if (manual_upr_KPG_tst)
	{if (manual_KPG_ON_tst) manual_KPG_ON = 1;
	 if (manual_KPG_OF_tst) manual_KPG_ON = 0;
	 if (manual_KPG_ON) KPG_ON;
		else KPG_OFF;
	}

	// ������ ���������� ��
if (!(((condition == CND_STOP)||(condition == CND_AO))&&(nvd<100)&& check &&(PgInStV<0.03)&&(!VZ_tst))) manual_upr_SZ_clr;
if (manual_upr_SZ_tst)
	{if (manual_SZ_ON_tst) manual_SZ_ON = 1;
	 if (manual_SZ_OF_tst) manual_SZ_ON = 0;
	 if (manual_SZ_ON) SZ_set;
		else SZ_clr;
	}

	// ������ ���������� ��
if (!(((condition == CND_STOP)||(condition == CND_AO))&&(nvd<100)&& check &&(PgInStV<0.03)&&(!SZ_tst))) manual_upr_VZ_clr;
if (manual_upr_VZ_tst)
	{if (manual_VZ_ON_tst) manual_VZ_ON = 1;
	 if (manual_VZ_OF_tst) manual_VZ_ON = 0;
	 if (manual_VZ_ON) VZ_set;
		else VZ_clr;
	}
	
	// ������ ���������� ��1
if (!(((condition == CND_STOP)||(condition == CND_AO))&&(nvd<100)&& check &&(AZ1timer < 30.0))) manual_upr_AZ1_clr;
if (manual_upr_AZ1_tst)
	{if (manual_AZ1_ON_tst) manual_AZ1_ON = 1;
	 if (manual_AZ1_OF_tst) manual_AZ1_ON = 0;
	 if (manual_AZ1_ON) AZ1_set;
		else AZ1_clr;
	}
if (AZ1_tst) AZ1timer += cycle;
		else AZ1timer = 0.0;
if (AZ1timer > 30.0) AZ1timer = 30.0;
	
// ������ ���������� ��2
if (!(((condition == CND_STOP)||(condition == CND_AO))&&(nvd<100)&& check &&(AZ2timer < 30.0))) manual_upr_AZ2_clr;
if (manual_upr_AZ2_tst)
	{if (manual_AZ2_ON_tst) manual_AZ2_ON = 1;
	 if (manual_AZ2_OF_tst) manual_AZ2_ON = 0;
	 if (manual_AZ2_ON) AZ2_set;
		else AZ2_clr;
	}
if (AZ2_tst) AZ2timer += cycle;
		else AZ2timer = 0.0;
if (AZ2timer > 30.0) AZ2timer = 30.0;

return GEF_EXECUTION_OK;
}
