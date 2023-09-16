#include "Funcs_For_Ship.h"

#define ROWS 10
#define COLS 10
#define SHIPS 5

int playerBoard[ROWS][COLS];
int playerShots[ROWS][COLS];
int computerBoard[ROWS][COLS];
int computerShots[ROWS][COLS];
int playerShips, computerShips;

void printBoard(int player, int shots)
{
    int i, j;
    printf("\n  ");
    for (i = 0; i < COLS; i++)
    {
        printf("%d ", i);
    }
    printf("\n");

    for (i = 0; i < ROWS; i++)
    {
        printf("%d  ", i);
        for (j = 0; j < COLS; j++)
        {
            if (player)
            {
                if (shots)
                {
                    if (playerShots[i][j] == 1)
                    {
                        printf("# ");
                    }
                    else if (playerShots[i][j] == 2)
                    {
                        printf("X ");
                    }
                    else if (playerShots[i][j] == 3)
                    {
                        printf("O ");
                    }
                    else
                    {
                        printf(". ");
                    }
                }
                else
                {
                    if (playerBoard[i][j] == 1)
                    {
                        printf("# ");
                    }
                    else
                    {
                        printf(". ");
                    }
                }
            }
            else
            {
                if (shots)
                {
                    if (computerShots[i][j] == 1)
                    {
                        printf("# ");
                    }
                    else if (computerShots[i][j] == 2)
                    {
                        printf("X ");
                    }
                    else if (computerShots[i][j] == 3)
                    {
                        printf("O ");
                    }
                    else
                    {
                        printf(". ");
                    }
                }
                else
                {
                    if (computerBoard[i][j] == 1)
                    {
                        printf("# ");
                    }
                    else
                    {
                        printf(". ");
                    }
                }
            }
        }
        printf("\n");
    }
    printf("\n");
}

int Entership()
{
    int x;
    while (scanf("%d", &x) != 1 || x < 0 || x > 9 || getchar() != '\n')
    {
        printf("Error\n");
        rewind(stdin);
    }
    return x;
}

void placeShips()
{
    int i, x, y;
    for (i = 0; i < SHIPS; i++)
    {
        printf("Enter the coordinates for your ship #%d: ", i + 1);
        x = Entership();
        y = Entership();
        playerBoard[x][y] = 1;
    }
    playerShips = SHIPS;
}

void placeComputerShips()
{
    int i, x, y;
    for (i = 0; i < SHIPS; i++)
    {
        x = rand() % ROWS;
        y = rand() % COLS;
        if (computerBoard[x][y] == 0)
        {
            computerBoard[x][y] = 1;
        }
        else
        {
            i--;
        }
    }
    computerShips = SHIPS;
}

void attack(int x, int y, int player)
{
    if (player)
    {
        if (computerBoard[x][y] == 1)
        {
            computerBoard[x][y] = 0;
            computerShots[x][y] = 2;
            printf("You sank the computer's ship!\n");
            computerShips--;
        }
        else if (computerBoard[x][y] == 0)
        {
            computerShots[x][y] = 3;
            printf("You missed!\n");
        }
        else
        {
            printf("You already attacked that square.\n");
        }
    }
    else
    {
        if (playerBoard[x][y] == 1)
        {
            playerBoard[x][y] = 0;
            playerShots[x][y] = 2;
            printf("The computer sank your ship!\n");
            playerShips--;
        }
        else if (playerBoard[x][y] == 0)
        {
            playerShots[x][y] = 3;
            printf("The computer missed!\n");
        }
        else
        {
            printf("The computer already attacked that square.\n");
        }
    }
}

void battleship()
{
    int x, y;
    srand(time(0));

    printf("Welcome to Battleship!\n");
    printf("You will place your ships on the board and then the computer will do the same.\n");
    printf("Then, you and the computer will take turns attacking each other's ships.\n");
    printf("The board is %d by %d and you have %d ships.\n", ROWS, COLS, SHIPS);
    printBoard(1, 0);
    placeShips();
    placeComputerShips();

    while (playerShips > 0 && computerShips > 0)
    {
        printf("Enter the coordinates to attack: ");
        x = Entership();
        y = Entership();
        attack(x, y, 1);
        printBoard(0, 1);
        printBoard(1, 0);

        x = rand() % ROWS;
        y = rand() % COLS;
        printf("Computer attacks %d %d\n", x, y);
        attack(x, y, 0);
        printBoard(1, 1);
        printBoard(0, 0);
    }

    if (playerShips == 0)
    {
        printf("You lost!\n");
    }
    else
    {
        printf("You won!\n");
    }
}


