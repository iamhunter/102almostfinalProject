//Andrew Hunter
//CPSC 102

/**  vector.c   **/

#include "vector.h"

/*  This file contains function definitions for    */
/*  for 3D vector operations                       */

/* Compute the sum of two vectors */
/* v3 = v2 + v1; */
void vec_sum(
vec_t *v1,   /* addend */
vec_t *v2,   /* addend */
vec_t *v3)   /* result */
{

    v3->x = v1->x + v2->x;
    v3->y = v1->y + v2->y;
    v3->z = v1->z + v2->z;
    
}

/* Compute the difference of two vectors */
/* v3 = v2 - v1 */
void vec_diff(
vec_t *v1,   /* subtrahend */
vec_t *v2,   /* minuend    */
vec_t *v3)   /* result     */
{

    v3->x = v2->x - v1->x;
    v3->y = v2->y - v1->y;
    v3->z = v2->z - v1->z;
    
}

/* Compute the componentwise product of two vectors */
/* v3 = v2 * v1; */
void vec_mult( 
vec_t *v1,   /* Input vector 1 */
vec_t *v2,   /* Input vector 2 */
vec_t *v3)   /* result         */
{
   
    v3->x = v2->x * v1->x;
    v3->y = v2->y * v1->y;
    v3->z = v2->z * v1->z;

}

/* Return the (dot) inner product of two input vectors     */
double vec_dot(
vec_t *v1,   /* Input vector 1 */
vec_t *v2)   /* Input vector 2 */
{
    return (v1->x * v2->x) + (v1->y * v2->y) + (v1->z * v2->z);
    
}

/* Return length of a 3d vector */
double vec_len(
vec_t *v1)  /* Vector whose length is desired */
{
    return sqrt(vec_dot(v1, v1));

}

/* Scale a 3d vector by multiplying each element by scale factor */
void vec_scale(
double fact,   /* Scale factor */
vec_t *v1,      /* Input vector */
vec_t *v2)      /* Output vector */
{
    v2->x = v1->x * fact;
    v2->y = v1->y * fact;
    v2->z = v1->z * fact;
    
}

/* Construct a unit vector v2 in direction of input vector v1 */
void vec_unit(
vec_t *v1,    /* Input vector      */
vec_t *v2)    /* output unit vec   */
{
    
    vec_scale((1.0 / vec_len(v1)), v1, v2);

   
}

/* Copy vector v1 to v2 another */
void vec_copy(
vec_t *v1,   /* input vector */
vec_t *v2)   /* output vector */
{
    v2->x = v1->x;
    v2->y = v1->y;
    v2->z = v1->z;

}

/* Read in values of vector from file */
/* Return the # of items read	*/
int vec_read(
FILE *in,     /* input file  */
vec_t *v1)    /* vector from input file */
{
    
    return fscanf(in, "%lf %lf %lf \n", &v1->x, &v1->y, &v1->z);
    
}

/* Print values of vector to file */
void vec_print(
FILE *out,     /* output file */
char *label,   /* label string */
vec_t *v1)      /* vector to print */
{
    
    fprintf(out, "%s %8.3lf %8.3lf %8.3lf \n", label, v1->x, v1->y, v1->z);
    

}
