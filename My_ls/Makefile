##
## Makefile for my_ls in /home/guerga_a/B1/Sys_Unix/PSU_2014_my_ls
## 
## Made by francois guergadic
## Login   <guerga_a@epitech.net>
## 
## Started on  Fri Nov 28 16:30:16 2014 francois guergadic
## Last update Sun Nov 30 19:50:20 2014 francois guergadic
##

CC		= gcc

RM		= rm -f

CFLAGS		+=  -Wextra -Wall -Werror
CFLAGS          +=  -ansi -pedantic
CFLAGS          +=  -I. -g

NAME		= my_ls

SRCS		= main.c \
		  aff.c \
		  file_nb.c \
		  init_tab.c \
		  sort_tab.c \
		  aff_erroc.c \
		  free_tab.c

LIB_SRCS        = lib/my/my_putchar.c   \
                  lib/my/my_putstr.c    \
                  lib/my/my_strcmp.c    \
                  lib/my/my_strcpy.c    \
                  lib/my/my_strlen.c

OBJS            = $(SRCS:.c=.o)

LIB_OBJS        = $(LIB_SRCS:.c=.o)

LIB = -L./lib/my/ -lmy

all:	$(NAME)

$(NAME): $(OBJS) $(LIB_OBJS)
	ar rc libmy.a $(LIB_OBJS)
	ranlib libmy.a
	mv libmy.a ./lib/my/.	
	@$(CC) $(OBJS) -o $(NAME) $(LIB) $(CFLAGS)
	@echo -e "\e[1;32m*** Compiled all files ***\e[0m\n"

lib:
	$(MAKE) -C ./lib/my/ re

clean:
	@$(RM) $(OBJS)
	@$(RM) $(LIB_OBJS)
	@echo -e -n "\e[1;33mDeleted files: \e[0m" 
	@echo $(OBJS) 
	@echo $(LIB_OBJS)

fclean: clean
	@$(RM) $(NAME)
	@$(RM) ./lib/my/libmy.a
	@echo -e -n "\e[1;36mDeleted executable file: \e[0m"
	@echo $(NAME)
	@echo libmy.a

re: fclean all

.PHONY: all clean fclean re lib
