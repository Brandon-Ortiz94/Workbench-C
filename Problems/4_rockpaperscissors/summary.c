/**
  Implmementation file for the summary component, responsible for storing the
  count of wins and ties and printing the report at the end.
  @author Instructors
  @file summary.c
*/

#include "summary.h"

#include <stdio.h>

// Win, lose and tie counters.  These need extern declarations in the header.
int AWinTotal = 0;
int BWinTotal = 0;
int TieTotal = 0;

void reportSummary()
{
  printf( "+--------+-------+\n" );
  printf( "| A Wins | %5d |\n", AWinTotal );
  printf( "+--------+-------+\n" );
  printf( "| B Wins | %5d |\n", BWinTotal );
  printf( "+--------+-------+\n" );
  printf( "| Ties   | %5d |\n", TieTotal );
  printf( "+--------+-------+\n" );
}
