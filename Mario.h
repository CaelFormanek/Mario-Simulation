/*
a. Cael Formanek
b. 2416167
c. cformanek@chapman.edu
d. CPSC 350 - 03
e. PA2: Not So Super Mario Bros.
*/

#pragma once

#include <string>
#include <stdlib.h>
#include <time.h>

class Mario
{
  private:
    int numCoins; // number of coins
    int powerLevel; // power level
    int N; // grid dimension
    int V; // number of lives
    int xPos; // x position on grid
    int yPos; // y position on grid
    int consecutiveKills; // consecutive kills
    int numMoves;

  public:
    Mario(); // default constructor
    Mario(int numCoins, int powerLevel, int N, int V, int xPos, int yPos, int consecutiveKills, int numMoves); // overloaded constructor
    ~Mario(); // default destructor

    std::string move(); // moves Mario randomly
    char fight(char c); // fighting an enemy
    char collectMushroom(); // collecting a mushroom
    char collectCoin(); // collecting a coin
    char interact(char c); // interacting with entities on grid
    
    int getNumCoins(); // getter
    void setNumCoins(int newNumCoins); // getter
    int getPowerLevel(); // getter
    void setPowerLevel(int newPowerLevel); // setter
    int getV(); // getter
    void setV(int newV); // setter
    int getXPos(); // getter
    void setXPos(int newXPos); // setter
    int getYPos(); // getter
    void setYPos(int newYPos); // setter
    int getConsecutiveKills(); // getter
    void setConsecutiveKills(int newConsecutiveKills); // setter
    int getNumMoves(); // getter
    void setNumMoves(int newNumMoves); // setter
};