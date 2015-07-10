/*
** prerequis.c for prerequis in /home/guerga_a/Piscine/agenda
**
** Made by francois guergadic
** Login   <guerga_a@epitech.net>
**
** Started on  Mon Jun 29 09:12:49 2015 francois guergadic
** Last update Tue Jun 30 09:04:41 2015 francois guergadic
*/

#include <stdlib.h>

typedef struct		s_list
{
	void   		*data;
	struct	s_list	*next;
}			t_list;

int		my_revlist_synthese(t_list **begin)
{
  struct s_list	*prev;
  struct s_list	*current;
  struct s_list	*next;

  prev = NULL;
  current = *begin;
  while (current != NULL)
    {
      next = current->next;
      current->next = prev;
      prev = current;
      current = next;
    }
  *begin = prev;
  return (0);
}

t_list		*my_findnodeeqinlist_synthese(t_list *begin, void *data_ref, int (*cmp)(void*, void*))
{
  struct s_list	*tmp;

  tmp = begin;
  while (tmp != NULL)
    {
      if ((*cmp)(tmp->data, data_ref) == 0)
	return (tmp);
      tmp = tmp->next;
    }
  return (NULL);
}
