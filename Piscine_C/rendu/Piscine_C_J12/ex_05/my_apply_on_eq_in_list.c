/*
** my_apply_on_eq_in_list.c for my_apply_on_eq_in_list in /home/guerga_a/rendu/Piscine_C_J12/ex_05
** 
** Made by francois guergadic
** Login   <guerga_a@epitech.net>
** 
** Started on  Tue Oct 21 11:20:27 2014 francois guergadic
** Last update Wed Oct 22 22:28:46 2014 francois guergadic
*/

#include <stdlib.h>
#include "../include/mylist.h"
#include "../include/my.h"

int	my_apply_on_eq_in_list(t_list *begin, int (*f)(),
			       void *data_ref, int (*cmp)())
{
  struct s_list *tmp;

  tmp = begin;
  while (tmp != NULL)
    {
      if ((*cmp)(tmp->data, data_ref) == 0)
	(*f)(tmp->data);
      tmp = tmp->next;
    }
  return (0);
}
