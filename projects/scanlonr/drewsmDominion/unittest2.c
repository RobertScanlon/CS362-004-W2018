/*
 * unit test 2 fullDeckCount()
 */
#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include "myAssert.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void testFullDeckCount()
{
	int player = 0;
	int card = smithy;
	struct gameState testG;
	struct gameState refG;
	int retValue = -5;
	int seed = 1;
	int k[10] = {adventurer, embargo, village, minion, mine, cutpurse,
			     sea_hag, tribute, smithy, council_room};

	/////////////////////////////////////////////////////////////////////
	// test an empty deck hand and discard
	initializeGame(2, k, seed, &refG);
	memcpy(&testG, &refG, sizeof(struct gameState));

	// set all to 0
	testG.deckCount[player] = 0;
	refG.deckCount[player] = 0;
	testG.handCount[player] = 0;
	refG.handCount[player] = 0;
	testG.discardCount[player] = 0;
	refG.discardCount[player] = 0;

	retValue = fullDeckCount(player, card, &testG);

	myAssert(retValue, 0, "Empty Deck, Hand, Discard, returns 0 smithies", 0);

	/////////////////////////////////////////////////////////////////////
	// deck = 1
	// hand = 0
	// discard = 0
	initializeGame(2, k, seed, &refG);
	memcpy(&testG, &refG, sizeof(struct gameState));

	// just one smithy in deck
	testG.deckCount[player] = 1;
	testG.deck[player][0] = smithy;
	refG.deckCount[player] = 1;
	refG.deck[player][0] = smithy;
	testG.handCount[player] = 0;
	refG.handCount[player] = 0;
	testG.discardCount[player] = 0;
	refG.discardCount[player] = 0;

	retValue = fullDeckCount(player, card, &testG);

	myAssert(retValue, 1, "1 smithy in deck, returns 1 smithies", 0);

	/////////////////////////////////////////////////////////////////////
	// deck = 0
	// hand = 1
	// discard = 0
	initializeGame(2, k, seed, &refG);
	memcpy(&testG, &refG, sizeof(struct gameState));

	// just one smithy in hand
	testG.deckCount[player] = 0;
	testG.hand[player][0] = smithy;
	refG.deckCount[player] = 0;
	refG.hand[player][0] = smithy;
	testG.handCount[player] = 1;
	refG.handCount[player] = 1;
	testG.discardCount[player] = 0;
	refG.discardCount[player] = 0;

	retValue = fullDeckCount(player, card, &testG);

	myAssert(retValue, 1, "1 smithy in hand, returns 1 smithies", 0);

	/////////////////////////////////////////////////////////////////////
	// deck = 0
	// hand = 0
	// discard = 1
	initializeGame(2, k, seed, &refG);
	memcpy(&testG, &refG, sizeof(struct gameState));

	// just one smithy in hand
	testG.deckCount[player] = 0;
	testG.discard[player][0] = smithy;
	refG.deckCount[player] = 0;
	refG.discard[player][0] = smithy;
	testG.handCount[player] = 0;
	refG.handCount[player] = 0;
	testG.discardCount[player] = 1;
	refG.discardCount[player] = 1;

	retValue = fullDeckCount(player, card, &testG);

	myAssert(retValue, 1, "1 smithy in discard, returns 1 smithies", 0);

	/////////////////////////////////////////////////////////////////////
	// deck = 1
	// hand = 1
	// discard = 1
	initializeGame(2, k, seed, &refG);
	memcpy(&testG, &refG, sizeof(struct gameState));

	// just one smithy in hand
	testG.deckCount[player] = 1;
	testG.discard[player][0] = smithy;
	refG.deckCount[player] = 1;
	refG.discard[player][0] = smithy;
	testG.handCount[player] = 1;
	testG.hand[player][0] = smithy;
	refG.handCount[player] = 1;
	refG.hand[player][0] = smithy;
	testG.discardCount[player] = 1;
	refG.discardCount[player] = 1;
	testG.deck[player][0] = smithy;
	refG.deck[player][0] = smithy;

	retValue = fullDeckCount(player, card, &testG);

	myAssert(retValue, 3, "1 smithy in discard, deck, hand, returns 3 smithies", 0);

	/////////////////////////////////////////////////////////////////////
	// deck = MAX_DECK
	// hand = MAX_DECK
	// discard = MAX_DECK
	initializeGame(2, k, seed, &refG);
	memcpy(&testG, &refG, sizeof(struct gameState));

	for (int i = 0; i < MAX_DECK; i++) {
		testG.deck[player][i] = smithy;
		refG.deck[player][i] = smithy;
		testG.hand[player][i] = smithy;
		refG.hand[player][i] = smithy;
		testG.discard[player][i] = smithy;
		refG.discard[player][i] = smithy;
	}
	testG.deckCount[player] = MAX_DECK;
	testG.handCount[player] = MAX_DECK;
	testG.discardCount[player] = MAX_DECK;
	refG.deckCount[player] = MAX_DECK;
	refG.handCount[player] = MAX_DECK;
	refG.discardCount[player] = MAX_DECK;

	retValue = fullDeckCount(player, card, &testG);

	myAssert(retValue, (MAX_DECK * 3), "Total of 3x MAX_DECK smithies", 0);

	/////////////////////////////////////////////////////////////////////
	// deck = 5 smithy, 5 adventurer
	// hand = 5 smithy, 5 adventurer
	// discard = 5 smithy, 5 adventurer
	initializeGame(2, k, seed, &refG);

	for (int i = 0; i < 10; i++) {
		if (i < 5) {
			testG.deck[player][i] = smithy;
			testG.hand[player][i] = smithy;
			testG.discard[player][i] = smithy;
		} else {
			testG.deck[player][i] = adventurer;
			testG.hand[player][i] = adventurer;
			testG.discard[player][i] = adventurer;
		}
	}
	testG.deckCount[player] = 10;
	testG.handCount[player] = 10;
	testG.discardCount[player] = 10;

	retValue = fullDeckCount(player, card, &testG);

	myAssert(retValue, 15, "Total of 15 smithies", 0);
}

int
main()
{
	fprintf(stderr, "BEGIN UNITTEST 2 fullDeckCount()\n");
	testFullDeckCount();
	fprintf(stderr, "END UNITTEST 2 fullDeckCount()\n");
	return 0;
}
