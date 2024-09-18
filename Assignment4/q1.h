#ifndef Q1_H
#define Q1_H

// declarations

extern char *pointer1;               // a pointer to a character
extern int array1[10];               // an array of 10 integers
extern int (&reference1)[10];        // a reference to an array of 10 integers
extern char (*pointer2)[5];          // a pointer to an array of character strings
extern char **pointer3;              // a pointer to a pointer to a character
extern const int integer1;           // a constant integer
extern const int *pointer4;          // a pointer to a constant integer
extern int *const pointer5;          // a constant pointer to an integer
extern const double *const pointer6; // a constant pointer to a constant double

#endif // Q1.H