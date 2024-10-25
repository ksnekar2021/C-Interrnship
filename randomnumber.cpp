#include <iostream>
#include <cstdlib>  // For rand() and srand()
#include <ctime>    // For time()

int main() {
    // Seed the random number generator with the current time
    std::srand(std::time(0));

    // Generate a random number between 1 and 100
    int randNum = std::rand() % 100 + 1;
    int userGuessnum = 0;

    std::cout << "Welcome to the Number Guessing Game!\n";
    std::cout << "I have chosen a number between 1 and 100.\n";
    std::cout << "Can you guess what it is?\n";

    // Loop until the user guesses the correct number
    while (userGuessnum != randNum) {
        std::cout << "Enter your guess: ";
        std::cin >> userGuessnum;

        if (userGuessnum > randNum) {
            std::cout << "Too high! Try again.\n";
        } else if (userGuessnum < randNum) {
            std::cout << "Too low! Try again.\n";
        } else {
            std::cout << "Congratulations! You guessed the correct number: " << randNum << "\n";
        }
    }

    return 0;
}
