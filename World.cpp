/*
a. Cael Formanek
b. 2416167
c. cformanek@chapman.edu
d. CPSC 350 - 03
e. PA2: Not So Super Mario Bros.
*/

#include <iostream>
#include <fstream>
#include "World.h"

/* default constructor */
World::World()
{
  this->L = 0;
  this->N = 0;
  this->V = 0;
  this->percentCoins = 0;
  this->percentNothing = 0;
  this->percentGoombas = 0;
  this->percentKoopas = 0;
  this->percentMushrooms = 0;
  levelArr = new Level[0];
  myMario = new Mario();
}

/* overloaded constructor */
World::World(int L, int N, int V, int percentCoins, int percentNothing, int percentGoombas, int percentKoopas, int percentMushrooms)
{
  this->L = L;
  this->N = N;
  this->V = V;
  this->percentCoins = percentCoins;
  this->percentNothing = percentNothing;
  this->percentGoombas = percentGoombas;
  this->percentKoopas = percentKoopas;
  this->percentMushrooms = percentMushrooms;

  /* array of levels specified by L */
  levelArr = new Level[L];
  for (int i = 0; i < L; i++)
  {
    Level* lvl = new Level(i+1, L, N, percentCoins, percentNothing, percentGoombas, percentKoopas, percentMushrooms);
    levelArr[i] = *lvl;
  }

  /* initializing Mario to have PL0, 0 coins, and start at a random xy spot */
  myMario = new Mario(0, 0, N, V, levelArr[0].getXPos(), levelArr[0].getYPos(), 0, 0);
}

/* default destructor */
World::~World()
{
  delete[] levelArr;
  delete myMario;
}

/* simulates the game */
void World::simulate()
{
  std::string divider = "==========";
  /* BEGIN CODE FROM SOURCE:https://cplusplus.com/doc/tutorial/files/ */ 
  std::ofstream myFile;
  myFile.open("log.txt");
  /* END OF CODE FROM SOURCE: https://cplusplus.com/doc/tutorial/files/ */

  /* for each level in the world */
  for (int i = 0; i < L; i++)
  {
    /* print original grid */
    for (int a = 0; a < N; a++)
    {
      if (a > 0) {myFile << "" << std::endl;}
      for (int b = 0; b < N; b++)
      {
        myFile << levelArr[i].getGrid()[a][b];
      }
    }
    myFile << "" << std::endl;

    /* divider */
    myFile << divider << std::endl;

    /* sets beginning coordinates for Mario */
    int yPos = levelArr[i].getYPos();
    int xPos = levelArr[i].getXPos();

    /* char previously at Mario's position */
    char prevChar = levelArr[i].getGrid()[yPos][xPos];

    /* sets Mario's position on grid */
    myMario->setYPos(yPos);
    myMario->setXPos(xPos);
    levelArr[i].getGrid()[yPos][xPos] = 'H';

    /* starting position */
    myFile << "Mario is starting in position: (" << levelArr[i].getYPos() << "," << levelArr[i].getXPos() << ")" << std::endl;

    /* divider */
    myFile << divider << std::endl;

    /* print updated grid */
    for (int a = 0; a < N; a++)
    {
      if (a > 0) {myFile << "" << std::endl;}
      for (int b = 0; b < N; b++)
      {
        myFile << levelArr[i].getGrid()[a][b];
      }
    }
    myFile << "" << std::endl;

    /* divider */
    myFile << divider << std::endl;

    /* start cycle of movement and interactions */
    while (true)
    {
      myFile << "Level: " << levelArr[i].getLevelNumber()-1 << ". ";
      myFile << "Mario is at position: (" << myMario->getYPos() << "," << myMario->getXPos() << "). ";
      myFile << "Mario is at power level " << myMario->getPowerLevel() << ". ";

      /* have Mario interact with an entity */
      char spotTracker = myMario->interact(prevChar);

      /* cover the interaction cases */
      if (prevChar == 'g') // goomba
      {
        if (spotTracker == 'x') {myFile << " Mario encountered a goomba and won. ";}
        else {myFile << " Mario encountered a goomba and lost. ";}
      } 
      if (prevChar == 'k') // koopa
      {
        if (spotTracker == 'x') {myFile << " Mario encounterd a koopa and won. ";}
        else {myFile << " Mario encountered a koopa and lost. ";}
      } 
      if (prevChar == 'x') // nothing
      {
        myFile << " Mario visited an empty space. ";
      } 
      if (prevChar == 'm') // mushroom
      {
        myFile << " Mario collected a mushroom. ";
      } 
      if (prevChar == 'c') // coin
      {
        myFile << " Mario collected a coin. ";
      }
      if (prevChar == 'w') // warp pipe
      {
        myFile << " Mario found a warp pipe." << " Mario has " << myMario->getV() << " lives left. Mario has " << myMario->getNumCoins() << " coins. Mario will WARP. " << std::endl;
        break;
      }
      
      /* creates a boolean that will check whether Mario should skip the level after defeating the boss */
      bool nextLevel = false;

      /* checks if Mario has defeated boss */
      if (prevChar == 'b') // boss
      {
        bool bossDefeated = false;
        while (bossDefeated == false)
        {
          if (spotTracker == 'x')
          {
            bossDefeated = true;
            myFile << " Mario encountered a boss and won. ";
            if (levelArr[i].getLevelNumber() == L)
            {
              myFile << "Mario has " << myMario->getV() << " lives left. Mario has " << myMario->getNumCoins() << " coins. Mario will stay put. " << std::endl;
              myFile << "\nMario took " << myMario->getNumMoves() << " total moves." << std::endl;
              myFile << "WE BEAT THE GAME! :)" << std::endl;
              myFile.close();
              return;
            }
            else
            {
              myFile << "Mario has " << myMario->getV() << " lives left. Mario has " << myMario->getNumCoins() << " coins. Mario will move to the next level. " << std::endl;
              nextLevel = true;
              break; // breaks out of current loop
            }
          }
          else
          {
            myFile << " Mario encountered a boss and lost. He will try to defeat the boss again. ";
            if (spotTracker == 't') {myFile << std::endl << "Game over, out of lives." << std::endl; myFile << "\nMario took " << myMario->getNumMoves() << " total moves."; myFile.close(); return;}
            spotTracker = myMario->interact(prevChar);
            if (spotTracker == 't') {myFile << std::endl << "Game over, out of lives." << std::endl; myFile << "\nMario took " << myMario->getNumMoves() << " total moves."; myFile.close(); return;}
          }
        } 
      }

      /* if Mario defeats a boss, go to the next level */
      if (nextLevel == true)
      {
        break;
      }

      /* check if Mario still has lives */
      if (spotTracker == 't') {myFile << std::endl << "Game over, out of lives." << std::endl; myFile << "\nMario took " << myMario->getNumMoves() << " total moves."; myFile.close(); return;}

      /* print out more info */
      myFile << "Mario has " << myMario->getV() << " lives left. Mario has " << myMario->getNumCoins() << " coins. Mario will move ";

      /* replace the used entity */
      levelArr[i].getGrid()[yPos][xPos] = spotTracker;

      /* move Mario */
      myFile << myMario->move() << ".";
      
      /* change x and y positions */
      yPos = myMario->getYPos();
      xPos = myMario->getXPos();

      /* replace prevChar */
      prevChar = levelArr[i].getGrid()[yPos][xPos];

      /* replace that spot with H */
      levelArr[i].getGrid()[yPos][xPos] = 'H';

      /* print updated grid */
      myFile << "" << std::endl;
      for (int a = 0; a < N; a++)
      {
        if (a > 0) {myFile << "" << std::endl;}
        for (int b = 0; b < N; b++)
        {
          myFile << levelArr[i].getGrid()[a][b];
        }
      }
      myFile << "" << std::endl;
      myFile << divider << std::endl;
    }
  }

  myFile.close();
}


/* gets L*/
int World::getL()
{
  return L;
}

/* sets L */
void World::setL(int newL)
{
  this->L = newL;
}

/* gets N */
int World::getN()
{
  return N;
}

/* sets N */
void World::setN(int newN)
{
  this->N = newN;
}

/* gets V */
int World::getV()
{
  return V;
}

/* sets V */
void World::setV(int newV)
{
  this->V = newV;
}

/* gets percentCoins */
int World::getPercentCoins()
{
  return percentCoins;
}

/* sets percentCoins */
void World::setPercentCoins(int newPercentCoins)
{
  this->percentCoins = newPercentCoins;
}

/* gets percentNothing */
int World::getPercentNothing()
{
  return percentNothing;
}

/* sets percentNothing */
void World::setPercentNothing(int newPercentNothing)
{
  this->percentNothing = newPercentNothing;
}

/* gets percent Goombas */
int World::getPercentGoombas()
{
  return percentGoombas;
}

/* sets percentGoombas */
void World::setPercentGoombas(int newPercentGoombas)
{
  this->percentGoombas = newPercentGoombas;
}

/* gets percentKoopas */
int World::getPercentKoopas()
{
  return percentGoombas;
}

/* sets percentKoopas */
void World::setPercentKoopas(int newPercentKoopas)
{
  this->percentKoopas = newPercentKoopas;
}

/* gets percentMushrooms */
int World::getPercentMushrooms()
{
  return percentMushrooms;
}

/* sets percentMushrooms */
void World::setPercentMushrooms(int newPercentMushrooms)
{
  this->percentMushrooms = newPercentMushrooms;
}