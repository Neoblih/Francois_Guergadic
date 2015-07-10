/*"
** my_str_to_tab.c for str_to_tab in /home/guerga_a/Igraph
** 
** Made by francois guergadic
** Login   <guerga_a@epitech.net>
** 
** Started on  Mon Oct 27 15:11:00 2014 francois guergadic
** Last update Sun Dec  7 10:30:59 2014 francois guergadic
*/

#include <stdlib.h>
#include "./include/fdf.h"

int	get_word_number(char *str)
{
  int	i;
  int	count;

  i = 0;
  count = 1;
  while (str[i])
    {
      if (str[i] == ' ')
	{
	  count = count + 1;
	}
      i = i + 1;
    }
  return (count);
}

int	get_next_word_len(char *str)
{
  int	i;

  i = 0;
  while (str[i] && str[i] != ' ')
    {
      i = i + 1;
    }
  return (i);
}

char	**my_str_to_tab(char *str)
{
  char	**dest;
  int	i;
  int	j;
  int	k;
  int	l;

  i = 0;
  k = 0;
  l = 0;
  if ((dest = malloc((get_word_number(str) + 1) * sizeof(char*))) == NULL)
    return (NULL);
  while	(i < get_word_number(str))
    {
      j = 0;
      if ((dest[i] = malloc((get_next_word_len(&str[l]) + 1) * sizeof(char)))
	  == NULL)
	return (NULL);
      while (j < get_next_word_len(&str[l]))
	{
	  dest[i][j] = str[k];
	  k = k + 1;
	  j = j + 1;
	}
      dest[i][j] = '\0';
      k = k + 1;
      l = k;
      i = i + 1;
    }
  dest[i] = NULL;
  return (dest);
}
