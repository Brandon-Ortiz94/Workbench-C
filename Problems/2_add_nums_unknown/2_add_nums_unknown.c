/*
  Reads a sequence of real numbers in a set and report the minimum, 
  maximum, and average values. This programs assumes that it is
  not known how many numbers are in the set.

  This program accepts input and prints to standard IO, user may call
  this program with IO redirection with no negative impacts. Output format
  is human friendly.

  Compile from CLI: gcc -Wall -std=c99 add_nums_unknown.c -o add_nums_unknown
 */
#include <stdio.h>
#include <stdlib.h>

/*
  Start of program. This program evaluates how many numbers exist in the given
  input source. Input is delimmited by all numerical entries delimitted by EOF
  that meet the conversion specifier %lf (double) formatting requirements.

  This program currently calculates minimum, maximum, total, and average of
  all values provided but can easily be expanded to incldue more complex 
  computations.
*/
int main(void)
{
  /* 
    n is the number of elements in the set.
  */
  int n = 0;

  /* 
    Val is the current value being assessed. Total is the sum of all numbers
    processed so far. Minimum and maximum refer to the largest/smallest number. 
  */
  double val = 0, total = 0, minimum = 0, maximum = 0;

  /* 
    A while-loop controlled by scanf()'s return value with a terminating condition
    of EOF (expanded to -1). The loop processes the numbers in the set performing
    computations on each iteration and actioning updates where prompted.

    On the first iteration of the while loop, the program handles initial 
    assignment of values; subsequent iterations focus on comparing min and
    max values and updating if appropriate.
  */
  while ( scanf( "%lf", &val ) != EOF ) {
    n++;
    total += val;

    if (n == 1) {
      minimum = val;
      maximum = val;
    } else {
      if ( val > maximum ) maximum = val;
      if ( val < minimum ) minimum = val;
    }
  }
  printf( "There are %d numbers in this set.\n", n );

  // Report minimum value
  printf( "Minimum:%9.2f\n", minimum );
  // Report maximum value
  printf( "Maximum:%9.2f\n", maximum );
  // Report average of all values
  printf( "Average:%9.2f\n", total/n);

  // Exit successfully.
  return EXIT_SUCCESS;
  }
