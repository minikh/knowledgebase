
T_BOOLEAN TON(T_BOOLEAN IN, T_INT16 Num_TON, T_REAL32 t_cycle, T_INT32 PT)
/*
IN - вход,
Num_TON - номер таймера,
t_cycle - время последнего цикла,
PT - задержка
*/

{
	if (!IN)
	{	
		TON_ARRAY[Num_TON] = 0;
		return (FALSE);
	}
	else
	{
		TON_ARRAY[Num_TON] += t_cycle;
		if(TON_ARRAY[Num_TON] < PT)
			return (FALSE);
		else
		{
			if(TON_ARRAY[Num_TON] < PT + t_cycle)
				TON_ARRAY[Num_TON] -= t_cycle;		// чтобы счетчик не переполнялся
			return (TRUE);
		}
	}
}


T_BOOLEAN R_TRIG(T_BOOLEAN signal, T_BOOLEAN* prev_cond)
{	
	if((!*prev_cond)&&(signal))
	{
		*prev_cond = signal;
		return (1);
	}
	else
	{
		*prev_cond = signal;
		return (0);
	}
} 

 T_BOOLEAN F_TRIG(T_BOOLEAN signal, T_BOOLEAN* prev_cond)
{	
	if((prev_cond)&&(!signal))
	{
		*prev_cond = signal;
		return (1);
	}
	else
	{
		*prev_cond = signal;
		return (0);
	}
} 


T_INT16 IterNum(T_INT16 *n_el)
{	
	T_INT16 ItNum;
    ItNum = 0;
	if ((*n_el >= 1) && (*n_el <= 3)) ItNum = 1;
	else if ((*n_el >= 4) && (*n_el <= 5)) ItNum = 2;
	else if ((*n_el >= 6) && (*n_el <= 9)) ItNum = 3;
	else if ((*n_el >= 10) && (*n_el <= 17)) ItNum = 4;
	else if ((*n_el >= 18) && (*n_el <= 21)) ItNum = 5;
	
 return ItNum;
}

T_REAL32 ramp(T_BOOLEAN enable1, T_REAL32 ramp_rate, T_REAL32 y_target, T_REAL32 y_current, T_REAL32 delt_T )
{
	T_REAL32 dd;
	T_REAL32 dy;	
	
	if(enable1)
	{
		if(ramp_rate == 0)
		{
			return(y_target);    
		}

		dd = y_target - y_current ;
		dy = fabs(ramp_rate) * delt_T ;       

		
		if(fabs(dd) <= dy)
			 return(y_target) ;
		 
			
		//(*--------------------------------------------------------*)  
		  if(dd > 0) 
			return(y_current + dy) ;
		  else
			return(y_current - dy) ;
		            
	}
	else	
			 return(y_current) ;
	 
}

int CPID( DPID* pid)
 {
	//static T_REAL32 err_prev_;
	//static T_REAL32 PV_prev1_;
	//static T_REAL32 PV_prev2_;
	T_REAL32 D_part;
	static T_BOOLEAN goal_dir_prev_;
	T_BOOLEAN DB_active;
	
	
	if((pid->loop_enable)&&(pid->loop_valid))
	{
		if(pid->KP > d_diff)
		{     
			if(pid->loop_direct)
				pid->err = pid->act_SP - pid->PV ;
			else
				pid->err = pid->PV - pid->act_SP ; 
                  
			if((pid->err <= pid->DB)&&(pid->err >= -pid->DB))
			{
				pid->err = 0 ;
				DB_active = TRUE;
			}
			else if(pid->err > 0)
			{
				pid->err = pid->err - pid->DB ;
				DB_active = FALSE;
			}
			else
			{
				pid->err = pid->err + pid->DB ;
				DB_active = FALSE;
			}
			//(*_______________________ Proportional Part__________________________________________*)
			pid->P_part = pid->KP * pid->err ;       
			//(*_______________________ Integral   Part (delta Integral) __________________________*)
			pid->dI_part = pid->KI * (pid->err ) * pid->delt_t ; 
			//(*_______________________ Derivative Part__________________________________________*)
			if(!pid->non_conv_D_part_enable)
				D_part = pid->D_part ; //(* D_part calculation organized in spPID *)
			else
				D_part = 0 ;
		}
		else
		{
			pid->P_part = 0;
			pid->dI_part = 0;	
		}
		//(*Kp =0.0 *)                  
		if(DB_active)
		{
			if (pid->loop_type == 1)  
			{
				if(pid->cur_act==pid->loop_direct)
					pid->goal_dir = TRUE;
				else
					pid->goal_dir = FALSE;
			}		
			else if (pid->loop_type == -1)
			{
				if(pid->cur_act != pid->loop_direct)
					pid->goal_dir = TRUE;
				else
					pid->goal_dir = FALSE;
			}
		}
		else if( pid->P_part > 0 )
			pid->goal_dir = FALSE ; //(* increase output *)
		else
			pid->goal_dir = TRUE ; //(* decrease output  *)
	
		//err_prev_ = pid->err ;   
		//PV_prev2_ = PV_prev1_ ;
		//PV_prev1_ = pid->PV ;   
		goal_dir_prev_ = pid->goal_dir;			  
		pid->PplusD_part = pid->P_part + D_part ;

	}
	return 1;
 }

 int runLimit(DSEL * s_sel)
{
	//(* Run all active and latched limit loops *)

	if(s_sel->main_loop != 1)
	{
		if((s_sel->pid_struct[1].loop_enable) && (s_sel->pid_struct[1].loop_valid) )
		{
			if(s_sel->pid_struct[1].active )
			{
				if(s_sel->pid_struct[1].loop_type != 2)
				{
					CPID(&s_sel->pid_struct[1]); //  (* Run activated PID *)
					
				}         
			}
		}
	} 
	
	if(s_sel->main_loop != 2)
	{
		if((s_sel->pid_struct[2].loop_enable) && (s_sel->pid_struct[2].loop_valid) )
		{
			if(s_sel->pid_struct[2].active )
			{
				if(s_sel->pid_struct[2].loop_type != 2)
				{
					CPID(&s_sel->pid_struct[2]); //  (* Run activated PID *)
					
				}         
			}
		}
	} 

	if(s_sel->main_loop != 3)
	{
		if((s_sel->pid_struct[3].loop_enable) && (s_sel->pid_struct[3].loop_valid) )
		{
			if(s_sel->pid_struct[3].active )
			{
				if(s_sel->pid_struct[3].loop_type != 2)
				{
					CPID(&s_sel->pid_struct[3]); //  (* Run activated PID *)
					
				}         
			}
		}
	} 

	if(s_sel->main_loop != 4)
	{
		if((s_sel->pid_struct[4].loop_enable) && (s_sel->pid_struct[4].loop_valid) )
		{
			if(s_sel->pid_struct[4].active )
			{
				if(s_sel->pid_struct[4].loop_type != 2)
				{
					CPID(&s_sel->pid_struct[4]); //  (* Run activated PID *)
					
				}         
			}
		}
	} 	
	
		if(s_sel->main_loop != 5)
	{
		if((s_sel->pid_struct[5].loop_enable) && (s_sel->pid_struct[5].loop_valid) )
		{
			if(s_sel->pid_struct[5].active )
			{
				if(s_sel->pid_struct[5].loop_type != 2)
				{
					CPID(&s_sel->pid_struct[5]); //  (* Run activated PID *)
					
				}         
			}
		}
	} 
	
	if(s_sel->main_loop != 6)
	{
		if((s_sel->pid_struct[6].loop_enable) && (s_sel->pid_struct[6].loop_valid) )
		{
			if(s_sel->pid_struct[6].active )
			{
				if(s_sel->pid_struct[6].loop_type != 2)
				{
					CPID(&s_sel->pid_struct[6]); //  (* Run activated PID *)
					
				}         
			}
		}
	} 

	if(s_sel->main_loop != 7)
	{
		if((s_sel->pid_struct[7].loop_enable) && (s_sel->pid_struct[7].loop_valid) )
		{
			if(s_sel->pid_struct[7].active )
			{
				if(s_sel->pid_struct[7].loop_type != 2)
				{
					CPID(&s_sel->pid_struct[7]); //  (* Run activated PID *)
					
				}         
			}
		}
	} 

	if(s_sel->main_loop != 8)
	{
		if((s_sel->pid_struct[8].loop_enable) && (s_sel->pid_struct[8].loop_valid) )
		{
			if(s_sel->pid_struct[8].active )
			{
				if(s_sel->pid_struct[8].loop_type != 2)
				{
					CPID(&s_sel->pid_struct[8]); //  (* Run activated PID *)
					
				}         
			}
		}
	} 		   
    return (1); 
} 

int limVer ( DSEL * s_sel, T_INT16* test_reg)
 {
	static T_BOOLEAN 	cond[8];
	T_INT16		i;
	T_BOOLEAN	LimCond_Q;
	T_INT16		num_lim;
	static T_BOOLEAN	prev_goal;
	T_INT16 	main_loop;
	
	
	main_loop = s_sel->main_loop;

	for(i = 1; i <= s_sel->N_loops; i++)// (* Verification all limit loops *)
	{
		if((s_sel->pid_struct[i].loop_enable) && ( s_sel->pid_struct[i].loop_valid) && (i != main_loop))
		{		
			if(s_sel->pid_struct[i].PV < s_sel->pid_struct[i].act_SP )
				cond[i] = FALSE;
			else if (s_sel->pid_struct[i].PV > s_sel->pid_struct[i].act_SP )
			{
				cond[i] = TRUE; 
			}
			if(((s_sel->pid_struct[i].loop_type == -1) && (cond[i] == FALSE)) || ((s_sel->pid_struct[i].loop_type == 1) && (cond[i])) || ((s_sel->pid_struct[i].loop_type == 2) && (s_sel->pid_struct[i].cur_act)))
			{
				s_sel->pid_struct[i].active = TRUE; //(* Limit active: PV low then lowSP or High then highSP, latched  *) 
				s_sel->pid_struct[i].cur_act = TRUE; //(* Limit active: PV low then lowSP or High then highSP, not latched *)
				s_sel->LimitCondition = TRUE ;     //(* Latched *)	
				if(i == 2)test_reg[12] += 1;
			
			}
			else
				s_sel->pid_struct[i].cur_act = FALSE; // (* Limit was active:  *)  
		}	
		else if(i == main_loop)
		{
			s_sel->pid_struct[main_loop].cur_act = TRUE;
			s_sel->pid_struct[main_loop].active = TRUE;
		}
		else
		{
			s_sel->pid_struct[i].cur_act = FALSE;
			s_sel->pid_struct[i].active = FALSE;
		}
	  
		//(*R_TRIG_LimCond(CLK:= s_sel->LimitCondition);*)
		LimCond_Q = R_TRIG(s_sel->LimitCondition, &TRIG_ARRAY[R_TRIG_LimCond1]);
		if( s_sel->LimitCondition)
		{
			if(LimCond_Q)
				num_lim = 1;
			 
			if((s_sel->pid_struct[i].active) &&  (num_lim > 1) && (i != main_loop))
			{
				s_sel->oppos_limits = (s_sel->pid_struct[i].limit_goal) ^ (prev_goal);
				prev_goal = s_sel->pid_struct[i].limit_goal;
			}
			else if(num_lim == 1)
			{
				LimCond_Q = s_sel->pid_struct[i].limit_goal;
				num_lim = 2;
			}
		}
		else
		{
			num_lim = 0;
			s_sel->oppos_limits = FALSE;
		}
	} 
	return (1);
 }

 int stopLim(DSEL * s_sel, T_INT16* test_reg)
{

	T_BOOLEAN current_active;
	T_INT16 main_loop;
	T_INT16 i;
	static T_BOOLEAN current_active_previous;
	T_BOOLEAN cond_1;
	T_BOOLEAN cond_2;
	T_BOOLEAN cond_3;
	
	test_reg[0] +=1;
	current_active = FALSE ;
	main_loop = s_sel->main_loop;
	for(i = 1; i <= s_sel->N_loops; i++)
	{
	  if(i != s_sel->main_loop)
		current_active = (s_sel->pid_struct[i].cur_act || current_active) ;  
	}
	 
	//(***********************************************************************)
	 
	//(* Resetting all limit condition *)
	cond_1 = 1 - current_active;
	if(s_sel->goal_dir_selected != s_sel->pid_struct[main_loop].goal_dir)
		cond_2 = 1;	 
	else
		cond_2 = 0;
	if(current_active == current_active_previous)
		cond_3 = 1;
	else 
		cond_3 = 0;
	if(cond_1)								test_reg[4] +=1;
	if(cond_2)								test_reg[5] +=1;
	if(cond_3)								test_reg[6] +=1;
	if(main_loop == s_sel->loop_selected)	test_reg[7] +=1;
	if(s_sel->force_out_of_limit)			test_reg[8] +=1;
	if(current_active)						test_reg[9] +=1;
	if(current_active_previous)				test_reg[10] +=1;
	if(cond_3) 								test_reg[11] +=1;
	if(s_sel->goal_dir_selected)			test_reg[13] +=1;
	if(s_sel->pid_struct[main_loop].goal_dir)test_reg[14] +=1;
	
	if(((s_sel->auto_man) && (cond_1 && cond_3 && (cond_2 ||(main_loop == s_sel->loop_selected)))) || ((!s_sel->auto_man) && cond_1) || s_sel->force_out_of_limit)
	{
		s_sel->LimitCondition = FALSE;
		s_sel->force_out_of_limit = FALSE;
		for(i = 1; i <= s_sel->N_loops; i++)
		{
			if((s_sel->pid_struct[i].active) && (i  != s_sel->loop_selected))
			{
				s_sel->pid_struct[i].PplusD_part = 0;
				s_sel->pid_struct[i].dI_part = 0;
				if (i == 2)
				{
					test_reg[3] += 1;
				}
			}     
			if(i != main_loop)
			{
				s_sel->pid_struct[i].active = FALSE;   //(* unlatch all included limits *)
				s_sel->pid_struct[i].cur_act = FALSE; 
				if (i == 2)
				{
					test_reg[2] += 1;
				}
			}
		}		
		test_reg[1] += 1;
		
	}
	//current_active_previous_previous = current_active_previous;
	current_active_previous = current_active;
	return (1);	

}


int SIG_SEL( DSEL * s_sel, T_INT16* test_reg ) 
{
	T_INT16 main_loop_in;
	static T_INT16 loop_selected;
	T_BOOLEAN first_lim_in_man = 0;
	T_INT16 i;
	T_BOOLEAN cond_PplusD_selected;
	T_BOOLEAN cond_dI_selected;
	
	
	
	main_loop_in = s_sel->main_loop ;
	//(*----------------Case for disabling loop on the fly ----------------*)

	if (s_sel->pid_struct[loop_selected].loop_enable == FALSE)  //(* check for previous scan enabled ?*) 
			s_sel->LimitCondition = FALSE;
	

	if(s_sel->auto_man)
	{
		//(* Signal selector for selecting P , D and dI parts *)
		//(*  Main Loop  *)

		CPID(&s_sel->pid_struct[main_loop_in]);   //(* Call main pid *)
		
		s_sel->PplusD_selected = s_sel->pid_struct[main_loop_in].PplusD_part ; 
		s_sel->dI_selected = s_sel->pid_struct[main_loop_in].dI_part ;
		s_sel->loop_selected = s_sel->pid_struct[main_loop_in].loop_num; //(* main loop selected *)
		s_sel->goal_dir_selected = s_sel->pid_struct[main_loop_in].goal_dir;
		s_sel->priority_selected = 100; //(* For main loop - lowest priority forever *)
		loop_selected = main_loop_in;
	}
	else if(s_sel->LimitCondition)
	{
		//(* ****** Special case for limit in manual ***)
		first_lim_in_man = TRUE;
	}
	else  // (*  Manual mode , no limit *)
	{
		s_sel->PplusD_selected = 0 ; 
		s_sel->dI_selected = 0 ;
	}
	        

	if(s_sel->tune_mode)
		return (1);
			  
	if(s_sel->auto_man || s_sel->lim_in_man_enable)
	{
		limVer(s_sel, test_reg); //(* ___Verification "Limit condition - ?" ____ *)
	     
		//(* -----------------------------------------------------------------------*)  
		if(s_sel->LimitCondition)
		{	//(* Run all active and latched limit loops *)
			runLimit(s_sel); //(* ___Verification "Limit condition - ?" ____ *) 
			//(*  ___________Selector ________________________________*)
			for(i = 1; i <= s_sel->N_loops; i++)
			{
				if(((s_sel->pid_struct[i].loop_enable && s_sel->pid_struct[i].loop_valid)) && (i != main_loop_in) )
				{
					if( s_sel->pid_struct[i].active)
					{
						if(first_lim_in_man)
						{
							s_sel->PplusD_selected = s_sel->pid_struct[i].PplusD_part ; //(*select biggest if direct or lowest if reverse action *)
							s_sel->loop_selected =  s_sel->pid_struct[i].loop_num ;
							s_sel->goal_dir_selected = s_sel->pid_struct[i].goal_dir;
							s_sel->priority_selected = s_sel->pid_struct[i].loop_priority;
							first_lim_in_man = FALSE;
						}

						if(s_sel->pid_struct[i].loop_direct)
						{
							cond_PplusD_selected = (s_sel->PplusD_selected < s_sel->pid_struct[i].PplusD_part);
							cond_dI_selected = (s_sel->dI_selected < s_sel->pid_struct[i].dI_part);
						}
						else
						{
							cond_PplusD_selected = (s_sel->PplusD_selected > s_sel->pid_struct[i].PplusD_part);
							cond_dI_selected = (s_sel->dI_selected > s_sel->pid_struct[i].dI_part);
						}
						//cond_dI_selected = true, если dI контура сильней будет толкать его PV вверх, чем ранее выбранная
						//cond_PplusS_selected = true, тоже самое
						if(s_sel->pid_struct[i].goal_dir == s_sel->goal_dir_selected) //  (* the same direction *)
						{
							if(s_sel->pid_struct[i].loop_type == -1) //(* Low Limit with the same priority - ?  *)
							{
								if(s_sel->pid_struct[loop_selected].cur_act || (s_sel->pid_struct[i].loop_priority < s_sel->pid_struct[loop_selected].loop_priority))
								{
									if(cond_PplusD_selected && (!s_sel->oppos_limits))
									{
										s_sel->PplusD_selected = s_sel->pid_struct[i].PplusD_part ; //(*select biggest if direct or lowest if reverse action *)
										loop_selected = i;
									}
									else if(s_sel->oppos_limits && ((loop_selected == main_loop_in) || ( !cond_PplusD_selected && (s_sel->pid_struct[loop_selected].limit_goal != s_sel->pid_struct[i].limit_goal)) || (cond_PplusD_selected && (s_sel->pid_struct[loop_selected].limit_goal ==s_sel->pid_struct[i].limit_goal))))
									{
										s_sel->PplusD_selected = s_sel->pid_struct[i].PplusD_part ; //(*select biggest if direct or lowest if reverse action *)
										loop_selected = i;				
									}
									if(cond_dI_selected && ( !s_sel->oppos_limits))                                                                                                                                                            
										s_sel->dI_selected = s_sel->pid_struct[i].dI_part ;
									else if(s_sel->oppos_limits && ((loop_selected == main_loop_in) || ( !cond_dI_selected)))
										s_sel->dI_selected = s_sel->pid_struct[i].dI_part ;
									
								}
								//(*s_sel->priority_selected := MIN(s_sel->pid_struct[i].loop_priority,s_sel->pid_struct[loop_selected].loop_priority);*)
								if(s_sel->pid_struct[i].loop_priority > s_sel->pid_struct[loop_selected].loop_priority) 
									s_sel->priority_selected = s_sel->pid_struct[loop_selected].loop_priority;
								else
									s_sel->priority_selected = s_sel->pid_struct[i].loop_priority;
							}
							else  //    (* ---- High Limit with the same priority ----- *)
							{
								if(s_sel->pid_struct[loop_selected].cur_act || (s_sel->pid_struct[i].loop_priority <= s_sel->pid_struct[loop_selected].loop_priority))
								{
									if(( !cond_PplusD_selected) && ( !s_sel->oppos_limits))
									{
										s_sel->PplusD_selected = s_sel->pid_struct[i].PplusD_part ; //(* select lowest action *)
										loop_selected = i;
									}
									else if (s_sel->oppos_limits && ((loop_selected == main_loop_in) || (cond_PplusD_selected && (s_sel->pid_struct[loop_selected].limit_goal != s_sel->pid_struct[i].limit_goal)) || (( !cond_PplusD_selected) && (s_sel->pid_struct[loop_selected].limit_goal == s_sel->pid_struct[i].limit_goal))))
									{
										s_sel->PplusD_selected = s_sel->pid_struct[i].PplusD_part ; //(* select lowest action *)
										loop_selected = i;
									}	
									if( !cond_dI_selected && ( !s_sel->oppos_limits))                                                                                                                                                            
										s_sel->dI_selected = s_sel->pid_struct[i].dI_part ; 
									else if(s_sel->oppos_limits && ((loop_selected == main_loop_in) || cond_dI_selected))
										s_sel->dI_selected = s_sel->pid_struct[i].dI_part ; 
									
								}
								//(*s_sel->priority_selected := MIN(s_sel->pid_struct[i].loop_priority,s_sel->pid_struct[loop_selected].loop_priority);*)
								if(s_sel->pid_struct[i].loop_priority > s_sel->pid_struct[loop_selected].loop_priority) 
									s_sel->priority_selected = s_sel->pid_struct[loop_selected].loop_priority;
								else
									s_sel->priority_selected = s_sel->pid_struct[i].loop_priority;
								
							} //(* End of IF with the same priority *)     
						}
						//(********************************************************************************************)       
						else //         (* different goal direction *) 
						{
							if(s_sel->pid_struct[i].cur_act)
							{
								if(s_sel->pid_struct[loop_selected].cur_act)  // (* selected before loop is active *)
								{
									if(s_sel->pid_struct[i].loop_priority < s_sel->priority_selected)  //(* Both are active *)
									{
										s_sel->PplusD_selected = s_sel->pid_struct[i].PplusD_part ; //(* select higher priority *)
										s_sel->goal_dir_selected = s_sel->pid_struct[i].goal_dir;
										s_sel->priority_selected = s_sel->pid_struct[i].loop_priority;
										loop_selected = i;
										s_sel->dI_selected = s_sel->pid_struct[i].dI_part ; 
									}
									else if(s_sel->pid_struct[i].loop_priority == s_sel->priority_selected)  //(* Both are active *)
									{
										if((s_sel->pid_struct[i].loop_type == 1) && (s_sel->pid_struct[loop_selected].loop_type != 1))  // (* Lower action *)
										{
											s_sel->PplusD_selected = s_sel->pid_struct[i].PplusD_part ; 
											s_sel->goal_dir_selected = s_sel->pid_struct[i].goal_dir;
											s_sel->priority_selected = s_sel->pid_struct[i].loop_priority;
											loop_selected = i;
											s_sel->dI_selected = s_sel->pid_struct[i].dI_part;
										}
									}
								}
								else //(* selected before loop is not active *)
								{
									//(*	IF NOT s_sel->oppos_limits THEN *)
									s_sel->PplusD_selected = s_sel->pid_struct[i].PplusD_part ; //(* select higher priority *)
									s_sel->goal_dir_selected = s_sel->pid_struct[i].goal_dir;
									s_sel->priority_selected = s_sel->pid_struct[i].loop_priority;
									loop_selected = i;
									s_sel->dI_selected = s_sel->pid_struct[i].dI_part ;
									//(*END_IF;*)
								}
							}	
							else  // (* current loop not active *) 
							{
								if(( !s_sel->pid_struct[loop_selected].cur_act) || (loop_selected == main_loop_in)) //(* previously selected loop is not active *)
								{
									if(((s_sel->pid_struct[i].loop_type == 1) && cond_PplusD_selected) || ((s_sel->pid_struct[i].loop_type == -1 ) && ( !cond_PplusD_selected)))
									{
										s_sel->PplusD_selected = s_sel->pid_struct[i].PplusD_part ; //(* select slowest *)
										s_sel->goal_dir_selected = s_sel->pid_struct[i].goal_dir;
										loop_selected = i;
									}
									if(s_sel->pid_struct[i].loop_priority > s_sel->pid_struct[loop_selected].loop_priority)
									{
										s_sel->priority_selected = s_sel->pid_struct[loop_selected].loop_priority;
									}
									else
									{
										s_sel->priority_selected = s_sel->pid_struct[i].loop_priority;
									}
									if(((s_sel->pid_struct[i].loop_type == 1) && cond_dI_selected) || ((s_sel->pid_struct[i].loop_type == -1) && ( !cond_dI_selected)))
									{
										s_sel->dI_selected = s_sel->pid_struct[i].dI_part ;        
									} 	        
								}
							}
						} // (* End of analisys goal directions  *)
						//(*---------------------------------------------------*)
					} //   (* Current loop is not to include into selection (not active)  *)
				}  //     (* Current loop is not enabled   *)
			}
			s_sel->limit_goal = s_sel->pid_struct[loop_selected].limit_goal;
		} //  (* No Limit conditions at all *)
		s_sel->loop_selected   =  loop_selected;
		stopLim(s_sel, test_reg);
		//(*--------------------------------------------------------------------*)
	}      

	return (1);
}






