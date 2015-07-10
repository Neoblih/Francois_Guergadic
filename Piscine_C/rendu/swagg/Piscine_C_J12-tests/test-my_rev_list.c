/*
** test-my_rev_list.c for test 3 in /home/guerga_a/rendu/Piscine_C_J12/tests
** 
** Made by francois guergadic
** Login   <guerga_a@epitech.net>
** 
** Started on  Tue Oct 21 14:28:08 2014 francois guergadic
** Last update Tue Oct 21 17:00:22 2014 francois guergadic
*/

#include <stdlib.h>
#include "../include/mylist.h"

int	main(int argc, char **argv)
{
  test(my_params_in_list(argc, argv));
  return (0);
}

int	test(void *list)
{
  my_show_list(list);
  my_rev_list(&list);
  my_putchar('\n');
  my_show_list(list);
}
