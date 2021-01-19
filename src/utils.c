/*-----------------------------------------------------------------------*/
/* Program: utils.c                                                      */
/*                                                                       */
/* Description:                                                          */
/* Some definitions.                                                     */
/*-----------------------------------------------------------------------*/
/* Erik Velasquez                                                        */
/*-----------------------------------------------------------------------*/

/*------------------------ Standard C/C++ Libraries ---------------------*/
/*** EMPTY ***/

/*------------------------ Other Libraries ------------------------------*/
/* Utility Libraries */
#include "utils.h"



/*---- Function Definitions ---------------------------------------------*/

/*-----------------------------------------------------------------------*/
/* function: fReadInputFile                                              */
/*                                                                       */
/* Description:                                                          */
/* Read input file                                                       */
/*-----------------------------------------------------------------------*/
void fReadInputFile(char * fileName, 
                    char arrayInput[MAX_N_INPUT][STR_MAX_SIZE], 
                    int * numInputs)
{
    FILE * fp;
    char * line = NULL;
    size_t len = 0;
    ssize_t read;

    fp = fopen(fileName, "r");
    if (fp == NULL)
    {
        return;
    }
    else
    {
        *numInputs = 0;
        while ( ((read = getline(&line, &len, fp)) != -1) 
                                            && (*numInputs < MAX_N_INPUT)) 
        {
            char *pos;
            if ((pos=strchr(line, '\n')) != NULL)
                *pos = '\0';
            strcpy(arrayInput[*numInputs], line);
            *numInputs += 1;
        }
        fclose(fp);
        if (line)
        {
            free(line);
        }
    }

}

/*-----------------------------------------------------------------------*/
/* function: fRand                                                       */
/*                                                                       */
/* Description:                                                          */
/* generate random number between fMin and fMax                          */
/*-----------------------------------------------------------------------*/
double fRand(double fMin, double fMax)
{
    double f = (double)rand() / RAND_MAX;
    return fMin + f * (fMax - fMin);
}


/*-----------------------------------------------------------------------*/
/* function: fgeneratePLarge                                             */
/*                                                                       */
/* Description:                                                          */
/* generate random pLarge                                                */
/*-----------------------------------------------------------------------*/
void fgeneratePLarge(double * pLarge)
{
    int i = 0;
    for (i = 0; i < NUM_PLARGE_ELEMENTS; i++)
    {
        pLarge[i] = fRand(randMinValue, randMaxValue);
    }

}

/*-----------------------------------------------------------------------*/
/* function: fwriteOutputResultFile                                      */
/*                                                                       */
/* Description:                                                          */
/* Write Output Result file                                              */
/*-----------------------------------------------------------------------*/
void fwriteOutputResultFile(char * fileName, 
                    char arrayInput[MAX_N_INPUT][STR_MAX_SIZE], 
                    int * numInputs, 
                    double *coo_normalizeTimeResult, double *coo_totalTimeResult,
                    double *coomkl_normalizeTimeResult, double *coomkl_totalTimeResult,
                    double *csr_normalizeTimeResult, double *csr_totalTimeResult,
                    double *csromp_normalizeTimeResult, double *csromp_totalTimeResult,
                    double *csrmkl_normalizeTimeResult, double *csrmkl_totalTimeResult)
{

    FILE * fp;
    int i;
    fp = fopen(fileName, "w");
    if (fp == NULL)
    {
        return;
    }
    else
    {
        fprintf(fp, "MatrixName,N-COO,T-COO,N-COOMKL,T-COOMKL,N-CSR,T-CSR,N-CSROMP,T-CSROMP,N-CSRMKL,T-CSRMKL\n");
        for (i = 0; i < *numInputs; i++)
        {
            fprintf(fp, "%s,%.15lf,%.15lf,%.15lf,%.15lf,%.15lf,%.15lf,%.15lf,%.15lf,%.15lf,%.15lf\n",
                                arrayInput[i],
                                coo_normalizeTimeResult[i], coo_totalTimeResult[i],
                                coomkl_normalizeTimeResult[i], coomkl_totalTimeResult[i],
                                csr_normalizeTimeResult[i], csr_totalTimeResult[i],
                                csromp_normalizeTimeResult[i], csromp_totalTimeResult[i],
                                csrmkl_normalizeTimeResult[i], csrmkl_totalTimeResult[i]
                                );
        }
        fclose(fp);
    }

}


/*---- End Function Definitions -----------------------------------------*/