#include "myAssert.h"

void myAssert(int x, int y, char *message)
{
	if (x == y) {
		fprintf(stderr, "%s\n", message);
		fprintf(stderr, "TEST PASSED");
		fprintf(stderr, " : %d = %d\n", x, y);
	} else {
		fprintf(stderr, "%s\n", message);
		fprintf(stderr, "TEST FAILED");
		fprintf(stderr, " : %d != %d\n", x, y);
	}
}
