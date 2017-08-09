
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



	#pragma pack(1)
	
	typedef struct
	{
    // температура в разных точках сильно отличается
    short EGT_Diff_High: 1;
    short filler1[1];
    int EGT_Diff_High_State;
    // прерван пуск по причине отказа зажигания
    short Start_SD3: 1;
    short filler2[1];
    int Start_SD3_State;
    short Start_SD2: 1;
    short filler3[1];
    int Start_SD2_State;
    short Start_SD1: 1;
    short filler4[1];
    int Start_SD1_State;
    short Start_SD4: 1;
    short filler5[1];
    int Start_SD4_State;
    short Start_SD5: 1;
    short filler6[1];
    int Start_SD5_State;
    short Start_SD8: 1;
    short filler7[1];
    int Start_SD8_State;
    short External_SD: 1;
    short filler8[1];
    int External_SD_State;
    short Operator_SD: 1;
    short filler9[1];
    int Operator_SD_State;
    short Logic_SD: 1;
    short filler10[1];
    int Logic_SD_State;
    short Pos_Dev_IGV: 1;
    short filler11[1];
    int Pos_Dev_IGV_State;
    short EGT_OverTemp: 1;
    short filler12[1];
    int EGT_OverTemp_State;
    short Pos_Dev_VSV: 1;
    short filler13[1];
    int Pos_Dev_VSV_State;
    short Pos_Dev_VBV: 1;
    short filler14[1];
    int Pos_Dev_VBV_State;
    short Pos_Span_VSV: 1;
    short filler15[1];
    int Pos_Span_VSV_State;
    short Pos_Span_VBV: 1;
    short filler16[1];
    int Pos_Span_VBV_State;
    short Pos_Span_IGV: 1;
    short filler17[1];
    int Pos_Span_IGV_State;
    short EGT_All_Fail: 1;
    short filler18[1];
    int EGT_All_Fail_State;
    short NHP_fail: 1;
    short filler19[1];
    int NHP_fail_State;
    short NLP_fail: 1;
    short filler20[1];
    int NLP_fail_State;
    short T1_fail: 1;
    short filler21[1];
    int T1_fail_State;
    short FCVPOS_fail: 1;
    short filler22[1];
    int FCVPOS_fail_State;
    short CDP_fail: 1;
    short filler23[1];
    int CDP_fail_State;
    short FGAS_P1_fail: 1;
    short filler24[1];
    int FGAS_P1_fail_State;
    short FGAS_P2_fail: 1;
    short filler25[1];
    int FGAS_P2_fail_State;
    short FGAS_T1_fail: 1;
    short filler26[1];
    int FGAS_T1_fail_State;
    short NLP_OverSpeed: 1;
    short filler27[1];
    int NLP_OverSpeed_State;
    short NHP_OverSpeed: 1;
    short filler28[1];
    int NHP_OverSpeed_State;
    short NPT_AccelSD: 1;
    short filler29[1];
    int NPT_AccelSD_State;
    short NPT_UnderSpeed: 1;
    short filler30[1];
    int NPT_UnderSpeed_State;
    short NPT_OverSpeed: 1;
    short filler31[1];
    int NPT_OverSpeed_State;
    short ShaftFailure: 1;
    short filler32[1];
    int ShaftFailure_State;
    short NHP_UnderSpeed: 1;
    short filler33[1];
    int NHP_UnderSpeed_State;
    short NLP_UnderSpeed: 1;
    short filler34[1];
    int NLP_UnderSpeed_State;
    short EGT_UnderTemp: 1;
    short filler35[1];
    int EGT_UnderTemp_State;
    short FCV_trip_track: 1;
    short filler36[1];
    int FCV_trip_track_State;
    short FCV_al_track: 1;
    short filler37[1];
    int FCV_al_track_State;
    short Decel_clamp: 1;
    short filler38[1];
    int Decel_clamp_State;
    short Accel_clamp: 1;
    short filler39[1];
    int Accel_clamp_State;
    short FGAS_fallback: 1;
    short filler40[1];
    int FGAS_fallback_State;
    short T1_manual: 1;
    short filler41[1];
    int T1_manual_State;
    short NPT_fail: 1;
    short filler42[1];
    int NPT_fail_State;
    short EGT_Dev_High: 1;
    short filler43[1];
    int EGT_Dev_High_State;
    short BV_Opened: 1;
    short filler44[1];
    int BV_Opened_State;
    short FGAS_P2_High: 1;
    short filler45[1];
    int FGAS_P2_High_State;
    short NPT_Low: 1;
    short filler46[1];
    int NPT_Low_State;
    short NPT_High: 1;
    short filler47[1];
    int NPT_High_State;
    short NHP_Low: 1;
    short filler48[1];
    int NHP_Low_State;
    short NHP_High: 1;
    short filler49[1];
    int NHP_High_State;
    short NLP_Low: 1;
    short filler50[1];
    int NLP_Low_State;
    short NLP_High: 1;
    short filler51[1];
    int NLP_High_State;
    short CDP_Low: 1;
    short filler52[1];
    int CDP_Low_State;
    short CDP_High: 1;
    short filler53[1];
    int CDP_High_State;
    short T1_Low: 1;
    short filler54[1];
    int T1_Low_State;
    short T1_High: 1;
    short filler55[1];
    int T1_High_State;
    short FCVPOS_Low: 1;
    short filler56[1];
    int FCVPOS_Low_State;
    short FCVPOS_High: 1;
    short filler57[1];
    int FCVPOS_High_State;
    short FGAS_P1_Low: 1;
    short filler58[1];
    int FGAS_P1_Low_State;
    short FGAS_T1_High: 1;
    short filler59[1];
    int FGAS_T1_High_State;
    short FGAS_P2_Low: 1;
    short filler60[1];
    int FGAS_P2_Low_State;
    short FGAS_P1_High: 1;
    short filler61[1];
    int FGAS_P1_High_State;
    short FGAS_T1_Low: 1;
    short filler62[1];
    int FGAS_T1_Low_State;
    short Power_High: 1;
    short filler63[1];
    int Power_High_State;
    short EGT_Low: 1;
    short filler64[1];
    int EGT_Low_State;
    short EGT_High: 1;
    short filler65[1];
    int EGT_High_State;
    short Power_Low: 1;
    short filler66[1];
    int Power_Low_State;
    short NHP_StartUp_Lost: 1;
    short filler67[1];
    int NHP_StartUp_Lost_State;
    short NPT_spike: 1;
    short NHP_spike: 1;
    short NLP_spike: 1;
	short flameout: 1;
    short filler68[2];	 
} AG_gt1_20_AE;
 

	
	
   typedef struct{
      int Nel;                //(* number of points in characterizer   *)
      float Fx[12];            
      float x[12];              
   } funct;
   
typedef struct
{
    float EGT_Start_SP_Value;
    float EGT_Start_Trip_Value;
} start_data;


   
typedef struct
{
    float PV;
    float real_PV;
    float Tf;
    int selection_method;
    short trans_enable[4];
    short failure: 1;
    short filler1[1];
    float PV_gain;
    float PV_bias;
    float RX_gain;
    float RX_bias;
    float AlarmHigh;
    float AlarmLow;
    int CharType;
} ext_var;
   
  
typedef struct
{
    int loop_type;
    int loop_num;
    int loop_priority;
    short loop_enable: 1;
    short loop_valid: 1;
    short rem_loc: 1;
    short auto_man: 1;
    short loop_direct: 1;
    short filler1[1];
    float delt_t;
    float SP_ramp_rate;
    float DB;
    float SP_gain;
    float SP_bias;
    float PV_gain;
    float PV_bias;
    float SP_LowClamp;
    float SP_HighClamp;
    float KP;
    float KI;
    short non_conv_D_part_enable: 1;
    short filler2[1];
    float D_part_clamp;
    float dMax_value;
    float dMin_value;
    short Reset_D_max_value: 1;
    short filler3[1];
    float KD;
    short PV_failure: 1;
    short SwitchFlag: 1;
    short filler4[1];
    float PV;
    float real_PV;
    float real_SP;
    float local_SP;
    float remote_SP;
    float limit_SP;
    float act_SP;
    short active: 1;
    short cur_act: 1;
    short goal_dir: 1;
    short limit_goal: 1;
    short filler5[1];
    float err;
    float P_part;
    float dI_part;
    float D_part;
    float PplusD_part;
    float m_mGOV;
    float derivative_threshold;
	float d_PV;
} DPID;


typedef struct
{
    // массив из 10ти контуров
    DPID pid_struct[10];
    float local_SP;
    float remote_SP;
    float act_SP;
    float manual_target;
    float PplusD_selected;
    float dI_selected;
    short goal_dir_selected: 1;
    short filler1[1];
    int priority_selected;
    int main_loop;
    int state;
    int act_control_mode;
    int N_loops;
    short tune_mode: 1;
    short auto_man: 1;
    short manual_enable: 1;
    short rem_loc: 1;
    short lim_in_man_enable: 1;
    short filler2[1];
    int lim_in_man_type;
    float rem_SP_filt_const;
    float manual_r_rate_s;
    float manual_r_rate_f;
    int loop_selected;
    short LimitCondition: 1;
    short force_out_of_limit: 1;
    short last_goal_dir: 1;
    short limit_goal: 1;
    short oppos_limits: 1;
    short filler3[1];
    float high_clamp;
    float low_clamp;
    int clamp;
    float vel_high_limit;
    float vel_low_limit;
    short vel_limit_ind: 1;
    short filler4[1];
    float hyst;
    short FCV_reverse: 1;
    short filler5[1];
    float cv;
    float FCV;
    float d_out_min;
    float d_out_max;
    long delta_time;
    short had_ESD: 1;
    short had_SD: 1;
    short filler6[2];
} DSEL;
 

 
 


typedef struct
{
    int main_loop;
    float local_SP;
    float remote_SP;
    float man_target;
    short Flame: 1;
    short ESD: 1;
    short External_SD: 1;
    short Reset: 1;
    short Start: 1;
    short Stop: 1;
    short Raise: 1;
    short Lower: 1;
    short Rated: 1;
    short Idle: 1;
    short NHP_Accel: 1;
    short NPT_Accel: 1;
    short Min_Gov: 1;
    short Remote: 1;
    short Auto: 1;
    short Start_Perm: 1;
    short Tune: 1;
    short OS_Test: 1;
    short Unload: 1;
    short Alarm_Reset: 1;
    short Idle_Fast: 1;
    short FCV_Ramp: 1;
    short Alt_NPT_SP: 1;
    short Alt_NHP_SP: 1;
    short Alt_NLP_SP: 1;
    short Alt_NHPL_SP: 1;
    short Alt_EGT_SP: 1;
    short Alt_CDP_SP: 1;
    short Alt_IGV_char: 1;
    short Alt_VBV_char: 1;
    short Alt_VSV_char: 1;
    short Reset_max: 1;
    short filler2[1];
    short Reset_min: 1;
    short NK12_BV: 1;
    short filler3[2];
} gtCommands;
 

 





typedef struct
{
    int Nel;
    float Fx[22];
    float x[22];
} outp_funct;

typedef struct
{
    float begin;
    float end;
} shaft_critical_zone;
 



typedef struct
{
    long coastdown_time;
    long pre_ignition_delay;
    long flameproof_time;
    long FCV_warmup_time;
    long start_stagnation_time;
    long NHP_warmup_time;
    long cooldown_time;
    float reset_speed;
    float FCV_ready_value;
    float FCV_initial_demand;
    float FCV_initial_demand_rate;
    float FCV_warmup_demand;
    float FCV_warmup_demand_rate;
    funct FCV_start_ramp_rate;
    float FCV_max_position1;
    float FCV_max_position2;
    float FCV_warmup_temperature_limit;
    float FCV_max_start_demand;
    funct FCV_amb_bias_char;
    float flame_detect_delta_EGT;
    float flame_detect_delta_NHP;
    float flame_detect_EGT;
    float NHP_SP_idle_depression;
    funct NHP_SP_idle_char;
    short NHP_SP_idle_char_enable: 1;
    short filler1[1];
    float NHP_SP_idle_fallback;
    float NHP_SP_cooldown;
    short NHP_SP_rated_R_enable: 1;
    short filler2[1];
    float stop_ramp_rate;
    funct NHP_accel_limit;
    funct NHP_start_ramp_rate;
    short EGT_SP_start_enable: 1;
    short filler3[1];
    float EGT_SP_start;
    float EGT_SP_start_rate;
    float EGT_start_rate_limit;
    float EGT_high_trip_start_value;
    int Start_goal;
    float NHP_SP_rated;
    float NPT_SP_rated;
    float NPT_min_depression;
    shaft_critical_zone NHP_critical_zone[7];
    shaft_critical_zone NPT_critical_zone[7];
    float critical_rate;
    float rated_ramp_rate;
    short remote_SP_auto_enable: 1;
    short filler4[1];
    // ( нужно idle ) 
    int default_start_goal;
    short HWorSW_flame_detect: 1;
    short Permissive_Enable: 1;
    short NPT_control_enable: 1;
    short filler5[1];
    float Idle_ramp_rate;
    float Idle_Fast_ramp_rate;
    int conf_change;
} AutoSeq_cnf;


typedef struct
{
    int FCV_fallback_action;
    int FCVL_fallback_action;
    int IGV_fallback_action;
    int VBV_fallback_action;
    int VSV_fallback_action;
    int Water_fallback_action;
} Fallback_conf;
 

 typedef struct
{
    // 1 - Low Speed Switch, 0 - High Speed Switch 
    short SpSwitchType: 1;
    short filler1[1];
    //  Value when SpSw should switch 
    float SpSwitchLevel;
    //  Neutral zone Widht  
    float SpSwitchNZ;
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
    float recovery_rate;
    float P1_nominal;
    float T1_nominal;
    float P1T1P2_comp_gain;
} FGAS_config;
 

typedef struct
{
    short OSP_enable: 1;
    short OSP: 1;
    short filler1[1];
    float OSP_NPT_threshold;
    float OSP_close_value;
    int OSP_deadtime;
    float OSP_Ki_adjust;
    float NPT_derivative_SD_threshold;
    float NPT_derivative_shutdown;
    float OSP_NHP_NLP_low;
    float OSP_NHP_NLP_high;
} OSP_cnf;
 

typedef struct
{
    int type_detect;
    float switch_SP;
    float max_NHP;
    float K_start;
    long T_K_start;
    float d_NHP;
    float d_CDP;
    float d_EGT;
    float d_FCV;
	long flameout_delay;
} flameout; 

typedef struct
{
    int conf_change;
    int number_of_loops;
    short manual_enable: 1;
    short lim_in_man_enable: 1;
    short filler1[1];
    int lim_in_man_type;
    float remote_SP_filter;
    float manual_r_rate_slow;
    float manual_r_rate_fast;
    funct accel_schedule;
    int accel_main_arg;
    funct accel_fb_schedule;
    int accel_alt_arg;
    funct decel_schedule;
    int decel_main_arg;
    funct decel_fb_schedule;
    int decel_alt_arg;
    short event_capture_in_Ready: 1;
    short filler2[1];
    float high_clamp;
    float low_clamp;
    float vel_high_limit;
    float vel_low_limit;
    float FCV_track_al_tol;
    float FCV_track_trip_tol;
    long FCV_track_delay;
    float man_step;
    long r_time;
    outp_funct FCV_char;
    float hyst;
    float NHP_proof;
    short FCV_reverse: 1;
    short filler3[1];
    float NK12_BV_step;
    float NK12_BV_NHPL_SP_step;
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
    int loop_num;
    // флаг изменения конфигурации
    int conf_change;
    float span;
    float offset;
    float SP_LowClamp;
    float SP_HighClamp;
    short loop_enable: 1;
    short filler1[1];
    int loop_type;
    int loop_priority;
    short loop_direct: 1;
    short filler2[1];
    float SP_ramp_rate;
    float DB;
    float derivative_threshold;
    // постоянная времени фильтрации
    float Tf;
    short limit_char_enable: 1;
    short filler3[1];
    // основной характирайзер SP
    funct main_char_SP;
    // альтернативный характирайзер SP
    funct char_alt_SP;
    // 0 - main char, 1- alt char
    short switch_cond: 1;
    // 0 - fallback_sp, 1- last char value
    short fallback_method: 1;
    short filler4[1];
    float fallback_SP;
    int char_arg;
    int char_alt_arg;
    float KP;
    float Kr;
    float Td;
    // charachterizer for KP
    funct char_KP;
    // charachterizer for KI
    funct char_Kr;
    // charachterizer for KD
    funct char_Td;
    short non_conv_D_part_enable: 1;
    short filler5[1];
    float D_part_clamp;
    // charachterizer for DB
    funct char_DB;
    // номер контура чье PV является аргументом для характирайзеров
    int PID_char_N;
    float high_trip_value;
    float low_trip_value;
    int alt_loop;
    int fallback_action;
    float AlarmHigh;
    float AlarmLow;
    float TransmitterHigh;
    float TransmitterLow;
    float transient_limit;
} PID_conf_fx;
   
   #pragma pack()
   
