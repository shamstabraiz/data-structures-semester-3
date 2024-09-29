#include <cstdlib>
#include <iostream>
#include <time.h>

using namespace std;

const int TOTAL_NUMBERS = 10;
const int NUMBER_RANGE = 100;
const int REPEATED_COUNT = 3;
bool IS_FIRST_TIME = true;

int genrateRandomNumber()
{
    const int randomNumber = rand() % 100;
    return randomNumber;
}

void generateWinningNumbers(int winningNumbers[], int previousWinningNumbers[])
{
    //first we will genrate 10 or TOTAL_NUMBERS of random numbers
    for (int i = 0; i < TOTAL_NUMBERS; ++i)
    {
        winningNumbers[i] = genrateRandomNumber();
    }

    //then if we have previous winner numbers then we will randomly select 3 numbers and replace then in winner numbers
    if (!IS_FIRST_TIME) {
        for (int i = 0; i < REPEATED_COUNT; ++i)
        {
            winningNumbers[i] = previousWinningNumbers[rand() % TOTAL_NUMBERS];
        }
    }

    // finally we will store current winning numbers in the array for next use
    for (int i = 0; i < TOTAL_NUMBERS; ++i)
    {
        previousWinningNumbers[i] = winningNumbers[i];
    }
}

int main()
{
    srand(time(0));
    cout << "---------------------------Wellcome To Lottery By Shams Tabraiz----------------------------------\n";
    cout << "How to play, Choose a number in you mind, if the number appers in the screen then your a winner, If not you can try again by pressing 'y' at the end, \nHint: Some numbers will be repeated from previous roll\n";

    int previousWinningNumbers[TOTAL_NUMBERS] = {};
    int winningNumbers[TOTAL_NUMBERS] = {};
    char playAgain;
    do
    {
        // Generate winning numbers and save them in the array
        generateWinningNumbers(winningNumbers, previousWinningNumbers);

        // Output the winning numbers to console
        cout << "Winning Numbers Are\n";
        for (int i = 0; i < TOTAL_NUMBERS; ++i)
        {
            cout << winningNumbers[i] << " ";
        }
        cout << "\n";


        // asking the user if they want to play again
        cout << "Do you want to play again? (y/n): ";
        cin >> playAgain;
        IS_FIRST_TIME = false;

    } while (playAgain == 'y' || playAgain == 'Y');

    cout << "Thank you for playing!\n";
    return 0;
}