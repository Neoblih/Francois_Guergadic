/*
** my_find_node_eq_in_list.c for my_find_node_eq_in_list in /home/guerga_a/rendu/Piscine_C_J12/ex_07
** 
** Made by francois guergadic
** Login   <guerga_a@epitech.net>
** 
** Started on  Tue Oct 21 11:45:58 2014 francois guergadic
** Last update Wed Oct 22 22:29:13 2014 francois guergadic
*/

#include <stdlib.h>
#include "../include/mylist.h"
#include "../include/my.h"

t_list	*my_find_node_eq_in_list(t_list *begin, void *data_ref, int (*cmp)())
{
  struct s_list *tmp;

  tmp = begin;
  while (tmp != NULL)
    {
      if ((*cmp)(tmp->data, data_ref) == 0)
	{
	  return (tmp);
	}
      tmp = tmp->next;
    }
}
