##
## Makefile for bsq in /home/guerga_a/B1/Prog_Elem/CPE_2015_bsq
## 
## Made by francois guergadic
## Login   <guerga_a@epitech.net>
## 
## Started on  Wed Jan 14 13:41:56 2015 francois guergadic
## Last update Sun Jan 18 18:49:48 2015 francois guergadic
##

CC		= gcc

RM		= rm -f

CFLAGS		+=  -Wextra -Wall -Werror
CFLAGS          +=  -ansi -pedantic
CFLAGS          +=  -I./include/. -g

NAME		= bsq

SRCS		= main.c \
		  aff_tab.c \
		  my_buff_to_tab.c

LIB_SRCS	= lib/my/my_strcpy.c \
		  lib/my/my_strlen.c \
		  lib/my/my_strcat.c \
		  lib/my/my_putchar.c \
		  lib/my/my_putstr.c

OBJS		= $(SRCS:.c=.o)

LIB_OBJS	= $(LIB_SRCS:.c=.o) 

LIB 		= -L./lib/my/ -lmy

all:	$(NAME)

$(NAME): $(OBJS) $(LIB_OBJS)
	ar rc libmy.a $(LIB_OBJS)
	ranlib libmy.a
	mv libmy.a ./lib/my/.
	$(CC) $(OBJS) -o $(NAME) $(LIB) $(CFLAGS)
	@echo -e "\e[1;32m*** Compiled all files ***\e[0m\n"

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
