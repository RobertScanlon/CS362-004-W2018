CFLAGS = -Wall -fpic -coverage -lm

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

unittestresults.out: dominion.o myAssert.o
	gcc -o unitTest1 unittest1.c -g dominion.o rngs.o myAssert.o -g $(CFLAGS)
	gcc -o unitTest2 unittest2.c -g dominion.o rngs.o myAssert.o -g $(CFLAGS)
	gcc -o unitTest3 unittest3.c -g dominion.o rngs.o myAssert.o -g $(CFLAGS)
	gcc -o unitTest4 unittest4.c -g dominion.o rngs.o myAssert.o -g $(CFLAGS)
	gcc -o cardTest1 cardTest1.c -g dominion.o rngs.o myAssert.o -g $(CFLAGS)
	gcc -o cardTest2 cardTest2.c -g dominion.o rngs.o myAssert.o -g $(CFLAGS)
	gcc -o cardTest3 cardTest3.c -g dominion.o rngs.o myAssert.o -g $(CFLAGS)
	gcc -o cardTest4 cardTest4.c -g dominion.o rngs.o myAssert.o -g $(CFLAGS)
	echo "******* BEGIN UNITTEST1 *******" > unittestresults.out 2>&1
	./unitTest1 >> unittestresults.out 2>&1
	echo "******* END UNITTEST1 *******\n" >> unittestresults.out 2>&1
	echo "******* BEGIN UNITTEST2 *******" >> unittestresults.out 2>&1
	./unitTest2 >> unittestresults.out 2>&1
	echo "******* END UNITTEST2 *******\n" >> unittestresults.out 2>&1
	echo "******* BEGIN UNITTEST3 *******" >> unittestresults.out 2>&1
	./unitTest3 >> unittestresults.out 2>&1
	echo "******* END UNITTEST3 *******\n" >> unittestresults.out 2>&1
	echo "******* BEGIN UNITTEST4 *******" >> unittestresults.out 2>&1
	./unitTest4 >> unittestresults.out 2>&1
	echo "******* END UNITTEST4 *******\n" >> unittestresults.out 2>&1
	echo "******* BEGIN CARDTEST1 *******" >> unittestresults.out 2>&1
	./cardTest1 >> unittestresults.out 2>&1
	echo "******* END CARDTEST1 *******\n" >> unittestresults.out 2>&1
	echo "******* BEGIN CARDTEST2 *******" >> unittestresults.out 2>&1
	./cardTest2 >> unittestresults.out 2>&1
	echo "******* END CARDTEST2 *******\n" >> unittestresults.out 2>&1
	echo "******* BEGIN CARDTEST3 *******" >> unittestresults.out 2>&1
	./cardTest3 >> unittestresults.out 2>&1
	echo "******* END CARDTEST3 *******\n" >> unittestresults.out 2>&1
	echo "******* BEGIN CARDTEST4 *******" >> unittestresults.out 2>&1
	./cardTest4 >> unittestresults.out 2>&1
	echo "******* END CARDTEST4 *******" >> unittestresults.out 2>&1

all: playdom player testDrawCard testBuyCard badTestDrawCard

clean:
	rm -f *.o playdom.exe playdom player player.exe  *.gcov *.gcda *.gcno *.so *.out testDrawCard testDrawCard.exe badTestDrawCard
	rm -rf *.dSYM
	rm -f unitTest*
	rm -f cardTest*
