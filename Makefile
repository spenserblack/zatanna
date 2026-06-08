CC=gcc

bin/zatanna: bin/grapheme.o src/main.c
	$(CC) -o bin/zatanna bin/grapheme.o src/main.c

bin/grapheme.o: src/grapheme.c src/grapheme.h
	$(CC) -c -o bin/grapheme.o src/grapheme.c

.PHONY: install
install: install-binary install-man-pages

.PHONY: install-binary
install-binary: bin/zatanna
	cp bin/zatanna /usr/bin/zatanna

.PHONY: install-man-pages
install-man-pages:
	cp -r man/* /usr/local/share/man/

.PHONY: test
test: bin/zatanna
	./test.sh

.PHONY: format
format:
	clang-format -i src/*
