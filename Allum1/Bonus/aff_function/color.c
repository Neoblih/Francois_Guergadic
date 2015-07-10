/*
** color.c for color.c in /home/guerga_a/B1/Prog_Elem/Allum1
** 
** Made by francois guergadic
** Login   <guerga_a@epitech.net>
** 
** Started on  Mon Feb  2 14:51:02 2015 francois guergadic
** Last update Fri Feb 13 22:06:00 2015 francois guergadic
*/

#include "allum1.h"

void	my_putchar_normal(char c)
{
  write(1, "\033[1m", 5);
  write(1, &c, 1);
  write(1, "\033[0m", 5);
}

void	my_putchar_pos(char c)
{
  if (c == ' ')
    {
      write(1, "\033[46m", 6);
      write(1, " ", 1);
      write(1, "\033[0m", 5);
    }
  else
    {
      write(1, "\033[1m", 5);
      write(1, "\033[36m", 6);
      write(1, &c, 1);
      write(1, "\033[0m", 5);
    }
}

void    my_putchar_select(char c)
{
  if (c == ' ')
    {
      write(1, "\033[0m", 5);
      write(1, " ", 1);
      write(1, "\033[0m", 5);
    }
  else
    {
      write(1, "\033[31m", 6);
      write(1, "\033[1m", 5);
      write(1, &c, 1);
      write(1, "\033[0m", 5);
    }
}

void	my_putstr_normal(char *s)
{
  int	i;

  i = 0;
  while (s[i])
    {
      my_putchar_normal(s[i]);
      i++;
    }
}

void	my_putstr_pos(char *s, t_cursor *cursor)
{
  int	i;

  i = 0;
  while (s[i])
    {
      if (i >= cursor->x + cursor->l && cursor->l < 0 && i <= cursor->x)
        if (cursor->select == 1)
	  my_putchar_select(s[i]);
	else
	  my_putchar_pos(s[i]);
      else if (i >= cursor->x && i <= cursor->x + cursor->l)
	if (cursor->select == 1)
          my_putchar_select(s[i]);
        else
          my_putchar_pos(s[i]);
      else
	my_putchar_normal(s[i]);
      i++;
    }
}
