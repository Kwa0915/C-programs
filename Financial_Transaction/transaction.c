/*
 * Author: Kok Hwa Khor
 * Date: 12/13/2019
 *
 * This source file contain several additional reports on the
 * financial data
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

#include "transaction.h"

Transaction *createTransaction (char *UUID,
                               char *type,
                               double amountOfTransaction,
                               char *accNum,
                               double accBalanceBefore,
                               double accBalanceAfter,
                               char *transferAccNum) {

  //creating a Transaction structure array
  Transaction *t = (Transaction *) malloc(sizeof(Transaction) * 1);
  t->UUID = (char *) malloc(sizeof(char) * (strlen(UUID) + 1));
  strcpy(t->UUID, UUID);
  t->type = (char *) malloc(sizeof(char) * (strlen(type) + 1));
  strcpy(t->type, type);
  t->amountOfTransaction = amountOfTransaction;
  t->accNum = (char *) malloc(sizeof(char) * (strlen(accNum) + 1));
  strcpy(t->accNum, accNum);
  t->accBalanceBefore = accBalanceBefore;
  t->accBalanceAfter = accBalanceAfter;
  t->transferAccNum = (char *) malloc(sizeof(char) * (strlen(transferAccNum) + 1));
  strcpy(t->transferAccNum, transferAccNum);

  return t;
}

Transaction* readFile (const char *fileName) {

  FILE *f = fopen (fileName, "r");

  //error checking
  if (f == NULL) {
    fprintf(stderr, "Unable to open file: %s\n", fileName);
    exit(1);
  }

  int i = 0;
  int size = 500;
  char buffer[1000];
  int numLines = atoi(fgets(buffer, size, f));

  Transaction *transactions = (Transaction *) malloc(sizeof(Transaction) * numLines);

  //Take in the file line by line, tokenized it and store it
  //into the array of Transaction
  while(fgets(buffer, size, f) != NULL && i < numLines) {
    char UUID[100];
    char *type;
    double amountOfTransaction;
    char *accNum;
    double accBalanceBefore, accBalanceAfter;
    char *transferAccNum;
    //setting the null terminator
    buffer[strlen(buffer) - 1] = '\0';
    char *transactionToken = strtok(buffer, ",");
    strcpy(UUID, transactionToken);
    type = strtok(NULL, ",");
    amountOfTransaction = atof(strtok(NULL, ","));
    accNum = strtok(NULL, ",");
    accBalanceBefore = atof(strtok(NULL, ","));
    accBalanceAfter = atof(strtok(NULL, ","));
    transferAccNum = strtok(NULL, ",");
    Transaction *t = createTransaction(UUID, type, amountOfTransaction, accNum, accBalanceBefore, accBalanceAfter, transferAccNum);
    transactions[i] = *t;
    i++;
  }

  fclose(f);

  return transactions;
}

void generateReports (const Transaction *t, char *fileName) {

  //read in the number of lines
  FILE *f = fopen (fileName, "r");

  if (f == NULL) {
    fprintf(stderr, "Unable to open file: %s\n", fileName);
    exit(1);
  }

  char buffer[50];
  int numLines = atoi(fgets(buffer, 50, f));

  fclose(f);

  int paymentNum = 0;
  int transferNum = 0;
  int withdrawNum = 0;
  int debitNum = 0;
  int depositNum = 0;
  int totalNum = 0;

  double paymentTotal = 0.0;
  double transferTotal = 0.0;
  double withdrawTotal = 0.0;
  double debitTotal = 0.0;
  double depositTotal = 0.0;
  double totalTransactions = 0.0;

  //Determine the type of transaction,
  //calculate the total and number of each transaction
  for (int i = 0; i < numLines; i++) {
    if (strcmp(t[i].type, "PAYMENT") == 0) {
      paymentTotal += t[i].amountOfTransaction;
      totalTransactions += t[i].amountOfTransaction;
      paymentNum++;
      totalNum++;
    } else if (strcmp(t[i].type, "TRANSFER") == 0) {
      transferTotal += t[i].amountOfTransaction;
      totalTransactions += t[i].amountOfTransaction;
      transferNum++;
      totalNum++;
    } else if (strcmp(t[i].type, "WITHDRAWAL") == 0) {
      withdrawTotal += t[i].amountOfTransaction;
      totalTransactions += t[i].amountOfTransaction;
      withdrawNum++;
      totalNum++;
    } else if (strcmp(t[i].type, "DEBIT") == 0) {
      debitTotal += t[i].amountOfTransaction;
      totalTransactions += t[i].amountOfTransaction;
      debitNum++;
      totalNum++;
    } else if (strcmp(t[i].type, "DEPOSIT") == 0) {
      depositTotal += t[i].amountOfTransaction;
      totalTransactions += t[i].amountOfTransaction;
      depositNum++;
      totalNum++;
    }
  }

  //print out the Total Reports
  printf("====================================\n");
  printf("Totals Report\n");
  printf("====================================\n");
  printf("Type            Count          Total\n");
  printf("====================================\n");
  printf("Payment %13d $ %12.2f\n", paymentNum, paymentTotal);
  printf("Transfer %12d $ %12.2f\n", transferNum, transferTotal);
  printf("Withdraw %12d $ %12.2f\n", withdrawNum, withdrawTotal);
  printf("Debit %15d $ %12.2f\n", debitNum, debitTotal);
  printf("Deposit %13d $ %12.2f\n", depositNum, depositTotal);
  printf("====================================\n");
  printf("Total %15d $ %12.2f\n\n", totalNum, totalTransactions);
}

void validateData (const Transaction *t, char *fileName) {

  //read in the number of lines
  FILE *f = fopen (fileName, "r");

  if (f == NULL) {
    fprintf(stderr, "Unable to open file: %s\n", fileName);
    exit(1);
  }

  char buffer[50];
  int numLines = atoi(fgets(buffer, 50, f));

  fclose(f);

  double difference = 0.0;
  int j = 0;
  int invalid[numLines];

  for (int i = 0; i < numLines; i++) {
    //if the transaction type is DEPOSIT,
    //the account balance after should be more than before
    if (strcmp(t[i].type, "DEPOSIT") == 0 && t[i].accBalanceAfter < t[i].accBalanceBefore) {
      invalid[j] = i;
      j++;
      //if the transaction type is either PAYMENT, TRANSFER, WITHDRAWAL or DEBIT,
      //the account balance after should be less than before
    } else if ( (strcmp(t[i].type, "PAYMENT") == 0 ||
               strcmp(t[i].type, "TRANSFER") == 0 ||
               strcmp(t[i].type, "WITHDRAWAL") == 0 ||
               strcmp(t[i].type, "DEBIT") == 0)  &&
               t[i].accBalanceAfter > t[i].accBalanceBefore) {
          invalid[j] = i;
          j++;
      //find the difference between the account balance after and before
    } else {
        if (t[i].accBalanceAfter > t[i].accBalanceBefore) {
          difference = t[i].accBalanceAfter - t[i].accBalanceBefore;
        } else {
          difference = t[i].accBalanceBefore - t[i].accBalanceAfter;
        }
        //if they are not equal, store it in an array and print it out later
        if (round(difference * 100) / 100 > round(t[i].amountOfTransaction * 100) / 100 ||
            round(difference * 100) / 100 < round(t[i].amountOfTransaction * 100) / 100) {
          invalid[j] = i;
          j++;
        }
      }
  }

  //print out the Balance Validation Report
  printf("====================================\n");
  printf("Balance Validation Report\n");
  printf("====================================\n");
  if (j != 0) {
    for (int i = 0; i < j; i++) {
      difference = t[invalid[i]].accBalanceAfter - t[invalid[i]].accBalanceBefore;
      //if the value is negative, make it positive
      if (difference < 0.0) {
        difference = difference * -1;
      }
      //calculate the 'off' amount
      double off = difference - t[invalid[i]].amountOfTransaction;
      printf("  Invalid Transaction, off by $%.2f:\n", off);
      printf("    %s: %s -> %s ( %s ) $ %.2f ($%.2f -> $%.2f)\n", t[invalid[i]].UUID, t[invalid[i]].accNum, t[invalid[i]].transferAccNum, t[invalid[i]].type, t[invalid[i]].amountOfTransaction, t[invalid[i]].accBalanceBefore, t[invalid[i]].accBalanceAfter);
    }
    printf("Number of invalid balances found: %d\n\n", j);
  } else {
    printf("Number of invalid balances found: 0\n\n");
  }
}

void depositLimit (const Transaction *t, char *fileName) {

  //read in the number of lines
  FILE *f = fopen (fileName, "r");

  if (f == NULL) {
    fprintf(stderr, "Unable to open file: %s\n", fileName);
    exit(1);
  }

  char buffer[50];
  int numLines = atoi(fgets(buffer, 50, f));

  fclose(f);

  int depositsExceed = 0;
  int depositsApproach = 0;

  //find the 'Deposit' type of transaction
  for (int i = 0; i < numLines; i++) {
    if (strcmp(t[i].type, "DEPOSIT") == 0) {
      if (t[i].amountOfTransaction >= 10000.00) {
        depositsExceed++;
      } else if (t[i].amountOfTransaction >= 9900.00 && t[i].amountOfTransaction <= 9999.99) {
        depositsApproach++;
      }
    }
  }

  //print out the Deposit Limit Report
  printf("Deposit Limit Report\n");
  printf("====================================\n");
  if (depositsExceed != 0 || depositsApproach !=0) {
    printf("Deposits exceeding 10k:   %d\n", depositsExceed);
    printf("Deposits approaching 10k: %d\n\n", depositsApproach);
  } else {
    printf("Deposits exceeding 10k:   0\n");
    printf("Deposits approaching 10k: 0\n\n");
  }
}

int compareAccNum (const void *a, const void *b) {
  const Transaction *x = (const Transaction *)a;
  const Transaction *y = (const Transaction *)b;
  //compare the account numbers of the transactions
  return strcmp(x->accNum, y->accNum);
}

void repeatedTransactions (Transaction *t, char *fileName) {

  //read in the number of lines
  FILE *f = fopen (fileName, "r");

  if (f == NULL) {
    fprintf(stderr, "Unable to open file: %s\n", fileName);
    exit(1);
  }

  char buffer[50];
  int numLines = atoi(fgets(buffer, 50, f));

  fclose(f);

  int repeated[numLines];
  int k = 0;

  Transaction *x = t;

  //calling the qsort function to sort them by Account Number
  qsort(x, numLines, sizeof(Transaction), compareAccNum);

  //if it's not the last one, compare the transaction to the next one
  //store it into an array and print it out later
  for (int i = 0; i < numLines; i++) {
    if (i != (numLines - 1) &&
        strcmp(x[i].accNum, x[i+1].accNum) == 0 &&
        strcmp(x[i].transferAccNum, x[i+1].transferAccNum) == 0 &&
        x[i].amountOfTransaction == x[i+1].amountOfTransaction) {
          repeated[k] = i;
          k++;
     //if it's not the first one, compare the transaction to the one before it
     //store it into an array and print it out later
     } else if (i != 0 &&
               strcmp(x[i].accNum, x[i-1].accNum) == 0 &&
               strcmp(x[i].transferAccNum, x[i-1].transferAccNum) == 0 &&
               x[i].amountOfTransaction == x[i-1].amountOfTransaction) {
        repeated[k] = i;
        k++;
      }
    }

  //print out the Repeated Transaction Report
  printf("====================================\n");
  printf("Repeated Transaction Report\n");
  printf("====================================\n");
  if (k != 0) {
    printf("Repeated Transactions:\n");
    for (int i = 0; i < k; i++) {
      printf("    %s: %s -> %s ( %s ) $ %.2f ($%.2f -> $%.2f)\n", t[repeated[i]].UUID, t[repeated[i]].accNum, t[repeated[i]].transferAccNum, t[repeated[i]].type, t[repeated[i]].amountOfTransaction, t[repeated[i]].accBalanceBefore, t[repeated[i]].accBalanceAfter);
    }
    printf("Total repeated transactions flagged: %d\n\n", k);
  } else {
    printf("Total repeated transactions flagged: 0\n\n");
  }
}

void benford (const Transaction *t, char *fileName) {

  //read in the number of lines
  FILE *f = fopen (fileName, "r");

  if (f == NULL) {
    fprintf(stderr, "Unable to open file: %s\n", fileName);
    exit(1);
  }

  char buffer[50];
  int numLines = atoi(fgets(buffer, 50, f));

  fclose(f);

  double count1 = 0;
  double count2 = 0;
  double count3 = 0;
  double count4 = 0;
  double count5 = 0;
  double count6 = 0;
  double count7 = 0;
  double count8 = 0;
  double count9 = 0;

  //divide the number until it becomes 1 digit,
  //then take the digit
  for (int i = 0; i < numLines; i++) {
    int first = t[i].amountOfTransaction;
    while (first >= 10) {
      first /= 10;
    }
    if (first == 1) {
      count1++;
    } else if (first == 2) {
      count2++;
    } else if (first == 3) {
      count3++;
    } else if (first == 4) {
      count4++;
    } else if (first == 5) {
      count5++;
    } else if (first == 6) {
      count6++;
    } else if (first == 7) {
      count7++;
    } else if (first == 8) {
      count8++;
    } else if (first == 9) {
      count9++;
    }
  }

  //calculate the total number of count
  int totalCount = count1 + count2 + count3 + count4 + count5 + count6 + count7 + count8 + count9;

  //calculate the frequency of each number
  double frequency1 = count1 / totalCount;
  double frequency2 = count2 / totalCount;
  double frequency3 = count3 / totalCount;
  double frequency4 = count4 / totalCount;
  double frequency5 = count5 / totalCount;
  double frequency6 = count6 / totalCount;
  double frequency7 = count7 / totalCount;
  double frequency8 = count8 / totalCount;
  double frequency9 = count9 / totalCount;

  //print out the Benford Analysis report
  printf("====================================\n");
  printf("Benford Analysis\n");
  printf("====================================\n");
  printf("Number  Count  Frequency  Expected  Difference\n");
  printf("1          %.0f       %.3f     0.301      %.3f\n", count1, frequency1, frequency1 - 0.301);
  printf("2          %.0f       %.3f     0.176      %.3f\n", count2, frequency2, frequency2 - 0.176);
  printf("3          %.0f       %.3f     0.125      %.3f\n", count3, frequency3, frequency3 - 0.125);
  printf("4          %.0f       %.3f     0.097      %.3f\n", count4, frequency4, frequency4 - 0.097);
  printf("5          %.0f       %.3f     0.079      %.3f\n", count5, frequency5, frequency5 - 0.079);
  printf("6          %.0f       %.3f     0.067      %.3f\n", count6, frequency6, frequency6 - 0.067);
  printf("7          %.0f       %.3f     0.058      %.3f\n", count7, frequency7, frequency7 - 0.058);
  printf("8          %.0f       %.3f     0.051      %.3f\n", count8, frequency8, frequency8 - 0.051);
  printf("9          %.0f       %.3f     0.046      %.3f\n\n", count9, frequency9, frequency9 - 0.046);
}

int compare (const void *t, const void *u) {
  const Transaction *x = (const Transaction *)t;
  const Transaction *y = (const Transaction *)u;
  //return a flag value 1 if no same UUID are found
  if (strcmp(x->UUID, y->UUID) != 0) {
    return 1;
    //return a flag value -1 if any of the components are different
  } else if (strcmp(x->type, y->type) != 0 ||
             x->amountOfTransaction != y->amountOfTransaction ||
             strcmp(x->accNum, y->accNum) != 0 ||
             strcmp(x->transferAccNum, y->transferAccNum) != 0 ||
             x->accBalanceBefore != y->accBalanceBefore ||
             x->accBalanceAfter != y->accBalanceAfter) {
    return -1;
    //return 0 if they are equal
  } else {
    return 0;
  }
}

int compareUUID (const void *t, const void *u) {
  const Transaction *x = (const Transaction *)t;
  const Transaction *y = (const Transaction *)u;
  //compare the UUID of both transactions
  return strcmp(x->UUID, y->UUID);
}

void dataAnomalies (Transaction *t, Transaction *u, char *fileName, char *fileName2) {

  //read in the number of lines of the first file
  FILE *f = fopen (fileName, "r");

  if (f == NULL) {
    fprintf(stderr, "Unable to open file: %s\n", fileName);
    exit(1);
  }

  char buffer[50];
  int numLines = atoi(fgets(buffer, 50, f));

  fclose(f);

  //read in the number of lines of the second file
  f = fopen (fileName2, "r");

  if (f == NULL) {
    fprintf(stderr, "Unable to open file: %s\n", fileName2);
    exit(1);
  }

  char buffer2[50];
  int numLines2 = atoi(fgets(buffer2, 50, f));

  fclose(f);

  Transaction *x = t;
  Transaction *y = u;

  //sort both of the transactions by UUID
  qsort(x, numLines, sizeof(Transaction), compareUUID);
  qsort(y, numLines2, sizeof(Transaction), compareUUID);

  int missing = 0;
  int inconsistent = 0;

  printf("====================================\n");
  printf("Database Snapshot Tampering Report\n");
  printf("====================================\n");

  //comparing database A to B
  int j = 0;
  for (int i = 0; i < numLines; i++) {
    //If the number of transactions in B happened to be less than A,
    //print out all the transactions in A after B reached the end of transactions
    if (j == numLines2) {
      printf("Missing Transaction: %s in database A but not in B\n", x[i].UUID);
      missing++;
      continue;
    }
    //calling the compare function to compare database A to B
    int result = compare(&x[i], &y[j]);
    //if they are equal, move on
    if (result == 0) {
      j++;
      continue;
      //if one UUID exist in A but not in B, print it out
    } else if (result == 1) {
      //if transaction in B is smaller than A, it might be further down
      //in the file, therefore, keep searching
        if (strcmp(y[j].UUID, x[i].UUID) < 0) {
          i--;
          j++;
          continue;
      } else {
        printf("Missing Transaction: %s in database A but not in B\n", x[i].UUID);
        missing++;
      }
      //print out the inconsistent data if they are different
    } else if (result == -1) {
      printf("Inconsistent Data:\n");
      printf("        A: %s: %s -> %s ( %s ) $ %.2f ($%.2f -> %.2f)\n", x[i].UUID, x[i].accNum, x[i].transferAccNum, x[i].type, x[i].amountOfTransaction, x[i].accBalanceBefore, x[i].accBalanceAfter);
      printf("        B: %s: %s -> %s ( %s ) $ %.2f ($%.2f -> %.2f)\n", y[j].UUID, y[j].accNum, y[j].transferAccNum, y[j].type, y[j].amountOfTransaction, y[j].accBalanceBefore, y[j].accBalanceAfter);
      inconsistent++;
      j++;
    }
  }

  //Comparing database B to A
  int k = 0;
  for (int i = 0; i < numLines2; i++) {
    //same logic as before, if the number of transactions in A happened
    //to be less than B, print out all the transactions in B after A reached
    //the end of transactions
    if (k == numLines) {
      printf("Missing Transaction: %s in database B but not in A\n", y[i].UUID);
      missing++;
      continue;
    }
    //if they are equal, move on
    if (compare(&y[i], &x[k]) == 0) {
      k++;
      continue;
    //if one UUID exist but not in the other, print it out
    } else if (compare(&y[i], &x[k]) == 1) {
      //if transaction in A is smaller than B, it might be further down
      //in the file, therefore, keep searching
        if (strcmp(x[k].UUID, y[i].UUID) < 0) {
          i--;
          k++;
        } else {
          printf("Missing Transaction: %s in database B but not in A\n", y[i].UUID);
          missing++;
        }
      }
    }
  printf("Total missing records:      %d\n", missing);
  printf("Total inconsistent records: %d\n", inconsistent);
}
