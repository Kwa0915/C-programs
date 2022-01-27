/* Author:Kok Hwa Khor
	 Date: 12/09/2019

	 This program estimate or predict a baseball team's win or loss ratio over
	 an entire season.
*/

#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int main (int argc, char **argv) {

	int scored;
	int allowed;
	int games;
	int wins;
	double percentage;
	double p = 0;
	double pWins;
	double pLoss;
	double error;

	scored = atoi(argv[1]);
	allowed = atoi(argv[2]);
	games = atoi(argv[3]);
	wins = atoi(argv[4]);

	if (scored < 0 || allowed < 0 || games < 0 || wins < 0) {
		printf("Invalid input(s)\n");
		return 0;
	} else {
			printf("p value  Win Percentage  Predicted Wins  Predicted Loss  Error\n");

			p = 2.00;
			percentage = pow(scored, p) / (pow(scored, p) + pow(allowed, p));
			pWins = games * percentage;
			pLoss = games - pWins;
			error = pWins - wins;
			percentage = percentage * 100;
			printf("%.2lf  %8.2lf  %11.0lf  %14.0lf  %13.0lf\n", p, percentage, pWins, pLoss, error);

			p = 1.83;
			percentage = pow(scored, p) / (pow(scored, p) + pow(allowed, p));
			pWins = games * percentage;
			pLoss = games - pWins;
			error = pWins - wins;
			percentage = percentage * 100;
			printf("%.2lf  %8.2lf  %11.0lf  %14.0lf  %13.0lf\n", p, percentage, pWins, pLoss, error);

			p = 1.5 * (log((double)(scored + allowed) / games))/(log(10)) + 0.45;
			percentage = pow(scored, p) / (pow(scored, p) + pow(allowed, p));
			pWins = games * percentage;
			pLoss = games - pWins;
			error = pWins - wins;
			percentage = percentage * 100;
			printf("%.2lf  %8.2lf  %11.0lf  %14.0lf  %13.0lf\n", p, percentage, pWins, pLoss, error);

			p = pow((double)(scored + allowed) / games, 0.287);
			percentage = pow(scored, p) / (pow(scored, p) + pow(allowed, p));
			pWins = games * percentage;
			pLoss = games - pWins;
			error = pWins - wins;
			percentage = percentage * 100;
			printf("%.2lf  %8.2lf  %11.0lf  %14.0lf  %13.0lf\n", p, percentage, pWins, pLoss, error);
		}

	return 0;
}
