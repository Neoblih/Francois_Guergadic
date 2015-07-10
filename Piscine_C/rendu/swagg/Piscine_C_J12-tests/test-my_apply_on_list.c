/*
** test-my_apply_on_list.c for test ex4 in /home/guerga_a/rendu/Piscine_C_J12/tests
** 
** Made by francois guergadic
** Login   <guerga_a@epitech.net>
** 
** Started on  Tue Oct 21 17:04:53 2014 francois guergadic
** Last update Tue Oct 21 17:58:54 2014 francois guergadic
*/

#include <stdlib.h>
#include "../include/mylist.h"
#include "my.h"

int	main(int argc, char **argv)
{
  test(my_params_in_list(argc, argv));
  return (0);
}

int	test(void *list)
{
  my_apply_on_list(list, my_putstr);
}
