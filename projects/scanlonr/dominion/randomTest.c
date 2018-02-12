#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include "myAssert.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <math.h>

#define N 100

int myRandom(int min, int max) {
    return (rand() % (max - min + 1)) + min;
}

int
main()
{
    srand(time(NULL));
    int n;
    for (int i = 0; i < N; i++) {
        n = myRandom(0, treasure_map);
        fprintf(stderr, "%d\n", n);
    }
    return 0;
}
