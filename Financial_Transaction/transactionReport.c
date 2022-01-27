/*
 * Author: Kok Hwa Khor
 * Date: 12/13/2019
 *
 * This source file contain the main functions for processing
 * financial data
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

#include "transaction.h"

int main (int argc, char **argv) {

  //taking in the first command line argument as the filename
  char *fileName = argv[1];

  //Calling the readFile function to create a transaction structure array
  Transaction *transactions = readFile(fileName);

  //Calling the generateReports function
  generateReports(transactions, fileName);

  //Calling the validateData function
  validateData(transactions, fileName);

  //Calling the depositLimit function
  depositLimit (transactions, fileName);

  //Calling the repeatedTransactions function
  repeatedTransactions (transactions, fileName);

  //calling the benford function
  benford (transactions, fileName);

  //taking in the second command line argument as the second filename
  char *fileName2 = argv[2];

  //creating another transaction structure array bu calling the readFile function
  Transaction *transactions2 = readFile(fileName2);

  //calling the dataAnomalies function
  dataAnomalies (transactions, transactions2, fileName, fileName2);

  return 0;
}
