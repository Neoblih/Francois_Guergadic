/*
** prerequis.c for strtowordtab in /home/guerga_a/Piscine
** 
** Made by francois guergadic
** Login   <guerga_a@epitech.net>
** 
** Started on  Mon Jun 15 09:03:17 2015 francois guergadic
** Last update Fri Jun 19 15:23:02 2015 francois guergadic
*/

#include <stdlib.h>
#include <stdio.h>

char	*remove_double(char *str)
{
  int	i;

  if (str == NULL)
    return (NULL);
  i = 0;
  if (str[0] == '\n')
    return (remove_double(&str[1]));
  while (str[i] && str[i + 1])
    {
      if (str[i] == '\n' && str[i + 1] == '\n')
	{
	  while (str[i] && str[i + 1])
	    {
	      str[i] = str[i + 1];
	      i++;
	    }
	  str[i] = '\0';
	  i = -1;
	}
      i++;
    }
  return (str);
}

int	is_alph(char c, char c2)
{
  if (c == c2)
    return (0);
  else
    return (1);
}

int	count_word(char *str, char c)
{
  int	i;
  int	count;

  i = 0;
  count = 1;
  while (str[i] && str[i + 1])
    {
      if (is_alph(str[i], c) == 0 && is_alph(str[i + 1], c) == 1)
	count ++;
      i++;
    }
 return (count);
}

int	word_len(char *str, char c)
{
  int	i;

  i = 0;
  if (str != NULL)
    {
      while (str[i])
	{
	  if (is_alph(str[i], c) == 0)
	    return (i);
	  i++;
	}
    }
  return (i);
}

char	**my_str_to_wordtab(char *str, char c)
{
  int	i;
  int	j;
  int	k;
  char	**tab;

  if (str == NULL)
    return (NULL);
  i = 0;
  j = 0;
  if ((tab = malloc(sizeof(char*) * (count_word(str, c) + 1))) == 0)
    return (NULL);
  while (str[j])
    {
      k = 0;
      if ((tab[i] = malloc(sizeof(char) * (word_len(&str[j], c) + 1))) == NULL)
	return (NULL);
      while (str[j] && is_alph(str[j], c) == 1)
	tab[i][k++] = str[j++];
      tab[i++][k] = '\0';
      while (str[j] && is_alph(str[j], c) == 0)
	j++;
    }
  tab[i] = NULL;
  return (tab);
}
