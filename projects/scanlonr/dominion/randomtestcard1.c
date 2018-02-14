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

#define NUMTESTS 100000
#define MAX_BUGS 1;

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
    int pHandBug = 0;
    int oHandBug = 0;
    int buyBug = 0;
    int playedBug = 0;
    int returnBug = 0;

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

	if (myAssert(handCntBefore + 3, handCntAfter, "Council Room Player added 4 cards to players hand and Discards 1 from hand", 1) != 0) {
        pHandBug++;
        if (pHandBug > MAX_BUGS) {
            return -1;
        }
    }
	if (myAssert(numBuysBefore + 1, numBuysAfter, "Council Room Player added +1 Buy", 1) != 0) {
        buyBug++;
        if (buyBug > MAX_BUGS) {
            return -1;
        }
    }
    if (myAssert(playedCntBefore + 1, playedCntAfter, "Council Room Player added 1 card to Played Cards", 1) != 0) {
        playedBug++;
        if (playedBug > MAX_BUGS) {
            return -1;
        }
    }
	for (int i = 0; i < post->numPlayers; i++) {
		if (i != player) {
			if (myAssert(othersHandCnt[i] + 1, othersHandCntAfter[i], "Council Room Other Player added 1 card to hand", 1) != 0) {
                oHandBug++;
                if (oHandBug > (MAX_BUGS * post->numPlayers)) {
                    return -1;
                }
            }
		}
	}
    if (myAssert(0, retValue, "cardEffect returns 0 when Council Room is played", 1) != 0) {
        returnBug++;
        if (returnBug > MAX_BUGS) {
            return -1;
        }
    }
    return 0;
}

void CouncilRoomRandomTester()
{
	fprintf(stderr, "BEGIN COUNCIL ROOM RANDOM TESTER %d ITERATIONS\n", NUMTESTS);
    int itr = 0;
	struct gameState *G = malloc(sizeof(struct gameState));
	srand(time(NULL));
	int seed = 1;
	int k[10] = {adventurer, embargo, village, minion, mine, cutpurse,
			 sea_hag, tribute, smithy, council_room};
	for (int i = 0; i < NUMTESTS; i++ ) {
        int numPlay = myRandom(2, MAX_PLAYERS);
        initializeGame(numPlay, k, 2, G);
        itr++;
		G->numBuys = myRandom(0, 100);
		for (int j = 0; j < MAX_PLAYERS; j++) {
			G->handCount[j] = myRandom(10, MAX_HAND / 2);
			G->deckCount[j] = myRandom(0, MAX_DECK / 2);
			G->discardCount[j] = myRandom(10, MAX_DECK / 2);
            G->playedCardCount = 0;
		}

		if (councilRoomOracle(G) != 0) {
            printGameState(G);
            //break;
        }
	}

	fprintf(stderr, "END COUNCIL ROOM RANDOM TESTER %d ITERATIONS\n", itr);
    if (itr == NUMTESTS) {
        fprintf(stderr, "NO ALL TESTS PASSED\n");
    }
    free(G);
}

int
main()
{
	CouncilRoomRandomTester();
	return 0;
}
