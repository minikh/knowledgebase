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
 * Module $Id: ctkVariables.c,v 1.6 2003/05/30 20:49:14 dsc Exp $
 *************************************************************************/
/******************************************************************************
`ModuleName ctkVariables.c
` This file contains stub implementations of  
` the PLC variable access functions which are used for debugging on the PC.
`
******************************************************************************/
/* IncludeFiles */
#include "ctkReleaseToUse.h"      /* Passes release number, used for three
                                     build environments - PLC firmware build
                                     C tool kit configuration build, and C
                                     Tool kit end user build.
                                  */
#include <string.h>
#include "ctkPlc.h"
#include "ctkInitCBlock.h"
/* Constants and Enumerations */
/* Type and Structure Definitions */
/* Global variables */


/* EXAMPLE FOR DEBUGGING WHEN USING PLC VARIABLES:

   The following example shows how to implement a simulation for debugging:

   For a PLC WORD variable declared as:

   PLC_VAR(valvePositionRec, "valvePosition");

   Declare a global variable in this file:

   PLC_VAR_WORD valvePosition;

   In the stub routines, use the following syntax:

   if (pVarInfo == &valvePositionRec)
   {
       valvePostion = *((T_WORD *)pWriteFrom); -- Whatever operation is needed
   }
*/

/* Routines */
#if (CTK_RELEASE_TO_USE >= 0x0350) /* only supported when compiling for
                                      version 3.5 or higher */


/******************************************************************************
`Proc ReadPlcVar
` See ctkVariables.h for a description of these functions.
******************************************************************************/
T_INT32 ReadPlcVar(PLC_VAR_REC *pVarInfo, void *pReadTo)
{
    T_INT32 status = GEF_OK;

    /* add variables here - see example at top of file
    if (pVarInfo == &myVarRec)
    {
        *pReadTo = myVar;
    }
    */

    return status;
}
/*****************************************************************************/


/******************************************************************************
`Proc ReadPlcArrayVarElement
` See ctkVariables.h for a description of these functions.
******************************************************************************/
T_INT32 ReadPlcArrayVarElement(PLC_VAR_REC *pVarInfo, 
                               void *pReadTo,
                               T_INT32 numIndicies,
                               ...)
{
    T_INT32 status = GEF_OK;

    /* add variables here - see example at top of file
    if (pVarInfo == &myVarRec)
    {
        *pReadTo = myVar;
    }
    */

    return status;
}
/*****************************************************************************/


/******************************************************************************
`Proc ReadPlcVarDiag
` See ctkVariables.h for a description of these functions.
******************************************************************************/
T_INT32 ReadPlcVarDiag(PLC_VAR_REC *pVarInfo, void *pReadDiagsTo)
{
    T_INT32 status = GEF_OK;

    /* add variables here - see example at top of file
    if (pVarInfo == &myVarRec)
    {
        *pReadDiagsTo = myVar;
    }
    */

    return status;
}
/*****************************************************************************/


/******************************************************************************
`Proc ReadPlcArrayVarElementDiag
` See ctkVariables.h for a description of these functions.
******************************************************************************/
T_INT32 ReadPlcArrayVarElementDiag(PLC_VAR_REC *pVarInfo, 
                                   void *pReadDiagsTo,
                                   T_INT32 numIndicies,
                                   ...)
{
    T_INT32 status = GEF_OK;

    /* add variables here - see example at top of file
    if (pVarInfo == &myVarRec)
    {
        *pReadDiagsTo = myVar;
    }
    */

    return status;
}
/*****************************************************************************/


/******************************************************************************
`Proc ReadPlcVarOvr
` See ctkVariables.h for a description of these functions.
******************************************************************************/
T_INT32 ReadPlcVarOvr(PLC_VAR_REC *pVarInfo, void *pReadOvrTo)
{
    T_INT32 status = GEF_OK;

    /* add variables here - see example at top of file
    if (pVarInfo == &myVarRec)
    {
        *pReadOvrTo = myVar;
    }
    */

    return status;
}
/*****************************************************************************/


/******************************************************************************
`Proc ReadPlcArrayVarElementOvr
` See ctkVariables.h for a description of these functions.
******************************************************************************/
T_INT32 ReadPlcArrayVarElementOvr(PLC_VAR_REC *pVarInfo, 
                                  void *pReadOvrTo,
                                  T_INT32 numIndicies,
                                  ...)
{
    T_INT32 status = GEF_OK;

    /* add variables here - see example at top of file
    if (pVarInfo == &myVarRec)
    {
        *pReadOvrTo = myVar;
    }
    */

    return status;
}
/*****************************************************************************/


/******************************************************************************
`Proc ReadPlcVarTrans
` See ctkVariables.h for a description of these functions.
******************************************************************************/
T_INT32 ReadPlcVarTrans(PLC_VAR_REC *pVarInfo, void *pReadTransTo)
{
    T_INT32 status = GEF_OK;

    /* add variables here - see example at top of file
    if (pVarInfo == &myVarRec)
    {
        *pReadTransTo = myVar;
    }
    */

    return status;
}
/*****************************************************************************/


/******************************************************************************
`Proc ReadPlcArrayVarElementTrans
` See ctkVariables.h for a description of these functions.
******************************************************************************/
T_INT32 ReadPlcArrayVarElementTrans(PLC_VAR_REC *pVarInfo, 
                                    void *pReadTransTo,
                                    T_INT32 numIndicies,
                                    ...)
{
    T_INT32 status = GEF_OK;

    /* add variables here - see example at top of file
    if (pVarInfo == &myVarRec)
    {
        *pReadTransTo = myVar;
    }
    */

    return status;
}
/*****************************************************************************/


/******************************************************************************
`Proc WritePlcVar
` See ctkVariables.h for a description of these functions.
******************************************************************************/
T_INT32 WritePlcVar(PLC_VAR_REC *pVarInfo, void *pWriteFrom)
{
    T_INT32 status = GEF_OK;

    /* add variables here - see example at top of file
    if (pVarInfo == &myVarRec)
    {
        myVar = *pWriteFrom;
    }
    */

    return status;
}
/*****************************************************************************/


/******************************************************************************
`Proc WritePlcArrayVarElement
` See ctkVariables.h for a description of these functions.
******************************************************************************/
T_INT32 WritePlcArrayVarElement(PLC_VAR_REC *pVarInfo, 
                                void *pWriteFrom,
                                T_INT32 numIndicies,
                                ...)
{
    T_INT32 status = GEF_OK;

    /* add variables here - see example at top of file
    if (pVarInfo == &myVarRec)
    {
        myVar = *pWriteFrom;
    }
    */

    return status;
}
/*****************************************************************************/


/******************************************************************************
`Proc PlcVarMemCopy
` See ctkVariables.h for a description of these functions.
******************************************************************************/
T_INT32 PlcVarMemCopy(PLC_VAR_REC *pDestVarInfo, 
                      PLC_VAR_REC *pSrcVarInfo)
{
    T_INT32 status = GEF_OK;

    /* add variables here - see example at top of file
    if (pDestVarInfo == &myVarRec)
    {
        myVar = 5;
    }
    */

    return status;
}
/*****************************************************************************/


/******************************************************************************
`Proc PlcVarType
` See ctkVariables.h for a description of these functions.
******************************************************************************/
T_DWORD PlcVarType(PLC_VAR_REC *pVarInfo)
{
    T_DWORD varType = PLC_INVALID_VAR_TYPE;

    /* add variables here - see example at top of file
    if (pVarInfo == &myVarRec)
    {
        varType = PLC_BOOL_VAR_TYPE;
    }
    */

    return varType;
}
/*****************************************************************************/


/******************************************************************************
`Proc PlcVarSizeof
` See ctkVariables.h for a description of these functions.
******************************************************************************/
T_DWORD PlcVarSizeof(PLC_VAR_REC *pVarInfo)
{
    T_DWORD varSize = 0;

    /* add variables here - see example at top of file
    if (pVarInfo == &myVarRec)
    {
        varSize = sizeof(PLC_VAR_WORD);
    }
    */

    return varSize;
}
/*****************************************************************************/


/******************************************************************************
`Proc PlcVarSizeofDiag
` See ctkVariables.h for a description of these functions.
******************************************************************************/
T_DWORD PlcVarSizeofDiag(PLC_VAR_REC *pVarInfo)
{
    T_DWORD diagSize = 0;

    /* add variables here - see example at top of file
    if (pVarInfo == &myVarRec)
    {
        diagSize = sizeof(PLC_VAR_WORD) / 2;
    }
    */

    return diagSize;
}
/*****************************************************************************/


/******************************************************************************
`Proc PlcVarSizeofOvr
` See ctkVariables.h for a description of these functions.
******************************************************************************/
T_DWORD PlcVarSizeofOvr(PLC_VAR_REC *pVarInfo)
{
    T_DWORD ovrSize = 0;

    /* add variables here - see example at top of file
    if (pVarInfo == &myVarRec)
    {
        ovrSize = sizeof(PLC_VAR_WORD);
    }
    */

    return ovrSize;
}
/*****************************************************************************/


/******************************************************************************
`Proc PlcVarSizeofTrans
` See ctkVariables.h for a description of these functions.
******************************************************************************/
T_DWORD PlcVarSizeofTrans(PLC_VAR_REC *pVarInfo)
{
    T_DWORD transSize = 0;

    /* add variables here - see example at top of file
    if (pVarInfo == &myVarRec)
    {
        transSize = sizeof(PLC_VAR_WORD);
    }
    */

    return transSize;
}
/*****************************************************************************/


/******************************************************************************
`Proc PlcVarNumDimensions
` See ctkVariables.h for a description of these functions.
******************************************************************************/
T_DWORD PlcVarNumDimensions(PLC_VAR_REC *pVarInfo)
{
    T_DWORD numDimensions = 0;

    /* add variables here - see example at top of file
    if (pVarInfo == &myVarRec)
    {
        numDimensions = 2;
    }
    */

    return numDimensions;
}
/*****************************************************************************/


/******************************************************************************
`Proc PlcVarHasDiags
` See ctkVariables.h for a description of these functions.
******************************************************************************/
T_BOOLEAN PlcVarHasDiags(PLC_VAR_REC *pVarInfo)
{
    T_BOOLEAN hasDiags = FALSE;

    /* add variables here - see example at top of file
    if (pVarInfo == &myVarRec)
    {
        hasDiags = TRUE;
    }
    */

    return hasDiags;
}
/*****************************************************************************/


/******************************************************************************
`Proc PlcVarHasOverrides
` See ctkVariables.h for a description of these functions.
******************************************************************************/
T_BOOLEAN PlcVarHasOverrides(PLC_VAR_REC *pVarInfo)
{
    T_BOOLEAN hasOverrides = FALSE;

    /* add variables here - see example at top of file
    if (pVarInfo == &myVarRec)
    {
        hasOverrides = TRUE;
    }
    */

    return hasOverrides;
}
/*****************************************************************************/


/******************************************************************************
`Proc PlcVarHasTransitions
` See ctkVariables.h for a description of these functions.
******************************************************************************/
T_BOOLEAN PlcVarHasTransitions(PLC_VAR_REC *pVarInfo)
{
    T_BOOLEAN hasTransitions = FALSE;

    /* add variables here - see example at top of file
    if (pVarInfo == &myVarRec)
    {
        hasTransitions = TRUE;
    }
    */

    return hasTransitions;
}
/*****************************************************************************/


/******************************************************************************
`Proc PlcVarArrayElementSize
` See ctkVariables.h for a description of these functions.
******************************************************************************/
T_DWORD PlcVarArrayElementSize(PLC_VAR_REC *pVarInfo)
{
    T_DWORD varSize = 0;

    /* add variables here - see example at top of file
    if (pVarInfo == &myVarRec)
    {
        varSize = sizeof(PLC_VAR_WORD);
    }
    */

    return varSize;
}
/*****************************************************************************/


/******************************************************************************
`Proc PlcVarArrayBound
` See ctkVariables.h for a description of these functions.
******************************************************************************/
T_DWORD PlcVarArrayBound(PLC_VAR_REC *pVarInfo, T_DWORD dimension)
{
    T_DWORD arrayBound = 0;

    /* add variables here - see example at top of file
    if (pVarInfo == &myVarRec)
    {
        if (dimension == 1)
            arrayBound = 5;
        else if (dimension == 2)
            arrayBound = 2;
    }
    */

    return arrayBound;
}
/*****************************************************************************/

#endif /* CTK_RELEASE_TO_USE >= 3.50 */
