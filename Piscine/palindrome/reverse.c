/*
** reverse.c for reverse in /home/guerga_a/Piscine/palindrome
**
** Made by francois guergadic
** Login   <guerga_a@epitech.net>
**
** Started on  Fri Jun 26 16:27:40 2015 francois guergadic
** Last update Fri Jun 26 17:26:15 2015 francois guergadic
*/

#include "palindrome.h"

int	reverse_flag(char **av)
{
  int	i;

  i = 0;
  while (av[i])
    {
      if (strcmp(av[i], "reverse") == 0)
	return (1);
      i++;
    }
  return (0);
}

int	reverse(int nb, int base)
{
  int	i;

  i = 0;
  while (do_return(i, base) < nb)
    {
      if (get_pal(i, base) == nb)
	{
	  return (i);
	}
      i++;
    }
  if (get_pal(i, base) == nb)
    return (i);
  return (0);
}

int	reverse_it(int nb, int base, t_flag *flag)
{
  int	i;

  i = 0;
  while (get_pal(i, base) < nb && do_return(i, base) < nb)
    i++;
  flag = flag;
  if (get_pal(i, base) == nb)
    return (get_it(i, base, flag));
  return (0);
}
