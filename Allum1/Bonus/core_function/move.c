/*
** move.c for move in /home/guerga_a/B1/Prog_Elem/Allum1
** 
** Made by francois guergadic
** Login   <guerga_a@epitech.net>
** 
** Started on  Tue Feb  3 13:45:48 2015 francois guergadic
** Last update Fri Feb 13 21:36:07 2015 francois guergadic
*/

#include "allum1.h"

void    top(t_cursor *cursor)
{
  if (cursor->y > 0 && cursor->select == 0)
    cursor->y--;
}

void    left(t_cursor *cursor)
{
  if (cursor->x > 0 && cursor->select == 0)
    cursor->x--;
  else if (cursor->select == 1)
    {
      if (cursor->x + cursor->l > 0)
        cursor->l--;
    }
}

void    bottom(t_cursor *cursor, int r)
{
  if (cursor->y < r && cursor->select == 0)
    cursor->y++;
}

void    right(t_cursor *cursor, int r)
{
  if (cursor->x < (r * 2) && cursor->select == 0)
    cursor->x++;
  else if (cursor->select == 1)
    {
      if (cursor->x + cursor->l < (r * 2))
        cursor->l++;
    }
}

int    move_cursor(t_cursor *cursor, int r, char *buff, char **_tab)
{
  if (buff[0] == 27 && buff[1] == 91 && buff[2] == 65)
    top(cursor);
  else if (buff[0] == 27 && buff[1] == 91 && buff[2] == 66)
    bottom(cursor, r - 1);
  else if (buff[0] == 27 && buff[1] == 91 && buff[2] == 67)
    right(cursor, r - 1);
  else if (buff[0] == 27 && buff[1] == 91 && buff[2] == 68)
    left(cursor);
  else if (buff[0] == ' ')
    select(cursor);
  else if (buff[0] == '\n')
    return (suppr(cursor, r, _tab));
  return (0);
}
