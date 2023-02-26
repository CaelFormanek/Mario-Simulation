/*
a. Cael Formanek
b. 2416167
c. cformanek@chapman.edu
d. CPSC 350 - 03
e. PA2: Not So Super Mario Bros.
*/

#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "Level.h"

/* default constructor */
Level::Level()
{
  this->levelNumber = 0;
  this->L = 0;
}

/* overloaded constructor */
Level::Level(int levelNumber, int L, int N, int percentCoins, int percentNothing, int percentGoombas, int percentKoopas, int percentMushrooms)
{
  this->levelNumber = levelNumber;
  this->L = L;
  this->percentCoins = percentCoins;
  this->percentNothing = percentNothing;
  this->percentGoombas = percentGoombas;
  this->percentKoopas = percentKoopas;
  this->percentMushrooms = percentMushrooms;

  /* initialize the grid */
  grid = new char*[N];
  for (int i = 0; i < N; i++)
  {
    grid[i] = new char[N];
  }
  
  /* based off percentages, create a number of each object for the grid */
  double divide = 100.00;
  char charArr[N*N];
  int numCoins = ((double)percentCoins/divide) * (N*N);
  int numNothing = ((double)percentNothing/divide) * (N*N);
  int numGoombas = ((double)percentGoombas/divide) * (N*N);
  int numKoopas = ((double)percentKoopas/divide) * (N*N);
  int numMushrooms = ((double)percentMushrooms/divide) * (N*N);

  /* use the sums to add each amount to grid */
  int sum1 = numCoins;
  int sum2 = numNothing+numCoins;
  int sum3 = numGoombas+numNothing+numCoins;
  int sum4 = numKoopas+numGoombas+numNothing+numCoins;
  int sum5 = numMushrooms+numKoopas+numGoombas+numNothing+numCoins;
  for (int i  = 0; i < sum1; i++) {charArr[i] = 'c';}
  for (int i = sum1; i < sum2; i++) {charArr[i] = 'x';}
  for (int i = sum2; i < sum3; i++) {charArr[i] = 'g';}
  for (int i = sum3; i < sum4; i++) {charArr[i] = 'k';}
  for (int i = sum4; i < sum5; i++) {charArr[i] = 'm';}

  int rowb = rand()%(N-1-0 + 1) + 0; // rand num between 0-(N-1)
  int colb = rand()%(N-1-0 + 1) + 0; // rand num between 0-(N-1)

  int roww = rand()%(N-1-0 + 1) + 0; // rand num between 0-(N-1)
  int colw = rand()%(N-1-0 + 1) + 0; // rand num between 0-(N-1)

  int rowH = rand()%(N-1-0 + 1) + 0; // rand num between 0-(N-1)
  int colH = rand()%(N-1-0 + 1) + 0; // rand num between 0-(N-1)
  
  /* randomize array */
  for (int i = 0; i < N*N; i++)
  {
    char temp = charArr[i];
    int randomNum = rand()%(((N*N)-1)-0 + 1) + 0; // num between 0-((N*N)-1)
    char temp2 = charArr[randomNum];
    charArr[i] = temp2;
    charArr[randomNum] = temp;
  }

  int iter = 0;
  /* fill array */
  for (int i = 0; i < N; i++)
  {
    for (int j = 0; j < N; j++)
    {
      grid[i][j] = charArr[iter];
      iter++; 
    }
  }
  
  /* implement exactly one boss, using random coordinates */
  char b = 'b';
  grid[rowb][colb] = b;

  /* if it is not the last level, implement one warp pipe, using random coordinates */
  if (levelNumber != L)
  {
    char w = 'w';
    grid[roww][colw] = w;
  }

  /* give Mario a place to start, using random coordinates */

  this->xPos = colH; // get the starting position for Mario
  this->yPos = rowH; // get the starting position for Mario
}

/* default destructor */
Level::~Level()
{
  for (int i = 0; i < N; i++)
  {
      delete[] grid[i]; 
  }
  delete[] grid;
}

/* gets grid */
char** Level::getGrid()
{
  return grid;
}

/* gets levelNumber */
 int Level::getLevelNumber()
 {
  return levelNumber;
 }

/* sets levelNumber */
void Level::setLevelNumber(int newLevelNumber)
{
  this->levelNumber = newLevelNumber;
}

/* gets xPos */
int Level::getXPos()
{
  return xPos;
}

/* sets xPos */
void Level::setXPos(int newXPos)
{
  this->xPos = newXPos;
}

/* gets yPos */
int Level::getYPos()
{
  return yPos;
}

/* sets xPos */
void Level::setYPos(int newYPos)
{
  this->yPos = newYPos;
}

/* gets percentCoins */
int Level::getPercentCoins()
{
  return percentCoins;
}

/* sets percentCoins */
void Level::setPercentCoins(int newPercentCoins)
{
  this->percentCoins = newPercentCoins;
}

/* gets percentNothing */
int Level::getPercentNothing()
{
  return percentNothing;
}

/* sets percentNothing */
void Level::setPercentNothing(int newPercentNothing)
{
  this->percentNothing = newPercentNothing;
}

/* gets percent Goombas */
int Level::getPercentGoombas()
{
  return percentGoombas;
}

/* sets percentGoombas */
void Level::setPercentGoombas(int newPercentGoombas)
{
  this->percentGoombas = newPercentGoombas;
}

/* gets percentKoopas */
int Level::getPercentKoopas()
{
  return percentGoombas;
}

/* sets percentKoopas */
void Level::setPercentKoopas(int newPercentKoopas)
{
  this->percentKoopas = newPercentKoopas;
}

/* gets percentMushrooms */
int Level::getPercentMushrooms()
{
  return percentMushrooms;
}

/* sets percentMushrooms */
void Level::setPercentMushrooms(int newPercentMushrooms)
{
  this->percentMushrooms = newPercentMushrooms;
}