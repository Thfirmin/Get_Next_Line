#!/bin/bash

buff=$1

FILES="
ola
empty
nl
41_no_nl
41_with_nl
42_no_nl
42_with_nl
43_no_nl
43_with_nl
multiple_nlx5
multiple_line_no_nl
multiple_line_with_nl
alternate_line_nl_no_nl
alternate_line_nl_with_nl
big_line_no_nl
big_line_with_nl
"
PATH="files/"


if [[ ! -f a.out ]]; then
	exit 2
fi
echo -e "[BUFFER_SIZE = ${buff}]:"
for file in $FILES; do
	echo -en "${PATH}${file}: "
	time ./a.out gnlTester/${PATH}${file} 1> /dev/null
	if [[ $? != 0 ]]; then
		exit 2
	fi
done
