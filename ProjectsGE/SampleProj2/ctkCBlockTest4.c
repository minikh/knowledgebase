#include "copyright.h"
/*************************************************************************
 * Module $Id: ctkCBlockTest4.c,v 1.6 2003/11/17 22:20:03 cashb1 Exp $
 *************************************************************************/
/******************************************************************************
`ModuleName ctkCBlockTest4.c
` This file uses all C Run Time and Target Library functions supported
` by the C Toolkit to test that all the supported functions can
` be compiled. 
` 
` Setup:  Note Hardware configuration memory must be setup to use %W memory,
`         watchdog set to 2550ms, Point Fault References Enabled.  The program
`         must use %P in the Main and %L if a subblock calls this block.
`         In order to see the output to the serial port, the serial port
`         should be set up for message mode.
*******************************************************************************/
/* `IncludeFiles */
#include "PACRXPlc.h"  /* Include file applicable for all targets */
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>
/* Constants / #defines  */

/* Structures and typedefs */

/* Declarations for Global variables */
/* Global variable used to run some functions
   only one time because running every sweep
   could cause loss of PLC communications such
   as changing the Run enabled mode each sweep */
static T_BOOLEAN firstExecution = TRUE;
/* Declarations for Local variables */
/* Forward declarations */
void ctkCBlockTest5(void);

/* Routines */
void ctkCBlockTest4(void)
{
    T_INT32 resultInt32;
    struct elapsed_clock_rec elapsedClockRec;
    struct nano_elapsed_clock_rec nanoElapsedClockRec;
    T_WORD errorCode = 1;
    char faultString[100];
    struct PLC_ver_info_rec plcVerInfoRec;
    struct const_sweep_timer_rec constSweepTimerRec;
    struct read_window_values_rec readWindowValuesRec;
    struct change_controller_comm_window_rec changeControllerCommWindow;
    struct change_backplane_comm_window_rec changeBackplaneCommWindow;
    struct change_background_window_rec changeBackgroundWindowRec;
    struct number_of_words_in_chksm_rec numberOfWordsInChecksumRec;
    struct tod_clock_rec todClockRec;
/*     struct tod_clock_with_status_rec todClockWithStatusRec; */
    struct time_since_start_of_sweep_rec timeSinceStartOfSweepRec;
    struct nano_time_since_start_of_sweep_rec nanoTimeSinceStartOfSweepRec;
    struct read_folder_name_rec readFolderNameRec;
    struct read_PLC_ID_rec readPlcIdRec;
    struct read_PLC_state_rec readPlcStateRec;
    struct mask_IO_interrupts_rec maskIoInterruptsRec;
    struct read_IO_override_status_rec readIoOverrideStatusRec;
    struct set_run_enable_rec setRunEnableRec;
    struct mask_timed_interrupts_rec maskTimedInterruptsRec;
    struct sus_res_HSC_interrupts_rec susResHscInterruptsRec;
    struct escm_status_rec escmStatusRec;
    struct comm_req_command_blk_rec commReqCommandBlkRec;
    struct comm_req_rec commReqRec;
    struct comm_req_command_blk_rec_extended commReqCommandBlkRecExtended;
    struct comm_req_rec_extended commReqExtendedRec;
    struct do_io_rec doIoRec;
    T_BYTE request_type;
    char id_str[8];
    T_BYTE tbl_typ;
    T_WORD ref_num;
    T_WORD len;
    T_BYTE data;
    char buffer[100];
    T_INT32 numBytes = 0;

    numBytes = sprintf(buffer, "Plc General functions \r\n");
    PLCC_MessageWrite(PORT1, buffer, numBytes);

    /* Plc General functions */
    resultInt32 = PLCC_read_elapsed_clock(&elapsedClockRec);
    resultInt32 =  PLCC_read_nano_elapsed_clock(&nanoElapsedClockRec);
    resultInt32 =  PLCC_chars_in_printf_q();
    
    errorCode = 1;
    sprintf(faultString, "This is a test fault string");
    resultInt32 =  PLCC_gen_alarm (errorCode, faultString);
    
    resultInt32 =  PLCC_get_plc_version (&plcVerInfoRec);

    constSweepTimerRec.const_sweep.input.action = READ_TIMER_VALUE_AND_STATE;
    resultInt32 =   PLCC_const_sweep_timer(&constSweepTimerRec);

    resultInt32 =   PLCC_read_window_values(&readWindowValuesRec);

    /* controller, backplane, and background comm windows set to PLC default values */
	changeControllerCommWindow.mode = LIMITED_MODE;	
	changeControllerCommWindow.time = 10;		
    resultInt32 =   PLCC_change_controller_comm_window (&changeControllerCommWindow);

	changeBackplaneCommWindow.mode = RUN_TO_COMPLETION_MODE;	
	changeBackplaneCommWindow.time = 255;	
    resultInt32 =   PLCC_change_backplane_comm_window(&changeBackplaneCommWindow);

	changeBackgroundWindowRec.mode = LIMITED_MODE;
	changeBackgroundWindowRec.time = 0;		
    resultInt32 =   PLCC_change_background_window (&changeBackgroundWindowRec);

    numberOfWordsInChecksumRec.read_set =  READ_CHECKSUM_WORDS;
    resultInt32 =   PLCC_number_of_words_in_chksm (&numberOfWordsInChecksumRec);

    todClockRec.read_write = READ_CLOCK;
    todClockRec.format = NUMERIC_DATA_FORMAT;
    resultInt32 =   PLCC_tod_clock(&todClockRec);
/*    resultInt32 =   PLCC_tod_clock_with_status(&todClockWithStatusRec); Not supported */

    resultInt32 =   PLCC_reset_watchdog_timer();
    resultInt32 =   PLCC_time_since_start_of_sweep (&timeSinceStartOfSweepRec);
    resultInt32 =   PLCC_nano_time_since_start_of_sweep (&nanoTimeSinceStartOfSweepRec);
    resultInt32 =   PLCC_read_folder_name (&readFolderNameRec);
    resultInt32 =   PLCC_read_PLC_ID(&readPlcIdRec);
    resultInt32 =   PLCC_read_PLC_state(&readPlcStateRec);
/*    resultInt32 =   PLCC_shut_down_plc(0);  commented out so that PLC does not shut down */

    maskIoInterruptsRec.mask = UNMASK; 
    maskIoInterruptsRec.memory_address = 33;
    maskIoInterruptsRec.memory_type = I_BIT; /* valid values must be I/O types I_BIT, AQ_MEM, AI_MEM */
    resultInt32 =   PLCC_mask_IO_interrupts(&maskIoInterruptsRec);

    resultInt32 =   PLCC_read_IO_override_status (&readIoOverrideStatusRec);

    /* run only one time to avoid communications issues with PLC */
    if (firstExecution)
    {
        setRunEnableRec.enable = RUN_ENABLED;  
        resultInt32 =   PLCC_set_run_enable(&setRunEnableRec);
    }

    maskTimedInterruptsRec.action = READ_INTERRUPT_MASK; 
    resultInt32 =   PLCC_mask_timed_interrupts (&maskTimedInterruptsRec);

    susResHscInterruptsRec.action =  RESUME; 
    susResHscInterruptsRec.memory_type = I_BIT;
    susResHscInterruptsRec.reference_address = 33;
    resultInt32 =   PLCC_sus_res_HSC_interrupts (&susResHscInterruptsRec);

    resultInt32 =   PLCC_get_escm_status (&escmStatusRec);

    numBytes = sprintf(buffer, "call comm req \r\n");
    PLCC_MessageWrite(PORT1, buffer, numBytes);

    /* Example sending a COMMREQ write to the GBC in rack 0, slot 9 (SBA 31)
       using bit memory */

    /* set the parameters */
    commReqRec.slot = 0x09;             /* GBC in rack 0, slot 9 */
    commReqRec.rack = 0x00;
    commReqRec.task_id = 0x01;          /* task id is dword 1 */
    commReqRec.command_blk = &commReqCommandBlkRec;  /* initialize pointer to command block */
    commReqCommandBlkRec.length = 14;          /* length of command block is 14 words */
    commReqCommandBlkRec.wait = 0x00;            /* 0 for nowait mode */
    commReqCommandBlkRec.status.seg_selector = R_MEM;    /* status in %R1002, 08 for RMEM */
    commReqCommandBlkRec.status.offset = 1001;        /* 1001 offset for %R1002 */
    commReqCommandBlkRec.idle_timeout = 0x00;    /* ignored in nowait mode */
    commReqCommandBlkRec.max_comm_time = 0x00;   /* ignored in nowait mode */
    commReqCommandBlkRec.data[0] = 12;         /* 12 for write device */
    commReqCommandBlkRec.data[1] = 31;         /* write to device at SBA 31 */
    commReqCommandBlkRec.data[2] = 76;         /* 76 is %M in bits written to */
    commReqCommandBlkRec.data[3] = 112;        /* offset for 112 for %M113 */
    commReqCommandBlkRec.data[12] =16;			/* 16 bits of data */
    commReqCommandBlkRec.data[13] = Qw(33);      /* send data of word at %Q33 */
    resultInt32 =   PLCC_comm_req(&commReqRec);

    /* Example sending a COMMREQ Extended write to the GBC in rack 0, slot 9 (SBA 31)
       using bit memory.  This function allows for addressing reference memories
       with addresses greater than 64K */

    /* set the parameters */
    commReqExtendedRec.slot = 0x09;             /* GBC in rack 0, slot 9 */
    commReqExtendedRec.rack = 0x00;
    commReqExtendedRec.task_id = 0x01;          /* task id is dword 1 */
    commReqExtendedRec.command_blk = &commReqCommandBlkRecExtended;  /* initialize pointer to command block */
    commReqCommandBlkRecExtended.length = 14;          /* length of command block is 14 words */
    commReqCommandBlkRecExtended.wait = 0x00;            /* 0 for nowait mode */
    commReqCommandBlkRecExtended.status.seg_selector = W_MEM;    /* status in %R1002, 08 for RMEM */
    commReqCommandBlkRecExtended.status.offset = 100001;        /* 100001 offset for %W100002 */
    commReqCommandBlkRecExtended.idle_timeout = 0x00;    /* ignored in nowait mode */
    commReqCommandBlkRecExtended.max_comm_time = 0x00;   /* ignored in nowait mode */
    commReqCommandBlkRecExtended.data[0] = 12;         /* 12 for write device */
    commReqCommandBlkRecExtended.data[1] = 31;         /* write to device at SBA 31 */
    commReqCommandBlkRecExtended.data[2] = 76;         /* 76 is %M in bits written to */
    commReqCommandBlkRecExtended.data[3] = 112;        /* offset for 112 for %M113 */
    commReqCommandBlkRecExtended.data[12] =16;			/* 16 bits of data */
    commReqCommandBlkRecExtended.data[13] = Qw(33);      /* send data of word at %Q33 */
    /* Note PLCC_comm_req_extended returns GEf_NOT_SUPPORTED for Rel 1.0 */
    resultInt32 =   PLCC_comm_req_extended(&commReqExtendedRec);

    doIoRec.start_mem_type = I_MEM; 
    doIoRec.start_mem_offset = 1;
    doIoRec.length = 1;
    doIoRec.alt_mem_type = M_MEM;
    doIoRec.alt_mem_offset = 1;
    resultInt32 =   PLCC_do_io(&doIoRec);

    resultInt32 =   PLCC_sus_io();

    request_type = READ_ID;
    sprintf(id_str,"1234567"); 
    /* Note: PLCC_SNP_ID returns GEF_NOT_SUPPORTED in Rel 1.0 */ 
    resultInt32 =  PLCC_SNP_ID(request_type, id_str); 

    tbl_typ =  I_MEM;  /* valid memories are I_MEM, Q_MEM, G_MEM, M_MEM */
    ref_num = 1;
    len = 1;
    resultInt32 =   PLCC_read_override(tbl_typ, ref_num, len, &data);


    numBytes = sprintf(buffer, "calling ctkCBlockTest5 \r\n");
    PLCC_MessageWrite(PORT1, buffer, numBytes);

    /* set flag to indicate first execution is complete */
    firstExecution = FALSE;
    ctkCBlockTest5();
}









