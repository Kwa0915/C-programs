/* Author: Kok Hwa Khor
 * Date: 10/2/2019
 *
 * This program find the missing number from the list
 */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main (int argc, char **argv) {

  int n = atoi(argv[1]);

  printf("Missing numbers 1 thru %d:\n", n);

  int check = 0;

  //nested for loop to check the missing number from the list
  for (int i = 1; i <= n; i++){
    check = 1;
    for (int j = 2; j < argc; j++){
      //exit the if statement if the number is in the list
      if (i == atoi(argv[j])){
        check = 0;
        break;
      }
    }
   //print out the missing number
   if (check == 1) {
     printf("%d, ", i);
   }
  }

  //if no number are missing,
  if (check == 0) {
    printf("None");
  }

  printf("\n");

  return 0;
}
