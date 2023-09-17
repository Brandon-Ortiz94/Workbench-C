/**
 * This program reads 2D point coordinates from standard input and counts 
 * the number of points that are inside a 20 x 20 square centered on the
 * origin.
 * 
 * A point is considered inside the square if the absolute value of its
 * coordinates are both less than or equal to 10.
 * 
 *   x = -10                                             x = 10
 *   .  .  .  .  .  .  .  .  .  . |  .  .  .  .  .  .  .  .  .  .  y = 10
 *   .     (inside)               |                             .
 *   .     .(-7, 8)               |                             .
 *   .                            |                             .
 *   .                            |                             .
 *   .                            |                             .
 *   .                            |                             .
 *   .                            |                             .
 *   .                            |                             .
 *   .                            |                             .
 *   .____________________________|_____________________________.
 *   .                            |                             .
 *   .                            |                             .
 *   .                            |                             .
 *   .                            |                             .  (outside)
 *   .                            |                             .  .(11, -4) 
 *   .                            |                             .
 *   .                            |                             .
 *   .                            |                             .
 *   .                            |                             .
 *   .  .  .  .  .  .  .  .  .  . |  .  .  .  .  .  .  .  .  .  . y = -10
 * 
 * This programs implementation contains the following restrictions:
 * - No if or switch statements; branching is handled by ternary statements
 * - No looping statements; loops are handled by ternary statements 
 *   coupled with recursion
 * @file square.c
 * @author Brandon Ortiz
 */

#include <stdio.h>
#include <stdlib.h>

/**
 * Returns the absolute value an argument (a coordinate).
 * 
 * @param val the element for which an absolute value is calculated
 * 
 * @return double returns the absolute value (a non-negative integer)of the 
 *         given element
 */
double absolute( double val )
{
  return val < 0 ? -val : val;
}

/**
 * Accepts a pair of coordinates (two doubles) and returns true (1) 
 * if the given coordinate is within the 20 x 20 cartesian map.
 * 
 * @param x the x coordinate
 * @param y the y coordinate
 * 
 * @return int returns true (1) if the coordinate pair is within the 
 *         20 x 20 cartesian map this program covers, false (0) otherwise
 */ 
int inside( double x, double y )
{
  // Are x and y coordinates within their min/max values?
  return absolute( x ) <= 10 && absolute( y ) <= 10 ? 1 : 0;
}


/**
 * Recursive helper function for countPoints() that checks if a given
 * x and y coordinate are within the boundaries of the mapped area this 
 * program covers. 
 * 
 * Each recursive call asks if the passed coordinates are within bounds and
 * incrementing num for valid coordinate.
 * 
 * Yes/No presents the binary option of true/false paths, with each path 
 * checking if there are more coordinates to check (EOF), and recursively calling
 * itself to check the validity of the given coordinates.
 * 
 * The base case for this recursion is no more coordinates left to check, at
 * which point the recursion collapses down returning num.
 * 
 * @param x the x coordinate
 * @param y the y coordinate
 * @param num the number of valid coordinates verified to exist on the 
 *            mapped area
 * 
 * @return int the number of coordinates verified to exist within mapped area
 */
int counter(double x, double y, int num) 
{
  // Are the coordinates provided within bounds?
  return inside( x, y ) ? 
    // Yes, incremement and continue evaluating
    (num += 1), 
      // Are there more coordinates to check
      scanf( "%lf%lf", &x, &y ) == EOF ? 
        // Base case: no
        num : 

        // Recursive case: Yes
        counter( x, y, num )

    // Not within bounds, are there more coordinates?
    : scanf( "%lf%lf", &x, &y ) == EOF ?
      // There are no more coordinates
      num :
      // There are more coordinates
      counter( x, y, num ) ;
}

/**
 * No argument function that opens up standard input and reads in 2D points 
 * from the input, counting how many of the coordinates read in are within
 * the mapped area covered by this program.
 * 
 * @return int the number of given points that are within the cartesian maps
 *         limits
 */
int countPoints()
{
  double x, y; // The coordinates x and y
  int num = 0; // The counter for how many coordinates are within bounds

  // Start reading in coordinates
  return scanf( "%lf%lf", &x, &y) == EOF ?
    // There was only this set of coordinates to read in
    inside( x, y ) ? ++num : 0 :
      // Only one coordinate was provided, if within bounds, increment counter
    counter( x, y, num) ;

}

int main()
{
  // Count all the points and print the result.
  printf( "%d\n", countPoints() );
  
  return EXIT_SUCCESS;

}
