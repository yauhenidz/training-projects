#include "../include/tttgame.h"

   TTTField::TTTField()
	{
			for(int i = 0; i < square; ++i)
				for(int j = 0; j < square; ++j)
					cells[i][j] = -1;
	}	

//Get square
    int TTTField::getSquare()
    {
        return square;
    }

// Re-draw the field
    void TTTField::updateField()
	{
            system("cls");

            std::cout << intro << std::endl;
			std::cout << "  1 2 3 4 5" << std::endl;
			
			for(int i = 0; i < square; ++i)
			{
				std::cout << i + 1 << " ";
				for(int j = 0; j < square; ++j)
				{
					
					switch (cells[i][j])
					{
						case 0:
					       std::cout << "0" << " ";
					       break;
					    case 1:
					       std::cout << "X" << " ";
					       break;
					    default: 
					       std::cout << "." << " ";
					 }      
				}
                std::cout << std::endl;
			}			
    std::cout << dialog;
    }

// Save a move
    int TTTField::updateCell(int row, int col, int value)
	{

        if(row < 0 || row >= square || col < 0 || col >=square)
		   return 0;
		
		if(cells[row][col] == -1)
		{   
		   cells[row][col] = value;
		   return 1;
		}
		else
		   return 0;  
	}

// Return a cell's address
    int * TTTField::getCell(int row, int col)
	{
		return &cells[row][col];
	}

// Check if there is an empty cell for move
    int TTTField::getVacant()
	{
		int vacants = 0;
		
		for(int i = 0; i < square; ++i)
			for(int j = 0; j < square; ++j)
				if(cells[i][j] == -1)
					vacants++;
		return vacants;			
	}


/* User's move */
    int TTTField::userMove()
    {
        std::cout << "Your turn, dude: ";
        int tryRow = 0;
        int tryColumn = 0;
        int tryPosition = 0;

        std::cin >> tryPosition;

        if (std::cin.fail())
        {
            std::cin.clear();
            std::cin.ignore(32767,'\n');
            dialog = "No way, dude! Try again. \n";
            return -10;
        }
        else
        {
            tryColumn = tryPosition % 10;
            tryRow = tryPosition / 10;
        }

        if(!updateCell(tryRow - 1, tryColumn - 1, 1))
        {
          dialog = "No way, dude! Try again. \n";
          return -10;
        }

        dialog = "\n";
        return checkWinner();
    }


/* Computer move
 * Idea: I take addresses of all empty cells and put them into a dynamic array.
 * Then chose an index randomly
*/
    int TTTField::computerMove()
    {
        std::cout << std::endl << "Now Super Computer turn. Thinking....... " << std::endl;
        std::chrono::milliseconds dura(1000);
        std::this_thread::sleep_for(dura);

        int vSize = getVacant();
        int **p = new int* [vSize];
        int indPtr = 0;

        for(int i = 0; i < getSquare(); ++i)
            for(int j = 0; j < getSquare(); ++j)
              if(*getCell(i,j) == -1)
                 {
                   p[indPtr] = getCell(i,j);
                   indPtr++;
                 }
        *p[getRandomNumber(0, vSize-1)] = 0;
        delete [] p;

        return checkWinner();
    }

/*
* Random for computer move
* */
    int TTTField::getRandomNumber(int min, int max)
    {
        static const double fraction = 1.0 / (static_cast<double>(RAND_MAX) + 1.0);
        return static_cast<int>(rand() * fraction * (max - min + 1) + min);
    }

// Check winning combinations
    int TTTField::checkWinner()
	{
		int checker = 0;
		
        //Check rows for 0
		for(int i=0; i < square; ++i)
		{
			for(int j =0; j < square; ++j)
			 if(cells[i][j] != 0)
			    checker = 1;
			if(checker == 0)
			 return checker;
			else
			 checker = 0; 
		}
				
        //Check rows for X
		checker = 1;
		for(int i =0; i < square; ++i)
		{
			for(int j =0; j < square; ++j)
			 if(cells[i][j] != 1)
			    checker = 0;
			if(checker == 1)
			 return 1;
			else
			 checker = 1; 
		}			  	 
		
        //Check columns for 0
		checker = 0;
		for(int i=0; i < square; ++i)
		{
			for(int j =0; j < square; ++j)
			 if(cells[j][i] != 0)
			    checker = 1;
			if(checker == 0)
			 return checker;
			else
			 checker = 0; 
		}

        //Check columns for X
		checker = 1;
		for(int i =0; i < square; ++i)
		{
			for(int j =0; j < square; ++j)
			 if(cells[j][i] != 1)
			    checker = 0;
			if(checker == 1)
			 return 1;
			else
			 checker = 1; 
		}	
			
        //Check diagonal for 0
		int iDiag, jDiag;		
		
		checker = 0;
		for (iDiag = square-1, jDiag = 0; iDiag >=0 ; --iDiag, ++jDiag)
		 if(cells[iDiag][jDiag] != 0)
		   checker = 1;
		if(checker == 0)
			return 0;
			
		checker = 0;
		for (int i = 0; i < square; ++i)
		 if(cells[i][i] != 0)
		   checker = 1;
		if(checker == 0)
			return 0;		
						  

        //Check diagonal for X

		checker = 1;
		for (iDiag = square-1, jDiag = 0; iDiag >=0 ; --iDiag, ++jDiag)
		 if(cells[iDiag][jDiag] != 1)
		   checker = 0;	
		if(checker == 1)
			return 1;
			
		checker = 1;
		for (int i = 0; i < square; ++i)
		 if(cells[i][i] != 1)
		   checker = 0;
		if(checker == 1)
			return 1;					 

// WTF here?!
			
			if(!getVacant())
			   return 5;
			  
		return -1;
	}



