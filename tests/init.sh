#!/bin/bash

NAME_H="cases.h"
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

MAIN_C+="$(find . -type f -name '*.c' | sed '/\/00.*\.c/!d' | xargs cat 2>/dev/null | sed -e '/^\w/!d' -e "s/(\w*)$/();/g" -e "s/^\w*\t/\tret += /g")
	return (ret);
}"

makefile=$(sed -e "s@^SRCS\s*=.*@SRCS\t\t\t= $(find . -type f -name '*.c' | tr '\n' ' ')@g" Makefile)
header="$(sed -e "/\(^\w\w*\t*\w.*);$\|#endif\)/d" -e '/^$/d' ${NAME_H})

$(find . -type d -name libft -prune -o -type f -name '*.c' | xargs cat | sed -e '/^\w.*)$/!d' -e '/^static/d' -e "s/)$/);/g")

#endif"

echo "${makefile}" > Makefile
echo "${MAIN_C}" > main.c
echo "${header}" > ${NAME_H}