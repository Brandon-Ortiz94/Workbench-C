/**
 * Header file for the summary component, responsible for storing the
 * count of wins and ties and printing the report at the end.
 * @author Brandon Ortiz
 * @file summary.h
*/

// Add extern variable declarations for the three counters
// defined in summary.c

/**
 * The total number of times player A has won.
 */
extern int AWinTotal;

/**
 * The total number of times player B has won.
 */
extern int BWinTotal;

/**
 * The total number of times player A and B have tied.
 */
extern int TieTotal;


/**
 * Prototype for the report summary. 
 * 
 * @brief This function reports the total wins and losses of each player.
 */
void reportSummary();
