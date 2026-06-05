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
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

static bool show_help = false;
static bool reverse_order = false;
static bool print_newline = true;

/**
 * Parses the optional arguments, setting the global variables. Fills `positional_args`
 * with all of the positional arguments, and returns the length of the positional
 * arguments.
 */
int parse_args(char * positional_args[], const int argc, char ** argv);

/**
 * Prints a word in reverse.
 */
void print_word(const char * word);

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
	printf("\t%s [-n] [-O|--reverse-order] words...\n", exe);
	printf("\n");
	printf("OPTIONS\n");
	printf("-n\t\t\tDon't print a newline at the end of the output\n");
	printf("-O, --reverse-order\tPrint from the last positional argument to the first\n");
	printf("-h, --help\t\tShow this help message and exit\n");
}

int parse_args(char * positional_args[], const int argc, char ** argv) {
	int positional_arg_count = 0;
	for (int i = 1; i < argc; ++i) {
		char * arg = argv[i];
		if (strcmp("-n", arg) == 0) {
			print_newline = false;
		} else if (strcmp("-O", arg) == 0 || strcmp("--reverse-order", arg) == 0) {
			reverse_order = true;
		} else if (strcmp("-h", arg) == 0 || strcmp("--help", arg) == 0) {
			show_help = true;
		} else {
			positional_args[positional_arg_count++] = arg;
		}
	}
	return positional_arg_count;
}

void print_word(const char * word) {
	// TODO Should handle multi-byte characters, like "あ"
	size_t index = strlen(word);
	if (index == 0) {
		return;
	}
	do {
		printf("%c", word[--index]);
	} while (index != 0);
}
