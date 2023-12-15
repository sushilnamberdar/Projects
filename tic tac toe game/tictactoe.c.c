#include <stdio.h>
void printBord();
void initilizeBord(char bord[3][3]);
int checkWin(char bord[3][3], char player);
int isbordfull();
char bord[3][3];
int row, col;

int main()
{
    char currentplayer = 'X';
    initilizeBord(bord);
    do
    {
        printBord(bord);
        // for move player
        printf("Pleter %c, Enter (row and col) one by one  ", currentplayer);
        scanf("%d", &row);
        scanf("%d",&col);
        // check for sell is empety
        if (bord[row][col] == ' ')
        {
            // make a move
            bord[row][col] = currentplayer;
            // check for win
            if (checkWin(bord, currentplayer))
            {
                printBord(bord);
                printf("Player %c wins the game ", currentplayer);
                break;
            }
            // for  a tie match
            if (isbordfull(bord))
            {
                printBord(bord);
                printf("its a tie match \n");
                break;
            }

            // for switiching player
            currentplayer = (currentplayer == 'X') ? '0' : 'X';
        }
        else
        {
            printf("Cell is alread occupies !\n");
        }

    } while (1);
}
// for initilize the board
void initilizeBord(char bord[3][3])
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            bord[i][j] = ' ';
        }
    }
}

// for printing board
void printBord()
{
     printf("***** Tic Tac Toe ******\n");
    for (int i = 0; i < 3; i++)
    {
        printf("| %c | %c | %c |\n", bord[i][0], bord[i][1], bord[i][2]);
        printf("_____________\n");
    }
}
int isbordfull(char bord[3][3])
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (bord[i][j] == ' ')
            {
                return 0;
            }
        }
        
    }
    return 1;
}
int checkWin(char bord[3][3], char player)
{
    for (int i = 0; i < 3; i++)
    {
        // for row and col
        if (bord[i][0] == player && bord[i][1] == player && bord[i][2] == player || bord[0][i] == player && bord[1][i] == player && bord[2][i] == player)
        {
            return 1;
        }
        // for digonal check
        if (bord[0][0] == player && bord[1][1] == player && bord[2][2] == player || bord[0][2] == player && bord[1][1] == player && bord[2][0] == player)
        {
            return 1;
        }
        
    }
    return 0;
}