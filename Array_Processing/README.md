# Array & Matrices Operations

This folder contain some necessary tools for processing arrays and matrices.

## Array Processing

[array_utils.c](/array_utils.c) and [array_utils.h](/array_utils.h) contain several functions that operate on arrays. Below describes some of the functions of array operation.

### Equal Comparison
```
isEqual(const int *a, const int *b, int size)
```

This tool can be used to compare two integer arrays and determine if they are equal.

### Content Reversing
```
reverse(int *a, int size)
```

This tool can be used to reverse the contents of an integer array.

### Content Reversing Copied
```
reverseCopy(const int *a, int size)
```

This tool creates and returns a new copy of a integer array with the contents reversed.

### Content Shifting
```
shift(int *a, int size, int k)
```

This tool shift the contents of an integer array to the right circularly by a specified position.

### Content Shifting Copied
```
shiftCopy(const int *a, int size, int k)
```

This tool creates a copy of the array with the contents circularly shifted to the right by a specified position.

### Find Even Numbers
```
getEvens(const int *a, int size, int *newSize)
```

This tool returns a new array containing only the even elements from an integer array.

### Circulant Matrix
```
circulant(const int *a, int size)
```

This tool takes an array of *n* elements and produces and *n x n* circulant matrix in which the first row consists of the array elements, then each subsequent row contains the same elements, but circularly shifted by one position.

### Matrix Collapsing
```
collapse(int **A, int n, int m)
```
This tool collapses an *n x m* matrix into an array of size *m* by summing all elements in each column.

## Circle Division problem

[Circle](/circle/) contains a program to solve the Circle Division problem which appeared in the 2006 World Puzzle Championsihps for introducing people to problem solving and computer sciecen without a computer.

The puzzle involves a colletion of numbers drawn around a circle. To solve the puzzle, 5 lines were drawn from the circle to the outside, dividing the numbers into five groups. Each group must have the same summation. An example is shown below.

![Circle Division Problem Example](/circle/Example.png)

###### Assignment 3 CSCE155E Fall 2019 - Prof. Chris Bourke