/*-----------------------------------------------------------------------*/
/* Program: gtime.c                                                      */
/*                                                                       */
/* Description:                                                          */
/* This program get the system time, code in C.                          */
/* A gettimeofday routine to give access to the wall                     */
/* clock timer on most UNIX-like systems.                                */
/*-----------------------------------------------------------------------*/
/* Erik Velasquez                                                        */
/*-----------------------------------------------------------------------*/

/*------------------------ Standard C/C++ Libraries ---------------------*/
/*** EMPTY ***/

/*------------------------ Other Libraries ------------------------------*/
/* Get Time Libraries */
#include "gtime.h"


/*---- Function Definitions ---------------------------------------------*/

/*-----------------------------------------------------------------------*/
/* function: fGetTime                                                    */
/*                                                                       */
/* Description:                                                          */
/* This program get the system time, code in C.                          */
/* A gettimeofday routine to give access to the wall                     */
/* clock timer on most UNIX-like systems.                                */
/*-----------------------------------------------------------------------*/
double fGetTime()
{
    struct timeval tp;
    struct timezone tzp;
    int i;

    i = gettimeofday(&tp,&tzp);
    return ( (double) tp.tv_sec + (double) tp.tv_usec * 1.e-6 ) ;
}


/*---- End Function Definitions -----------------------------------------*/