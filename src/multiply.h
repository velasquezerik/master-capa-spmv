/*-----------------------------------------------------------------------*/
/* Program: multiply.h                                                   */
/*                                                                       */
/* Description:                                                          */
/* This program execute the matrix multiplication code in C.             */
/*-----------------------------------------------------------------------*/
/* Erik Velasquez                                                        */
/*-----------------------------------------------------------------------*/

#ifndef MULTIPLY_H
#define MULTIPLY_H

/*------------------------ Standard C/C++ Libraries ---------------------*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <sys/time.h>
#include <string.h>

/*------------------------ Other Libraries ------------------------------*/
/* Utility Libraries */
#include "utils.h"

/* Get Time Libraries */
#include "gtime.h"


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
/* function: fMultiplyCOO                                                */
/*                                                                       */
/* Description:                                                          */
/* COO multiply code                                                     */
/*-----------------------------------------------------------------------*/
void fMultiplyCOO(int *row, int *col, double *val, int nnz, double *p, 
                                                            double *q);



/*----- End Function Prototypes -----------------------------------------*/

#endif
