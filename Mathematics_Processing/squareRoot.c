/* Author: Kok Hwa Khor
 * Date: 10/2/2019
 *
 * This program compute the square root of a value.
 */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main (int argc, char **argv) {

  double x = atof(argv[1]);
  double e = atof(argv[2]);

  //error input
  if (e < 0 || x < 0) {
    printf("Invalid Input!\n");
    return 0;
  }

  int power = 0;
  //scale up
  while(x < 0.5) {
    x = x * 4;
    power--;
  }
  //scale down
  while(x >= 2.0) {
    x = x / 4;
    power++;
  }

  double a = x;
  double c = x - 1.0;
  double a1 = 0.0;

  //compute the value for a and c
  a = a - ((a * c) / 2.0);
  c = ((c * c) * (c - 3.0)) / 4.0;

  //while loop to computer the value of a until it
  //gets smaller than e
  while (fabs(a1 - a) > e) {
    a1 = a;
    a = a - ((a * c) / 2.0);
    c = ((c * c) * (c - 3.0)) / 4.0;
  }

  //scaling back up
  a = a * (pow(2, power));

  printf("sqrt(%lf) ~= %lf\n", atof(argv[1]), a);

  return 0;
}
