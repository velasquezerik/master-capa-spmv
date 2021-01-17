/*-----------------------------------------------------------------------*/
/* Program: multiply.c                                                   */
/*                                                                       */
/* Description:                                                          */
/* This program execute the matrix multiplication code in C.             */
/*-----------------------------------------------------------------------*/
/* Erik Velasquez                                                        */
/*-----------------------------------------------------------------------*/

/*------------------------ Standard C/C++ Libraries ---------------------*/
/*** EMPTY ***/

/*------------------------ Other Libraries ------------------------------*/
/* Multiply Libraries */
#include "multiply.h"



/*---- Function Definitions ---------------------------------------------*/


/*-----------------------------------------------------------------------*/
/* function: fMultiplyCOO                                                */
/*                                                                       */
/* Description:                                                          */
/* COO multiply code                                                     */
/*-----------------------------------------------------------------------*/
void fMultiplyCOO(int *row, int *col, double *val, int nnz, double *p, 
                                                            double *q)
{
    int i;
    for(i = 0; i < nnz ; i++)
    {
        q[row[i]] += val[i] * p[col[i]];
    }  

}






/*---- End Function Definitions -----------------------------------------*/
