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
 * Module $Id: ctkRefMem.c,v 1.10 2010/08/05 14:27:48 mummids1 Exp $
 *************************************************************************/
/******************************************************************************
`ModuleName ctkRefMem.c
` This file contains stub implementations of  
` the PLC reference memory functions which are used for debugging on the PC.
`
*******************************************************************************/
/* IncludeFiles */
#include <string.h>
#include "ctkPlc.h"
#include "ctkInitCBlock.h"
#include "ctkReleaseToUse.h"
/* Constants and Enumerations */
/* Type and Structure Definitions */
/* Global variables */

/* bit mask needed by Reference memory macros */
const T_DWORD tlib_bit_mask[16] = 
{0x00000001, 0x00000002, 0x00000004, 0x00000008, 
 0x00000010, 0x00000020, 0x00000040, 0x00000080, 
 0x00000100, 0x00000200, 0x00000400, 0x00000800, 
 0x00001000, 0x00002000, 0x00004000, 0x00008000};


RACK_REFERENCE_REC rackReferenceRecord[LIMIT_NUM_RACKS];
/* Local Variables */
/* Forward declarations */
/* Routines */
/******************************************************************************
`Proc IsDiscrete
` Based on the segment selector, this function determines if the selector refers
` to discrete memory type.
`
`InParam RefTable
` Contains the reference table segment selector
`
`ReturnVal
` Returns TRUE if the RefTable is discrete and FALSE otherwise.
`
*******************************************************************************/
static T_BOOLEAN IsDiscrete(T_WORD RefTable)
{
    T_BOOLEAN returnValue;
    switch (RefTable)
    {
        case LOCAL_BOOLEAN_BLOCK_MEM:      
        case I_MEM:
        case Q_MEM:
        case T_MEM:
        case M_MEM:
        case SA_MEM:
        case SB_MEM:
        case SC_MEM:
        case S_MEM:
        case G_MEM:
        case I_BIT:
        case I_DIAG_MEM:
        case Q_DIAG_MEM:
        case I_TRANS_MEM:
        case Q_TRANS_MEM:
        case T_TRANS_MEM:
        case M_TRANS_MEM:
        case SA_TRANS_MEM:
        case SB_TRANS_MEM:
        case SC_TRANS_MEM:
        case S_TRANS_MEM:
        case G_TRANS_MEM:
            returnValue= TRUE;
            break;
        default:
            returnValue = FALSE;
            break;
    }
    return returnValue;
}

/******************************************************************************
`Proc IsWord
` Based on the segment selector, this function determines if the selector refers
` to word type memory.
`
`InParam RefTable
` Contains the reference table segment selector
`
`ReturnVal
` Returns TRUE if the RefTable is word type and FALSE otherwise.
`
*******************************************************************************/
static T_BOOLEAN IsWord(T_WORD RefTable)
{
    T_BOOLEAN returnValue;
    switch (RefTable)
    {
        case L_MEM:
        case P_MEM:
        case R_MEM:
        case AI_MEM:
        case AQ_MEM:
        case W_MEM:
            returnValue = TRUE;
            break;
        default:
            returnValue = FALSE;
            break;
    }
    return returnValue;
}
        
/******************************************************************************
`Proc IsAnalogDiagnostic
` Based on the segment selector, this function determines if the selector refers
` to analog diagnostic type memory.
`
`InParam RefTable
` Contains the reference table segment selector
`
`ReturnVal
` Returns TRUE if the RefTable is analog diagnostic type and FALSE otherwise.
`
*******************************************************************************/
static T_BOOLEAN IsAnalogDiagnostic(T_WORD RefTable)
{
    T_BOOLEAN returnValue;
    switch (RefTable)
    {
        case AI_DIAG_MEM:
        case AQ_DIAG_MEM:
            returnValue = TRUE;
            break;
        default:
            returnValue = FALSE;
            break;
    }
    return returnValue;
}
        
/*******************************************************************************/

/******************************************************************************
`Proc WritePlcByte
` See ctkRefMem.h for a description of these functions.
*******************************************************************************/
T_INT32 WritePlcByte(T_WORD RefTable, T_DWORD address, T_BYTE writeValue, 
                     T_BOOLEAN msbByte)
{
    /* Note:  for stub implementations there is no address limit error checking */
    T_INT32 status = GEF_OK;
    /*` Initialize a byte array pointer to the start of the reference table memory */
    T_BYTE (*pRefMemory)[] = ((T_BYTE (*)[])(*g_GefSetupTable.pRefSegAndSizesTbl)[RefTable].pSegMemory);
    /*` IF the RefTable is discrete type
      `     use a bit address to write to the byte */
    if (IsDiscrete(RefTable))
    {
        (*pRefMemory)[((address)-1)>>3] = writeValue;
    }
    /*` ELSE the RefTable is not discrete type
      `     IF the RefTable is word type
      `         use a word address to write to the byte */
    else
    {
        if (IsWord(RefTable))
        {
            (*pRefMemory)[((address)-1)*2+msbByte] = writeValue;
        }
        /*` ELSE the RefTable is not word type
          `     IF the RefTable is analog diagnostics type 
          `         use a byte address to write to the byte */
        else
        {
            if (IsAnalogDiagnostic(RefTable))
            {
                (*pRefMemory)[((address)-1)] = writeValue;
            }
            /*` ELSE the RefTable is not analog diagnostics type
                    set status to error */
            else
            {
                status = GEF_ERROR;
            }
            /*` the RefTable is analog diagnostics type */
        }
        /*` ENDIF the RefTable is not word type */
    }
    /*` ENDIF the RefTable is discrete type */               
    return status;
}

/*******************************************************************************/

/******************************************************************************
`Proc ReadPlcByte
` See ctkRefMem.h for a description of these functions.
*******************************************************************************/
T_BYTE ReadPlcByte (T_WORD RefTable, T_DWORD address,T_BOOLEAN msbByte)
{
    T_BYTE returnValue;
    /* Note:  for stub implementations there is no error checking */
    /*` Initialize a byte array pointer to the start of the reference table memory */
    T_BYTE (*pRefMemory)[] = ((T_BYTE (*)[])(*g_GefSetupTable.pRefSegAndSizesTbl)[RefTable].pSegMemory);
    /*` IF the RefTable is discrete
      `     use a bit address to read byte */
    if (IsDiscrete(RefTable))
    {
        returnValue =  (*pRefMemory)[((address)-1)>>3];
    }
    /*` ELSE the RefTable is word
      `     IF the RefTable is word type
      `         use a word address to read the byte */
    else
    {
        if (IsWord(RefTable))
        {
            returnValue =  (*pRefMemory)[((address)-1)*2+msbByte];
        }
        /*` ELSE the RefTable is not word type
          `     IF the RefTable is analog diagnostics type 
          `         use a byte address to read the byte */
        else
        {
            if (IsAnalogDiagnostic(RefTable))
            {
                returnValue =  (*pRefMemory)[((address)-1)];
            }
            /*` ELSE the RefTable is not analog diagnostics type
                    return error value */
            else
            {
                returnValue = GEF_ERROR; /* $$$ look at setting errno here */
            }
            /*` the RefTable is analog diagnostics type */
        }
        /*` ENDIF the RefTable is not word type */
    }
    /*` ENDIF the RefTable is discrete type */               
    return returnValue;
}

/*******************************************************************************/

/******************************************************************************
`Proc WritePlcWord
` See ctkRefMem.h for a description of these functions.
*******************************************************************************/
T_INT32 WritePlcWord(T_WORD RefTable, T_DWORD address, T_WORD writeValue)
{
    /* Note:  for stub implementations there is no error checking */
    T_INT32 status = GEF_OK;
    /*` Initialize a byte array pointer to the start of the reference table memory */
    T_BYTE (*pDiscreteRefMemory)[] = ((T_BYTE (*)[])(*g_GefSetupTable.pRefSegAndSizesTbl)[RefTable].pSegMemory);
    T_WORD (*pWordRefMemory)[] = ((T_WORD (*)[])(*g_GefSetupTable.pRefSegAndSizesTbl)[RefTable].pSegMemory);
    /*` IF the RefTable is discrete
      `     use a bit address to write to the word */
    if (IsDiscrete(RefTable))
    {
        (*(T_WORD *)&((*pDiscreteRefMemory)[((address)-1)>>3])) = writeValue;
    }
    /*` ELSE the RefTable is word
      `     IF the RefTable is word type
      `         use a word address to write to the word */
    else
    {
        if (IsWord(RefTable))
        {
            (*pWordRefMemory)[((address)-1)] = writeValue;
        }
        /*` ELSE the RefTable is not word type
          `     IF the RefTable is analog diagnostics type 
          `         use a byte address to write to the word */
        else
        {
            if (IsAnalogDiagnostic(RefTable))
            {
                (*(T_WORD *)&((*pDiscreteRefMemory)[((address)-1)])) = writeValue;
            }
            /*` ELSE the RefTable is not analog diagnostics type
                    set status to error */
            else
            {
                status = GEF_ERROR;
            }
            /*` the RefTable is analog diagnostics type */
        }
        /*` ENDIF the RefTable is not word type */
    }
    /*` ENDIF the RefTable is discrete type */               
    return status;
}

/*******************************************************************************/

/******************************************************************************
`Proc ReadPlcWord
` See ctkRefMem.h for a description of these functions.
*******************************************************************************/
T_WORD ReadPlcWord (T_WORD RefTable, T_DWORD address)
{
    T_WORD returnValue;
    /* Note:  for stub implementations there is no error checking */
    /*` Initialize a byte array pointer to the start of the reference table memory */
    T_BYTE (*pDiscreteRefMemory)[] = ((T_BYTE (*)[])(*g_GefSetupTable.pRefSegAndSizesTbl)[RefTable].pSegMemory);
    T_WORD (*pWordRefMemory)[] = ((T_WORD (*)[])(*g_GefSetupTable.pRefSegAndSizesTbl)[RefTable].pSegMemory);
    /*` IF the RefTable is discrete
      `     use a bit address to write to the word */
    if (IsDiscrete(RefTable))
    {
        returnValue =  (*(T_WORD *)&((*pDiscreteRefMemory)[((address)-1)>>3]));
    }
    /*` ELSE the RefTable is word
      `     IF the RefTable is word type
      `         use a word address to read the word */
    else
    {
        if (IsWord(RefTable))
        {
            returnValue = (*pWordRefMemory)[((address)-1)];
        }
        /*` ELSE the RefTable is not word type
          `     IF the RefTable is analog diagnostics type 
          `         use a byte address to read the word */
        else
        {
            if (IsAnalogDiagnostic(RefTable))
            {
                returnValue = (*(T_WORD *)&((*pDiscreteRefMemory)[((address)-1)]));
            }
            /*` ELSE the RefTable is not analog diagnostics type
                    set return value to error */
            else
            {
                returnValue = GEF_ERROR;
            }
            /*` the RefTable is analog diagnostics type */
        }
        /*` ENDIF the RefTable is not word type */
    }
    /*` ENDIF the RefTable is discrete type */               
    return returnValue;
}

/*******************************************************************************/

/******************************************************************************
`Proc WritePlcInt
` See ctkRefMem.h for a description of these functions.
*******************************************************************************/
T_INT32 WritePlcInt(T_WORD RefTable, T_DWORD address, T_INT16 writeValue)
{
    /* Note:  for stub implementations there is no error checking */
    T_INT32 status = GEF_OK;
    /*` Initialize a byte array pointer to the start of the reference table memory */
    T_BYTE (*pDiscreteRefMemory)[] = ((T_BYTE (*)[])(*g_GefSetupTable.pRefSegAndSizesTbl)[RefTable].pSegMemory);
    T_WORD (*pWordRefMemory)[] = ((T_WORD (*)[])(*g_GefSetupTable.pRefSegAndSizesTbl)[RefTable].pSegMemory);
    /*` IF the RefTable is discrete
      `     use a bit address to write to the int*/
    if (IsDiscrete(RefTable))
    {
        (*(T_INT16 *)&((*pDiscreteRefMemory)[((address)-1)>>3])) = writeValue;
    }
    /*` ELSE the RefTable is word
      `     IF the RefTable is word type
      `         use a word address to write to the int */
    else
    {
        if (IsWord(RefTable))
        {
            (*(T_INT16 *)&((*pWordRefMemory)[((address)-1)])) = writeValue;
        }
        /*` ELSE the RefTable is not word type
          `     IF the RefTable is analog diagnostics type 
          `         use a byte address to write to the int */
        else
        {
            if (IsAnalogDiagnostic(RefTable))
            {
                (*(T_INT16 *)&((*pDiscreteRefMemory)[((address)-1)])) = writeValue;
            }
            /*` ELSE the RefTable is not analog diagnostics type
                    set status to error */
            else
            {
                status = GEF_ERROR;
            }
            /*` the RefTable is analog diagnostics type */
        }
        /*` ENDIF the RefTable is not word type */
    }
    /*` ENDIF the RefTable is discrete type */               
    return status;
}

/*******************************************************************************/

/******************************************************************************
`Proc ReadPlcInt
` See ctkRefMem.h for a description of these functions.
*******************************************************************************/
T_INT16 ReadPlcInt (T_WORD RefTable, T_DWORD address)
{
    T_INT16 returnValue;
    /* Note:  for stub implementations there is no error checking */
    /*` Initialize a byte array pointer to the start of the reference table memory */
    T_BYTE (*pDiscreteRefMemory)[] = ((T_BYTE (*)[])(*g_GefSetupTable.pRefSegAndSizesTbl)[RefTable].pSegMemory);
    T_WORD (*pWordRefMemory)[] = ((T_WORD (*)[])(*g_GefSetupTable.pRefSegAndSizesTbl)[RefTable].pSegMemory);
    /*` IF the RefTable is discrete
      `     use a bit address to write to the word */
    if (IsDiscrete(RefTable))
    {
        returnValue =  (*(T_INT16 *)&((*pDiscreteRefMemory)[((address)-1)>>3]));
    }
    /*` ELSE the RefTable is word
      `     IF the RefTable is word type
      `         use a word address to read the int */
    else
    {
        if (IsWord(RefTable))
        {
            returnValue =  (*(T_INT16 *)&((*pWordRefMemory)[((address)-1)]));
        }
        /*` ELSE the RefTable is not word type
          `     IF the RefTable is analog diagnostics type 
          `         use a byte address to read the int */
        else
        {
            if (IsAnalogDiagnostic(RefTable))
            {
                returnValue =  (*(T_INT16 *)&((*pDiscreteRefMemory)[((address)-1)]));
            }
            /*` ELSE the RefTable is not analog diagnostics type
                    set status to error */
            else
            {
                returnValue = GEF_ERROR;
            }
            /*` the RefTable is analog diagnostics type */
        }
        /*` ENDIF the RefTable is not word type */
    }
    /*` ENDIF the RefTable is discrete type */               
    return returnValue;
}

/*******************************************************************************/

/******************************************************************************
`Proc WritePlcDword
` See ctkRefMem.h for a description of these functions.
*******************************************************************************/
T_INT32 WritePlcDint(T_WORD RefTable, T_DWORD address, T_INT32 writeValue)
{
    /* Note:  for stub implementations there is no error checking */
    T_INT32 status = GEF_OK;
    /*` Initialize a byte array pointer to the start of the reference table memory */
    T_BYTE (*pDiscreteRefMemory)[] = ((T_BYTE (*)[])(*g_GefSetupTable.pRefSegAndSizesTbl)[RefTable].pSegMemory);
    T_WORD (*pWordRefMemory)[] = ((T_WORD (*)[])(*g_GefSetupTable.pRefSegAndSizesTbl)[RefTable].pSegMemory);
    /*` IF the RefTable is discrete
      `     use a bit address to write to the word */
    if (IsDiscrete(RefTable))
    {
        (*(T_INT32 *)&((*pDiscreteRefMemory)[((address)-1)>>3])) = writeValue;
    }
    /*` ELSE the RefTable is word
      `     IF the RefTable is word type
      `         use a word address to write to the dword */
    else
    {
        if (IsWord(RefTable))
        {
            (*(T_INT32 *)&((*pWordRefMemory)[((address)-1)])) = writeValue;
        }
        /*` ELSE the RefTable is not word type
          `     IF the RefTable is analog diagnostics type 
          `         use a byte address to write to the dword */
        else
        {
            if (IsAnalogDiagnostic(RefTable))
            {
                (*(T_INT32 *)&((*pDiscreteRefMemory)[((address)-1)])) = writeValue;
            }
            /*` ELSE the RefTable is not analog diagnostics type
                    set status to error */
            else
            {
                status = GEF_ERROR;
            }
            /*` the RefTable is analog diagnostics type */
        }
        /*` ENDIF the RefTable is not word type */
    }
    /*` ENDIF the RefTable is discrete type */               
    return status;
}

/*******************************************************************************/

/******************************************************************************
`Proc ReadPlcDword
` See ctkRefMem.h for a description of these functions.
*******************************************************************************/
T_INT32 ReadPlcDint (T_WORD RefTable, T_DWORD address)
{
    T_INT32 returnValue;
    /* Note:  for stub implementations there is no error checking */
    /*` Initialize a byte array pointer to the start of the reference table memory */
    T_BYTE (*pDiscreteRefMemory)[] = ((T_BYTE (*)[])(*g_GefSetupTable.pRefSegAndSizesTbl)[RefTable].pSegMemory);
    T_WORD (*pWordRefMemory)[] = ((T_WORD (*)[])(*g_GefSetupTable.pRefSegAndSizesTbl)[RefTable].pSegMemory);
    /*` IF the RefTable is discrete
      `     use a bit address to write to the word */
    if (IsDiscrete(RefTable))
    {
        returnValue =  (*(T_INT32 *)&((*pDiscreteRefMemory)[((address)-1)>>3]));
    }
    /*` ELSE the RefTable is word
      `     IF the RefTable is word type
      `         use a word address to read the dword */
    else
    {
        if (IsWord(RefTable))
        {
            returnValue =  (*(T_INT32 *)&((*pWordRefMemory)[((address)-1)]));
        }
        /*` ELSE the RefTable is not word type
          `     IF the RefTable is analog diagnostics type 
          `         use a byte address to read the dword */
        else
        {
            if (IsAnalogDiagnostic(RefTable))
            {
                returnValue =  (*(T_INT32 *)&((*pDiscreteRefMemory)[((address)-1)]));
            }
            /*` ELSE the RefTable is not analog diagnostics type
                    set status to error */
            else
            {
                returnValue =  GEF_ERROR;
            }
            /*` the RefTable is analog diagnostics type */
        }
        /*` ENDIF the RefTable is not word type */
    }
    /*` ENDIF the RefTable is discrete type */               
    return returnValue;
}

/*******************************************************************************/

#if (CTK_RELEASE_TO_USE >= 0x0550) /* only supported when compiling for
									  version 5.5 */

/******************************************************************************
`Proc WritePlcDouble
` See ctkRefMem.h for a description of these functions.
*******************************************************************************/
T_INT32 WritePlcDouble(T_WORD RefTable, T_DWORD address, T_REAL64 writeValue)
{
	/* Note:  for stub implementations there is no error checking */
	T_INT32 status = GEF_OK;
	/*` Initialize a byte array pointer to the start of the reference table memory */
	T_BYTE (*pDiscreteRefMemory)[] = ((T_BYTE (*)[])(*g_GefSetupTable.pRefSegAndSizesTbl)[RefTable].pSegMemory);
	T_WORD (*pWordRefMemory)[] = ((T_WORD (*)[])(*g_GefSetupTable.pRefSegAndSizesTbl)[RefTable].pSegMemory);
	/*` IF the RefTable is discrete
	  `     use a bit address to write to the word */
	if (IsDiscrete(RefTable))
	{
		(*(T_REAL64 *)&((*pDiscreteRefMemory)[((address)-1)>>3])) = writeValue;
	}
	/*` ELSE the RefTable is word
	  `     IF the RefTable is word type
	  `         use a word address to write to the dword */
	else
	{
		if (IsWord(RefTable))
		{
			(*(T_REAL64 *)&((*pWordRefMemory)[((address)-1)])) = writeValue;
		}
		/*` ELSE the RefTable is not word type
		  `     IF the RefTable is analog diagnostics type 
		  `         use a byte address to write to the dword */
		else
		{
			if (IsAnalogDiagnostic(RefTable))
			{
				(*(T_REAL64 *)&((*pDiscreteRefMemory)[((address)-1)])) = writeValue;
			}
			/*` ELSE the RefTable is not analog diagnostics type
					set status to error */
			else
			{
				status = GEF_ERROR;
			}
			/*` the RefTable is analog diagnostics type */
		}
		/*` ENDIF the RefTable is not word type */
	}
	/*` ENDIF the RefTable is discrete type */               
	return status;
}

/*******************************************************************************/

/******************************************************************************
`Proc ReadPlcDouble
` See ctkRefMem.h for a description of these functions.
*******************************************************************************/
T_REAL64 ReadPlcDouble (T_WORD RefTable, T_DWORD address)
{
	T_REAL64 returnValue;
	/* Note:  for stub implementations there is no error checking */
	/*` Initialize a byte array pointer to the start of the reference table memory */
	T_BYTE (*pDiscreteRefMemory)[] = ((T_BYTE (*)[])(*g_GefSetupTable.pRefSegAndSizesTbl)[RefTable].pSegMemory);
	T_WORD (*pWordRefMemory)[] = ((T_WORD (*)[])(*g_GefSetupTable.pRefSegAndSizesTbl)[RefTable].pSegMemory);
	/*` IF the RefTable is discrete
	  `     use a bit address to write to the word */
	if (IsDiscrete(RefTable))
	{
		returnValue =  (*(T_REAL64 *)&((*pDiscreteRefMemory)[((address)-1)>>3]));
	}
	/*` ELSE the RefTable is word
	  `     IF the RefTable is word type
	  `         use a word address to read the dword */
	else
	{
		if (IsWord(RefTable))
		{
			returnValue =  (*(T_REAL64 *)&((*pWordRefMemory)[((address)-1)]));
		}
		/*` ELSE the RefTable is not word type
		  `     IF the RefTable is analog diagnostics type 
		  `         use a byte address to read the dword */
		else
		{
			if (IsAnalogDiagnostic(RefTable))
			{
				returnValue =  (*(T_REAL64 *)&((*pDiscreteRefMemory)[((address)-1)]));
			}
			/*` ELSE the RefTable is not analog diagnostics type
					set status to error */
			else
			{
				returnValue =  GEF_ERROR;
			}
			/*` the RefTable is analog diagnostics type */
		}
		/*` ENDIF the RefTable is not word type */
	}
	/*` ENDIF the RefTable is discrete type */               
	return returnValue;
}

#endif /* CTK_RELEASE_TO_USE >= 5.50 */

/******************************************************************************
`Proc PlcMemCopy
` See ctkRefMem.h for a description of these functions.
*******************************************************************************/
T_INT32 PlcMemCopy(void *pDestination, void *pSource, T_DWORD size)
{
    /* Note: Stub implementations perform minimal error checking */
    T_INT32 status = GEF_OK;
    if (memcpy(pDestination, pSource, size) == NULL)
    {
        status = GEF_ERROR;
    }
    return status;
}

/*******************************************************************************/

/******************************************************************************
`Proc refMemSize
` See ctkRefMem.h for a description of these functions.
*******************************************************************************/
T_DWORD refMemSize(T_WORD RefTable)
{
    /* Note: for this stub implementation, the memory sizes are fixed.  These
       may not reflect the actual size of memory for the PLC you are using */
    T_INT32 refSize;
    switch (RefTable)
    {
        case L_MEM:
            refSize =  MAX_L_WORDS;
            break;
        case P_MEM:
            refSize =  MAX_P_WORDS;
            break;
        case R_MEM:
            refSize =  MAX_R_WORDS;
            break;
        case AI_MEM:
            refSize =  MAX_AI_WORDS;
            break;
        case AQ_MEM:
            refSize =  MAX_AQ_WORDS;
            break;
        case W_MEM:
            refSize =  MAX_W_WORDS;
            break;
        case AI_DIAG_MEM:
            refSize =  MAX_AI_WORDS; 
            break;
        case AQ_DIAG_MEM:
            refSize =  MAX_AQ_WORDS; 
            break;
        case LOCAL_BOOLEAN_BLOCK_MEM:      
            refSize =  MAX_LOCAL_BOOLEAN_BLOCK_BYTES;
            break;
        case I_MEM:
            refSize =  MAX_I_POINTS;
            break;
        case Q_MEM:
            refSize =  MAX_Q_POINTS;
            break;
        case T_MEM:
            refSize =  MAX_T_POINTS;
            break;
        case M_MEM:
            refSize =  MAX_M_POINTS;
            break;
        case SA_MEM:
            refSize =  MAX_SA_POINTS;
            break;
        case SB_MEM:
            refSize =  MAX_SB_POINTS;
            break;
        case SC_MEM:
            refSize =  MAX_SC_POINTS;
            break;
        case S_MEM:
            refSize =  MAX_S_POINTS;
            break;
        case G_MEM:
            refSize =  MAX_G_POINTS;
            break;
        case I_BIT:
            refSize =  MAX_I_POINTS;
            break;
        case I_DIAG_MEM:
            refSize =  MAX_I_POINTS;
            break;
        case Q_DIAG_MEM:
            refSize =  MAX_Q_POINTS;
            break;
        case I_TRANS_MEM:
            refSize =  MAX_I_POINTS;
            break;
        case Q_TRANS_MEM:
            refSize =  MAX_Q_POINTS;
            break;
        case T_TRANS_MEM:
            refSize =  MAX_T_POINTS;
            break;
        case M_TRANS_MEM:
            refSize =  MAX_M_POINTS;
            break;
        case SA_TRANS_MEM:
            refSize =  MAX_SA_POINTS;
            break;
        case SB_TRANS_MEM:
            refSize =  MAX_SB_POINTS;
            break;
        case SC_TRANS_MEM:
            refSize =  MAX_SC_POINTS;
            break;
        case S_TRANS_MEM:
            refSize =  MAX_S_POINTS;
            break;
        case G_TRANS_MEM:
            refSize =  MAX_G_POINTS;
            break;
        default:
            refSize =  GEF_ERROR;
            break;
    }
    return refSize;
}

/*******************************************************************************/

/******************************************************************************
`Proc setBit
` See ctkRefMem.h for a description of this function.
*******************************************************************************/
T_INT32 setBit(T_WORD RefTable, T_DWORD offset, T_WORD bitNumber)
{
    T_INT32 status = GEF_OK;
    if (IsDiscrete(RefTable))
    {
        (*((T_BYTE (*)[])((*g_GefSetupTable.pRefSegAndSizesTbl)[RefTable].pSegMemory)))[((offset)-1)>>3] |=  tlib_bit_mask[((offset)-1)&7];
    }
    else if (IsWord(RefTable))
    {
        (*((T_WORD (*)[])((*g_GefSetupTable.pRefSegAndSizesTbl)[RefTable].pSegMemory)))[(offset)-1] |=  tlib_bit_mask[((bitNumber)-1)&0x0F];
    }
    else
    {
        status = GEF_ERROR;
    }        
    return status;
}

/*******************************************************************************/

/******************************************************************************
`Proc clearBit
` See ctkRefMem.h for a description of this function.
*******************************************************************************/
T_INT32 clearBit(T_WORD RefTable, T_DWORD offset, T_WORD bitNumber)
{
    T_INT32 status = GEF_OK;
    if (IsDiscrete(RefTable))
    {
        (*((T_BYTE (*)[])((*g_GefSetupTable.pRefSegAndSizesTbl)[RefTable].pSegMemory)))[((offset)-1)>>3] &=  ~tlib_bit_mask[((offset)-1)&7];
    }
    else if (IsWord(RefTable))
    {
        (*((T_WORD (*)[])((*g_GefSetupTable.pRefSegAndSizesTbl)[RefTable].pSegMemory)))[(offset)-1] &=  ~tlib_bit_mask[((bitNumber)-1)&0x0F];
    }
    else
    {
        status = GEF_ERROR;
    }        
    return status;
}

/*******************************************************************************/

/******************************************************************************
`Proc rackX
` See ctkRefMem.h for a description of these functions.
*******************************************************************************/
T_DWORD rackX(T_BYTE rackNumber)
{
    T_DWORD rackSummaryBit = (rackReferenceRecord[rackNumber].RackFlags & REF_RACK_SUMMARY_FLAG);
    return rackSummaryBit;
}

/*******************************************************************************/

/******************************************************************************
`Proc slotX
` See ctkRefMem.h for a description of these functions.
*******************************************************************************/
T_DWORD slotX(T_BYTE rackNumber, T_DWORD slotNumber)
{
    T_DWORD slotFault = ((rackReferenceRecord[rackNumber].SlotFaults &(tlib_bit_mask[(slotNumber)]))>>(slotNumber));
    return slotFault;
}


/*******************************************************************************/

/******************************************************************************
`Proc blockX
` See ctkRefMem.h for a description of these functions.
*******************************************************************************/
T_DWORD blockX(T_BYTE rackNumber, T_DWORD slotNumber, 
                      T_DWORD busNumber, T_DWORD sbaNumber)
{
    T_DWORD moduleReferenceBit = 0x00000001;
    return moduleReferenceBit;
}

/*******************************************************************************/

/******************************************************************************
`Proc rsbm
` See ctkRefMem.h for a description of these functions.
*******************************************************************************/
RACK_REFERENCE_REC *rsmb(T_BYTE rackNumber)
{
    return &rackReferenceRecord[rackNumber];
}
