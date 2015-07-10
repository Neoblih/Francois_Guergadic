/*
** init_cursor.c for cursor_init in /home/guerga_a/B1/Prog_Elem/Allum1/init_function
** 
** Made by francois guergadic
** Login   <guerga_a@epitech.net>
** 
** Started on  Fri Feb 13 21:42:48 2015 francois guergadic
** Last update Fri Feb 13 21:43:19 2015 francois guergadic
*/

#include "allum1.h"

void    cursor_init(t_cursor *cursor)
{
  cursor->x = 0;
  cursor->y = 0;
  cursor->l = 0;
  cursor->select = 0;
}
