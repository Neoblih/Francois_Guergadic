/*
** main.c for allum1 in /home/guerga_a/B1/Prog_Elem/Allum1
** 
** Made by francois guergadic
** Login   <guerga_a@epitech.net>
** 
** Started on  Mon Feb  2 13:27:33 2015 francois guergadic
** Last update Fri Feb 13 21:51:13 2015 francois guergadic
*/

#include "./include/allum1.h"

int			main(int argc, char **argv)
{
  t_cursor		*cursor;
  char			**_tab;
  int			r;

  if (argc == 1)
    r = 4;
  else if ((r = my_getnbr(argv[1])) <= 2)
    r = 4;
  _tab = init_tab(r);
  if ((cursor = malloc(sizeof(cursor) * 2)) == NULL)
    return (1);
  aff_rules(r);
  launch_game(_tab, r, cursor);
  return (0);
}
