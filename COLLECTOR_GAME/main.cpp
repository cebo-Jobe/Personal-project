#include  <iostream>
#include <cstdlib>
#include <sstream>
#include <string>
#include <ctime>
#include "Game.h"
#include "Game.cpp"

using namespace std;
using namespace Game;

int main(int argc, char** argv)
{
    srand(time(0));
   if(argc != 4)
   {
       cerr << "Invalid number of arguments" << endl;
       cerr << "Please type " << argv[0] << " <num of rows> <num of cols> <num of treasure>" << endl;
       exit(ERROR_NUM_ARGS);
   }

       int intRows = convToInt(argv[1]);
       int intCols = convToInt(argv[2]);
       int intNumTreasure = convToInt(argv[3]);

       char inputC;

       bool blnContinue = true;

       type2DArray world = allocMem(intRows,intCols);
       initArray(world,intRows,intCols,intNumTreasure);

       do
       {
              system("cls");
           cout << "       >>>>>>>>>'COLLECTOR'<<<<<<<<<<" << endl
                << "[a-LEFT, d-RIGHT, w-UP, s-DOWN] >(q-QUIT)<" << endl
                << "[PRESS ENTER AFTER A KEY DIRECTION]" << endl;

                 printWorld(world,intRows,intCols);
           cin >> inputC;
                switch(inputC)
                {
                    case 'a':
                    case 'A':

                           movePlayer(world,inputC,intRows,intCols,intNumTreasure);
                        break;
                    case 'd':
                    case 'D':

                           movePlayer(world,inputC,intRows,intCols,intNumTreasure);
                       break;
                    case 'w':
                    case 'W':

                         movePlayer(world,inputC,intRows,intCols,intNumTreasure);
                       break;
                    case 's':
                    case 'S':
                        movePlayer(world,inputC,intRows,intCols,intNumTreasure);
                    break;

                    case 'q':
                    case 'Q':

                         cout << "GAME QUIT :-(" << endl;
                        blnContinue = false;
                    break;

                }

        //  system("pause");

       }while(blnContinue);




     //deAllocMem(world,intRows);

    return SUCCESS;
}


