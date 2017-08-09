
#define	d_diff 0.001

#define	Preignition_TON 2
#define flameout_run_TON 3
#define flameout_start_TON 4

#define	flameproof_u_st_ramp 5   // используется в таймере TON 
#define	aFCV_warmup_u_st_ramp 16  // используется в таймере TON 
#define	aFCV_ramp_u_st_ramp 7
#define	aFCV_ramp_u_st_ramp_cv 8
#define	aNHP_warmup_u_st_ramp 9
#define	aRatedramp_u_st_ramp 10
#define	aNPT_ramp_u_st_ramp 11


#define R_TRIG_LimCond1 0
#define	R_TRIG_ResetSD  1
#define	R_TRIG_flameDet 3
#define	R_TRIG_flameproof 4
#define	R_TRIG_FCVwarmup_end 7
#define	R_TRIG_FCVwarmup 8
#define	R_TRIG_FCVramp_begin 9
#define	R_TRIG_NHPcntrl 10
#define	R_TRIG_rramp 11
#define	R_TRIG_NPTramp 12

		
		

		
		
		
		
#define	deriv_num_fcv_ramp_egt 0	
#define	deriv_num_fcv_ramp_nhp 1	

/* #ifndef _structs_h_
#define _structs_h_
#pragma pack(2) */

	#pragma pack(1)
	
	typedef struct
	{
    // температура в разных точках сильно отличается
    T_BYTE EGT_Diff_High: 1;
    T_BYTE filler1[1];
    T_INT16 EGT_Diff_High_State;
    // прерван пуск по причине отказа зажигания
    T_BYTE Start_SD3: 1;
    T_BYTE filler2[1];
    T_INT16 Start_SD3_State;
    T_BYTE Start_SD2: 1;
    T_BYTE filler3[1];
    T_INT16 Start_SD2_State;
    T_BYTE Start_SD1: 1;
    T_BYTE filler4[1];
    T_INT16 Start_SD1_State;
    T_BYTE Start_SD4: 1;
    T_BYTE filler5[1];
    T_INT16 Start_SD4_State;
    T_BYTE Start_SD5: 1;
    T_BYTE filler6[1];
    T_INT16 Start_SD5_State;
    T_BYTE Start_SD8: 1;
    T_BYTE filler7[1];
    T_INT16 Start_SD8_State;
    T_BYTE External_SD: 1;
    T_BYTE filler8[1];
    T_INT16 External_SD_State;
    T_BYTE Operator_SD: 1;
    T_BYTE filler9[1];
    T_INT16 Operator_SD_State;
    T_BYTE Logic_SD: 1;
    T_BYTE filler10[1];
    T_INT16 Logic_SD_State;
    T_BYTE Pos_Dev_IGV: 1;
    T_BYTE filler11[1];
    T_INT16 Pos_Dev_IGV_State;
    T_BYTE EGT_OverTemp: 1;
    T_BYTE filler12[1];
    T_INT16 EGT_OverTemp_State;
    T_BYTE Pos_Dev_VSV: 1;
    T_BYTE filler13[1];
    T_INT16 Pos_Dev_VSV_State;
    T_BYTE Pos_Dev_VBV: 1;
    T_BYTE filler14[1];
    T_INT16 Pos_Dev_VBV_State;
    T_BYTE Pos_Span_VSV: 1;
    T_BYTE filler15[1];
    T_INT16 Pos_Span_VSV_State;
    T_BYTE Pos_Span_VBV: 1;
    T_BYTE filler16[1];
    T_INT16 Pos_Span_VBV_State;
    T_BYTE Pos_Span_IGV: 1;
    T_BYTE filler17[1];
    T_INT16 Pos_Span_IGV_State;
    T_BYTE EGT_All_Fail: 1;
    T_BYTE filler18[1];
    T_INT16 EGT_All_Fail_State;
    T_BYTE NHP_fail: 1;
    T_BYTE filler19[1];
    T_INT16 NHP_fail_State;
    T_BYTE NLP_fail: 1;
    T_BYTE filler20[1];
    T_INT16 NLP_fail_State;
    T_BYTE T1_fail: 1;
    T_BYTE filler21[1];
    T_INT16 T1_fail_State;
    T_BYTE FCVPOS_fail: 1;
    T_BYTE filler22[1];
    T_INT16 FCVPOS_fail_State;
    T_BYTE CDP_fail: 1;
    T_BYTE filler23[1];
    T_INT16 CDP_fail_State;
    T_BYTE FGAS_P1_fail: 1;
    T_BYTE filler24[1];
    T_INT16 FGAS_P1_fail_State;
    T_BYTE FGAS_P2_fail: 1;
    T_BYTE filler25[1];
    T_INT16 FGAS_P2_fail_State;
    T_BYTE FGAS_T1_fail: 1;
    T_BYTE filler26[1];
    T_INT16 FGAS_T1_fail_State;
    T_BYTE NLP_OverSpeed: 1;
    T_BYTE filler27[1];
    T_INT16 NLP_OverSpeed_State;
    T_BYTE NHP_OverSpeed: 1;
    T_BYTE filler28[1];
    T_INT16 NHP_OverSpeed_State;
    T_BYTE NPT_AccelSD: 1;
    T_BYTE filler29[1];
    T_INT16 NPT_AccelSD_State;
    T_BYTE NPT_UnderSpeed: 1;
    T_BYTE filler30[1];
    T_INT16 NPT_UnderSpeed_State;
    T_BYTE NPT_OverSpeed: 1;
    T_BYTE filler31[1];
    T_INT16 NPT_OverSpeed_State;
    T_BYTE ShaftFailure: 1;
    T_BYTE filler32[1];
    T_INT16 ShaftFailure_State;
    T_BYTE NHP_UnderSpeed: 1;
    T_BYTE filler33[1];
    T_INT16 NHP_UnderSpeed_State;
    T_BYTE NLP_UnderSpeed: 1;
    T_BYTE filler34[1];
    T_INT16 NLP_UnderSpeed_State;
    T_BYTE EGT_UnderTemp: 1;
    T_BYTE filler35[1];
    T_INT16 EGT_UnderTemp_State;
    T_BYTE FCV_trip_track: 1;
    T_BYTE filler36[1];
    T_INT16 FCV_trip_track_State;
    T_BYTE FCV_al_track: 1;
    T_BYTE filler37[1];
    T_INT16 FCV_al_track_State;
    T_BYTE Decel_clamp: 1;
    T_BYTE filler38[1];
    T_INT16 Decel_clamp_State;
    T_BYTE Accel_clamp: 1;
    T_BYTE filler39[1];
    T_INT16 Accel_clamp_State;
    T_BYTE FGAS_fallback: 1;
    T_BYTE filler40[1];
    T_INT16 FGAS_fallback_State;
    T_BYTE T1_manual: 1;
    T_BYTE filler41[1];
    T_INT16 T1_manual_State;
    T_BYTE NPT_fail: 1;
    T_BYTE filler42[1];
    T_INT16 NPT_fail_State;
    T_BYTE EGT_Dev_High: 1;
    T_BYTE filler43[1];
    T_INT16 EGT_Dev_High_State;
    T_BYTE BV_Opened: 1;
    T_BYTE filler44[1];
    T_INT16 BV_Opened_State;
    T_BYTE FGAS_P2_High: 1;
    T_BYTE filler45[1];
    T_INT16 FGAS_P2_High_State;
    T_BYTE NPT_Low: 1;
    T_BYTE filler46[1];
    T_INT16 NPT_Low_State;
    T_BYTE NPT_High: 1;
    T_BYTE filler47[1];
    T_INT16 NPT_High_State;
    T_BYTE NHP_Low: 1;
    T_BYTE filler48[1];
    T_INT16 NHP_Low_State;
    T_BYTE NHP_High: 1;
    T_BYTE filler49[1];
    T_INT16 NHP_High_State;
    T_BYTE NLP_Low: 1;
    T_BYTE filler50[1];
    T_INT16 NLP_Low_State;
    T_BYTE NLP_High: 1;
    T_BYTE filler51[1];
    T_INT16 NLP_High_State;
    T_BYTE CDP_Low: 1;
    T_BYTE filler52[1];
    T_INT16 CDP_Low_State;
    T_BYTE CDP_High: 1;
    T_BYTE filler53[1];
    T_INT16 CDP_High_State;
    T_BYTE T1_Low: 1;
    T_BYTE filler54[1];
    T_INT16 T1_Low_State;
    T_BYTE T1_High: 1;
    T_BYTE filler55[1];
    T_INT16 T1_High_State;
    T_BYTE FCVPOS_Low: 1;
    T_BYTE filler56[1];
    T_INT16 FCVPOS_Low_State;
    T_BYTE FCVPOS_High: 1;
    T_BYTE filler57[1];
    T_INT16 FCVPOS_High_State;
    T_BYTE FGAS_P1_Low: 1;
    T_BYTE filler58[1];
    T_INT16 FGAS_P1_Low_State;
    T_BYTE FGAS_T1_High: 1;
    T_BYTE filler59[1];
    T_INT16 FGAS_T1_High_State;
    T_BYTE FGAS_P2_Low: 1;
    T_BYTE filler60[1];
    T_INT16 FGAS_P2_Low_State;
    T_BYTE FGAS_P1_High: 1;
    T_BYTE filler61[1];
    T_INT16 FGAS_P1_High_State;
    T_BYTE FGAS_T1_Low: 1;
    T_BYTE filler62[1];
    T_INT16 FGAS_T1_Low_State;
    T_BYTE Power_High: 1;
    T_BYTE filler63[1];
    T_INT16 Power_High_State;
    T_BYTE EGT_Low: 1;
    T_BYTE filler64[1];
    T_INT16 EGT_Low_State;
    T_BYTE EGT_High: 1;
    T_BYTE filler65[1];
    T_INT16 EGT_High_State;
    T_BYTE Power_Low: 1;
    T_BYTE filler66[1];
    T_INT16 Power_Low_State;
    T_BYTE NHP_StartUp_Lost: 1;
    T_BYTE filler67[1];
    T_INT16 NHP_StartUp_Lost_State;
    T_BYTE NPT_spike: 1;
    T_BYTE NHP_spike: 1;
    T_BYTE NLP_spike: 1;
	T_BYTE flameout: 1;
    T_BYTE filler68[2];	 
} AG_gt1_20_AE;
 

	
	
   typedef struct{
      T_INT16 Nel;                //(* number of points in characterizer   *)
      T_REAL32 Fx[12];            
      T_REAL32 x[12];              
   } funct;
   
typedef struct
{
    T_REAL32 EGT_Start_SP_Value;
    T_REAL32 EGT_Start_Trip_Value;
} start_data;


   
typedef struct
{
    T_REAL32 PV;
    T_REAL32 real_PV;
    T_REAL32 Tf;
    T_INT16 selection_method;
    T_BYTE trans_enable[4];
    T_BYTE failure: 1;
    T_BYTE filler1[1];
    T_REAL32 PV_gain;
    T_REAL32 PV_bias;
    T_REAL32 RX_gain;
    T_REAL32 RX_bias;
    T_REAL32 AlarmHigh;
    T_REAL32 AlarmLow;
    T_INT16 CharType;
} ext_var;
   
  
typedef struct
{
    T_INT16 loop_type;
    T_INT16 loop_num;
    T_INT16 loop_priority;
    T_BYTE loop_enable: 1;
    T_BYTE loop_valid: 1;
    T_BYTE rem_loc: 1;
    T_BYTE auto_man: 1;
    T_BYTE loop_direct: 1;
    T_BYTE filler1[1];
    T_REAL32 delt_t;
    T_REAL32 SP_ramp_rate;
    T_REAL32 DB;
    T_REAL32 SP_gain;
    T_REAL32 SP_bias;
    T_REAL32 PV_gain;
    T_REAL32 PV_bias;
    T_REAL32 SP_LowClamp;
    T_REAL32 SP_HighClamp;
    T_REAL32 KP;
    T_REAL32 KI;
    T_BYTE non_conv_D_part_enable: 1;
    T_BYTE filler2[1];
    T_REAL32 D_part_clamp;
    T_REAL32 dMax_value;
    T_REAL32 dMin_value;
    T_BYTE Reset_D_max_value: 1;
    T_BYTE filler3[1];
    T_REAL32 KD;
    T_BYTE PV_failure: 1;
    T_BYTE SwitchFlag: 1;
    T_BYTE filler4[1];
    T_REAL32 PV;
    T_REAL32 real_PV;
    T_REAL32 real_SP;
    T_REAL32 local_SP;
    T_REAL32 remote_SP;
    T_REAL32 limit_SP;
    T_REAL32 act_SP;
    T_BYTE active: 1;
    T_BYTE cur_act: 1;
    T_BYTE goal_dir: 1;
    T_BYTE limit_goal: 1;
    T_BYTE filler5[1];
    T_REAL32 err;
    T_REAL32 P_part;
    T_REAL32 dI_part;
    T_REAL32 D_part;
    T_REAL32 PplusD_part;
    T_REAL32 m_mGOV;
    T_REAL32 derivative_threshold;
	T_REAL32 d_PV;
} DPID;


typedef struct
{
    // массив из 10ти контуров
    DPID pid_struct[10];
    T_REAL32 local_SP;
    T_REAL32 remote_SP;
    T_REAL32 act_SP;
    T_REAL32 manual_target;
    T_REAL32 PplusD_selected;
    T_REAL32 dI_selected;
    T_BYTE goal_dir_selected: 1;
    T_BYTE filler1[1];
    T_INT16 priority_selected;
    T_INT16 main_loop;
    T_INT16 state;
    T_INT16 act_control_mode;
    T_INT16 N_loops;
    T_BYTE tune_mode: 1;
    T_BYTE auto_man: 1;
    T_BYTE manual_enable: 1;
    T_BYTE rem_loc: 1;
    T_BYTE lim_in_man_enable: 1;
    T_BYTE filler2[1];
    T_INT16 lim_in_man_type;
    T_REAL32 rem_SP_filt_const;
    T_REAL32 manual_r_rate_s;
    T_REAL32 manual_r_rate_f;
    T_INT16 loop_selected;
    T_BYTE LimitCondition: 1;
    T_BYTE force_out_of_limit: 1;
    T_BYTE last_goal_dir: 1;
    T_BYTE limit_goal: 1;
    T_BYTE oppos_limits: 1;
    T_BYTE filler3[1];
    T_REAL32 high_clamp;
    T_REAL32 low_clamp;
    T_INT16 clamp;
    T_REAL32 vel_high_limit;
    T_REAL32 vel_low_limit;
    T_BYTE vel_limit_ind: 1;
    T_BYTE filler4[1];
    T_REAL32 hyst;
    T_BYTE FCV_reverse: 1;
    T_BYTE filler5[1];
    T_REAL32 cv;
    T_REAL32 FCV;
    T_REAL32 d_out_min;
    T_REAL32 d_out_max;
    T_INT32 delta_time;
    T_BYTE had_ESD: 1;
    T_BYTE had_SD: 1;
    T_BYTE filler6[2];
} DSEL;
 

 
 


typedef struct
{
    T_INT16 main_loop;
    T_REAL32 local_SP;
    T_REAL32 remote_SP;
    T_REAL32 man_target;
    T_BYTE Flame: 1;
    T_BYTE ESD: 1;
    T_BYTE External_SD: 1;
    T_BYTE Reset: 1;
    T_BYTE Start: 1;
    T_BYTE Stop: 1;
    T_BYTE Raise: 1;
    T_BYTE Lower: 1;
    T_BYTE Rated: 1;
    T_BYTE Idle: 1;
    T_BYTE NHP_Accel: 1;
    T_BYTE NPT_Accel: 1;
    T_BYTE Min_Gov: 1;
    T_BYTE Remote: 1;
    T_BYTE Auto: 1;
    T_BYTE Start_Perm: 1;
    T_BYTE Tune: 1;
    T_BYTE OS_Test: 1;
    T_BYTE Unload: 1;
    T_BYTE Alarm_Reset: 1;
    T_BYTE Idle_Fast: 1;
    T_BYTE FCV_Ramp: 1;
    T_BYTE Alt_NPT_SP: 1;
    T_BYTE Alt_NHP_SP: 1;
    T_BYTE Alt_NLP_SP: 1;
    T_BYTE Alt_NHPL_SP: 1;
    T_BYTE Alt_EGT_SP: 1;
    T_BYTE Alt_CDP_SP: 1;
    T_BYTE Alt_IGV_char: 1;
    T_BYTE Alt_VBV_char: 1;
    T_BYTE Alt_VSV_char: 1;
    T_BYTE Reset_max: 1;
    T_BYTE filler2[1];
    T_BYTE Reset_min: 1;
    T_BYTE NK12_BV: 1;
    T_BYTE filler3[2];
} gtCommands;
 

 





typedef struct
{
    T_INT16 Nel;
    T_REAL32 Fx[22];
    T_REAL32 x[22];
} outp_funct;

typedef struct
{
    T_REAL32 begin;
    T_REAL32 end;
} shaft_critical_zone;
 



typedef struct
{
    T_INT32 coastdown_time;
    T_INT32 pre_ignition_delay;
    T_INT32 flameproof_time;
    T_INT32 FCV_warmup_time;
    T_INT32 start_stagnation_time;
    T_INT32 NHP_warmup_time;
    T_INT32 cooldown_time;
    T_REAL32 reset_speed;
    T_REAL32 FCV_ready_value;
    T_REAL32 FCV_initial_demand;
    T_REAL32 FCV_initial_demand_rate;
    T_REAL32 FCV_warmup_demand;
    T_REAL32 FCV_warmup_demand_rate;
    funct FCV_start_ramp_rate;
    T_REAL32 FCV_max_position1;
    T_REAL32 FCV_max_position2;
    T_REAL32 FCV_warmup_temperature_limit;
    T_REAL32 FCV_max_start_demand;
    funct FCV_amb_bias_char;
    T_REAL32 flame_detect_delta_EGT;
    T_REAL32 flame_detect_delta_NHP;
    T_REAL32 flame_detect_EGT;
    T_REAL32 NHP_SP_idle_depression;
    funct NHP_SP_idle_char;
    T_BYTE NHP_SP_idle_char_enable: 1;
    T_BYTE filler1[1];
    T_REAL32 NHP_SP_idle_fallback;
    T_REAL32 NHP_SP_cooldown;
    T_BYTE NHP_SP_rated_R_enable: 1;
    T_BYTE filler2[1];
    T_REAL32 stop_ramp_rate;
    funct NHP_accel_limit;
    funct NHP_start_ramp_rate;
    T_BYTE EGT_SP_start_enable: 1;
    T_BYTE filler3[1];
    T_REAL32 EGT_SP_start;
    T_REAL32 EGT_SP_start_rate;
    T_REAL32 EGT_start_rate_limit;
    T_REAL32 EGT_high_trip_start_value;
    T_INT16 Start_goal;
    T_REAL32 NHP_SP_rated;
    T_REAL32 NPT_SP_rated;
    T_REAL32 NPT_min_depression;
    shaft_critical_zone NHP_critical_zone[7];
    shaft_critical_zone NPT_critical_zone[7];
    T_REAL32 critical_rate;
    T_REAL32 rated_ramp_rate;
    T_BYTE remote_SP_auto_enable: 1;
    T_BYTE filler4[1];
    // ( нужно idle ) 
    T_INT16 default_start_goal;
    T_BYTE HWorSW_flame_detect: 1;
    T_BYTE Permissive_Enable: 1;
    T_BYTE NPT_control_enable: 1;
    T_BYTE filler5[1];
    T_REAL32 Idle_ramp_rate;
    T_REAL32 Idle_Fast_ramp_rate;
    T_INT16 conf_change;
} AutoSeq_cnf;


typedef struct
{
    T_INT16 FCV_fallback_action;
    T_INT16 FCVL_fallback_action;
    T_INT16 IGV_fallback_action;
    T_INT16 VBV_fallback_action;
    T_INT16 VSV_fallback_action;
    T_INT16 Water_fallback_action;
} Fallback_conf;
 

 typedef struct
{
    // TRUE - Low Speed Switch, FALSE - High Speed Switch 
    T_BYTE SpSwitchType: 1;
    T_BYTE filler1[1];
    //  Value when SpSw should switch 
    T_REAL32 SpSwitchLevel;
    //  Neutral zone Widht  
    T_REAL32 SpSwitchNZ;
} SpSwitch_ARRAY;
 
typedef struct
{
    SpSwitch_ARRAY NPT_SpSwitch[6];
    SpSwitch_ARRAY NHP_SpSwitch[6];
    SpSwitch_ARRAY NHPr_SpSwitch[6];
    SpSwitch_ARRAY NLP_SpSwitch[6];
    SpSwitch_ARRAY NLPr_SpSwitch[6];
} SpSwitch_conf;
 
typedef struct
{
    funct P2_char;
    T_REAL32 recovery_rate;
    T_REAL32 P1_nominal;
    T_REAL32 T1_nominal;
    T_REAL32 P1T1P2_comp_gain;
} FGAS_config;
 

typedef struct
{
    T_BYTE OSP_enable: 1;
    T_BYTE OSP: 1;
    T_BYTE filler1[1];
    T_REAL32 OSP_NPT_threshold;
    T_REAL32 OSP_close_value;
    T_INT16 OSP_deadtime;
    T_REAL32 OSP_Ki_adjust;
    T_REAL32 NPT_derivative_SD_threshold;
    T_REAL32 NPT_derivative_shutdown;
    T_REAL32 OSP_NHP_NLP_low;
    T_REAL32 OSP_NHP_NLP_high;
} OSP_cnf;
 

typedef struct
{
    T_INT16 type_detect;
    T_REAL32 switch_SP;
    T_REAL32 max_NHP;
    T_REAL32 K_start;
    T_INT32 T_K_start;
    T_REAL32 d_NHP;
    T_REAL32 d_CDP;
    T_REAL32 d_EGT;
    T_REAL32 d_FCV;
	T_INT32 flameout_delay;
} flameout; 

typedef struct
{
    T_INT16 conf_change;
    T_INT16 number_of_loops;
    T_BYTE manual_enable: 1;
    T_BYTE lim_in_man_enable: 1;
    T_BYTE filler1[1];
    T_INT16 lim_in_man_type;
    T_REAL32 remote_SP_filter;
    T_REAL32 manual_r_rate_slow;
    T_REAL32 manual_r_rate_fast;
    funct accel_schedule;
    T_INT16 accel_main_arg;
    funct accel_fb_schedule;
    T_INT16 accel_alt_arg;
    funct decel_schedule;
    T_INT16 decel_main_arg;
    funct decel_fb_schedule;
    T_INT16 decel_alt_arg;
    T_BYTE event_capture_in_Ready: 1;
    T_BYTE filler2[1];
    T_REAL32 high_clamp;
    T_REAL32 low_clamp;
    T_REAL32 vel_high_limit;
    T_REAL32 vel_low_limit;
    T_REAL32 FCV_track_al_tol;
    T_REAL32 FCV_track_trip_tol;
    T_INT32 FCV_track_delay;
    T_REAL32 man_step;
    T_INT32 r_time;
    outp_funct FCV_char;
    T_REAL32 hyst;
    T_REAL32 NHP_proof;
    T_BYTE FCV_reverse: 1;
    T_BYTE filler3[1];
    T_REAL32 NK12_BV_step;
    T_REAL32 NK12_BV_NHPL_SP_step;
    AutoSeq_cnf AutoSeq;
    Fallback_conf Fallback_conf;
    SpSwitch_conf SPSwitch;
    FGAS_config FGAS_conf;
    OSP_cnf OSP;
	flameout flame_out;
} gt_config;


typedef struct
{
    // номер контура
    T_INT16 loop_num;
    // флаг изменения конфигурации
    T_INT16 conf_change;
    T_REAL32 span;
    T_REAL32 offset;
    T_REAL32 SP_LowClamp;
    T_REAL32 SP_HighClamp;
    T_BYTE loop_enable: 1;
    T_BYTE filler1[1];
    T_INT16 loop_type;
    T_INT16 loop_priority;
    T_BYTE loop_direct: 1;
    T_BYTE filler2[1];
    T_REAL32 SP_ramp_rate;
    T_REAL32 DB;
    T_REAL32 derivative_threshold;
    // постоянная времени фильтрации
    T_REAL32 Tf;
    T_BYTE limit_char_enable: 1;
    T_BYTE filler3[1];
    // основной характирайзер SP
    funct main_char_SP;
    // альтернативный характирайзер SP
    funct char_alt_SP;
    // 0 - main char, 1- alt char
    T_BYTE switch_cond: 1;
    // 0 - fallback_sp, 1- last char value
    T_BYTE fallback_method: 1;
    T_BYTE filler4[1];
    T_REAL32 fallback_SP;
    T_INT16 char_arg;
    T_INT16 char_alt_arg;
    T_REAL32 KP;
    T_REAL32 Kr;
    T_REAL32 Td;
    // charachterizer for KP
    funct char_KP;
    // charachterizer for KI
    funct char_Kr;
    // charachterizer for KD
    funct char_Td;
    T_BYTE non_conv_D_part_enable: 1;
    T_BYTE filler5[1];
    T_REAL32 D_part_clamp;
    // charachterizer for DB
    funct char_DB;
    // номер контура чье PV является аргументом для характирайзеров
    T_INT16 PID_char_N;
    T_REAL32 high_trip_value;
    T_REAL32 low_trip_value;
    T_INT16 alt_loop;
    T_INT16 fallback_action;
    T_REAL32 AlarmHigh;
    T_REAL32 AlarmLow;
    T_REAL32 TransmitterHigh;
    T_REAL32 TransmitterLow;
    T_REAL32 transient_limit;
} PID_conf_fx;
   
   #pragma pack()
  
//#endif
