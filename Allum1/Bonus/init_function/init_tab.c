/*
** aff_pyr.c for aff_pyr in /home/guerga_a/B1/Prog_Elem/Allum1
** 
** Made by francois guergadic
** Login   <guerga_a@epitech.net>
** 
** Started on  Mon Feb  2 13:37:53 2015 francois guergadic
** Last update Fri Feb 13 20:49:25 2015 francois guergadic
*/

#include "allum1.h"

void	fill_line(char *line, int r, int i)
{
  int	j;
  int	k;

  j = i;
  k = 0;
  while (j++ < r)
    my_strcat(line, " ");
  while (k++ < (i * 2) - 1)
    my_strcat(line, "|");
  while ((j++ + k - i - 1) < (r * 2))
    my_strcat(line, " ");
}

char	**init_tab(int r)
{
  char	**_tab;
  int	i;

  i = 0;
  if ((_tab = malloc(sizeof(char*) * (r + 1))) == NULL)
    return (NULL);
  while (i < r)
    {
      if ((_tab[i] = malloc(sizeof(char) * (r * 2))) == NULL)
	return (NULL);
      _tab[i][0] = '\0';
      fill_line(_tab[i], r, i + 1);
     i++;
    }
  _tab[i] = NULL;
  return (_tab);
}
