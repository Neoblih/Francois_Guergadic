/*
** my_apply_on_list.c for my_apply_on_list in /home/guerga_a/rendu/Piscine_C_J12/ex_04
** 
** Made by francois guergadic
** Login   <guerga_a@epitech.net>
** 
** Started on  Tue Oct 21 11:14:41 2014 francois guergadic
** Last update Wed Oct 22 22:28:28 2014 francois guergadic
*/

#include <stdlib.h>
#include "../include/mylist.h"
#include "../include/my.h"

int	my_apply_on_list(t_list *begin, int (*f)(void*))
{
  struct s_list *tmp;

  tmp = begin;
  while (tmp != NULL)
    {
      (*f)(tmp->data);
      tmp = tmp->next;
    }
  begin = tmp;
  return (0);
}
