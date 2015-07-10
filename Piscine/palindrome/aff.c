/*
** aff.c for aff.c in /home/guerga_a/Piscine/palindrome
**
** Made by francois guergadic
** Login   <guerga_a@epitech.net>
**
** Started on  Fri Jun 26 11:12:13 2015 francois guergadic
** Last update Sat Jun 27 17:02:51 2015 francois guergadic
*/

#include "palindrome.h"

void	aff_it(int n, int i, int pal, int base)
{
  printf("%i donne %i en %i itération(s) (en base %i)\n", n, pal, i, base);
}

int	aff_error(char *str, char c)
{
  fprintf(stdout, "%s\n", str);
  if (c == 'e')
    exit(0);
  return (0);
}
