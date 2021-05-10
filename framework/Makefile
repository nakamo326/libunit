NAME		= libunit.a
CC			= gcc
CFLAGS		= -Wall -Wextra -Werror #-g -fsanitize=address
AR			= ar
ARFLAGS		= scr
SRCDIR		= ./
SRCS		= $(addprefix $(SRCDIR), $(SRCFILE))
B_SRCS		= $(addprefix $(SRCDIR), $(B_SRCFILE))
OBJS		= $(SRCS:.c=.o)
B_OBJS		= $(B_SRCS:.c=.o)
SRCFILE		= load_test.c launch_tests.c lst_utils.c result.c
B_SRCFILE	= load_test.c launch_tests.c lst_utils.c result_bonus.c

all			: $(NAME)

$(NAME)		: $(OBJS)
	$(AR) $(ARFLAGS) $(NAME) $(OBJS)

clean		:
	$(RM) $(OBJS) $(B_OBJS)

fclean		: clean
	$(RM) $(NAME) 

re			: fclean all

bonus		: $(B_SRCS) $(B_OBJS)
	$(AR) $(ARFLAGS) $(NAME) $(B_OBJS)

.PHONY		: all clean fclean re bonus