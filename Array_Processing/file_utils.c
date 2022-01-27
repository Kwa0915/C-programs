#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "file_utils.h"

char *getFileContents(const char *filePath) {

  FILE *f = fopen("filePath", "r");
  char buff[100];
  char *s = fgets(buff, 100, f);
  while (s != NULL) {
    s = fgets(buff, 100, f);
  }
  fclose(f);
  return NULL;
}

char **getFileLines(const char *filePath, int *numLines){

  FILE *f = fopen("filePath", "r");
  char *s = fgets(numLines, 100, filePath);
  while (s != NULL) {
    s = fgets(numLines, 100, filePath);
    numLines[strlen(buff)-1] = '\0';
  }
  fclose(f);
  return NULL;
}
