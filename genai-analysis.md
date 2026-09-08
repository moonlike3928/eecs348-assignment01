# GenAI Analysis

This document contains the analysis of the two GenAI programs, as well as the one selected and the edits made to it.

## Access

Access to these LLMs was through LM Studio, a locally-run application found at https://lmstudio.ai.
All models used were downloaded and run for free using this application.

## Prompt

This prompt was used for both LLMs:
```text
Write a C program that picks a secret number between 1 and 10. The user gets up to 3 tries to guess the number. 
The secret number should be fixed. Printf and Scanf should be used to interact with the user. A while or for loop should be used to allow 
the user to guess up to three times. Use if/else statements to check the guess. Stop the loop immediately if the user guesses correctly. 
Print a final win/lose message. Make sure the program follows this output scheme:
    >   Guess a number between 1 and 10.
    >   Attempt 1/3. Enter your guess: 5
    >   Too low! Try again.
    >   Attempt 2/3. Enter your guess: 8
    >   Too high! Try again.
    >   Attempt 3/3. Enter your guess: 7
    >   Correct! You win!"
```

## Model 1

- Model name: `liquid/lfm2.5-1.2b`

Generated program:
```c
#include <stdio.h>

int main() {
    int secret = 5; // Fixed secret number between 1 and 10
    int attempts = 0;
    int guess;

    printf("Guess a number between 1 and 10.\n");
    while (attempts < 3) {
        printf("Attempt %d/3. Enter your guess: ", attempts + 1);
        scanf("%d", &guess);

        if (guess < secret) {
            printf("Too low! Try again.\n");
        } else if (guess > secret) {
            printf("Too high! Try again.\n");
        } else {
            printf("Correct! You win!\n");
            return 0;
        }
        attempts++;
    }

    printf("Game over. The secret number was %d.\n", secret);
    return 0;
}
```

### Code Review

- Correctness
    - Program compiles/runs with no edits
    - Does not gracefully handle edge cases:
        - Text inputs are silently treated as integers
        - Numbers above/below maximum integer size over/underflow silently
- Complexity
    - O(1) runtime complexity, maximum of three guesses.
    - Uses a while loop rather than a for loop
    - Uses three declared variables
- Maintainability
    - Only a single line comment, no prologue 
    - Straightforward program flow 
    - well-named variables


## Model 2

- Model name: `Ibm Granite_Granite 4.2 3b`

Generated program:
```c
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
```
### Code Review

- Correctness
    - Program did not compile intially- incorrect printf statement on line 20
    - Does gracefully handle some edge cases:
        - Text inputs are rejected
        - Numbers above/below maximum integer size over/underflow silently
- Complexity
    - O(1) runtime complexity, maximum of three guesses.
    - Includes stdlib, using much more memory than the other LLM's program
    - Uses four declared variables
    - Uses a for loop instead of a while loop
- Maintainability
    - Few comments, no prologue
    - Straightforward program flow 
    - well-named variables
    - Program exits unsuccessfully when a user gives an invalid input