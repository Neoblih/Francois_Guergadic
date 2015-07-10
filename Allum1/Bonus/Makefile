##
## Makefile for Allum1 in /home/guerga_a/B1/Prog_Elem/Allum1
## 
## Made by francois guergadic
## Login   <guerga_a@epitech.net>
## 
## Started on  Mon Feb  2 13:26:29 2015 francois guergadic
## Last update Sat Feb 21 11:03:29 2015 francois guergadic
##

CC		= gcc

RM		= rm -f

CFLAGS		+=  -Wextra -Wall -Werror
CFLAGS          +=  -ansi -pedantic
CFLAGS          +=  -I./include/

NAME		= allum1

SRCS		= main.c \
		  aff_function/color.c \
		  aff_function/aff_tab.c \
		  aff_function/my_putstr_blue.c \
		  aff_function/my_put_nbr_blue.c \
		  core_function/move.c \
		  core_function/remove.c \
		  core_function/game.c \
		  init_function/free_tab.c \
		  init_function/init_cursor.c \
		  init_function/init_read.c \
		  init_function/init_tab.c \
		  ia.c

LIB_SRCS	= lib/my/my_strcat.c \
		  lib/my/my_strcpy.c \
		  lib/my/my_getnbr.c \
		  lib/my/my_putchar.c \
		  lib/my/my_putstr.c

OBJS		= $(SRCS:.c=.o)

LIB_OBJS	= $(LIB_SRCS:.c=.o)

LIB		= -L./lib/my/ -lmy -lncurses

all:	$(NAME)

$(NAME): $(OBJS) $(LIB_OBJS)
	ar rc libmy.a $(LIB_OBJS)
	ranlib libmy.a
	mv libmy.a ./lib/my/.
	$(CC) $(OBJS) -o $(NAME) $(LIB) $(CFLAGS)
	@echo -e -n "\e[1;32m*** Compiled all files ***\e[0m\n"

lib:
	$(MAKE) -C ./lib/my/ re

clean:
	$(RM) $(OBJS)
	@echo -e -n "\e[1;33mDeleted files: \e[0m" 
	@echo $(OBJS) 

fclean: clean
	$(RM) $(NAME)
	@echo -e -n "\e[1;36mDeleted executable file: \e[0m"
	@echo $(NAME)

re: fclean all

.PHONY: all lib clean fclean re
