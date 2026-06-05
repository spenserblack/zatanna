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

TESTS="it_works"
for t in $TESTS; do
	echo -n "$t..."
	"$t"
done

exit "$EXIT_CODE"
