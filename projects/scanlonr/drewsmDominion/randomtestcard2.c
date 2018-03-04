/*
    Steward Card
    randomtestcard2.c
*/
#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include "myAssert.h"
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string.h>

#define NUMTESTS 10000
#define MAX_BUGS 10

int handCountBug = 0;
int coinCountBug = 0;
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
    fprintf(stderr, "deckCount:       %d\n", g->deckCount[g->whoseTurn]);
    fprintf(stderr, "discardCount:    %d\n", g->discardCount[g->whoseTurn]);
    fprintf(stderr, "playedCardCount: %d\n", g->playedCardCount);
}

int myRandom(int min, int max) {
    return (rand() % (max - min + 1)) + min;
}

int StewardRoomOracle(struct gameState *post, int choice1, int p)
{
	int b = 0;
    int retCode = 0;
    int handCountBefore = post->handCount[p];
    int coinsBefore = post->coins;

	//int retValue = cardEffect(steward, choice1, 0, 0, post, 0, &b);
    int retValue = stewardEffect(choice1, 0, 0, post, 0, p);

    int handCountAfter = post->handCount[p];
    int coinsAfter = post->coins;

    // when choice is 1 check that 2 cards drawn, played card discarded
    if (choice1 == 1) {
        if (handCountBug < MAX_BUGS) {
            if (myAssert(handCountBefore + 1, handCountAfter, "+2 cards drawn, played card discarded", 1) != 0) {
                handCountBug++;
                retCode = -1;
            }
        }

    // when choice is 2, check that +2 coins and played card discarded
    } else if (choice1 == 2) {
        if (coinCountBug < MAX_BUGS) {
            if (myAssert(coinsBefore + 2, coinsAfter, "+2 coins", 1) != 0) {
                coinCountBug++;
                retCode = -1;
            }
        }
        if (handCountBug < MAX_BUGS) {
            if (myAssert(handCountBefore, handCountAfter + 1, "played card discarded", 1) != 0) {
                handCountBug++;
                retCode = -1;
            }
        }

    // if any other choice value, check that total of 3 cards removed from hand
    } else {
        if (handCountBug < MAX_BUGS) {
            if (myAssert(handCountBefore, handCountAfter + 3, "played card discarded, 2 cards trashed", 1) != 0) {
                handCountBug++;
                retCode = -1;
            }
        }
    }

    // check that card effect returns 0 when steward is played
    if (returnBug < MAX_BUGS) {
        if (myAssert(0, retValue, "cardEffect returns 0 when Steward is played", 1) != 0) {
            returnBug++;
            retCode = -1;
        }
    }

    return retCode;
}

void StewardRoomRandomTester()
{
    int bugCount = 0;
	fprintf(stderr, "BEGIN STEWARD RANDOM TESTER %d ITERATIONS\n", NUMTESTS);
	struct gameState *G = malloc(sizeof(struct gameState));
	srand(time(NULL));
	int seed = 1;
	int itr = 0;
	int choice1;
	int p = 0;
	int k[10] = {adventurer, embargo, village, minion, mine, cutpurse,
			 sea_hag, tribute, smithy, council_room};

    // create random gamestate for each test run
	for (int i = 0; i < NUMTESTS; i++ ) {
		struct gameState *G = malloc(sizeof(struct gameState));
		itr++;
		initializeGame(2, k, 2, G);

        // max MAX_HAND - 2 to allow for up to 2 cards drawn
		G->handCount[p] = myRandom(1, MAX_HAND - 2);
		G->deckCount[p] = myRandom(0, MAX_DECK);

        // min 5 so we don't end up with empty deck and discard
		G->discardCount[p] = myRandom(5, MAX_DECK - 1);

        // choice can be 0, 1, 2, or 3
        choice1 = myRandom(0, 3);

        // 'reasonable' coin values
        G->coins = myRandom(0, 100);

        if (StewardRoomOracle(G, choice1, p) != 0) {
            bugCount++;
            printGameState(G);
        }
		free(G);
	}

	fprintf(stderr, "END STEWARD RANDOM TESTER %d ITERATIONS\n", itr);
    if (bugCount == 0) {
        fprintf(stderr, "ALL TESTS PASSED\n");
    } else {
        fprintf(stderr, "TESTING FOUND AT LEAST %d BUGS\n", bugCount);
    }
}

int
main()
{
	StewardRoomRandomTester();
	return 0;
}
