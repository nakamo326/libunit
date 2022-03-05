NAME			= libunit
CC				= gcc
CFLAGS			= -Wall -Wextra -Werror
LIBFT_DIR		= ../real-tests/libft
FRAMEWORK_DIR	= ../framework
LIBUNIT_DIR		= ..
B_LIBUNIT		= $(FRAMEWORK_DIR)/libunit.a
OBJS			= $(SRCS:.c=.o)
SRCS			= ./atoi/00_launcher.c ./atoi/01_basic_test.c ./atoi/02_error_a.c ./atoi/03_ascii_0.c ./atoi/04_space.c ./atoi/05_space2.c ./atoi/06_space3.c ./atoi/07_space4.c ./atoi/08_space5.c ./atoi/09_hyphen.c ./atoi/10_plus.c ./atoi/11_intmin.c ./atoi/12_over_intmin.c ./atoi/13_over_intmax.c ./atoi/14_over_intmax2.c ./atoi/15_overlong.c ./atoi/16_overlong2.c ./atoi/17_overlong3.c ./atoi/18_overlong4.c ./atoi/19_overlong5.c ./atoi/20_overlong6.c ./atoi/21_overlong7.c ./atoi/22_overlong8.c ./atoi/23_overlong9.c ./atoi/24_overlong10.c ./atoi/25_overlong11.c ./atoi/26_overlong12.c ./atoi/27_overlong13.c ./atoi/28_null_p.c ./main.c ./strlen/00_launcher.c ./strlen/01_basic_test.c ./strlen/02_basic_test2.c ./strlen/03_basic_test3.c ./strlen/04_basic_test4.c ./strlen/05_basic_test5.c ./strlen/06_basic_test6.c ./strlen/07_basic_test7.c ./strlen/08_basic_test8.c ./strlen/09_include_allascii_test.c ./strlen/10_include_nullchar_test.c ./strlen/11_include_space_test.c ./strlen/12_empty_str_test.c ./strlen/13_bigger_str_test.c ./strlen/14_NULL_test.c ./exception/00_launcher.c ./exception/01_ko_case.c ./exception/02_bus_error.c ./exception/03_time_out.c ./exception/04_sig_abrt.c ./exception/05_sig_fpe.c ./exception/06_sig_pipe.c ./exception/07_sig_ill.c

all	: _libft _unit $(NAME)

bonus : _libft _bonus_unit $(NAME)

$(NAME) : $(LIBFT_DIR)/libft.a $(FRAMEWORK_DIR)/libunit.a $(OBJS)
	$(RM) ../result.txt
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT_DIR)/libft.a $(FRAMEWORK_DIR)/libunit.a -o $(NAME)

_libft:
	$(MAKE) -C $(LIBFT_DIR)

_unit:
	$(MAKE) -C $(FRAMEWORK_DIR)

_bonus_unit:
	$(MAKE) bonus -C $(FRAMEWORK_DIR)

test		: all
	$(RM) ../result.txt
	./$(NAME)

add	:
	bash init.sh

clean:
	rm -f $(OBJS)
	$(MAKE) clean -C $(LIBFT_DIR)
	$(MAKE) clean -C $(FRAMEWORK_DIR)

fclean: clean
	$(RM) ../result.txt
	$(RM) $(NAME)
	$(MAKE) fclean -C $(LIBFT_DIR)
	$(MAKE) fclean -C $(FRAMEWORK_DIR)

re:		fclean all

.PHONY:	all clean fclean re bonus test _unit _libft _bonus_unit
