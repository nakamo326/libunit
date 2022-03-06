# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mkamei <mkamei@student.42tokyo.jp>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/10/13 10:43:27 by ynakamot          #+#    #+#              #
#    Updated: 2022/03/06 13:33:17 by mkamei           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
CFLAGS = -Wall -Wextra -Werror

SRCFILE =	ft_memset.c ft_bzero.c ft_memcpy.c ft_memccpy.c ft_memmove.c \
			ft_memchr.c ft_memcmp.c ft_strlen.c ft_strlcpy.c ft_strlcat.c \
			ft_strchr.c ft_strrchr.c ft_strnstr.c ft_strncmp.c ft_atoi.c \
			ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c \
			ft_toupper.c ft_tolower.c ft_calloc.c ft_strdup.c ft_substr.c \
			ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c \
			ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
			ft_putnbr_base_fd.c ft_lltoa_base.c ft_ltoa.c ft_abs.c \
			ft_isspace.c ft_free_split.c ft_extend_split.c ft_addstr_split.c \
			ft_split_multi.c ft_putchar.c ft_str_sandwich.c ft_wrap_malloc.c \
			ft_atoll.c ft_free.c ft_putstrs_fd.c ft_putsize_fd.c

B_SRCFILE=	ft_lstnew.c ft_lstadd_front.c ft_lstsize.c \
			ft_lstlast.c ft_lstadd_back.c ft_lstdelone.c \
			ft_lstclear.c ft_lstiter.c ft_lstmap.c ft_lstinsert.c

OBJDIR = ./obj
OBJECTS = $(addprefix $(OBJDIR)/, $(notdir $(SRCFILE:.c=.o)))
B_OBJECTS = $(addprefix $(OBJDIR)/, $(notdir $(B_SRCFILE:.c=.o)))

all: $(NAME)

$(NAME): $(OBJECTS)
	ar rcs $(NAME) $(OBJECTS)

bonus: $(OBJECTS) $(B_OBJECTS)
	ar rcs $(NAME) $(OBJECTS) $(B_OBJECTS)

$(OBJDIR)/%.o: %.c
	@mkdir -p $(OBJDIR)
	gcc $(CFLAGS) -I. -c $< -o $@

clean:
	$(RM) $(OBJECTS) $(B_OBJECTS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all bonus clean fclean re
