#include <stdio.h>
#define countOfLines 7
#define maxLength 1000

int getline(char line[], int len) {
    char currChar;
    int i = 0;

    for(; (currChar = getc(stdin)) != '\n' && i < len; i++) {
        if(i + 1 < len) line[i] = currChar;
        else line[i] = '\0';
    }

    return i;
}

void copy(char source[], char target[]) {
    for(int i = 0; (target[i] = source[i]) != '\0'; i++);
}

int main() {
    int currLength = 0;
    int largestLength = 0;

    char currLine[maxLength];
    char largestLine[maxLength];

    for(int i = 0; i < countOfLines; i++) {
        currLength = getline(currLine, maxLength);

        if(currLength > largestLength) {
            largestLength = currLength;
            copy(currLine, largestLine);
        }
    }

    printf("\n%s", largestLine);
}