#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "array_utils.h"

int main () {

  int a[] = {2,3,4,5};
  int b[] = {2,3,4,5};
  int c[] = {1,2,3,4};
  int d[] = {1,2,3,4};

  int size = 4;
  int check = 0;

  check = isEqual(a,b,size);
  printf("%d\n", check);
  check = isEqual(a,c,size);
  printf("%d\n", check);

  printf("===========================\n");

  reverse(a, size);
  for (int i=0; i<size; i++) {
    printf("%d\n", a[i]);
  }

  printf("===========================\n");

  int * newReverse = reverseCopy(b, size);
  for (int i=0; i<size; i++) {
    printf("%d\n", newReverse[i]);
  }

  printf("===========================\n");

  int k = 2;
  int e[] = {2,3,5,6,12,13};
  int newSize = 6;
  shift(e, newSize, k);
  for (int i=0; i<newSize; i++) {
    printf("%d\n", e[i]);
  }

  printf("===========================\n");

  int * newShift = shiftCopy(d, size, k);
  for (int i=0; i<size; i++) {
    printf("%d\n", newShift[i]);
  }

  printf("===========================\n");

  int * even = (int *) malloc(3 * sizeof(int));
  getEvens(e, newSize, even);
  for (int i=0; i<3; i++) {
    printf("%d\n", even[i]);
  }

  printf("===========================\n");

  int ** circulantTest = circulant(a, 4);
  for (int i=0; i<size; i++) {
      for(int j=0; j<size; j++) {
        printf("%d ", circulantTest[i][j]);
        }
      printf("\n");
      }

  printf("===========================\n");

  int ** arrayA = (int **) malloc(3 * sizeof(int *));
  for (int i = 0; i < 4; i++) {
    arrayA[i] = (int *) malloc(4 * sizeof(int));
  }

  int arrayB[3][4] = {
          {1,2,3,4},
          {4,1,2,3},
          {2,3,4,1}
          };

  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 4; j++) {
      arrayA[i][j] = arrayB[i][j];
    }
  }

  int * collapseTest = collapse(arrayA, 3, 4);
  for (int i = 0; i < 4; i++) {
    printf("%d, ", collapseTest[i]);
  }

  return 0;
}
