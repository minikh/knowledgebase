#include "copyright.h"
/*************************************************************************
 * Module $Id: ctkCBlockTest3.c,v 1.6 2003/11/17 22:19:32 cashb1 Exp $
 *************************************************************************/
/******************************************************************************
`ModuleName ctkCBlockTest3.c
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
#define MY_EXT_PLC_FAULT_TABLE_SIZE 64
#define MY_EXT_IO_FAULT_TABLE_SIZE 64
/* Structures and typedefs */
/* Because the extended fault table structure is intended to support
   various number of fault entries, the user must create their own
   extended fault table structure with the same elements as 
   struct read_ext_fault_tables_rec but with the PLC_faults or 
   IO_Faults members dimensioned to equal the maximum number of
   faults the user wants to read from the fault table.  
   An example is shown below where the maximum number of PLC or IO fault
   table entries to be read from the PLC or IO fault table is determined
   by the definitions MY_EXT_PLC_FAULT_TABLE_SIZE & MY_EXT_IO_FAULT_TABLE_SIZE 
   respectively.   
   
   Note:  this structure must be packed using the
   #pragma pack(1) before the start of the structure definition and 
   the #pragma pack() directive at the end of the structure definition.
   
   When calling the PLCC_read_ext_fault_tables, the address of this
   variable is passed to the function and is cast to a "struct read_ext_fault_tables_rec"
   pointer to avoid getting a compiler warning (see example below).   */

#pragma pack(1)
struct my_read_ext_fault_tables_rec 
{
   T_WORD table; /* PLC_EXT_FAULT_TABLE or IO_EXT_FAULT_TABLE */
   T_WORD start_index;
   T_WORD number_of_entries_to_read;
   T_WORD reserved[12];
   struct time_stamp_rec time_since_clear;
   T_WORD num_faults_since_clear;
   T_WORD num_faults_in_queue;
   T_WORD num_faults_read;
   T_WORD PlcName[16];
   union
   {
      struct PLC_ext_fault_entry_rec PLC_faults[MY_EXT_PLC_FAULT_TABLE_SIZE];
      struct IO_ext_fault_entry_rec IO_faults[MY_EXT_IO_FAULT_TABLE_SIZE];
   } faultEntry;
};
#pragma pack()

/* Declarations for Global variables */

/* Declarations for Local variables */
/* Forward declarations */
void ctkCBlockTest4(void);

/* Routines */
void ctkCBlockTest3(void)
{
    T_INT32 resultInt32;
    struct clear_fault_tables_rec clearFaultTablesRec;
    struct read_last_fault_rec readLastFaultRec;
    struct read_last_ext_fault_rec readLastExtFaultRec;
    struct read_fault_tables_rec readFaultTablesRec;
    struct my_read_ext_fault_tables_rec readExtFaultTablesRec;
    char buffer[100];
    T_INT32 numBytes = 0;

    numBytes = sprintf(buffer, "Plc Fault Functions \r\n");
    PLCC_MessageWrite(PORT1, buffer, numBytes);

    /* Plc Fault Functions */
    clearFaultTablesRec.table = PLC_FAULT_TABLE;
    resultInt32 = PLCC_clear_fault_tables(&clearFaultTablesRec);

    readLastFaultRec.table = IO_FAULT_TABLE;
    resultInt32 = PLCC_read_last_fault(&readLastFaultRec);

    readLastExtFaultRec.table = PLC_EXT_FAULT_TABLE;
    resultInt32 = PLCC_read_last_ext_fault(&readLastExtFaultRec);

    readFaultTablesRec.table = IO_FAULT_TABLE;
    resultInt32 = PLCC_read_fault_tables(&readFaultTablesRec);

    readExtFaultTablesRec.table =  IO_EXT_FAULT_TABLE;
    readExtFaultTablesRec.start_index = 0; /* start at the first entry */
    readExtFaultTablesRec.number_of_entries_to_read = MY_EXT_IO_FAULT_TABLE_SIZE; /* read up to the maximum size */
    resultInt32 = PLCC_read_ext_fault_tables((struct read_ext_fault_tables_rec*)&readExtFaultTablesRec);


    numBytes = sprintf(buffer, "calling ctkCBlockTest4 \r\n");
    PLCC_MessageWrite(PORT1, buffer, numBytes);

    ctkCBlockTest4();
}









