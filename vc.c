#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

char getRandomLetter() {
    const char vowels[] = "aeiou";
    const char consonants[] = "bcdfghjklmnpqrstvwxyz";
    const char allLetters[] = "abcdefghijklmnopqrstuvwxyz";

    char letter;
    int randomType = rand() % 2; 

    if (randomType == 0) {
        letter = consonants[rand() % (sizeof(consonants) - 1)];
    } else {
        letter = vowels[rand() % (sizeof(vowels) - 1)];
    }

    return letter;
}

void drawLetters(char letters[]) {
    for (int i = 0; i < 10; i++) {
        letters[i] = getRandomLetter();
    }
    letters[10] = '\0'; 
}

int canFormWord(const char word[], const char drawnLetters[]) {
    char tempDrawnLetters[11];
    strcpy(tempDrawnLetters, drawnLetters);

    for (int i = 0; i < strlen(word); i++) {
        char* foundLetter = strchr(tempDrawnLetters, word[i]);
        if (foundLetter != NULL) {
            *foundLetter = ' '; 
        } else {
            return 0; 
        }
    }
    return 1; 
}

int main() {
    srand(time(NULL)); 

    char player1Letters[11], player2Letters[11];
    char word[50];
    int numVowels;

    printf("Player 1, enter the number of vowels you want: ");
    scanf("%d", &numVowels);

    drawLetters(player1Letters);

    printf("Player 2, enter the number of vowels you want: ");
    scanf("%d", &numVowels);

    drawLetters(player2Letters);

    printf("Player 1, enter your word: ");
    scanf("%s", word);

    if (canFormWord(word, player1Letters)) {
        printf("Player 1's word is valid!\n");
    } else {
        printf("Player 1's word is not valid.\n");
    }

    printf("Player 2, enter your word: ");
    scanf("%s", word);

    if (canFormWord(word, player2Letters)) {
        printf("Player 2's word is valid!\n");
    } else {
        printf("Player 2's word is not valid.\n");
    }

    return 0;
}
