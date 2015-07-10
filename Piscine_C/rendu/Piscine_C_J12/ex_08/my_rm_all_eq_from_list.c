/*
** my_rm_all_eq_from_list.c for ex 8 in /home/guerga_a/rendu/Piscine_C_J12/ex_08
** 
** Made by francois guergadic
** Login   <guerga_a@epitech.net>
** 
** Started on  Tue Oct 21 11:50:58 2014 francois guergadic
** Last update Tue Oct 21 12:32:26 2014 francois guergadic
*/

#include <stdlib.h>
#include "../include/mylist.h"

t_list	*my_remove_in_list(t_list *prev, t_list *current)
{
  struct s_list *tmp;

  tmp = current;
  prev->next = tmp->next;
  return (prev);
}

int	my_rm_all_eq_from_list(t_list **begin, void *data_ref, int (*cmp)())
{
  struct s_list *prev;
  struct s_list *current;

  prev = NULL;
  current = *begin;
  if ((*cmp)(current->data, data_ref) == 0)
    {
    }
  else
    {
      while (current->next->data != NULL)
	{
	  if ((*cmp)(current->next->data, data_ref) == 0)
	    current = my_remove_in_list(current, current->next);
	  current = current->next;
	}
    }
}
