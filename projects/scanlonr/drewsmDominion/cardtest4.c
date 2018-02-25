/*
 * card test 4
 */
#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include "myAssert.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void testCouncilRoom()
{
	int card = council_room;
	int numPlayers = 2;
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

	// test with 2 players
	initializeGame(numPlayers, k, seed, &refG);
	memcpy(&testG, &refG, sizeof(struct gameState));
	testG.hand[player][testG.handCount[player] - 1] = council_room;
	refG.hand[player][refG.handCount[player] - 1] = council_room;
	handPos = refG.handCount[player] - 1;

	retValue = cardEffect(card, choice1, choice2, choice3, &testG, handPos, &bonus);
	myAssert(retValue, 0, "council_room implementation returns 0");
	myAssert(testG.handCount[player], refG.handCount[player] + 3, "Playing council_room increases players hand count by 3 (accounting for discard of council_room)");
	myAssert(testG.numBuys, refG.numBuys + 1, "Playing council_room increased numBuys by +1");
	for (int i = 1; i < numPlayers; i++) {
		myAssert(testG.handCount[i], refG.handCount[i] + 1, "Other players hand count increased by 1");
	}

	// test with MAX players
	numPlayers = MAX_PLAYERS;
	initializeGame(numPlayers, k, seed, &refG);
	memcpy(&testG, &refG, sizeof(struct gameState));
	testG.hand[player][testG.handCount[player] - 1] = council_room;
	refG.hand[player][refG.handCount[player] - 1] = council_room;
	handPos = refG.handCount[player] - 1;

	retValue = cardEffect(card, choice1, choice2, choice3, &testG, handPos, &bonus);
	myAssert(retValue, 0, "council_room implementation returns 0");
	myAssert(testG.handCount[player], refG.handCount[player] + 3, "Playing council_room increases players hand count by 3 (accounting for discard of council_room)");
	myAssert(testG.numBuys, refG.numBuys + 1, "Playing council_room increased numBuys by +1");
	for (int i = 1; i < numPlayers; i++) {
		myAssert(testG.handCount[i], refG.handCount[i] + 1, "Other players hand count increased by 1");
	}
}

int
main()
{
	testCouncilRoom();
	return 0;
}
