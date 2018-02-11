/*
    randomtestadventurer.c
*/
#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include "myAssert.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void adventurerChecker(struct gameState *post) {
    // copy gamstate into 'pre' so it can be compared to its state
    // before cardEffect is called
    struct gameState pre;
    memcpy(&pre, post, sizeof(struct gameState));

    int player = post->whoseTurn;

    int numTreasure = 0;
    int currentCard = 0;
    int tmp[MAX_HAND];
    int tmpPos = 0;

    int retValue;

    int choice1 = 0;
    int choice2 = 0;
    int choice3 = 0;
    int handPos = 0;
    int bonus = 0;

    retValue = cardEffect(adventurer, choice1, choice2, choice3, post, handPos, &bonus);

    while (numTreasure < 2) {
        currentCard = drawCard(player, &pre);
        if (currentCard == copper || currentCard == silver || currentCard == gold) {
            numTreasure++;
        } else {
            tmp[tmpPos] = currentCard;
            tmpPos++;
        }
    }
    for (int i = tmpPos - 1; i >= 0; i--) {
        pre.discard[player][pre.discardCount[player]] = tmp[i];
        pre.discardCount[player]--;
    }
    myAssert(0, retValue, "cardEffect returns 0", 1);
    myAssert(0, memcmp(&pre, post, sizeof(struct gameState)), "Pre and Post states are equal", 1);
}

void checkOracle()
{
    struct gameState G;
    int seed = 1;
    int k[10] = {adventurer, embargo, village, minion, mine, cutpurse,
                 sea_hag, tribute, smithy, council_room};

    initializeGame(2, k, seed, &G);
    adventurerChecker(&G);
}

int
main()
{
    checkOracle();
	return 0;
}
