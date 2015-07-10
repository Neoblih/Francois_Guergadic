##
## Makefile for makefile in /home/guerga_a/Igraph
## 
## Made by francois guergadic
## Login   <guerga_a@epitech.net>
## 
## Started on  Thu Oct 23 13:15:50 2014 francois guergadic
## Last update Sat Dec  6 18:19:25 2014 francois guergadic
##

LIB_PATH = -L/usr/lib64 -lmlx -L/usr/lib64/X11 -lXext -lX11

SRCS = main.c \
	aff_ligne.c \
	my_buff_to_tab.c \
	my_str_to_tab.c \
	fdf.c \
	epur_str.c \
	free_tab.c

OBJS = $(SRCS:.c=.o)

CFLAGS += -Werror -Wall -Wextra 
CFLAGS += -ansi -pedantic 
CFLAGS += -I./include -g

DEBUG += -g

MY_LIB = -L./lib/ -lmy

NAME = fdf

$(NAME): $(OBJS)
	gcc $(OBJS) -o $(NAME) $(CFLAGS) $(MY_LIB) $(LIB_PATH)

all: $(NAME)

clean:
	rm -rf $(OBJS)

fclean:	clean
	rm -rf $(NAME)

re:	fclean all

.PHONY: all clean fclean re
