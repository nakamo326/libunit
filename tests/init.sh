#!/bin/bash

LF=$'\n'
NAME="CASES_H${LF}"
INCLUDE="# include <string.h>
# include \"../real-tests/libft/libft.h\"
# include \"../framework/libunit.h\"

"

HEADER="#ifndef ${NAME}"
HEADER+="# define ${NAME}${INCLUDE}"
HEADER+=$(find . -type d -name libft -prune -o -name '*.c'  | xargs cat 2>/dev/null | sed -e '/^\w/!d' | sed -e "s/)$/);/g")
HEADER+="${LF}${LF}# endif"

echo "${HEADER}" > cases.h

makefile="NAME			= libunit
CC				= gcc
CFLAGS			= -Wall -Wextra -Werror
LIBFT_DIR		= ../real-tests/libft
FRAMEWORK_DIR	= ../framework
LIBUNIT_DIR		= ../
SRCS			= $(find . -name '*.c' | tr '\n' ' ')
"


makefile+='
OBJS			= $(SRCS:.c=.o)

all	:	$(NAME)

$(NAME) : $(OBJS)
	$(MAKE) -C $(LIBFT_DIR)
	$(MAKE) -C $(FRAMEWORK_DIR)
	cp $(LIBFT_DIR)/libft.a $(LIBUNIT_DIR)
	cp $(FRAMEWORK_DIR)/libunit.a $(LIBUNIT_DIR)
	$(RM) ../result.txt

test		: $(NAME)
	$(RM) ../result.txt
	$(CC) $(OBJS) $(LIBUNIT_DIR)/libft.a $(LIBUNIT_DIR)/libunit.a $(CFLAGS) -o $(NAME) && ./libunit

add	:
	bash init.sh

clean:
	rm -f $(OBJS)

bonus : $(OBJS)
	$(MAKE) -C $(LIBFT_DIR)
	$(MAKE) bonus -C $(FRAMEWORK_DIR)
	cp $(LIBFT_DIR)/libft.a $(LIBUNIT_DIR)
	cp $(FRAMEWORK_DIR)/libunit.a $(LIBUNIT_DIR)
	$(RM) ../result.txt

fclean: clean
	$(MAKE) fclean -C $(LIBFT_DIR)
	$(MAKE) fclean -C $(FRAMEWORK_DIR)
	rm -f $(NAME) $(LIBUNIT_DIR)/libft.a $(LIBUNIT_DIR)/libunit.a

re:		fclean all

.PHONY:	all clean fclean re bonus'

echo "${makefile}" > Makefile