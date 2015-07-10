/*
** my_show_wordtab.c for my_show_wordtab in /home/guerga_a/rendu/Missing
** 
** Made by francois guergadic
** Login   <guerga_a@epitech.net>
** 
** Started on  Thu Oct 23 12:14:14 2014 francois guergadic
** Last update Thu Oct 23 12:22:53 2014 francois guergadic
*/

#include <stdlib.h>
#include "my.h"

char	**my_str_to_wordtab(char *str);

int	my_show_wordtab(char **tab)
{
  int	i;

  i = 0;
  while (tab[i])
    {
      my_putstr(tab[i]);
      my_putchar('\n');
      i = i + 1;
    }
}

int	main(int ac, char **av)
{
  my_show_wordtab(my_str_to_wordtab(av[1]));
}
