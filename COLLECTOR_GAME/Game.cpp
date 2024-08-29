#include "Game.h"
#include <iostream>
#include <cstdlib>
#include <sstream>
#include <string>

namespace Game
{

   int convToInt(string strVal)
  {
     stringstream ss{strVal};
     int convInt = 0;
     ss >> convInt;
     ///checking if it was passed a string as an argument
     if(ss.fail())
     {
         cerr << strVal <<" Could not be converted, please enter a string " << endl;
         exit(ERROR_ARGS_TYPES);
     }
     return convInt;
  }
 /// function which generates random numbers
  int genRandom(int lower, int upper)
  {
      int range = upper - lower +1;
      return rand()% range + lower;

  }
  ///Allocate memory
    type2DArray allocMem(int rows, int cols)
    {
        type2DArray world = new type1DArray[rows];
        for(int r = 0; r < rows ; r++)
        {
            world[r] = new int[cols];
        }
        return world;
    }

  ///initializing the game world
  void initArray(type2DArray world, int rows, int cols, int treasures)
  {
        for(int r = 0; r < rows; r++)
        {
            for(int c = 0; c < cols;  c++)
            {
                 world[r][c] = WORLD;
                 if(genRandom(1,100) <= OBSTACLE_CHANCE)
                 {
                     world[r][c] = OBSTACLE;

                 }

                 if(genRandom(1,100) <= HOLE_CHANCE)
                 {
                     if(world[r][c] == WORLD)
                      {
                         world[r][c] = HOLE;
                      }


                 }


            }
        }


        while(treasures > 0)
                 {
                     int TR = genRandom(0,rows-1);
                     int TC = genRandom(0,cols-1);
                      if(world[TR][TC] == WORLD)
                      {
                          world[TR][TC] = TREASURE;
                      }

                      treasures--;
                 }


        int playerR = genRandom(0,rows-1);
        int playerC = genRandom(0,cols-1);
        while(world[playerR][playerC] == OBSTACLE || world[playerR][playerC] == TREASURE)
        {
             playerR = genRandom(0,rows-1);
             playerC = genRandom(0,cols-1);
        }
        world[playerR][playerC] = PLAYER;
  }

  ///functionality of finding a players position
  void findPlayer(int &PRow, int &PCol, type2DArray world, int rows, int cols)
  {
      for(int r = 0; r < rows ; r++)
      {
          for(int c = 0; c < cols ; c++)
          {
              if(world[r][c] == PLAYER)
              {
                  PRow = r;
                  PCol = c;
              }
          }
      }
  }

  ///functionality of moving a player
  void movePlayer (type2DArray world, char Directions, int rows, int cols, int &treasures)
  {
    int PRow = -1;
    int PCol = -1;
    findPlayer(PRow, PCol,world,rows,cols);

    int DR = PRow;
    int DC = PCol;

    switch(Directions)
    {

    case 'w':
    case 'W':
        DR--;
    break;

    case 's':
    case 'S':
        DR++;
    break;

    case 'a':
    case 'A':
        DC--;
    break;

    case 'd':
    case 'D':
        DC++;
    break;

    }

    if(isInWorld(DR,DC,rows,cols))
    {

        if(world[DR][DC] == TREASURE)
        {

             world[PRow][PCol] = WORLD;
             world[DR][DC] = PLAYER;

              treasures--;
                  cout << treasures;
                  if(treasures == 0)
                  {
                    cout << "YOU WIN;-)";
                    exit(SUCCESS);
                   }

        }
       else if(world[DR][DC] == HOLE)
        {
             cerr << "GAME OVER:-(";
             exit(SUCCESS);


        } else if(world[DR][DC] != OBSTACLE)
        {
             world[PRow][PCol] = WORLD;
             world[DR][DC] = PLAYER;


        }
    }





  }

  ///checking of the player is i the game world
  bool isInWorld(int DR, int DC, int rows, int cols)
  {
      if(DR < 0 || DR >= rows || DC < 0 || DC >= cols)
      {

          return false;
      }else
      {

          return true;
      }
  }
  void printWorld(type2DArray world, int rows, int cols)
  {
       for(int r = 0; r < rows; r++)
        {
            for(int c = 0; c < cols;  c++)
            {
                 cout << CHARACTER[world[r][c]] << " ";
            }
           cout << endl;
        }

  }

  //de-Allocating the memory
  void deAllocMem(type2DArray &world, int rows)
 {
     for(int n = 0; n < rows; n++)
     {
         delete[] world[n];
     }
     //delete[] world;
     world = nullptr;
 }



}
