/*
** comp_id.c for comp_id in /home/guerga_a/Piscine/SBMLparser/idflag
** 
** Made by francois guergadic
** Login   <guerga_a@epitech.net>
** 
** Started on  Mon Jun 15 16:16:19 2015 francois guergadic
** Last update Wed Jun 17 18:11:13 2015 francois guergadic
*/

#include <stdio.h>
#include <stdlib.h>
#include "SBMLparser.h"

int     reactants(char *str, int i)
{
  while (str[i])
    {
      if (my_strncmp(&str[i], "listOfReactants", 15) == 0)
	return (1);
      if (my_strncmp(&str[i], "listOfProducts", 14) == 0)
	return (0);
      i--;
    }
  return (0);
}

void	aff_spec(char *str, int i)
{
  int	j;
  char	temp[200];

  while (str[i])
    {
      j = 0;
      if (my_strncmp(&str[i], "Reaction", 8) == 0)
	{
	  while (str[i] != '\"')
	    {
	      temp[j] = str[i];
	      j++;
	      i++;
	    }
	  temp[j] = '\0';
	  printf("----->%s", temp);
	  break;
	}
      i--;
    }
}

void	aff_quant(char *str, int i)
{
  int   j;
  char  temp[200];

  while (str[i])
    {
      j= 0;
      if (my_strncmp(&str[i], "speciesReference stoichiometry=", 31) == 0)
        {
	  i = i + 32;
          while (str[i] != '\"')
            {
              temp[j] =str[i];
              j++;
              i++;
            }
          temp[j] = '\0';
          printf(" (%i)\n", atoi(temp));
          break;
        }
      i--;
    }
}

void	aff_species(char *id, char *str)
{
  int	i;
  int	n;

  i = 0;
  n = 0;
  while (str[i])
    {
      if (my_strncmp(&str[i], "species=", 8) == 0 &&
          my_strncmp(&str[i + 9], id, my_strlen(id)) == 0 &&
          str[i + 9 + my_strlen(id)] == '\"' &&
	  reactants(str, i) == 1)
        {
          n++;
          if (n == 1)
            printf("List of reactions consuming species %s (quantities)\n", id);
          aff_spec(str, i);
	  aff_quant(str, i);
        }
      i++;
    }
  if (n == 0)
    printf("Fichier incorrect\n");
}
