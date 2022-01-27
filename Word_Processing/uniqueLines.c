/**
 * Author: Kok Hwa Khor
 * Date: 11/13/2019
 *
 * This program contain the source code that processes a text
 * file and removes any duplicate lines and outputting the
 * unique lines to a new output file
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main (int argc, char **argv) {

  FILE *f = fopen(argv[1], "r");

  //create a static string
  char buff[1000];
  int counter = 0;
  //while loop to count the number of lines
  while (fgets(buff, 1000, f) != NULL) {
    counter++;
  }

  fclose(f);

  //creating a 2D dynamic string to store the unique lines
  char **unique = (char **) malloc(counter * sizeof(char*));
  for (int i = 0; i < counter; i++) {
    unique[i] = (char *) malloc(100 * sizeof(char));
  }

  //creatign a dynamic string to take in every line
  char *string = (char *) malloc(100 * sizeof(char));

  f = fopen(argv[1], "r");

  //take in the first line of the file to the string
  fgets(unique[0], 100, f);
  //setting the terminating character
  unique[0][strlen(unique[0])-1] = '\0';
  //remove the carriage return character
  if (unique[0][strlen(unique[0])-1] == '\r') {
    unique[0][strlen(unique[0])-1] = '\0';
  }

  //declaring n for comparing the string
  int n = 1;
  //declaring i for the loop
  int i = 1;
  //declaring stringCounter for the number of index
  int stringCounter = 1;

  //while loop to take in the lines from the file
  while (fgets(string, 100, f) != NULL) {
    //setting the terminating character
    string[strlen(string)-1] = '\0';
    //removing the carriage return character
    if (string[strlen(string)-1] == '\r') {
      string[strlen(string)-1] = '\0';
    }
    //for loop to compare if the string is already exist
    for (int j = 0; j < i; j++) {
      n = strcmp(string, unique[j]);
      //exit the loop if the string exists
      if (n == 0) {
        break;
      }
    }
    //continue the iteration if the string exists
    if (n == 0) {
      continue;
    } else {
      //copy it into the string if it's unique
      strcpy(unique[stringCounter], string);
      stringCounter++;
    }
    i++;
  }

  fclose(f);
  //free the string memory
  free(string);

  f = fopen(argv[2], "w");

  //for loop to write it into the file
  for (int i = 0; i < stringCounter; i++) {
    fprintf(f, "%s\n", unique[i]);
  }

  fclose(f);
  //free the unique string memory
  for (int i = 0; i < counter; i++) {
    free(unique[i]);
  }
  free(unique);

  return 0;
}
