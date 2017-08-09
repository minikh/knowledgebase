/*************************************************************************
*    This computer program contains confidential and proprietary         *
*    information of GE Intelligent Platforms, Inc. Neither the program 	 *
*    nor the information contained therein may be copied or disclosed 	 *
*    to any third party without the prior written approval of 			 *
*    GE Intelligent Platforms. Unauthorized use of the information 		 *
*    or program is strictly prohibited.                      			 *
*                                                                        *
*    Copyright (c) 2001 - 2010 GE INTELLIGENT PLATFORMS, INC.		 	 *
*      Published in only limited, copyright sense and all rights,        *
*      including trade secret rights, are reserved.  Unauthorized        *
*      use of the information or program is strictly prohibited.         *
*                                                                        *
*    All Rights Reserved.                                                *
*************************************************************************/
/*************************************************************************
 * Module $Id: ctkPlcFault.c,v 1.5 2010/08/05 14:27:48 mummids1 Exp $
 *************************************************************************/
/******************************************************************************
`ModuleName ctkPlcFault.c
` This file contains stub implementations of  
` the PLC fault table functions which are used for debugging on the PC.
`
*******************************************************************************/
/* IncludeFiles */
#include "ctkPlc.h"

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
`Proc PLCC_clear_fault_tables
` See ctkPlcFault.h for a description of this function.
*******************************************************************************/
T_INT32  PLCC_clear_fault_tables(struct clear_fault_tables_rec *x)
{
    T_INT32 status = GEF_PWR_FLOW;
    return status;
}

/*******************************************************************************/

/******************************************************************************
`Proc PLCC_read_last_fault
` See ctkPlcFault.h for a description of this function.
*******************************************************************************/
T_INT32  PLCC_read_last_fault(struct read_last_fault_rec *x)
{
    T_INT32 status = GEF_PWR_FLOW;
    return status;
}

/*******************************************************************************/

/******************************************************************************
`Proc PLCC_read_last_ext_fault
` See ctkPlcFault.h for a description of this function.
*******************************************************************************/
T_INT32  PLCC_read_last_ext_fault(struct read_last_ext_fault_rec *x)
{
    T_INT32 status = GEF_PWR_FLOW;
    return status;
}

/*******************************************************************************/

/******************************************************************************
`Proc PLCC_read_fault_tables
` See ctkPlcFault.h for a description of this function.
*******************************************************************************/
T_INT32  PLCC_read_fault_tables(struct read_fault_tables_rec *x)
{
    T_INT32 status = GEF_PWR_FLOW;
    return status;
}

/*******************************************************************************/

/******************************************************************************
`Proc PLCC_read_ext_fault_tables
` See ctkPlcFault.h for a description of this function.
*******************************************************************************/
T_INT32  PLCC_read_ext_fault_tables(struct read_ext_fault_tables_rec *x)
{
    T_INT32 status = GEF_PWR_FLOW;
    return status;
}

/*******************************************************************************/
