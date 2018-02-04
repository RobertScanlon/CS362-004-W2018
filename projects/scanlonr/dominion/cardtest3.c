/*
 * card test 3
 */
#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include "myAssert.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void testGreatHall()
{
	int card = great_hall;
	int choice1 = 0;
	int choice2 = 0;
	int choice3 = 0;
	int handPos = 0;
	int bonus = 0;
	int player = 0;
	struct gameState testG;
	struct gameState refG;
	int retValue = -5;
	int seed = 1;
	int k[10] = {adventurer, embargo, village, minion, mine, cutpurse,
				 sea_hag, tribute, smithy, council_room};

	// test when deck is empty, discard contains 1 copper
	initializeGame(2, k, seed, &refG);
	memcpy(&testG, &refG, sizeof(struct gameState));
	testG.hand[player][testG.handCount[player] - 1] = great_hall;
	handPos = testG.handCount[player] - 1;
	refG.hand[player][refG.handCount[player] - 1] = great_hall;

	testG.deckCount[player] = 0;
	refG.deckCount[player] = 0;
	testG.discard[player][0] = copper;
	refG.discard[player][0] = copper;
	testG.discardCount[player] = 1;
	refG.discardCount[player] = 1;

	retValue = cardEffect(card, choice1, choice2, choice3, &testG, handPos, &bonus);
	myAssert(retValue, 0, "GreatHall implementation returns 0");
	myAssert(testG.hand[player][testG.handCount[player] - 1], copper, "Player drawn a copper into hand");
	myAssert(testG.numActions, refG.numActions + 1, "Players action count increased by 1");
	myAssert(testG.handCount[player], refG.handCount[player], "Handcount remains unchanged as 1 card is drawn and GreatHall is discarded");

	// test when deck contains 1 copper
	initializeGame(2, k, seed, &refG);
	memcpy(&testG, &refG, sizeof(struct gameState));
	testG.hand[player][testG.handCount[player] - 1] = great_hall;
	handPos = testG.handCount[player] - 1;
	refG.hand[player][refG.handCount[player] - 1] = great_hall;

	testG.deckCount[player] = 1;
	refG.deckCount[player] = 1;
	testG.deck[player][0] = copper;
	refG.deck[player][0] = copper;
	testG.discardCount[player] = 0;
	refG.discardCount[player] = 0;

	retValue = cardEffect(card, choice1, choice2, choice3, &testG, handPos, &bonus);
	myAssert(retValue, 0, "GreatHall implementation returns 0");
	myAssert(testG.hand[player][testG.handCount[player] - 1], copper, "Player drawn a copper into hand");
	myAssert(testG.numActions, refG.numActions + 1, "Players action count increased by 1");
	myAssert(testG.handCount[player], refG.handCount[player], "Handcount remains unchanged as 1 card is drawn and GreatHall is discarded");
}

int
main()
{
	testGreatHall();
	return 0;
}
