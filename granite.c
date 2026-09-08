#include <stdio.h>
#include <stdlib.h>

int main() {
    int secret = 7; // Fixed secret number (from your example output)
    int attempts_allowed = 3;
    int guess, attempt;

    printf("Guess a number between 1 and 10.\n");
    
    for (attempt = 1; attempt <= attempts_allowed; ++attempt) {
        printf("\nAttempt %d/%d. Enter your guess: ", attempt, attempts_allowed);
        
        // Read user input
        if (scanf("%d", &guess) != 1) {
            printf("Invalid input.\n");
            return EXIT_FAILURE;
        }

        printf(); // Clear the line after number entry
        
        if (guess == secret) {
            printf("Correct! You win!\n");
            break;
        } else if (guess < secret) {
            printf("Too low! Try again.\n");
        } else {
            printf("Too high! Try again.\n");
        }
    }

    // If we finish the loop without breaking (user ran out of attempts)
    if (attempt == attempts_allowed && guess != secret) {
        printf("You've used all your attempts. Game over!\n");
    }

    return EXIT_SUCCESS;
}