/*
** my_show_list.c for my_show_list in /home/guerga_a/rendu/Piscine_C_J12/tests
** 
** Made by francois guergadic
** Login   <guerga_a@epitech.net>
** 
** Started on  Tue Oct 21 14:37:26 2014 francois guergadic
** Last update Tue Oct 21 14:43:48 2014 francois guergadic
*/

#include <stdlib.h>
#include "../include/mylist.h"

void	my_show_list(struct s_list *list)
{
  while (list != NULL)
    {
      my_putstr(list->data);
      my_putchar('\n');
      list = list->next;
    }
}
