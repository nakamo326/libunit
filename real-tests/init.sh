#!/bin/bash

LF=$'\n'
NAME="CASES_H${LF}"
INCLUDE='# include <string.h>
# include "../real-tests/libft/libft.h"
# include "../framework/libunit.h"
# include <limits.h>
# include <ctype.h>

'

HEADER="#ifndef ${NAME}"
HEADER+="# define ${NAME}${INCLUDE}"
HEADER+=$(find . -type d -name libft -prune -o -type f -name '*.c' | xargs cat | sed -e '/^\w.*)$/!d' -e '/^static/d' -e "s/)$/);/g")
HEADER+="${LF}${LF}#endif"

MAIN_C='#include "cases.h"
#include <stdio.h>

int	main(void)
{
	int	ret;

	puts("\n\x1b[36m\x1b[1m*********************************");
	puts("*****    42 - Unit Tests    *****");
	puts("*********************************\x1b[0m\n\x1b[39m");
	ret = 0;
'

MAIN_C+="$(find . -type f -name '*.c' | sed '/\/00.*\.c/!d' | xargs cat | sed -e '/^\w/!d' -e "s/(\w*)$/();/g" -e "s/^\w*\t/\tret += /g")
	return (ret);
}"

echo "${MAIN_C}" > main.c
echo "${HEADER}" > cases.h

sed -i -e "s@^SRCS\s*=.*@SRCS\t\t\t= $(find . -name '*.c' | tr '\n' ' ')@g" Makefile