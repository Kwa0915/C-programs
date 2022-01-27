/**
 * Author: Kok Hwa Khor
 * Date: 11/13/2019
 *
 * This program contain the source code of headers for several
 * functions that operate on strings
 */

//this function converts a string to an alternating caps format
void altCaps(char *s);

//this function takes a string and returns a new copy of a
//substring of it starting from a specified index to the
//end of the string
char *substringToEnd(const char *s, int beginningIndex);

//this function takes a string and returns a new copy of a
//substring of it starting from a specified index and going
//a specified ending index
char *substringIndex(const char *s, int beginIndex, int endIndex);

//this function takes a string and returns a new copy of a
//substring of it starting from a specified index of a
//particular size
char *substringSize(const char *s, int beginningIndex, int size);
