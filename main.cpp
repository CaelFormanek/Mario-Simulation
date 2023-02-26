/*
a. Cael Formanek
b. 2416167
c. cformanek@chapman.edu
d. CPSC 350 - 03
e. PA2: Not So Super Mario Bros.
*/

#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
#include <time.h>
#include "World.h"


int main(int argc, char** argv)
{

  srand(time(NULL));
  
  /* open a file called myFile, along with an array to store the numbers*/
  int arr[8];
  int iter = 0;

  /* BEGIN CODE FROM SOURCE: https://stackoverflow.com/questions/14516915/read-numeric-data-from-a-text-file-in-c */ 
  /* input numbers from spec.txt into arr */
  int a;
  std::fstream myFile("spec.txt", std::ios_base::in);
  while (myFile >> a)
  {
    arr[iter] = a;
    iter++;
  }
  /* END OF CODE FROM SOURCE: https://stackoverflow.com/questions/14516915/read-numeric-data-from-a-text-file-in-c */

  /* creating the world with which the simulation will be run */
  World myWorld(arr[0], arr[1], arr[2], arr[3], arr[4], arr[5], arr[6], arr[7]);
  myWorld.simulate();
  

  return 0;
}