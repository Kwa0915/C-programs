/* Author: Kok Hwa Khor
 * Date: 10/2/2019
 *
 * This program is to calculate the population growth over
 * the next several years
 */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main (int argc, char **argv) {

  //take in the value for population, growth rate, citizens
  //and number of years
  int population = atoi(argv[1]);
  double growthRate = atof(argv[2]);
  int addCitizens = atoi(argv[3]);
  int years = atoi(argv[4]);

  //error input
  if (population < 0 || years <= 0){
    printf("Invalid Input!\n");
    return 0;
  }

  int modelA = 0;
  int modelB = 0;
  int populationA = population;
  int populationB = population;

  printf("Year  Model A  Model B\n");

  //for loop to calculate the growth rate and print it out
  for (int i = 0; i <= years; i++){

    modelA = round(populationA * (growthRate + 1));
    modelB = round(populationB + addCitizens);

    printf("%4d %8d %8d\n", i, populationA, populationB);

    populationA = modelA;
    populationB = modelB;
  }

  return 0;
}
