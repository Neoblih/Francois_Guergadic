##
## Makefile for SBMLparser in /home/guerga_a/Piscine/SBMLparser
## 
## Made by francois guergadic
## Login   <guerga_a@epitech.net>
## 
## Started on  Mon Jun 15 09:27:24 2015 francois guergadic
## Last update Wed Jun 17 17:01:51 2015 francois guergadic
##

CC		= gcc

RM		= rm -f

CFLAGS		+=  -Wextra -Wall -Werror
CFLAGS          +=  -ansi -pedantic
CFLAGS          +=  -I./include/.

NAME		= SBMLparser

SRCS		= main.c \
		  prerequis.c \
		  global/error.c \
		  global/my_free.c \
		  global/my_read.c \
		  parsing/parsing.c \
		  parsing/tab_tools.c \
		  idflag/comp_id.c \
		  idflag/pars_id.c \
		  idflag/spec_id.c \
		  idflag/equa_id.c \
		  idflag/any_id.c \
		  idflag/tools.c \
		  idflag/reac_id.c \
		  json/json_tools.c \
		  json/json_aff_compartment.c \
		  json/json_aff_species.c \
		  json/json_aff_reaction.c \
		  json/json_reaction.c \
		  json/json_compound.c

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
