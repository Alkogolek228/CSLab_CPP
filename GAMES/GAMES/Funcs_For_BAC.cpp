#include "Funcs_For_BAC.h"

int Enter()
{
    int x;
    while (scanf("%d", &x) != 1 || x < 1000 || x > 9999 || getchar() != '\n')
    {
        printf("Error\n");
        rewind(stdin);
    }
    return x;
}

void BAC()
{
    srand(time(NULL));
    printf("Welcome to the Bulls and Cows game. Try to find the secret number\n");
    printf("If number is correct - cow, if number is correct and placed rightly - bull\n");

    // Generate the secret number
    int secret[NUM_DIGITS];
    for (int i = 0; i < NUM_DIGITS; i++)
    {
        secret[i] = rand() % 10;
    }

    while (1)
    {
        int bulls = 0, cows = 0;
        int guess;
        printf("Enter your guess: ");
        guess = Enter();

        int guess_digits[NUM_DIGITS];
        for (int i = 0; i < NUM_DIGITS; i++)
        {
            guess_digits[i] = guess % 10;
            guess /= 10;
        }

        // Check for bulls and cows
        for (int i = 0; i < NUM_DIGITS; i++)
        {
            if (guess_digits[i] == secret[i])
            {
                bulls++;
            }
            else
            {
                for (int j = 0; j < NUM_DIGITS; j++)
                {
                    if (guess_digits[i] == secret[j])
                    {
                        cows++;
                    }
                }
            }
        }

        printf("Bulls: %d, Cows: %d\n", bulls, cows);

        if (bulls == NUM_DIGITS)
        {
            printf("You won!\n");
            break;
        }
    }
}