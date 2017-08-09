/*************************************************************************
*    This computer program contains confidential and proprietary         *
*    information of GE Intelligent Platforms, Inc. Neither the program 	 *
*    nor the information contained therein may be copied or disclosed 	 *
*    to any third party without the prior written approval of 			 *
*    GE Intelligent Platforms. Unauthorized use of the information 		 *
*    or program is strictly prohibited.                      			 *
*                                                                        *
*    Copyright (c) 2001 - 2010 GE INTELLIGENT PLATFORMS, INC.  	 		 *
*      Published in only limited, copyright sense and all rights,        *
*      including trade secret rights, are reserved.  Unauthorized        *
*      use of the information or program is strictly prohibited.         *
*                                                                        *
*    All Rights Reserved.                                                *
*************************************************************************/
/*************************************************************************
 * Module $Id: ctkPlcFunc.c,v 1.13 2010/08/05 14:27:48 mummids1 Exp $
 *************************************************************************/
/******************************************************************************
`ModuleName ctkPlcFunc.c
` This file contains stub implementations of  general
` PLC functions which are used for debugging on the PC.
`
*******************************************************************************/
/* IncludeFiles */

#include "ctkReleaseToUse.h"      /* Passes release number, used for three
                                     build environments - PLC firmware build
                                     C tool kit configuration build, and C
                                     Tool kit end user build.
                                  */

#include "ctkPlc.h"
#include "stdio.h"

/* Constants and Enumerations */
/* These are defined in firmware execute.h file but don't want to pull
   this file in for a stub C file.  So they are being defined here */
#define GEF_PWR_FLOW        1
#define GEF_NO_PWR_FLOW     0
/* Type and Structure Definitions */
/* Global variables */
/* Local Variables */
/* Forward declarations */
/* Routines */
/******************************************************************************
`Proc PLCC_read_elapsed_clock
` See ctkPlcFunc.h for a description of this function.
*******************************************************************************/
T_INT32 PLCC_read_elapsed_clock(struct elapsed_clock_rec *pElapsedClockRec)
{
    T_INT32 status = GEF_OK;
    return status;
}

/******************************************************************************
`Proc PLCC_read_nano_elapsed_clock
` See ctkPlcFunc.h for a description of this function.
*******************************************************************************/
T_INT32 PLCC_read_nano_elapsed_clock(struct nano_elapsed_clock_rec *pNanoElapsedClockRec)
{
    T_INT32 status = GEF_OK;
    return status;
}

/*******************************************************************************/

/******************************************************************************
`Proc PLCC_chars_in_printf_q
` See ctkPlcFunc.h for a description of this function.
*******************************************************************************/
T_INT32 PLCC_chars_in_printf_q(void)
{
    T_INT32 status = GEF_OK;
    return status;
}

/*******************************************************************************/

/******************************************************************************
`Proc PLCC_MessageWrite
` See ctkPlcFunc.h for a description of this function.
*******************************************************************************/

T_INT32 PLCC_MessageWrite(T_INT32 port, char *buffer, T_INT32 numBytes)
{
    printf(buffer);
    return numBytes;
}

/*******************************************************************************/


/******************************************************************************
`Proc PLCC_MessageRead
` See ctkPlcFunc.h for a description of this function.
*******************************************************************************/

T_INT32 PLCC_MessageRead(T_INT32 port, char *buffer, T_INT32 numBytes)
{

/* Add code to simulate receiving characters from the port */
    return numBytes;
}

/*******************************************************************************/


/******************************************************************************
`Proc PLCC_CharsInMessageWriteQ
` See ctkPlcFunc.h for a description of this function.
*******************************************************************************/

T_INT32 PLCC_CharsInMessageWriteQ(T_INT32 port)
{
/* Add code to simulate number of bytes in serial port queue */
    T_INT32 numBytesInQ = 0;
    return numBytesInQ;
}

/*******************************************************************************/


/******************************************************************************
`Proc PLCC_CharsInMessageReadQ
` See ctkPlcFunc.h for a description of this function.
*******************************************************************************/

T_INT32 PLCC_CharsInMessageReadQ(T_INT32 port)
{
/* Add code to simulate number of bytes in serial port queue */
    T_INT32 numBytesInQ = 1;
    return numBytesInQ;
}

/*******************************************************************************/
/******************************************************************************
`Proc PLCC_gen_alarm
` See ctkPlcFunc.h for a description of this function.
*******************************************************************************/
T_INT32 PLCC_gen_alarm ( T_WORD errorCode, char * faultString)
{
    T_INT32 status = GEF_OK;
    return status;
}

/*******************************************************************************/

/******************************************************************************
`PLCC_get_plc_version
` See ctkPlcFunc.h for a description of this function.
*******************************************************************************/
T_INT32 PLCC_get_plc_version ( struct PLC_ver_info_rec *pPlcVerInfoRec)
{
    T_INT32 status = GEF_OK;
    return status;
}

/*******************************************************************************/

/******************************************************************************
`Proc PLCC_const_sweep_timer
` See ctkPlcFunc.h for a description of this function.
*******************************************************************************/
T_INT32  PLCC_const_sweep_timer(struct const_sweep_timer_rec *pConstSweepTimerRec)
{
    T_INT32 status = GEF_PWR_FLOW;
    return status;
}

/*******************************************************************************/

/******************************************************************************
`Proc PLCC_read_window_values
` See ctkPlcFunc.h for a description of this function.
*******************************************************************************/
T_INT32  PLCC_read_window_values(struct read_window_values_rec *pReadWindowValuesRec)
{
    T_INT32 status = GEF_PWR_FLOW;
    return status;
}

/*******************************************************************************/

/******************************************************************************
`Proc PLCC_change_controller_comm_window
` See ctkPlcFunc.h for a description of this function.
*******************************************************************************/
T_INT32  PLCC_change_controller_comm_window
		     (struct change_controller_comm_window_rec *pChangeControllerCommWindowRec)
{
    T_INT32 status = GEF_PWR_FLOW;
    return status;
}

/*******************************************************************************/

/******************************************************************************
`Proc PLCC_change_backplane_comm_window
` See ctkPlcFunc.h for a description of this function.
*******************************************************************************/
T_INT32  PLCC_change_backplane_comm_window
		     (struct change_backplane_comm_window_rec *pChangeBackplaneCommWindowRec)
{
    T_INT32 status = GEF_PWR_FLOW;
    return status;
}

/*******************************************************************************/

/******************************************************************************
`Proc PLCC_change_background_window
` See ctkPlcFunc.h for a description of this function.
*******************************************************************************/
T_INT32  PLCC_change_background_window
		     (struct change_background_window_rec *pChangeBackgroundWindowRec)
{
    T_INT32 status = GEF_PWR_FLOW;
    return status;
}

/*******************************************************************************/

/******************************************************************************
`Proc PLCC_number_of_words_in_chksm
` See ctkPlcFunc.h for a description of this function.
*******************************************************************************/
T_INT32  PLCC_number_of_words_in_chksm
		     (struct number_of_words_in_chksm_rec *pNumberOfWordsInChksmRec)
{
    T_INT32 status = GEF_PWR_FLOW;
    return status;
}

/*******************************************************************************/

/******************************************************************************
`Proc PLCC_tod_clock
` See ctkPlcFunc.h for a description of this function.
*******************************************************************************/
T_INT32  PLCC_tod_clock(struct tod_clock_rec *pTodClockRec)
{
    T_INT32 status = GEF_PWR_FLOW;
    return status;
}

/*******************************************************************************/

/******************************************************************************
`Proc PLCC_reset_watchdog_timer
` See ctkPlcFunc.h for a description of this function.
*******************************************************************************/
T_INT32  PLCC_reset_watchdog_timer(void)
{
    T_INT32 status = GEF_PWR_FLOW;
    return status;
}

/*******************************************************************************/

/******************************************************************************
`Proc PLCC_time_since_start_of_sweep
` See ctkPlcFunc.h for a description of this function.
*******************************************************************************/
T_INT32  PLCC_time_since_start_of_sweep
		     (struct time_since_start_of_sweep_rec *pTimeSinceStartOfSweepRec)
{
    T_INT32 status = GEF_PWR_FLOW;
    return status;
}

/******************************************************************************
`Proc PLCC_nano_time_since_start_of_sweep
` See ctkPlcFunc.h for a description of this function.
*******************************************************************************/
T_INT32  PLCC_nano_time_since_start_of_sweep
		     (struct nano_time_since_start_of_sweep_rec *pNanoTimeSinceStartOfSweepRec)
{
    T_INT32 status = GEF_PWR_FLOW;
    return status;
}

/*******************************************************************************/


/*******************************************************************************/

/******************************************************************************
`Proc PLCC_read_folder_name
` See ctkPlcFunc.h for a description of this function.
*******************************************************************************/
T_INT32  PLCC_read_folder_name
		     (struct read_folder_name_rec *pReadFolderNameRec)
{
    T_INT32 status = GEF_PWR_FLOW;
    return status;
}

/*******************************************************************************/

/******************************************************************************
`Proc PLCC_read_PLC_ID
` See ctkPlcFunc.h for a description of this function.
*******************************************************************************/
T_INT32  PLCC_read_PLC_ID(struct read_PLC_ID_rec *pReadPlcIdRec)
{
    T_INT32 status = GEF_PWR_FLOW;
    return status;
}

/*******************************************************************************/

/******************************************************************************
`Proc PLCC_read_PLC_state
` See ctkPlcFunc.h for a description of this function.
*******************************************************************************/
T_INT32  PLCC_read_PLC_state(struct read_PLC_state_rec *pReadPlcStateRec)
{
    T_INT32 status = GEF_PWR_FLOW;
    return status;
}

/*******************************************************************************/

/******************************************************************************
`Proc PLCC_shut_down_plc
` See ctkPlcFunc.h for a description of this function.
*******************************************************************************/
T_INT32  PLCC_shut_down_plc(T_WORD numberOfSweeps)
{
    T_INT32 status = GEF_PWR_FLOW;
    return status;
}

/*******************************************************************************/


#if (CTK_RELEASE_TO_USE >= 0x0500) /* only supported when compiling for
                                      version 5.0 or higher */
/******************************************************************************
`Proc PLCC_set_application_redundancy_mode
` See ctkPlcFunc.h for a description of this function.
*******************************************************************************/
T_INT32  PLCC_set_application_redundancy_mode(T_WORD role)
{
    T_INT32 status = GEF_PWR_FLOW;
    return status;
}

/*******************************************************************************/
#endif /* CTK_RELEASE_TO_USE >= 5.00 */

/******************************************************************************
`Proc PLCC_mask_IO_interrupts
` See ctkPlcFunc.h for a description of this function.
*******************************************************************************/
T_INT32  PLCC_mask_IO_interrupts(struct mask_IO_interrupts_rec *pMaskIoInterruptsRec)
{
    T_INT32 status = GEF_PWR_FLOW;
    return status;
}

/*******************************************************************************/


#if (CTK_RELEASE_TO_USE >= 0x0350) /* only supported when compiling for
                                      version 3.5 or higher */
/******************************************************************************
`Proc  PLCC_mask_IO_interrupts_ext
` See ctkPlcFunc.h for a description of this function.
*******************************************************************************/
T_INT32  PLCC_mask_IO_interrupts_ext(
                     struct mask_IO_interrupts_ext_rec *pMaskIoInterruptsExtRec)
{
    T_INT32 status = GEF_PWR_FLOW;
    return status;
}

/*******************************************************************************/
#endif /* CTK_RELEASE_TO_USE >= 3.50 */


/******************************************************************************
`Proc PLCC_read_IO_override_status
` See ctkPlcFunc.h for a description of this function.
*******************************************************************************/
T_INT32  PLCC_read_IO_override_status
		     (struct read_IO_override_status_rec *pReadIoOverrideStatusRec)
{
    T_INT32 status = GEF_PWR_FLOW;
    return status;
}

/*******************************************************************************/

/******************************************************************************
`Proc PLCC_set_run_enable
` See ctkPlcFunc.h for a description of this function.
*******************************************************************************/
T_INT32  PLCC_set_run_enable(struct set_run_enable_rec *pSetRunEnableRec)
{
    T_INT32 status = GEF_PWR_FLOW;
    return status;
}

/*******************************************************************************/

/******************************************************************************
`Proc PLCC_mask_timed_interrupts
` See ctkPlcFunc.h for a description of this function.
*******************************************************************************/
T_INT32  PLCC_mask_timed_interrupts
	(struct mask_timed_interrupts_rec *pMaskTimedInterruptsRec)
{
    T_INT32 status = GEF_PWR_FLOW;
    return status;
}

/*******************************************************************************/

/******************************************************************************
`Proc PLCC_sus_res_HSC_interrupts
` See ctkPlcFunc.h for a description of this function.
*******************************************************************************/
T_INT32  PLCC_sus_res_HSC_interrupts
		     (struct sus_res_HSC_interrupts_rec *pSusResHscInterruptsRec)
{
    T_INT32 status = GEF_PWR_FLOW;
    return status;
}

/*******************************************************************************/


#if (CTK_RELEASE_TO_USE >= 0x0350) /* only supported when compiling for
                                      version 3.5 or higher */
/******************************************************************************
`Proc  PLCC_sus_res_interrupts_ext
` See ctkPlcFunc.h for a description of this function.
*******************************************************************************/
T_INT32  PLCC_sus_res_interrupts_ext(
                     struct sus_res_interrupts_ext_rec *pSusResInterruptsExtRec)
{
    T_INT32 status = GEF_PWR_FLOW;
    return status;
}

/*******************************************************************************/
#endif /* CTK_RELEASE_TO_USE >= 3.50 */


/******************************************************************************
`Proc PLCC_get_escm_status
` See ctkPlcFunc.h for a description of this function.
*******************************************************************************/
extern T_INT32   PLCC_get_escm_status (struct escm_status_rec *pEscmStatusRec)
{
    T_INT32 status = GEF_PWR_FLOW;
    return status;
}

/*******************************************************************************/
/* End of SVCREQ functions.                                                    */
/*******************************************************************************/

/******************************************************************************
`Proc PLCC_comm_req
` See ctkPlcFunc.h for a description of this function.
*******************************************************************************/
T_INT32  PLCC_comm_req(struct comm_req_rec *pCommReqRec)
{
    T_INT32 status = GEF_PWR_FLOW;
    return status;
}

/*******************************************************************************/

/******************************************************************************
`Proc PLCC_comm_req_extended
` See ctkPlcFunc.h for a description of this function.
*******************************************************************************/
T_INT32  PLCC_comm_req_extended(struct comm_req_rec_extended *pCommReqExtendedRec)
{
    T_INT32 status = GEF_PWR_FLOW;
    return status;
}


/******************************************************************************
`Proc PLCC_do_io
` See ctkPlcFunc.h for a description of this function.
*******************************************************************************/
T_INT32  PLCC_do_io(struct do_io_rec *pDoIoRec)
{
    T_INT32 status = GEF_PWR_FLOW;
    return status;
}

/*******************************************************************************/


#if (CTK_RELEASE_TO_USE >= 0x0350) /* only supported when compiling for
                                      version 3.5 or higher */
/******************************************************************************
`Proc PLCC_do_io_ext
` See ctkPlcFunc.h for a description of this function.
*******************************************************************************/
T_INT32  PLCC_do_io_ext(struct do_io_ext_rec *pDoIoExtRec)
{
    T_INT32 status = GEF_PWR_FLOW;
    return status;
}

/*******************************************************************************/
#endif /* CTK_RELEASE_TO_USE >= 3.50 */

#if (CTK_RELEASE_TO_USE >= 0x0500) /* only supported when compiling for
                                      version 5.0 or higher */
/******************************************************************************
`Proc PLCC_scan_set_io
` See ctkPlcFunc.h for a description of this function.
*******************************************************************************/
T_INT32  PLCC_scan_set_io(struct scan_set_io_rec *pScanSetIo)
{
    T_INT32 status = GEF_PWR_FLOW;
    return status;
}

/*******************************************************************************/
#endif /* CTK_RELEASE_TO_USE >= 5.00 */

/******************************************************************************
`Proc PLCC_sus_io
` See ctkPlcFunc.h for a description of this function.
*******************************************************************************/
T_INT32  PLCC_sus_io(void)
{
    T_INT32 status = GEF_PWR_FLOW;
    return status;
}

/*******************************************************************************/

/******************************************************************************
`Proc PLCC_SNP_ID
` See ctkPlcFunc.h for a description of this function.
*******************************************************************************/
T_INT32 PLCC_SNP_ID(T_BYTE request_type, char *id_str_ptr)
{
    T_INT32 status = GEF_NOT_SUPPORTED;
    return status;
}

/*******************************************************************************/

/******************************************************************************
`Proc PLCC_read_override
` See ctkPlcFunc.h for a description of this function.
*******************************************************************************/
T_INT32  PLCC_read_override(T_WORD tbl_typ, T_WORD ref_num, T_WORD len,
		     T_BYTE *data)
{
    T_INT32 status = GEF_OK;
    return status;
}
