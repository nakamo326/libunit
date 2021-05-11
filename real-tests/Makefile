NAME			= libunit
CC				= gcc
CFLAGS			= -Wall -Wextra -Werror
LIBFT_DIR		= ../real-tests/libft
FRAMEWORK_DIR	= ../framework
LIBUNIT_DIR		= ../
SRCS			= ./atoi/00_launcher.c ./atoi/01_basic_test.c ./atoi/02_error_a.c ./atoi/03_ascii_0.c ./atoi/04_space.c ./atoi/05_space2.c ./atoi/06_space3.c ./atoi/07_hyphen.c ./atoi/08_space4.c ./atoi/09_space5.c ./atoi/10_plus.c ./atoi/11_intmin.c ./atoi/12_over_intmin.c ./atoi/13_over_intmax.c ./atoi/14_over_intmax2.c ./atoi/15_overlong.c ./atoi/16_overlong2.c ./atoi/17_overlong3.c ./atoi/18_overlong4.c ./atoi/19_overlong5.c ./atoi/20_overlong6.c ./atoi/21_overlong7.c ./atoi/22_overlong8.c ./atoi/23_overlong9.c ./atoi/24_overlong10.c ./atoi/25_overlong11.c ./atoi/26_overlong12.c ./atoi/27_overlong13.c ./atoi/28_null_p.c ./is_alnum/00_launcher.c ./is_alnum/01_basic_test.c ./is_alnum/02_basic_test.c ./is_alnum/03_basic_test.c ./is_alnum/04_basic_test.c ./is_alnum/05_basic_test.c ./libft/ft_atoi.c ./libft/ft_bzero.c ./libft/ft_calloc.c ./libft/ft_isalnum.c ./libft/ft_isalpha.c ./libft/ft_isascii.c ./libft/ft_isdigit.c ./libft/ft_isprint.c ./libft/ft_itoa.c ./libft/ft_lstadd_back.c ./libft/ft_lstadd_front.c ./libft/ft_lstclear.c ./libft/ft_lstdelone.c ./libft/ft_lstiter.c ./libft/ft_lstlast.c ./libft/ft_lstmap.c ./libft/ft_lstnew.c ./libft/ft_lstsize.c ./libft/ft_memccpy.c ./libft/ft_memchr.c ./libft/ft_memcmp.c ./libft/ft_memcpy.c ./libft/ft_memmove.c ./libft/ft_memset.c ./libft/ft_putchar_fd.c ./libft/ft_putendl_fd.c ./libft/ft_putnbr_fd.c ./libft/ft_putstr_fd.c ./libft/ft_split.c ./libft/ft_strchr.c ./libft/ft_strdup.c ./libft/ft_strjoin.c ./libft/ft_strlcat.c ./libft/ft_strlcpy.c ./libft/ft_strlen.c ./libft/ft_strmapi.c ./libft/ft_strncmp.c ./libft/ft_strnstr.c ./libft/ft_strrchr.c ./libft/ft_strtrim.c ./libft/ft_substr.c ./libft/ft_tolower.c ./libft/ft_toupper.c ./main.c ./strlen/00_launcher.c ./strlen/01_basic_test.c ./strlen/02_basic_test2.c ./strlen/03_basic_test3.c ./strlen/04_basic_test4.c ./strlen/05_basic_test5.c ./strlen/06_basic_test6.c ./strlen/07_basic_test7.c ./strlen/08_include_allascii_test.c ./strlen/09_include_nullchar_test.c ./strlen/10_include_space_test.c ./strlen/11_basic_test11.c ./strlen/12_empty_str_test.c ./strlen/14_bigger_str_test.c ./tolower/00_launcher.c ./tolower/01_basic_test.c ./tolower/02_basic_test2.c ./tolower/03_not_alpha.c ./tolower/04_nullchar_test.c ./tolower/05_notascii_test.c ./toupper/00_launcher.c ./toupper/01_basic_test.c ./toupper/02_basic_test2.c ./toupper/03_not_alpha.c ./toupper/04_nullchar_test.c ./toupper/05_notascii_test.c 

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

.PHONY:	all clean fclean re bonus
