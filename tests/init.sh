#!/bin/bash

LF=$'\n'
NAME="TEST_H${LF}"
INCLUDE="# include <string.h>
# include \"../real-tests/libft/libft.h\"

"

HEADER="#ifndef ${NAME}"
HEADER+="# define ${NAME}${INCLUDE}"
HEADER+=$(find . -type d -name libft -prune -o -name '*.c'  | xargs cat 2>/dev/null | sed -e '/^\w/!d' | sed -e "s/)$/);/g")
HEADER+="${LF}${LF}# endif"

echo "${HEADER}" > test.h