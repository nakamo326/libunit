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
B_FLAG		= .b_flag

all			: $(NAME)

$(NAME)		: $(OBJS)
	$(AR) $(ARFLAGS) $(NAME) $(OBJS)

bonus		: $(B_FLAG)

$(B_FLAG)	: $(B_OBJS)
	$(RM) $(NAME)
	$(AR) $(ARFLAGS) $(NAME) $(B_OBJS)
	touch $(B_FLAG)

clean		:
	$(RM) $(OBJS) $(B_OBJS)

fclean		: clean
	$(RM) $(B_FLAG)
	$(RM) $(NAME) 

re			: fclean all

.PHONY		: all clean fclean re bonus test