/*
** comp_id.c for comp_id in /home/guerga_a/Piscine/SBMLparser/idflag
** 
** Made by francois guergadic
** Login   <guerga_a@epitech.net>
** 
** Started on  Mon Jun 15 16:16:19 2015 francois guergadic
** Last update Wed Jun 17 15:01:26 2015 francois guergadic
*/

#include <stdio.h>
#include <stdlib.h>
#include "SBMLparser.h"

int	nb_compar(char *id, char *str)
{
  int   i;
  int   n;

  i = 0;
  n = 0;
  while (str[i])
    {
      if (my_strncmp(&str[i], "species compartment=", 20) == 0 &&
          my_strncmp(&str[i + 21], id, my_strlen(id)) == 0 &&
          str[i + 21 + my_strlen(id)] == '\"')
        {
          n++;
          i = i + 21 + my_strlen(id);
        }
      i++;
    }
  return (n);
}

int	get_comp_len(char *str)
{
  int   i;
  int   j;

  i = 0;
  while (str[i])
    {
      j = 0;
      if (my_strncmp(&str[i], "name=", 5) == 0)
        {
          i = i + 6;
          while (str[i] != '\"')
            {
              j++;
              i++;
            }
	  return (j);
        }
      i++;
    }
  return (0);
}

char	*feed_comp(char *str, char *dest)
{
  int	i;
  int	j;

  i = 0;
  while (str[i])
    {
      j = 0;
      if (my_strncmp(&str[i], "name=", 5) == 0)
        {
          i = i + 6;
          while (str[i] != '\"')
            {
              dest[j] = str[i];
              j++;
              i++;
            }
          dest[j] = '\0';
	  return (dest);
        }
      i++;
    }
  return (NULL);
}

int	my_aff_comp(char **tab, char *id, int n)
{
  int	i;

  i = 0;
  tab = sort_tab(tab);
  if (n == 0)
    return (1);
  printf("List of species in compartment %s\n", id);
  while (tab[i])
    {
      printf("----->%s\n", tab[i]);
      i++;
    }
  return (0);
}

void	aff_compartment(char *id, char *str)
{
  int	i;
  int	n;
  char	**comp_list;

  i = 0;
  n = 0;
  if ((comp_list = malloc(sizeof(char*) * (nb_compar(id, str) + 1))) == NULL)
    exit(1);
  while (str[i])
    {
      if (my_strncmp(&str[i], "species compartment=", 20) == 0 &&
          my_strncmp(&str[i + 21], id, my_strlen(id)) == 0 &&
          str[i + 21 + my_strlen(id)] == '\"')
        {
          if ((comp_list[n] = malloc(sizeof(char) *
				     (get_comp_len(&str[i]) + 1))) == NULL)
	    exit(1);
          feed_comp(&str[i], comp_list[n++]);
        }
      i++;
    }
  comp_list[n] = NULL;
  if ((my_aff_comp(comp_list, id, n)) == 1)
    aff_any(str);
  free_tab(comp_list);
}
