/*
 * Author: Kok Hwa Khor
 * Date: 10/25/2019
 *
 * This file contain the source codes of several functions
 * that operate on arrays.
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "array_utils.h"

int isEqual(const int *a, const int *b, int size) {

  //error checking
  if (a == NULL || b == NULL) {
    return 2;
  }

  if (size <= 0) {
    return 2;
  }

  //for loop to check if the the numbers are not equal, exit
  for (int i = 0; i < size; i++) {
    if (a[i] != b[i]) {
      return 0;
    }
  }
  return 1;
}

int reverse(int *a, int size) {

  //error checking
  if (a == NULL) {
    return 1;
  }

  if (size <= 0) {
    return 1;
  }

  int last = size-1;
  int temp = 0;
  //for loop to swap the values from the front to the back
  for (int i = 0; i < size/2; i++) {
    temp = a[i];
    a[i] = a[last];
    a[last] = temp;
    last--;
  }
  return 0;
}

int * reverseCopy(const int *a, int size) {

  //error checking
  if (a == NULL) {
    return NULL;
  }

  if (size <= 0) {
    return NULL;
  }

  //Creating a dynamic array to make a copy of the reversed array
  int *cReverse = (int *) malloc(size * sizeof(int));
  //for loop to make a copy the array
  for (int i = 0; i < size; i++){
    cReverse[i] = a[i];
  }
  //calling the reverse function to reverse the content of the array
  reverse(cReverse, size);

  return cReverse;
}

int shift(int *a, int size, int k) {

  //error checking
  if (a == NULL) {
    return 1;
  }

  if (size <= 0 || k < 0) {
    return 1;
  }

  //creating a temporary dynamic array to arrange and shift the array
  int *tempK = (int *) malloc(size * sizeof(int));

  //copy the value starting from k
  for (int i = 0; i < k; i++) {
    tempK[i] = a[size - k + i];
  }
  //copy the value from the start up to k
  for (int i = 0; i < size - k; i++) {
    tempK[i+k] = a[i];
  }
  //copying the shifted array back to the original array
  for (int i = 0; i < size; i++) {
    a[i] = tempK[i];
  }

  return 0;
}

int * shiftCopy(const int *a, int size, int k) {
  //error checking
  if (a == NULL) {
    return NULL;
  }

  if (size <= 0 || k < 0) {
    return NULL;
  }

  //creating a dynamic array to copy the shifted array
  int *cShift = (int *) malloc(size * sizeof(int));
  //for loop to make a copy of the array
  for (int i = 0; i < size; i++) {
    cShift[i] = a[i];
  }
  //calling the shift function to shift the value of the array
  shift(cShift, size, k);

  return cShift;
}

int * getEvens(const int *a, int size, int *newSize) {
  //error checking
  if (a == NULL || newSize == NULL) {
    return NULL;
  }

  if (size <= 0) {
    return NULL;
  }

  int evenSize = 0;
  //for loop to check if the value is divisible by two
  for (int i = 0; i < size; i++) {
    if (a[i] % 2 == 0) {
      evenSize++;
    }
  }

  //assigning the value of the new size array
  *newSize = evenSize;

  //creating a dynamic array for the array with even values
  int *newArray = (int *) malloc(*newSize * sizeof(int));

  int length = 0;
  //for loop to assign the even values to the array
  for (int i = 0; i < size; i++) {
    if (a[i] % 2 == 0) {
      newArray[length] = a[i];
      length++;
    }
  }
  return newArray;
}

int ** circulant(const int *a, int size) {
  //error checking
  if (a == NULL) {
    return NULL;
  }

  if (size <= 0) {
    return NULL;
  }

  //Creating a 2D dynamic array of size x size
  int ** array = (int **) malloc(size * sizeof(int *));
  for (int i = 0; i < size; i++) {
    array[i] = (int *) malloc(size * sizeof(int));
  }

  //Creating a dynamic array
  int * copy = (int *) malloc(size * sizeof(int *));
  //Make a copy for of the original array
  for (int i = 0; i < size; i++) {
    copy[i] = a[i];
  }
  int k = 0;
  //Assigning the value of the array with each row shifted by 1
  for (int i = 0; i < size; i++) {
    for (int j = 0; j < size; j++) {
      array[i][j] = copy[j];
    }
    //calling the shift function to shift value of the array
    shift(copy, size, 1);
    k++;
  }
  return array;
}

int * collapse(int **A, int n, int m) {
  //error checking
  if (A == NULL) {
    return NULL;
  }

  if (n <= 0 || m <= 0) {
    return NULL;
  }

  //Creating a dynamic array for the result
  int * sumArray = (int *) malloc(m * sizeof(int));
  //nested for loop to add each column in every row together
  for (int j = 0; j < m; j++) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
      sum += A[i][j];
    }
    //assign the sum value to the resulting array
    sumArray[j] = sum;
  }
  return sumArray;
}
