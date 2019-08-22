#include "../include/tttgame.h"

int main ()
{

    TTTField game;
    int gameOver = -1;

    while(gameOver == -1)
    {
            game.updateField();

            //user's move
            gameOver = game.userMove();
            if(gameOver == -10)
            {
                gameOver = -1;
                continue;
            }
            game.updateField();

            //computer's move
            if(gameOver == -1)
               gameOver = game.computerMove();
    }

 switch (gameOver)
 {
    case 1:
      std::cout << std::endl << "You won dude! Congrats!" << std::endl;
      break;
    case 0:
      game.updateField();
      std::cout << std::endl << "You are such a LOOOOOSER!!!" << std::endl;
      break;
    default:
      std::cout << std::endl << "DRAW. No winner." << std::endl;
 }

 return 0;
}
