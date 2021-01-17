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


/*---- End Function Definitions -----------------------------------------*/