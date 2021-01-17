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

/*---- End Function Definitions -----------------------------------------*/