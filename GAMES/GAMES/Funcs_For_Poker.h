#define _CRT_SECURE_NO_WARNINGS
#pragma once
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <locale.h>
#include <wchar.h>
#include <io.h>

#define NUM_CARDS_IN_DECK 52
#define NUM_CARDS_IN_HAND 5


struct card
{
    const char* rank;
    const char* suit;
};

struct hand
{
    struct card cards[NUM_CARDS_IN_HAND];
    int score;
};

struct deck
{
    struct card cards[NUM_CARDS_IN_DECK];
    int num_cards;
};

void init_deck(struct deck* deck);
void print_hand(struct hand* hand);
void shuffle(struct deck* deck);
void deal(struct hand* hand, struct deck* deck);
int calculate_score(struct hand* hand);
int Enter(int player_money);
void pocker();