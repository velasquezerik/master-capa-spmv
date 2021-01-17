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

/* MKL Libraries */
#include "mkl.h"
#include "mkl_spblas.h"


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
void fMultiplyCOO(int *row, int *col, double *val, 
                                            int nnz, double *p, double *q);

/*-----------------------------------------------------------------------*/
/* function: fgetResultMultiplyCOO                                       */
/*                                                                       */
/* Description:                                                          */
/* COO multiply code, timing results                                     */
/*-----------------------------------------------------------------------*/
void fgetResultMultiplyCOO(int nrow, int ncol, int *row, int *col, 
                            double *val, int nnz, double *p, double *q, 
                            double *normalizedTime, double *totalTime);


/*-----------------------------------------------------------------------*/
/* function: fgetResultMultiplyMKLCOO                                    */
/*                                                                       */
/* Description:                                                          */
/* MKL multiply code, timing results, COO matrix                         */
/*-----------------------------------------------------------------------*/
void fgetResultMultiplyMKLCOO(int nrow, int ncol, int *row, int *col, 
                            double *val, int nnz, double *p, double *q, 
                            double *normalizedTime, double *totalTime);


/*-----------------------------------------------------------------------*/
/* function: fMultiplyCSR                                                */
/*                                                                       */
/* Description:                                                          */
/* CSR multiply code                                                     */
/*-----------------------------------------------------------------------*/
void fMultiplyCSR(int nrow, int ncol, int *row_off, int *col, double *val, 
                                            int nnz, double *x, double *y);



/*-----------------------------------------------------------------------*/
/* function: fgetResultMultiplyCSR                                       */
/*                                                                       */
/* Description:                                                          */
/* CSR multiply code, timing results                                     */
/*-----------------------------------------------------------------------*/
void fgetResultMultiplyCSR(int nrow, int ncol, int *row_off, int *col, 
                            double *val, int nnz, double *x, double *y, 
                            double *normalizedTime, double *totalTime);


/*-----------------------------------------------------------------------*/
/* function: fgetResultMultiplyMKLCSR                                    */
/*                                                                       */
/* Description:                                                          */
/* MKL multiply code, timing results, CSR matrix                         */
/*-----------------------------------------------------------------------*/
void fgetResultMultiplyMKLCSR(int nrow, int ncol, int *row, int *row_off, int *col, 
                            double *val, int nnz, double *p, double *q, 
                            double *normalizedTime, double *totalTime);


/*-----------------------------------------------------------------------*/
/* function: fMultiplyCSR_OMP                                            */
/*                                                                       */
/* Description:                                                          */
/* CSR multiply code, with omp                                           */
/*-----------------------------------------------------------------------*/
void fMultiplyCSR_OMP(int nrow, int ncol, int *row_off, int *col, double *val, 
                                            int nnz, double *x, double *y);


/*-----------------------------------------------------------------------*/
/* function: fgetResultMultiplyCSR_OMP                                   */
/*                                                                       */
/* Description:                                                          */
/* CSR multiply code, timing results, with omp                           */
/*-----------------------------------------------------------------------*/
void fgetResultMultiplyCSR_OMP(int nrow, int ncol, int *row_off, int *col, 
                            double *val, int nnz, double *x, double *y, 
                            double *normalizedTime, double *totalTime);


/*----- End Function Prototypes -----------------------------------------*/

#endif
