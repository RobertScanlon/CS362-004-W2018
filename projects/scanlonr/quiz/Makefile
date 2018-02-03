build: testme.c
	gcc -o testme testme.c -g -Wall -O0 -fprofile-arcs -ftest-coverage

run: testme
	./testme

coverage:

clean:
	rm -f testme
	rm -f *.DS_Store
	rm -f .dSYM
	rm -f *.gcda
	rm -f *.gcno
