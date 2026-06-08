/*
	Prints words with the letters reversed.
	Copyright (C) 2026  Spenser Black

	This program is free software: you can redistribute it and/or modify
	it under the terms of the GNU General Public License as published by
	the Free Software Foundation, either version 3 of the License, or
	(at your option) any later version.

	This program is distributed in the hope that it will be useful,
	but WITHOUT ANY WARRANTY; without even the implied warranty of
	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
	GNU General Public License for more details.

	You should have received a copy of the GNU General Public License
	along with this program.  If not, see <https://www.gnu.org/licenses/>.
*/
#include "grapheme.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static bool show_help = false;
static bool reverse_order = false;
static bool print_newline = true;
static bool normalize_casing = false;
static bool keep_punctuation_order = false;

/**
 * Parses the optional arguments, setting the global variables. Fills `positional_args`
 * with all of the positional arguments, and returns the length of the positional
 * arguments.
 */
int parse_args(char * positional_args[], const int argc, char ** argv);

/**
 * Prints a word in reverse.
 */
void print_word(char * word);

/**
 * Prints the help message.
 */
void print_help(const char * exe);

int main(int argc, char * argv[]) {
	int start;
	int end;
	int counter;

	char * positional_args[argc - 1];
	const int positional_arg_count = parse_args(positional_args, argc, argv);

	if (show_help) {
		print_help(argv[0]);
		return 0;
	}

	if (positional_arg_count == 0) {
		return 0;
	}

	if (reverse_order) {
		print_word(positional_args[positional_arg_count - 1]);
		for (int i = positional_arg_count - 2; i >= 0; --i) {
			printf(" ");
			print_word(positional_args[i]);
		}
	} else {
		print_word(positional_args[0]);
		for (int i = 1; i < positional_arg_count; ++i) {
			printf(" ");
			print_word(positional_args[i]);
		}
	}

	if (print_newline) {
		printf("\n");
	}

	return 0;
}

void print_help(const char * exe) {
	printf("USAGE\n");
	printf("\t%s [-c|--normalize-casing] [-n] [-O|--reverse-order] words...\n", exe);
	printf("\n");
	printf("OPTIONS\n");
	printf("-c, --normalize-casing\tSwap the casing of the first and last letter of each word\n");
	printf("-n\t\t\tDon't print a newline at the end of the output\n");
	printf("-O, --reverse-order\tPrint from the last positional argument to the first\n");
	printf("-p, --punctuation-order\tKeep punctuation at the end of a word\n");
	printf("-h, --help\t\tShow this help message and exit\n");
}

int parse_args(char * positional_args[], const int argc, char ** argv) {
	int positional_arg_count = 0;
	for (int i = 1; i < argc; ++i) {
		char * arg = argv[i];
		if (strcmp("-c", arg) == 0 || strcmp("--normalize-casing", arg) == 0) {
			normalize_casing = true;
		} else if (strcmp("-n", arg) == 0) {
			print_newline = false;
		} else if (strcmp("-O", arg) == 0 || strcmp("--reverse-order", arg) == 0) {
			reverse_order = true;
		} else if (strcmp("-p", arg) == 0 || strcmp("--punctuation-order", arg) == 0) {
			keep_punctuation_order = true;
		} else if (strcmp("-h", arg) == 0 || strcmp("--help", arg) == 0) {
			show_help = true;
		} else {
			positional_args[positional_arg_count++] = arg;
		}
	}
	return positional_arg_count;
}

void print_word(char * word) {
	size_t char_count = strlen(word);
	if (char_count == 0) {
		return;
	}

	struct grapheme graphemes[char_count];
	const int graphemes_len = collect_graphemes(word, graphemes);
	int last_index = graphemes_len - 1;
	const bool print_punctuation_after = keep_punctuation_order && grapheme_is_punctuation(graphemes[last_index]);

	if (print_punctuation_after) {
		last_index -= 1;
	}

	if (normalize_casing && grapheme_is_uppercase(graphemes[0])) {
		graphemes[last_index] = grapheme_to_uppercase(graphemes[last_index]);
		graphemes[0] = grapheme_to_lowercase(graphemes[0]);
	}

	for (int i = last_index; i >= 0; --i) {
		const struct grapheme grapheme = graphemes[i];
		print_grapheme(grapheme);
	}

	if (print_punctuation_after) {
		print_grapheme(graphemes[last_index + 1]);
	}
}
