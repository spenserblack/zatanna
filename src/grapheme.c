#include "grapheme.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

/**
 * Guesses the length of a grapheme from the first byte (`char`).
 */
static int guess_grapheme_len(const unsigned char c) {
	// NOTE This isn't a fully accurate definition for every possible byte, but it's a
	//		rough approximation that should handle most cases.
	if (c <= 0x7F) {
		return 1;
	}
	if (c <= 0xDF) {
		return 2;
	}
	if (c <= 0xEF) {
		return 3;
	}
	return 4;
}

int collect_graphemes(char * s, struct grapheme * graphemes) {
	char c_tmp;
	int grapheme_len;
	size_t i = 0;
	int collection_len = 0;

	while ((c_tmp = s[i]) != '\0') {
		grapheme_len = guess_grapheme_len(c_tmp);
		// NOTE This is currently unsafe and can travel past the end of the string for
		//		unexpected byte sequences, e.g. `{0xEF}`.
		graphemes[collection_len].substr = s + i;
		graphemes[collection_len++].len = grapheme_len;

		// NOTE Ensure memory safety by looking forward a few bytes.
		const size_t next_i = i + (size_t)grapheme_len;
		for (size_t lookahead = i + 1; lookahead < next_i; ++lookahead) {
			if (s[lookahead] == '\0') {
				return -1;
			}
		}
		i = next_i;
	}

	return collection_len;
}

bool grapheme_is_uppercase(const struct grapheme grapheme) {
	// TODO Currently incomplete, and does not support other languages with capitalization.
	const char c = grapheme.substr[0];
	return 'A' <= c && c <= 'Z';
}

bool grapheme_is_lowercase(const struct grapheme grapheme) {
	// TODO Currently incomplete, and does not support other languages with capitalization.
	const char c = grapheme.substr[0];
	return 'a' <= c && c <= 'z';
}

static const char * latin_uppercase = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

const struct grapheme grapheme_to_uppercase(const struct grapheme grapheme) {
	// TODO Currently incomplete, and does not support other languages with capitalization.
	const char c = grapheme.substr[0];
	if ('a' <= c && c <= 'z') {
		const unsigned char index = c - 'a';
		const struct grapheme uppercase = {.substr = &(latin_uppercase[index]), .len = 1};
		return uppercase;
	}
	return grapheme;
}

static const char * latin_lowercase = "abcdefghijklmnopqrstuvwxyz";

const struct grapheme grapheme_to_lowercase(const struct grapheme grapheme) {
	// TODO Currently incomplete, and does not support other languages with capitalization.
	const char c = grapheme.substr[0];
	if ('A' <= c && c <= 'Z') {
		const unsigned char index = c - 'A';
		const struct grapheme lowercase = {.substr = &(latin_lowercase[index]), .len = 1};
		return lowercase;
	}
	return grapheme;
}

void print_grapheme(const struct grapheme grapheme) {
	for (int i = 0; i < grapheme.len; ++i) {
		printf("%c", grapheme.substr[i]);
	}
}
