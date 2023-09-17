/** 
 * Implementation file for the game component, responsible for
 * determining the winner of a rock-paper-scissors game.
 * @author Brandon Ortiz
 * @file game.c
*/

#include "game.h"
#include "summary.h"

#include <stdlib.h>
#include <stdio.h>

/** 
 * Called when the program gets a word starting with an invalid letter.
 * It prints an error message and exits the program unsuccessfully.
 * 
 * This funciton is static, so it's not visible to other components.
 * It's for internal use only by this component, and it shouldn't not
 * get a prototype in the header.
 */
static void invalid()
{
  printf( "Invalid character\n" );
  exit( EXIT_FAILURE );
}

void decideGame( char alet, char blet )
{
  // Throw invalid if the character is not one of the acceptables
  if ( alet != 'r' && alet != 'p' && alet != 's' 
    && blet != 'r' && blet != 'p' && blet != 's' ) {
      invalid();
  }

  // Possible play combos
  if ( alet == 'r' && blet == 'p' ) {
    ++BWinTotal;
    printf( "%s", "Player B wins\n" );
  }
  else if ( alet == 'p' && blet == 'p' ) {
    ++TieTotal;
    printf( "%s", "Players tie\n" );
  }
  else if ( alet == 's' && blet == 'p' ) {
    ++AWinTotal;
    printf( "%s", "Player A wins\n" );
  }

  else if ( alet == 'r' && blet == 's' ) {
    ++AWinTotal;
    printf( "%s", "Player A wins\n" );
  }
  else if ( alet == 'p' && blet == 's' ) {
    ++BWinTotal;
    printf( "%s", "Player B wins\n" );
  }
  else if ( alet == 's' && blet == 's' ) {
    ++TieTotal;
    printf( "%s", "Players tie\n" );
  }

  else if ( alet == 'r' && blet == 'r' ) {
    ++TieTotal;
    printf( "%s", "Players tie\n" );
  }
  else if ( alet == 'p' && blet == 'r' ) {
    ++AWinTotal;
    printf( "%s", "Player A wins\n" );
  }
  else if ( alet == 's' && blet == 'r' ) {
    ++BWinTotal;
    printf( "%s", "Player B wins\n" );
  }

}
