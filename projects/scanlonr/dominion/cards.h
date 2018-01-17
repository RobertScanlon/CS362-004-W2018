#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

void playAdventurer(struct gameState *state, int currentPlayer, int drawntreasure, int cardDrawn, int z);
void playSmithy(struct gameState *state, int currentPlayer, int handPos);
void playGreatHall(struct gameState *state, int currentPlayer, int handPos);
void playFeast(struct gameState *state, int currentPlayer, int *temphand, int x, int choice1);
void playCouncilRoom(struct gameState *state, int currentPlayer);
