/*
** comp_id.c for comp_id in /home/guerga_a/Piscine/SBMLparser/idflag
** 
** Made by francois guergadic
** Login   <guerga_a@epitech.net>
** 
** Started on  Mon Jun 15 16:16:19 2015 francois guergadic
** Last update Wed Jun 17 12:47:05 2015 francois guergadic
*/

#include <stdio.h>
#include "SBMLparser.h"

void	aff_p_e(char *str)
{
  int	i;
  int	n;

  n = 0;
  i = 0;
  while (str[i] && my_strncmp(&str[i], "<listOfProducts>", 16) == 1)
    i++;
  while (str[i] && my_strncmp(&str[i], "</listOfProducts>", 17) == 1)
    {
      if (aff_smth(&str[i]) == 1)
	aff_stoi(i, str, n);
      n+=aff_compound(&str[i]);
      i++;
    }
  printf("\n");
}

void	aff_r_e(char *str)
{
  int	i;
  int	n;

  n = 0;
  i = 0;
  while (str[i] && my_strncmp(&str[i], "</listOfReactants>", 18) == 1)
    {
      if (aff_smth(&str[i]) == 1)
	aff_stoi(i, str, n);
      n+=aff_compound(&str[i]);
      i++;
    }
}

void	aff_products_e(char *id, char *str)
{
  int	i;
  int	n;

  i = 0;
  n = 0;
  while (str[i])
    {
      if (my_strncmp(&str[i], "id=", 3) == 0 &&
          my_strncmp(&str[i + 4], id, my_strlen(id)) == 0 &&
          str[i + 4 + my_strlen(id)] == '\"')
        {
          n++;
          aff_p_e(&str[i + 4 + my_strlen(id)]);
          i = i + 4 + my_strlen(id);
	  break;
	}
      i++;
    }
}

void	aff_reactants_e(char *id, char *str)
{
  int	i;

  i = 0;
  while (str[i])
    {
      if (my_strncmp(&str[i], "id=", 3) == 0 &&
          my_strncmp(&str[i + 4], id, my_strlen(id)) == 0 &&
          str[i + 4 + my_strlen(id)] == '\"')
        {
          aff_r_e(&str[i + 4 + my_strlen(id)]);
          i = i + 4 + my_strlen(id);
	  break;
        }
      i++;
    }
  aff_arrow(str, i);
}

void	aff_reaction_e(char *id, char *str)
{
  aff_reactants_e(id, str);
  aff_products_e(id, str);
}
