/*
********************************************************************************
*
*      GSM AMR-NB speech codec   R98   Version 7.6.0   December 12, 2001
*                                R99   Version 3.3.0                
*                                REL-4 Version 4.1.0                
*
********************************************************************************
*
*      File             : gmed_n.c
*      Purpose          : calculates N-point median.
*
********************************************************************************
*/
/*
********************************************************************************
*                         MODULE INCLUDE FILE AND VERSION ID
********************************************************************************
*/
#include "gmed_n.h"

/*
********************************************************************************
*                         INCLUDE FILES
********************************************************************************
*/
#include <stdlib.h>
#include <stdio.h>
#include "typedef.h"
#include "basic_op.h"

/*
********************************************************************************
*                         LOCAL VARIABLES AND TABLES
********************************************************************************
*/

#define NMAX 9  /* largest N used in median calculation */

/*
********************************************************************************
*                         PUBLIC PROGRAM CODE
********************************************************************************
*/
/*************************************************************************
*
*  FUNCTION:   gmed_n
*
*  PURPOSE:    calculates N-point median.
*
*  DESCRIPTION:
*             
*************************************************************************/
Word16 voAMRNBEnc_gmed_n (   /* o : index of the median value (0...N-1)      */
			   Word16 ind[], /* i : Past gain values                         */
			   Word16 n      /* i : The number of gains; this routine is only valid for a odd number of gains n <= NMAX) */
			   )
{
	int    i, j, ix = 0;
	Word16 max;
	Word16 medianIndex;
	Word16 tmp[NMAX];
	Word16 tmp2[NMAX];

	for (i = 0; i < n; i++)
	{
		tmp2[i] = ind[i]; 
	}

	for (i = 0; i < n; i++)
	{
		max = -32767;              
		for (j = 0; j < n; j++)
		{
			if(tmp2[j] >= max)
			{
				max = tmp2[j];                           
				ix = j;                                       
			}
		}
		tmp2[ix] = -32768;                                     
		tmp[i] = ix;                                         
	}
	medianIndex=tmp[n>>1];           /* account for complex addressing */
	return (ind[medianIndex]);                                     
}