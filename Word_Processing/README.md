# Word Operations

This folder contain some of the tools for processing sentences or word documents.

## Strings processing

[string_utils.c](/string_utils.c) and [string_utils.h](/string_utils.h) are used to operate on strings, or arrays of char types. Below describes some of the functions of strings operation.

### Convert to Alternating Caps
```
altCaps(char *s)
```

This function converts a string to an alternating caps format in which the first letter is lower case and every other letter is alternating between upper and lower case.

### Returning substring to end
```
substringToEnd(const char *s, int beginningIndex)
```

This function takes a string and returns a new copy of a substring of it starting from a specified index to the end of the string.

### Returning substring with specified snding
```
substringIndex(const char *s, int beginIndex, int endIndex)
```

This function takes a string and returns a new copy of a substring of it starting from a specified index to a specified ending index.

### Returning substring with specified size
```
substringSize(const char *s, int beginningIndex, int size)
```

This function takes a string and returns a new copy of a substring of it starting from a specified index of a particular size.

## Removing duplicate lines

[uniqueLines.c](/uniqueLines.c) can be used to remove any duplicate lines and output the unique lines to a new output file.

## Formatting long lines

[formatFile.c](/formatFile.c) can be used to process a text file with long lines and reformats it by inserting line breaks so that lines have no more than 72 characters.

###### Assignment 4 CSCE155E Fall 2019 - Prof. Chris Bourke