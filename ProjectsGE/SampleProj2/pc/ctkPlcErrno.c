/*************************************************************************
*    This computer program contains confidential and proprietary         *
*    information of GE Intelligent Platforms, Inc. Neither the program 	 *
*    nor the information contained therein may be copied or disclosed 	 *
*    to any third party without the prior written approval of 			 *
*    GE Intelligent Platforms. Unauthorized use of the information 		 *
*    or program is strictly prohibited.                      			 *
*                                                                        *
*    Copyright (c) 2001 - 2010 GE INTELLIGENT PLATFORMS, INC.   	 	 *
*      Published in only limited, copyright sense and all rights,        *
*      including trade secret rights, are reserved.  Unauthorized        *
*      use of the information or program is strictly prohibited.         *
*                                                                        *
*    All Rights Reserved.                                                *
*************************************************************************/
/*************************************************************************
 * Module $Id: ctkPlcErrno.c,v 1.4 2010/08/05 14:27:48 mummids1 Exp $
 *************************************************************************/
/******************************************************************************
`ModuleName ctkPlcErrno.c
` This include file contains stub implementations of Errno
` PLC function which is used for debugging on the PC.
`
*******************************************************************************/
/* IncludeFiles */
#include "ctkPlc.h"

/* Constants and Enumerations */
/* Type and Structure Definitions */
/* Global variables */
/* Local Variables */
/* Forward declarations */
/* Routines */
/******************************************************************************
`Proc PLCC_GetErrno
` See ctkPlcErrno.h for a description of this function.
*******************************************************************************/
int PLCC_GetErrno(void)
{
    T_INT32 status = GEF_OK;
    return status;
}
/*******************************************************************************/

/******************************************************************************
`Proc PLCC_ClearErrno
` See ctkPlcErrno.h for a description of this function.
*******************************************************************************/
void PLCC_ClearErrno(void)
{
}
/*******************************************************************************/
