/*
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

#define NUMTESTS 100000

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

int StewardRoomOracle(struct gameState *post, int choice1, int handPos)
{
	int b = 0;
	int retValue = cardEffect(steward, choice1, 0, 0, post, handPos, &b);
    return 0;
}

void StewardRoomRandomTester()
{
	fprintf(stderr, "BEGIN STEWARD RANDOM TESTER %d ITERATIONS\n", NUMTESTS);
	struct gameState *G = malloc(sizeof(struct gameState));
	srand(time(NULL));
	int seed = 1;
	int itr = 0;
	int choice1;
	int handPos;
	int p = 0;
	int k[10] = {adventurer, embargo, village, minion, mine, cutpurse,
			 sea_hag, tribute, smithy, council_room};
	for (int i = 0; i < NUMTESTS; i++ ) {
		struct gameState *G = malloc(sizeof(struct gameState));
		itr++;
		initializeGame(2, k, 2, G);

		G->handCount[p] = myRandom(1, MAX_HAND - 2);
		G->deckCount[p] = myRandom(0, MAX_DECK);
		G->discardCount[p] = myRandom(0, MAX_DECK - 1);
		handPos = myRandom(0, G->handCount[p] - 1);
		G->hand[p][handPos] = steward;
		choice1 = myRandom(0, 3);

		StewardRoomOracle(G, choice1, handPos);
		free(G);
	}

	fprintf(stderr, "END STEWARD RANDOM TESTER %d ITERATIONS\n", itr);
    if (itr == NUMTESTS) {
        fprintf(stderr, "NO ALL TESTS PASSED\n");
    }
}

int
main()
{
	StewardRoomRandomTester();
	return 0;
}
