/*
    Adventurer Card
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
#define MAX_BUGS 1

// global counts of different bugs
int treasureBug = 0;
int handBug = 0;
int discardBug = 0;
int returnBug = 0;

void printGameState(struct gameState *g)
{
    fprintf(stderr, "numPlayers:      %d\n", g->numPlayers);
    fprintf(stderr, "whoseTurn:       %d\n", g->whoseTurn);
    fprintf(stderr, "phase:           %d\n", g->phase);
    fprintf(stderr, "numActions:      %d\n", g->numActions);
    fprintf(stderr, "coins:           %d\n", g->coins);
    fprintf(stderr, "numBuys:         %d\n", g->numBuys);

    fprintf(stderr, "handCount:       %d\n", g->handCount[g->whoseTurn]);
    // for (int i = 0; i < g->handCount[g->whoseTurn]; i++) {
    //     fprintf(stderr, "\thand[%d]: %d\n", i, g->hand[g->whoseTurn][i]);
    // }

    fprintf(stderr, "deckCount:       %d\n", g->deckCount[g->whoseTurn]);
    // for (int i = 0; i < g->deckCount[g->whoseTurn]; i++) {
    //     fprintf(stderr, "\tdeck[%d]: %d\n", i, g->deck[g->whoseTurn][i]);
    // }

    fprintf(stderr, "discardCount:    %d\n", g->discardCount[g->whoseTurn]);
    // for (int i = 0; i < g->discardCount[g->whoseTurn]; i++) {
    //     fprintf(stderr, "\tdiscard[%d]: %d\n", i, g->discard[g->whoseTurn][i]);
    // }

    fprintf(stderr, "playedCardCount: %d\n", g->playedCardCount);
}

int myRandom(int min, int max) {
    return (rand() % (max - min + 1)) + min;
}


int adventurerOracle(struct gameState *post)
{
    int retCode = 0;
    int retValue = 0;
    int b = 0;
    int tBefore = 0;

    // get discard count before execution
    int disCntBefore = post->discardCount[0];

    // count treasure cards before execution
    for (int i = 0; i < post->handCount[0]; i++) {
        if (post->hand[post->whoseTurn][i] == copper ||
            post->hand[post->whoseTurn][i] == silver ||
            post->hand[post->whoseTurn][i] == gold) {
            tBefore++;
        }
    }

    // get hand count before execution
    int hCntBefore = post->handCount[post->whoseTurn];

    retValue = cardEffect(adventurer, 0, 0, 0, post, 0, &b);

    // get values after code executes
    int tAfter = 0;
    for (int i = 0; i < post->handCount[0]; i++) {
        if (post->hand[post->whoseTurn][i] == copper ||
            post->hand[post->whoseTurn][i] == silver ||
            post->hand[post->whoseTurn][i] == gold) {
            tAfter++;
        }
    }
    int hCntAfter = post->handCount[post->whoseTurn];

    // check that the number of treasure cards in the player's hand
    // increases by 2 after calling code
    if (treasureBug < MAX_BUGS) {
        if (myAssert(tBefore + 2, tAfter, "Treasure in hand +2", 1) != 0) {
            treasureBug++;
            retCode = -1;
        }
    }

    // check that players hand only contains one more card
    // to account for discarding played card
    if (handBug < MAX_BUGS) {
        if (myAssert(hCntBefore + 1, hCntAfter, "Hand Count increased by 1 (+2 treasure, -1 card played)", 1) != 0) {
            handBug++;
            retCode = -1;
        }
    }

    // make sure non treasures are discarded
    if (discardBug < MAX_BUGS) {
        if (post->discardCount[0] <= disCntBefore) {
            myAssert(0, 1, "Non treasure cards discarded from hand", 1);
            discardBug++;
            retCode = -1;
        }
    }

    // check that cardEffect return 0 after adventurer played
    if (returnBug < MAX_BUGS) {
        if (myAssert(0, retValue, "cardEffect returns 0 on adventurer play", 1) != 0) {
            returnBug++;
            retCode = -1;
        }
    }
    return retCode;
}

void adventurerRandomTester()
{
    fprintf(stderr, "BEGIN ADVENTURER RANDOM TESTER %d ITERATIONS\n", NUMTESTS);
    srand(time(NULL));
    int bugCount = 0;
    int treasures = 0;
    int itr = 0;
    int seed = 1;
    int k[10] = {adventurer, embargo, village, minion, mine, cutpurse,
             sea_hag, tribute, smithy, council_room};

    // create a new random game state for each test case
    for (int i = 0; i < NUMTESTS; i++) {
        struct gameState *G = malloc(sizeof(struct gameState));
        itr++;
        initializeGame(2, k, 2, G);

        // hand count can be from 0 to max - 2
        // because up to 2 cards can be added to the hand
        // and we can not overflow the hand array
        G->handCount[0] = myRandom(1, MAX_HAND - 2);
        for (int h = 0; h < G->handCount[0]; h++) {
            G->hand[0][h] = myRandom(0,  treasure_map);
        }

        treasures = 0;

        // make sure there are at least 2 treasure cards in the deck + discard
        while (treasures < 2) {

            // let the deck be possibly empty to test empty deck code in
            // adventurer implementation
            G->deckCount[0] = myRandom(0,  MAX_DECK);
            for (int d = 0; d < G->deckCount[0]; d++) {
                G->deck[0][d] = myRandom(0,  treasure_map);
                if (d == 0) {
                    G->deck[0][d] = smithy;
                }
                if (G->deck[0][d] == copper || G->deck[0][d] == silver || G->deck[0][d] == gold) {
                    treasures++;
                }
            }

            // no not allow discard to be empty
            // this avoid failure when both deck and discard are empty
            // which would not happen in an actual game, therefore, no need to
            // test
            G->discardCount[0] = myRandom(10,  MAX_DECK);
            for (int c = 0; c < G->discardCount[0]; c++) {
                G->discard[0][c] = myRandom(0,  treasure_map);
                if (G->discard[0][c] == copper || G->discard[0][c] == silver || G->discard[0][c] == gold) {
                    treasures++;
                }
            }
        }

        // if any assertions failed, print gamestate
        if (adventurerOracle(G) != 0) {
            printGameState(G);
            bugCount++;
        }
        free(G);
    }
    fprintf(stderr, "END ADVENTURER RANDOM TESTER %d ITERATIONS\n", itr);
    if (bugCount == 0) {
        fprintf(stderr, "ALL TESTS PASSED\n");
    } else {
        fprintf(stderr, "TESTING FOUND AT LEAST %d BUGS\n", bugCount);
    }
}



int
main()
{
    adventurerRandomTester();
	return 0;
}
