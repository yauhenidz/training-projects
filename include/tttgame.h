#ifndef TTTGAME_H
#define TTTGAME_H

#include <iostream>
#include <cstdlib>
#include <chrono>
#include <thread>
#include <string>


class TTTField {
private:

    const int square = 5;
    int cells[5][5];
    std::string dialog = "\n";
    const std::string intro = "Hey, dude! \n"
                        "This is Super Tic-Tac-Toe game! \n"
                        "To make a move - input a position Row and Column. \n"
                        "Only digits. No spaces and other symbols in between. \n"
                        "Example: to get row=2, column=2 cell input 22. \n"
                        "Good luck, dude! \n";

public:
    TTTField();
    void updateField();
    int updateCell(int, int, int);
    int * getCell(int, int);
    int getVacant();
    int userMove();
    int computerMove();
    int checkWinner();
    int getRandomNumber(int, int);
    int getSquare();

};

#endif // TTTGAME_H
