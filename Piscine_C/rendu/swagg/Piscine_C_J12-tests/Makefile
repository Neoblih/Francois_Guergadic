##
## Makefile for makefile in /home/guerga_a/rendu/Piscine_C_J12/tests
## 
## Made by francois guergadic
## Login   <guerga_a@epitech.net>
## 
## Started on  Tue Oct 21 14:44:26 2014 francois guergadic
## Last update Tue Oct 21 18:45:20 2014 francois guergadic
##

LIB 	= -lmy -L../lib/

SHOWLIST	= my_show_list.c

all: ex01 ex02 ex03 ex04 ex05 ex06 ex07

ex01:
	@gcc -o ex1 test-my_params_in_list.c ../ex_01/my_params_in_list.c $(SHOWLIST) $(LIB)

ex02:
	@gcc -o ex2 test-my_list_size.c ../ex_02/my_list_size.c ../ex_01/my_params_in_list.c $(SHOWLIST) $(LIB)

ex03:
	@gcc -o ex3 test-my_rev_list.c ../ex_03/my_rev_list.c ../ex_01/my_params_in_list.c $(SHOWLIST) $(LIB)

ex04:
	@gcc -o ex4 test-my_apply_on_list.c ../ex_04/my_apply_on_list.c ../ex_01/my_params_in_list.c $(SHOWLIST) $(LIB)

ex05:
	@gcc -o ex5 test-my_apply_on_eq_in_list.c ../ex_05/my_apply_on_eq_in_list.c ../ex_01/my_params_in_list.c $(SHOWLIST) $(LIB)

ex06:
	@gcc -o ex6 test-my_find_elm_eq_in_list.c ../ex_06/my_find_elm_eq_in_list.c ../ex_01/my_params_in_list.c $(SHOWLIST) $(LIB)

ex07:
	@gcc -o ex7 test-my_find_node_eq_in_list.c ../ex_07/my_find_node_eq_in_list.c ../ex_01/my_params_in_list.c $(SHOWLIST) $(LIB)

clean:
	@rm -f ex1 ex2 ex3 ex4 ex5 ex6
