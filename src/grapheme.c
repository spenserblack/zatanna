#include <stdlib.h>
#include "grapheme.h"

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
