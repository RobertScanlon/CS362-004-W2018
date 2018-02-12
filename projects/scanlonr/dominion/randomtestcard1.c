/*
    randomtestcard1.c
*/
#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include "myAssert.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define NUMTESTS 100

int myRandom(int min, int max) {
    return (rand() % (max - min + 1)) + min;
}

void councilRoomOracle(struct gameState *post)
{
	int b = 0;

	int player = post->whoseTurn;
	int handCntBefore = post->handCount[player];
	int numBuysBefore = post->numBuys;
	int discardCntBefore = post->discardCount[player];

	int othersHandCnt[post->numPlayers];
	for (int i = 0; i < post->numPlayers; i++) {
		if (i != player) {
			othersHandCnt[i] = post->handCount[i];
		}
	}

	// execute card effect
	cardEffect(council_room, 0, 0, 0, post, 0, &b);

	int handCntAfter = post->handCount[player];
	int numBuysAfter = post->numBuys;
	int discardCntAfter = post->discardCount[player];

	int othersHandCntAfter[post->numPlayers];
	for (int i = 0; i < post->numPlayers; i++) {
		if (i != player) {
			othersHandCntAfter[i] = post->handCount[i];
		}
	}

	myAssert(handCntBefore + 3, handCntAfter, "Council Room Player added 4 cards to players hand and Discards 1 from hand", 1);
	myAssert(numBuysBefore + 1, numBuysAfter, "Council Room Player added +1 Buy", 1);
	for (int i = 0; i < post->numPlayers; i++) {
		if (i != player) {
			myAssert(othersHandCnt[i] + 1, othersHandCntAfter[i], "Council Room Other Player added 1 card to hand", 1);
		}
	}
}

void CouncilRoomRandomTester()
{
	fprintf(stderr, "BEGIN COUNCIL ROOM RANDOM TESTER %d ITERATIONS\n", NUMTESTS);
	struct gameState G;
	srand(time(NULL));
	int seed = 1;
	int k[10] = {adventurer, embargo, village, minion, mine, cutpurse,
			 sea_hag, tribute, smithy, council_room};
	initializeGame(myRandom(1, MAX_PLAYERS), k, seed, &G);
	for (int i = 0; i < NUMTESTS; i++ ) {
		G.numPlayers = myRandom(1, MAX_PLAYERS);
		G.whoseTurn = myRandom(0, MAX_PLAYERS - 1);
		G.numBuys = myRandom(0, 100);
		for (int j = 0; j < G.numPlayers; j++) {
			G.handCount[j] = myRandom(10, MAX_HAND / 2);
			G.deckCount[j] = myRandom(10, MAX_DECK /2 );
			G.discardCount[j] = myRandom(10, MAX_DECK / 2);
		}
		councilRoomOracle(&G);
	}

	fprintf(stderr, "END COUNCIL ROOM RANDOM TESTER %d ITERATIONS\n", NUMTESTS);
}

int
main()
{
	CouncilRoomRandomTester();
	return 0;
}
