/*
** tab_sort.c for sort in /home/guerga_a/Piscine/FASTAtools/part4
**
** Made by francois guergadic
** Login   <guerga_a@epitech.net>
**
** Started on  Wed Jun 24 16:22:54 2015 francois guergadic
** Last update Wed Jun 24 18:14:26 2015 francois guergadic
*/

#include "FASTAtools.h"

int	my_strrealcmp(char *s1, char *s2)
{
  int	i;

  i = 0;
  while (s1[i] && s2[i])
    {
      if (s1[i] > s2[i])
	return (1);
      if (s1[i] < s2[i])
	return (-1);
      i++;
    }
  if (strlen(s1) > strlen(s2))
    return (1);
  if (strlen(s1) < strlen(s2))
    return (-1);
  return (0);
}

char	**sort_tab(char **tab)
{
  int	i;
  char	*tmp;

  i = 0;
  while (tab[i] && tab[i + 1])
    {
      if (my_strrealcmp(tab[i], tab[i + 1]) == 1)
        {
          while (tab[i] && tab[i + 1])
            {
	      tmp = tab[i];
              tab[i] = tab[i + 1];
	      tab[i + 1] = tmp;
	      i++;
            }
          i = -1;
        }
      i++;
    }
  return (tab);
}

char	**remove_double(char **tab)
{
  int	i;

  i = 0;
  while (tab[i] && tab[i + 1])
    {
      if (strcmp(tab[i], tab[i + 1]) == 0)
        {
          while (tab[i] && tab[i + 1])
            {
              tab[i] = tab[i + 1];
              i++;
            }
	  tab[i] = NULL;
          i = -1;
        }
      i++;
    }
  return (tab);
}
