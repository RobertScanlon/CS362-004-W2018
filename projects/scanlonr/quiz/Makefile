testme.o: testme.c
	gcc -c testme.c

build: testme.o
	gcc -o testme testme.o

run: testme
	./testme

clean:
	rm -f testme
	rm -f *.o
	rm -f *.DS_Store
	rm -rf *.dSYM
