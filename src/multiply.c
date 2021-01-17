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

/*-----------------------------------------------------------------------*/
/* function: fgetResultMultiplyCOO                                       */
/*                                                                       */
/* Description:                                                          */
/* COO multiply code, timing results                                     */
/*-----------------------------------------------------------------------*/
void fgetResultMultiplyCOO(int nrow, int ncol, int *row, int *col, 
                            double *val, int nnz, double *p, double *q, 
                            double *normalizedTime, double *totalTime)
{
    int r;
    double tic, toc, eTime;
    double nz;

    /* number of non - zeros (average) per row */
    nz = (double)nnz / (double)nrow ;

    /* Warming up */
    fMultiplyCOO(row, col, val, nnz, p, q);

    tic = fGetTime();
    for ( r = 0; r < LOOP_COUNT; r++)
    {
        fMultiplyCOO(row, col, val, nnz, p, q);
    }
    toc = fGetTime();
    /* Get the total execution time */
    eTime = toc - tic;

    /* Get the average execution time */
    *totalTime = ((eTime)/ LOOP_COUNT);

    /* Get normalize Time */
    *normalizedTime = ((eTime)/(nrow*nz*LOOP_COUNT));
    

}


/*-----------------------------------------------------------------------*/
/* function: fgetResultMultiplyMKLCOO                                    */
/*                                                                       */
/* Description:                                                          */
/* MKL multiply code, timing results, COO matrix                         */
/*-----------------------------------------------------------------------*/
void fgetResultMultiplyMKLCOO(int nrow, int ncol, int *row, int *col, 
                            double *val, int nnz, double *p, double *q, 
                            double *normalizedTime, double *totalTime)
{
    int m, n, i, r;
    double tic, toc, eTime;
    double nz;
    double alpha, beta;
    alpha = 1.0; beta = 0.0;

    /* number of non - zeros (average) per row */
    nz = (double)nnz / (double)nrow ;

    /* Warming up */
    // mkl_sparse_d_create_coo (sparse_matrix_t *A, sparse_index_base_t indexing, MKL_INT rows, MKL_INT cols, MKL_INT nnz, MKL_INT *row_indx, MKL_INT * col_indx, double *values);
    sparse_matrix_t A;
    mkl_sparse_d_create_coo(&A, SPARSE_INDEX_BASE_ZERO, nrow, ncol, nnz, row, col, val);
    struct matrix_descr descrA;
    descrA.type = SPARSE_MATRIX_TYPE_GENERAL;
    
    //mkl_sparse_d_mv (const sparse_operation_t operation, const double alpha, const sparse_matrix_t A, const struct matrix_descr descr, const double *x, const double beta, double *y);
    mkl_sparse_d_mv (SPARSE_OPERATION_NON_TRANSPOSE, alpha, A, descrA, p, beta, q);

    tic = fGetTime();
    for ( r = 0; r < LOOP_COUNT; r++)
    {
        mkl_sparse_d_mv (SPARSE_OPERATION_NON_TRANSPOSE, alpha, A, descrA, p, beta, q);

    }
    toc = fGetTime();
    /* Get the total execution time */
    eTime = toc - tic;

    /* Get the average execution time */
    *totalTime = ((eTime)/ LOOP_COUNT);

    /* Get normalize Time */
    *normalizedTime = ((eTime)/(nrow*nz*LOOP_COUNT));

}

/*-----------------------------------------------------------------------*/
/* function: fMultiplyCSR                                                */
/*                                                                       */
/* Description:                                                          */
/* CSR multiply code                                                     */
/*-----------------------------------------------------------------------*/
void fMultiplyCSR(int nrow, int ncol, int *row_off, int *col, double *val, 
                                            int nnz, double *x, double *y)
{
    int i, j, k=0;
    for(i = 0; i < nrow; ++i)
    {
        y[i] = 0.0;
        for(j = row_off[i]; j < row_off[i+1]; ++j)
        {
            y[i] += val[j]*x[col[j]];
        }
    }
}


/*-----------------------------------------------------------------------*/
/* function: fgetResultMultiplyCSR                                       */
/*                                                                       */
/* Description:                                                          */
/* CSR multiply code, timing results                                     */
/*-----------------------------------------------------------------------*/
void fgetResultMultiplyCSR(int nrow, int ncol, int *row_off, int *col, 
                            double *val, int nnz, double *x, double *y, 
                            double *normalizedTime, double *totalTime)
{
    int r;
    double tic, toc, eTime;
    double nz;

    /* number of non - zeros (average) per row */
    nz = (double)nnz / (double)nrow ;

    /* Warming up */
    fMultiplyCSR(nrow, ncol, row_off, col, val, nnz, x, y);

    tic = fGetTime();
    for ( r = 0; r < LOOP_COUNT; r++)
    {
        fMultiplyCSR(nrow, ncol, row_off, col, val, nnz, x, y);
    }
    toc = fGetTime();
    /* Get the total execution time */
    eTime = toc - tic;

    /* Get the average execution time */
    *totalTime = ((eTime)/ LOOP_COUNT);

    /* Get normalize Time */
    *normalizedTime = ((eTime)/(nrow*nz*LOOP_COUNT));
}



/*-----------------------------------------------------------------------*/
/* function: fgetResultMultiplyMKLCSR                                    */
/*                                                                       */
/* Description:                                                          */
/* MKL multiply code, timing results, CSR matrix                         */
/*-----------------------------------------------------------------------*/
void fgetResultMultiplyMKLCSR(int nrow, int ncol, int *row, int *row_off, int *col, 
                            double *val, int nnz, double *p, double *q, 
                            double *normalizedTime, double *totalTime)
{
    int m, n, i, r;
    double tic, toc, eTime;
    double nz;
    double alpha, beta;
    alpha = 1.0; beta = 0.0;

    /* number of non - zeros (average) per row */
    nz = (double)nnz / (double)nrow ;

    /* Warming up */
    sparse_matrix_t A,B;
    mkl_sparse_d_create_coo(&B, SPARSE_INDEX_BASE_ZERO, nrow, ncol, nnz, row, col, val);
    mkl_sparse_convert_csr (B, SPARSE_OPERATION_NON_TRANSPOSE, &A);
    struct matrix_descr descrA;
    descrA.type = SPARSE_MATRIX_TYPE_GENERAL;
    
    //mkl_sparse_d_mv (const sparse_operation_t operation, const double alpha, const sparse_matrix_t A, const struct matrix_descr descr, const double *x, const double beta, double *y);
    mkl_sparse_d_mv (SPARSE_OPERATION_NON_TRANSPOSE, alpha, A, descrA, p, beta, q);

    tic = fGetTime();
    for ( r = 0; r < LOOP_COUNT; r++)
    {
        mkl_sparse_d_mv (SPARSE_OPERATION_NON_TRANSPOSE, alpha, A, descrA, p, beta, q);

    }
    toc = fGetTime();
    /* Get the total execution time */
    eTime = toc - tic;

    /* Get the average execution time */
    *totalTime = ((eTime)/ LOOP_COUNT);

    /* Get normalize Time */
    *normalizedTime = ((eTime)/(nrow*nz*LOOP_COUNT));

}

/*-----------------------------------------------------------------------*/
/* function: fMultiplyCSR_OMP                                            */
/*                                                                       */
/* Description:                                                          */
/* CSR multiply code, with omp                                           */
/*-----------------------------------------------------------------------*/
void fMultiplyCSR_OMP(int nrow, int ncol, int *row_off, int *col, double *val, 
                                            int nnz, double *x, double *y)
{
    int i, j, k=0;
    #pragma omp parallel for
    for(i = 0; i < nrow; ++i)
    {
        y[i] = 0.0;
        for(j = row_off[i]; j < row_off[i+1]; ++j)
        {
            y[i] += val[j]*x[col[j]];
        }
    }
}

/*-----------------------------------------------------------------------*/
/* function: fgetResultMultiplyCSR_OMP                                   */
/*                                                                       */
/* Description:                                                          */
/* CSR multiply code, timing results, with omp                           */
/*-----------------------------------------------------------------------*/
void fgetResultMultiplyCSR_OMP(int nrow, int ncol, int *row_off, int *col, 
                            double *val, int nnz, double *x, double *y, 
                            double *normalizedTime, double *totalTime)
{
    int r;
    double tic, toc, eTime;
    double nz;

    /* number of non - zeros (average) per row */
    nz = (double)nnz / (double)nrow ;

    /* Warming up */
    fMultiplyCSR_OMP(nrow, ncol, row_off, col, val, nnz, x, y);

    tic = fGetTime();
    for ( r = 0; r < LOOP_COUNT; r++)
    {
        fMultiplyCSR_OMP(nrow, ncol, row_off, col, val, nnz, x, y);
    }
    toc = fGetTime();
    /* Get the total execution time */
    eTime = toc - tic;

    /* Get the average execution time */
    *totalTime = ((eTime)/ LOOP_COUNT);

    /* Get normalize Time */
    *normalizedTime = ((eTime)/(nrow*nz*LOOP_COUNT));
}

/*---- End Function Definitions -----------------------------------------*/
