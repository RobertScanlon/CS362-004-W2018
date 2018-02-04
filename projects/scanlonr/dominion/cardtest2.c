/*
 * card test 2 (adventurer)
 */
#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include "myAssert.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void testAdventurer()
{
	int card = adventurer;
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

	int testcoppers;
	int refcoppers;
	int testsilvers;
	int refsilvers;
	int testgolds;
	int refgolds;

	// test for when player has empty deck
	// and discard contains 2 copper
	testG.deckCount[player] = 0;
	refG.deckCount[player] = 0;

	testG.discard[player][0] = copper;
	testG.discard[player][1] = copper;
	testG.discardCount[player] = 2;
	refG.discard[player][0] = copper;
	refG.discard[player][1] = copper;
	refG.discardCount[player] = 2;

	testG.hand[player][testG.handCount[player] - 1] = adventurer;
	handPos = testG.handCount[player] - 1;
	refG.hand[player][refG.handCount[player] - 1] = adventurer;

	retValue = cardEffect(adventurer, choice1, choice2, choice3, &testG, handPos, &bonus);

	// assert correct return value
	myAssert(retValue, 0, "Play adventurer returns 0");

	// assert that num coppers in hand increase by 2
	refcoppers = 0;
	for (int i = 0; i < refG.handCount[player]; i++) {
		if (refG.hand[player][i] == copper) {
			refcoppers++;
		}
	}
	testcoppers = 0;
	for (int i = 0; i < testG.handCount[player]; i++) {
		if (testG.hand[player][i] == copper) {
			testcoppers++;
		}
	}
	myAssert(testcoppers, refcoppers + 2, "Playing adventurer inceases num coppers in hand by 2, when only 2 coppers in discard");
	myAssert(testG.handCount[player], refG.handCount[player] + 2, "Hand count increases by 2 when discard contains only treasure cards");

	// test for when player has empty deck
	// and discard contains 2 silver
	initializeGame(2, k, seed, &refG);
	memcpy(&testG, &refG, sizeof(struct gameState));
	testG.deckCount[player] = 0;
	refG.deckCount[player] = 0;

	testG.discard[player][0] = silver;
	testG.discard[player][1] = silver;
	testG.discardCount[player] = 2;
	refG.discard[player][0] = silver;
	refG.discard[player][1] = silver;
	refG.discardCount[player] = 2;

	testG.hand[player][testG.handCount[player] - 1] = adventurer;
	handPos = testG.handCount[player] - 1;
	refG.hand[player][refG.handCount[player] - 1] = adventurer;

	retValue = cardEffect(adventurer, choice1, choice2, choice3, &testG, handPos, &bonus);

	// assert correct return value
	myAssert(retValue, 0, "Play adventurer returns 0");

	// assert that num silvers in hand increase by 2
	refsilvers = 0;
	for (int i = 0; i < refG.handCount[player]; i++) {
		if (refG.hand[player][i] == silver) {
			refsilvers++;
		}
	}
	testsilvers = 0;
	for (int i = 0; i < testG.handCount[player]; i++) {
		if (testG.hand[player][i] == silver) {
			testsilvers++;
		}
	}
	myAssert(testsilvers, refsilvers + 2, "Playing adventurer inceases num silvers in hand by 2, when only 2 silvers in discard");
	myAssert(testG.handCount[player], refG.handCount[player] + 2, "Hand count increases by 2 when discard contains only treasure cards");

	// test for when player has empty deck
	// and discard contains 2 gold
	initializeGame(2, k, seed, &refG);
	memcpy(&testG, &refG, sizeof(struct gameState));
	testG.deckCount[player] = 0;
	refG.deckCount[player] = 0;

	testG.discard[player][0] = gold;
	testG.discard[player][1] = gold;
	testG.discardCount[player] = 2;
	refG.discard[player][0] = gold;
	refG.discard[player][1] = gold;
	refG.discardCount[player] = 2;

	testG.hand[player][testG.handCount[player] - 1] = adventurer;
	handPos = testG.handCount[player] - 1;
	refG.hand[player][refG.handCount[player] - 1] = adventurer;

	retValue = cardEffect(adventurer, choice1, choice2, choice3, &testG, handPos, &bonus);

	// assert correct return value
	myAssert(retValue, 0, "Play adventurer returns 0");

	// assert that num golds in hand increase by 2
	refgolds = 0;
	for (int i = 0; i < refG.handCount[player]; i++) {
		if (refG.hand[player][i] == gold) {
			refgolds++;
		}
	}
	testgolds = 0;
	for (int i = 0; i < testG.handCount[player]; i++) {
		if (testG.hand[player][i] == gold) {
			testgolds++;
		}
	}
	myAssert(testgolds, refgolds + 2, "Playing adventurer inceases num golds in hand by 2, when only 2 golds in discard");
	myAssert(testG.handCount[player], refG.handCount[player] + 2, "Hand count increases by 2 when discard contains only treasure cards");

	// test when player deck has copper, siler, gold
	initializeGame(2, k, seed, &refG);
	memcpy(&testG, &refG, sizeof(struct gameState));
	testG.deckCount[player] = 3;
	refG.deckCount[player] = 3;

	testG.deck[player][0] = gold;
	testG.deck[player][1] = silver;
	testG.deck[player][2] = copper;
	refG.deck[player][0] = gold;
	refG.deck[player][1] = silver;
	refG.deck[player][2] = copper;

	testG.hand[player][testG.handCount[player] - 1] = adventurer;
	handPos = testG.handCount[player] - 1;
	refG.hand[player][refG.handCount[player] - 1] = adventurer;

	retValue = cardEffect(adventurer, choice1, choice2, choice3, &testG, handPos, &bonus);

	// assert correct return value
	myAssert(retValue, 0, "Play adventurer returns 0");

	// assert that num golds in hand increase by 0
	refgolds = 0;
	for (int i = 0; i < refG.handCount[player]; i++) {
		if (refG.hand[player][i] == gold) {
			refgolds++;
		}
	}
	testgolds = 0;
	for (int i = 0; i < testG.handCount[player]; i++) {
		if (testG.hand[player][i] == gold) {
			testgolds++;
		}
	}
	// assert that num silver in hand increase by 1
	refsilvers = 0;
	for (int i = 0; i < refG.handCount[player]; i++) {
		if (refG.hand[player][i] == silver) {
			refsilvers++;
		}
	}
	testsilvers = 0;
	for (int i = 0; i < testG.handCount[player]; i++) {
		if (testG.hand[player][i] == silver) {
			testsilvers++;
		}
	}
	// assert that num copper in hand increase by 1
	refcoppers = 0;
	for (int i = 0; i < refG.handCount[player]; i++) {
		if (refG.hand[player][i] == copper) {
			refcoppers++;
		}
	}
	testcoppers = 0;
	for (int i = 0; i < testG.handCount[player]; i++) {
		if (testG.hand[player][i] == copper) {
			testcoppers++;
		}
	}
	myAssert(testgolds, refgolds, "Playing adventurer inceases num golds in hand by 0, when discard = [gold, silver, copper]");
	myAssert(testsilvers, refsilvers + 1, "Playing adventurer inceases num silver in hand by 1, when discard = [gold, silver, copper]");
	myAssert(testcoppers, refcoppers + 1, "Playing adventurer inceases num copper in hand by 1, when discard = [gold, silver, copper]");
	myAssert(testG.handCount[player], refG.handCount[player] + 2, "Hand count increases by 2 when discard contains only treasure cards");

	// test when player deck has smithy, copper, siler, gold
	initializeGame(2, k, seed, &refG);
	memcpy(&testG, &refG, sizeof(struct gameState));
	testG.deckCount[player] = 4;
	refG.deckCount[player] = 4;

	testG.deck[player][0] = gold;
	testG.deck[player][1] = silver;
	testG.deck[player][2] = copper;
	testG.deck[player][3] = smithy;
	refG.deck[player][0] = gold;
	refG.deck[player][1] = silver;
	refG.deck[player][2] = copper;
	refG.deck[player][3] = smithy;

	testG.hand[player][testG.handCount[player] - 1] = adventurer;
	handPos = testG.handCount[player] - 1;
	refG.hand[player][refG.handCount[player] - 1] = adventurer;

	retValue = cardEffect(adventurer, choice1, choice2, choice3, &testG, handPos, &bonus);

	// assert correct return value
	myAssert(retValue, 0, "Play adventurer returns 0");

	// assert that num golds in hand increase by 0
	refgolds = 0;
	for (int i = 0; i < refG.handCount[player]; i++) {
		if (refG.hand[player][i] == gold) {
			refgolds++;
		}
	}
	testgolds = 0;
	for (int i = 0; i < testG.handCount[player]; i++) {
		if (testG.hand[player][i] == gold) {
			testgolds++;
		}
	}
	// assert that num silver in hand increase by 1
	refsilvers = 0;
	for (int i = 0; i < refG.handCount[player]; i++) {
		if (refG.hand[player][i] == silver) {
			refsilvers++;
		}
	}
	testsilvers = 0;
	for (int i = 0; i < testG.handCount[player]; i++) {
		if (testG.hand[player][i] == silver) {
			testsilvers++;
		}
	}
	// assert that num copper in hand increase by 1
	refcoppers = 0;
	for (int i = 0; i < refG.handCount[player]; i++) {
		if (refG.hand[player][i] == copper) {
			refcoppers++;
		}
	}
	testcoppers = 0;
	for (int i = 0; i < testG.handCount[player]; i++) {
		if (testG.hand[player][i] == copper) {
			testcoppers++;
		}
	}
	myAssert(testgolds, refgolds, "Playing adventurer inceases num golds in hand by 0, when discard = [gold, silver, copper, smithy]");
	myAssert(testsilvers, refsilvers + 1, "Playing adventurer inceases num silver in hand by 1, when discard = [gold, silver, copper, smithy]");
	myAssert(testcoppers, refcoppers + 1, "Playing adventurer inceases num copper in hand by 1, when discard = [gold, silver, copper, smithy]");
	myAssert(testG.handCount[player], refG.handCount[player] + 2, "Hand count increases by 2 when discard contains only treasure cards, smithy");
	// discard count should increase by one, bc a smithy was pulled from deck
	myAssert(testG.discardCount[player], refG.discardCount[player] + 1, "Discard count should increase by 1, as the drawn smithy should be discarded");
	int testSmithies = 0;
	int refSmithies = 0;
	for (int i = 0; i < refG.handCount[player]; i++) {
		if (refG.hand[player][i] == smithy) {
			refSmithies++;
		}
	}
	for (int i = 0; i < testG.handCount[player]; i++) {
		if (testG.hand[player][i] == smithy) {
			testSmithies++;
		}
	}
	myAssert(testSmithies, refSmithies, "Num of smithies in hand should remain unchanged");
}

int
main()
{
	testAdventurer();
	return 0;
}
