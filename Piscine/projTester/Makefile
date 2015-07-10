##
## Makefile for projTester in /home/guerga_a/Piscine/projTester
## 
## Made by francois guergadic
## Login   <guerga_a@epitech.net>
## 
## Started on  Thu Jun 18 09:09:40 2015 francois guergadic
## Last update Sat Jun 20 11:40:21 2015 francois guergadic
##

CC		= gcc

RM		= rm -f

CFLAGS		+=  -Wextra -Wall -Werror
CFLAGS          +=  -ansi -pedantic
CFLAGS          +=  -I./include/.

NAME		= projTester

SRCS		= main.c \
		  tools.c \
		  get.c \
		  prerequis.c \
		  compare.c \
		  my_str_to_wordtab.c \
		  args.c \
		  error.c \
		  my_read.c \

OBJS		= $(SRCS:.c=.o)

all:	$(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS) -o $(NAME) $(CFLAGS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
