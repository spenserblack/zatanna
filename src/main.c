#include <stdbool.h>
#include <stdio.h>

static bool reverse_order = false;

void print_word(const char * word);

int main(int argc, char * argv[]) {
	int start;
	int end;
	int counter;
	if (argc <= 1) {
		return 0;
	}

	if (reverse_order) {
		print_word(argv[argc - 1]);
		for (int i = argc - 2; i > 0; --i) {
			printf(" ");
			print_word(argv[i]);
		}
	} else {
		print_word(argv[1]);
		for (int i = 2; i < argc; ++i) {
			printf(" ");
			print_word(argv[i]);
		}
	}

	return 0;
}

void print_word(const char * word) {
	printf("%s", word);
}
