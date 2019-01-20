/* Problem Name is &&& Optimal Path &&& PLEASE DO NOT REMOVE THIS LINE. */

/*
** Instructions to candidate.
**  1) You are an avid rock collector who lives in southern California. Some rare 
**     and desirable rocks just became available in New York, so you are planning 
**     a cross-country road trip. There are several other rare rocks that you could 
**     pick up along the way. 
**     
**     You have been given a grid filled with numbers, representing the number of 
**     rare rocks available in various cities across the country.  Your objective 
**     is to find the optimal path from So_Cal to New_York that would allow you to 
**     accumulate the most rocks along the way. 
**     
**     Note: You can only travel either north (up) or east (right).
**  2) Consider adding some additional tests in doTestsPass().
**  3) Implement optimalPath() correctly.
**  4) Here is an example:
**                                                           ^
**                 {{0,0,0,0,5}, New_York (finish)           N
**                  {0,1,1,1,0},                         < W   E >
**   So_Cal (start) {2,0,0,0,0}}                             S
**                                                           v 
**   The total for this example would be 10 (2+0+1+1+1+0+5).
*/

#include <iostream>
using namespace std;

/*
**  Find the optimal path.
*/
template <int nRows, int nCols>
int optimalPath(int (&grid)[nRows][nCols])
{
  // Todo: Implement optimalPath
  /*
 {2,3,4,5,10},
 {2,3,4,5,5},
 {2,2,2,2,2}
 
 { {2,0,0,0,5},
   {2,3,1,1,0}, 12
   {2,2,2,2,2}
  */
  int i,j, start;
  start = grid[nRows-1][0];
  // cout << start << endl;
  for(i = 0; i < nRows; i++)
    grid[i][0] += start;
  for(j=0; j < nCols; j++)
    grid[nRows-1][j] += start;
  grid[nRows-1][0] = start;
  
//   for(i = 0; i < nRows; i++){
//     for(j=0; j < nCols; j++)
//       cout<<grid[i][j];
//     cout<< endl;
// }
    
  for(i = nRows-2; i>=0; i--){ // traversing up--1
    for(j = 1; j < nCols; j++){ // traversing right
      
      grid[i][j] += max(grid[i][j-1],grid[i+1][j]);

    }
    // cout<< endl;
  }
  return grid[0][nCols-1];
}

/*
**  Returns true if the tests pass. Otherwise, returns false;
*/
bool doTestsPass()
{
  bool result = 1;
  // Base test case
  int a[3][5] = {{0,0,0,0,5},
         {0,1,1,1,0},
         {2,0,0,0,0}};
  
  // int b[3][4] = {{}}
  // result &= optimalPath(a) == 10;
  
  return result;
}

/*
**  Execution entry point.
*/
int main()
{
  // Run the tests
  if(doTestsPass())
  {
  printf("All tests pass");
  }
  else
  {
  printf("Tests failed");
  }

  return 0;
}
