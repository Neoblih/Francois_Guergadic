/*
** my_split.c for split in /home/guerga_a/Piscine/FASTAtools/part1
**
** Made by francois guergadic
** Login   <guerga_a@epitech.net>
**
** Started on  Wed Jun 24 09:59:02 2015 francois guergadic
** Last update Thu Jun 25 15:55:52 2015 francois guergadic
*/

#include "FASTAtools.h"

int	id_number(char *str)
{
  int	i;
  int	count;

  count = (i = 0);
  while (str[i])
    {
      if (str[i] == '>')
	count++;
      i++;
    }
  if (count < 2)
    {
      fprintf(stdout, "Usage : ./FASTAtools option [k]\n");
      exit(1);
    }
  return (count);
}

int	id_len(char *str)
{
  int	i;

  i = 0;
  while (str[i])
    {
      if (str[i] == '\n')
	return (i);
      i++;
    }
  return (i);
}

int	seq_len(char *str)
{
  int	i;
  i = 0;
  while (str[i])
    {
      if (str[i] == '>')
	return (i);
      i++;
    }
  return (i);
}

char	**create_id_tab(char *str)
{
  char	**tab;
  int	i;
  int	j;
  int	k;

  if ((tab = malloc(sizeof(char*) * (id_number(str) + 1))) == NULL)
    return (NULL);
  i = (j = 0);
  while (str[i])
    {
      if (str[i] == '>')
	{
	  if ((tab[j] = malloc(sizeof(char) * (id_len(&str[i]) + 1))) == NULL)
	    return (NULL);
	  k = 0;
	  while (str[i] && str[i] != '\n')
	    tab[j][k++] = str[i++];
	  tab[j][k] = '\0';
	  j++;
	}
      else
	i++;
    }
  tab[j] = NULL;
  return (tab);
}

char	**create_seq_tab(char *str)
{
  char	**tab;
  int	i;
  int	j;
  int	k;

  i = (j = 0);
  if ((tab = malloc(sizeof(char*) * (id_number(str) + 1))) == NULL)
    return (NULL);
  while (str[i])
    if (str[i] != '>')
      {
	if ((tab[j] = malloc(sizeof(char) * (seq_len(&str[i]) + 1))) == NULL)
	  return (NULL);
	k = 0;
	while (str[i] && str[i++] != '>')
	  if (my_select(str[i - 1]) == 1)
	    tab[j][k++] = my_maj(str[i - 1]);
	tab[j][k] = '\0';
	j++;
      }
    else
      while (str[i] && str[i++] != '\n');
  tab[j] = NULL;
  return (tab);
}
