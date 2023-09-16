#include "Funcs_For_Poker.h"

const char* RANKS[] = { "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K", "A" };
//const wchar_t* SUITS[4] = {L"\u2660", L"\u2665", L"\u2666", L"\u2663"};
const char* SUITS[] = { "S", "C", "H", "D" };

// Initializes a deck of cards
void init_deck(struct deck* deck)
{
    int idx = 0;
    for (int i = 0; i < 13; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            deck->cards[idx].rank = RANKS[i];
            deck->cards[idx].suit = SUITS[j];
            idx++;
        }
    }
    deck->num_cards = NUM_CARDS_IN_DECK;
}

void print_hand(struct hand* hand)
{
    for (int i = 0; i < NUM_CARDS_IN_HAND; i++)
    {
        //wprintf(L"%s%lc ", hand->cards[i].rank, hand->cards[i].suit);
        printf("%s%s ", hand->cards[i].rank, hand->cards[i].suit);
    }
    printf("\n");
}

void shuffle(struct deck* deck)
{
    for (int i = 0; i < NUM_CARDS_IN_DECK; i++) {

        int j = rand() % NUM_CARDS_IN_DECK;
        struct card temp = deck->cards[i];
        deck->cards[i] = deck->cards[j];
        deck->cards[j] = temp;
    }
}

void deal(struct hand* hand, struct deck* deck)
{
    for (int i = 0; i < NUM_CARDS_IN_HAND; i++)
    {
        hand->cards[i] = deck->cards[deck->num_cards - 1];
        deck->num_cards--;
    }
}

int calculate_score(struct hand* hand)
{
    int score = 0;
    int ranks[13] = { 0 };
    int suits[4] = { 0 };

    for (int i = 0; i < NUM_CARDS_IN_HAND; i++)
    {
        for (int j = 0; j < 13; j++)
        {
            if (strcmp(hand->cards[i].rank, RANKS[j]) == 0)
            {
                ranks[j]++;
                break;
            }
        }

        for (int j = 0; j < 4; j++)
        {
            if (strcmp(hand->cards[i].suit, SUITS[j]) == 0)
            {
                suits[j]++;
                break;
            }
        }
    }
    bool straight = true;
    for (int i = 0; i < 13; i++)
    {
        if (ranks[i] != 1)
        {
            straight = false;
            break;
        }
    }
    if (straight)
    {
        score = 4;
    }
    bool flush = false;
    for (int i = 0; i < 4; i++)
    {
        if (suits[i] == NUM_CARDS_IN_HAND)
        {
            flush = true;
            break;
        }
    }

    if (flush)
    {
        score = 5;
    }

    for (int i = 0; i < 13; i++)
    {
        if (ranks[i] == 4)
        {
            score = 8;
            break;
        }
    }

    for (int i = 0; i < 13; i++)
    {
        if (ranks[i] == 3)
        {
            score = 3;
            break;
        }
    }

    for (int i = 0; i < 13; i++)
    {
        if (ranks[i] == 2)
        {
            score = 1;
            break;
        }
    }
    return score;
}

int Enter(int player_money)
{
    int x;
    while (scanf("%d", &x) != 1 || x < 0 || x > player_money || getchar() != '\n')
    {
        printf("Error\n");
        rewind(stdin);
    }
    return x;
}

void pocker()
{
    setlocale(LC_ALL, "");
    printf("Welocome to the simplified veersion of poker!\n");
    int player_money = 100;
    int bet;

    while (player_money > 0)
    {
        printf("You have $%d. Enter your bet: ", player_money);
        bet = Enter(player_money);

        struct deck deck;
        init_deck(&deck);
        shuffle(&deck);

        struct hand player_hand, computer_hand;
        deal(&player_hand, &deck);
        deal(&computer_hand, &deck);

        player_hand.score = calculate_score(&player_hand);
        computer_hand.score = calculate_score(&computer_hand);

        printf("Your hand: ");
        print_hand(&player_hand);
        printf("Computer's hand: ");
        print_hand(&computer_hand);

        if (player_hand.score > computer_hand.score)
        {
            printf("You win $%d!\n", bet);
            player_money += bet;
        }
        else if (player_hand.score < computer_hand.score)
        {
            printf("Computer wins $%d!\n", bet);
            player_money -= bet;
        }
        else 
        {

            printf("It's a tie!\n");
        }
    }
    printf("You have run out of money. Game over.\n");
}

