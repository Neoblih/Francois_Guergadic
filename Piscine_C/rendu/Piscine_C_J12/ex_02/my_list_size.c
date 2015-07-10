/*
** my_list_size.c for my_list_size in /home/guerga_a/rendu/Piscine_C_J12/ex_02
** 
** Made by francois guergadic
** Login   <guerga_a@epitech.net>
** 
** Started on  Tue Oct 21 10:55:15 2014 francois guergadic
** Last update Wed Oct 22 22:27:40 2014 francois guergadic
*/

#include <stdlib.h>
#include "../include/mylist.h"
#include "../include/my.h"

int	my_list_size(t_list *begin)
{
  int	size;
  struct s_list *tmp;

  tmp = begin;
  size = 0;
  while (tmp != NULL)
    {
      size = size + 1;
      tmp = tmp->next;
    }
  return (size);
}
