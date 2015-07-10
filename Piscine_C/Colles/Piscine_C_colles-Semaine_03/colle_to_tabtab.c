/*
** colle_to_tabtab.c for str[] to str[][] in /home/guerga_a/Colles/Piscine_C_colles-Semaine_03
** 
** Made by francois guergadic
** Login   <guerga_a@epitech.net>
** 
** Started on  Sat Oct 25 17:18:41 2014 francois guergadic
** Last update Sun Oct 26 14:58:42 2014 francois guergadic
*/

#include <stdlib.h>

char	**str_to_tab(char *str, int height, int length)
{
  int	i;
  int	j;
  char  **dest;

  i = 0;
  j = 0;
  dest = malloc(height * sizeof(char*));
  if (dest == NULL)
    return (NULL);
  while (j < height && str[i + (length * j) + j])
    {
      dest[j] = malloc(length * sizeof(char));
      if (dest[j] == NULL)
	return (NULL);
      while (i < length && str[i + (length * j) + j])
	{
	  dest[j][i] = str[i + (length * j) + j];
	  i = i + 1;
	}
      i = 0;
      j = j + 1;
    }
  dest[j] = NULL;
  return (dest);
}

int     my_show_wordtab(char **tab)
{
  int   i;

  i = 0;
  while (tab[i])
    {
      my_putstr(tab[i]);
      my_putchar('\n');
      i = i + 1;
    }
}
