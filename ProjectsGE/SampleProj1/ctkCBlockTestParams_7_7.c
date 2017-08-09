#include "copyright.h"
/*************************************************************************
 * Module $Id: ctkCBlockTestParams_7_7.c,v 1.10 2007/04/12 17:20:51 dej Exp $
 *************************************************************************/
/******************************************************************************
`ModuleName ctkBlockTestParams_7_7.c
` This file tests 7 input and 7 output parameters.
`
` Setup:   For this example, the C Block parameters in the programmer 
`          must be set up to use 7 input and 7 output parameters and
`          each parameter should be a Word type parameter.   
`
`          Note:  For the general case, input/output parameters
`          for the C Source file should match the type and size of the
`          C Block parameters declared in the programmer.  The C source 
`          input/output parameter types can be any of the following: 
`          T_BOOLEAN, T_INT16, T_WORD, T_INT32, T_DWORD, T_REAL32.  
`          These correspond to the following programmer types respectively:  
`          BOOL, INT, WORD, DINT, DWORD, REAL.
*******************************************************************************/
/* `IncludeFiles */
#include "PACRXPlc.h"
/* Constants / #defines  */
/* Structures and typedefs */

/* Declarations for Global variables */

/* Declarations for Local variables */

/* Routines */

int GefMain (T_WORD  *pCoolantTemp,       /* Input Param 1  */
             T_WORD  *pToolPosition,      /* Input Param 2  */
             T_WORD  *pChuckType,         /* Input Param 3  */
             T_WORD  *pHeadstockPos,      /* Input Param 4  */
             T_WORD  *pTailstockPos,      /* Input Param 5  */
             T_WORD  *pPrimaryTurretIndx, /* Input Param 6  */
             T_WORD  *pBackupTurretIndx,  /* Input Param 7  */
             T_WORD  *pNewPrimTurretIndx, /* Output Param 1 */
             T_WORD  *pNewTailstockPos,   /* Output Param 2 */
             T_WORD  *pNewHeadstockPos,   /* Output Param 3 */
             T_WORD  *pChuckLights,       /* Output Param 4 */
             T_WORD  *pSpindleSpeed,      /* Output Param 5 */
             T_WORD  *pNewToolPosition,   /* Output Param 6 */
             T_WORD  *pNewCoolantTemp)    /* Output Param 7 */

{
    *pNewPrimTurretIndx =  *pCoolantTemp;
    *pNewTailstockPos =    *pToolPosition;
    *pNewHeadstockPos =    *pChuckType;
    *pChuckLights =        *pHeadstockPos;
    *pSpindleSpeed =       *pTailstockPos;
    *pNewToolPosition =    *pPrimaryTurretIndx;
    *pNewCoolantTemp =     *pBackupTurretIndx;

    if (*pCoolantTemp > 1000)
    {
        return GEF_EXECUTION_ERROR;
    }
    return GEF_EXECUTION_OK;   /* Execution OK */
}        