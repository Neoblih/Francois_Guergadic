/*
** prerequis.c for strtowordtab in /home/guerga_a/Piscine
** 
** Made by francois guergadic
** Login   <guerga_a@epitech.net>
** 
** Started on  Mon Jun 15 09:03:17 2015 francois guergadic
** Last update Mon Jun 15 12:39:49 2015 francois guergadic
*/

#include <stdlib.h>
#include <stdio.h>

int	is_alph(char c)
{
  if (c >= '0' && c <= '9')
    return (1);
  if (c >= 'a' && c <= 'z')
    return (1);
  if (c >= 'A' && c <= 'Z')
    return (1);
  return (0);
}

int	count_word(char *str)
{
  int	i;
  int	count;

  i = 0;
  count = 1;
  while (str[i] && str[i + 1])
    {
      if (is_alph(str[i]) == 0 && is_alph(str[i + 1]) == 1)
	count ++;
      i++;
    }
 return (count);
}

int	word_len(char *str)
{
  int	i;

  i = 0;
  if (str != NULL)
    {
      while (str[i])
	{
	  if (is_alph(str[i]) == 0)
	    return (i);
	  i++;
	}
    }
  return (i);
}

char	**my_strtowordtab_synthese(char *str)
{
  int	i;
  int	j;
  int	k;
  char	**tab;

  if (str == NULL)
    return (NULL);
  i = 0;
  j = 0;
  if ((tab = malloc(sizeof(char*) * (count_word(str) + 1))) == 0)
    return (NULL);
  while (str[j])
    {
      k = 0;
      if ((tab[i] = malloc(sizeof(char) * (word_len(&str[j]) + 1))) == NULL)
	return (NULL);
      while (str[j] && is_alph(str[j]) == 1)
	tab[i][k++] = str[j++];
      tab[i++][k] = '\0';
      while (str[j] && is_alph(str[j]) == 0)
	j++;
    }
  tab[i] = NULL;
  return (tab);
}
