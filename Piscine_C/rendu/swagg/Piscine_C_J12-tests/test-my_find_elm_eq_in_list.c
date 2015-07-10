/*
** test-my_find_elm_eq_in_list.c for test ex6 in /home/guerga_a/rendu/Piscine_C_J12/tests
** 
** Made by francois guergadic
** Login   <guerga_a@epitech.net>
** 
** Started on  Tue Oct 21 18:27:34 2014 francois guergadic
** Last update Tue Oct 21 18:49:49 2014 francois guergadic
*/

#include <stdlib.h>
#include "../include/mylist.h"
#include "../include/my.h"

int	main(int ac, char **av)
{
  test(my_params_in_list(ac, av));
}

int	test(t_list *test)
{
  my_find_elm_eq_in_list(test, "test", my_strcmp);
}
