/*-----------------------------------------------------------------------*/
/* Program: main.c                                                       */
/*                                                                       */
/* Description:                                                          */
/* This program execute test for matrix multiplication code in C.        */
/*-----------------------------------------------------------------------*/
/* Erik Velasquez                                                        */
/*-----------------------------------------------------------------------*/

/*------------------------ Standard C/C++ Libraries ---------------------*/
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <math.h>

/*------------------------ Other Libraries ------------------------------*/
/* Get Time Libraries */
#include "gtime.h"

/* Utility Libraries */
#include "utils.h"

/* Matrix Market Libraries */
#include "mmio.h"


/*-------------------------------------------------------------------------
*                             Main Function
*------------------------------------------------------------------------*/
int main(int argc, char ** argv)
{
    /*----------------------Variables declaration------------------------*/

    char inputFileName[STR_MAX_SIZE];
    char arrayInput[MAX_N_INPUT][STR_MAX_SIZE];
    int numInputs;
    int i, j;
    int nArray;
    double * pLarge;
    double * qLarge;
    int nNz;
    int nRow, *indRow;
    int nCol, *indCol;
    double nz;
    double * val;
    int ret_code;
    MM_typecode matcode;
    FILE *f;

    /*--------------------- End of variables declaration ----------------*/

    /*-------------------------- Verify Input ---------------------------*/

    if (argc == 2)
    {
        strcpy(inputFileName, argv[1]);
        printf ( "Using input: %s\n" ,inputFileName);
    }
    else
    {
        strcpy(inputFileName, DEFAULT_INPUT);
        printf ("Using default input: %s\n" ,inputFileName);
    }

    /*------------------------ End Verify Input -------------------------*/

    /*--------------------- Variables initialization --------------------*/

    numInputs = 0;
    i = 0;
    nArray = NUM_PLARGE_ELEMENTS*sizeof(double);
    nNz = 0;
    nz = 0;
    nRow = 0;
    nCol = 0;

    /*------------------End of Variables initialization------------------*/

    /*-------------------------- Reserve Memmory ------------------------*/

    pLarge = (double*)_mm_malloc(nArray, sizeof(double));
    qLarge = (double*)_mm_malloc(nArray, sizeof(double));
    memset(pLarge, 0, nArray );
    memset(qLarge, 0, nArray );

    /*----------------------- End Reserve Memmory -----------------------*/
 
    /*-------------------------- Main Code ------------------------------*/
    
    // read input file
    fReadInputFile(inputFileName, arrayInput, &numInputs);

    printf("Number of matrix files: %d\n", numInputs);


    for (i = 0; i < numInputs; i++)
    {
        printf("Executing Matrix %s, please wait ...\n", arrayInput[i]);

        if ((f = fopen(arrayInput[i], "r")) == NULL)
        {
            return EXIT_FAILURE;

        }
        else
        {
            if (mm_read_banner(f, &matcode) != 0)
            {
                printf("Could not process Matrix Market banner.\n");
                return EXIT_FAILURE;
            }

            /*  only supports a subset of the Matrix Market data types.  */
            if (mm_is_complex(matcode) && mm_is_matrix(matcode) 
                                                && mm_is_sparse(matcode) )
            {
                printf("Sorry, this application does not support ");
                printf("Market Market type: [%s]\n", mm_typecode_to_str(matcode));
                return EXIT_FAILURE;
            }

            /* find out size of sparse matrix .... */
            if ((ret_code = mm_read_mtx_crd_size(f, &nRow, &nCol, &nNz)) !=0)
            {
                return EXIT_FAILURE;
            }

            /* reseve memory for matrices */
            indRow = (int *) _mm_malloc(nNz * sizeof(int), sizeof(double));
            indCol = (int *) _mm_malloc(nNz * sizeof(int), sizeof(double));
            val = (double *) _mm_malloc(nNz * sizeof(double), sizeof(double));
    /* NOTE: when reading in doubles, ANSI C requires the use of the "l"  */
    /*   specifier as in "%lg", "%lf", "%le", otherwise errors will occur */
    /*  (ANSI C X3.159-1989, Sec. 4.9.6.2, p. 136 lines 13-15)            */
            for (j=0; j<nNz; j++)
            {
                fscanf(f, "%d %d %lg\n", &indRow[j], &indCol[j], &val[j]);
                indRow[j]--;  /* adjust from 1-based to 0-based */
                indCol[j]--;
            }

            fclose(f);

        }

        /************************/
        /* now write out matrix */
        /************************/
        mm_write_banner(stdout, matcode);
        printf("Matrix %s, Rows=%i, Cols=%i, NNZ=%i ...\n", arrayInput[i], 
                                                        nCol, nRow, nNz);

        _mm_free(indRow);
        _mm_free(indCol);
        _mm_free(val);

    }

    /*-------------------------- End Main Code --------------------------*/

    /*-------------------------- Free Memmory ---------------------------*/

    _mm_free(pLarge);
    _mm_free(qLarge);

    /*------------------------ End Free Memmory -------------------------*/

    return EXIT_SUCCESS;
}
/*-------------------------------------------------------------------------
*                        END OF MAIN FUNCTION                        
*------------------------------------------------------------------------*/