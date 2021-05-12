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
HEADER+=$(find . -type d -name libft -prune -o -name '*.c'  | xargs cat 2>/dev/null | sed -e '/^\w/!d' | sed -e "s/)$/);/g")
HEADER+="${LF}${LF}#endif"


makefile="NAME			= libunit
CC				= gcc
CFLAGS			= -Wall -Wextra -Werror
LIBFT_DIR		= ../real-tests/libft
FRAMEWORK_DIR	= ../framework
LIBUNIT_DIR		= ../
SRCS			= $(find . -name '*.c' | tr '\n' ' ')
"

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

MAIN_C+="$(find . -name '*.c' | sed '/\/00.*\.c/!d' | xargs cat 2>/dev/null | sed -e '/^\w/!d' -e "s/(\w*)$/();/g" -e "s/^\w*\t/\tret += /g")
	return (ret);
}"

echo "${MAIN_C}" > main.c
echo "${HEADER}" > cases.h

files=$(find . -name '*.c' | tr '\n' ' ')
sed -i -e "s@^SRCS\s*=.*@SRCS\t\t\t\t= ${files}@g" Makefile