/**
 * Main implementation file, responsible for processing all the games and
 * printing the summary at the end.
 * @author Instructors
 * @file tournament.c
*/

// Headers for other components.
#include "input.h"
#include "summary.h"
#include "game.h"

/**
 * @brief Program begins here. This program uses a collection of compilation 
 *        declared in the header to collect inputs from two players to 
 *        determine the winner in a game of rock, paper, scissors.
 */
int main()
{
  // Keep reading games to the end of input.
  char alet, blet;
  while ( ( alet = getInitial() ) != '\0' ) {
    blet = getInitial();

    // Process this game.
    decideGame( alet, blet );
  }

  // Report the summary at the end.
  reportSummary();
}
