#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 10

int rollDice(int);

void stepComputer(char **, int);

void displayBoard(char **, char **);

void generateTrapIndex(char **, int *, int *);

void generateTrapValues(int *, int *);

void stepPlayer(char **, int);

int main(void) {
    //values
    int changeTimeVar = 10;
    int stepNumPlayer, stepNumComp;
    int trapRow, trapCol, trapValuePlayer, trapValueComp;

    srand(time(NULL) * changeTimeVar);

    char **computer = (char **) malloc(sizeof(char *) * BOARD_SIZE);
    char **player = (char **) malloc(sizeof(char *) * BOARD_SIZE);
    for (int i = 0; i < BOARD_SIZE; i++) {
        computer[i] = (char *) malloc(sizeof(char) * BOARD_SIZE);
        player[i] = (char *) malloc(sizeof(char) * BOARD_SIZE);
    }
    // generate table
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            if (i == 0 || i == 9 || j == 0 || j == 9){
                player[i][j] = '-';
                computer[i][j] = '-';
            }

            else{
                player[i][j] = ' ';
                computer[i][j] = ' ';
            }

        }
    }

    generateTrapValues(&trapValueComp, &trapValuePlayer);


    player[0][0] = 'P';
    computer[9][9] = 'C';
    for (int i = 0; i < 5; ++i) {
        changeTimeVar *= 10;
        do {
            stepNumComp = rollDice(changeTimeVar);
            stepNumPlayer = rollDice(changeTimeVar*10);
        } while (stepNumComp == stepNumPlayer);


        if (i == 0) {
            printf("---------Initial Boards-------\n");
            displayBoard(computer, player);
        } else {
            printf("---------Round %d-------\n", i);
            printf("I have rolled the dice and got %d\n", stepNumComp);
            printf("I have rolled the dice for you and you got %d\n", stepNumPlayer);
            stepPlayer(player, stepNumPlayer);
            stepComputer(computer, stepNumComp);
            displayBoard(computer, player);
        }



    }
}

int rollDice(int r) {
    int dice = (rand() % 6) + 1;
    return dice;
}

void stepComputer(char **computerStepArr, int stepNumComp) {
    int currentRow = 9, currentCol = 9;
    int x = 9, y = 9;
    computerStepArr[currentRow][currentCol] = '-';
    for (int i = 0; i < 36; i++) {
        if (x < BOARD_SIZE - 1 && y == 0) {
            x++;
            if (computerStepArr[y][x] == 'C') {
                currentRow = y;
                currentCol = x;
            }
        } else if (y < BOARD_SIZE - 1 && x == BOARD_SIZE - 1) {
            y++;
            if (computerStepArr[y][x] == 'C') {
                currentRow = y;
                currentCol = x;
            }
        } else if (x > 0 && y == BOARD_SIZE - 1) {
            x--;
            if (computerStepArr[y][x] == 'C') {
                currentRow = y;
                currentCol = x;
            }
        } else if (y > 0 && x == 0) {
            y--;
            if (computerStepArr[y][x] == 'C') {
                currentRow = y;
                currentCol = x;
            }
        }
        // printf("\nx = %d y=%d\n",x,y);
    }

    computerStepArr[currentRow][currentCol] = '-';

    for (int i = 0; i < stepNumComp; i++) {
        if (currentCol < BOARD_SIZE - 1 && currentRow == 0) {
            currentCol++;
        } else if (currentRow < BOARD_SIZE - 1 && currentCol == BOARD_SIZE - 1) {
            currentRow++;
        } else if (currentCol > 0 && currentRow == BOARD_SIZE - 1) {
            currentCol--;
        } else if (currentRow > 0 && currentCol == 0) {
            currentRow--;
        }

    }

    computerStepArr[currentRow][currentCol] = 'C';

}

void stepPlayer(char **playerStepArr, int stepNumPlayer) {

    int currentRow = 0, currentCol = 0;
    int x = 0, y = 0;
    playerStepArr[currentRow][currentCol] = '-';
    for (int i = 0; i < 36; i++) {
        if (x < BOARD_SIZE - 1 && y == 0) {
            x++;
            if (playerStepArr[y][x] == 'P') {
                currentRow = y;
                currentCol = x;
            }
        } else if (y < BOARD_SIZE - 1 && x == BOARD_SIZE - 1) {
            y++;
            if (playerStepArr[y][x] == 'P') {
                currentRow = y;
                currentCol = x;
            }
        } else if (x > 0 && y == BOARD_SIZE - 1) {
            x--;
            if (playerStepArr[y][x] == 'P') {
                currentRow = y;
                currentCol = x;
            }
        } else if (y > 0 && x == 0) {
            y--;
            if (playerStepArr[y][x] == 'P') {
                currentRow = y;
                currentCol = x;
            }
        }
        // printf("\nx = %d y=%d\n",x,y);
    }

    playerStepArr[currentRow][currentCol] = '-';

    for (int i = 0; i < stepNumPlayer; i++) {
        if (currentCol < BOARD_SIZE - 1 && currentRow == 0) {
            currentCol++;
        } else if (currentRow < BOARD_SIZE - 1 && currentCol == BOARD_SIZE - 1) {
            currentRow++;
        } else if (currentCol > 0 && currentRow == BOARD_SIZE - 1) {
            currentCol--;
        } else if (currentRow > 0 && currentCol == 0) {
            currentRow--;
        }
    }

    playerStepArr[currentRow][currentCol] = 'P';
}

void displayBoard(char **computer, char **player) {
    printf("    Player Board\n");
    printf("  ");
    for (int i = 0; i < 10; ++i) {
        printf("%d ", i);
    }
    for (int i = 0; i < BOARD_SIZE; i++) {
        printf("\n");
        printf("%d ", i);
        for (int j = 0; j < BOARD_SIZE; j++) {
            printf("%c ", player[i][j]);
        }
    }
    printf("\n");

    printf("    Computer Board\n");
    printf("  ");
    for (int i = 0; i < 10; ++i) {
        printf("%d ", i);
    }
    for (int i = 0; i < BOARD_SIZE; i++) {
        printf("\n");
        printf("%d ", i);
        for (int j = 0; j < BOARD_SIZE; j++) {
            printf("%c ", computer[i][j]);
        }
    }
    printf("\n");
}

void generateTrapIndex(char **computerBoard, int *trapRow, int *trapCol) {

    printf("----Computer----\n");
    int side = rand() % 4;
    if (side == 0) {
        *trapRow = 0;
        *trapCol = rand() % (BOARD_SIZE - 2) + 1;
    } else if (side == 1) { // Right side
        *trapRow = rand() % (BOARD_SIZE - 2) + 1;
        *trapCol = BOARD_SIZE - 1;
    } else if (side == 2) {
        *trapRow = BOARD_SIZE - 1;
        *trapCol = rand() % (BOARD_SIZE - 2) + 1;
    } else if (side == 3) {
        *trapRow = rand() % (BOARD_SIZE - 2) + 1;
        *trapCol = 0;
    }

    printf("Generated trap index (row col): %d %d\n", *trapRow, *trapCol);
    //printf("Generated trap value: %d\n", *trapValue);
    computerBoard[*trapRow][*trapCol] = '*';
}

void generateTrapValues(int *trapValueComp, int *trapValuePlayer) {
    *trapValueComp = rand() % 5 + 1;
    *trapValuePlayer = rand() % 5 + 1;
}


