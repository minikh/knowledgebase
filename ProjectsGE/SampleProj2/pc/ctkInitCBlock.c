#include "copyright.h"
/*************************************************************************
 * Module $Id: ctkInitCBlock.c,v 1.5 2005/06/30 14:52:49 cas Exp $
 *************************************************************************/
/******************************************************************************
`ModuleName ctkInitCBlock.c
` This file initializes memory for a C Block when the C Block is being 
` debugged on the PC. 
`
*******************************************************************************/
/* Uncomment "#define UNIT_TEST" line to enable unit test code */
/* #define UNIT_TEST */

/* `IncludeFiles */
#include "ctkInitCBlock.h"
#include "PACRXPlc.h"
#include "ctkGefSetupTable.h"
/* Constants / #defines  */
/* Structures and typedefs */
/* Declarations for Global variables */
REF_SEG_AND_SIZES_TABLE g_GlobalRefSegSizeTable; /* reference table memory
                                                    segment and size structure
                                                    which is pointed to by
                                                    a member in the 
                                                    g_GefSetupTable structure */

T_GEF_SETUP_TABLE    g_GefSetupTable;   /* C Setup table which contains reference 
                                       table memory segment and size structure
                                       which provides pointers to %L and %P
                                       memory location and sizes. */

/* create memory for each of the reference tables */
T_WORD lMem[MAX_L_WORDS] = {0};
T_WORD pMem[MAX_P_WORDS] = {0};
T_WORD rMem[MAX_R_WORDS] = {0};
T_WORD aiMem[MAX_AI_WORDS] = {0};
T_WORD aqMem[MAX_AQ_WORDS] = {0};
#ifndef UNIT_TEST
T_WORD wMem[MAX_W_WORDS] = {0};
#else /* unit test case;  simulator doesn't allow allocation of 2 Meg memory */
T_WORD wMem[100] = {0};
#endif /* not defined UNIT_TEST */
T_WORD aiDiagMem[MAX_AI_WORDS] = {0};
T_WORD aqDiagMem[MAX_AQ_WORDS] = {0};
T_BYTE localBooleanBlockMem[MAX_LOCAL_BOOLEAN_BLOCK_BYTES] = {0};
T_BYTE iMem[MAX_I_POINTS/8] = {0};
T_BYTE qMem[MAX_Q_POINTS/8] = {0};
T_BYTE tMem[MAX_T_POINTS/8] = {0};
T_BYTE mMem[MAX_M_POINTS/8] = {0};
T_BYTE saMem[MAX_SA_POINTS/8] = {0};
T_BYTE sbMem[MAX_SB_POINTS/8] = {0};
T_BYTE scMem[MAX_SC_POINTS/8] = {0};
T_BYTE sMem[MAX_S_POINTS/8] = {0};
T_BYTE gMem[MAX_G_POINTS/8] = {0};
T_BYTE iDiagMem[MAX_I_POINTS/8] = {0};
T_BYTE qDiagMem[MAX_Q_POINTS/8] = {0};
T_BYTE iTransMem[MAX_I_POINTS/8] = {0};
T_BYTE qTransMem[MAX_Q_POINTS/8] = {0};
T_BYTE tTransMem[MAX_T_POINTS/8] = {0};
T_BYTE mTransMem[MAX_M_POINTS/8] = {0};
T_BYTE saTransMem[MAX_SA_POINTS/8] = {0};
T_BYTE sbTransMem[MAX_SB_POINTS/8] = {0};
T_BYTE scTransMem[MAX_SC_POINTS/8] = {0};
T_BYTE sTransMem[MAX_S_POINTS/8] = {0};
T_BYTE gTransMem[MAX_G_POINTS/8] = {0};


/* Declarations for Local variables */
/* Forward declarations */
/* Routines */
/******************************************************************************
`Proc initCBlock()
` See ctkInitCBlock.h for a description of this function  
`
*******************************************************************************/
void initCBlock(void)
{
    /* Initialize g_GefSetupTables segment and size reference table structure */
    g_GefSetupTable.pLocalRefSegSizeTable = (REF_LOCAL_SEG_AND_SIZES_TABLE *)&g_GlobalRefSegSizeTable;
    g_GefSetupTable.pRefSegAndSizesTbl = &g_GlobalRefSegSizeTable;

    /* initialize pointers to each reference table memory */
    g_GlobalRefSegSizeTable[L_MEM].pSegMemory = &lMem;
    g_GlobalRefSegSizeTable[L_MEM].SizeInBytes = sizeof(lMem);

    g_GlobalRefSegSizeTable[P_MEM].pSegMemory = &pMem;
    g_GlobalRefSegSizeTable[P_MEM].SizeInBytes = sizeof(pMem);

    g_GlobalRefSegSizeTable[R_MEM].pSegMemory = &rMem;
    g_GlobalRefSegSizeTable[R_MEM].SizeInBytes = sizeof(rMem);

    g_GlobalRefSegSizeTable[AI_MEM].pSegMemory = &aiMem;
    g_GlobalRefSegSizeTable[AI_MEM].SizeInBytes = sizeof(aiMem);

    g_GlobalRefSegSizeTable[AQ_MEM].pSegMemory = &aqMem;
    g_GlobalRefSegSizeTable[AQ_MEM].SizeInBytes = sizeof(aqMem);

    g_GlobalRefSegSizeTable[W_MEM].pSegMemory = &wMem;
    g_GlobalRefSegSizeTable[W_MEM].SizeInBytes = sizeof(wMem);

    g_GlobalRefSegSizeTable[AI_DIAG_MEM].pSegMemory = &aiDiagMem;
    g_GlobalRefSegSizeTable[AI_DIAG_MEM].SizeInBytes = sizeof(aiDiagMem);

    g_GlobalRefSegSizeTable[AQ_DIAG_MEM].pSegMemory = &aqDiagMem;
    g_GlobalRefSegSizeTable[AQ_DIAG_MEM].SizeInBytes = sizeof(aqDiagMem);

    g_GlobalRefSegSizeTable[LOCAL_BOOLEAN_BLOCK_MEM].pSegMemory = &localBooleanBlockMem;
    g_GlobalRefSegSizeTable[LOCAL_BOOLEAN_BLOCK_MEM].SizeInBytes = sizeof(localBooleanBlockMem);

    g_GlobalRefSegSizeTable[I_MEM].pSegMemory = &iMem;
    g_GlobalRefSegSizeTable[I_MEM].SizeInBytes = sizeof(iMem);

    g_GlobalRefSegSizeTable[Q_MEM].pSegMemory = &qMem;
    g_GlobalRefSegSizeTable[Q_MEM].SizeInBytes = sizeof(qMem);

    g_GlobalRefSegSizeTable[T_MEM].pSegMemory = &tMem;
    g_GlobalRefSegSizeTable[T_MEM].SizeInBytes = sizeof(tMem);

    g_GlobalRefSegSizeTable[M_MEM].pSegMemory = &mMem;
    g_GlobalRefSegSizeTable[M_MEM].SizeInBytes = sizeof(mMem);

    g_GlobalRefSegSizeTable[SA_MEM].pSegMemory = &saMem;
    g_GlobalRefSegSizeTable[SA_MEM].SizeInBytes = sizeof(saMem);

    g_GlobalRefSegSizeTable[SB_MEM].pSegMemory = &sbMem;
    g_GlobalRefSegSizeTable[SB_MEM].SizeInBytes = sizeof(sbMem);

    g_GlobalRefSegSizeTable[SC_MEM].pSegMemory = &scMem;
    g_GlobalRefSegSizeTable[SC_MEM].SizeInBytes = sizeof(scMem);

    g_GlobalRefSegSizeTable[S_MEM].pSegMemory = &sMem;
    g_GlobalRefSegSizeTable[S_MEM].SizeInBytes = sizeof(sMem);

    g_GlobalRefSegSizeTable[G_MEM].pSegMemory = &gMem;
    g_GlobalRefSegSizeTable[G_MEM].SizeInBytes = sizeof(gMem);

    g_GlobalRefSegSizeTable[I_BIT].pSegMemory = &iMem;
    g_GlobalRefSegSizeTable[I_BIT].SizeInBytes = sizeof(iMem);

    g_GlobalRefSegSizeTable[I_DIAG_MEM].pSegMemory = &iDiagMem;
    g_GlobalRefSegSizeTable[I_DIAG_MEM].SizeInBytes = sizeof(iDiagMem);

    g_GlobalRefSegSizeTable[Q_DIAG_MEM].pSegMemory = &qDiagMem;
    g_GlobalRefSegSizeTable[Q_DIAG_MEM].SizeInBytes = sizeof(qDiagMem);

    g_GlobalRefSegSizeTable[I_TRANS_MEM].pSegMemory = &iTransMem;
    g_GlobalRefSegSizeTable[I_TRANS_MEM].SizeInBytes = sizeof(iTransMem);

    g_GlobalRefSegSizeTable[Q_TRANS_MEM].pSegMemory = &qTransMem;
    g_GlobalRefSegSizeTable[Q_TRANS_MEM].SizeInBytes = sizeof(qTransMem);

    g_GlobalRefSegSizeTable[T_TRANS_MEM].pSegMemory = &tTransMem;
    g_GlobalRefSegSizeTable[T_TRANS_MEM].SizeInBytes = sizeof(tTransMem);

    g_GlobalRefSegSizeTable[M_TRANS_MEM].pSegMemory = &mTransMem;
    g_GlobalRefSegSizeTable[M_TRANS_MEM].SizeInBytes = sizeof(mTransMem);

    g_GlobalRefSegSizeTable[SA_TRANS_MEM].pSegMemory = &saTransMem;
    g_GlobalRefSegSizeTable[SA_TRANS_MEM].SizeInBytes = sizeof(saTransMem);

    g_GlobalRefSegSizeTable[SB_TRANS_MEM].pSegMemory = &sbTransMem;
    g_GlobalRefSegSizeTable[SB_TRANS_MEM].SizeInBytes = sizeof(sbTransMem);

    g_GlobalRefSegSizeTable[SC_TRANS_MEM].pSegMemory = &scTransMem;
    g_GlobalRefSegSizeTable[SC_TRANS_MEM].SizeInBytes = sizeof(scTransMem);

    g_GlobalRefSegSizeTable[S_TRANS_MEM].pSegMemory = &sTransMem;
    g_GlobalRefSegSizeTable[S_TRANS_MEM].SizeInBytes = sizeof(sTransMem);

    g_GlobalRefSegSizeTable[G_TRANS_MEM].pSegMemory = &gTransMem;
    g_GlobalRefSegSizeTable[G_TRANS_MEM].SizeInBytes = sizeof(gTransMem);

    g_GefSetupTable.pLinkageInfo = NULL;
}

/*******************************************************************************/
/* Unit Test Code */
#ifdef UNIT_TEST

void ctkInitCBlockTest(void)
{
    T_BYTE resultByte;
    T_BYTE setByte =0x55;

    initCBlock();
    /* Test access to each table */
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
    Sb(1) = setByte;
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

    /* test for local Boolean Block */
    (*localBlock_mem)[0] = 01;
    resultByte = FST_EXE;
    
    /* Test for Transition and Diag memory */
    IB_TRANS(1)= setByte;
    resultByte = IB_TRANS(1);
    QB_TRANS(8)= setByte;
    resultByte = QB_TRANS(8);
    MB_TRANS(9)= setByte;
    resultByte = MB_TRANS(9);
    TB_TRANS(16)= setByte;
    resultByte = TB_TRANS(16);
    GB_TRANS(17)= setByte;
    resultByte = GB_TRANS(17);
    SB_TRANS(1)= setByte;
    resultByte = SB_TRANS(1);
    SAB_TRANS(8)= setByte;
    resultByte = SAB_TRANS(8);
    SBB_TRANS(9)= setByte;
    resultByte = SBB_TRANS(9);
    SCB_TRANS(16)= setByte;
    resultByte = SCB_TRANS(16);

    IB_DIAG(1) = setByte;
    resultByte = IB_DIAG(1);
    QB_DIAG(8) = setByte;
    resultByte = QB_DIAG(8);
    AIB_DIAG(1) = setByte;
    resultByte = AIB_DIAG(1);
    AQB_DIAG(2) = setByte;
    resultByte = AQB_DIAG(2);
}

#endif /* UNIT_TEST */
