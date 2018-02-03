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

	/////////////////////////////////////////////////////////////////////
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

	//////////////////////////////////////////////////////////////////////
	// test a deck with 1 card
	initializeGame(2, k, seed, &refG);
	memcpy(&testG, &refG, sizeof(struct gameState));

	// set the handcount to 1
	testG.deckCount[player] = 1;
	refG.deckCount[player] = 1;

	// set the 1 card to smithy
	testG.deck[player][0] = smithy;
	refG.deck[player][0] = smithy;

	retValue = shuffle(player, &testG);

	// assert that deckCount did not change
	myAssert(testG.deckCount[player],
			 refG.deckCount[player],
			 "Shuffle with 1 card (smithy) deck did not change deckCount");
	// assert that shuffle returned -1
	myAssert(retValue, 0, "Shuffle with 1 card (smithy) deck returned 0");

	//////////////////////////////////////////////////////////////////////
	// test a deck with MAX_DECK cards
	initializeGame(2, k, seed, &refG);
	memcpy(&testG, &refG, sizeof(struct gameState));

	// set the handcount to 1
	testG.deckCount[player] = MAX_DECK;
	refG.deckCount[player] = MAX_DECK;

	// set the  cards to smithy
	for (int i = 0; i < MAX_DECK; i++) {
		testG.deck[player][i] = smithy;
		refG.deck[player][i] = smithy;
	}

	retValue = shuffle(player, &testG);

	// assert that deckCount did not change
	myAssert(testG.deckCount[player],
			 refG.deckCount[player],
			 "Shuffle with MAX_DECK cards (smithy) deck did not change deckCount");
	// assert that shuffle returned 0
	myAssert(retValue, 0, "Shuffle with MAX_DECK cards (smithy) deck returned 0");

	////////////////////////////////////////////////////////////////////
	// test that shuffle changes card order
	initializeGame(2, k, seed, &refG);
	memcpy(&testG, &refG, sizeof(struct gameState));

	int sameOrder = 1;
	int testEstates, refEstates, testCoppers, refCoppers = 0;

	retValue = shuffle(player, &testG);

	// assert that shuffle returned 0
	myAssert(retValue, 0, "Shuffle starting deck returned 0");

	for (int i = 0; i < refG.deckCount[player]; i++) {
		if (refG.deck[player][i] != testG.deck[player][i]) {
			sameOrder = 0;
		}
		if (refG.deck[player][i] == 'estate') {
			refEstates++;
		}
		if (testG.deck[player][i] == 'estate') {
			testEstates++;
		}
		if (refG.deck[player][i] == 'copper') {
			refCoppers++;
		}
		if (testG.deck[player][i] == 'copper') {
			testCoppers++;
		}
	}

	// assert that card counts did not change
	myAssert(testCoppers, refCoppers, "Copper Card Count unchanged");
	myAssert(testEstates, refEstates, "Estate Card Count unchanged");

	// assert card order changed
	myAssert(sameOrder, 0, "Card order changed after shuffle");
}


int
main()
{
	testShuffle();
	return 0;
}
