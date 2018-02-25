#include "myAssert.h"

int myAssert(int x, int y, char *message, int quietFail)
{
	if (!quietFail) {

		if (x == y) {
			fprintf(stderr, "%s\n", message);
			fprintf(stderr, "TEST PASSED");
			fprintf(stderr, " : %d = %d\n", x, y);
            return 0;
		} else {
			fprintf(stderr, "%s\n", message);
			fprintf(stderr, "TEST FAILED");
			fprintf(stderr, " : %d != %d\n", x, y);
            return -1;
		}
	} else {
		if (x != y) {
			fprintf(stderr, "TEST FAILED: %d!=%d: %s\n", x, y, message);
            return -1;
		}
        return 0;
	}
}
