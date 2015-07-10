/*
** reverse.c for reverse in /home/guerga_a/Piscine/FASTAtools/part4
**
** Made by francois guergadic
** Login   <guerga_a@epitech.net>
**
** Started on  Wed Jun 24 12:26:53 2015 francois guergadic
** Last update Thu Jun 25 09:36:13 2015 francois guergadic
*/

#include "FASTAtools.h"

int	my_strstr_6(char *str)
{
  int	i;

  i = 0;
  while (str[i] && str[i + 1] && str[i + 2])
    {
      if (strncmp(&str[i], "TAA", 3) == 0 ||
	  strncmp(&str[i], "TGA", 3) == 0 ||
	  strncmp(&str[i], "TAG", 3) == 0)
	return (1);
      i+=3;
    }
  return (0);
}

int	my_aff_6(char *str)
{
  int	i;

  i = 0;
  if (strlen(str) < 6)
    return (1);
  if (my_strstr_6(str) == 0)
    return (1);
  if (strncmp(&str[i], "ATG", 3) == 0)
    {
      while (strncmp(&str[i], "TAA", 3) != 0 &&
	     strncmp(&str[i], "TGA", 3) != 0 &&
	     strncmp(&str[i], "TAG", 3) != 0)
	{
	  aff_acide(&str[i]);
	  i+=3;
	}
      printf("\n");
    }
  return (0);
}

void	aff_seq_6(char **tab)
{
  int	i;
  int	j;

  i = 0;
  while (tab[i])
    {
      j = 0;
      while (tab[i][j])
	{
	  my_aff_6(&tab[i][j]);
	  j++;
	}
      i++;
    }
}

void	part_6()
{
  char	*str;
  char	**seq_tab;

  str = my_read();
  seq_tab = create_seq_tab(str);
  aff_seq_6(seq_tab);
  free(str);
  free_tab(seq_tab);
}
