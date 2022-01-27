#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main (int argc, char **argv) {

  int a[100];
  int b[100];
  int n = atoi(argv[1]);

  for (int i = 1; i < argc; i++) {
    a[i] = atoi(argv[i]);
  }

  printf("Missing numbers 1 thru %d:\n", n);

  for (int i = 1; i < argc; i++) {
    for (int j = 1; j < argc; j++) {
      if (a[j] > a[i]){
        int temp = a[i];
        a[i] = a[j];
        a[j] = temp;
      }
    }
  }

  for (int i = 1; i < argc; i++) {
    printf("%d ", a[i]);
  }

  int j = 0;
  int k = 1;
  for (int i = 1; i <= n; i++) {
    if (i == a[k]) {
      k++;
    } else if (i != a[k]) {
      b[j] = i;
      k++;
      j++;
    }
  }


  /*int k = 1;
  for (int i = 1; i < argc; i++) {
      for (int j = 1; j < n; j++) {
        if (j != a[i]) {
          b[k] = j;
          k++;
        }
      }
    }
*/

  printf("\n%d\n", k);

  for (int i = 0; i <= n; i++) {
    printf("%d ", b[i]);
  }

  /*for (int i = 1; i <= argc; i++) {
    int num = 0;
    for (int j = 1; j <= n; j++) {
      if (j == atoi(argv[i])) {
        num = 1;
      }
    }
    if (num == 0) {
      printf("%d, ", atoi(argv[i]));
    }
  }
*/
  return 0;
}
