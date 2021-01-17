/*-----------------------------------------------------------------------*/
/* Program: gtime.h                                                      */
/*                                                                       */
/* Description:                                                          */
/* This program get the system time, code in C.                          */
/* A gettimeofday routine to give access to the wall                     */
/* clock timer on most UNIX-like systems.                                */
/*-----------------------------------------------------------------------*/
/* Erik Velasquez                                                        */
/*-----------------------------------------------------------------------*/

#ifndef GTIME_H
#define GTIME_H

/*------------------------ Standard C/C++ Libraries ---------------------*/
#include <sys/time.h>


/*------------------------ Other Libraries ------------------------------*/
/*** EMPTY ***/



/*--------- Constant Definitions ----------------------------------------*/

/*** EMPTY ***/

/*-------- End Constant Definitions -------------------------------------*/



/*----- Macros ----------------------------------------------------------*/

/*** EMPTY ***/

/*--- End Macros --------------------------------------------------------*/



/*----- Variables -------------------------------------------------------*/

/*** EMPTY ***/

/*----- End Variables ---------------------------------------------------*/



/*---- Datatypes --------------------------------------------------------*/

/*** EMPTY ***/

/*------ End Datatypes --------------------------------------------------*/



/*---- Function Definitions ---------------------------------------------*/

/*** EMPTY ***/

/*---- End Function Definitions -----------------------------------------*/



/*---- Function Prototypes ----------------------------------------------*/

/*-----------------------------------------------------------------------*/
/* function: fGetTime                                                    */
/*                                                                       */
/* Description:                                                          */
/* This program get the system time, code in C.                          */
/* A gettimeofday routine to give access to the wall                     */
/* clock timer on most UNIX-like systems.                                */
/*-----------------------------------------------------------------------*/
double fGetTime();

/*----- End Function Prototypes -----------------------------------------*/

#endif