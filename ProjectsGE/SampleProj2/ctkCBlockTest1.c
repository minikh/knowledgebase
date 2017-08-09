#include "copyright.h"
/*************************************************************************
 * Module $Id: ctkCBlockTest1.c,v 1.10 2006/10/19 18:12:43 cas Exp $
 *************************************************************************/
/******************************************************************************
`ModuleName ctkCBlockTest1.c
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
extern void ctkCBlockTest2(void);

/* Routines */
void testFunction(void)
{
    T_INT32 numBytes = 0;
    char buffer[100];
    numBytes = sprintf(buffer, "test function called \r\n");
    PLCC_MessageWrite(PORT1, buffer, numBytes);
}

int cmpfunc(const void *__e1, const void *__e2)
{
    return 0;
}

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
    char buffer[100] = "This is my buffer";
    double x = 1;
    double y = 2;
    double result;
    int exponent = 100;
    int __exp = 1;
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
    float resultFloat;
    T_INT32 numBytes = 0;
    T_INT32 numBytesInQ = 0;

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

    /* If message mode is supported
           Make sure write message queue is empty 
                   before continuing because
                   the next section will write
                   status to the serial port */
    if (PLCC_CharsInMessageWriteQ(PORT1) != GEF_ERROR)
    {
        while (PLCC_CharsInMessageWriteQ(PORT1) != 0)
        {
        }
    }
    /* test making a call to a user function */
    testFunction();
    /* stdio.h  functions */
    sprintf (buffer, "This is my buffer \r\n");

    /* Message Mode Read/Write Functions */
    numBytesInQ = PLCC_CharsInMessageWriteQ(0);
    numBytes = sprintf(buffer, "Test of PLCC_MessageWrite \r\n");
    PLCC_MessageWrite(PORT1, buffer, numBytes);

    numBytesInQ = PLCC_CharsInMessageReadQ(0);
    numBytes = PLCC_MessageRead(0, buffer, numBytesInQ);

    numBytes = sprintf(buffer, "math.h functions \r\n");
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

    numBytes = sprintf(buffer, "stdlib.h functions \r\n");
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

    numBytes = sprintf(buffer, "string.h functions \r\n");
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

    numBytes = sprintf(buffer, "time.h functions \r\n");
    PLCC_MessageWrite(PORT1, buffer, numBytes);

    /* time.h functions */
    resultInt = strftime (__s1, _n, _format,
		   	          &_tmstruct);
    resultInt = asctime_r(&_tmstruct, _buffer,
			         &_buflen);
    result = difftime (_t1, _t0);

    numBytes = sprintf(buffer, "ctype.h functions \r\n");
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

    resultInt =       tolower( 'D');
    resultInt =       toupper( 'd');
    
    numBytes = sprintf(buffer, "calling ctkCBlockTest2 \r\n");
    PLCC_MessageWrite(PORT1, buffer, numBytes);

    ctkCBlockTest2();

    numBytes = sprintf(buffer, "end of GefMain \r\n");
    PLCC_MessageWrite(PORT1, buffer, numBytes);

    return GEF_EXECUTION_OK;
}

void ctkCBlockTest1(void)
{

    char buffer[100];
    T_INT32 numBytes = 0;
    numBytes = sprintf(buffer, "ctkCBlockTest1 executing \r\n");
    PLCC_MessageWrite(PORT1, buffer, numBytes);

}









