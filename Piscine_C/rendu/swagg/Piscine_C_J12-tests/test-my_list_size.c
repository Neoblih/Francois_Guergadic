/*
** test-my_list_size.c for test 2 in /home/guerga_a/rendu/Piscine_C_J12/tests
** 
** Made by francois guergadic
** Login   <guerga_a@epitech.net>
** 
** Started on  Tue Oct 21 14:23:27 2014 francois guergadic
** Last update Tue Oct 21 15:56:05 2014 francois guergadic
*/

#include <stdlib.h>
#include "../include/mylist.h"

int	main(int argc, char **argv)
{
  my_put_nbr(my_list_size(my_params_in_list(argc, argv)));
}
