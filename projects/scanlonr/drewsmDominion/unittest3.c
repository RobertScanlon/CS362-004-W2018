/*
 * unit test 3 updateCoins()
 */
#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include "myAssert.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void testUpdateCoins()
{
	int player = 0;
	int bonus;
	struct gameState testG;
	struct gameState refG;
	int retValue = -5;
	int seed = 1;
	int k[10] = {adventurer, embargo, village, minion, mine, cutpurse,
			     sea_hag, tribute, smithy, council_room};

	// no cards in hand, no bonus
	bonus = 0;
	initializeGame(2, k, seed, &refG);
	memcpy(&testG, &refG, sizeof(struct gameState));
	refG.coins = 0;
	testG.coins = 0;

	refG.handCount[player] = 0;
	testG.handCount[player] = 0;

	retValue = updateCoins(player, &testG, bonus);
	myAssert(retValue, 0, "updateCoins returns 0", 0);
	myAssert(refG.coins, testG.coins, "Empty deck, no bonus: coin count unchanged", 0);

	// no cards in hand, 1 bonus
	bonus = 1;
	initializeGame(2, k, seed, &refG);
	memcpy(&testG, &refG, sizeof(struct gameState));
	refG.coins = 0;
	testG.coins = 0;

	refG.handCount[player] = 0;
	testG.handCount[player] = 0;

	retValue = updateCoins(player, &testG, bonus);
	myAssert(retValue, 0, "updateCoins returns 0", 0);
	myAssert(refG.coins + 1, testG.coins, "Empty deck, 1 bonus: coin count +1", 0);

	// 1 copper cards in hand, 0 bonus
	bonus = 0;
	initializeGame(2, k, seed, &refG);
	memcpy(&testG, &refG, sizeof(struct gameState));
	refG.coins = 0;
	testG.coins = 0;

	refG.handCount[player] = 1;
	refG.hand[player][0] = copper;
	testG.handCount[player] = 1;
	testG.hand[player][0] = copper;

	retValue = updateCoins(player, &testG, bonus);
	myAssert(retValue, 0, "updateCoins returns 0", 0);
	myAssert(refG.coins + 1, testG.coins, "1 copper deck, 0 bonus: coin count +1", 0);

	// 1 copper cards in hand, 1 bonus
	bonus = 1;
	initializeGame(2, k, seed, &refG);
	memcpy(&testG, &refG, sizeof(struct gameState));
	refG.coins = 0;
	testG.coins = 0;

	refG.handCount[player] = 1;
	refG.hand[player][0] = copper;
	testG.handCount[player] = 1;
	testG.hand[player][0] = copper;

	retValue = updateCoins(player, &testG, bonus);
	myAssert(retValue, 0, "updateCoins returns 0", 0);
	myAssert(refG.coins + 2, testG.coins, "1 copper deck, 1 bonus: coin count +2", 0);

	// 1 silver cards in hand, 0 bonus
	bonus = 0;
	initializeGame(2, k, seed, &refG);
	memcpy(&testG, &refG, sizeof(struct gameState));
	refG.coins = 0;
	testG.coins = 0;

	refG.handCount[player] = 1;
	refG.hand[player][0] = silver;
	testG.handCount[player] = 1;
	testG.hand[player][0] = silver;

	retValue = updateCoins(player, &testG, bonus);
	myAssert(retValue, 0, "updateCoins returns 0", 0);
	myAssert(refG.coins + 2, testG.coins, "1 silver deck, 0 bonus: coin count +2", 0);

	// 1 silver cards in hand, 1 bonus
	bonus = 1;
	initializeGame(2, k, seed, &refG);
	memcpy(&testG, &refG, sizeof(struct gameState));
	refG.coins = 0;
	testG.coins = 0;

	refG.handCount[player] = 1;
	refG.hand[player][0] = silver;
	testG.handCount[player] = 1;
	testG.hand[player][0] = silver;

	retValue = updateCoins(player, &testG, bonus);
	myAssert(retValue, 0, "updateCoins returns 0", 0);
	myAssert(refG.coins + 3, testG.coins, "1 silver deck, 1 bonus: coin count +3", 0);

	// 1 gold cards in hand, 0 bonus
	bonus = 0;
	initializeGame(2, k, seed, &refG);
	memcpy(&testG, &refG, sizeof(struct gameState));
	refG.coins = 0;
	testG.coins = 0;

	refG.handCount[player] = 1;
	refG.hand[player][0] = gold;
	testG.handCount[player] = 1;
	testG.hand[player][0] = gold;

	retValue = updateCoins(player, &testG, bonus);
	myAssert(retValue, 0, "updateCoins returns 0", 0);
	myAssert(refG.coins + 3, testG.coins, "1 gold deck, 0 bonus: coin count +3", 0);

	// 1 gold cards in hand, 1 bonus
	bonus = 1;
	initializeGame(2, k, seed, &refG);
	memcpy(&testG, &refG, sizeof(struct gameState));
	refG.coins = 0;
	testG.coins = 0;

	refG.handCount[player] = 1;
	refG.hand[player][0] = gold;
	testG.handCount[player] = 1;
	testG.hand[player][0] = gold;

	retValue = updateCoins(player, &testG, bonus);
	myAssert(retValue, 0, "updateCoins returns 0", 0);
	myAssert(refG.coins + 4, testG.coins, "1 gold deck, 1 bonus: coin count +4", 0);

	// 1 gold, silver, copper cards in hand, 0 bonus
	bonus = 0;
	initializeGame(2, k, seed, &refG);
	memcpy(&testG, &refG, sizeof(struct gameState));
	refG.coins = 0;
	testG.coins = 0;

	refG.handCount[player] = 3;
	refG.hand[player][0] = gold;
	refG.hand[player][1] = silver;
	refG.hand[player][2] = copper;
	testG.handCount[player] = 3;
	testG.hand[player][0] = gold;
	testG.hand[player][1] = silver;
	testG.hand[player][2] = copper;

	retValue = updateCoins(player, &testG, bonus);
	myAssert(retValue, 0, "updateCoins returns 0", 0);
	myAssert(refG.coins + 6, testG.coins, "1 gold, silver, copper in deck, 0 bonus: coin count +6", 0);

	// 1 gold, silver, copper cards in hand, 1 bonus
	bonus = 1;
	initializeGame(2, k, seed, &refG);
	memcpy(&testG, &refG, sizeof(struct gameState));
	refG.coins = 0;
	testG.coins = 0;

	refG.handCount[player] = 3;
	refG.hand[player][0] = gold;
	refG.hand[player][1] = silver;
	refG.hand[player][2] = copper;
	testG.handCount[player] = 3;
	testG.hand[player][0] = gold;
	testG.hand[player][1] = silver;
	testG.hand[player][2] = copper;

	retValue = updateCoins(player, &testG, bonus);
	myAssert(retValue, 0, "updateCoins returns 0", 0);
	myAssert(refG.coins + 7, testG.coins, "1 gold, silver, copper in deck, 1 bonus: coin count +7", 0);

	// 10 gold, silver, copper cards in hand, 0 bonus
	bonus = 0;
	initializeGame(2, k, seed, &refG);
	memcpy(&testG, &refG, sizeof(struct gameState));
	refG.coins = 0;
	testG.coins = 0;

	refG.handCount[player] = 30;
	testG.handCount[player] = 30;
	for (int i = 0; i < 30; i++) {
		if (i < 10) {
			refG.hand[player][i] = copper;
			testG.hand[player][i] = copper;
		} else if (i < 20) {
			refG.hand[player][i] = silver;
			testG.hand[player][i] = silver;
		} else {
			refG.hand[player][i] = gold;
			testG.hand[player][i] = gold;
		}
	}
	retValue = updateCoins(player, &testG, bonus);
	myAssert(retValue, 0, "updateCoins returns 0", 0);
	myAssert(refG.coins + 60, testG.coins, "10 gold, silver, copper in deck, 0 bonus: coin count +60", 0);

	// 10 gold, silver, copper cards in hand, 10 bonus
	bonus = 10;
	initializeGame(2, k, seed, &refG);
	memcpy(&testG, &refG, sizeof(struct gameState));
	refG.coins = 0;
	testG.coins = 0;

	refG.handCount[player] = 30;
	testG.handCount[player] = 30;
	for (int i = 0; i < 30; i++) {
		if (i < 10) {
			refG.hand[player][i] = copper;
			testG.hand[player][i] = copper;
		} else if (i < 20) {
			refG.hand[player][i] = silver;
			testG.hand[player][i] = silver;
		} else {
			refG.hand[player][i] = gold;
			testG.hand[player][i] = gold;
		}
	}
	retValue = updateCoins(player, &testG, bonus);
	myAssert(retValue, 0, "updateCoins returns 0", 0);
	myAssert(refG.coins + 70, testG.coins, "10 gold, silver, copper in deck, 10 bonus: coin count +70", 0);

}


int
main()
{
	fprintf(stderr, "BEGIN UNITTET 3 updateCoins()\n");
	testUpdateCoins();
	fprintf(stderr, "END UNITTET 3 updateCoins()\n");
	return 0;
}
