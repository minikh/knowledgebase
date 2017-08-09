#include "copyright.h"
/*************************************************************************
 * Module $Id: ctkCBlockTest6.c,v 1.6 2003/11/17 22:20:55 cashb1 Exp $
 *************************************************************************/
/******************************************************************************
`ModuleName ctkCBlockTest6.c
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
void ctkCBlockTest1(void);

/* Routines */
void ctkCBlockTest6(void)
{
    T_INT32 resultInt32;
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
    T_BYTE resultByte;
    T_WORD resultWord;
    T_BYTE rack=1;
    T_BYTE slot=5;
    T_DWORD address=1;
    T_DWORD length = 5;
    char buffer[100];
    T_INT32 numBytes = 0;

    numBytes = sprintf(buffer, "Plc Reference Memory Functions & Macros \r\n");
    PLCC_MessageWrite(PORT1, buffer, numBytes);

    /* Plc Reference Memory Functions & Macros */
    BIT_SET_R(10,16);
    resultByte = BIT_TST_R(10,16);
    BIT_CLR_R(10,16);
    resultByte = BIT_TST_R(10,16);
    BIT_SET_AI(6,4);
    resultWord = BIT_TST_AI(6,4);
    BIT_CLR_AI(6,4);
    resultWord = BIT_TST_AI(6,4);
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
    Ib(17) = setByte;
    resultByte = Ib(17);
    Qb(17) = setByte;
    resultByte = Qb(17);
    Mb(9) = setByte;
    resultByte = Mb(9);
    Tb(16) = setByte;
    resultByte = Tb(16);
    Gb(17) = setByte;
    resultByte = Gb(17);
/*    Sb(1) = setByte;  uncomment to get const warning */
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
    LB(8,1) = setByte;
    resultByte = LB(8,1);

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
/*    Sw(1) = setWord;   uncomment to get const warning */
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
    AQW(12) = setWord;
    resultWord = AQW(12);
    WW(11) = setWord;
    resultWord = WW(11);
    PW(12) = setWord;
    resultWord = PW(12);
    LW(13) = setWord;
    resultWord = LW(13);

    Ii(48) = setInt16;
    resultInt16 = Ii(48);
    Qi(65) = setInt16;
    resultInt16 = Qi(65);
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
    LD(500) = setInt32;
    resultInt32 = LD(500);

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
/*    QB_TRANS(8)= setByte; uncomment to get const warning */
    resultByte = QB_TRANS(8);
    resultByte = BIT_TST_Q_TRANS(8);
/*    MB_TRANS(9)= setByte; uncomment to get const warning */
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

/*    IB_DIAG(1) = setByte;  uncomment to get const warning */
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

    numBytes = sprintf(buffer, "Plc Reference Memory Functions & Macros: start of size funcs \r\n");
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

    numBytes = sprintf(buffer, "Plc Reference Memory Functions & Macros: start of rackx funcs \r\n");
    PLCC_MessageWrite(PORT1, buffer, numBytes);

    resultDword = RACKX(rack);
    resultDword = SLOTX(rack, slot);
    resultDword = BLOCKX(rack,slot, busNumber, sbaNumber);
    pRackReferenceRec =  RSMB(rack);

    numBytes = sprintf(buffer, "Plc Reference Memory Functions & Macros: start of bit/tst/clr discrete funcs \r\n");
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

    numBytes = sprintf(buffer, "Plc Reference Memory Functions & Macros: start of write/read funcs \r\n");
    PLCC_MessageWrite(PORT1, buffer, numBytes);

    resultInt32 = WritePlcByte(RefTable, address, writeValueByte, msbByte);
    resultByte = ReadPlcByte (RefTable, address, msbByte);
    resultInt32 = WritePlcWord(RefTable, address, writeValueWord);
    resultWord = ReadPlcWord (RefTable, address);
    resultInt32 = WritePlcInt(RefTable, address, writeValueInt16);
    resultInt16 = ReadPlcInt (RefTable, address);
    resultInt32 = WritePlcDint(RefTable, address, writeValueInt32);
    resultInt32 = ReadPlcDint (RefTable, address);
    resultInt32 = PlcMemCopy(&RB(500,0), &AIB(1,0), length);
    resultDword = refMemSize(R_MEM);
    resultInt32 = setBit(R_MEM, 1, 1);
    resultInt32 = clearBit(R_MEM, 1, 1);


    numBytes = sprintf(buffer, "calling ctkCBlockTest1 \r\n");
    PLCC_MessageWrite(PORT1, buffer, numBytes);

    ctkCBlockTest1();
}









