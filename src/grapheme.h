#ifndef ZATANNA_GRAPHEME_H
#define ZATANNA_GRAPHEME_H
/**
 * Represents a portion of a string that is a single grapheme.
 */
struct grapheme {
	char * substr;
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
 * Prints a grapheme. It does *not* print a newline.
 */
void print_grapheme(const struct grapheme grapheme);
#endif
