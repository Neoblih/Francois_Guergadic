/*
** tab_tools.c for tab_tools in /home/guerga_a/Piscine/SBMLparser
** 
** Made by francois guergadic
** Login   <guerga_a@epitech.net>
** 
** Started on  Mon Jun 15 13:45:20 2015 francois guergadic
** Last update Tue Jun 16 14:21:03 2015 francois guergadic
*/

#include <stdlib.h>
#include <stdio.h>
#include "SBMLparser.h"

void	aff_parsing(char **tab)
{
  int	i;
  int	j;
  char	**tmp;

  i = 0;
  while (tab[i])
    {
      j = 1;
      tmp = my_strtowordtab_synthese(tab[i]);
      printf("%s\n", tmp[0]);
      while (tmp[j])
	{
	  printf("----->%s\n", tmp[j]);
	  j++;
	}
      free_tab(tmp);
      i++;
    }
}

char	*sort_str(char *str)
{
  char	**tab;
  int	i;

  i = 1;
  tab = my_strtowordtab_synthese(str);
  sort_tab(&tab[1]);
  str[0] = '\0';
  my_strcat(str, tab[0]);
  while (tab[i])
    {
      my_strcat(str, " ");
      my_strcat(str, tab[i]);
      i++;
    }
  free_tab(tab);
  return (str);
}

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
  if (my_strlen(s1) > my_strlen(s2))
    return (1);
  if (my_strlen(s1) < my_strlen(s2))
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
      if (my_strcmp(tab[i], tab[i + 1]) == 0)
        {
          while (tab[i] && tab[i + 1])
            {
              tab[i] = tab[i + 1];
              i++;
            }
          tab[i] = NULL;
	  free(tab[i + 1]);
          i = -1;
        }
      i++;
    }
  return (tab);
}
