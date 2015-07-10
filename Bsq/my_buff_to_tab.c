/*
** colle_to_tabtab.c for str[] to str[][] in /home/guerga_a/Colles/Piscine_C_colles-Semaine_03
** 
** Made by francois guergadic
** Login   <guerga_a@epitech.net>
** 
** Started on  Sat Oct 25 17:18:41 2014 francois guergadic
** Last update Sat Jan 17 11:33:07 2015 francois guergadic
*/

#include <stdlib.h>
#include "my.h"

char    **buff_to_tab(char *str, int height, int length);

int     tab_length(char *tab)
{
  int   i;

  i = 0;
  while (tab[i] && tab[i] != '\n')
    i = i + 1;
  return (i);
}

int     tab_height(char *tab)
{
  int   i;
  int   count;

  count = 0;
  i = 0;
  while (tab[i])
    {
      if (tab[i] == '\n')
        count++;
      i++;
    }
  return (count);
}

char	**my_buff_to_tab(char *str)
{
  return (buff_to_tab(str, tab_height(str), tab_length(str)));
}

char	**buff_to_tab(char *str, int height, int length)
{
  int	i;
  int	j;
  char  **dest;

  i = 0;
  j = 0;
  if ((dest = malloc((height + 1) * sizeof(char*))) == NULL)
    return (NULL);
  while (j < height && str[i + (length * j) + j])
    {
      if ((dest[j] = malloc((length + 1) * sizeof(char))) == NULL)
	return (NULL);
      while (i < length && str[i + (length * j) + j])
        {
          dest[j][i] = str[i + (length * j) + j];
          i = i + 1;
        }
      dest[j][i] = '\0';
      i = 0;
      j = j + 1;
    }
  dest[j] = NULL;
  return (dest);
}
