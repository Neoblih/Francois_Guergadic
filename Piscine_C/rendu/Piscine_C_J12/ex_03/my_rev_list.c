/*
** my_rev_list.c for my_rev_list in /home/guerga_a/rendu/Piscine_C_J12/ex_03
** 
** Made by francois guergadic
** Login   <guerga_a@epitech.net>
** 
** Started on  Tue Oct 21 11:05:33 2014 francois guergadic
** Last update Wed Oct 22 22:28:14 2014 francois guergadic
*/

#include <stdlib.h>
#include "../include/mylist.h"
#include "../include/my.h"

int	my_rev_list(t_list **begin)
{
  struct s_list *prev;
  struct s_list *current;
  struct s_list *next;

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
