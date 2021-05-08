NAME		= libunit.a
CC			= gcc
CFLAGS		= -Wall -Wextra -Werror
AR			= ar
ARFLAGS		= scr
SRCDIR		= ./
SRCS		= $(addprefix $(SRCDIR), $(SRCFILE))
OBJS		= $(SRCS:.c=.o)
SRCFILE		= load_test.c launch_tests.c lst_utils.c

all			: $(NAME)

$(NAME)		: $(OBJS)
	$(AR) $(ARFLAGS) $(NAME) $^

clean		:
	$(RM) $(OBJS)

fclean		: clean
	$(RM) $(NAME)

re			: fclean all

.PHONY		: all clean fclean re bonus