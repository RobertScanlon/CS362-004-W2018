/*
 * card test 1 (smithy)
 */
#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include "myAssert.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void testSmithy()
{
	// testing is done though cardEffect which is assumed to operate correctly
	// for testing smithy we are only concered with local variables
	// state, currentPlayer, handPos, i from cardEffect
	int card = smithy;
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

	initializeGame(2, k, seed, &refG);
	memcpy(&testG, &refG, sizeof(struct gameState));

	// set smithy as card in hand[handPos]
	testG.hand[player][testG.handCount[player] - 1] = smithy;
	handPos = testG.handCount[player] - 1;
	refG.hand[player][refG.handCount[player] - 1] = smithy;

	// set the to contain only 10 copper
	for (int i = 0; i < 10; i++) {
		testG.deck[player][i] = copper;
		refG.deck[player][i] = copper;
	}
	testG.deckCount[player] = 10;
	refG.deckCount[player] = 10;

	//retValue = cardEffect(card, choice1, choice3, choice3, &testG, handPos, &bonus);
	retValue = smithyEffect(&testG, handPos, testG.whoseTurn);

	// assert that cardEffect returns 0
	myAssert(retValue, 0, "playSmithy() returns 0 from cardEffect()", 0);

	// assert that hand has 2 more cards
	myAssert(testG.handCount[player], refG.handCount[player] + 2, "Playing smithy increased handCount by 2 (draw 3, discard smithy)", 0);

	// assert that new cards came from players deck
	int c = 1;
	for (int i = refG.handCount[player] - 1; i < testG.handCount[player]; i++) {
		if (testG.hand[player][i] != copper) {
			c = 0;
		}
	}
	myAssert(c, 1, "New Cards came from players deck", 0);

}

int
main()
{
	fprintf(stderr, "BEGIN CARDTEST1 Smithy\n");
	testSmithy();
	fprintf(stderr, "END CARDTEST1 Smithy\n");
	return 0;
}
