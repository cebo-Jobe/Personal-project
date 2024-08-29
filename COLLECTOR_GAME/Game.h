#ifndef GAME_H_INCLUDED
#define GAME_H_INCLUDED

#include <iostream>
#include <cstdlib>
#include <sstream>
#include <string>

using namespace std;
namespace Game
{
typedef int* type1DArray;
typedef type1DArray* type2DArray;
const int NUM_ARGS = 4; ///<Collector.exe> <NUM_ROWS> <NUM_COLS> <num_treasure>

//distribution chances in the game world in each cell
const int TREASURE_CHANCE = 4;
const int HOLE_CHANCE= 6;
const int OBSTACLE_CHANCE = 4;
//Game entities
const int WORLD    = 0;
const int PLAYER   = 1;
const int OBSTACLE = 2;
const int TREASURE = 3;
const int HOLE = 4;

char CHARACTER[] = {'.','P','#','$','0'};

///Player movements
const int UP    = 0;
const int DOWN  = 1;
const int LEFT  = 2;
const int RIGHT = 3;


///error code
const int ERROR_NUM_ARGS   = -1;
const int ERROR_ARGS_TYPES = -2;
const int SUCCESS          =  0;

/// function prototypes
int convToInt(string strVal);
int genRandom(int lower, int upper);
type2DArray allocMem(int rows, int cols);
void deAllocMem(type2DArray &world, int rows);
void initArray(type2DArray world, int rows, int cols, int treasures);
void findPlayer(int &PRow, int &PCol, type2DArray world,int rows, int cols);
void movePlayer (type2DArray world, char Directions, int rows, int cols);
bool isInWorld(int DR, int DC, int rows, int cols);
void printWorld(type2DArray world, int rows, int cols);
}



#endif // GAME_H_INCLUDED
