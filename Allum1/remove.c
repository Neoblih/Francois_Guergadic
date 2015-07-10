/*
** remove.c for remove in /home/guerga_a/B1/Prog_Elem/Allum1
** 
** Made by francois guergadic
** Login   <guerga_a@epitech.net>
** 
** Started on  Wed Feb  4 11:05:07 2015 francois guergadic
** Last update Sat Feb 21 11:11:41 2015 francois guergadic
*/

#include "allum1.h"

void    remove_tab(t_cursor *cursor, char **_tab)
{
  int   i;
  int   j;

  i = cursor->y;
  j = 0;
  while (_tab[i][j])
    {
      if (j >= cursor->x + cursor->l && cursor->l < 0 && j <= cursor->x)
        _tab[i][j] = ' ';
      else if (j >= cursor->x && j <= cursor->x + cursor->l && cursor->l >= 0)
        _tab[i][j] = ' ';
      j++;
    }
}

int     smth_to_rm(t_cursor *cursor, char **_tab)
{
  int   i;
  int   j;

  i = cursor->y;
  j = 0;
  if (cursor->select == 0)
    return (0);
  while (_tab[i][j])
    {
      if (j >= cursor->x + cursor->l && cursor->l < 0 &&
	  j <= cursor->x && _tab[i][j] == '|')
        return (1);
      else if (j >= cursor->x && j <= cursor->x + cursor->l &&
	       cursor->l >= 0 && _tab[i][j] == '|')
        return (1);
      j++;
    }
  return (0);
}

int		suppr(t_cursor *cursor, char **_tab)
{
  if (smth_to_rm(cursor, _tab) != 1)
    return (0);
  remove_tab(cursor, _tab);
  cursor->select = 0;
  cursor->l = 0;
  return (1);
}
