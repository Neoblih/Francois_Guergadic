/*
** my_putstr_blue.c for putchar blue in /home/guerga_a/B1/Prog_Elem/Allum1/aff_function
** 
** Made by francois guergadic
** Login   <guerga_a@epitech.net>
** 
** Started on  Fri Feb 13 20:50:33 2015 francois guergadic
** Last update Fri Feb 13 21:58:54 2015 francois guergadic
*/

#include "allum1.h"

void	my_pc_b(char c)
{
  write(1, "\033[1m", 5);
  write(1, "\033[36m", 6);
  write(1, &c, 1);
  write(1, "\033[0m", 5);
}

void	my_putstr_blue(char *s)
{
  int	i;

  i = 0;
  while (s[i])
    {
      my_pc_b(s[i]);
      i++;
    }
}
