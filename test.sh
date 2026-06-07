#!/bin/sh
SCRIPT="$(readlink -f "$0")"
ROOT="$(dirname "$SCRIPT")"
EXE="$ROOT/bin/zatanna"
SUCCESS="\033[1;42m OK \033[0m"
FAIL="\033[1;41mFAIL\033[0m"
EXIT_CODE=0

assert_eq() {
	if [ "$1" = "$2" ]; then
		echo "$SUCCESS"
	else
		echo "$FAIL"
		echo "\"$1\" != \"$2\""
		EXIT_CODE=1
	fi
}

it_works() {
	RESULT="$("$EXE" -n hello world)"
	assert_eq "$RESULT" "olleh dlrow"
}

reversed_order() {
	RESULT="$("$EXE" -n -O hello world)"
	assert_eq "$RESULT" "dlrow olleh"
}

multi_byte_chars_cn() {
	RESULT="$("$EXE" -n "大熊猫")"
	assert_eq "$RESULT" "猫熊大"
}

multi_byte_chars_de() {
	RESULT="$("$EXE" -n "tschüß")"
	assert_eq "$RESULT" "ßühcst"
}

multi_byte_chars_jp() {
	RESULT="$("$EXE" -n "こんにちは")"
	assert_eq "$RESULT" "はちにんこ"
}

normalized_casing() {
	RESULT="$("$EXE" -n -c Hello world)"
	assert_eq "$RESULT" "Olleh dlrow"
}

TESTS="it_works reversed_order multi_byte_chars_cn multi_byte_chars_de multi_byte_chars_jp normalized_casing"
for t in $TESTS; do
	echo -n "$t..."
	"$t"
done

exit "$EXIT_CODE"
