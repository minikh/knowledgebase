#include "copyright.h"
/*************************************************************************
 * Module $Id: ctkCBlockTest5.c,v 1.7 2003/11/17 22:20:27 cashb1 Exp $
 *************************************************************************/
/******************************************************************************
`ModuleName ctkCBlockTest5.c
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
void ctkCBlockTest6(void);

/* Routines */
void ctkCBlockTest5(void)
{
    T_INT32 resultInt32;
    T_WORD resultWord;
    T_BYTE checksumArea[100] = {0};
    T_DWORD length = 5;
    T_WORD currentCrcValue = 0;
    T_BYTE resultByte;
    T_BYTE rack=1;
    T_BYTE slot=5;
    T_WORD subSlot = 0;
    T_WORD region = 1;
    T_BYTE valueByte;
    T_DWORD address=1;
    T_WORD valueWord = 0x5555;
    T_DWORD valueDword = 0xaaaa;
    T_BYTE buffer1[100];
    T_BYTE op_type;
    T_BYTE mask;
    T_BYTE semaphore_output_byte;
    T_WORD semaphore_output_word;
    T_WORD busStatus = 0;
    T_BYTE originalValueByte =0;
    T_WORD originalValueWord =0;
    T_DWORD originalValueDword =0;
    char buffer[100];
    T_INT32 numBytes = 0;

    numBytes = sprintf(buffer, "Plc Utility Functions \r\n");
    PLCC_MessageWrite(PORT1, buffer, numBytes);

    /* Plc Utility Functions */
    resultWord = PLCC_Crc16Checksum(checksumArea, length, currentCrcValue);

    numBytes = sprintf(buffer, "Plc Bus Read/Write Functions \r\n");
    PLCC_MessageWrite(PORT1, buffer, numBytes);

    /* Plc Bus Read/Write Functions */
    resultByte =   PLCC_BUS_read_byte(rack, slot, subSlot, region, &busStatus, &valueByte, address);
    resultByte =   PLCC_BUS_read_word(rack, slot, subSlot, region,&busStatus, &valueWord, address);
    resultByte =   PLCC_BUS_read_dword(rack, slot, subSlot, region,&busStatus, &valueDword, address);
    resultByte =   PLCC_BUS_read_block(rack, slot, subSlot, region, &busStatus, buffer1, sizeof(buffer1), address);
    resultByte =   PLCC_BUS_write_byte(rack, slot, subSlot, region,&busStatus, valueByte, address);
    resultByte =   PLCC_BUS_write_word(rack, slot, subSlot, region, &busStatus, valueWord, address);
    resultByte =   PLCC_BUS_write_dword(rack, slot, subSlot, region, &busStatus, valueDword, address);
    resultByte =   PLCC_BUS_write_block(rack, slot, subSlot, region, &busStatus, buffer1, sizeof(buffer1), address);
    resultInt32 =   PLCC_BUS_RMW_byte(rack, slot, subSlot, region, &busStatus, &originalValueByte, op_type, mask, address);
    resultInt32 =   PLCC_BUS_RMW_word(rack, slot, subSlot, region,&busStatus, &originalValueWord, op_type, mask, address);
    resultInt32 =   PLCC_BUS_RMW_dword(rack, slot, subSlot, region, &busStatus, &originalValueDword, op_type, mask, address);
    resultInt32 =   PLCC_BUS_TST_byte(rack, slot, subSlot, region, &busStatus, &semaphore_output_byte, address);
    resultInt32 =   PLCC_BUS_TST_word(rack, slot, subSlot, region,&busStatus, &semaphore_output_word, address);

    numBytes = sprintf(buffer, "calling ctkCBlockTest6 \r\n");
    PLCC_MessageWrite(PORT1, buffer, numBytes);

    ctkCBlockTest6();
}









