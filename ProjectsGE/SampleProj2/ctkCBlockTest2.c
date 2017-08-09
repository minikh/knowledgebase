#include "copyright.h"
/*************************************************************************
 * Module $Id: ctkCBlockTest2.c,v 1.6 2003/11/17 22:18:50 cashb1 Exp $
 *************************************************************************/
/******************************************************************************
`ModuleName ctkCBlockTest2.c
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

/* Declarations for Local variables */
/* Forward declarations */
void ctkCBlockTest3(void);

/* Routines */
void ctkCBlockTest2(void)
{
    T_DWORD resultDword;
    char buffer[100];
    T_INT32 numBytes = 0;

    numBytes = sprintf(buffer, "Plc Fault Functions \r\n");
    PLCC_MessageWrite(PORT1, buffer, numBytes);

    /* PLC Errno functions */
    resultDword = PLCC_GetErrno();
    PLCC_ClearErrno();

    numBytes = sprintf(buffer, "calling ctkCBlockTest3 \r\n");
    PLCC_MessageWrite(PORT1, buffer, numBytes);

    ctkCBlockTest3();

}









