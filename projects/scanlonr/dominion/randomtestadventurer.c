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
#include <time.h>
#include <math.h>

#define NUMTESTS 10000

int myRandom(int min, int max) {
    return (rand() % (max - min + 1)) + min;
}

void adventurerChecker(struct gameState *post) {
    // copy gamstate into 'pre' so it can be compared to its state
    // before cardEffect is called
    struct gameState pre;
    memcpy(&pre, post, sizeof(struct gameState));

    int player = pre.whoseTurn;

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

    int befTreasurePre = 0;
    int befTreasurePost = 0;
    int treasurePre = 0;
    int treasurePost = 0;

    for (int i = 0; i < pre.handCount[player]; i++) {
        if (pre.hand[player][i] == copper ||
            pre.hand[player][i] == silver ||
            pre.hand[player][i] == gold) {
                befTreasurePre++;
            }
    }
    for (int i = 0; i < post->handCount[player]; i++) {
        if (post->hand[player][i] == copper ||
            post->hand[player][i] == silver ||
            post->hand[player][i] == gold) {
                befTreasurePost++;
            }
    }
    // call cardEffect to execute adventurer code on the 'post' gameState
    retValue = cardEffect(adventurer, choice1, choice2, choice3, post, handPos, &bonus);

    // perform what the adventurer implmentation should do on the 'pre' gameState
    while (numTreasure < 2) {
        drawCard(player, &pre);
        currentCard = pre.hand[player][pre.handCount[player]-1];
        if (currentCard == copper || currentCard == silver || currentCard == gold) {
            numTreasure++;
        } else {
            tmp[tmpPos]=currentCard;
            pre.handCount[player]--;
            tmpPos++;
        }
    }
    for (int j = tmpPos - 1; j >= 0; j--) {
        pre.discard[player][pre.discardCount[player]] = tmp[j];
        pre.discardCount[player]++;
    }

    // count the number of treasure cards in both gameStates after execution
    // of adventurer code
    for (int i = 0; i < pre.handCount[player]; i++) {
        if (pre.hand[player][i] == copper ||
            pre.hand[player][i] == silver ||
            pre.hand[player][i] == gold) {
                treasurePre++;
            }
    }
    for (int i = 0; i < post->handCount[player]; i++) {
        if (post->hand[player][i] == copper ||
            post->hand[player][i] == silver ||
            post->hand[player][i] == gold) {
                treasurePost++;
            }
    }
    myAssert((treasurePre - befTreasurePre), (treasurePost - befTreasurePost),
              "Number of Treasure cards in hand after execution is correct", 1);
    myAssert(0, retValue, "cardEffect returns 0", 1);
}

void checkOracle()
{
    struct gameState G;
    int seed = 1;
    int k[10] = {adventurer, embargo, village, minion, mine, cutpurse,
                 sea_hag, tribute, smithy, council_room};

    initializeGame(2, k, seed, &G);
    G.deck[G.whoseTurn][0] = smithy;
    G.deck[G.whoseTurn][1] = smithy;
    G.deck[G.whoseTurn][2] = smithy;
    G.deck[G.whoseTurn][3] = copper;
    G.deck[G.whoseTurn][4] = smithy;
    G.deck[G.whoseTurn][5] = smithy;
    G.deck[G.whoseTurn][6] = silver;
    G.deckCount[G.whoseTurn] = 7;
    adventurerChecker(&G);
}

void randomTester()
{
    fprintf(stderr, "BEGIN ADVENTURER RANDOM TESTER %d ITERATIONS\n", NUMTESTS);
    struct gameState G;
    srand(time(NULL));
    int treasures;
    for (int i = 0; i < NUMTESTS; i++) {
        for (int j = 0; j < sizeof(struct gameState); j++) {
            ((char*)&G)[i] = myRandom(0, 256);
        }
        G.numPlayers = myRandom(1, MAX_PLAYERS);
        G.whoseTurn = myRandom(0, G.numPlayers - 1);

        G.handCount[G.whoseTurn] = myRandom(0,  MAX_HAND);
        for (int h = 0; h < G.handCount[G.whoseTurn]; h++) {
            G.hand[G.whoseTurn][h] = myRandom(0,  treasure_map);
        }

        while (treasures < 2) {
            treasures = 0;
            G.deckCount[G.whoseTurn] = myRandom(0,  MAX_DECK);
            for (int d = 0; d < G.deckCount[G.whoseTurn]; d++) {
                G.deck[G.whoseTurn][d] = myRandom(0,  treasure_map);
                if (G.deck[G.whoseTurn][d] == copper || G.deck[G.whoseTurn][d] == silver || G.deck[G.whoseTurn][d] == gold) {
                    treasures++;
                }
            }


            G.discardCount[G.whoseTurn] = myRandom(0,  MAX_DECK);
            for (int c = 0; c < G.handCount[G.whoseTurn]; c++) {
                G.discard[G.whoseTurn][c] = myRandom(0,  treasure_map);
                if (G.discard[G.whoseTurn][c] == copper || G.discard[G.whoseTurn][c] == silver || G.discard[G.whoseTurn][c] == gold) {
                    treasures++;
                }
            }
        }

        adventurerChecker(&G);
    }
    fprintf(stderr, "END ADVENTURER RANDOM TESTER %d ITERATIONS\n", NUMTESTS);
}



int
main()
{
    //checkOracle();
    randomTester();
	return 0;
}
