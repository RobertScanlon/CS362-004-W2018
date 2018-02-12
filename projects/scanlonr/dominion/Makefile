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

randomtestadventurer.out: dominion.o myAssert.o
	rm -f *.gcov *.gcda *.gcno
	gcc -c dominion.c -g $(CFLAGS)
	gcc -o randomtestadventurer randomtestadventurer.c -g dominion.o rngs.o myAssert.o $(CFLAGS) -O0
	./randomtestadventurer > randomtestadventurer.out 2>&1
	gcov -bfu dominion.c >> randomtestadventurer.out 2>&1

randomtestcard1.out: dominion.o myAssert.o
	rm -f *.gcov *.gcda *.gcno
	gcc -c dominion.c -g $(CFLAGS)
	gcc -o randomtestcard1 randomtestcard1.c -g dominion.o rngs.o myAssert.o $(CFLAGS) -O0
	./randomtestcard1 > randomtestcard1.out 2>&1
	gcov -bfu dominion.c >> randomtestcard1.out 2>&1

unittestresults.out: dominion.o myAssert.o
	echo -e  "**********************************************************************" > unittestresults.out 2>&1
	echo -e  "******************* BEGIN UNITTEST1 shuffle() function ***************" >> unittestresults.out 2>&1
	rm -f *.gcov *.gcda *.gcno
	gcc -c dominion.c -g  $(CFLAGS)
	gcc -o unitTest1 unittest1.c -g dominion.o rngs.o myAssert.o -g $(CFLAGS)
	./unitTest1 >> unittestresults.out 2>&1
	echo -e  "******************* gcov results *****************" >> unittestresults.out 2>&1
	gcov -bfu dominion.c >> unittestresults.out 2>&1
	#gcov dominion.c >> unittestresults.out 2>&1
	echo -e  "******************* END UNITTEST1 shuffle() function *****************" >> unittestresults.out 2>&1
	echo -e  "**********************************************************************\n\n" >> unittestresults.out 2>&1
	echo -e  "**********************************************************************" >> unittestresults.out 2>&1
	echo -e  "******************* BEGIN UNITTEST2 fullDeckCount() function *********" >> unittestresults.out 2>&1
	rm -f *.gcov *.gcda *.gcno
	gcc -c dominion.c -g  $(CFLAGS)
	gcc -o unitTest2 unittest2.c -g dominion.o rngs.o myAssert.o -g $(CFLAGS)
	./unitTest2 >> unittestresults.out 2>&1
	echo -e  "******************* gcov results *****************" >> unittestresults.out 2>&1
	gcov -bfu dominion.c >> unittestresults.out 2>&1
	#gcov dominion.c >> unittestresults.out 2>&1
	echo -e  "******************* END UNITTEST2 fullDeckCount() function ***********" >> unittestresults.out 2>&1
	echo -e  "**********************************************************************\n\n" >> unittestresults.out 2>&1
	echo -e  "**********************************************************************" >> unittestresults.out 2>&1
	echo -e  "******************* BEGIN UNITTEST3 updateCoins() function ***********" >> unittestresults.out 2>&1
	rm -f *.gcov *.gcda *.gcno
	gcc -c dominion.c -g  $(CFLAGS)
	gcc -o unitTest3 unittest3.c -g dominion.o rngs.o myAssert.o -g $(CFLAGS)
	./unitTest3 >> unittestresults.out 2>&1
	echo -e  "******************* gcov results *****************" >> unittestresults.out 2>&1
	gcov -bfu dominion.c >> unittestresults.out 2>&1
	#gcov dominion.c >> unittestresults.out 2>&1
	echo -e  "******************* END UNITTEST3 updateCoins() function *************" >> unittestresults.out 2>&1
	echo -e  "**********************************************************************\n\n" >> unittestresults.out 2>&1
	echo -e  "**********************************************************************" >> unittestresults.out 2>&1
	echo -e  "******************* BEGIN UNITTEST4 compare() function ***************" >> unittestresults.out 2>&1
	rm -f *.gcov *.gcda *.gcno
	gcc -c dominion.c -g  $(CFLAGS)
	gcc -o unitTest4 unittest4.c -g dominion.o rngs.o myAssert.o -g $(CFLAGS)
	./unitTest4 >> unittestresults.out 2>&1
	echo -e  "******************* gcov results *****************" >> unittestresults.out 2>&1
	gcov -bfu dominion.c >> unittestresults.out 2>&1
	#gcov dominion.c >> unittestresults.out 2>&1
	echo -e  "******************* END UNITTEST4 compare() function *****************" >> unittestresults.out 2>&1
	echo -e  "**********************************************************************\n\n" >> unittestresults.out 2>&1
	echo -e  "**********************************************************************" >> unittestresults.out 2>&1
	echo -e  "******************* BEGIN CARDTEST1 smithy implementation ************" >> unittestresults.out 2>&1
	rm -f *.gcov *.gcda *.gcno
	gcc -c dominion.c -g  $(CFLAGS)
	gcc -o cardTest1 cardtest1.c -g dominion.o rngs.o myAssert.o -g $(CFLAGS)
	./cardTest1 >> unittestresults.out 2>&1
	echo -e  "******************* gcov results *****************" >> unittestresults.out 2>&1
	gcov -bfu dominion.c >> unittestresults.out 2>&1
	#gcov dominion.c >> unittestresults.out 2>&1
	echo -e  "******************* END CARDTEST1 smithy implementation **************" >> unittestresults.out 2>&1
	echo -e  "**********************************************************************\n\n" >> unittestresults.out 2>&1
	echo -e  "**********************************************************************" >> unittestresults.out 2>&1
	echo -e  "******************* BEGIN CARDTEST2 adventurer implementation ********" >> unittestresults.out 2>&1
	rm -f *.gcov *.gcda *.gcno
	gcc -c dominion.c -g  $(CFLAGS)
	gcc -o cardTest2 cardtest2.c -g dominion.o rngs.o myAssert.o -g $(CFLAGS)
	./cardTest2 >> unittestresults.out 2>&1
	echo -e  "******************* gcov results *****************" >> unittestresults.out 2>&1
	gcov -bfu dominion.c >> unittestresults.out 2>&1
	#gcov dominion.c >> unittestresults.out 2>&1
	echo -e  "******************* END CARDTEST2 adventurer implementation **********" >> unittestresults.out 2>&1
	echo -e  "**********************************************************************\n\n" >> unittestresults.out 2>&1
	echo -e  "**********************************************************************" >> unittestresults.out 2>&1
	echo -e  "******************* BEGIN CARDTEST3 great hall implementation ********" >> unittestresults.out 2>&1
	rm -f *.gcov *.gcda *.gcno
	gcc -c dominion.c -g  $(CFLAGS)
	gcc -o cardTest3 cardtest3.c -g dominion.o rngs.o myAssert.o -g $(CFLAGS)
	./cardTest3 >> unittestresults.out 2>&1
	echo -e  "******************* gcov results *****************" >> unittestresults.out 2>&1
	gcov -bfu dominion.c >> unittestresults.out 2>&1
	#gcov dominion.c >> unittestresults.out 2>&1
	echo -e  "******************* END CARDTEST3 great hall implementation **********" >> unittestresults.out 2>&1
	echo -e  "**********************************************************************\n\n" >> unittestresults.out 2>&1
	echo -e  "**********************************************************************" >> unittestresults.out 2>&1
	echo -e  "******************* BEGIN CARDTEST4 council room implementation ******" >> unittestresults.out 2>&1
	rm -f *.gcov *.gcda *.gcno
	gcc -c dominion.c -g  $(CFLAGS)
	gcc -o cardTest4 cardtest4.c -g dominion.o rngs.o myAssert.o -g $(CFLAGS)
	./cardTest4 >> unittestresults.out 2>&1
	echo -e  "******************* gcov results *****************" >> unittestresults.out 2>&1
	gcov -bfu dominion.c >> unittestresults.out 2>&1
	#gcov dominion.c >> unittestresults.out 2>&1
	echo -e  "******************* END CARDTEST4 council room implementation ********" >> unittestresults.out 2>&1
	echo -e  "**********************************************************************\n\n" >> unittestresults.out 2>&1

randomTest: rngs.o
	gcc -o randomTest randomTest.c -g rngs.o $(CFLAGS) -O0
	./randomTest

all: playdom player testDrawCard testBuyCard badTestDrawCard

clean:
	rm -f *.o playdom.exe playdom player player.exe  *.gcov *.gcda *.gcno *.so *.out testDrawCard testDrawCard.exe badTestDrawCard
	rm -rf *.dSYM
	rm -f unitTest*
	rm -f cardTest*
	rm -f randomtestadventurer randomtestcard1 randomtestcard2
