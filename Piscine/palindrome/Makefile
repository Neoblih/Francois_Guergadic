##
## Makefile for palindrome in /home/guerga_a/Piscine/palindrome
## 
## Made by francois guergadic
## Login   <guerga_a@epitech.net>
## 
## Started on  Fri Jun 26 09:07:34 2015 francois guergadic
## Last update Sat Jun 27 17:21:49 2015 francois guergadic
##

COMP		= gcc

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

NAME		= palindrome

SRC		= main.c \
		  aff.c \
		  my_power_rec.c \
		  tools.c \
		  reverse.c \
		  error.c

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
