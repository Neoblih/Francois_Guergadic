/*
** my_str_to_wordtab.c for my_str_to_word_tab in /home/guerga_a/rendu/Missing
** 
** Made by francois guergadic
** Login   <guerga_a@epitech.net>
** 
** Started on  Thu Oct 23 10:41:39 2014 francois guergadic
** Last update Thu Oct 23 12:59:03 2014 francois guergadic
*/

#include <stdlib.h>
#include "my.h"

char	**my_str_to_wordtab(char *str)
{
  char	**dest;
  char	*tmp;
  int	i;
  int	j;
  int	k;
  int	in_word;

  j = 0;
  i = 0;
  k = 0;
  in_word = 0;
  dest = malloc(50 * sizeof(char*));
  tmp = malloc(100 * sizeof(char));
  while (str[i])
    {
      if ((str[i] > 64 && str[i] < 91) || (str[i] > 96 && str[i] < 123))
        in_word = 1;
      else if (in_word == 1)
	{
	  dest[k] = malloc(100 * sizeof(char));
	  my_strcpy(dest[k], tmp);
	  free(tmp);
	  j = 0;
	  in_word = 0;
	  k = k + 1;
	  tmp = malloc(100 * sizeof(char));
	}
      if (in_word == 1)
	{
	  tmp[j] = str[i];
	  j = j + 1;
	}
      i = i + 1;
    }
  if (in_word == 1)
    {
      dest[k] = malloc(100 * sizeof(char));
      my_strcpy(dest[k], tmp);
      free(tmp);
    }
  return (dest);
}
