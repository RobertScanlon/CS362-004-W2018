SHELL := /bin/bash

CFLAGS = -Wall -fpic -coverage -lm -std=c99

rngs.o: rngs.h rngs.c
	gcc -c rngs.c -g  $(CFLAGS)

myAssert.o: myAssert.h myAssert.c
	gcc -c myAssert.c -g $(CFLAGS)

dominion.o: dominion.h dominion.c rngs.o
	gcc -c dominion.c -g  $(CFLAGS)

playdom: dominion.o playdom.c
	gcc -o playdom playdom.c -g dominion.o rngs.o $(CFLAGS)
#To run playdom you need to entere: ./playdom <any integer number> like ./playdom 10*/
testDrawCard: testDrawCard.c dominion.o rngs.o
	gcc  -o testDrawCard -g  testDrawCard.c dominion.o rngs.o $(CFLAGS)

badTestDrawCard: badTestDrawCard.c dominion.o rngs.o
	gcc -o badTestDrawCard -g  badTestDrawCard.c dominion.o rngs.o $(CFLAGS)

testBuyCard: testDrawCard.c dominion.o rngs.o
	gcc -o testDrawCard -g  testDrawCard.c dominion.o rngs.o $(CFLAGS)

testAll: dominion.o testSuite.c
	gcc -o testSuite testSuite.c -g  dominion.o rngs.o $(CFLAGS)

interface.o: interface.h interface.c
	gcc -c interface.c -g  $(CFLAGS)

runtests: testDrawCard
	./testDrawCard &> unittestresult.out
	gcov dominion.c >> unittestresult.out
	cat dominion.c.gcov >> unittestresult.out

player: player.c interface.o
	gcc -o player player.c -g  dominion.o rngs.o interface.o $(CFLAGS)

randomtestadventurer.out: dominion.o myAssert.o randomtestadventurer.out
	rm -f *.gcov *.gcda *.gcno
	gcc -c dominion.c -g $(CFLAGS)
	gcc -o randomtestadventurer randomtestadventurer.c -g dominion.o rngs.o myAssert.o $(CFLAGS) -O0
	./randomtestadventurer > randomtestadventurer.out 2>&1
	echo -e "\nBEGIN COVERAGE RESULTS\n" >> randomtestadventurer.out 2>&1
	gcov -bfu dominion.c >> randomtestadventurer.out 2>&1
	cat dominion.c.gcov >> randomtestadventurer.out 2>&1
	echo -e "\nEND COVERAGE RESULTS\n" >> randomtestadventurer.out 2>&1

randomtestcard1.out: dominion.o myAssert.o randomtestcard1.out
	rm -f *.gcov *.gcda *.gcno
	gcc -c dominion.c -g $(CFLAGS)
	gcc -o randomtestcard1 randomtestcard1.c -g dominion.o rngs.o myAssert.o $(CFLAGS) -O0
	./randomtestcard1 > randomtestcard1.out 2>&1
	echo -e "\nBEGIN COVERAGE RESULTS\n" >> randomtestcard1.out 2>&1
	gcov -bfu dominion.c >> randomtestcard1.out 2>&1
	cat dominion.c.gcov >> randomtestcard1.out 2>&1
	echo -e "\nEND COVERAGE RESULTS\n" >> randomtestcard1.out 2>&1

randomtestcard2.out: dominion.o myAssert.o randomtestcard2.out
	rm -f *.gcov *.gcda *.gcno
	gcc -c dominion.c -g $(CFLAGS)
	gcc -o randomtestcard2 randomtestcard2.c -g dominion.o rngs.o myAssert.o $(CFLAGS) -O0
	./randomtestcard2 > randomtestcard2.out 2>&1
	echo -e "\nBEGIN COVERAGE RESULTS\n" >> randomtestcard2.out 2>&1
	gcov -bfu dominion.c >> randomtestcard2.out 2>&1
	cat dominion.c.gcov >> randomtestcard2.out 2>&1
	echo -e "\nEND COVERAGE RESULTS\n" >> randomtestcard2.out 2>&1

unittest1results.out: dominion.o myAssert.o unittest1results.out
	rm -f *.gcov *.gcda *.gcno
	gcc -c dominion.c -g  $(CFLAGS)
	gcc -o unitTest1 unittest1.c -g dominion.o rngs.o myAssert.o -g $(CFLAGS)
	./unitTest1 >> unittest1results.out 2>&1
	echo -e  "BEGIN COVERAGE RESULTS\n" >> unittest1results.out 2>&1
	gcov -bfu dominion.c >> unittest1results.out 2>&1
	echo -e  "END COVERAGE RESULTS\n" >> unittest1results.out 2>&1

unittest2results.out: dominion.o myAssert.o unittest2results.out
	rm -f *.gcov *.gcda *.gcno
	gcc -c dominion.c -g  $(CFLAGS)
	gcc -o unitTest2 unittest2.c -g dominion.o rngs.o myAssert.o -g $(CFLAGS)
	./unitTest2 >> unittest2results.out 2>&1
	echo -e  "BEGIN COVERAGE RESULTS\n" >> unittest2results.out 2>&1
	gcov -bfu dominion.c >> unittest2results.out 2>&1
	echo -e  "END COVERAGE RESULTS\n" >> unittest2results.out 2>&1

unittest3results.out: dominion.o myAssert.o unittest3results.out
	rm -f *.gcov *.gcda *.gcno
	gcc -c dominion.c -g  $(CFLAGS)
	gcc -o unitTest3 unittest3.c -g dominion.o rngs.o myAssert.o -g $(CFLAGS)
	./unitTest3 >> unittest3results.out 2>&1
	echo -e  "BEGIN COVERAGE RESULTS\n" >> unittest3results.out 2>&1
	gcov -bfu dominion.c >> unittest3results.out 2>&1
	echo -e  "END COVERAGE RESULTS\n" >> unittest3results.out 2>&1

unittest4results.out: dominion.o myAssert.o unittest4results.out
	rm -f *.gcov *.gcda *.gcno
	gcc -c dominion.c -g  $(CFLAGS)
	gcc -o unitTest4 unittest4.c -g dominion.o rngs.o myAssert.o -g $(CFLAGS)
	./unitTest4 >> unittest4results.out 2>&1
	echo -e  "BEGIN COVERAGE RESULTS\n" >> unittest4results.out 2>&1
	gcov -bfu dominion.c >> unittest4results.out 2>&1
	echo -e  "END COVERAGE RESULTS\n" >> unittest4results.out 2>&1

cardtest1results.out: dominion.o myAssert.o cardtest1results.out
	rm -f *.gcov *.gcda *.gcno
	gcc -c dominion.c -g  $(CFLAGS)
	gcc -o cardtest1 cardtest1.c -g dominion.o rngs.o myAssert.o -g $(CFLAGS)
	./cardtest1 >> cardtest1results.out 2>&1
	echo -e  "BEGIN COVERAGE RESULTS\n" >> cardtest1results.out 2>&1
	gcov -bfu dominion.c >> cardtest1results.out 2>&1
	echo -e  "END COVERAGE RESULTS\n" >> cardtest1results.out 2>&1

cardtest2results.out: dominion.o myAssert.o cardtest2results.out
	rm -f *.gcov *.gcda *.gcno
	gcc -c dominion.c -g  $(CFLAGS)
	gcc -o cardtest2 cardtest2.c -g dominion.o rngs.o myAssert.o -g $(CFLAGS)
	./cardtest2 >> cardtest2results.out 2>&1
	echo -e  "BEGIN COVERAGE RESULTS\n" >> cardtest2results.out 2>&1
	gcov -bfu dominion.c >> cardtest2results.out 2>&1
	echo -e  "END COVERAGE RESULTS\n" >> cardtest2results.out 2>&1

cardtest3results.out: dominion.o myAssert.o cardtest3results.out
	rm -f *.gcov *.gcda *.gcno
	gcc -c dominion.c -g  $(CFLAGS)
	gcc -o cardtest3 cardtest3.c -g dominion.o rngs.o myAssert.o -g $(CFLAGS)
	./cardtest3 >> cardtest3results.out 2>&1
	echo -e  "BEGIN COVERAGE RESULTS\n" >> cardtest3results.out 2>&1
	gcov -bfu dominion.c >> cardtest3results.out 2>&1
	cat dominion.c.gcov >> cardtest3results.out 2>&1
	echo -e  "END COVERAGE RESULTS\n" >> cardtest3results.out 2>&1

cardtest4results.out: dominion.o myAssert.o cardtest4results.out
	rm -f *.gcov *.gcda *.gcno
	gcc -c dominion.c -g  $(CFLAGS)
	gcc -o cardtest4 cardtest4.c -g dominion.o rngs.o myAssert.o -g $(CFLAGS)
	./cardtest4 >> cardtest4results.out 2>&1
	echo -e  "BEGIN COVERAGE RESULTS\n" >> cardtest4results.out 2>&1
	gcov -bfu dominion.c >> cardtest4results.out 2>&1
	cat dominion.c.gcov >> cardtest4results.out 2>&1
	echo -e  "END COVERAGE RESULTS\n" >> cardtest4results.out 2>&1

a5tests: cardtest4results.out cardtest3results.out cardtest2results.out cardtest1results.out unittest4results.out unittest3results.out unittest2results.out unittest1results.out randomtestcard2.out randomtestcard1.out randomtestadventurer.out

all: playdom player testDrawCard testBuyCard badTestDrawCard

clean:
	rm -f *.o playdom.exe playdom player player.exe  *.gcov *.gcda *.gcno *.so *.out testDrawCard testDrawCard.exe badTestDrawCard
	rm -rf *.dSYM
	rm -f unitTest*
	rm -f cardTest*
	rm -f randomtestadventurer randomtestcard1 randomtestcard2 cardtest4 cardtest3 cardtest2 cardtest1 unittest4 unitTest4 unitTest3 unitTest2 unitTest1
	rm -f *.tmp
