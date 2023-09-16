#include "Funcs_For_Roulette.h"

void roulette()
{
	printf("Welocome to the Russain Roulette game\nChoose the game mode\n");
	srand(time(NULL));
	int turn = 0;
	printf("1 - you VS player\n");
	printf("2 - you VS PC\n");

	switch (_getch())
	{
		for (;;)
		{
		case 49:
		{
			for (;;)
			{
				printf("Player number %d - your turn!\n", (turn) % 2 + 1);
				_getch();

				if (rand() % 7 == 0)
				{
					printf("Player number %d - lost!!!\n", (turn) % 2 + 1);
					return;
				}

				else
				{
					printf("Player number %d - you're lucky!\n", (turn) % 2 + 1);
					turn++;
				}
			}
		}

		case 50:
		{
			for (;;)
			{
				printf("Player - your turn!\n");
				_getch();

				if (rand() % 7 == 0 && rand() % 7 == 1)
				{
					printf("Player - lost!\n");
					return;
				}

				else
				{
					printf("Player - you're lucky!\n");
					turn++;
				}

				if (rand() % 7 == 1)
				{
					printf("PC - lost!!!\n", (turn) % 2 + 1);
					return;
				}
			}
		}
		}
	}
}
