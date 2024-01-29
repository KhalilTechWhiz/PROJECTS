#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ATTEMPTS 10
#define NUM_PAWNS 5
#define NUM_COLORS 8

int getRandomNumber(int max) {
    return rand() % (max + 1);
}

void initializeHiddenPawns(int hiddenPawns[]) {
    for (int i = 0; i < NUM_PAWNS; i++) {
        hiddenPawns[i] = getRandomNumber(NUM_COLORS - 1);
    }
}

void evaluateGuess(const int hiddenPawns[], const int guess[], int result[]) {
    for (int i = 0; i < NUM_PAWNS; i++) {
        if (hiddenPawns[i] == guess[i]) {
            result[i] = 1;  
        } else {
            result[i] = 0;  
        }
    }

    for (int i = 0; i < NUM_PAWNS; i++) {
        if (result[i] == 0) {
            for (int j = 0; j < NUM_PAWNS; j++) {
                if (hiddenPawns[j] == guess[i] && result[j] == 0) {
                    result[j] = -1;  
                    break;
                }
            }
        }
    }
}

void printBoard(const int guess[], const int result[]) {
    printf("Current Board: ");
    for (int i = 0; i < NUM_PAWNS; i++) {
        printf("%d ", guess[i]);
    }

    printf("\nWell-placed pawns: ");
    for (int i = 0; i < NUM_PAWNS; i++) {
        if (result[i] == 1) {
            printf("%d ", i + 1);
        }
    }

    printf("\nMisplaced pawns: ");
    for (int i = 0; i < NUM_PAWNS; i++) {
        if (result[i] == -1) {
            printf("%d ", i + 1);
        }
    }
    printf("\n");
}

int main() {
    srand(time(NULL));  

    int hiddenPawns[NUM_PAWNS];
    int guess[NUM_PAWNS];
    int result[NUM_PAWNS];

    initializeHiddenPawns(hiddenPawns);

    printf("Codemaker has placed 5 hidden pawns. Codebreaker, try to guess the combination!\n");

    for (int attempt = 1; attempt <= MAX_ATTEMPTS; attempt++) {
        printf("\nAttempt %d: Enter your guess (numbers representing colors, separated by space): ", attempt);
        for (int i = 0; i < NUM_PAWNS; i++) {
            scanf("%d", &guess[i]);
        }

        evaluateGuess(hiddenPawns, guess, result);
        printBoard(guess, result);

        int correctGuesses = 0;
        for (int i = 0; i < NUM_PAWNS; i++) {
            if (result[i] == 1) {
                correctGuesses++;
            }
        }

        if (correctGuesses == NUM_PAWNS) {
            printf("Congratulations! Codebreaker has guessed the correct combination!\n");
            break;
        }

        if (attempt == MAX_ATTEMPTS) {
            printf("Game over! Codebreaker couldn't guess the correct combination. The correct combination was: ");
            for (int i = 0; i < NUM_PAWNS; i++) {
                printf("%d ", hiddenPawns[i]);
            }
            printf("\n");
        }
    }

    return 0;
}
