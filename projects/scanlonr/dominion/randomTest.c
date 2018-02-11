#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include "myAssert.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

#define N 100000

int
main()
{
    SelectStream(0);
    PutSeed(-1);
    int n;
    for (int i = 0; i < N; i++) {
        n = Random();
        n = Random();
        n = Random();
        n = Random();
        n = Random();
        n = Random();
        n = Random();
        n = Random();
        n = Random();
    }
    return 0;
}
