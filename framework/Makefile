NAME := libunit.a

SHELL := /bin/bash
CC := gcc
CFLAGS := -Wall -Wextra -Werror -MMD -MP
ARFLAGS := scr
INCLUDE = ./includes
INCLUDES =  $(INCLUDE) $(LIBFTINCLUDE)
IOPT	= $(addprefix -I , $(INCLUDES))

SRCDIR := srcs
SRCFILE	=\
	srcs/framework/launch_tests.c\
	srcs/framework/load_test.c\
	srcs/framework/lst_utils.c\
	srcs/framework/result.c\
	srcs/list/ft_clst_begin.c\
	srcs/list/ft_clst_clear.c\
	srcs/list/ft_clst_insert.c\
	srcs/list/ft_clst_insert_all.c\
	srcs/list/ft_clst_isempty.c\
	srcs/list/ft_clst_isend.c\
	srcs/list/ft_clst_last.c\
	srcs/list/ft_clst_link.c\
	srcs/list/ft_clst_next.c\
	srcs/list/ft_clst_pop.c\
	srcs/list/ft_clst_popdel.c\
	srcs/list/ft_clst_size.c\
	srcs/list/ft_clstadd_back.c\
	srcs/list/ft_clstadd_front.c\
	srcs/list/ft_clstdelone.c\
	srcs/list/ft_clstfirst.c\
	srcs/list/ft_clstnew.c\
	srcs/list/ft_clstnew_add_back.c\

OBJDIR := objs
OBJS = $(patsubst $(SRCDIR)%,$(OBJDIR)%,$(SRCFILE:.c=.o))
DEPS = $(patsubst $(SRCDIR)%,$(OBJDIR)%,$(SRCFILE:.c=.d))

LIBS := -lft

LIBFTDIR = libft
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
	rm -f $@;
	$(AR) $(ARFLAGS) framework.a $^
	$(AR) cqT $@ framework.a $(LIBFT)
#	@echo -e "flags  : $(YLW)$(ARFLAGS)$(NC)\nbuild  : $(GRN)$^$(NC)\n=> $(BLU)$@$(NC)"

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@mkdir -p $(OBJDIR)/$(*D)
	$(CC) $(CFLAGS) -c $< $(IOPT) -o $@
	@echo -e "compile: $(MGN)$<$(NC)\
	$$(yes ' ' | head -n $$(expr $(ALIGN) - $$((`echo $< | wc -m` - 1))) | tr -d '\n') -> \
	$(GRN)$@$(NC)"

add	:
	bash make.sh $(SRCDIR) SRCFILE
	bash header.sh $(SRCDIR)/framework $(INCLUDE)/libunit.h


debug: CFLAGS += -g -fsanitize=integer -fsanitize=address -DDEBUG
debug: re

clean:
	$(RM) $(OBJS) $(DEPS)
	$(RM) -r $(OBJDIR)

fclean: clean
	$(RM) $(NAME)

re: fclean
	$(MAKE) all

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