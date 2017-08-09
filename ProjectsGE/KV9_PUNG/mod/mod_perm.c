// ������ ��������� 16 ���

#include "math.h"     // �������������� �������
#include "PACRXPlc.h" //��������� ��� �����������
//#include "data.h"     //��������� � ��������������
#include "dataMod.h"  //�������������� ������
// ���������
#define NORM_T     288.15    //���� ������������������ ������� ���, %
#define NORM_P     1.033     //�������� ��������� ������� ���, %/�
#define M_PI       3.1415926 //���� ������������������ ������� ���, ��
#define integStep  0.02      //��� ��������������, ���. 
/////
// ������� ���������� 
#define init_tst   BIT_TST_M(3702) //�������������
#define AZ1_set	   BIT_SET_M(3406) //�������� ������� ��������� 1
#define AZ1_clr	   BIT_CLR_M(3406) //��������� ������� ��������� 1
#define AZ1_tst	   BIT_TST_M(3406) //��������� ������� ��������� 1
#define AZ2_set	   BIT_SET_M(3407) //�������� ������� ��������� 2
#define AZ2_clr	   BIT_CLR_M(3407) //��������� ������� ��������� 2
#define AZ2_tst	   BIT_TST_M(3407) //��������� ������� ��������� 2
#define SZ_set	   BIT_SET_M(3404) //������� ��������� ��������
#define SZ_clr	   BIT_CLR_M(3404) //������� ��������� ��������
#define SZ_tst	   BIT_TST_M(3404) //������� ��������� ��������
#define VZ_set	   BIT_SET_M(3405) //������� ��������� ��������
#define VZ_clr	   BIT_CLR_M(3405) //������� ��������� ��������
#define VZ_tst	   BIT_TST_M(3405) //��������� ��������� ��������� ��������
#define start_set  BIT_SET_M(3706) //������� ������� ���������
#define start_clr  BIT_CLR_M(3706) //������ ������� ������� ���������
#define start_tst  BIT_TST_M(3706) //�������� ������� ������� ������� ���������

#define EnginWorks_set BIT_SET_M(3456) //���� "��������� ��������"
#define EnginWorks_clr BIT_CLR_M(3456) //����� ���� "��������� ��������"
#define EnginWorks_tst BIT_TST_M(3456) //�������� ������� ������� "��������� ��������"

#define cycle	   RF(1701)		   //����� ����� (� ��������)
#define Ptg		   RF(1705)		   //�������� ���������� ���� ����� ��
#define DG_POZ     RF(1703)        //��������� �������� ����, %
//#define PVNA_V     RW(1401)        //��������� ��� �������, ����.
#define Tatm       288.15        //����������� ������� �� ����� � ���, ����.������� 
#define Patm       1.033        //������ �������� ������� �� ����� � ���


// �������� ���������� 
// ��������� ���������
#define NGG1    			RF(1721)				//������� �������� �� - 1-� �����(13000 ��/��� = 13000 �.�.)
#define NGG2    			RF(1723)				//������� �������� �� - 2-� �����(13000 ��/��� = 13000 �.�.)
#define NST1    			RF(1725)				//������� �������� �� - 1-� �����(9000 ��/��� = 9000 �.�.)
#define NST2    			RF(1727)				//������� �������� �� - 2-� �����(9000 ��/��� = 9000 �.�.)

// ������ ��������� ��������
#define PK_I    			RF(1777)				//���. �������� ������� �� ������������ 0...2.5 ���

// ��������� (-50...1000 ���� � = -500...10000 �.�.)
#define TTXG1    			RF(1779)				//� ���� �� �� �� ������� �1
#define TTXG2    			RF(1781)				//� ���� �� �� �� ������� �2

#define TTXH1    			RF(1729)				//������ ����������� ���� �� �� �� ������� 1
#define TTXH2    			RF(1731)				//������ ����������� ���� �� �� �� ������� 2
#define TTXH3    			RF(1733)				//������ ����������� ���� �� �� �� ������� 3
#define TTXH4    			RF(1735)				//������ ����������� ���� �� �� �� ������� 4
#define TTXH5    			RF(1737)				//������ ����������� ���� �� �� �� ������� 5
#define TTXH6    			RF(1739)				//������ ����������� ���� �� �� �� ������� 6
#define TTXH7    			RF(1741)				//������ ����������� ���� �� �� �� ������� 7
#define TTXH8    			RF(1743)				//������ ����������� ���� �� �� �� ������� 8
#define TTXH9    			RF(1745)				//������ ����������� ���� �� �� �� ������� 9
#define TTXH10    			RF(1747)				//������ ����������� ���� �� �� �� ������� 10
#define TTXH11    			RF(1749)				//������ ����������� ���� �� �� �� ������� 11

#define TTXH12    			RF(1751)				//������ ����������� ���� �� �� �� ������� 12

#define TTXL1    			RF(1753)				//������ ����������� ���� �� �� �� ������� 1
#define TTXL2    			RF(1755)				//������ ����������� ���� �� �� �� ������� 2
#define TTXL3    			RF(1757)				//������ ����������� ���� �� �� �� ������� 3
#define TTXL4    			RF(1759)				//������ ����������� ���� �� �� �� ������� 4
#define TTXL5    			RF(1761)				//������ ����������� ���� �� �� �� ������� 5
#define TTXL6    			RF(1763)				//������ ����������� ���� �� �� �� ������� 6
#define TTXL7    			RF(1765)				//������ ����������� ���� �� �� �� ������� 7
#define TTXL8    			RF(1767)				//������ ����������� ���� �� �� �� ������� 8
#define TTXL9    			RF(1769)				//������ ����������� ���� �� �� �� ������� 9
#define TTXL10    			RF(1771)				//������ ����������� ���� �� �� �� ������� 10
#define TTXL11    			RF(1773)				//������ ����������� ���� �� �� �� ������� 11
#define TTXL12    			RF(1775)				//������ ����������� ���� �� �� �� ������� 12





#define Nvd		   RF(1511)		   //������� �������� ������ �������������� ����� ��������� � ���
/*

#define Nst		   RF(1515)		   //������� �������� ������ ��������� �������
#define Tt		   RF(1521)		   //������ ����������� ���� �� �������� ��������������
#define Tst		   RF(1523)		   //������ ����������� ���� �� ��������� ��������
#define Pkvd	   RF(1527)		   //�������� ������� �� ������������ �� ���
*/


//#define Gt_tek	   RF(1133)		   //������ ������� �� ������ �� ���������� �������
#define set_VNA	   RF(1503)		   //������� �� ���
//#define set_DUS	   RF(1103)		   //������� �� �������
#define Nvd0		RF(1667)		//���������� Nvd

int GefMain(void) { //������ ��������

// ��������� ����������
static int   TimeInteg,i; 
//int   StepQuantity; 
static int   StartTrigger;  

static float Gt;       
static float Mst;      
static float Gt0t;     
static float Gt0n;     

//static float Nvd;		   		   //������� �������� ������ �������������� ����� ��������� � ���
static float Nst;		   		   //������� �������� ������ ��������� �������
static float Tt;		  		   //������ ����������� ���� �� �������� ��������������
static float Tst;		  		   //������ ����������� ���� �� ��������� ��������
static float Pkvd;	   			   //�������� ������� �� ������������ �� ���


//float Nvd0;     
static float Fvna;
static float kNormP;   
static float kNormT;   
//float IntegStep;
static float MstToNvdfunc; 
static float Nvd0ToA1func; 
static float Nvd0ToA2func; 
static float Nvd0ToA3func; 
static float Nvd0ToA4func; 
static float Gt0ToNvd0func; 
static float Nvd0ToGt0func; 
static float Nvd0ToPowfunc; 
static float Nvd0ToPk0func; 
static float ZsVSToNvd0func; 
static float Nvd0ToTst0func;
static float Nvd0ToTauvd0func; 
static float YdusMainToGtfunc;
static float Gt0startToNvd0func; 
static float YdusMain;
static float Nvd0ToA5func; 
static float Nvd0ToA6func; 
static float test_NVD;
static float test_NVD1;

test_NVD    =harakt(ZsVSToNvd0,    RF(10013));
RF(10011) = test_NVD;

if (init_tst)  {// �������������

    Tt=0;
    Gt=0;
    Nst=0;
    Mst=231;
    Nvd=0;
    Nvd0=0;
    Gt0t=0;
    Gt0n=0;
    Fvna=0;
    Pkvd=0;
    kNormT=1;
    kNormP=1;
    StartTrigger = 0;
    YdusMain=DG_POZ; 


	YdusMainToGtfunc=harakt(YdusMainToGt,DG_POZ);
	Gt0ToNvd0func   =harakt(Gt0ToNvd0,   Gt0t);
	Nvd0ToPowfunc   =harakt(Nvd0ToPow,   Nvd0);
    Nvd0ToTst0func  =harakt(Nvd0ToTst0,  Nvd0);
    Nvd0ToPk0func   =harakt(Nvd0ToPk0,   Nvd0);
	
	Gt=YdusMainToGtfunc;
	Nvd0=Gt0ToNvd0func;
    Nvd=Nvd0/kNormT;
 	kNormT=1;//sqrt(NORM_T/(Tatm+273.15));
    kNormP=NORM_P/Patm;
    Gt0t=Gt*kNormT*kNormP;
    Gt0n=Gt0t;
    Fvna=set_VNA;
    //Nst=sqrt(Nvd0ToPowfunc/POW_COEFF);
    Pkvd=Nvd0ToPk0func;
    Tt=Nvd0ToTst0func;

    if (Nvd<10)  Nvd =10; 
    if (Nvd0<10) Nvd0=10; 
    if (Nst<10)  Nst =10; 

} 
else {// ���������� ������
    //StepQuantity = cycle/0.02 + 0.5;
	//for (TimeInteg=1; TimeInteg<=StepQuantity; TimeInteg++)  {// ���� ��������������
	//i = 2;
	//	while (i--) {
    if (Nvd<10)  Nvd =10;
    if (Nvd0<10) Nvd0=10;
    if (Nst<10)  Nst =10;

       MstToNvdfunc    =harakt(MstToNvd0,    Nvd0);
       Nvd0ToPowfunc   =harakt(Nvd0ToPow,   Nvd0);
       Nvd0ToTst0func  =harakt(Nvd0ToTst0,  Nvd0);
       Nvd0ToPk0func   =harakt(Nvd0ToPk0,   Nvd0);
       Nvd0ToTauvd0func=harakt(Nvd0ToTauvd0,Nvd0);
       Nvd0ToA1func    =harakt(Nvd0ToA1,    Nvd0);
       Nvd0ToA2func    =harakt(Nvd0ToA2,    Nvd0);
       Nvd0ToA3func    =harakt(Nvd0ToA3,    Nvd0);
       Nvd0ToA4func    =harakt(Nvd0ToA4,    Nvd0);
       Nvd0ToA5func    =harakt(Nvd0ToA5,    Nvd0);
       Nvd0ToA6func    =harakt(Nvd0ToA6,    Nvd0);
       ZsVSToNvd0func  =harakt(ZsVSToNvd0,  Nvd0);
       Gt0startToNvd0func=harakt(Gt0startToNvd0,Nvd0);
       YdusMain=DG_POZ; 

//      if (set_DUS - YdusMain > _DUS_DZ) YdusMain = YdusMain + integStep*DUS_RATE;
//      else YdusMain = YdusMain -integStep*DUS_RATE;
      

	   if (Nvd0>8750) { 
        if (StartTrigger) StartTrigger=0; // ������� �� ��������� ������ � �������
	   }
	   if ((Nvd0<8740) && !((DG_POZ<10) && !VZ_tst)) {
		   if (!StartTrigger) StartTrigger = 1;
       // ������� �� �������  ������ � ���������
       // ��������� ������ ������������� � ����� ����������� � ��� ����������������
       // ������� ������, ������� ��� ������ ������������ ������� ������ 
       }
    YdusMainToGtfunc =harakt(YdusMainToGt, DG_POZ);
    Gt=YdusMainToGtfunc*Ptg/1.8; // ���� ���� �������� ��������� �� �������� ��      
    
	if (StartTrigger) {
		if (VZ_tst) Mst=1;
	}
    else Mst=0; 
    
	kNormT=1;//sqrt(NORM_T/(Tatm+273.15));
    kNormP=1;//NORM_P/Patm;                 
    Nvd0  =Nvd*kNormT;
    Gt0t  =Gt*kNormT*kNormP;
    
    Gt0ToNvd0func =harakt(Gt0ToNvd0, Gt0t);
    Nvd0ToGt0func =harakt(Nvd0ToGt0, Nvd0);
    
    Gt0n=Nvd0ToGt0func;
    Fvna=set_VNA;

	if (StartTrigger)  // ��������� ������
	{
		//RF(1679) = RF(1677);
	//RF(10019) = Nvd0;
    MstToNvdfunc      =harakt(MstToNvd0,     Nvd0);
    ZsVSToNvd0func    =harakt(ZsVSToNvd0,    Nvd0);
    Gt0startToNvd0func=harakt(Gt0startToNvd0,Nvd0);
	
	//RF(1671) = harakt(ZsVSToNvd0,RF(1669));
	//RF(1675) = RF(1673);
		
	if (VZ_tst) {Nvd0=Nvd0+cycle*((ZsVSToNvd0func)-Mst*MstToNvdfunc+Gt0t*Gt0startToNvd0func)*1000.0*(30.0/M_PI)*(30.0/M_PI)/(12.17*Nvd0);
		//if (Nvd0>3000) Nvd0=3000;
	//RF(10001) = Nvd0;
	//RF(10003) = ZsVSToNvd0func;
	//RF(10005) = Mst*MstToNvdfunc;
	//RF(10007) = cycle*(ZsVSToNvd0func-Mst*MstToNvdfunc+Gt0t*Gt0startToNvd0func)*1000.0*(30.0/M_PI)*(30.0/M_PI)/(12.17*Nvd0);
    //RF(10009) = Gt0t*Gt0startToNvd0func;
	}
        else        Nvd0=Nvd0+cycle*(-Mst*MstToNvdfunc+Gt0t*Gt0startToNvd0func)* 1000.0*(30.0/M_PI)*(30.0/M_PI)/(12.17*Nvd0);
                    Pkvd=Nvd0ToPk0func;
	
	} else {// ������� ������
		//RF(1679) = Gt0ToNvd0func;
		Nvd0=Nvd0+cycle*((Gt0ToNvd0func-Nvd0)/Nvd0ToTauvd0func+Nvd0ToA4func*(Fvna-set_VNA)/Nvd0ToTauvd0func);
		Pkvd=(Nvd0ToPk0func+Nvd0ToA2func*(Gt0t-Gt0n)/Gt0n)/kNormP+(Fvna-set_VNA)*Nvd0ToA5func;
	}
    
	if (Gt>50) Nst=Nst+cycle*30000*1.2*((Nvd0ToPowfunc+Nvd0ToA1func*(Gt0t-Gt0n)/Gt0n)/(kNormT*kNormP)-POW_COEFF*Nst*Nst)/((J_ST+J_N)*M_PI*Nst);
    // � ���������� ��������, ���������� � ��, ������� ������������ ���� ��������� �� ������� �������� ������� ����� �������,
    // ����� ��� �������� ���������� ������������ �������������
    else Nst=Nst+cycle*30000.0*(-POW_COEFF*Nst*Nst)/((J_ST+J_N)*M_PI*Nst);
	
//RF(10051) = Gt;
//RF(10053) = Nvd0ToPowfunc;
//RF(10055) = (Nvd0ToA1func*(Gt0t-Gt0n)/Gt0n)/(kNormT*kNormP);
//RF(10057) = POW_COEFF*Nst*Nst;
//RF(10059) = (J_ST+J_N)*M_PI*Nst;
//RF(10049) = cycle*30000*((Nvd0ToPowfunc+Nvd0ToA1func*(Gt0t-Gt0n)/Gt0n)/(kNormT*kNormP)-POW_COEFF*Nst*Nst)/((J_ST+J_N)*M_PI*Nst);
//RF(10047) = cycle*30000.0*(-POW_COEFF*Nst*Nst)/((J_ST+J_N)*M_PI*Nst);
    if (Gt0t>120) { 
		if (AZ1_tst || EnginWorks_tst)  
    Tt=(Nvd0ToTst0func+Nvd0ToA3func*(Gt0t-Gt0n)/Gt0n)*(Tatm)/NORM_T+(Fvna-set_VNA)*Nvd0ToA6func;
	}
    else Tt=Tatm + 160.0;
    
	Nvd=Nvd0/kNormT;

//} //end for  

    if (Nvd<10)  Nvd =10;
    if (Nvd0<10) Nvd0=10;
    if (Nst<10)  Nst =10;
}
//RF(1141) = Tt;//��� �������
	NGG1 = (double)Nvd;// + RW(1140) + RW(1141);   							//������� �������� �� - 1-� �����(13000 ��/��� = 13000 �.�.)
	NGG2 = (double)Nvd;// + RW(1140) + RW(1142);    							//������� �������� �� - 2-� �����(13000 ��/��� = 13000 �.�.)

	NST1 = (double)Nst;//+ RW(1150) + RW(1151);    							//������� �������� �� - 1-� �����(9000 ��/��� = 9000 �.�.)
	NST2 = (double)Nst;//+ RW(1150) + RW(1152);    							//������� �������� �� - 2-� �����(9000 ��/��� = 9000 �.�.)

	PK_I = (double)Pkvd/10; //+ RF(8003);   							//���. �������� ������� �� ������������ 0...2.5 ���

	TTXG1 = (double)(Tt-273);// + RW(1161);					//� ���� �� �� �� ������� �1
	TTXG2 = (double)(Tt-273);// + RW(1162);    				//� ���� �� �� �� ������� �2

	TTXH1 = (double)(Tt-273);// + RW(1090);// + RW(1091);    							//������ ����������� ���� �� �� �� ������� 1
	TTXH2 = (double)(Tt-273);// + RW(1090);// + RW(1092);    							//������ ����������� ���� �� �� �� ������� 2
	TTXH3 = (double)(Tt-273);// + RW(1090);//+ RW(1093);    							//������ ����������� ���� �� �� �� ������� 3
	TTXH4 = (double)(Tt-273);// + RW(1090);// + RW(1094);    							//������ ����������� ���� �� �� �� ������� 4
	TTXH5 = (double)(Tt-273);// + RW(1090);//+ RW(1095);    							//������ ����������� ���� �� �� �� ������� 5
	TTXH6 = (double)(Tt-273);// + RW(1090);// + RW(1096);    							//������ ����������� ���� �� �� �� ������� 6
	TTXH7 = (double)(Tt-273);// + RW(1090);// + RW(1097);    							//������ ����������� ���� �� �� �� ������� 7
	TTXH8 = (double)(Tt-273);// + RW(1090);// + RW(1098);    							//������ ���������� ���� �� �� �� ������� 8
	TTXH9 = (double)(Tt-273);// + RW(1090);// + RW(1099);    							//������ ����������� ���� �� �� �� ������� 9
	TTXH10 = (double)(Tt-273);// + RW(1090);// + RW(1110);   							//������ ����������� ���� �� �� �� ������� 10
	TTXH11 = (double)(Tt-273);// + RW(1090);// + RW(1111);   							//������ ����������� ���� �� �� �� ������� 11
	TTXH12 = (double)(Tt-273);// + RW(1090);// + RW(1112);   							//������ ����������� ���� �� �� �� ������� 12

	TTXL1 = (double)(Tt-273);// + RW(1120) + RW(1121);    							//������ ����������� ���� �� �� �� ������� 1
	TTXL2 = (double)(Tt-273);// + RW(1120) + RW(1122);    							//������ ����������� ���� �� �� �� ������� 2
	TTXL3 = (double)(Tt-273);// + RW(1120) + RW(1123);    							//������ ����������� ���� �� �� �� ������� 3
	TTXL4 = (double)(Tt-273);// + RW(1120) + RW(1124);    							//������ ����������� ���� �� �� �� ������� 4
	TTXL5 = (double)(Tt-273);// + RW(1120) + RW(1125);    							//������ ����������� ���� �� �� �� ������� 5
	TTXL6 = (double)(Tt-273);// + RW(1120) + RW(1126);    							//������ ����������� ���� �� �� �� ������� 6
	TTXL7 = (double)(Tt-273);// + RW(1120) + RW(1127);    							//������ ����������� ���� �� �� �� ������� 7

	TTXL8 = (double)(Tt-273);// + RW(1120) + RW(1128);    							//������ ����������� ���� �� �� �� ������� 8
	TTXL9 = (double)(Tt-273);//+ RW(1120) + RW(1129);    							//������ ����������� ���� �� �� �� ������� 9
	TTXL10 = (double)(Tt-273);// + RW(1120) + RW(1130);   							//������ ����������� ���� �� �� �� ������� 10
	TTXL11 = (double)(Tt-273);// + RW(1120) + RW(1131);   							//������ ����������� ���� �� �� �� ������� 11
	TTXL12 = (double)(Tt-273);// + RW(1120) + RW(1132);   							//������ ����������� ���� �� �� �� ������� 12

	//RF(1209) = Tt;

} //end main 

