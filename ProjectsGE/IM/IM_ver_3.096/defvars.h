//Дискретные входы				
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
				
				
//Дискретные выходы				
#define	DO_ON			IM->DO.ON
#define	DO_OF			IM->DO.OF
#define	DO_STOP			IM->DO.STOP
#define	DO_ONForce			IM->DO.ONForce
#define	DO_OFForce			IM->DO.OFForce
				
				
//Команды автоматические				
#define	AVT_ON			IM->AVT.ON
#define	AVT_OF			IM->AVT.OF
				
				
//Кнопки				
#define	BTN_ON			IM->BTN.ON
#define	BTN_OF			IM->BTN.OF
#define	BTN_RU			IM->BTN.RU
#define	BTN_STOP			IM->BTN.STOP
				
				
//Команды из алгоритма				
#define	ALG_DO_Ban			IM->ALG.DO_Ban
#define	ALG_RU_Ban			IM->ALG.RU_Ban
				
//Настройки				
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
#define	CFG_PRIORITY_RU			IM->CFG.PRIORITY_RU
				
				
				
				
//Статусы				
#define	ST_Ver			IM->ST.Ver
#define	ST_Narab			IM->ST.Narab
#define	ST_Num			IM->ST.Num
#define	ST_ON_IMIT			IM->ST.ON_IMIT
#define	ST_FLT			IM->ST.FLT
#define	ST_RUs			IM->ST.RUs
#define	ST_RU_Ban			IM->ST.RU_Ban
#define	ST_Move			IM->ST.Move
#define	ST_MID			IM->ST.MID
#define	ST_DI_ON			IM->ST.DI_ON1
#define	ST_DI_OF			IM->ST.DI_OF1
#define	ST_DO_ON			IM->ST.DO_ON1
#define	ST_DO_OF			IM->ST.DO_OF1
#define	ST_AVT_ON			IM->ST.AVT_ON2
#define	ST_AVT_OF			IM->ST.AVT_OF2
#define	ST_BTN_ON			IM->ST.BTN_ON2
#define	ST_BTN_OF			IM->ST.BTN_OF2
#define	ST_TYPE_IM			IM->ST.TYPE_IM

				
				
//Ошибки				
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
#define	PS_Vibr			IM->PS.Vibr
#define	PS_Loil			IM->PS.Loil
#define	PS_U_OF			IM->PS.U_OF
#define	PS_Poil			IM->PS.Poil
#define	PS_TYPE_IM_FLT			IM->PS.TYPE_IM_FLT
#define	PS_T_Block_FLT			IM->PS.T_Block_FLT
#define	PS_T_KCU_FLT			IM->PS.T_KCU_FLT
#define	PS_T_NotMove_FLT			IM->PS.T_NotMove_FLT
#define	PS_T_NotCO_FLT			IM->PS.T_NotCO_FLT
#define	PS_T_Alarm_FLT			IM->PS.T_Alarm_FLT

				
//Служебная область				
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
#define	TMP_T_Force_ON			IM->TMP.T_Force_ON
#define	TMP_T_Force_OF			IM->TMP.T_Force_OF
#define	TMP_T_Force_ON_EN			IM->TMP.T_Force_ON_EN
#define	TMP_T_Force_OF_EN			IM->TMP.T_Force_OF_EN
#define	TMP_T_Block_ON			IM->TMP.T_Block_ON
#define	TMP_T_Block_OF			IM->TMP.T_Block_OF
#define	TMP_T_Block_ON_EN			IM->TMP.T_Block_ON_EN
#define	TMP_T_Block_OF_EN			IM->TMP.T_Block_OF_EN
#define	TMP_T_Imit_ON			IM->TMP.T_Imit_ON
#define	TMP_T_Imit_OF			IM->TMP.T_Imit_OF
#define	TMP_T_Imit_ON_EN			IM->TMP.T_Imit_ON_EN
#define	TMP_T_Imit_OF_EN			IM->TMP.T_Imit_OF_EN
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
#define	TMP_DI_ON			IM->TMP.DI_ON1
#define	TMP_PRIORITY_RU			IM->TMP.PRIORITY_RU



