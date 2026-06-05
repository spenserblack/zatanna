CC=gcc

bin/zatanna: src/main.c
	$(CC) -o bin/zatanna src/main.c

.PHONY: test
test: bin/zatanna
	./test.sh
