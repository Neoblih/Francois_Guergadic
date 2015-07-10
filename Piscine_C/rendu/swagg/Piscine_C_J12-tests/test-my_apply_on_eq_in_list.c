/*
** test-my_apply_on_eq_in_list.c for test 5 in /home/guerga_a/rendu/Piscine_C_J12/tests
** 
** Made by francois guergadic
** Login   <guerga_a@epitech.net>
** 
** Started on  Tue Oct 21 18:07:09 2014 francois guergadic
** Last update Tue Oct 21 18:18:05 2014 francois guergadic
*/

#include <stdlib.h>
#include "../include/mylist.h"
#include "../include/my.h"

int     main(int argc, char **argv)
{
  test(my_params_in_list(argc, argv));
  return (0);
}

int     test(void *list)
{
  my_apply_on_eq_in_list(list, my_putstr, "test", my_strcmp);
}
