NAME		= libunit.a
CC			= gcc
CFLAGS		= -Wall -Wextra -Werror
AR			= ar
ARFLAGS		= scr
SRCDIR		= ./framework
SRCS		= $(addprefix $(SRCDIR), $(SRCFILE))
OBJS		= $(SRCS:.c=.o)
SRCFILE		= test.c

all			: $(NAME)

$(NAME)		: $(OBJS)
	$(AR) $(ARFLAGS) $(NAME) $^

clean		:
	$(RM) $(OBJS)

fclean		: clean
	$(RM) $(NAME)

re			: fclean all

.PHONY		: all clean fclean re bonus