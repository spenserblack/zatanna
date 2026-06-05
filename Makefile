CC=gcc

bin/zatanna: src/main.c
	$(CC) -o bin/zatanna src/main.c

.PHONY: install
install: bin/zatanna
	cp bin/zatanna /usr/bin/zatanna

.PHONY: test
test: bin/zatanna
	./test.sh
