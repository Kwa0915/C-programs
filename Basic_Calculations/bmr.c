/* Author: Kok Hwa Khor
	 Date: 12/09/2019

	 This program computes a subject's BMR.
*/

#include <stdlib.h>
#include <stdio.h>

int main (int argc, char **argv) {

	int sex;
	double weight;
	double height;
	double age;
	double fBMR;
	double mBMR;

	printf("Enter subject's gender (1=female, 2=male):\n");
	scanf("%d", &sex);
	printf("Enter subject's weight (kg):\n");
	scanf("%lf", &weight);
	printf("Enter subject's height (cm):\n");
	scanf("%lf", &height);
	printf("Enter subject's age (years):\n");
	scanf("%lf", &age);

	if (sex <= 0 || weight <= 0 || height <= 0 || age <=0) {
		printf("Error.\n");
		return 0;
	} else {

			fBMR = 655.1 + 9.6 * weight + 1.8 * height - 4.7 * age;
			mBMR = 66.47 + 13.7 * weight + 5 * height - 6.8 * age;

			if (sex == 1) {
				printf("Subject's BMR: %.2lf kCal/day.\n", fBMR);
			} else {
				printf("Subject's BMR: %.2lf kCal/day.\n", mBMR);
			}
		}

	return 0;
}
