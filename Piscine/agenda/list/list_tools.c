/*
** list_tools.c for list tools in /home/guerga_a/Piscine/agenda/list
**
** Made by francois guergadic
** Login   <guerga_a@epitech.net>
**
** Started on  Mon Jun 29 14:40:38 2015 francois guergadic
** Last update Mon Jun 29 14:42:23 2015 francois guergadic
*/

#include "agenda.h"

int		my_put_in_list(struct s_list **list, void *data)
{
  struct s_list *elem;

  if ((elem = malloc(sizeof(elem) * 4)) == NULL)
    return (1);
  elem->data = data;
  elem->next = *list;
  *list = elem;
  return (0);
}
