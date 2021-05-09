NAME			= a.out
CC				= gcc
CFLAGS			= -Wall -Wextra -Werror
LIBFT_DIR		= ../real-tests/libft
FRAMEWORK_DIR	= ../framework
SRCDIR			= ./strlen/
SRCS			= $(addprefix $(SRCDIR), $(SRCFILE)) main.c
OBJS			= $(SRCS:.c=.o)
SRCFILE			= 00_launcher.c 01_basic_test.c 02_NULL_test.c \
					03_bigger_str_test.c 04_include_nullchar_test.c

all	:	$(NAME)

$(NAME) : $(OBJS)
	$(MAKE) re -C $(LIBFT_DIR)
	$(MAKE) re -C $(FRAMEWORK_DIR)
	cp $(LIBFT_DIR)/libft.a .
	cp $(FRAMEWORK_DIR)/libunit.a .
	$(MAKE) fclean -C $(LIBFT_DIR)
	$(MAKE) fclean -C $(FRAMEWORK_DIR)
	$(CC) $(OBJS) libft.a libunit.a $(CFLAGS) -o ${NAME}

clean:
	rm -f $(OBJS)

fclean: clean
		rm -f $(NAME)

re:		fclean all

.PHONY:	all clean fclean re