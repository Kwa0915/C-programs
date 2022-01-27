/**
 * Author: Kok Hwa Khor
 * Date: 11/13/2019
 *
 * This program contain the source code that processes a text file
 * with long lines and reformats it by inserting line breaks so
 * that lines have no more than 72 characters
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main (int argc, char **argv) {

  FILE *f = fopen(argv[1], "r");

  //take in the first character from the file
  char c = fgetc(f);
  int counter = 1;
  //while loop to find the number of characters in the file
  while (c != EOF) {
    c = fgetc(f);
    counter++;
  }

  fclose(f);

  //creating a dynamic string to store all the characters
  char *string = (char *) malloc((counter) * sizeof(char));

  f = fopen(argv[1], "r");

  //store the first character
  c = fgetc(f);
  string[0] = c;

  int i = 1;
  //while loop to store all the characters
  while (c != EOF) {
    c = fgetc(f);
    string[i] = c;
    i++;
  }
  //setting the terminating character
  string[strlen(string)-1] = '\0';

  //declaring a breakCounter variable to break the line
  int breakCounter = 0;

  //for loop to insert endline characters
  for (int i = 0; i < counter; i++) {
    breakCounter++;
    //reset the counter if there's an endline character
    if (string[i] == '\n') {
      breakCounter = 0;
    }
    //insert endline character at 72
    if (breakCounter > 72) {
      //while loop to find the whitespace
      while (string[i] != ' ') {
        i--;
      }
      //replace the whitespace with endline character
      string[i] = '\n';
      //resetting the breakCounter
      breakCounter = 0;
    }
  }

  f = fopen (argv[2], "w");

  //writing the string into the file
  fprintf(f, "%s", string);

  fclose(f);

  return 0;
}
