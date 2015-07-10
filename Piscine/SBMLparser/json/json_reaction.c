/*
** json_compound.c for compound in /home/guerga_a/Piscine/SBMLparser/json
** 
** Made by francois guergadic
** Login   <guerga_a@epitech.net>
** 
** Started on  Tue Jun 16 11:08:42 2015 francois guergadic
** Last update Wed Jun 17 12:19:56 2015 francois guergadic
*/

#include <stdio.h>
#include <stdlib.h>
#include "SBMLparser.h"

void	aff_j_compartment_r(char *str, char *id)
{
  int	i;
  int	n;

  n = 0;
  i = 0;
  while (str[i])
    {
      if (my_strncmp(&str[i], "id=\"", 4) == 0 &&
	  my_strncmp(&str[i + 4], id, my_strlen(id)) == 0)
	{
	  if (n == 0)
	    printf("\t\"listOfCompartments\": [\n");
	  n++;
	  aff_compartment_in_json(str, i);
	}
      i++;
    }
  if (n > 0)
    printf("\t],\n");
}

void	aff_j_species_r(char *str, char *id)
{
  int	i;

  i = 0;
  while (str[i])
    {
      if (my_strncmp(&str[i], "id=\"", 4) == 0 &&
          my_strncmp(&str[i + 4], id, my_strlen(id)) == 0)
        {
          aff_species_in_json(str, i);
        }
      i++;
    }
}

void	aff_j_reaction_r(char *str, char *id)
{
  int	i;
  int	n;

  n = 0;
  i = 0;
  while (str[i])
    {
      if (my_strncmp(&str[i], "id=\"", 4) == 0 &&
          my_strncmp(&str[i + 4], id, my_strlen(id)) == 0)
        {
	  if (n == 0)
            printf("\t\"listOfReaction\": [\n");
          n++;
	  aff_reaction_in_json(str, i);
        }
      i++;
    }
  if (n > 0)
    printf("\t]\n");
}

void	json_reaction(char *str, char *id)
{
  char	**spec_name;
  int	i;

  i = 0;
  spec_name = species_tab(str, id);
  printf("{\n");
  while (spec_name[i])
    {
      if (i == 0)
	printf("\t\"listOfSpecies\": [\n");
      aff_j_species_r(str, spec_name[i]);
      i++;
    }
  printf("\t],\n");
  aff_j_reaction_r(str, id);
  printf("}\n");
  free_tab(spec_name);
}
