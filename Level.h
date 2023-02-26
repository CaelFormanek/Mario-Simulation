/*
a. Cael Formanek
b. 2416167
c. cformanek@chapman.edu
d. CPSC 350 - 03
e. PA2: Not So Super Mario Bros.
*/

#pragma once

class Level
{
  private:
    int levelNumber; // the level number
    int L; // number of levels
    int N; // grid dimension
    int xPos; // starting x position for Mario
    int yPos; // starting y position for Mario
    int percentCoins; // percentage of a level with coins
    int percentNothing; // percenatge of a level with nothing
    int percentGoombas; // percentage of a level with Goombas
    int percentKoopas; // percentage of a level with Koopas
    int percentMushrooms; // percentage of a level with Mushrooms
    char** grid; // grid for each level
    
  public:
    Level(); // default constructor
    Level(int levelNumber, int L, int N, int percentCoins, int percentNothing, int percentGoombas, int percentKoopas, int percentMushrooms); // overloaded constructior
    ~Level(); // default destructor

    char** getGrid(); // get grid
    int getLevelNumber(); // getter
    void setLevelNumber(int newLevelNumber); // setter
    int getXPos(); // getter
    void setXPos(int newXPos); // setter
    int getYPos(); // getter
    void setYPos(int newYPos); // setter
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