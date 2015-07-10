/*
** test-my_find_node_eq_in_list.c for test ex7 in /home/guerga_a/rendu/Piscine_C_J12/tests
** 
** Made by francois guergadic
** Login   <guerga_a@epitech.net>
** 
** Started on  Tue Oct 21 18:42:55 2014 francois guergadic
** Last update Tue Oct 21 18:50:11 2014 francois guergadic
*/

#include <stdlib.h>
#include "../include/mylist.h"
#include "../include/my.h"

int     main(int ac, char **av)
{
  test(my_params_in_list(ac, av));
}

int     test(t_list *test)
{
  my_show_list(my_find_node_eq_in_list(test, "test", my_strcmp));
}
