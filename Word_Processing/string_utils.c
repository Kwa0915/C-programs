/**
 * Author: Kok Hwa Khor
 * Date: 11/13/2019
 *
 * This program contain the source code for several functions
 * that operate on strings
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#include "string_utils.h"

void altCaps(char *s) {
  //error checking
  if (s == NULL) {
    return;
  }

  int j = 2;
  //for loop to converts the string
  for (int i = 0; i < strlen(s); i++) {
    //ignoring whitespace character
    if (s[i] == ' ') {
      continue;
    }
    //ignoring characters that are not alphabets
    if ( (s[i]>='a' && s[i]<='z') || (s[i]>='A' && s[i]<='Z') ) {
      //if else statement to alternate caps
      if (j % 2 == 0) {
        s[i] = tolower(s[i]);
      } else {
        s[i] = toupper(s[i]);
      }
      j++;
    }
  }
}

char *substringToEnd(const char *s, int beginningIndex) {
  //error checking
  if (s == NULL || beginningIndex < 0) {
    return NULL;
  }
  //calculating the length for the string
  int n = strlen(s) - beginningIndex;
  //creating a dynamic string
  char *copy = (char *) malloc ((n+1) * sizeof(char));
  int j = 0;
  //for loop that starts from the beginningIndex until the end
  //of the string
  for (int i = beginningIndex; i <= strlen(s); i++) {
    copy[j] = s[i];
    j++;
  }
  //setting the terminating character
  copy[n] = '\0';

  return copy;
}

char *substringIndex(const char *s, int beginIndex, int endIndex) {
  //error checking
  if (s == NULL || beginIndex < 0 || endIndex < 0) {
    return NULL;
  }
  //calculating the length for the string
  int n = endIndex - beginIndex + 1;
  //creating a dynamic string
  char *copy = (char *) malloc((n+1) * sizeof(char));
  int j = 0;
  //for loop that starts from the beginIndex to the endIndex
  for (int i = beginIndex; i < endIndex; i++) {
    copy[j] = s[i];
    j++;
  }
  //setting the terminating character
  copy[j] = '\0';

  return copy;
}

char *substringSize(const char *s, int beginningIndex, int size) {
  //error checking
  if (s == NULL || beginningIndex < 0 || size < 0) {
    return NULL;
  }

  int j = 0;
  //creating a dynamic array
  char *copy = (char *) malloc((size+1) * sizeof(char));
  //for loop that starts from the beginningIndex until the size
  for (int i = beginningIndex; i < size + beginningIndex; i++) {
    copy[j] = s[i];
    j++;
  }
  //setting the terminating character
  copy[j] = '\0';

  return copy;
}
