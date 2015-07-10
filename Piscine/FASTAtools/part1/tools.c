/*
** tools.c for tools in /home/guerga_a/Piscine/FASTAtools
**
** Made by francois guergadic
** Login   <guerga_a@epitech.net>
**
** Started on  Wed Jun 24 10:37:53 2015 francois guergadic
** Last update Wed Jun 24 11:52:38 2015 francois guergadic
*/

#include "FASTAtools.h"

int	my_select(char c)
{
  if (c == 'A' || c == 'a' ||
      c == 'T' || c == 't' ||
      c == 'G' || c == 'g' ||
      c == 'C' || c == 'c' ||
      c == 'N' || c == 'n')
    return (1);
  else
    return (0);
}

void	part_1()
{
  char	*str;
  char	**id_tab;
  char	**seq_tab;

  str = my_read();
  id_tab = create_id_tab(str);
  seq_tab = create_seq_tab(str);
  free(str);
  aff_fasta(id_tab, seq_tab);
  free_tab(id_tab);
  free_tab(seq_tab);
}
