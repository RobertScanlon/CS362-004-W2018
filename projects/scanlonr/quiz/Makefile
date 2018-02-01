build: testme.c
	gcc -o prog testme.c -fprofile-arcs -ftest-coverage -O0 -g

buildmac: testme.c
	gcc-7 -o prog testme.c -fprofile-arcs -ftest-coverage -O0

run: prog
	./prog

test: prog
	./gcov -b testme.c > results.out

clean:
	rm -f prog
	rm -f *.out
	rm -f *.gcov
	rm -f *.gcda
	rm -f *.gcno
	rm -f *.dSYM
	rm -f *.DS_Store
