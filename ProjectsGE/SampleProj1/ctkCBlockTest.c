#include "copyright.h"
/*************************************************************************
 * Module $Id: ctkCBlockTest.c,v 1.12 2006/09/27 15:12:00 cas Exp $
 *************************************************************************/
/******************************************************************************
`ModuleName ctkCBlockTest.c
` This file uses all C Run Time and Target Library functions supported
` by the C Toolkit to test that all the supported functions can
` be compiled.  This file does not necessarily demonstrate the correct setup 
` for each function call because its purpose is to show that each function 
` can be compiled, linked and executed. 

` 
` Setup:  Note Hardware configuration memory must be setup to use %W memory,
`         watchdog set to 2550ms, Point Fault References Enabled.  The program
`         must use %P in the Main and %L if a subblock calls this block.
*******************************************************************************/
/* `IncludeFiles */
#include "PACRXPlc.h"  /* Include file applicable for all targets */
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>
#include <float.h>
#include <limits.h>
/* Constants / #defines  */
#define STATUS_REG 1000
#define TEST_FUNCTION_CALLED 1
#define MATH_FUNCTIONS 2
#define STLIB_FUNCTIONS 3
#define STRING_FUNCTIONS 4
#define TIME_FUNCTIONS 5
#define CTYPE_FUNCTIONS 6
#define GEFCLIB_FUNCTIONS 7
#define PLC_ERRNO_FUNCTIONS 8
#define PLC_FAULT_FUNCTIONS 9
#define PLC_GENERAL_FUNCTIONS 10
#define COMM_REQ_FUNCTIONS 11
#define DO_IO_SUS_IO_FUNCTIONS 12
#define PLC_UTILITY_FUNCTIONS 13
#define BUS_READ_WRITE_FUNCTIONS 14
#define PLC_REF_MEMORY_FUNCTIONS 15
#define REF_MEM_SIZE_FUNCTIONS 16
#define REF_MEM_RACKX_FUNCTIONS 17
#define REF_MEM_BIT_CLR_TST_FUNCTIONS 18
#define REF_MEM_READ_WRITE_FUNCTIONS 19
#define SERIAL_PORT_READ_WRITE_FUNCTIONS 20

/* default offsets for PLC data exchanges */
#define AI_offset		101
#define AQ_offset	101
#define L_offset		1
#define P_offset		51
#define R_offset		101
#define W_offset		51
#define I_offset		81
#define Q_offset		81
#define M_offset		81		
#define T_offset		1
#define G_offset		81

/* Structures and typedefs */

/* Declarations for Global variables */

/* Declarations for Local variables */
/* Forward declarations */
/* forward declaration */
/* Routines */
void testFunction(void)
{
    RW(STATUS_REG) =  TEST_FUNCTION_CALLED;
//    printf("test function called \n");
}

int cmpfunc(const void *__e1, const void *__e2)
{
   return 0; /* prevents compiler warning */
}

extern void myFunc(void);

int GefMain(void)
{
    char buffer[] = "This is my buffer";
    double x = 1;
    double y = 2;
    double result;
    int exponent = 100;
    int __exp =1;
    double IntResult = 1000;
    float x1 = 1.57;
    float y1 = 2.57;
    int numer = 1;
    int denom = 2;
    div_t divStruct = {1,2};
    unsigned int __seed = 567;
    int __i = -32;
    long resultLong;
    long __iLong = 500;
    char end[] = "Test String";
    char *__endptr = end;
    int __baseInt = 2;
    unsigned long resultUlong = 100;
    char key[] = "55";
    void *__key = (void *)key;
    char base[] = "My Test String 55";
    void *__base = (void *)base;
    size_t __nelem = 10;
    size_t __size = 20;
    char *	pString;
    /* s1 array must be at least len(s1) + len(s2) +1 bytes in size */
    char s1[25] = "My Test String";
    char *__s1 = s1;
    char s2[] = " 55";
    char *__s2 = s2;
    int __c = 0x43;
    int resultInt;
    int __errcode = 0x33;
     /* __buf buffer must be at least 256 bytes for strerror_r call*/
    char __buf[256] = "This is a buffer";
    size_t __n = 10; 
    char *__ppLast = &s1[3];
    int s10[10];
    void *__s10 = (void *)s10;
    int s20[10];
    void *__s20 = (void *)s20;
    void *pVoid;
    char source[] = "This is the source";
    char destination[] = "This is the destin";
    int nbytes = 5;
    size_t _n = 5;
    char _format[] = "%a";
    struct tm _tmstruct = {0,0,0,1,0,0,0,0,0};
    char _buffer[50];
    size_t _buflen = 50;
    time_t _t1 = 100;
    time_t _t0 = 50;
    char resultChar = 'D';
    T_INT32 resultInt32;
    struct clear_fault_tables_rec clearFaultTablesRec;
    struct read_last_fault_rec readLastFaultRec;
    struct read_last_ext_fault_rec readLastExtFaultRec;
    struct read_fault_tables_rec readFaultTablesRec;
    struct read_ext_fault_tables_rec readExtFaultTablesRec;
    struct elapsed_clock_rec elapsedClockRec;
    struct nano_elapsed_clock_rec nanoElapsedClockRec;
    T_WORD errorCode;
    char faultString[] = "This is a fault string";
    struct PLC_ver_info_rec plcVerInfoRec;
    struct const_sweep_timer_rec constSweepTimerRec;
    struct read_window_values_rec readWindowValuesRec;
    struct change_controller_comm_window_rec changeControllerCommWindow;
    struct change_backplane_comm_window_rec changeBackplaneCommWindow;
    struct change_background_window_rec changeBackgroundWindowRec;
    struct number_of_words_in_chksm_rec numberOfWordsInChecksumRec;
    struct tod_clock_rec todClockRec;
/*     struct tod_clock_with_status_rec todClockWithStatusRec; function not supported for this release */
    struct time_since_start_of_sweep_rec timeSinceStartOfSweepRec;
    struct nano_time_since_start_of_sweep_rec nanoTimeSinceStartOfSweepRec;
    struct read_folder_name_rec readFolderNameRec;
    struct read_PLC_ID_rec readPlcIdRec;
    struct read_PLC_state_rec readPlcStateRec;
    struct mask_IO_interrupts_rec maskIoInterruptsRec;
    struct read_IO_override_status_rec readIoOverrideStatusRec;
    struct set_run_enable_rec setRunEnableRec;
    struct mask_timed_interrupts_rec maskTimedInterruptsRec;
    struct sus_res_HSC_interrupts_rec susResHscInterruptsRec;
    struct escm_status_rec escmStatusRec;
    struct comm_req_command_blk_rec commReqCommandBlkRec;
    struct comm_req_rec commReqRec;
    struct comm_req_command_blk_rec_extended commReqCommandBlkRecExtended;
    struct comm_req_rec_extended commReqExtendedRec;
    struct do_io_rec doIoRec;
    T_BYTE request_type;
    char id_str[] = "This is an SNP Id";
    T_BYTE tbl_typ;
    T_WORD ref_num;
    T_WORD len;
    T_BYTE data;
    T_WORD resultWord;
    T_BYTE firstByte[100];
    T_DWORD length = 5;
    T_WORD currentCrcValue = 0;
    T_BYTE resultByte;
    T_BYTE rack=1;
    T_BYTE slot=5;
    T_WORD subSlot = 0;
    T_WORD region;
    T_BYTE valueByte;
    T_DWORD address=1;
    T_WORD valueWord;
    T_DWORD valueDword;
    T_BYTE buffer1[100];
    T_BYTE op_type;
    T_BYTE mask;
    T_BYTE semaphore_output_byte;
    T_WORD semaphore_output_word;
    T_BYTE setByte = 0x55;
    T_INT16 resultInt16;
    float resultFloat;
    T_WORD setWord = 0x55AA;
    T_INT16 setInt16 = -15000;
    T_INT32 setInt32 = -150000;
    float setFloat = 3.33333;
    T_DWORD resultDword;
    T_DWORD busNumber = 0;
    T_DWORD sbaNumber = 16;
    RACK_REFERENCE_REC *pRackReferenceRec;
    T_WORD RefTable = R_MEM;
    T_BYTE writeValueByte = 0xaa;
    T_WORD writeValueWord = 0x55aa;
    T_INT16 writeValueInt16 = -32000;
    T_INT32 writeValueInt32 = -320000;
    T_BOOLEAN msbByte = TRUE;
    T_WORD busStatus = 0;
    T_BYTE originalValueByte =0;
    T_WORD originalValueWord =0;
    T_DWORD originalValueDword =0;
    float largeFloat;
    T_DWORD longNumber;
    T_INT32 scanfReturn = 0;
    T_INT32 scanfInput = 0xaaaa5555;
    T_INT32 port = 0;
    char messageBuffer[] = "Test Serial I/O Message Buffer";
    T_INT32 numBytes = 30;
    float hugeValueFloat;
    /* test that link errors are caught by uncommenting the next line */
    /* myFunc(); */
    /* test making a call to a user function */
    testFunction();

    /* stdio.h  functions */
    sprintf (buffer, "This is my buffer");
    scanfReturn = sscanf("123","%d", &scanfInput);

    RW(STATUS_REG) = MATH_FUNCTIONS;
//    printf("math.h functions \n");

    /* math.h functions */
    largeFloat = DBL_MAX;  /* verifies float.h  usage */
    longNumber = LONG_MAX; /* verified limits.h usage */
    hugeValueFloat = HUGE_VAL;  /* tests HUGE_VAL which links to function infinity() */
    result = acos (x);
    result = asin (x);
    result = atan (x);
    result = ceil (x);
    result = cos (x);
    result = cosh (x);
    result = exp (x);
    result = fabs (x);
    result = floor (x);
    result = fmod (x, y);
    result = frexp (x, &exponent);
    result = ldexp (x, __exp);
    result = log (x);
    result = log10 (x);
    result = modf (x, &IntResult);
    result = pow (x, y);
    result = sin (x);
    result = sinh (x);
    result = sqrt (x);
    result = tan (x);
    result = tanh (x);

    resultFloat = acosf (x1);
    resultFloat =  	asinf (x1);
    resultFloat =  	atanf (x1);
    resultFloat =  	ceilf (x1);
    resultFloat =  	cosf (x1);
    resultFloat =  	coshf (x1);
    resultFloat =  	expf (x1);
    resultFloat =  	fabsf (x1);
    resultFloat =  	floorf (x1);
    resultFloat =  	fmodf (x1, y1);
    resultFloat =  	logf (x1);
    resultFloat =  	log10f (x1);
    resultFloat =  	powf (x1, y1);
    resultFloat =  	sinf (x1);
    resultFloat =  	sinhf (x1);
    resultFloat =  	sqrtf (x1);
    resultFloat =  	tanf (x1);
    resultFloat =  	tanhf (x1);
    resultFloat = x1*y1;

    RW(STATUS_REG) = STLIB_FUNCTIONS;
//    printf("stdlib.h functions \n");

    /* stdlib.h functions */
    div_r (numer, denom, &divStruct);
    numer=	rand ();
    srand (__seed);
    numer = abs (__i);
    result = atof ("Test string");
    numer = atoi ("Test string");
    resultLong = atol ("Test string");
    resultLong = labs (__iLong);
    resultLong = strtol ("Test string55", &__endptr, __baseInt);
    resultUlong = strtoul ("Test string55", &__endptr, __baseInt);
    pVoid = bsearch (__key, __base,
		             __nelem, __size,
		             &cmpfunc);
    __nelem = 17;
    __size = 1;
    qsort (__base,__nelem, __size, &cmpfunc);
    RW(STATUS_REG) = STRING_FUNCTIONS;
//    printf("string.h functions \n");

    /* string.h functions */
    pString = strcat (__s1, __s2);
    pString = strchr (__s1, __c);
    resultInt = strcmp (__s1, __s2);
    pString = strcpy (__s1, __s2);
    resultInt = strcspn (__s1, __s2);
    resultInt = strerror_r (__errcode, __buf);
    resultInt = strlen (__s1);
    pString = strncat (__s1, __s2, __n);
    resultInt = strncmp (__s1, __s2, __n);
    pString = strncpy (__s1, __s2, __n);
    pString = strpbrk (__s1, __s2);
    pString = strrchr (__s1, __c);
    resultInt = strspn (__s1, __s2);
    pString = strstr (__s1, __s2);
    pString = strtok_r (__s1, __s2, &__ppLast);
    pVoid = memchr (__s10, __c, __n);
    resultInt = memcmp (__s10, __s20, __n);
    pVoid = memcpy (__s10, __s20, __n);
    pVoid = memmove (__s10, __s20, __n);
    pVoid = memset (__s10, __c, __n);
    uswab (source, destination, nbytes);
    resultInt = strcoll (__s1, __s2);

    RW(STATUS_REG) = TIME_FUNCTIONS;
//    printf("time.h functions \n");
    /* time.h functions */
    resultInt = strftime (__s1, _n, _format,
		   	          &_tmstruct);
    resultInt = asctime_r(&_tmstruct, _buffer,
			         &_buflen);
    result = difftime (_t1, _t0);

    RW(STATUS_REG) = CTYPE_FUNCTIONS;
//    printf("ctype.h functions \n");
    /* ctype.h functions */
    resultInt = isalnum( __c);
    resultInt =       isalpha( __c);
    resultInt =       iscntrl( __c);
    resultInt =       isdigit( __c);
    resultInt =       isgraph( __c);
    resultInt =       islower( __c);
    resultInt =       isprint( __c);
    resultInt =       ispunct( __c);
    resultInt =       isspace( __c);
    resultInt =       isupper( __c);
    resultInt =       isxdigit( __c);
    resultInt =       tolower( __c);
    resultInt =       toupper( __c);

    RW(STATUS_REG) = GEFCLIB_FUNCTIONS;


/* Example legacy functions */

#ifdef LEGACY70
    /* GefCLib.h functions */
    pString = _fstrcat (__s1, __s2);
    pString = _fstrchr (__s1, __c);
    resultInt = _fstrcmp (__s1, __s2);
    pString = _fstrcpy (__s1, __s2);
    resultInt = _fstrcspn (__s1, __s2);
    resultInt = _fstrlen (__s1);
    pString = _fstrncat (__s1, __s2, __n);
    resultInt = _fstrncmp (__s1, __s2, __n);
    pString = _fstrncpy (__s1, __s2, __n);
    pString = _fstrpbrk (__s1, __s2);
    pString = _fstrrchr (__s1, __c);
    resultInt = _fstrspn (__s1, __s2);
    pString = _fstrstr (__s1, __s2);
    pVoid = _fmemchr (__s10, __c, __n);
    resultInt = _fmemcmp (__s10, __s20, __n);
    pVoid = _fmemcpy (__s10, __s20, __n);
    pVoid = _fmemmove (__s10, __s20, __n);
    pVoid = _fmemset (__s10, __c, __n);
#endif

    _swab (source, destination, nbytes);

    resultInt = max(100,10);
    resultInt = min(100,10);

    resultChar = toascii(150);

    resultInt =      tolower( 'D');
    resultInt =      toupper( 'd');

    RW(STATUS_REG) = PLC_ERRNO_FUNCTIONS;
//    printf("PLC Errno functions \n");
    /* PLC Errno functions */
    resultDword = PLCC_GetErrno();
    PLCC_ClearErrno();

    RW(STATUS_REG) = PLC_FAULT_FUNCTIONS;
//    printf("Plc Fault Functions \n");
    /* Plc Fault Functions */
    resultInt32 = PLCC_clear_fault_tables(&clearFaultTablesRec);
    resultInt32 = PLCC_read_last_fault(&readLastFaultRec);
    resultInt32 = PLCC_read_last_ext_fault(&readLastExtFaultRec);
    resultInt32 = PLCC_read_fault_tables(&readFaultTablesRec);
    resultInt32 = PLCC_read_ext_fault_tables(&readExtFaultTablesRec);

    RW(STATUS_REG) = PLC_GENERAL_FUNCTIONS;
//    printf("Plc General functions \n");
    /* Plc General functions */
    resultInt32 = PLCC_read_elapsed_clock(&elapsedClockRec);
    resultInt32 =  PLCC_read_nano_elapsed_clock(&nanoElapsedClockRec);
    resultInt32 =  PLCC_chars_in_printf_q();
    resultInt32 =  PLCC_gen_alarm (errorCode, faultString);
    resultInt32 =  PLCC_get_plc_version (&plcVerInfoRec);
    constSweepTimerRec.const_sweep.input.action = READ_TIMER_VALUE_AND_STATE;
    constSweepTimerRec.const_sweep.input.timer_value = 1000;
    resultInt32 =   PLCC_const_sweep_timer(&constSweepTimerRec);
    resultInt32 =   PLCC_read_window_values(&readWindowValuesRec);
    // controller, backplane, and background comm windows set to PLC default values
	changeControllerCommWindow.mode = LIMITED_MODE;	
	changeControllerCommWindow.time = 10;		
	resultInt32 =   PLCC_change_controller_comm_window (&changeControllerCommWindow);	
	changeBackplaneCommWindow.mode = RUN_TO_COMPLETION_MODE;	
	changeBackplaneCommWindow.time = 255;	
	resultInt32 =   PLCC_change_backplane_comm_window(&changeBackplaneCommWindow);
	changeBackgroundWindowRec.mode = LIMITED_MODE;
	changeBackgroundWindowRec.time = 0;		
    resultInt32 =   PLCC_change_background_window (&changeBackgroundWindowRec);
    resultInt32 =   PLCC_number_of_words_in_chksm (&numberOfWordsInChecksumRec);
    resultInt32 =   PLCC_tod_clock(&todClockRec);
/*    resultInt32 =   PLCC_tod_clock_with_status(&todClockWithStatusRec); * not supported this release */
    resultInt32 =   PLCC_time_since_start_of_sweep (&timeSinceStartOfSweepRec);
    resultInt32 =   PLCC_nano_time_since_start_of_sweep (&nanoTimeSinceStartOfSweepRec);
    resultInt32 =   PLCC_read_folder_name (&readFolderNameRec);
    resultInt32 =   PLCC_read_PLC_ID(&readPlcIdRec);
    resultInt32 =   PLCC_read_PLC_state(&readPlcStateRec);
    if (0)  /* never call this function but include it in the code so that the link to the firmware is tested
               during the store process */
    {
        resultInt32 =   PLCC_shut_down_plc(0);
    }
    resultInt32 =   PLCC_mask_IO_interrupts(&maskIoInterruptsRec);
    resultInt32 =   PLCC_read_IO_override_status (&readIoOverrideStatusRec);
    resultInt32 =   PLCC_set_run_enable(&setRunEnableRec);
    resultInt32 =   PLCC_mask_timed_interrupts (&maskTimedInterruptsRec);
    resultInt32 =   PLCC_sus_res_HSC_interrupts (&susResHscInterruptsRec);
    resultInt32 =   PLCC_get_escm_status (&escmStatusRec);
    resultInt32 =  PLCC_SNP_ID(request_type, id_str);
    resultInt32 =   PLCC_read_override(tbl_typ, ref_num, len, &data);

    commReqRec.command_blk = &commReqCommandBlkRec;
    commReqRec.command_blk->idle_timeout = 1;
    commReqRec.command_blk->length = 128;
    commReqRec.command_blk->max_comm_time = 6;
    commReqRec.command_blk->status.offset = 1;
    commReqRec.command_blk->status.seg_selector = R_MEM;
    commReqRec.command_blk->wait = 0;
    commReqRec.rack = 0;
    commReqRec.slot = 1;
    commReqRec.task_id = 13;


    RW(STATUS_REG) = COMM_REQ_FUNCTIONS;
//    printf("call comm req \n");
    resultInt32 =   PLCC_comm_req(&commReqRec);
    commReqExtendedRec.command_blk = &commReqCommandBlkRecExtended;
    commReqExtendedRec.command_blk->data[0] = 0x5555;
    resultInt32 =   PLCC_comm_req_extended(&commReqExtendedRec);

    resultInt32 =   PLCC_reset_watchdog_timer();


    RW(STATUS_REG) = DO_IO_SUS_IO_FUNCTIONS;
    resultInt32 =   PLCC_do_io(&doIoRec);
    resultInt32 =   PLCC_sus_io();

    RW(STATUS_REG) = PLC_UTILITY_FUNCTIONS;
//    printf("Plc Utility Functions \n");
    /* Plc Utility Functions */
    resultWord = PLCC_Crc16Checksum(firstByte, length, currentCrcValue);

    RW(STATUS_REG) = BUS_READ_WRITE_FUNCTIONS;
//    printf("Plc Bus Read/Write Functions \n");
    /* Plc Bus Read/Write Functions */
    resultByte =   PLCC_BUS_read_byte(rack, slot, subSlot, region, &busStatus, &valueByte, address);
    resultByte =   PLCC_BUS_read_word(rack, slot, subSlot, region, &busStatus, &valueWord, address);
    resultByte =   PLCC_BUS_read_dword(rack, slot, subSlot, region, &busStatus, &valueDword, address);
    resultByte =   PLCC_BUS_read_block(rack, slot, subSlot, region, &busStatus, buffer1, sizeof(buffer1), address);
    resultByte =   PLCC_BUS_write_byte(rack, slot, subSlot, region, &busStatus, valueByte, address);
    resultByte =   PLCC_BUS_write_word(rack, slot, subSlot, region, &busStatus, valueWord, address);
    resultByte =   PLCC_BUS_write_dword(rack, slot, subSlot, region, &busStatus, valueDword, address);
    resultByte =   PLCC_BUS_write_block(rack, slot, subSlot, region, &busStatus, buffer1, sizeof(buffer1), address);
    resultInt32 =   PLCC_BUS_RMW_byte(rack, slot, subSlot, region, &busStatus, &originalValueByte, op_type, mask, address);
    resultInt32 =   PLCC_BUS_RMW_word(rack, slot, subSlot, region, &busStatus, &originalValueWord, op_type, mask, address);
    resultInt32 =   PLCC_BUS_RMW_dword(rack, slot, subSlot, region, &busStatus, &originalValueDword, op_type, mask, address);
    resultInt32 =   PLCC_BUS_TST_byte(rack, slot, subSlot, region, &busStatus, &semaphore_output_byte, address);
    resultInt32 =   PLCC_BUS_TST_word(rack, slot, subSlot, region, &busStatus, &semaphore_output_word, address);

    RW(STATUS_REG) = PLC_REF_MEMORY_FUNCTIONS;
//    printf("Plc Reference Memory Functions & Macros \n");
    /* Plc Reference Memory Functions & Macros */
    BIT_SET_R( R_offset, 16 );
    resultByte = BIT_TST_R( R_offset, 16 );
    BIT_CLR_R( R_offset, 16 );
    resultByte = BIT_TST_R( R_offset, 16 );
    BIT_SET_AI( AI_offset, 4);
    resultWord = BIT_TST_AI( AI_offset, 4);
    BIT_CLR_AI( AI_offset, 4);
    resultWord = BIT_TST_AI( AI_offset, 4);
    BIT_SET_AQ( AQ_offset, 13);
    resultWord = BIT_TST_AQ( AQ_offset, 13);
    BIT_CLR_AQ( AQ_offset, 13);
    resultWord = BIT_TST_AQ( AQ_offset, 13);
    BIT_SET_W( W_offset, 14);
    resultWord = BIT_TST_W( W_offset, 14);
    BIT_CLR_W( W_offset, 14);
    resultWord = BIT_TST_W( W_offset, 14);
    BIT_SET_P( P_offset, 3);
    resultWord = BIT_TST_P( P_offset, 3);
    BIT_CLR_P( P_offset, 3);
    resultWord = BIT_TST_P( P_offset, 3);
    BIT_SET_L( L_offset, 8);
    resultWord = BIT_TST_L( L_offset, 8);
    BIT_CLR_L( L_offset, 8);
    resultWord = BIT_TST_L( L_offset, 8);
    resultByte = BIT_TST_S(1);
    resultByte = FST_SCN; 
    resultByte = T_10MS;
    resultByte = T_100MS;
    resultByte = T_SEC;
    resultByte = T_MIN;
    resultByte = ALW_ON;
    resultByte = ALW_OFF;
    resultByte = SY_FULL; 
    resultByte = IO_FULL;
    resultByte = FST_EXE;
    Ib( I_offset+16 ) = setByte;
    resultByte = Ib( I_offset+16 );
    Qb( Q_offset+31 ) = setByte;
    resultByte = Qb( Q_offset+31 );
    Mb( M_offset+21 ) = setByte;
    resultByte = Mb( M_offset+21 );
    Tb( T_offset+16 ) = setByte;
    resultByte = Tb( T_offset+16 );
    Gb( G_offset+25 ) = setByte;
    resultByte = Gb( G_offset+25 );
/*    Sb(1) = setByte; uncomment to generate warning */
    resultByte = Sb(1);
    SAb(5) = setByte;
    resultByte = SAb(5);
    SBb(11) = setByte;
    resultByte = SBb(11);
    SCb(14) = setByte;
    resultByte = SCb(14);
    RB( R_offset+1, 0) = setByte;
    resultByte = RB( R_offset+1, 0);
    AIB( AI_offset+1, 1) = setByte;
    resultByte = AIB( AI_offset+1, 1);
    AQB( AQ_offset+1, 0) = setByte;
    resultByte = AQB( AQ_offset+1, 0);
    WB( W_offset+1, 1) = setByte;
    resultByte = WB( W_offset+1, 1);
    PB( P_offset+1, 0) = setByte;
    resultByte = PB( P_offset+1, 0);
    LB( L_offset+1, 1) = setByte;
    resultByte = LB( L_offset+1, 1);

    Iw( I_offset+32 ) = setWord;
    resultWord = Iw( I_offset+32 );
    Qw( Q_offset+39 ) = setWord;
    resultWord = Qw( Q_offset+39 );
    Mw( M_offset+47 ) = setWord;
    resultWord = Mw( M_offset+47 );
    Tw( T_offset+40) = setWord;
    resultWord = Tw( T_offset+40);
    Gw( G_offset+32 ) = setWord;
    resultWord = Gw( G_offset+32 );
/*     Sw(1) = setWord; uncomment to generate warning */
    resultWord = Sw(1);
    SAw(8) = setWord;
    resultWord = SAw(8);
    SBw(9) = setWord;
    resultWord = SBw(9);
    SCw(16) = setWord;
    resultWord = SCw(16);

    RW( R_offset+2 ) = setWord;
    resultWord = RW( R_offset+2 );
    AIW( AI_offset+2 ) = setWord;
    resultWord = AIW( AI_offset+2 );
    AQW( AQ_offset+2 ) = setWord;
    resultWord = AQW( AQ_offset+2 );
    WW( W_offset+2 ) = setWord;
    resultWord = WW( W_offset+2 );
    PW( P_offset+2 ) = setWord;
    resultWord = PW( P_offset+2 );
    LW( L_offset+2 ) = setWord;
    resultWord = LW( L_offset+2 );

    Ii( I_offset+48 ) = setInt16;
    resultInt16 = Ii( I_offset+48 );
    Qi( Q_offset+55 ) = setInt16;
    resultInt16 = Qi( Q_offset+55 );
    Mi( M_offset+63 ) = setInt16;
    resultInt16 = Mi( M_offset+63 );
    Ti( T_offset+57 ) = setInt16;
    resultInt16 = Ti( T_offset+57 );
    Gi( G_offset+59 ) = setInt16;
    resultInt16 = Gi( G_offset+59 );
/*    Si(9) = setInt16;  uncomment to generate warning */
    resultInt16 = Si(9);
    SAi(8) = setInt16;
    resultInt16 = SAi(8);
    SBi(1) = setInt16;
    resultInt16 = SBi(1);
    SCi(9) = setInt16;
    resultInt16 = SCi(9);

    RI( R_offset+3 ) = setInt16;
    resultInt16 = RI( R_offset+3 );
    AII( AI_offset+3 ) = setInt16;
    resultInt16 = AII( AI_offset+3 );
    AQI( AQ_offset+3 ) = setInt16;
    resultInt16 = AQI( AQ_offset+3 );
    WI( W_offset+3 ) = setInt16;
    resultInt16 = WI( W_offset+3 );
    PI( P_offset+3 ) = setInt16;
    resultInt16 = PI( P_offset+3 );
    LI( L_offset+3 ) = setInt16;
    resultInt16 = LI( L_offset+3 );

    Id( I_offset+64 ) = setInt32;
    resultInt32 = Id( I_offset+64 );
    Qd( Q_offset+73 ) = setInt32;
    resultInt32 = Qd( Q_offset+73 );
    Md( M_offset+95 ) = setInt32;
    resultInt32 = Md( M_offset+95 );
    Td( T_offset+83 ) = setInt32;
    resultInt32 = Td( T_offset+83 );
    Gd( G_offset+79 ) = setInt32;
    resultInt32 = Gd( G_offset+79 );
/*    Sd(1) = setInt32; uncomment to generate warning */
    resultInt32 = Sd(1);
    SAd(8) = setInt32;
    resultInt32 = SAd(8);
    SBd(9) = setInt32;
    resultInt32 = SBd(9);
    SCd(16) = setInt32;
    resultInt32 = SCd(16);

    RD( R_offset+4 ) = setInt32;
    resultInt32 = RD( R_offset+4 );
    AID( AI_offset+4 ) = setInt32;
    resultInt32 = AID( AI_offset+4 );
    AQD( AQ_offset+4 ) = setInt32;
    resultInt32 = AQD( AQ_offset+4 );
    WD( W_offset+4 ) = setInt32;
    resultInt32 = WD( W_offset+4 );
    PD( P_offset+4 ) = setInt32;
    resultInt32 = PD( P_offset+4 );
    LD( L_offset+4 ) = setInt32;
    resultInt32 = LD( L_offset+4 );

    RF( R_offset+6 ) = setFloat;
    resultFloat = RF( R_offset+6 );
    AIF( AI_offset+6 ) = setFloat;
    resultFloat = AIF( AI_offset+6 );
    AQF( AQ_offset+6 ) = setFloat;
    resultFloat = AQF( AQ_offset+6 );
    WF( W_offset+6 ) = setFloat;
    resultFloat = WF( W_offset+6 );
    PF( P_offset+6 ) = setFloat;
    resultFloat = PF( P_offset+6 );
    LF( L_offset+6 ) = setFloat;
    resultFloat = LF( L_offset+6 );

/*    IB_TRANS(1)= setByte;  uncomment to generate warning */
    resultByte = IB_TRANS(1);
    resultByte = BIT_TST_I_TRANS(1);
/*    QB_TRANS(8)= setByte; uncomment to generate warning */
    resultByte = QB_TRANS(8);
    resultByte = BIT_TST_Q_TRANS(8);
/*    MB_TRANS(9)= setByte; uncomment to generate warning */
    resultByte = MB_TRANS(9);
    resultByte = BIT_TST_M_TRANS(9);
/*    TB_TRANS(16)= setByte; uncomment to generate warning */
    resultByte = TB_TRANS(16);
    resultByte = BIT_TST_T_TRANS(16);
/*    GB_TRANS(17)= setByte;  uncomment to generate warning */
    resultByte = GB_TRANS(17);
    resultByte = BIT_TST_G_TRANS(17);
/*    SB_TRANS(1)= setByte;  uncomment to generate warning */
    resultByte = SB_TRANS(1);
    resultByte = BIT_TST_S_TRANS(1);
/*    SAB_TRANS(8)= setByte; uncomment to generate warning */
    resultByte = SAB_TRANS(8);
    resultByte = BIT_TST_SA_TRANS(8);
/*    SBB_TRANS(9)= setByte; uncomment to generate warning */
    resultByte = SBB_TRANS(9);
    resultByte = BIT_TST_SB_TRANS(9);
/*    SCB_TRANS(16)= setByte; uncomment to generate warning */
    resultByte = SCB_TRANS(16);
    resultByte = BIT_TST_SC_TRANS(16);

/*    IB_DIAG(1) = setByte; uncomment to generate warning */
    resultByte = IB_DIAG(1);
    resultByte = BIT_TST_I_DIAG(1);
/*    QB_DIAG(8) = setByte;  uncomment to generate warning */
    resultByte = QB_DIAG(8);
    resultByte = BIT_TST_Q_DIAG(8);
/*    AIB_DIAG(1) = setByte; uncomment to generate warning */
    resultByte = AIB_DIAG(1);
/*    AQB_DIAG(2) = setByte; uncomment to generate warning */
    resultByte = AQB_DIAG(2);

    resultByte = AI_HIALRM(1);
    resultByte = AI_LOALRM(1);
    resultByte = AIB_FAULT(1);
    resultByte = AQB_FAULT(2);
    resultByte = AI_OVERRANGE(1);
    resultByte = AI_UNDERRANGE(1);

    RW(STATUS_REG) = REF_MEM_SIZE_FUNCTIONS;
//    printf("Plc Reference Memory Functions & Macros: start of size funcs \n");

    resultInt32 = L_SIZE;
    resultInt32 = P_SIZE;

    resultInt32 = R_SIZE;
    resultInt32 = AI_SIZE;
    resultInt32 = AQ_SIZE;
    resultInt32 = W_SIZE;
    resultInt32 = I_SIZE;
    resultInt32 = Q_SIZE;
    resultInt32 = T_SIZE;
    resultInt32 = M_SIZE;
    resultInt32 = G_SIZE;
    resultInt32 = SA_SIZE;
    resultInt32 = SB_SIZE;
    resultInt32 = SC_SIZE;
    resultInt32 = S_SIZE;
    resultInt32 = I_DIAGS_SIZE;
    resultInt32 = Q_DIAGS_SIZE;
    resultInt32 = AI_DIAGS_SIZE;
    resultInt32 = AQ_DIAGS_SIZE;

    RW(STATUS_REG) = REF_MEM_RACKX_FUNCTIONS;
//    printf("Plc Reference Memory Functions & Macros: start of rackx funcs \n");
    resultDword = RACKX(rack);
    resultDword = SLOTX(rack, slot);
    resultDword = BLOCKX(rack,slot, busNumber, sbaNumber);
    pRackReferenceRec =  RSMB(rack);

    RW(STATUS_REG) = REF_MEM_BIT_CLR_TST_FUNCTIONS;
//    printf("Plc Reference Memory Functions & Macros: start of bit/tst/clr discrete funcs \n");
    resultInt32 = BIT_SET_I( I_offset );
    resultByte = BIT_TST_I( I_offset );
    resultInt32 = BIT_CLR_I( I_offset );
    resultByte = BIT_TST_I( I_offset );

    resultInt32 = BIT_SET_Q( Q_offset+7 );
    resultByte = BIT_TST_Q( Q_offset+7 );
    resultInt32 = BIT_CLR_Q( Q_offset+7 );
    resultByte = BIT_TST_Q( Q_offset+7 );

    resultInt32 = BIT_SET_M( M_offset+15 );
    resultByte = BIT_TST_M( M_offset+15 );
    resultInt32 = BIT_CLR_M( M_offset+15 );
    resultByte = BIT_TST_M( M_offset+15 );

    resultInt32 = BIT_SET_T( T_offset+13 );
    resultByte = BIT_TST_T( T_offset+13 );    
    resultInt32 = BIT_CLR_T( T_offset+13 );
    resultByte = BIT_TST_T( T_offset+13 );    

    resultInt32 = BIT_SET_G( G_offset+11 );
    resultByte = BIT_TST_G( G_offset+11 );    
    resultInt32 = BIT_CLR_G( G_offset+11 );
    resultByte = BIT_TST_G( G_offset+11 );    

    resultInt32 = BIT_SET_SA(1);
    resultByte = BIT_TST_SA(1);
    resultInt32 = BIT_CLR_SA(1);
    resultByte = BIT_TST_SA(1);

    resultInt32 = BIT_SET_SB(9);
    resultByte = BIT_TST_SB(9);
    resultInt32 = BIT_CLR_SB(9);
    resultByte = BIT_TST_SB(9);

    resultInt32 = BIT_SET_SC(16);
    resultByte = BIT_TST_SC(16);
    resultInt32 = BIT_CLR_SC(16);
    resultByte = BIT_TST_SC(16);

    RW(STATUS_REG) = REF_MEM_READ_WRITE_FUNCTIONS;
//    printf("Plc Reference Memory Functions & Macros: start of write/read funcs \n");

    resultInt32 = WritePlcByte(RefTable, R_offset+address, writeValueByte, msbByte);
    resultByte = ReadPlcByte (RefTable, R_offset+address, msbByte);
    resultInt32 = WritePlcWord(RefTable, R_offset+address, writeValueWord);
    resultWord = ReadPlcWord (RefTable, R_offset+address);
    resultInt32 = WritePlcInt(RefTable, R_offset+address, writeValueInt16);
    resultInt16 = ReadPlcInt (RefTable, R_offset+address);
    resultInt32 = WritePlcDint(RefTable, R_offset+address, writeValueInt32);
    resultInt32 = ReadPlcDint (RefTable, R_offset+address);
    resultInt32 = PlcMemCopy(&RB( R_offset+1,1), &AIB(AI_offset+1,1), length);
    resultDword = refMemSize(R_MEM);
    resultInt32 = setBit(R_MEM, R_offset, 1);
    resultInt32 = clearBit(R_MEM, R_offset, 1);

    RW(STATUS_REG) = SERIAL_PORT_READ_WRITE_FUNCTIONS;
/* Serial Port Read/Write Functions */
   resultInt32 = PLCC_MessageWrite(port, messageBuffer, numBytes);
   resultInt32 = PLCC_MessageRead(port, messageBuffer, numBytes);
   resultInt32 = PLCC_CharsInMessageWriteQ(port);
   resultInt32 = PLCC_CharsInMessageReadQ(port);

//    printf("end of GefMain \n");
    return GEF_EXECUTION_OK;
}









