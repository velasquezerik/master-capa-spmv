/*-----------------------------------------------------------------------*/
/* Program: utils.h                                                      */
/*                                                                       */
/* Description:                                                          */
/* Some definitions.                                                     */
/*-----------------------------------------------------------------------*/
/* Erik Velasquez                                                        */
/*-----------------------------------------------------------------------*/

#ifndef UTILS_H
#define UTILS_H

/*------------------------ Standard C/C++ Libraries ---------------------*/
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

/*------------------------ Other Libraries ------------------------------*/
/*** EMPTY ***/



/*--------- Constant Definitions ----------------------------------------*/

#define DEFAULT_INPUT "../input/input.txt"

#define DEFAULT_RUNS "../result/"

#define CODE_VERSION "v001"

#define SEPARATOR "-"

#define OUTPUT_EXTENSION ".txt"

#define STR_MAX_SIZE 100

#define MAX_N_INPUT 2000

#define NUM_PLARGE_ELEMENTS 2000000

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
/* function: fReadInputFile                                              */
/*                                                                       */
/* Description:                                                          */
/* Read input file                                                       */
/*-----------------------------------------------------------------------*/
void fReadInputFile(char * fileName, 
                    char arrayInput[MAX_N_INPUT][STR_MAX_SIZE], 
                    int * numInputs);


/*----- End Function Prototypes -----------------------------------------*/

#endif