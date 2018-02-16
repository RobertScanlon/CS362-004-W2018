/*
    randomtestcard1.c
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
#define MAX_BUGS 1

// global bug counts
int pHandBug = 0;
int oHandBug = 0;
int buyBug = 0;
int playedBug = 0;
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

int councilRoomOracle(struct gameState *post)
{
    int retCode = 0;
	int b = 0;
    int retValue = 0;
	int player = post->whoseTurn;
	int handCntBefore = post->handCount[player];
	int numBuysBefore = post->numBuys;
	int playedCntBefore = post->playedCardCount;

	int othersHandCnt[post->numPlayers];
	for (int i = 0; i < post->numPlayers; i++) {
		if (i != player) {
			othersHandCnt[i] = post->handCount[i];
		}
	}

	// execute card effect
	retValue = cardEffect(council_room, 0, 0, 0, post, 0, &b);

	int handCntAfter = post->handCount[player];
	int numBuysAfter = post->numBuys;
	int playedCntAfter = post->playedCardCount;

	int othersHandCntAfter[post->numPlayers];
	for (int i = 0; i < post->numPlayers; i++) {
		if (i != player) {
			othersHandCntAfter[i] = post->handCount[i];
		}
	}

    // check that +4 cards drawn -1 card discarded
    if (pHandBug < MAX_BUGS) {
        if (myAssert(handCntBefore + 3, handCntAfter, "Council Room Player added 4 cards to players hand and Discards 1 from hand", 1) != 0) {
            pHandBug++;
            retCode = -1;
        }
    }

    // check that players buy is incremented by 1
    if (buyBug < MAX_BUGS) {
        if (myAssert(numBuysBefore + 1, numBuysAfter, "Council Room Player added +1 Buy", 1) != 0) {
            buyBug++;
            retCode = -1;
        }
    }

    // played card count increases by one after execution
    if (playedBug < MAX_BUGS) {
        if (myAssert(playedCntBefore + 1, playedCntAfter, "Council Room Player added 1 card to Played Cards", 1) != 0) {
            playedBug++;
            retCode = -1;
        }
    }

    // check that all other players gain a card
    if (oHandBug < (MAX_BUGS * post->numPlayers)) {
        for (int i = 0; i < post->numPlayers; i++) {
            if (i != player) {
                if (myAssert(othersHandCnt[i] + 1, othersHandCntAfter[i], "Council Room Other Player added 1 card to hand", 1) != 0) {
                    oHandBug++;
                    retCode = -1;
                }
            }
        }
    }

    // check that card effect returns 0 when council_room played
    if (returnBug < MAX_BUGS) {
        if (myAssert(0, retValue, "cardEffect returns 0 when Council Room is played", 1) != 0) {
            returnBug++;
            retCode = -1;
        }
    }

    return retCode;
}

void CouncilRoomRandomTester()
{
	fprintf(stderr, "BEGIN COUNCIL ROOM RANDOM TESTER %d ITERATIONS\n", NUMTESTS);
    int itr = 0;
    int bugCount = 0;
	srand(time(NULL));
	int seed = 1;
	int k[10] = {adventurer, embargo, village, minion, mine, cutpurse,
			 sea_hag, tribute, smithy, council_room};

    // create a unique gamestate for each random test
    for (int i = 0; i < NUMTESTS; i++ ) {
        struct gameState *G = malloc(sizeof(struct gameState));
        int numPlay = myRandom(2, MAX_PLAYERS);
        initializeGame(numPlay, k, 2, G);
        itr++;

        // make current number of buys a 'reasonable' number
        // including boundary case of 0
		G->numBuys = myRandom(0, 100);
		for (int j = 0; j < MAX_PLAYERS; j++) {

            // MAX_DECK - 4 is max to avoid overflow
			G->handCount[j] = myRandom(1, MAX_HAND - 4);
			G->deckCount[j] = myRandom(0, MAX_DECK);

            // min of 10 in case dekc is empty we still want to be
            // able to draw cards
			G->discardCount[j] = myRandom(10, MAX_DECK);

            // 'reasonable' played card count
            G->playedCardCount = myRandom(0, 100);
		}

		if (councilRoomOracle(G) != 0) {
            printGameState(G);
            bugCount++;
        }
        free(G);
	}

	fprintf(stderr, "END COUNCIL ROOM RANDOM TESTER %d ITERATIONS\n", itr);
    if (bugCount == 0) {
        fprintf(stderr, "ALL TESTS PASSED\n");
    } else {
        fprintf(stderr, "TESTING FOUND AT LEAST %d BUGS\n", bugCount);
    }
}

int
main()
{
	CouncilRoomRandomTester();
	return 0;
}
