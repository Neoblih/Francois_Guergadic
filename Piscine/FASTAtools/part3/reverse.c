/*
** reverse.c for reverse in /home/guerga_a/Piscine/FASTAtools/part3
**
** Made by francois guergadic
** Login   <guerga_a@epitech.net>
**
** Started on  Wed Jun 24 12:26:53 2015 francois guergadic
** Last update Thu Jun 25 15:05:45 2015 francois guergadic
*/

#include "FASTAtools.h"

char	*my_revstr(char *str)
{
  int	i;
  int	j;
  int	temp;
  int	len;

  j = 0;
  len = (i = strlen(str) - 1);
  while (j < (len / 2) + (len % 2))
    {
      temp = str[i];
      str[i] = str[j];
      str[j] = temp;
      i--;
      j++;
    }
  return (str);
}

char	reverse_letter(char c)
{
  if (c == 'T')
    return ('A');
  if (c == 'A')
    return ('T');
  if (c == 'G')
    return ('C');
  if (c == 'C')
    return ('G');
  return (' ');
}

char	**reverse(char **tab)
{
  int	i;
  int	j;

  i = 0;
  while (tab[i])
    {
      j = 0;
      while (tab[i][j])
	{
	  tab[i][j] = reverse_letter(tab[i][j]);
	  j++;
	}
      tab[i] = my_revstr(tab[i]);
      i++;
    }
  return (tab);
}

void	part_3()
{
  char	*str;
  char	**id_tab;
  char	**seq_tab;

  str = my_read();
  id_tab = create_id_tab(str);
  seq_tab = create_seq_tab(str);
  free(str);
  seq_tab = reverse(seq_tab);
  aff_fasta(id_tab, seq_tab);
  free_tab(id_tab);
  free_tab(seq_tab);
}
