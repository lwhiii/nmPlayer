/*
********************************************************************************
*
*      GSM AMR-NB speech codec   R98   Version 7.6.0   December 12, 2001
*                                R99   Version 3.3.0                
*                                REL-4 Version 4.1.0                
*
********************************************************************************
*
*      File             : set_zero.h
*      Description      : Set vector x[] to zero
*
*
********************************************************************************
*/
#ifndef set_zero_h
#define set_zero_h
/*********************************************************************************
*                         INCLUDE FILES
*********************************************************************************/
#include "basic_op.h"
#include "typedef.h"

/*********************************************************************************
*                         PUBLIC PROGRAM CODE
*********************************************************************************/
__voinline void Set_zero (
    Word16 x[],         /* (o)    : vector to clear     */
    Word16 L            /* (i)    : length of vector    */
)
{
   Word32 num = (Word32)L;
   do{
	   *x++ = 0;
   }while(--num !=0);
}
#endif