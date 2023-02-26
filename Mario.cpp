/*
a. Cael Formanek
b. 2416167
c. cformanek@chapman.edu
d. CPSC 350 - 03
e. PA2: Not So Super Mario Bros.
*/

#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <time.h>
#include "Mario.h"

/* default constructor */
Mario::Mario()
{
  this->numCoins = 0;
  this->powerLevel = 0;
  this->N = 0;
  this->V = 0;
  this->xPos = 0;
  this->yPos = 0;
  this->consecutiveKills = 0;
  this->numMoves = 0;
}

/* overloaded constructor */
Mario::Mario(int numCoins, int powerLevel, int N, int V, int xPos, int yPos, int consecutiveKills, int numMoves)
{
  this->numCoins = numCoins;
  this->powerLevel = powerLevel;
  this->N = N;
  this->V = V;
  this->xPos = xPos;
  this->yPos = yPos;
  this->consecutiveKills = consecutiveKills;
  this->numMoves = numMoves;
}

/* default destructor */
Mario::~Mario()
{
  
}

/* moves Mario randomly */
std::string Mario::move()
{
  /* increases the number of moves each time he moves */
  this->numMoves += 1;
  
  int randNum = rand()%(4-1 + 1) + 1; // picks a random number 1-4

  if (randNum == 1) {this->xPos += 1; if (this->xPos > (N-1)){this->xPos = 0;} if (this->xPos < 0) {this->xPos = (N-1);} return "RIGHT";} 
  if (randNum == 2) {this->xPos -= 1; if (this->xPos > (N-1)){this->xPos = 0;} if (this->xPos < 0) {this->xPos = (N-1);} return "LEFT";} 
  if (randNum == 4) {this->yPos -= 1; if (this->yPos > (N-1)){this->yPos = 0;} if (this->yPos < 0) {this->yPos = (N-1);} return "UP";} 
  if (randNum == 3) {this->yPos += 1; if (this->yPos > (N-1)){this->yPos = 0;} if (this->yPos < 0) {this->yPos = (N-1);} return "DOWN";} 
  
  return "DID NOT MOVE";
}

/* fighting an enemy */
char Mario::fight(char c)
{
  int winning = rand()%(100-1 + 1) + 1; // random num between 1-100

  if (this->V == 0) {return 't';} // t will end the simulation
  
  /* case for a Goomba */
  if (c == 'g')
  {
    if (winning > 20) 
    {
      this->consecutiveKills += 1;
      if (this->consecutiveKills == 7) {this->V += 1;}
      return 'x';
    } // the spot has nothing now, move on
    else 
    {
      this->consecutiveKills = 0;
      if (this->powerLevel < 1) {this->V -= 1;} // if PL0 , lose a life
      this->powerLevel -= 1; // decrease powerLevel
      if (this->powerLevel < 0) {this->powerLevel = 0;} // powerLevel can't be less than 0
      if (this->V == 0) {return 't';} // t will end the simulation
    }
  }

  /* case for a Koopa Troopa */
  if (c == 'k')
  {
    if (winning > 35)
    {
      this->consecutiveKills += 1;
      if (this->consecutiveKills == 7) {this->V += 1;}
      return 'x';
    } // the spot has nothing now, move on
    else 
    {
      this->consecutiveKills = 0;
      if (this->powerLevel < 1) {this->V -= 1;} // if PL0 or PL1, lose a life
      this->powerLevel -= 1; // decrease powerLevel
      if (this->powerLevel < 0) {this->powerLevel = 0;} // powerLevel can't be less than 0
      if (this->V == 0) {return 't';} // t will end the simulation
    }
  }

  /* case for a Boss */
  if (c == 'b')
  {
    if (winning > 50)
    {
      this->consecutiveKills += 1;
      if (this->consecutiveKills == 7) {this->V += 1;}
      return 'x';
    } // the spot has nothing now, move on
    else 
    {
      this->consecutiveKills = 0;
      if (this->powerLevel < 2) {this->V -= 1;} // if PL0 or PL1, lose a life
      this->powerLevel -= 2; // decrease powerLevel
      if (this->powerLevel < 0) {this->powerLevel = 0;} // powerLevel can't be less than 0
      if (this->V == 0) {return 't';} // t will end the simulation
    }
  }

  return c; // only happens when Mario loses a fight
}

/* collecting a mushroom */
char Mario::collectMushroom()
{
  if (this->powerLevel == 2) {} // do nothing
  else {this->powerLevel += 1;} // otherwise increase the powerLevel

  return 'x'; // the spot now contains nothing
}

char Mario::collectCoin()
{
  this->numCoins += 1;
  if (this->numCoins == 20)
  {
    this->V += 1; // increase the number of lives
    this->numCoins = 0; // reset the coins to 0
  }

  return 'x'; // the spot now contains nothing
}

/* interacting with entities on the grid */
char Mario::interact(char c)
{
  /* in the case there is an enemy */
  char enemyArr[3] = {'g', 'k', 'b'};
  for (char enemy : enemyArr)
  {
    if (c == enemy) {return fight(enemy);}
  }

  /* in the case there is a mushroom */
  if (c == 'm') {return collectMushroom();}

  /* in the case there is a coin */
  if (c == 'c') {return collectCoin();}

  /* in the case there is a warp pipe */
  if (c == 'w') {return c;} // the simulate function will check for a return value w

  /* in this case there is nothing */
  return c;
}

/* get numCoins*/
int Mario::getNumCoins()
{
  return numCoins;
}

/* sets numCoins*/
void Mario::setNumCoins(int newNumCoins)
{
  this->numCoins = newNumCoins;
}

/* gets powerLevel */
int Mario::getPowerLevel()
{
  return powerLevel;
}

/* sets powerLevel */
void Mario::setPowerLevel(int newPowerLevel)
{
  this->powerLevel = newPowerLevel;
}

/* gets V */
int Mario::getV()
{
  return V;
}

/* sets V */
void Mario::setV(int newV)
{
  this->V = newV;
}

/* gets xPos */
int Mario::getXPos()
{
  return xPos;
}

/* sets xPos */
void Mario::setXPos(int newXPos)
{
  this->xPos = newXPos;
}

/* gets yPos */
int Mario::getYPos()
{
  return yPos;
}

/* sets xPos */
void Mario::setYPos(int newYPos)
{
  this->yPos = newYPos;
}

/* gets consecutiveKills */
int Mario::getConsecutiveKills()
{
  return consecutiveKills;
}

/* sets consecutiveKills */    
void Mario::setConsecutiveKills(int newConsecutiveKills)
{
  this->consecutiveKills = newConsecutiveKills;
}

/* gets numMoves */
int Mario::getNumMoves()
{
  return numMoves;
}

/* sets NumMoves */
void Mario::setNumMoves(int newNumMoves)
{
  this->numMoves = newNumMoves;
}