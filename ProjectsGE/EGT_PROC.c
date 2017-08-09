#include <PACRXPlc.h>

void EGT_PROC(ext_var *conf_ani, PID_conf_fx *EGT_cnf, REAL_IN_STRUCT *Anis, ANI *out, T_REAL32 *DEV_PLUS, T_REAL32 *DEV_MINUS, T_REAL32 *DIFF, T_BOOLEAN *EGT_ALL_FAILURE)
{
T_INT16    i;
T_INT16    j;
T_INT16    k;
T_INT16    x;
T_INT16    y;
T_INT16    z;
T_REAL32    a;
T_INT16    inc;
T_INT16    iCount;
T_INT16    inps_in_use;
T_INT16    used_nums[25];
T_INT16    index;
T_INT16    k_intern;
REAL_IN_STRUCT    AnIn[25];
REAL_IN_STRUCT    tmp_var;
T_INT16    input_selected;
T_INT16    prev_input_selected;
T_WORD    prev_error[25];
T_BOOLEAN    prev_enable[25];
T_REAL32    EGT[25];
T_BOOLEAN    EGT_ERR[25];
T_REAL32    EGT_AVG;
T_REAL32    EGT_MAX;
T_REAL32    EGT_MED;
T_REAL32    EGT_MIN;
T_INT16    EGT_AVG_num;
T_INT16    EGT_MAX_num;
T_INT16    EGT_MED_num;
T_INT16    EGT_MIN_num;
T_REAL32    GAIN;
T_INT16    good_channels[25];
T_REAL32    tmp1;
// Created: Monday, April 12, 2010
// Description:
//-------------------------------------


       
                  
       inps_in_use = 0;
       for( iCount=1 ; iCount <=  24 ; iCount++){ 
         used_nums[iCount] =0; 
         switch(  iCount ){ 
 case
           1:    tmp_var= Anis[1];
 case
           2:    tmp_var= Anis[2];
 case
           3:    tmp_var= Anis[3];
 case
           4:    tmp_var= Anis[4];
 case
           5:    tmp_var= Anis[5];
 case
           6:    tmp_var= Anis[6];
 case
           7:    tmp_var= Anis[7];
 case
           8:    tmp_var= Anis[8];
 case
           9:    tmp_var= Anis[9];
 case
           10:    tmp_var= Anis[10];
 case
           11:    tmp_var= Anis[11];
 case
           12:    tmp_var= Anis[12];
 case
           13:    tmp_var= Anis[13];
 case
           14:    tmp_var= Anis[14];
 case
           15:    tmp_var= Anis[15];
 case
           16:    tmp_var= Anis[16];
 case
           17:    tmp_var= Anis[17];
 case
           18:    tmp_var= Anis[18];
 case
           19:    tmp_var= Anis[19];
 case
           20:    tmp_var= Anis[20];
 case
           21:    tmp_var= Anis[21];
 case
           22:    tmp_var= Anis[22];
 case
           23:    tmp_var= Anis[23];
 case
           24:    tmp_var= Anis[24];
         }
               
         if( conf_ani->trans_enable[iCount] ){

            AnIn[iCount].Value = tmp_var.Value * 100.0;  
            
            AnIn[iCount].Error = tmp_var.Error;
               inps_in_use = inps_in_use + 1;
               used_nums[inps_in_use] = iCount;
         }
      } 
      
      
      

      prev_input_selected = input_selected;

    EGT_AVG=0.0;
    EGT_MAX=0.0;
    EGT_MED=0.0;
    EGT_MIN=99.9; 
    k_intern = 0;   
      
                      for( iCount = 1 ; iCount <=  inps_in_use ; iCount++){  
               index = used_nums[iCount];
               if( AnIn[index].Error == 0 ){

                  if( EGT_MAX < AnIn[index].Value ){
                     EGT_MAX = AnIn[index].Value;
                     EGT_MAX_num = index;
                  }
          
                  if( EGT_MIN > AnIn[index].Value ){
                     EGT_MIN = AnIn[index].Value;
                     EGT_MIN_num = index;                                
                  }

                  EGT_AVG=EGT_AVG+AnIn[index].Value;
          k_intern = k_intern +1;
          good_channels[k_intern] = index;
               }
            } 
            
            T_k_intern1 = k_intern;
            T_EGT_AVG = EGT_AVG;

               if( (k_intern > 0) ){ 
                  out->Error = FALSE;
          EGT_AVG_num = k_intern; 
          INT_TO_REAL(k_intern,tmp1);
          if( (tmp1 != 0.0) ){
                    EGT_AVG = EGT_AVG /tmp1;                     }
      T_EGT_AVG = EGT_AVG;
          if( k_intern == 1 ){
                     index = good_channels[1];
                     EGT_MED = AnIn[index].Value;
           EGT_MED_num=index;
                  }else{ 
              
              
                      if( (k_intern <= 12) ){   
                        
                                                for( j=2 ; j <=  k_intern ; j++){ 
                             y=good_channels[j];
                             a=AnIn[y].Value;
                             i=j-1;
                             x=good_channels[i];
                             while( (i > 0 && AnIn[x].Value > a) ){  
                                    k=i+1;
                                    good_channels[k]=good_channels[i];
                                    i=i-1;
                                    if( i == 0 ){
                                        EXIT;
                                    }
                                     x=good_channels[i];
                             }
                             k=i+1;
                             good_channels[k]=y;
                          }
            
                        }else{  
                                                    inc = 1;
                            do{
                             inc = inc * 3;
                             inc = inc + 1;
                           }while( inc >= k_intern
                           );
                           T_inc = inc;
                           do{
                            inc = inc / 3;
                             for( i = inc+1 ; i <=  k_intern ; i++){ 
                                 x = good_channels[i];
                                 a = AnIn[x].Value;
                                 j = i;
                                 k = j - inc;
                                 z = good_channels[k];
                                 while( AnIn[z].Value > a ){ 
                                       good_channels[j] = good_channels[k];
                                       j = j - inc;
                                       if( j <= inc ){
                                           EXIT;
                                       }
                                       k = j - inc;
                                 }
                                 good_channels[j] = x;
                              }
                            }while( inc < 1
                            );
   
                         } 
                       
                     i=fmod(k_intern,2);
                     j= (k_intern / 2);
                     k= j+1;
                     y=good_channels[j];
                     z=good_channels[k];

          good_channels[k]=fmod(k,k_intern);
          z=fmod(j,y);


                       
                     if( i == 0 ){
                        EGT_MED = AnIn[y].Value;
                        EGT_MED_num = y;
                      }else{
                        EGT_MED = AnIn[z].Value;
                        EGT_MED_num = z;
                      }
               
            }
   
               }else{
                  out->Error = TRUE; 
               }        
  T_EGT_MED = EGT_MED;
  T_Method = conf_ani->selection_method;
switch( conf_ani->selection_method ){ 
 case
     1:   out->Value = EGT_MED; 
                           input_selected=EGT_MED_num;
 case 
     2:   out->Value = EGT_AVG; 
                           input_selected=EGT_AVG_num;
 case 
     3:   out->Value = EGT_MIN; 
                           input_selected=EGT_MIN_num;
 case 
   4:   out->Value = EGT_MAX; 
                           input_selected=EGT_MAX_num;   
}  
T_*out_EGT = out->Value;                         
      
if( prev_input_selected != input_selected ){

      
      if( conf_ani->trans_enable[1] != prev_enable[1] ){ 
         out->SwitchFlag = TRUE;
      }else if( conf_ani->trans_enable[2] != prev_enable[2] ){ 
         out->SwitchFlag = TRUE;
      }else if( conf_ani->trans_enable[3] != prev_enable[3] ){ 
         out->SwitchFlag = TRUE;
      }else if( conf_ani->trans_enable[4] != prev_enable[4] ){ 
         out->SwitchFlag = TRUE;
      }else if( conf_ani->trans_enable[5] != prev_enable[5] ){ 
         out->SwitchFlag = TRUE;
      }else if( conf_ani->trans_enable[6] != prev_enable[6] ){ 
         out->SwitchFlag = TRUE;
      }else if( conf_ani->trans_enable[7] != prev_enable[7] ){ 
         out->SwitchFlag = TRUE;
      }else if( conf_ani->trans_enable[8] != prev_enable[8] ){ 
         out->SwitchFlag = TRUE;
      }else if( conf_ani->trans_enable[9] != prev_enable[9] ){ 
         out->SwitchFlag = TRUE;
      }else if( conf_ani->trans_enable[10] != prev_enable[10] ){ 
         out->SwitchFlag = TRUE;
      }else if( conf_ani->trans_enable[11] != prev_enable[11] ){ 
         out->SwitchFlag = TRUE;
      }else if( conf_ani->trans_enable[12] != prev_enable[12] ){ 
         out->SwitchFlag = TRUE;
      }else if( conf_ani->trans_enable[13] != prev_enable[13] ){ 
         out->SwitchFlag = TRUE;
      }else if( conf_ani->trans_enable[14] != prev_enable[14] ){ 
         out->SwitchFlag = TRUE;
      }else if( conf_ani->trans_enable[15] != prev_enable[15] ){ 
         out->SwitchFlag = TRUE;
      }else if( conf_ani->trans_enable[16] != prev_enable[16] ){ 
         out->SwitchFlag = TRUE;
      }else if( conf_ani->trans_enable[17] != prev_enable[17] ){ 
         out->SwitchFlag = TRUE;
      }else if( conf_ani->trans_enable[18] != prev_enable[18] ){ 
         out->SwitchFlag = TRUE;
      }else if( conf_ani->trans_enable[19] != prev_enable[19] ){ 
         out->SwitchFlag = TRUE;
      }else if( conf_ani->trans_enable[20] != prev_enable[20] ){ 
         out->SwitchFlag = TRUE;
      }else if( conf_ani->trans_enable[21] != prev_enable[21] ){ 
         out->SwitchFlag = TRUE;
      }else if( conf_ani->trans_enable[22] != prev_enable[22] ){ 
         out->SwitchFlag = TRUE;
      }else if( conf_ani->trans_enable[23] != prev_enable[23] ){ 
         out->SwitchFlag = TRUE;
      }else if( conf_ani->trans_enable[24] != prev_enable[24] ){ 
         out->SwitchFlag = TRUE;
      }
      

      
      if( conf_ani->trans_enable[1] && (AnIn[1].Error != prev_error[1]) ){
         out->SwitchFlag = TRUE;
      }else if( conf_ani->trans_enable[2] && (AnIn[2].Error != prev_error[2]) ){
         out->SwitchFlag = TRUE;
      }else if( conf_ani->trans_enable[3] && (AnIn[3].Error != prev_error[3]) ){
         out->SwitchFlag = TRUE;
      }else if( conf_ani->trans_enable[4] && (AnIn[4].Error != prev_error[4]) ){
         out->SwitchFlag = TRUE;
      }else if( conf_ani->trans_enable[5] && (AnIn[5].Error != prev_error[5]) ){
         out->SwitchFlag = TRUE;
      }else if( conf_ani->trans_enable[6] && (AnIn[6].Error != prev_error[6]) ){
         out->SwitchFlag = TRUE;
      }else if( conf_ani->trans_enable[7] && (AnIn[7].Error != prev_error[7]) ){
         out->SwitchFlag = TRUE;
      }else if( conf_ani->trans_enable[8] && (AnIn[8].Error != prev_error[8]) ){
         out->SwitchFlag = TRUE;
      }else if( conf_ani->trans_enable[9] && (AnIn[9].Error != prev_error[9]) ){
         out->SwitchFlag = TRUE;
      }else if( conf_ani->trans_enable[10] && (AnIn[10].Error != prev_error[10]) ){
         out->SwitchFlag = TRUE;
      }else if( conf_ani->trans_enable[11] && (AnIn[11].Error != prev_error[11]) ){
         out->SwitchFlag = TRUE;
      }else if( conf_ani->trans_enable[12] && (AnIn[12].Error != prev_error[12]) ){
         out->SwitchFlag = TRUE;
      }else if( conf_ani->trans_enable[13] && (AnIn[13].Error != prev_error[13]) ){
         out->SwitchFlag = TRUE;
      }else if( conf_ani->trans_enable[14] && (AnIn[14].Error != prev_error[14]) ){
         out->SwitchFlag = TRUE;
      }else if( conf_ani->trans_enable[15] && (AnIn[15].Error != prev_error[15]) ){
         out->SwitchFlag = TRUE;
      }else if( conf_ani->trans_enable[16] && (AnIn[16].Error != prev_error[16]) ){
         out->SwitchFlag = TRUE;
      }else if( conf_ani->trans_enable[17] && (AnIn[17].Error != prev_error[17]) ){
         out->SwitchFlag = TRUE;
      }else if( conf_ani->trans_enable[18] && (AnIn[18].Error != prev_error[18]) ){
         out->SwitchFlag = TRUE;
      }else if( conf_ani->trans_enable[19] && (AnIn[19].Error != prev_error[19]) ){
         out->SwitchFlag = TRUE;
      }else if( conf_ani->trans_enable[20] && (AnIn[20].Error != prev_error[20]) ){
         out->SwitchFlag = TRUE; 
      }else if( conf_ani->trans_enable[21] && (AnIn[21].Error != prev_error[21]) ){
         out->SwitchFlag = TRUE;
      }else if( conf_ani->trans_enable[22] && (AnIn[22].Error != prev_error[22]) ){
         out->SwitchFlag = TRUE;
      }else if( conf_ani->trans_enable[23] && (AnIn[23].Error != prev_error[23]) ){
         out->SwitchFlag = TRUE;
      }else if( conf_ani->trans_enable[24] && (AnIn[24].Error != prev_error[24]) ){
         out->SwitchFlag = TRUE;        
      }
    
}else{
   out->SwitchFlag = FALSE;
}

prev_enable[1] = conf_ani->trans_enable[1];
prev_enable[2] = conf_ani->trans_enable[2];
prev_enable[3] = conf_ani->trans_enable[3];
prev_enable[4] = conf_ani->trans_enable[4];
prev_enable[5] = conf_ani->trans_enable[5];
prev_enable[6] = conf_ani->trans_enable[6];
prev_enable[7] = conf_ani->trans_enable[7];
prev_enable[8] = conf_ani->trans_enable[8];
prev_enable[9] = conf_ani->trans_enable[9];
prev_enable[10] = conf_ani->trans_enable[10];
prev_enable[11] = conf_ani->trans_enable[11];
prev_enable[12] = conf_ani->trans_enable[12];
prev_enable[13] = conf_ani->trans_enable[13];
prev_enable[14] = conf_ani->trans_enable[14];
prev_enable[15] = conf_ani->trans_enable[15];
prev_enable[16] = conf_ani->trans_enable[16];
prev_enable[17] = conf_ani->trans_enable[17];
prev_enable[18] = conf_ani->trans_enable[18];
prev_enable[19] = conf_ani->trans_enable[19];
prev_enable[20] = conf_ani->trans_enable[20];
prev_enable[21] = conf_ani->trans_enable[21];
prev_enable[22] = conf_ani->trans_enable[22];
prev_enable[23] = conf_ani->trans_enable[23];
prev_enable[24] = conf_ani->trans_enable[24];

prev_error[1] = AnIn[1].Error;
prev_error[2] = AnIn[2].Error;
prev_error[3] = AnIn[3].Error;
prev_error[4] = AnIn[4].Error;
prev_error[5] = AnIn[5].Error;
prev_error[6] = AnIn[6].Error;
prev_error[7] = AnIn[7].Error;
prev_error[8] = AnIn[8].Error;
prev_error[9] = AnIn[9].Error;
prev_error[10] = AnIn[10].Error;
prev_error[11] = AnIn[11].Error;
prev_error[12] = AnIn[12].Error;
prev_error[13] = AnIn[13].Error;
prev_error[14] = AnIn[14].Error;
prev_error[15] = AnIn[15].Error;
prev_error[16] = AnIn[16].Error;
prev_error[17] = AnIn[17].Error;
prev_error[18] = AnIn[18].Error;
prev_error[19] = AnIn[19].Error;
prev_error[20] = AnIn[20].Error;
prev_error[21] = AnIn[21].Error;
prev_error[22] = AnIn[22].Error;
prev_error[23] = AnIn[23].Error;
prev_error[24] = AnIn[24].Error;

GAIN=EGT_cnf->span/100.0;
EGT[1]=AnIn[1].Value*GAIN + EGT_cnf->offset;
EGT[2]=AnIn[2].Value*GAIN + EGT_cnf->offset;
EGT[3]=AnIn[3].Value*GAIN + EGT_cnf->offset;
EGT[4]=AnIn[4].Value*GAIN + EGT_cnf->offset;
EGT[5]=AnIn[5].Value*GAIN + EGT_cnf->offset;
EGT[6]=AnIn[6].Value*GAIN + EGT_cnf->offset;
EGT[7]=AnIn[7].Value*GAIN + EGT_cnf->offset;
EGT[8]=AnIn[8].Value*GAIN + EGT_cnf->offset;
EGT[9]=AnIn[9].Value*GAIN + EGT_cnf->offset;
EGT[10]=AnIn[10].Value*GAIN + EGT_cnf->offset;
EGT[11]=AnIn[11].Value*GAIN + EGT_cnf->offset;
EGT[12]=AnIn[12].Value*GAIN + EGT_cnf->offset;
EGT[13]=AnIn[13].Value*GAIN + EGT_cnf->offset;
EGT[14]=AnIn[14].Value*GAIN + EGT_cnf->offset;
EGT[15]=AnIn[15].Value*GAIN + EGT_cnf->offset;
EGT[16]=AnIn[16].Value*GAIN + EGT_cnf->offset;
EGT[17]=AnIn[17].Value*GAIN + EGT_cnf->offset;
EGT[18]=AnIn[18].Value*GAIN + EGT_cnf->offset;
EGT[19]=AnIn[19].Value*GAIN + EGT_cnf->offset;
EGT[20]=AnIn[20].Value*GAIN + EGT_cnf->offset;
EGT[21]=AnIn[21].Value*GAIN + EGT_cnf->offset;
EGT[22]=AnIn[22].Value*GAIN + EGT_cnf->offset;
EGT[23]=AnIn[23].Value*GAIN + EGT_cnf->offset;
EGT[24]=AnIn[24].Value*GAIN + EGT_cnf->offset;

EGT_ERR[1] = (AnIn[1].Error != 0);
EGT_ERR[2] = (AnIn[2].Error != 0);
EGT_ERR[3] = (AnIn[3].Error != 0);
EGT_ERR[4] = (AnIn[4].Error != 0);
EGT_ERR[5] = (AnIn[5].Error != 0);
EGT_ERR[6] = (AnIn[6].Error != 0);
EGT_ERR[7] = (AnIn[7].Error != 0);
EGT_ERR[8] = (AnIn[8].Error != 0);
EGT_ERR[9] = (AnIn[9].Error != 0);
EGT_ERR[10] = (AnIn[10].Error != 0);
EGT_ERR[11] = (AnIn[11].Error != 0);
EGT_ERR[12] = (AnIn[12].Error != 0);
EGT_ERR[13] = (AnIn[13].Error != 0);
EGT_ERR[14] = (AnIn[14].Error != 0);
EGT_ERR[15] = (AnIn[15].Error != 0);
EGT_ERR[16] = (AnIn[16].Error != 0);
EGT_ERR[17] = (AnIn[17].Error != 0);
EGT_ERR[18] = (AnIn[18].Error != 0);
EGT_ERR[19] = (AnIn[19].Error != 0);
EGT_ERR[20] = (AnIn[20].Error != 0);
EGT_ERR[21] = (AnIn[21].Error != 0);
EGT_ERR[22] = (AnIn[22].Error != 0);
EGT_ERR[23] = (AnIn[23].Error != 0);
EGT_ERR[24] = (AnIn[24].Error != 0);

if( (k_intern > 0) ){
EGT_MAX=EGT_MAX*GAIN + EGT_cnf->offset;
EGT_MIN=EGT_MIN*GAIN + EGT_cnf->offset;
EGT_MED=EGT_MED*GAIN + EGT_cnf->offset;
EGT_AVG=EGT_AVG*GAIN + EGT_cnf->offset;
*EGT_ALL_FAILURE=FALSE;
}else{ 
EGT_MAX=0.0;
EGT_MIN=0.0;
EGT_MED=0.0;
EGT_AVG=0.0;
*EGT_ALL_FAILURE=inps_in_use>0;
}

*DEV_PLUS=EGT_MAX-EGT_AVG;
*DEV_MINUS=EGT_AVG-EGT_MIN;
*DIFF=EGT_MAX-EGT_MIN;







}
void GefMain(conf_ani, EGT_cnf, Anis, out, DEV_PLUS, DEV_MINUS, DIFF, EGT_ALL_FAILURE)
ext_var    *conf_ani;
PID_conf_fx    *EGT_cnf;
REAL_IN_STRUCT    *Anis;
ANI    *out;
T_REAL32    *DEV_PLUS;
T_REAL32    *DEV_MINUS;
T_REAL32    *DIFF;
T_BOOLEAN    *EGT_ALL_FAILURE;
{
    EGT_PROC(conf_ani, EGT_cnf, Anis, out, DEV_PLUS, DEV_MINUS, DIFF, EGT_ALL_FAILURE);
}
