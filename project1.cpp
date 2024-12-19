#include <iostream>
#include <cstdlib>
#include <ctime>

void playGame();

int main() {
    std::cout << "Welcome to the Number Guessing Game!\n";
    char playAgain;

    do {
        playGame();
        std::cout << "\nDo you want to play again? (y/n): ";
        std::cin >> playAgain;
    } while (playAgain == 'y' || playAgain == 'Y');

    std::cout << "Thanks for playing! Goodbye!\n";
    return 0;
}

void playGame() {
    std::srand(static_cast<unsigned int>(std::time(0))); // Seed random number generator
    int randomNumber = std::rand() % 100 + 1; // Random number between 1 and 100
    int guess;
    int attempts = 0;
    const int maxAttempts = 7; // Maximum attempts allowed

    std::cout << "\nI have chosen a number between 1 and 100.\n";
    std::cout << "You have " << maxAttempts << " attempts to guess it. Good luck!\n";

    while (attempts < maxAttempts) {
        std::cout << "Enter your guess: ";
        std::cin >> guess;

        if (guess < 1 || guess > 100) {
            std::cout << "Please enter a number between 1 and 100.\n";
            continue;
        }

        attempts++;

        if (guess < randomNumber) {
            std::cout << "Too low! Try again.\n";
        } else if (guess > randomNumber) {
            std::cout << "Too high! Try again.\n";
        } else {
            std::cout << "Congratulations! You guessed the number in " << attempts << " attempts!\n";
            return;
        }
    }

    std::cout << "Sorry, you've used all your attempts. The number was " << randomNumber << ".\n";
}
