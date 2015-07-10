##
## Makefile for makefile in /home/guerga_a/Colles/Piscine_C_colles-Semaine_03
## 
## Made by francois guergadic
## Login   <guerga_a@epitech.net>
## 
## Started on  Sat Oct 25 16:18:58 2014 francois guergadic
## Last update Sat Oct 25 21:32:29 2014 francois guergadic
##

SRC     = main.c \
	  colle3.c \
	  colle_to_tabtab.c \
	  colle_struct.c \
	  match.c \
	  aff_result.c

OBJS    = $(SRC:.c=.o)

LIB	= -lmy -L./lib/my/

NAME    = colle3

all: $(NAME)

$(NAME):
	gcc -c $(SRC)
	gcc -o $(NAME) $(OBJS) $(LIB)

clean:
	rm -f $(OBJS)

fclean:
	rm -f $(NAME)
