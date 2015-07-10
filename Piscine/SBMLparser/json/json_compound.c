/*
** json_compound.c for compound in /home/guerga_a/Piscine/SBMLparser/json
** 
** Made by francois guergadic
** Login   <guerga_a@epitech.net>
** 
** Started on  Tue Jun 16 11:08:42 2015 francois guergadic
** Last update Wed Jun 17 18:14:09 2015 francois guergadic
*/

#include <stdio.h>
#include <stdlib.h>
#include "SBMLparser.h"

void	aff_j_compartment(char *str, char *id)
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

void	aff_j_species(char *str, char *id)
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
            printf("\t\"listOfSpecies\": [\n");
          n++;
          aff_species_in_json(str, i);
        }
      i++;
    }
  if (n > 0)
    printf("\t],\n");
}

void	aff_j_reaction(char *str, char *id)
{
  int	i;
  int	n;

  n = 0;
  i = 0;
  while (str[i])
    {
      if (my_strncmp(&str[i], "species=\"", 9) == 0 &&
          my_strncmp(&str[i + 9], id, my_strlen(id)) == 0)
        {
          if (n == 0)
            printf("\t\"listOfReactions\": [\n");
          n++;
          aff_reaction_in_json(str, i);
        }
      i++;
    }
  if (n > 0)
    printf("\t]\n");
}

void	json_compound(char *str, char *id)
{
  int	i;

  i = 0;
  while (str[i])
    {
      if (my_strncmp(&str[i], "id=\"", 4) == 0 &&
          my_strncmp(&str[i + 4], id, my_strlen(id)) == 0 &&
	  str[i + 4 + my_strlen(id)] == '\"')
	{
	  printf("{\n");
	  aff_j_compartment(str, id);
	  aff_j_species(str, id);
	  aff_j_reaction(str, id);
	  printf("}\n");
	  exit(0);
	}
      i++;
    }
  printf("Fichier incorrect\n");
}
