/*
 * Author: Kok Hwa Khor
 * Date: 10/25/2019
 *
 * This file contain the source codes for circle division problem
 */
 
#include <stdlib.h>
#include <stdio.h>

//This function shift the contents of the integer array by integer k
int shift(int *a, int size, int k);

//This function sort the array in ascending order
void insertionSort(int *array, int size);

int main (int argc, char **argv) {

  int total = 0;

  //Creating a dynamic array to store all the values in the question
  int * array = (int *) malloc((argc - 1) * sizeof(int));

  //For loop to store the values into the array and to count the total value
  for (int i = 0; i < argc-1; i++) {
    array[i] = atoi(argv[i+1]);
    total += array[i];
  }

  //Find the sum value for each division
  int divisionValues = 0;
  divisionValues = total / 5;

  //Creating a dynamic array to store the values for the solutions
  int * solution = (int *) malloc (5 * sizeof(int));

  //No solutions
  if (total % 5 != 0) {
    printf("No Solution!\n");
    return 0;
  }

  printf("Solution found with divisions at indices:\n");

  int sum = 0;
  int numberOfSolutions = 0;
  int length = 0;

  //Nested for loop to find the solutions

  //for loop to shift the array and run through to find each solution
  //at different starting point
  for (int k = 0; k < argc-1; k++) {
    length = 0;
    sum = 0;
    //for loop to find the solution
    for (int i = 0; i < argc-1; i++) {
      //adding the values
      sum += array[i];
      //checking if the sum is same as the division values
      if (sum > divisionValues) {
        sum = 0;
        break;
      }
      else if (sum == divisionValues) {
        //taking the shifted array into consideration which is why the -k
        solution[length] = (i - k + 1);
        //numberOfSolutions counter
        numberOfSolutions++;
        //length of the solution array
        length++;
        sum = 0;
      }
    }
    //exit the loop if the 5 solutions are found
    if (numberOfSolutions == 5) {
      break;
    }
    numberOfSolutions = 0;
    //calling the shift function to shift the array
    shift(array, argc-1, 1);
  }
  //if the solution found at the last indices is the last value
  //in the circle, reassigning it back because it's circulant
   if (solution[4] == (argc -1)) {
      for (int i = 0; i < 5 ; i++) {
        solution[i] = argc - 1- solution[i];
      }
   }

  //if there's is no 5 solutions, exit
  if(numberOfSolutions != 5) {
    printf("No Solution!\n");
    return 0;
  }

  //calling the sorting function to arrange the arrays
  insertionSort(solution, 5);
  //for loop to print out the solutions
  for (int j = 0; j < 5; j++) {
    printf("%d ", solution[j]);
  }

  printf("\nSum: %d\n", divisionValues);

  return 0;
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

void insertionSort(int *array, int size) {

  int value;
  //for loop to arrange the value in ascending order
  for(int i = 1; i < size; i++) {
    value = array[i];
    int j = i;
    //if the next value in the index is bigger than current, swap it
    while(j > 0 && array[j-1] > value) {
      array[j] = array[j-1];
      j--;
    }
    //assigning the value back to the index
    array[j] = value;
  }
}
