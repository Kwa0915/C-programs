#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "string_utils.h"

int main (int argc, char **argv) {

  char word[] = "Dank OT memes are where its at!";
  altCaps(word);
  printf("%s\n", word);

  char word2[] = "Institute Electrical Electronics Engineers";
  char *copy = substringToEnd(word2, 3);
  printf("%s\n", copy);

  char word3[] = "Cornhuskers";
  char *copy2 = substringIndex(word3, 4, 10);
  printf("%s\n", copy2);

  char word4[] = "Institute Electrical Electronics Engineers";
  char *copy3 = substringSize(word4, 0, 4);
  printf("%s\n", copy3);

  return 0;
}
