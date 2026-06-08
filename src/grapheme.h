#ifndef ZATANNA_GRAPHEME_H
#define ZATANNA_GRAPHEME_H
#include <stdbool.h>
/**
 * Represents a portion of a string that is a single grapheme.
 */
struct grapheme {
	const char * substr;
	/**
	 * Should be between 1 and 4.
	 */
	int len;
};

/**
 * Collects a string into graphemes, returning the length of the collection.
 *
 * It will never collect more graphemes than there are bytes in string, so `strlen(s)`
 * is a safe length for `graphemes`.
 */
int collect_graphemes(char * s, struct grapheme * graphemes);

/**
 * Checks if the grapheme is uppercase.
 */
bool grapheme_is_uppercase(const struct grapheme grapheme);

/**
 * Checks if the grapheme is lowercase.
 */
bool grapheme_is_lowercase(const struct grapheme grapheme);

/**
 * Converts the grapheme to uppercase.
 */
const struct grapheme grapheme_to_uppercase(const struct grapheme grapheme);

/**
 * Converts the grapheme to lowercase.
 */
const struct grapheme grapheme_to_lowercase(const struct grapheme grapheme);

/**
 * Checks if the grapheme is punctuation.
*/
bool grapheme_is_punctuation(const struct grapheme grapheme);

/**
 * Prints a grapheme. It does *not* print a newline.
 */
void print_grapheme(const struct grapheme grapheme);
#endif
