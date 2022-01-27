/*
 * Author: Kok Hwa Khor
 * Date: 12/13/2019
 *
 * This source file contain the headers for several functions
 * on financial data Reports
 */

//Creating a transaction structure
typedef struct {
  char * UUID;
  char * type;
  double amountOfTransaction;
  char * accNum;
  double accBalanceBefore;
  double accBalanceAfter;
  char * transferAccNum;
} Transaction;

//This function create a transaction structure array
Transaction *createTransaction(char *UUID,
                               char *type,
                               double amountOfTransaction,
                               char *accNum,
                               double accBalanceBefore,
                               double accBalanceAfter,
                               char *transferAccNum);

//This function reads in the file, tokenized it and store it
//into the transaction array
Transaction* readFile (const char *fileName);

//This function prints out the data on each type of transactions
void generateReports(const Transaction *t, char *fileName);

//This function finds out any invalid transaction and prints it out
void validateData(const Transaction *t, char *fileName);

//This function finds out the number of deposits in excess of $10,100
//and between $9,900 and $9,999.99
void depositLimit (const Transaction *t, char *fileName);

//This fucntion compare the Account Number of the transactions
//to use in qsort
int compareAccNum (const void *a, const void *b);

//This function finds out any repeated transactions and prints it out
void repeatedTransactions (Transaction *t, char *fileName);

//This function analyze a set of numbers by Benford's Law
void benford (const Transaction *t, char *fileName);

//This function compare the components of transaction in two databases
int compare (const void *t, const void *u);

//This function compare the UUID of the transactions
//to use in qsort
int compareUUID (const void *t, const void *u);

//This function identify potential issues by comparing two database and find
//any anomalies between 
void dataAnomalies (Transaction *t, Transaction *u, char *fileName, char *fileName2);
