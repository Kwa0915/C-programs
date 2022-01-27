#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main (int argc, char **argv) {

  double x = atof(argv[1]);
  double e = atof(argv[2]);

  int power = 0;
  //scale up:
  while(x < 0.5) {
    x = x * 4;
    power--;
  }
  while(x >= 2.0) {
    x = x / 4;
    power++;
  }

  printf("%lf\n", x);

  double a = x;
  double c = x - 1.0;
  double a1 = 0.0;
  double c1 = 0.0;
  double aDiff = 0;

  while (aDiff > e) {
    a1 = a - ((a * c) / 2.0);
    c1 = ((c * c) * (c - 3.0)) / 4.0;
    aDiff = fabs(a1 - a);
    a = a1;
    c = c1;
  }

  printf("%lf\n", a);

  // while(a < 0.5) {
  //   a = a * 4;
  //   power--;
  // }
  // while(a >= 2.0) {
  //   a = a / 4;
  //   power++;
  // }


  a = a * (pow(2, power));

  printf("%lf\n", a);

  printf("sqrt(%lf) ~= %lf\n", atof(argv[1]), a);

  return 0;
}
