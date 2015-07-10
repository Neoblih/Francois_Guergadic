/*
** my_params_in_list.c for my_params_in_list in /home/guerga_a/rendu/Piscine_C_J12/ex_01
** 
** Made by francois guergadic
** Login   <guerga_a@epitech.net>
** 
** Started on  Tue Oct 21 09:27:54 2014 francois guergadic
** Last update Wed Oct 22 22:27:23 2014 francois guergadic
*/

#include <stdlib.h>
#include "../include/mylist.h"
#include "../include/my.h"

int	my_put_in_list(struct s_list **list, void *data)
{
  struct s_list *elem;

  elem = malloc(sizeof(*elem));
  if (elem == NULL)
    return (1);
  elem->data = data;
  elem->next = *list;
  *list = elem;
  return (0);
}

t_list	*my_params_in_list(int ac, char **av)
{
  int	i;
  struct s_list *list;

  i = 0;
  list = NULL;
  while (i < ac)
    {
      my_put_in_list(&list, av[i]);
      i = i + 1;
    }
  return (list);
}
