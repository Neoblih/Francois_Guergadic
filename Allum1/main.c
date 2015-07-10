/*
** main.c for allum1 in /home/guerga_a/B1/Prog_Elem/Allum1
** 
** Made by francois guergadic
** Login   <guerga_a@epitech.net>
** 
** Started on  Mon Feb  2 13:27:33 2015 francois guergadic
** Last update Sat Feb 21 12:16:34 2015 francois guergadic
*/

#include "./include/allum1.h"

int			main(void)
{
  t_cursor		*cursor;
  char			**_tab;

  _tab = init_tab(4);
  if ((cursor = malloc(sizeof(cursor) * 2)) == NULL)
    return (1);
  launch_game(_tab, cursor);
  return (0);
}
