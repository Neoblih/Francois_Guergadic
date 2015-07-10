/*
** comp_id.c for comp_id in /home/guerga_a/Piscine/SBMLparser/idflag
** 
** Made by francois guergadic
** Login   <guerga_a@epitech.net>
** 
** Started on  Mon Jun 15 16:16:19 2015 francois guergadic
** Last update Wed Jun 17 14:45:08 2015 francois guergadic
*/

#include <stdio.h>
#include <stdlib.h>
#include "SBMLparser.h"

int	my_aff_any(char **tab)
{
  int	i;

  i = 0;
  tab = sort_tab(tab);
  printf("List of species\n");
  while (tab[i])
    {
      printf("----->%s\n", tab[i]);
      i++;
    }
  return (0);
}

int	nb_any(char *str)
{
  int	i;
  int	n;

  i = 0;
  n = 0;
  while (str[i])
    {
      if (my_strncmp(&str[i], "species compartment=\"", 21) == 0)
        {
          n++;
          i = i + 21;
        }
      i++;
    }
  return (n);
}

void	aff_any(char *str)
{
  int	i;
  int	n;
  char	**comp_list;

  i = 0;
  n = 0;
  if ((comp_list = malloc(sizeof(char*) * (nb_any(str) + 1))) == NULL)
    exit(1);
  while (str[i])
    {
      if (my_strncmp(&str[i], "species compartment=\"", 21) == 0)
        {
          i = i + 21;
          if ((comp_list[n] = malloc(sizeof(char) *
                                     (get_comp_len(&str[i]) + 1))) == NULL)
            exit(1);
          feed_comp(&str[i], comp_list[n++]);
        }
      i++;
    }
  comp_list[n] = NULL;
  my_aff_any(comp_list);
  free_tab(comp_list);
}
