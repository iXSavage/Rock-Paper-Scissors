#include <iostream>
#include <cstdlib>
#include <ctime>

char GetUserChoice();
char GetComputerChoice();
void ShowChoice(char choice);
int ShowWinner(char Player, char Computer, int& playerScore, int& computerScore);

int main()
{
    int playerScore = 0;
    int computerScore = 0;

    do {
        char Player;
        char Computer;

        Player = GetUserChoice();
        std::cout << "You choose: ";
        ShowChoice(Player);

        Computer = GetComputerChoice();
        std::cout << "Computer chose: ";
        ShowChoice(Computer);

        ShowWinner(Player, Computer, playerScore, computerScore);

        std::cout << "Player Score: " << playerScore << std::endl;
        std::cout << "Computer Score: " << computerScore << std::endl;

        char playAgain;
        bool validChoice = false;

        do {
            std::cout << "Do you want to play again? (y/n): ";
            std::cin >> playAgain;

            if (playAgain == 'y' || playAgain == 'Y' || playAgain == 'n' || playAgain == 'N') {
                validChoice = true;
            } else {
                std::cout << "Invalid input. Please enter 'y' or 'n'." << std::endl;
            }
        } while (!validChoice);

        if (playAgain == 'n' || playAgain == 'N') {
            break;
        }

    } while (true);

    std::cout << "Thank you for playing!" << std::endl;

    return 0;
}


char GetUserChoice(){
   char Player;
   std::cout << "iXSavage Rock, Paper, Scissors Game" << std::endl;

   do{
      std::cout << "Choose one of the following choices" << std::endl;
      std::cout << " 'r' for Rock" << std::endl;
      std::cout << " 'p' for Paper" << std::endl;
      std::cout << " 's' for Scissors" << std::endl;
      std::cin >> Player;  

   if (Player != 'r' && Player != 'p' && Player !='s')
   {
      std::cout << "Invalid Input. Try again" << std::endl;
   }
   } while (Player != 'r' && Player != 'p' && Player !='s');
   return Player;
}
char GetComputerChoice(){
   srand(time(NULL));
   int num = rand() % 3 + 1;

   switch(num){
   case 1: return 'r';
   case 2: return 'p';
   case 3: return 's';
   }
return 0;
}
void ShowChoice(char choice) {
    switch (choice) {
        case 'r':
            std::cout << "Rock" << std::endl;
            std::cout << "    _______" << std::endl;
            std::cout << "---'   ____)" << std::endl;
            std::cout << "      (_____)" << std::endl;
            std::cout << "      (_____)" << std::endl;
            std::cout << "      (____)" << std::endl;
            std::cout << "---.__(___)" << std::endl;
            break;
        case 'p':
            std::cout << "Paper" << std::endl;
            std::cout << "    _______" << std::endl;
            std::cout << "---'   ____)____" << std::endl;
            std::cout << "          ______)" << std::endl;
            std::cout << "          _______)" << std::endl;
            std::cout << "         _______)" << std::endl;
            std::cout << "---.__________)" << std::endl;
            break;
        case 's':
            std::cout << "Scissors" << std::endl;
            std::cout << "    _______" << std::endl;
            std::cout << "---'   ____)____" << std::endl;
            std::cout << "          ______)" << std::endl;
            std::cout << "       __________)" << std::endl;
            std::cout << "      (____)" << std::endl;
            std::cout << "---.__(___)" << std::endl;
            break;
    }
}

int ShowWinner(char Player, char Computer, int& playerScore, int& computerScore)
{
    int result;

    switch (Player)
    {
        case 'r':
            if (Computer == 'r')
            {
                std::cout << "This round is a tie" << std::endl;
                result = 0;
            }
            else if (Computer == 'p')
            {
                std::cout << "Computer Wins" << std::endl;
                computerScore++;
                result = 2;
            }
            else
            {
                std::cout << "You Win" << std::endl;
                playerScore++;
                result = 1;
            }
            break;

        case 'p':
            if (Computer == 'r')
            {
                std::cout << "You Win" << std::endl;
                playerScore++;
                result = 1;
            }
            else if (Computer == 'p')
            {
                std::cout << "This round is a tie" << std::endl;
                result = 0;
            }
            else
            {
                std::cout << "Computer Wins" << std::endl;
                computerScore++;
                result = 2;
            }
            break;

        case 's':
            if (Computer == 'r')
            {
                std::cout << "Computer Wins" << std::endl;
                computerScore++;
                result = 2;
            }
            else if (Computer == 'p')
            {
                std::cout << "You Win" << std::endl;
                playerScore++;
                result = 1;
            }
            else
            {
                std::cout << "This round is a tie" << std::endl;
                result = 0;
            }
            break;
    }

    return result;
}
