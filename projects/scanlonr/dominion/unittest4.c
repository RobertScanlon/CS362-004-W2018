/*
 * unit test 4
 */
#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include "myAssert.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <limits.h>

void testCompare()
{
	int zero = 0;
	int neg1 = -1;
	int one = 1;
	int two = 2;
	int min = INT_MIN;
	int max = INT_MAX;

	// -1, -1 => 0
	myAssert(compare((void*)&neg1, (void*)&neg1), 0, "-1 = -1 returns 0");

	// 0, 0 => 0
	myAssert(compare((void*)&zero, (void*)&zero), 0, "0 = 0 returns 0");

	// 1, 1 => 0
	myAssert(compare((void*)&one, (void*)&one), 0, "1 = 1 returns 0");

	// -1, 0 => -1
	myAssert(compare((void*)&neg1, (void*)&zero), -1, "-1 < 0 returns -1");

	// 0, 1 => -1
	myAssert(compare((void*)&zero, (void*)&one), -1, "0 < 1 returns -1");

	// 1, 2 => -1
	myAssert(compare((void*)&one, (void*)&two), -1, "1 < 2 returns -1");

	// 0, -1 => 1
	myAssert(compare((void*)&zero, (void*)&neg1), 1, "0 > -1 returns 1");

	// 1, 0 => 1
	myAssert(compare((void*)&one, (void*)&zero), 1, "1 > 0 returns 1");

	// 2, 1 => 1
	myAssert(compare((void*)&two, (void*)&one), 1, "2 > 1 returns 1");

	// INT_MIN, INT_MAX => -1
	myAssert(compare((void*)&min, (void*)&max), -1, "INT_MIN < INT_MAX returns -1");

	// INT_MAX, INT_MIN => 1
	myAssert(compare((void*)&max, (void*)&min), 1, "INT_MAX > INT_MIN returns 1");

	// INT_MIN, INT_MIN => 0
	myAssert(compare((void*)&min, (void*)&min), 0, "INT_MIN = INT_MIN returns 0");

	// INT_MAX, INT_MAX => 0
	myAssert(compare((void*)&max, (void*)&max), 0, "INT_MAX = INT_MAX returns 0");
}

int
main()
{
	testCompare();
	return 0;
}
