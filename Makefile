CC=gcc

bin/zatanna: bin/grapheme.o src/main.c
	$(CC) -o bin/zatanna bin/grapheme.o src/main.c

bin/grapheme.o: src/grapheme.c src/grapheme.h
	$(CC) -c -o bin/grapheme.o src/grapheme.c

.PHONY: install
install: bin/zatanna
	cp bin/zatanna /usr/bin/zatanna

.PHONY: test
test: bin/zatanna
	./test.sh
