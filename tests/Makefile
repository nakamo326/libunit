NAME			= libunit
CC				= gcc
CFLAGS			= -Wall -Wextra -Werror
LIBFT_DIR		= ../real-tests/libft
FRAMEWORK_DIR	= ../framework
SRCDIR			= ./strlen/
# SRCS			= $(shell find . -name '*.c')
SRCS			= $(STRLENSRC) $(ATOISRC) main.c
OBJS			= $(SRCS:.c=.o)
STRLENSRC		= ./strlen/05_basic_test5.c \
				./strlen/03_basic_test3.c \
				./strlen/14_bigger_str_test.c \
				./strlen/01_basic_test.c \
				./strlen/08_include_allascii_test.c \
				./strlen/00_launcher.c \
				./strlen/12_empty_str_test.c \
				./strlen/07_basic_test7.c \
				./strlen/11_basic_test11.c \
				./strlen/02_basic_test2.c \
				./strlen/09_not_endwith_nullchar.c \
				./strlen/06_basic_test6.c \
				./strlen/10_include_space_test.c \
				./strlen/13_include_nullchar_test.c \
				./strlen/15_NULL_test.c \
				./strlen/04_basic_test4.c\
				./strlen/16_buserror.c\
				./strlen/17_ko_case.c\
				./strlen/18_zero_divide.c
ATOISRC			= ./atoi/00_launcher.c\
				./atoi/01_basic_test.c\
				./atoi/02_error_a.c\
				./atoi/03_ascii_0.c\
				./atoi/04_space.c\
				./atoi/05_space2.c\
				./atoi/06_space3.c\
				./atoi/07_hyphen.c\
				./atoi/08_space4.c\
				./atoi/09_space5.c\
				./atoi/10_plus.c\
				./atoi/11_intmin.c\
				./atoi/12_over_intmin.c\
				./atoi/13_over_intmax.c\
				./atoi/14_over_intmax2.c\
				./atoi/15_overlong.c\
				./atoi/16_overlong2.c\
				./atoi/17_overlong3.c\
				./atoi/18_overlong4.c\
				./atoi/19_overlong5.c\
				./atoi/20_overlong6.c\
				./atoi/21_overlong7.c\
				./atoi/22_overlong8.c\
				./atoi/23_overlong9.c\
				./atoi/24_overlong10.c\
				./atoi/25_overlong11.c\
				./atoi/26_overlong12.c\
				./atoi/27_overlong13.c\
				./atoi/28_null_p.c

all	:	$(NAME)

$(NAME) : $(OBJS)
	$(MAKE) -C $(LIBFT_DIR)
	$(MAKE) -C $(FRAMEWORK_DIR)
	cp $(LIBFT_DIR)/libft.a .
	cp $(FRAMEWORK_DIR)/libunit.a .
	$(RM) ../result.txt

run		: $(NAME)
	$(CC) $(OBJS) libft.a libunit.a $(CFLAGS) -o $(NAME) && ./libunit
clean:
	rm -f $(OBJS)

bonus	: $(NAME)

fclean: clean
	$(MAKE) fclean -C $(LIBFT_DIR)
	$(MAKE) fclean -C $(FRAMEWORK_DIR)
	rm -f $(NAME) libft.a libunit.a

re:		fclean all

.PHONY:	all clean fclean re bonus

