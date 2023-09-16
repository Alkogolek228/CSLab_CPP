#include "Funcs_For_XO.h"
#include "Funcs_For_Roulette.h"
#include "Funcs_For_Poker.h"
#include "Funcs_For_Ship.h"
#include "Funcs_For_BAC.h"

int main(int argc, char const* argv[])
{
    for (;;)
    {
        system("cls");
        printf("Choose the game\n");
        printf("0 - exit\n1 - XO\n2 - Russian Roulette\n3 - Poker\n4 - Battleship\n5 - Bulls and Cows\n");

        switch (_getch())
        {
        case 48:
        {
            system("cls");
            printf("Good Bye!!!\n");
            break;
        }

        case 49:
        {
            system("cls");
            XOgame();
            _getch();
            continue;
        }

        case 50:
        {
            system("cls");
            roulette();
            _getch();
            continue;
        }

        case 51:
        {
            system("cls");
            pocker();
            _getch();
            continue;
        }

        case 52:
        {
            system("cls");
            battleship();
            _getch();
            continue;
        }

        case 53:
        {
            system("cls");
            BAC();
            _getch();
            continue;
        }

        default:
        {
            system("cls");
            printf("Error, there is no such game!\n");
            continue;
        }
        }
        return 0;
    }
}