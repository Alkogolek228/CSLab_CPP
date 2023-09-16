#include "Funcs_For_XO.h"

void printBoard(char board[ROWS][COLS])
{
    printf("\n");
    for (int row = 0; row < ROWS; row++)
    {
        for (int col = 0; col < COLS; col++)
        {
            printf("%c ", board[row][col]);
            if (col < COLS - 1)
            {
                printf("| ");
            }
        }
        printf("\n");
        if (row < ROWS - 1)
        {
            printf("---------\n");
        }
    }
    printf("\n");
}

int checkVictory(char board[ROWS][COLS])
{
    // Check rows and columns for victory
    for (int row = 0; row < ROWS; row++)
    {
        for (int col = 0; col < COLS; col++)
        {
            int following = 1;
            // Check row
            for (int i = 1; i < TO_WIN; i++)
            {
                if (board[row][col] == board[row][col + i] && board[row][col] != ' ')
                {
                    following++;
                }
            }
            if (following == TO_WIN)
            {
                return board[row][col] == 'X' ? 1 : 2;
            }
            // Check column
            following = 1;
            for (int i = 1; i < TO_WIN; i++)
            {
                if (board[row][col] == board[row + i][col] && board[row][col] != ' ')
                {
                    following++;
                }
            }
            if (following == TO_WIN)
            {
                return board[row][col] == 'X' ? 1 : 2;
            }
        }
    }

    // Check diagonals for victory
    int following = 1;
    for (int i = 1; i < TO_WIN; i++)
    {
        if (board[0][0] == board[i][i] && board[0][0] != ' ')
        {
            following++;
        }
    }
    if (following == TO_WIN)
    {
        return board[0][0] == 'X' ? 1 : 2;
    }
    following = 1;
    for (int i = 1; i < TO_WIN; i++)
    {
        if (board[0][TO_WIN - 1] == board[i][TO_WIN - 1 - i] && board[0][TO_WIN - 1] != ' ')
        {
            following++;
        }
    }
    if (following == TO_WIN)
    {
        return board[0][TO_WIN - 1] == 'X' ? 1 : 2;
    }

    // If no victory was found, return 0
    return 0;
}

int checkDraw(char board[ROWS][COLS])
{
    // Check if the board is full
    for (int row = 0; row < ROWS; row++)
    {
        for (int col = 0; col < COLS; col++)
        {
            if (board[row][col] == ' ')
            {
                return 0;
            }
        }
    }
    // If the board is full, the game is a draw
    return 1;
}

void XOgame()
{
    char board[ROWS][COLS];
    for (int row = 0; row < ROWS; row++)
    {
        for (int col = 0; col < COLS; col++)
        {
            board[row][col] = ' ';
        }
    }

    printf("Welcome to the XO game\n");
    printf("Choose the game mode:\n");
    printf("1 - You VS PC\n");
    printf("2 - You VS Player\n");
    switch (_getch())
    {
    case 49:
    {
        srand(time(NULL));

        int player = 1; // 1 for player, 2 for computer
        int winner = 0;
        while (winner == 0)
        {
            printBoard(board);

            if (player == 1)
            {
                // Get player's move
                printf("Enter your move (row column): ");
                int row, col;
                scanf("%d %d", &row, &col);
                if (row < 0 || row >= ROWS || col < 0 || col >= COLS || board[row][col] != ' ')
                {
                    printf("Invalid move!\n");
                    continue;
                }
                board[row][col] = 'X';
            }
            else
            {
                // Get computer's move
                // First, check if there is a move that would allow the computer to win
                for (int row = 0; row < ROWS; row++)
                {
                    for (int col = 0; col < COLS; col++)
                    {
                        if (board[row][col] == ' ')
                        {
                            board[row][col] = 'O';
                            if (checkVictory(board) == 2)
                            {
                                printf("Computer's move: %d %d\n", row, col);
                                goto end_turn;
                            }
                            board[row][col] = ' ';
                        }
                    }
                }
                // Then, check if there is a move that would block the player from winning
                for (int row = 0; row < ROWS; row++)
                {
                    for (int col = 0; col < COLS; col++)
                    {
                        if (board[row][col] == ' ')
                        {
                            board[row][col] = 'X';
                            if (checkVictory(board) == 1)
                            {
                                board[row][col] = 'O';
                                printf("Computer's move: %d %d\n", row, col);
                                goto end_turn;
                            }
                            board[row][col] = ' ';
                        }
                    }
                }
                // Otherwise, choose a random move
                int row, col;
                do {
                    row = rand() % ROWS;
                    col = rand() % COLS;
                } while (board[row][col] != ' ');
                board[row][col] = 'O';
                printf("Computer's move: %d %d\n", row, col);
            }
        end_turn:

            // Check for victory or draw
            winner = checkVictory(board);
            if (winner == 0 && checkDraw(board))
            {
                winner = 3; // 3 for draw
            }
            if (winner == 0)
            {
                // Switch players
                player = player == 1 ? 2 : 1;
            }
        }

        // Print the final board and the winner (or draw)
        printBoard(board);
        if (winner == 1)
        {
            printf("You won!\n");
        }
        else if (winner == 2)
        {
            printf("Computer won!\n");
        }
        else
        {
            printf("It's a draw!\n");
        }
    }
    case 50:
    {
        int player = 1; // 1 for player 1, 2 for player 2
        int winner = 0;
        while (winner == 0)
        {
            printBoard(board);

            // Get player's move
            printf("Player %d's turn. Enter your move (row column): ", player);
            int row, col;
            scanf("%d %d", &row, &col);
            if (row < 0 || row >= ROWS || col < 0 || col >= COLS || board[row][col] != ' ')
            {
                printf("Invalid move!\n");
                continue;
            }
            board[row][col] = player == 1 ? 'X' : 'O';

            // Check for victory or draw
            winner = checkVictory(board);
            if (winner == 0 && checkDraw(board))
            {
                winner = 3; // 3 for draw
            }
            if (winner == 0)
            {
                // Switch players
                player = player == 1 ? 2 : 1;
            }
        }

        printBoard(board);
        if (winner == 1)
        {
            printf("Player 1 won!\n");
        }
        else if (winner == 2)
        {
            printf("Player 2 won!\n");
        }
        else if (winner == 3)
        {
            printf("It's a draw!\n");
        }
    }
    }
}
