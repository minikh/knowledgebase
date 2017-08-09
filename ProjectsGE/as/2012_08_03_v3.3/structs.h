
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
 

 
 

   
#pragma pack()
