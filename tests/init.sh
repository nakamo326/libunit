#!/bin/bash

NAME_H="cases.h"
t=$(printf "\t")

MAIN_C="$(find . -type f -name main.c | xargs cat | sed -e "/.*launcher.*);$/d" -e "/return (.*);$/d" -e "/^}$/d")
$(find . -type f -name '*.c' | sed '/\/00.*\.c/!d' | xargs cat | sed -e '/^[a-zA-Z]/!d' -e "s/(.*)$/();/g" -e "s/^[a-zA-Z][a-zA-Z_0-9]*${t}/${t}ret |= /g")
	return (ret);
}"

makefile=$(sed -e "s@^SRCS\s*=.*@SRCS${t}${t}$(printf "\t")= $(find . -type f -name '*.c' | tr '\n' ' ' | sed 's/\s*$//')@g" Makefile)

header="$(sed -e "/^[a-zA-Z][a-zA-Z_0-9]*.*);$/d" -e '/#endif/d' -e '/^$/d' ${NAME_H})

$(find . -type d -name libft -prune -o -type f -name '*.c' | xargs cat | sed -e '/^[a-zA-Z].*)$/!d' -e '/^static/d' -e "s/)$/);/g")

#endif"

echo "${makefile}" > Makefile
echo "${MAIN_C}" > main.c
echo "${header}" > ${NAME_H}