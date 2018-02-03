/*
 * unit test 1 shuffle()
 */
#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include "myAssert.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void testShuffle()
{
	int player = 0;
	struct gameState testG;
	struct gameState refG;
	int retValue = -5;
	int seed = 1;
	int k[10] = {adventurer, embargo, village, minion, mine, cutpurse,
			     sea_hag, tribute, smithy, council_room};

	// test an empty deck
	initializeGame(2, k, seed, &refG);
	memcpy(&testG, &refG, sizeof(struct gameState));

	// set the handcount to 0
	testG.deckCount[player] = 0;
	refG.deckCount[player] = 0;

	retValue = shuffle(player, &testG);

	// assert that deckCount did not change
	myAssert(testG.deckCount[player],
	         refG.deckCount[player],
		     "Shuffle with empty deck did not change deckCount");
	// assert that shuffle returned -1
	myAssert(retValue, -1, "Shuffle with empty deck returned -1");
}


int
main()
{
	testShuffle();
	return 0;
}
