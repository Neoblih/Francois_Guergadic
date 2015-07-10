##
## Makefile for FASTtool in /home/guerga_a/Piscine/FASTAtools
## 
## Made by francois guergadic
## Login   <guerga_a@epitech.net>
## 
## Started on  Wed Jun 24 09:16:36 2015 francois guergadic
## Last update Thu Jun 25 09:34:30 2015 francois guergadic
##

COMP		= gcc -O3

RM		= rm -f

BLUE		= "\033[1;36m"
GREEN		= "\033[1;32m"
YELLOW		= "\033[1;33m"
RED		= "\033[1;31m"
NC		= "\033[0m"

DEBUG		= yes

INCLUDE		= include

CFLAGS		= -Wextra -Wall -Werror
CFLAGS          += -ansi -pedantic
CFLAGS          += -I./$(INCLUDE)/.
ifeq ($(DEBUG), yes)
	CFLAGS += -g
endif

LDFLAGS		=

LIBS 		=

NAME		= FASTAtools

SRC		= main.c	\
		  part1/my_split.c \
		  part1/tools.c \
		  part2/my_split2.c \
		  part3/reverse.c \
		  part4/part4.c \
		  part4/tab_sort.c \
		  part5/part5.c \
		  part6/part6.c \
		  part6/aff.c \
		  global/my_read.c \
		  prerequis.c

OBJS		= $(SRC:.c=.o)

aff_make	= echo -e $(GREEN) "** Make DONE **" $(NC) "\n\t-Compiled executed file: " $(NAME) "\n"

aff_clean	= echo -e $(YELLOW) "** clean DONE **" $(NC) "\n\t-Cleaned .o files \n"

aff_fclean	= echo -e $(BLUE) "** fclean DONE **" $(NC) "\n\t-Cleaned" $(NAME) "\n"

aff_comp        = echo -e "Creating .o file from" $<

aff_error       = echo -e $(RED) "\n |-----\n | Error while creating .o file from" $< "\n |-----\n" $(NC)

all:	$(NAME)


$(NAME): $(OBJS)
	@$(COMP) -o $@ $^ $(LIBS) $(LDFLAGS)
	@$(aff_make)

%.o: %.c
	@($(COMP) -o $@ -c $< $(CFLAGS) && $(aff_comp)) || $(aff_error)

clean:
	@$(RM) $(OBJS)
	@$(aff_clean)

fclean: clean
	@$(RM) $(NAME)
	@$(aff_fclean)

re: fclean all

.PHONY: all clean fclean re
