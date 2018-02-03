#include <stdio.h>
#include <stdlib.h>

//Simple Command Line TicTacToe board game with AI

/* ToDo:
 * Board Format     DONE
 * Player1 Move     DONE
 * Player2 Move     DONE
 * Move Control     DONE
 * Board Full Check DONE
 * Win Conditions   DONE
 * Start Screen     INCOMPLETE
 * AI               INCOMPLETE
 * Bug Fixing       ---
 * Clean Up         ---
 * QOL Changes      ---
 * */

char board[2][2]; //Initialize the board

//Holds positions of input
int xMove = 0;
int yMove = 0;

//Used for later check whos turn and game state
int move = 0;

//Unused right now, Used for menu
int gameType = 0;

//Counts how many moved have been taken if this reaches 9 it means the board is full
int moveCount = 0;


int drawBoard(void) {
    //Draws the board
    printf("     0   1   2 \n");
    printf("\n    ---+---+---\n"); //Formatter
    for (int x = 0; x < 3; x++) {
        printf("%d  ", x);
        for (int y = 0; y < 3; y++) {
            if (y == 1) {
                printf(" %d ", board[x][y]);
            } else {
                printf("| %d |", board[x][y]);
            }
        }
        printf("\n    ---+---+---\n"); //Formatter
    }
    return 0;
}

int player1move() {
    //Assigns a 1 to the board position selected if not used
    int x = 0;
    printf("Player 1 turn!\n");
    while (x == 0) {
        printf("X: ");
        scanf("%d", &xMove);
        printf("Y: ");
        scanf("%d", &yMove);
        if (board[xMove][yMove] != 0)
            printf("Position already taken");
        else
            board[xMove][yMove] = 1;
        x = 1;
    }
    drawBoard();
    return 0;
}


int player2move() {
    //Assigns a 2 to the location if not used
    int x = 0;
    printf("Player 2 turn!\n");
    while (x == 0) {
        printf("X: ");
        scanf("%d", &xMove);
        printf("Y: ");
        scanf("%d", &yMove);
        if (board[xMove][yMove] != 0)
            printf("Position already taken");
        else
            board[xMove][yMove] = 2;
        x = 1;
    }

    drawBoard();
    return 0;
}


int playermove() {
    //Determines the game state and player turn
    while (moveCount != 9) {
        switch (move) {
            case 0:
                player1move();
                if (checkWin() == 1)
                    move = 2;
                else
                    move = 1;
                break;
            case 1:
                player2move();
                if (checkWin() == 1)
                    move = 2;
                else
                    move = 0;
                break;
            case 2 :
                exit(0);
        }
        moveCount++;

    }
    printf("\n Game Over \n");
    return 0;
}

/* Win conditions

 *
 * Columns
 * 00 10 20 Left Column
 * 01 11 21 Middle Column
 * 02 12 22 Right Column
 *
 * Diagonal
 * 00 11 22 Top Left > Bottom Right
 * 20 11 02 Bottom Left > Top Right
 */

int checkWin() {
    //ToDo: Algorthim for detecting 3 in a row?
    //checks if win condition has been met
    int win = 1;
    /* Rows
    * 00 01 02 Top Row
    * 10 11 12 Middle Row
    * 20 21 22 Bottom Row */
    for (int i = 1; i == 1 || i == 2; i++) {
        if (board[0][0] == i && board[0][1] == i && board[0][2] == i)           //Top
            printf("\nPlayer %d wins!\n", (move + 1));
        else if (board[1][0] == i && board[1][1] == i && board[1][2] == i)      //Middle
            printf("\nPlayer %d wins!\n", (move + 1));
        else if (board[2][0] == i && board[2][1] == i && board[2][2] == i)      //Bottom
            printf("\nPlayer %d wins!\n", (move + 1));
        else if (board[0][0] == i && board[1][0] == i && board[2][0] == i)      //Left
            printf("\nPlayer %d wins!\n", (move + 1));
        else if (board[0][1] == i && board[1][1] == i && board[2][1] == i)      //Middle
            printf("\nPlayer %d wins!\n", (move + 1));
        else if (board[0][2] == i && board[1][2] == i && board[2][2] == i)      //Right
            printf("\nPlayer %d wins!\n", (move + 1));
        else if (board[0][0] == i && board[1][1] == i && board[2][2] == i)      //TL > BR
            printf("\nPlayer %d wins!\n", (move + 1));
        else if (board[2][0] == i && board[1][1] == i && board[0][2] == i)      //BL > TR
            printf("\nPlayer %d wins!\n", (move + 1));
        else
            win = 0;
    }
    return win;
}


int main() {
    drawBoard();
    playermove();
    return 0;
}

