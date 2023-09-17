/**
 * Implementation file for the input component, responsible for reading the
 * shape thrown by a player.
 * @author Brandon Ortiz
 * @file input.c
*/
#include "input.h"
#include <stdio.h>
#include <ctype.h>

char getInitial()
{
  // Declare a variable to hold the input being read
  char c;

  // Read in the next char; if the program received EOF (-1), return 0
  if ( ( c = getchar() ) == EOF ) {
    return 0;
  }

  char y = c;

  // Consume the rest of the word, so the next call to getInitial() starts 
  // on the first letter
  while (isalpha( getchar() ));



  return y;

}
