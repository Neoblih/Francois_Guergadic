##
## Makefile for make in /home/guerga_a/B1/Sys_Unix/PSU_2014_my_ls/lib
## 
## Made by francois guergadic
## Login   <guerga_a@epitech.net>
## 
## Started on  Sat Nov 29 12:37:52 2014 francois guergadic
## Last update Wed Jan 14 13:39:02 2015 francois guergadic
##

CC	= gcc

RM	= rm -f

FLAGS   += -Wextra -Wall -Werror
CFLAGS  += -ansi -pedantic
CFLAGS  += -I.

LDFLAGS =

SRC	= my_find_prime_sup.c \
	  my_getnbr.c \
	  my_isneg.c \
	  my_is_prime.c \
	  my_power_rec.c \
	  my_putchar.c \
	  my_put_nbr.c \
	  my_putstr.c \
	  my_revstr.c \
	  my_sort_int_tab.c \
	  my_square_root.c \
	  my_strcapitalize.c \
	  my_strcmp.c \
	  my_strcpy.c \
	  my_str_isalpha.c \
	  my_str_islower.c \
	  my_str_isnum.c \
	  my_str_isprintable.c \
	  my_str_isupper.c \
	  my_strlen.c \
	  my_strlowcase.c \
	  my_strncmp.c \
	  my_strncpy.c \
	  my_strstr.c \
	  my_strupcase.c \
	  my_swap.c

OBJS	= $(SRC:.c=.o)

NAME	= libmy.a

all: $(NAME)

$(NAME):
	$(CC) -c $(SRC)
	@echo "libmy compilation succes"
	ar rc $(NAME) $(OBJS)
	ranlib $(NAME)
	@echo "Libmy succesfully created"
	cp libmy.a ../
	cp my.h ../../include/.
	@echo "libmy.a and my.h successfully moved to their respective folders"

clean:
	$(RM) $(OBJS)
	@echo ".o files deleted"

fclean: clean
	$(RM) $(NAME)
	@echo $(NAME) "deleted"

re:	fclean all

.PHONY: all clean fclean re
