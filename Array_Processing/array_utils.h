/*
 * Author: Kok Hwa Khor
 * Date: 10/25/2019
 *
 * This file contain the source codes of function prototypes
 */

//This function takes two integer arrays and determines if they are equal
int isEqual(const int *a, const int *b, int size);

//This function takes an integer array and reverses its contents
int reverse(int *a, int size);

//This function takes an integer array and creates and returns
//a new copy with the contents reversed
int * reverseCopy(const int *a, int size);

//This function shift the contents of the integer array by integer k
int shift(int *a, int size, int k);

//This function shift the contents of the integer array by integer k
// and creates a copy of the array
int * shiftCopy(const int *a, int size, int k);

//This function takes an integer array and returns a new array
//containing only the even elements
int * getEvens(const int *a, int size, int *newSize);

//This function takes an array of n elements and produces an nxn
//circulant matrix in which the subsequent row are shifted by
//one position
int ** circulant(const int *a, int size);

//This function "collapes" an n x m matrix into an array of size main
//by summing all elements in each column
int * collapse(int **A, int n, int m);
