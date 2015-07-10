/*
** pars_id.c for pars in /home/guerga_a/Piscine/SBMLparser
** 
** Made by francois guergadic
** Login   <guerga_a@epitech.net>
** 
** Started on  Mon Jun 15 15:11:25 2015 francois guergadic
** Last update Wed Jun 17 18:10:26 2015 francois guergadic
*/

#include <stdio.h>
#include <stdlib.h>
#include "SBMLparser.h"

int	my_strncmp(char *s1, char *s2, int n)
{
  int	i;

  i = 0;
  while (s1[i] && s2[i] && i < n)
    {
      if (s1[i] != s2[i])
	return (1);
      i++;
    }
  if (i != n)
    return (1);
  return (0);
}

int	get_cat(char *id)
{
  if (my_strncmp(id, "Compound", 8) == 0)
    return (2);
  if (my_strncmp(id, "Reaction", 8) == 0)
    return (3);
  else
    return (1);
}

void	pars_id(char *id, char *str, int e, int json)
{
  if (e == -1)
    {
      printf("Fichier incorrect\n");
      exit(1);
    }
  if (get_cat(id) == 1 && json != 1)
    aff_compartment(id, str);
  else if (get_cat(id) == 2 && json != 1)
    aff_species(id, str);
  else if (get_cat(id) == 3 && e == 0 && json != 1)
    aff_reaction(id, str);
  else if (get_cat(id) == 3 && e == 1 && json != 1)
    aff_reaction_e(id, str);
  else if (get_cat(id) == 1)
    printf("Fichier incorrect\n");
  else if (get_cat(id) == 2)
    json_compound(str, id);
  else if (get_cat(id) == 3)
    printf("Fichier incorrect\n");
}
