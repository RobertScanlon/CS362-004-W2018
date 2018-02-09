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

void adventurerChecker(struct gameState *post, int player, int drawnT, int card, int z, int *tmpHand) {
    // copy gamstate into 'pre' so it can be compared to its state
    // before cardEffect is called
    struct gameState pre;
    memcpy(&pre, post, sizeof(struct gameState));

    int numTreasure = 0;
    int currentCard = 0;
    int tmp[MAX_HAND];
    int tmpPos = 0;

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
    myAssert(0, memcmp(&pre, post, sizeof(struct gameState)), "Pre and Post states are equal", 1);
}

int
main()
{
	return 0;
}
