#include <iostream>
#include <cstdlib>
#include <ctime>

int main() {

    srand(time(0));
    int secretNumber = rand() % 100 + 1;


    int userGuess;
    int attempts = 0;
    bool guessedCorrectly = false;

    std::cout << "Welcome to the Number Guessing Game!" << std::endl;
    std::cout << "I have selected a random number between 1 and 100. Try to guess it!" << std::endl;

    while (!guessedCorrectly) {

        std::cout << "Enter your guess: ";
        std::cin >> userGuess;


        attempts++;


        if (userGuess == secretNumber) {
            guessedCorrectly = true;
            std::cout << "Congratulations! You guessed the correct number " << secretNumber << " in " << attempts << " attempts." << std::endl;
        } else if (userGuess < secretNumber) {
            std::cout << "Too low! Try again." << std::endl;
        } else {
            std::cout << "Too high! Try again." << std::endl;
        }
    }

    return 0;
}
