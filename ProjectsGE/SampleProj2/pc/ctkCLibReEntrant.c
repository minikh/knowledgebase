#include "copyright.h"
/*************************************************************************
 * Module $Id: ctkCLibReEntrant.c,v 1.4 2005/06/30 14:51:21 cas Exp $
 *************************************************************************/
/******************************************************************************
`ModuleName ctkCLibReentrant.c
` This file contains implementations of C run time re-entrant functions
` which are used when the user's application is being debugged on the PC. 
`
*******************************************************************************/
/* Uncomment "#define UNIT_TEST" line to enable unit test code */
/* #define UNIT_TEST */
/* `IncludeFiles */
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>  /* for swab */

#ifndef UNIT_TEST
#include "ctkCLibReEntrant.h"
#include "PACRXPlc.h"
#endif /* UNIT_TEST */
/* Constants / #defines  */
#ifdef UNIT_TEST
#define MAX_ASC_TIME_BUFFER 28 /* size of buffer needed for asctime_r */
#endif /* UNIT_TEST */

/* Structures and typedefs */

/* Declarations for Global variables */

/* Declarations for Local variables */
/* Forward declarations */
/* Routines */
/* stdlib.h functions */
void 	uswab (char *source, char *destination, int nbytes)
{
    swab(source, destination, nbytes);
}

/******************************************************************************
`Proc div_r
` See description of function in ctkCLibReentrant.h
*******************************************************************************/
#ifdef UNIT_TEST
void div_r_ut
#else
void     div_r 
#endif /* UNIT_TEST */
               (int numerator, int denominator, div_t * divStructPtr)
{
    /* using non-reentrant form since this is only for PC debug */
    *divStructPtr = div(numerator, denominator);
}

/* string.h functions */
/******************************************************************************
`Proc strerror_r
` See description of function in ctkCLibReentrant.h
*******************************************************************************/
#ifdef UNIT_TEST
int	strerror_r_ut
#else
int	strerror_r 
#endif /* UNIT_TEST */
            (int __errcode, char *__buf)
{
    int status = GEF_OK;
    /* using non-reentrant form since this is only for PC debug */
    *__buf = *strerror(__errcode);
    return status;
}
/******************************************************************************
`Proc strtok_r
` See description of function in ctkCLibReentrant.h
*******************************************************************************/
#ifdef UNIT_TEST
char *	strtok_r_ut
#else
char *	strtok_r 
#endif /* UNIT_TEST */
                (char *__s, const char *__sep, char **__ppLast)
{
    /* using non-reentrant form since this is only for PC debug */
    return strtok(__s, __sep);
}            


/* time.h functions */
/******************************************************************************
`Proc asctime_r
` See description of function in ctkCLibReentrant.h
*******************************************************************************/
#ifdef UNIT_TEST
int  asctime_r_ut
#else
int  asctime_r 
#endif /* UNIT_TEST */
              (const struct tm *_tm, char *_buffer, size_t *_buflen)
{
    int returnValue;
    if (*_buflen <= MAX_ASC_TIME_BUFFER)
    {
        memcpy(_buffer, asctime(_tm), *_buflen);
        returnValue = *_buflen;
    }
    else
    {
        memcpy(_buffer, asctime(_tm), MAX_ASC_TIME_BUFFER);
        returnValue = MAX_ASC_TIME_BUFFER;
    }
    return returnValue;
}        

/*******************************************************************************/

#ifdef UNIT_TEST
void ctkCLibReEntrantTest(void)
{
    int numerator = 100;
    int denominator = 50;
    div_t divStruct;
    int resultInt;
    int __errcode = -1;
    char __buf[100];
    char *resultCharPtr;
    char __s[] = "This is my first token^And this is my second token^third token";
    char __sep[] = "^";
    char *pLast;
    struct tm _tm;
    char _buffer[100];
    size_t _buflen = 100;

    _tm.tm_sec = 52;
    _tm.tm_min = 03;
    _tm.tm_hour = 01;
    _tm.tm_mday = 16;
    _tm.tm_mon = 9;
    _tm.tm_wday = 7;
    _tm.tm_isdst = 1;
    _tm.tm_yday = 100;
    _tm.tm_year = 02;
    div_r_ut (numerator, denominator, &divStruct);
    resultInt = strerror_r_ut (__errcode, __buf);
    resultCharPtr = strtok_r_ut (__s, __sep, &pLast);
    resultCharPtr = strtok_r_ut (NULL, __sep, &pLast);
    resultInt = asctime_r_ut(&_tm, _buffer, &_buflen);
}
#endif /* UNIT_TEST */        

