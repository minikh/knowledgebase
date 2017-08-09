#include "copyright.h"
/*************************************************************************
 * Module $Id: ctkCBlockTestDriver.c,v 1.5 2003/11/17 22:34:22 cashb1 Exp $
 *************************************************************************/
/******************************************************************************
`ModuleName ctkCBlockTestDriver.c
` This file provides a an entry point when debugging a C Block on the 
` PC.  The entry point function (main) initializes memory and then
` calls the C Blocks GefMain function. 
*******************************************************************************/
/* `IncludeFiles */
#include "ctkInitCBlock.h"
#include "PACRXPlc.h"  /* Include file applicable for all targets */
/* my C Block Driver code */
/* forward declaration */
int GefMain (T_WORD  *coolantTemp,       /* Input Param 1  */
             T_WORD  *toolPosition,      /* Input Param 2  */
             T_WORD  *chuckType,         /* Input Param 3  */
             T_WORD  *headstockPos,      /* Input Param 4  */
             T_WORD  *tailstockPos,      /* Input Param 5  */
             T_WORD  *primaryTurretIndx, /* Input Param 6  */
             T_WORD  *backupTurretIndx,  /* Input Param 7  */
             T_WORD  *newPrimTurretIndx, /* Output Param 1 */
             T_WORD  *newTailstockPos,   /* Output Param 2 */
             T_WORD  *newHeadstockPos,   /* Output Param 3 */
             T_WORD  *chuckLights,       /* Output Param 4 */
             T_WORD  *spindleSpeed,      /* Output Param 5 */
             T_WORD  *newToolPosition,   /* Output Param 6 */
             T_WORD  *newCoolantTemp);    /* Output Param 7 */

int main(int argc, char *argv[])
{

    T_WORD  coolantTemp = 0;       /* Input Param 1  */
    T_WORD  toolPosition = 0;      /* Input Param 2  */
    T_WORD  chuckType = 0;         /* Input Param 3  */
    T_WORD  headstockPos = 0;      /* Input Param 4  */
    T_WORD  tailstockPos = 0;      /* Input Param 5  */
    T_WORD  primaryTurretIndx = 0; /* Input Param 6  */
    T_WORD  backupTurretIndx = 0;  /* Input Param 7  */
    T_WORD  newPrimTurretIndx = 0; /* Output Param 1 */
    T_WORD  newTailstockPos = 0;   /* Output Param 2 */
    T_WORD  newHeadstockPos = 0;   /* Output Param 3 */
    T_WORD  chuckLights = 0;       /* Output Param 4 */
    T_WORD  spindleSpeed = 0;      /* Output Param 5 */
    T_WORD  newToolPosition = 0;   /* Output Param 6 */
    T_WORD  newCoolantTemp = 0;    /* Output Param 7 */
    initCBlock(); /* creates reference memory and initializes pointers to that memory*/

    return GefMain(&coolantTemp,       /* Input Param 1  */
             &toolPosition,      /* Input Param 2  */
             &chuckType,         /* Input Param 3  */
             &headstockPos,      /* Input Param 4  */
             &tailstockPos,      /* Input Param 5  */
             &primaryTurretIndx, /* Input Param 6  */
             &backupTurretIndx,  /* Input Param 7  */
             &newPrimTurretIndx, /* Output Param 1 */
             &newTailstockPos,   /* Output Param 2 */
             &newHeadstockPos,   /* Output Param 3 */
             &chuckLights,       /* Output Param 4 */
             &spindleSpeed,      /* Output Param 5 */
             &newToolPosition,   /* Output Param 6 */
             &newCoolantTemp);    /* Output Param 7 */
}
/* end of my C Block Driver code */
