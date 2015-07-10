/*
** my_str_to_wordtab.c for my_str_to_wordtab in /home/guerga_a/B1/Sys_Unix/PSU_2014_minishell1
** 
** Made by francois guergadic
** Login   <guerga_a@epitech.net>
** 
** Started on  Wed Jan 21 11:57:48 2015 francois guergadic
** Last update Wed Jan 21 14:09:53 2015 francois guergadic
*/

#include <stdlib.h>

int	word_len(char *str)
{
  int	n;

  n = 0;
  while (str[n] != '\0' && str[n] != ' ' && str[n] != '\n')
    n++;
  return (n);
}

int	word_count(char *str)
{
  int	cmp;
  int	nb;

  cmp = 0;
  nb = 0;
  while (str[nb] != '\0' && str[nb] != '\n')
    {
      if (str[nb] == ' ' && str[nb + 1] != '\0')
	cmp++;
      nb++;
    }
  return (cmp);
}

char	**my_str_to_wordtab(char *str)
{
  char	**tab;
  int	i;
  int	j;
  int	k;

  i = 0;
  j = 0;
  k = 0;
  if ((tab = malloc(((word_count(str) + 2)) * sizeof(*tab))) == NULL)
    return (NULL);
  while (str[i] != '\0')
    {
      if (str[i] == ' ')
	{
	  i++;
	  j++;
	  k = 0;
	}
      if ((tab[j] = malloc(((word_len(str + i) + 1)) * sizeof(**tab))) == NULL)
	return (NULL);
      while (str[i] != ' ' && str[i])
	tab[j][k++] = str[i++];
      tab[j][k] = '\0';
    }
  tab[j + 1] = NULL;
  return (tab);
}
