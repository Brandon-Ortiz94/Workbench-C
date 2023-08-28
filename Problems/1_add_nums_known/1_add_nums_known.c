/*
  Read a sequence of real numbers in a set and report the minimum, 
  maximum, and average values. This program assumes it is known
  how many numbers are in the set.

  Compile from CLI: gcc -Wall -std=c99 add_nums_known.c -o add_nums_known
 */
#include <stdio.h>
#include <stdlib.h>

/*
  Start of program. This program demands that the first value entered 
  indicates n, where n equals how many elements exist in the set.

  Once identified, the program will loop n times, once for each possible
  value. On each loop the program will assess the given value against 
  min/max values, reassigning if needed, and adds the value to the total.

  The total is used (with n) to calculate the average of the values.

  This program accepts input and prints to standard IO, user may call
  this program with IO redirection with no negative impacts.
*/
int main(void)
{
  /* 
    n is the first value entered into the program and indicates how many
    values there are to process. It is not part of the set.
  */
  int n;

  // Read in the first value.
  scanf( "%d", &n );

  // Diagnostic message to help with tracking inputs
  // printf( "There are %lf numbers in this set.\n", n );

  /* 
    Val is the current value being assessed. Total is the sum of all numbers
    processed so far. Minimum and maximum refer to the largest/smallest number. 
  */
  double val, total = 0, minimum, maximum;

  /* 
    A for-each loop delimited by n, the number of values to process. 
    Min/max values are assigned during the first loop and checked for 
    each consecutive loop; the current number is added into the total. 
  */
  for (int i = 0; i < n; i++) {
    scanf( "%lf", &val );

    // Min/max checks
    if (i == 0) {
      minimum = val;
      maximum = val;
    } else {
      if (val > maximum) maximum = val;
      if (val < minimum) minimum = val;
    }
    
    // Add to total
    total += val;

    // Diagnostic messages to help with tracking inputs
    // printf( "The number %lf was entered.\n", val );
    // printf( "The minimum is now %lf.\n", n );
    // printf( "The maximum is now %lf.\n", n );
  }

  // Report minimum value
  printf( "Minimum:%9.2f\n", minimum );
  // Report maximum value
  printf( "Maximum:%9.2f\n", maximum );
  // Report average of all values
  printf( "Average:%9.2f\n", total/n);

  // Exit successfully.
  return EXIT_SUCCESS;
  }
