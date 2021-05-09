NAME		= libunit.a
CC			= gcc
CFLAGS		= -Wall -Wextra -Werror
AR			= ar
ARFLAGS		= scr
OBJS		= $(SRCS:.c=.o)
VAL			= $(shell find . -name '*.c')
SRCS			= $(shell find . -name '*.c')
run :
	@echo $(VAL)