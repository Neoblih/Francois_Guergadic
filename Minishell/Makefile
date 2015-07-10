##
## Makefile for bsq in /home/guerga_a/B1/Prog_Elem/CPE_2015_bsq
## 
## Made by francois guergadic
## Login   <guerga_a@epitech.net>
## 
## Started on  Wed Jan 14 13:41:56 2015 francois guergadic
## Last update Fri Jan 30 12:25:34 2015 francois guergadic
##

CC		= gcc

RM		= rm -f

CFLAGS		+=  -Wextra -Wall -Werror
CFLAGS          +=  -ansi -pedantic
CFLAGS          +=  -I./include/. -g

NAME		= mysh

SRCS		= main.c \
		  my_str_to_wordtab.c \
		  env_function.c \
		  function.c \
		  env.c \
		  my_setenv.c \
		  my_other_putchar.c \
		  prompt.c \
		  alloc_env.c

LIB_SRCS	= lib/my/my_putchar.c \
		  lib/my/my_putstr.c \
		  lib/my/my_strcmp.c \
		  lib/my/my_strcat.c \
		  lib/my/my_strcpy.c \
		  lib/my/my_strlen.c \
		  lib/my/my_strncmp.c \
		  lib/my/my_getnbr.c \

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
