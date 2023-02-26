/*
a. Cael Formanek
b. 2416167
c. cformanek@chapman.edu
d. CPSC 350 - 03
e. PA2: Not So Super Mario Bros.
*/

#pragma once

#include "Level.h"
#include "Mario.h"

class World
{
  private:
    int L; // number of levels
    int N; // dimension of the grid
    int V; // number of initial lives
    int percentCoins; // percentage of a level with coins
    int percentNothing; // percenatge of a level with nothing
    int percentGoombas; // percentage of a level with Goombas
    int percentKoopas; // percentage of a level with Koopas
    int percentMushrooms; // percentage of a level with Mushrooms
    Level* levelArr; // holds the levels of the game
    Mario* myMario; // Mario object for the game
    
  public:
    World(); // default constructor
    World(int L, int N, int V, int percentCoins, int percentNothing, int percentGoombas, int percentKoopas, int percentMushrooms); // overloaded constructor
    ~World(); // default destructor

    void simulate(); // simulates the game;

    int getL(); // getter
    void setL(int newL); // setter
    int getN(); // getter
    void setN(int newN); // setter
    int getV(); // getter
    void setV(int newV); // setter
    int getPercentCoins(); // getter
    void setPercentCoins(int newPercentCoins); // setter
    int getPercentNothing(); // getter
    void setPercentNothing(int newPercentNothing); // setter
    int getPercentGoombas(); // getter
    void setPercentGoombas(int newPercentGoombas); // setter
    int getPercentKoopas(); // getter
    void setPercentKoopas(int newPercentKoopas); // setter
    int getPercentMushrooms(); // getter
    void setPercentMushrooms(int newPercentMushrooms); // setter
};