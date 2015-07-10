/*
** my_split.c for split in /home/guerga_a/Piscine/FASTAtools/part1
**
** Made by francois guergadic
** Login   <guerga_a@epitech.net>
**
** Started on  Wed Jun 24 09:59:02 2015 francois guergadic
** Last update Wed Jun 24 12:19:09 2015 francois guergadic
*/

#include "FASTAtools.h"

char	my_maj2(char c)
{
  if (c == 't' || c == 'T')
    return ('U');
  if (c >= 'a' && c <= 'z')
    return (c - 'a' + 'A');
  return (c);
}

char	**create_ARN_tab(char *str)
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
	    tab[j][k++] = my_maj2(str[i - 1]);
	tab[j][k] = '\0';
	j++;
      }
    else
      while (str[i] && str[i++] != '\n');
  tab[j] = NULL;
  return (tab);
}

void	part_2()
{
  char	*str;
  char	**id_tab;
  char	**seq_tab;

  str = my_read();
  id_tab = create_id_tab(str);
  seq_tab = create_ARN_tab(str);
  free(str);
  aff_fasta(id_tab, seq_tab);
  free_tab(id_tab);
  free_tab(seq_tab);
}
