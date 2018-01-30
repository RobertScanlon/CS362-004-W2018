#include "myAssert.h"

void myAssert(int x, int y, char *message)
{
	if (x == y) {
		fprintf(stderr, "Test %s passed: %d = %d\n", message, x, y);
	} else {
		fprintf(stderr, "Test %s failed: %d != %d\n", message, x, y);
	}
}
