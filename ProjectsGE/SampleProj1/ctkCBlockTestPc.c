#include "copyright.h"
/*************************************************************************
 * Module $Id: ctkCBlockTestPc.c,v 1.12 2003/11/19 17:30:50 cashb1 Exp $
 *************************************************************************/
/******************************************************************************
`ModuleName ctkCBlockTestPc.c
` This file uses all C Run Time and Target Library functions supported
` by the C Toolkit to test that all the supported functions can
` be compiled, linked and executed for PC debugging.  This file does not
` necessarily demonstrate the correct setup for each function call
` because its purpose is to show that each function can be compiled, linked
` and executed. 
*******************************************************************************/
/* `IncludeFiles */
#include "PACRXPlc.h"  /* Include file applicable for all targets */
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>
#include "ctkInitCBlock.h"
/* Constants / #defines  */

/* Structures and typedefs */

/* Declarations for Global variables */

/* Declarations for Local variables */
/* Forward declarations */
/* forward declaration */
/* Routines */
void testFunction(void)
{
    T_INT32 numBytes = 0;
    char buffer[100] = "This is my buffer";
    numBytes = sprintf(buffer, "test function called \n");
    PLCC_MessageWrite(PORT1, buffer, numBytes);
}

int cmpfunc(const void *__e1, const void *__e2)
{
    return 0;
}

int GefMain(void *pR8, void *pI1000, void *pM500)
{
    char buffer[100] = "This is my buffer";
    double x = 1;
    double y = 2;
    double result;
    int exponent = 100;
    int __exp;
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
    char s1[] = "My Test String";
    char *__s1 = s1;
    char s2[] = " 55";
    char *__s2 = s2;
    int __c = 0x43;
    int resultInt;
    int __errcode = 0x33;
    char __buf[] = "This is a buffer";
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
    T_WORD region = 1;
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
    T_DWORD scanfInput;
    T_WORD busStatus = 0;
    T_BYTE originalValueByte =0;
    T_WORD originalValueWord =0;
    T_DWORD originalValueDword =0;
    T_INT32 scanfReturn = 0;
    T_INT32 numBytes = 0;
    T_INT32 numBytesInQ = 0;

    /* test that link errors are caught by uncommenting the next line */
    /* myFunc(); */
    /* test making a call to a user function */
    testFunction();
    /* stdio.h  functions */
    sprintf (buffer, "This is my buffer");
    scanfReturn = sscanf("123","%d", &scanfInput);



    /* Message Mode Read/Write Functions */
    numBytesInQ = PLCC_CharsInMessageWriteQ(0);
    numBytes = sprintf(buffer, "Test of PLCC_MessageWrite \n");
    PLCC_MessageWrite(PORT1, buffer, numBytes);

    numBytesInQ = PLCC_CharsInMessageReadQ(0);
    numBytes = PLCC_MessageRead(0, buffer, numBytesInQ);

    numBytes = sprintf(buffer, "math.h functions \n");
    PLCC_MessageWrite(PORT1, buffer, numBytes);

    /* math.h functions */
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


    numBytes = sprintf(buffer, "stdlib.h functions \n");
    PLCC_MessageWrite(PORT1, buffer, numBytes);

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
    qsort (__base, __nelem, __size, &cmpfunc);


    numBytes = sprintf(buffer, "string.h functions \n");
    PLCC_MessageWrite(PORT1, buffer, numBytes);

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


    numBytes = sprintf(buffer, "time.h functions \n");
    PLCC_MessageWrite(PORT1, buffer, numBytes);

    /* time.h functions */
    resultInt = strftime (__s1, _n, _format,
		   	          &_tmstruct);
    resultInt = asctime_r(&_tmstruct, _buffer,
			         &_buflen);
    result = difftime (_t1, _t0);


    numBytes = sprintf(buffer, "ctype.h functions \n");
    PLCC_MessageWrite(PORT1, buffer, numBytes);


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


    numBytes = sprintf(buffer, "PLC Errno functions \n");
    PLCC_MessageWrite(PORT1, buffer, numBytes);

    /* PLC Errno functions */
    resultDword = PLCC_GetErrno();
    PLCC_ClearErrno();


    numBytes = sprintf(buffer, "Plc Fault Functions \n");
    PLCC_MessageWrite(PORT1, buffer, numBytes);

    /* Plc Fault Functions */
    resultInt32 = PLCC_clear_fault_tables(&clearFaultTablesRec);
    resultInt32 = PLCC_read_last_fault(&readLastFaultRec);
    resultInt32 = PLCC_read_last_ext_fault(&readLastExtFaultRec);
    resultInt32 = PLCC_read_fault_tables(&readFaultTablesRec);
    resultInt32 = PLCC_read_ext_fault_tables(&readExtFaultTablesRec);


    numBytes = sprintf(buffer, "Plc General functions \n");
    PLCC_MessageWrite(PORT1, buffer, numBytes);

    /* Plc General functions */
    resultInt32 = PLCC_read_elapsed_clock(&elapsedClockRec);
    resultInt32 =  PLCC_read_nano_elapsed_clock(&nanoElapsedClockRec);
    resultInt32 =  PLCC_chars_in_printf_q();
    resultInt32 =  PLCC_gen_alarm (errorCode, faultString);
    resultInt32 =  PLCC_get_plc_version (&plcVerInfoRec);
    resultInt32 =   PLCC_const_sweep_timer(&constSweepTimerRec);
    resultInt32 =   PLCC_read_window_values(&readWindowValuesRec);
    resultInt32 =   PLCC_change_controller_comm_window (&changeControllerCommWindow);
    resultInt32 =   PLCC_change_backplane_comm_window(&changeBackplaneCommWindow);
    resultInt32 =   PLCC_change_background_window (&changeBackgroundWindowRec);
    resultInt32 =   PLCC_number_of_words_in_chksm (&numberOfWordsInChecksumRec);
    resultInt32 =   PLCC_tod_clock(&todClockRec);
/*    resultInt32 =   PLCC_tod_clock_with_status(&todClockWithStatusRec); * not supported this release */
    resultInt32 =   PLCC_reset_watchdog_timer();
    resultInt32 =   PLCC_time_since_start_of_sweep (&timeSinceStartOfSweepRec);
    resultInt32 =   PLCC_nano_time_since_start_of_sweep (&nanoTimeSinceStartOfSweepRec);
    resultInt32 =   PLCC_read_folder_name (&readFolderNameRec);
    resultInt32 =   PLCC_read_PLC_ID(&readPlcIdRec);
    resultInt32 =   PLCC_read_PLC_state(&readPlcStateRec);
    resultInt32 =   PLCC_shut_down_plc(0);
    resultInt32 =   PLCC_mask_IO_interrupts(&maskIoInterruptsRec);
    resultInt32 =   PLCC_read_IO_override_status (&readIoOverrideStatusRec);
    resultInt32 =   PLCC_set_run_enable(&setRunEnableRec);
    resultInt32 =   PLCC_mask_timed_interrupts (&maskTimedInterruptsRec);
    resultInt32 =   PLCC_sus_res_HSC_interrupts (&susResHscInterruptsRec);
    resultInt32 =   PLCC_get_escm_status (&escmStatusRec);
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


    numBytes = sprintf(buffer, "call comm req \n");
    PLCC_MessageWrite(PORT1, buffer, numBytes);

    resultInt32 =   PLCC_comm_req(&commReqRec);
    resultInt32 =   PLCC_comm_req_extended(&commReqExtendedRec);
    resultInt32 =   PLCC_do_io(&doIoRec);
    resultInt32 =   PLCC_sus_io();
    resultInt32 =  PLCC_SNP_ID(request_type, id_str);
    resultInt32 =   PLCC_read_override(tbl_typ, ref_num, len, &data);


    numBytes = sprintf(buffer, "Plc Utility Functions \n");
    PLCC_MessageWrite(PORT1, buffer, numBytes);

    /* Plc Utility Functions */
    resultWord = PLCC_Crc16Checksum(firstByte, length, currentCrcValue);


    numBytes = sprintf(buffer, "Plc Bus Read/Write Functions \n");
    PLCC_MessageWrite(PORT1, buffer, numBytes);

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


    numBytes = sprintf(buffer, "Plc Reference Memory Functions & Macros \n");
    PLCC_MessageWrite(PORT1, buffer, numBytes);

    /* Plc Reference Memory Functions & Macros */
    BIT_SET_R(10,16);
    resultByte = BIT_TST_R(10,16);
    BIT_CLR_R(10,16);
    resultByte = BIT_TST_R(10,16);
    BIT_SET_AI(5,4);
    resultWord = BIT_TST_AI(5,4);
    BIT_CLR_AI(5,4);
    resultWord = BIT_TST_AI(5,4);
    BIT_SET_AQ(20,13);
    resultWord = BIT_TST_AQ(20,13);
    BIT_CLR_AQ(20,13);
    resultWord = BIT_TST_AQ(20,13);
    BIT_SET_W(20,14);
    resultWord = BIT_TST_W(20,14);
    BIT_CLR_W(20,14);
    resultWord = BIT_TST_W(20,14);
    BIT_SET_P(11,3);
    resultWord = BIT_TST_P(11,3);
    BIT_CLR_P(11,3);
    resultWord = BIT_TST_P(11,3);
    BIT_SET_L(33,8);
    resultWord = BIT_TST_L(33,8);
    BIT_CLR_L(33,8);
    resultWord = BIT_TST_L(33,8);
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
    Ib(1) = setByte;
    resultByte = Ib(1);
    Qb(8) = setByte;
    resultByte = Qb(8);
    Mb(9) = setByte;
    resultByte = Mb(9);
    Tb(16) = setByte;
    resultByte = Tb(16);
    Gb(17) = setByte;
    resultByte = Gb(17);
/*    Sb(1) = setByte; uncomment to get const warning */
    resultByte = Sb(1);
    SAb(5) = setByte;
    resultByte = SAb(5);
    SBb(11) = setByte;
    resultByte = SBb(11);
    SCb(14) = setByte;
    resultByte = SCb(14);
    RB(1,0) = setByte;
    resultByte = RB(1,0);
    AIB(2,1) = setByte;
    resultByte = AIB(2,1);
    AQB(3,0) = setByte;
    resultByte = AQB(3,0);
    WB(5,1) = setByte;
    resultByte = WB(5,1);
    PB(6,0) = setByte;
    resultByte = PB(6,0);
    LB(7,1) = setByte;
    resultByte = LB(7,1);

    Iw(25) = setWord;
    resultWord = Iw(25);
    Qw(32) = setWord;
    resultWord = Qw(32);
    Mw(33) = setWord;
    resultWord = Mw(33);
    Tw(40) = setWord;
    resultWord = Tw(40);
    Gw(41) = setWord;
    resultWord = Gw(41);
/*    Sw(1) = setWord; uncomment to get const warning */
    resultWord = Sw(1);
    SAw(8) = setWord;
    resultWord = SAw(8);
    SBw(9) = setWord;
    resultWord = SBw(9);
    SCw(16) = setWord;
    resultWord = SCw(16);

    RW(8) = setWord;
    resultWord = RW(8);
    AIW(9) = setWord;
    resultWord = AIW(9);
    AQW(10) = setWord;
    resultWord = AQW(10);
    WW(11) = setWord;
    resultWord = WW(11);
    PW(12) = setWord;
    resultWord = PW(12);
    LW(13) = setWord;
    resultWord = LW(13);

    Ii(48) = setInt16;
    resultInt16 = Ii(48);
    Qi(49) = setInt16;
    resultInt16 = Qi(49);
    Mi(56) = setInt16;
    resultInt16 = Mi(56);
    Ti(57) = setInt16;
    resultInt16 = Ti(57);
    Gi(64) = setInt16;
    resultInt16 = Gi(64);
/*    Si(9) = setInt16;  uncomment to get const warning */
    resultInt16 = Si(9);
    SAi(8) = setInt16;
    resultInt16 = SAi(8);
    SBi(1) = setInt16;
    resultInt16 = SBi(1);
    SCi(9) = setInt16;
    resultInt16 = SCi(9);

    RI(14) = setInt16;
    resultInt16 = RI(14);
    AII(15) = setInt16;
    resultInt16 = AII(15);
    AQI(16) = setInt16;
    resultInt16 = AQI(16);
    WI(17) = setInt16;
    resultInt16 = WI(17);
    PI(18) = setInt16;
    resultInt16 = PI(18);
    LI(19) = setInt16;
    resultInt16 = LI(19);

    Id(72) = setInt32;
    resultInt32 = Id(72);
    Qd(73) = setInt32;
    resultInt32 = Qd(73);
    Md(80) = setInt32;
    resultInt32 = Md(80);
    Td(81) = setInt32;
    resultInt32 = Td(81);
    Gd(88) = setInt32;
    resultInt32 = Gd(88);
/*    Sd(1) = setInt32;  uncomment to get const warning */
    resultInt32 = Sd(1);
    SAd(8) = setInt32;
    resultInt32 = SAd(8);
    SBd(9) = setInt32;
    resultInt32 = SBd(9);
    SCd(16) = setInt32;
    resultInt32 = SCd(16);

    RD(19) = setInt32;
    resultInt32 = RD(19);
    AID(20) = setInt32;
    resultInt32 = AID(20);
    AQD(21) = setInt32;
    resultInt32 = AQD(21);
    WD(22) = setInt32;
    resultInt32 = WD(22);
    PD(23) = setInt32;
    resultInt32 = PD(23);
    LD(24) = setInt32;
    resultInt32 = LD(24);

    RF(25) = setFloat;
    resultFloat = RF(25);
    AIF(26) = setFloat;
    resultFloat = AIF(26);
    AQF(27) = setFloat;
    resultFloat = AQF(27);
    WF(28) = setFloat;
    resultFloat = WF(28);
    PF(29) = setFloat;
    resultFloat = PF(29);
    LF(30) = setFloat;
    resultFloat = LF(30);

/*    IB_TRANS(1)= setByte; uncomment to get const warning */
    resultByte = IB_TRANS(1);
    resultByte = BIT_TST_I_TRANS(1);
/*    QB_TRANS(8)= setByte;  uncomment to get const warning */
    resultByte = QB_TRANS(8);
    resultByte = BIT_TST_Q_TRANS(8);
/*    MB_TRANS(9)= setByte;  uncomment to get const warning */
    resultByte = MB_TRANS(9);
    resultByte = BIT_TST_M_TRANS(9);
/*    TB_TRANS(16)= setByte; uncomment to get const warning */
    resultByte = TB_TRANS(16);
    resultByte = BIT_TST_T_TRANS(16);
/*    GB_TRANS(17)= setByte; uncomment to get const warning */
    resultByte = GB_TRANS(17);
    resultByte = BIT_TST_G_TRANS(17);
/*    SB_TRANS(1)= setByte; uncomment to get const warning */
    resultByte = SB_TRANS(1);
    resultByte = BIT_TST_S_TRANS(1);
/*    SAB_TRANS(8)= setByte; uncomment to get const warning */
    resultByte = SAB_TRANS(8);
    resultByte = BIT_TST_SA_TRANS(8);
/*    SBB_TRANS(9)= setByte; uncomment to get const warning */
    resultByte = SBB_TRANS(9);
    resultByte = BIT_TST_SB_TRANS(9);
/*    SCB_TRANS(16)= setByte; uncomment to get const warning */
    resultByte = SCB_TRANS(16);
    resultByte = BIT_TST_SC_TRANS(16);

/*    IB_DIAG(1) = setByte; uncomment to get const warning */
    resultByte = IB_DIAG(1);
    resultByte = BIT_TST_I_DIAG(1);
/*    QB_DIAG(8) = setByte; uncomment to get const warning */
    resultByte = QB_DIAG(8);
    resultByte = BIT_TST_Q_DIAG(8);
/*    AIB_DIAG(1) = setByte; uncomment to get const warning */
    resultByte = AIB_DIAG(1);
/*    AQB_DIAG(2) = setByte; uncomment to get const warning */
    resultByte = AQB_DIAG(2);

    resultByte = AI_HIALRM(1);
    resultByte = AI_LOALRM(1);
    resultByte = AIB_FAULT(1);
    resultByte = AQB_FAULT(2);
    resultByte = AI_OVERRANGE(1);
    resultByte = AI_UNDERRANGE(1);


    numBytes = sprintf(buffer, "Plc Reference Memory Functions & Macros: start of size funcs \n");
    PLCC_MessageWrite(PORT1, buffer, numBytes);

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


    numBytes = sprintf(buffer, "Plc Reference Memory Functions & Macros: start of rackx funcs \n");
    PLCC_MessageWrite(PORT1, buffer, numBytes);

    resultDword = RACKX(rack);
    resultDword = SLOTX(rack, slot);
    resultDword = BLOCKX(rack,slot, busNumber, sbaNumber);
    pRackReferenceRec =  RSMB(rack);


    numBytes = sprintf(buffer, "Plc Reference Memory Functions & Macros: start of bit/tst/clr discrete funcs \n");
    PLCC_MessageWrite(PORT1, buffer, numBytes);

    resultInt32 = BIT_SET_I(1);
    resultByte = BIT_TST_I(1);
    resultInt32 = BIT_CLR_I(1);
    resultByte = BIT_TST_I(1);

    resultInt32 = BIT_SET_Q(8);
    resultByte = BIT_TST_Q(8);
    resultInt32 = BIT_CLR_Q(8);
    resultByte = BIT_TST_Q(8);

    resultInt32 = BIT_SET_M(9);
    resultByte = BIT_TST_M(9);
    resultInt32 = BIT_CLR_M(9);
    resultByte = BIT_TST_M(9);

    resultInt32 = BIT_SET_T(16);
    resultByte = BIT_TST_T(16);    
    resultInt32 = BIT_CLR_T(16);
    resultByte = BIT_TST_T(16);    

    resultInt32 = BIT_SET_G(17);
    resultByte = BIT_TST_G(17);    
    resultInt32 = BIT_CLR_G(17);
    resultByte = BIT_TST_G(17);    

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


    numBytes = sprintf(buffer, "Plc Reference Memory Functions & Macros: start of write/read funcs \n");
    PLCC_MessageWrite(PORT1, buffer, numBytes);

    resultInt32 = WritePlcByte(RefTable, address, writeValueByte, msbByte);
    resultByte = ReadPlcByte (RefTable, address, msbByte);
    resultInt32 = WritePlcWord(RefTable, address, writeValueWord);
    resultWord = ReadPlcWord (RefTable, address);
    resultInt32 = WritePlcInt(RefTable, address, writeValueInt16);
    resultInt16 = ReadPlcInt (RefTable, address);
    resultInt32 = WritePlcDint(RefTable, address, writeValueInt32);
    resultInt32 = ReadPlcDint (RefTable, address);
    resultInt32 = PlcMemCopy(&RB(1,0), &AIB(1,0), length);
    resultDword = refMemSize(R_MEM);
    resultInt32 = setBit(R_MEM, 1, 1);
    resultInt32 = clearBit(R_MEM, 1, 1);


    numBytes = sprintf(buffer, "end of GefMain \n");
    PLCC_MessageWrite(PORT1, buffer, numBytes);

    return resultInt;
}

int main(int argc, char *argv[])
{
    initCBlock(); /* creates reference memory and initializes pointers to that memory*/
    GefMain(&RB(8,0), &Ib(1000), &Mb(500)); /* calling main passing pointers
                                               to %R8, %I1000 and %M500 and
                                               passing a constant parameter */
    return 0;
}








