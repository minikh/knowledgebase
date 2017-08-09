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
/*********************************************************************************
 * Module $Id: ctkPlcBus.c,v 1.4 2010/08/05 14:27:48 mummids1 Exp $
 ********************************************************************************/
/******************************************************************************
`ModuleName ctkPlcBus.c
` This include file contains stub implementations of 
` PLC Bus Read/Write functions which are used for debugging on the PC.
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
`Proc PLCC_BUS_read_byte
` See ctkPlcBus.h for a description of this function.
*******************************************************************************/
T_INT32 PLCC_BUS_read_byte(T_WORD rack, T_WORD slot, T_WORD subSlot, T_WORD region, 
                          T_WORD *pStatus, T_BYTE *value, T_DWORD address)
{
    T_INT32 status = TRUE;
    return status;
}

/*******************************************************************************/

/******************************************************************************
`Proc PLCC_BUS_read_word
` See ctkPlcBus.h for a description of this function.
*******************************************************************************/
T_INT32 PLCC_BUS_read_word(T_WORD rack, T_WORD slot, T_WORD subSlot, T_WORD region, 
                          T_WORD *pStatus, T_WORD *value, T_DWORD address)
{
    T_INT32 status = TRUE;
    return status;
}

/*******************************************************************************/

/******************************************************************************
`Proc PLCC_BUS_read_dword
` See ctkPlcBus.h for a description of this function.
*******************************************************************************/
T_INT32 PLCC_BUS_read_dword(T_WORD rack, T_WORD slot, T_WORD subSlot, T_WORD region, 
                           T_WORD *pStatus, T_DWORD *value, T_DWORD address)
{
    T_INT32 status = TRUE;
    return status;
}

/*******************************************************************************/

/******************************************************************************
`Proc PLCC_BUS_read_block
` See ctkPlcBus.h for a description of this function.
*******************************************************************************/
T_INT32 PLCC_BUS_read_block(T_WORD rack, T_WORD slot, T_WORD subSlot, T_WORD region, 
                           T_WORD *pStatus, void *buffer, T_WORD length, T_DWORD address)
{
    T_INT32 status = TRUE;
    return status;
}

/*******************************************************************************/

/******************************************************************************
`Proc PLCC_BUS_write_byte
` See ctkPlcBus.h for a description of this function.
*******************************************************************************/

T_INT32 PLCC_BUS_write_byte(T_WORD rack, T_WORD slot, T_WORD subSlot, T_WORD region, 
                           T_WORD *pStatus, T_BYTE value, T_DWORD address)
{
    T_INT32 status = TRUE;
    return status;
}

/*******************************************************************************/

/******************************************************************************
`Proc PLCC_BUS_write_word
` See ctkPlcBus.h for a description of this function.
*******************************************************************************/
T_INT32 PLCC_BUS_write_word(T_WORD rack, T_WORD slot, T_WORD subSlot, T_WORD region, 
                           T_WORD *pStatus, T_WORD value, T_DWORD address)
{
    T_INT32 status = TRUE;
    return status;
}

/*******************************************************************************/

/******************************************************************************
`Proc PLCC_BUS_write_dword
` See ctkPlcBus.h for a description of this function.
*******************************************************************************/
T_INT32 PLCC_BUS_write_dword(T_WORD rack, T_WORD slot, T_WORD subSlot, T_WORD region, 
                            T_WORD *pStatus, T_DWORD value, T_DWORD address)
{
    T_INT32 status = TRUE;
    return status;
}

/*******************************************************************************/

/******************************************************************************
`Proc PLCC_BUS_write_block
` See ctkPlcBus.h for a description of this function.
*******************************************************************************/

T_INT32 PLCC_BUS_write_block(T_WORD rack, T_WORD slot, T_WORD subSlot, T_WORD region, 
                            T_WORD *pStatus, void *buffer, T_WORD length, T_DWORD address)
{
    T_INT32 status = TRUE;
    return status;
}

/*******************************************************************************/

/******************************************************************************
`Proc PLCC_BUS_RMW_byte
` See ctkPlcBus.h for a description of this function.
*******************************************************************************/
T_INT32 PLCC_BUS_RMW_byte(T_WORD rack, T_WORD slot, T_WORD subSlot, T_WORD region, 
                          T_WORD *pStatus, T_BYTE *pOriginalValue, 
                          T_WORD op_type, T_DWORD mask, T_DWORD address)
{
    T_INT32 status = TRUE;
    return status;
}

/*******************************************************************************/

/******************************************************************************
`Proc PLCC_BUS_RMW_word
` See ctkPlcBus.h for a description of this function.
*******************************************************************************/
T_INT32 PLCC_BUS_RMW_word(T_WORD rack, T_WORD slot, T_WORD subSlot, T_WORD region, 
                          T_WORD *pStatus, T_WORD *pOriginalValue, 
                          T_WORD op_type, T_DWORD mask, T_DWORD address)
{
    T_INT32 status = TRUE;
    return status;
}

/*******************************************************************************/

/******************************************************************************
`Proc PLCC_BUS_RMW_dword
` See ctkPlcBus.h for a description of this function.
*******************************************************************************/
T_INT32 PLCC_BUS_RMW_dword(T_WORD rack, T_WORD slot, T_WORD subSlot, T_WORD region, 
                           T_WORD *pStatus, T_DWORD *pOriginalValue,
                           T_WORD op_type, T_DWORD mask, T_DWORD address)
{
    T_INT32 status = TRUE;
    return status;
}

/*******************************************************************************/

/******************************************************************************
`Proc PLCC_BUS_TST_byte
` See ctkPlcBus.h for a description of this function.
*******************************************************************************/
T_INT32 PLCC_BUS_TST_byte(T_WORD rack, T_WORD slot, T_WORD subSlot, T_WORD region, 
                          T_WORD *pStatus, T_BYTE *semaphore_output, T_DWORD address)
{
    T_INT32 status = TRUE;
    return status;
}

/*******************************************************************************/

/******************************************************************************
`Proc PLCC_BUS_TST_word
` See ctkPlcBus.h for a description of this function.
*******************************************************************************/
T_INT32 PLCC_BUS_TST_word(T_WORD rack, T_WORD slot, T_WORD subSlot, T_WORD region, 
                          T_WORD *pStatus, T_WORD *semaphore_output, T_DWORD address)
{
    T_INT32 status = TRUE;
    return status;
}

/*******************************************************************************/

