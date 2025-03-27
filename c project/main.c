#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(0)); // Seed the random number generator

    int randomNumber = (rand() % 100) + 1; // Generate a random number between 1 and 100
    int no_of_guesses = 0;
    int guessed;

    printf("Guess the number (between 1 and 100):\n");

    do {
        printf("Enter your guess: ");
        scanf("%d", &guessed);

        if (guessed > randomNumber) {
            printf("Lower number, please!\n");
        } else if (guessed < randomNumber) {
            printf("Higher number, please!\n");
        }
        else{
            printf("congrats! ");
        }
        no_of_guesses++;
    } while (guessed != randomNumber);

    printf("Congratulations! You guessed the number in %d attempts.\n", no_of_guesses);

    return 0;
}
