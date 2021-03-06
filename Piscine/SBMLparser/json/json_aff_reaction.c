/*
** json_aff_compartment.c for aff_compartment in /home/guerga_a/Piscine/SBMLparser/json
** 
** Made by francois guergadic
** Login   <guerga_a@epitech.net>
** 
** Started on  Tue Jun 16 11:57:27 2015 francois guergadic
** Last update Wed Jun 17 12:44:14 2015 francois guergadic
*/

#include <stdio.h>
#include <stdlib.h>
#include "SBMLparser.h"

void	aff_reaction_id(char *str, int i)
{
  char	temp[200];
  int	j;

  j = 0;
  while (str[i] && my_strncmp(&str[i], "id=\"", 4) == 1)
    i--;
  i = i + 4;
  while (str[i] != '\"')
    {
      temp[j] = str[i];
      i++;
      j++;
    }
  temp[j] = '\0';
  printf("%s", temp);
}

void	aff_reaction_name(char *str, int i)
{
  char	temp[200];
  int	j;

  j = 0;
  while (str[i] && my_strncmp(&str[i], "name=\"", 6) == 1)
    i--;
  i = i + 6;
  while (str[i] != '\"')
    {
      temp[j] = str[i];
      i++;
      j++;
    }
  temp[j] = '\0';
  printf("%s", temp);
}

void	aff_reaction_reversible(char *str, int i)
{
  char	temp[200];
  int	j;

  j = 0;
  while (str[i] && my_strncmp(&str[i], "reversible=\"", 12) == 1)
    i--;
  i = i + 12;
  while (str[i] != '\"')
    {
      temp[j] = str[i];
      i++;
      j++;
    }
  temp[j] = '\0';
  printf("%s", temp);
}

void    aff_reaction_in_json(char *str, int i)
{
  printf("\t\t{\n\t\t\t\"id\": \"");
  aff_reaction_id(str, i);
  printf("\",\n\t\t\t\"name\": \"");
  aff_reaction_name(str, i);
  printf("\",\n\t\t\t\"reversible\": \"");
  aff_reaction_reversible(str, i);
  printf("\"\n\t\t}\n");
}
