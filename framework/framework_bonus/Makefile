NAME := libunit.a

SHELL := /bin/bash
CC := gcc
CFLAGS := -Wall -Wextra -Werror -MMD -MP #-g -fsanitize=address
ARFLAGS := scr
INCLUDE = ./includes
INCLUDES =  $(INCLUDE) $(LIBFTINCLUDE)
IOPT	= $(addprefix -I , $(INCLUDES))

SRCDIR := srcs
SRCFILE	=\
	srcs/framework/error_bonus.c\
	srcs/framework/file_out_bonus.c\
	srcs/framework/launch_test_bonus.c\
	srcs/framework/load_test_bonus.c\
	srcs/framework/print_header_bonus.c\
	srcs/framework/print_result_all_bonus.c\
	srcs/framework/print_result_one_bonus.c\
	srcs/framework/put_status_bonus.c\
	srcs/framework/run_test_bonus.c\
	srcs/framework/success_count_bonus.c\
	srcs/framework/testcount_bonus.c\
	srcs/framework/wait_proc_bonus.c\
	srcs/list/ft_clst_begin_bonus.c\
	srcs/list/ft_clst_clear_bonus.c\
	srcs/list/ft_clst_insert_bonus.c\
	srcs/list/ft_clst_insert_all_bonus.c\
	srcs/list/ft_clst_isempty_bonus.c\
	srcs/list/ft_clst_isend_bonus.c\
	srcs/list/ft_clst_last_bonus.c\
	srcs/list/ft_clst_link_bonus.c\
	srcs/list/ft_clst_next_bonus.c\
	srcs/list/ft_clst_pop_bonus.c\
	srcs/list/ft_clst_popdel_bonus.c\
	srcs/list/ft_clst_size_bonus.c\
	srcs/list/ft_clstadd_back_bonus.c\
	srcs/list/ft_clstadd_front_bonus.c\
	srcs/list/ft_clstdelone_bonus.c\
	srcs/list/ft_clstfirst_bonus.c\
	srcs/list/ft_clstnew_bonus.c\
	srcs/list/ft_clstnew_add_back_bonus.c\

OBJDIR := objs
OBJS = $(patsubst $(SRCDIR)%,$(OBJDIR)%,$(SRCFILE:.c=.o))
DEPS = $(patsubst $(SRCDIR)%,$(OBJDIR)%,$(SRCFILE:.c=.d))

LIBS := -lft

LIBFTDIR = ../libft
LIBFTINCLUDE = $(LIBFTDIR)
LIBFT = $(LIBFTDIR)/libft.a

# ==== Align length to format compile message ==== #
ALIGN := $(shell tr ' ' '\n' <<<"$(SRCFILE)" | while read line; do echo \
	$$((`echo $$line | wc -m`)); done | awk 'm<$$1{ m=$$1} END{print m}')

all: _libft $(NAME)

-include $(DEPS)

_libft	:
	$(MAKE) -C $(LIBFTDIR)

$(LIBFT) : _libft

$(NAME): $(OBJS)
	cp $(LIBFT) $(NAME)
	$(AR) $(ARFLAGS) $(NAME) $(OBJS)
	@echo -e "flags  : $(YLW)$(ARFLAGS)$(NC)\nbuild  : $(GRN)$^$(NC)\n=> $(BLU)$@$(NC)"

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@mkdir -p $(OBJDIR)/$(*D)
	@$(CC) $(CFLAGS) -c $< $(IOPT) -o $@
	@echo -e "compile: $(MGN)$<$(NC)\
	$$(yes ' ' | head -n $$(expr $(ALIGN) - $$((`echo $< | wc -m` - 1))) | tr -d '\n') -> \
	$(GRN)$@$(NC)"

add	:
	bash make.sh $(SRCDIR) SRCFILE
	bash header.sh $(SRCDIR)/framework $(INCLUDE)/libunit.h

debug: CFLAGS += -g -fsanitize=address
debug: re

clean:
	$(MAKE) clean -C $(LIBFTDIR)
	$(RM) $(OBJS) $(DEPS)
	$(RM) -r $(OBJDIR)

fclean: clean
	$(MAKE) fclean -C $(LIBFTDIR)
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re debug srcs

# ==== Color define ==== #
YLW := \033[33m
GRN := \033[32m
YLW := \033[33m
BLU := \033[34m
MGN := \033[35m
CYN := \033[36m
NC := \033[m

# ==== suggest 'j' option of make command ==== #
ifeq ($(shell uname), Linux)
	procs := $$(expr $$(grep cpu.cores /proc/cpuinfo | sort -u | sed 's/[^0-9]//g') + 1)
else
	procs := $$(expr $$(system_profiler SPHardwareDataType | grep Total | sed 's/[^0-9]//g') + 1)
endif

.PHONY: proc
proc:
	@echo -e "please do $(CYN)export MAKEFLAGS=-j$(procs)$(NC)"
