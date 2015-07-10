/*
** json_aff_compartment.c for aff_compartment in /home/guerga_a/Piscine/SBMLparser/json
** 
** Made by francois guergadic
** Login   <guerga_a@epitech.net>
** 
** Started on  Tue Jun 16 11:57:27 2015 francois guergadic
** Last update Wed Jun 17 12:22:02 2015 francois guergadic
*/

#include <stdio.h>
#include <stdlib.h>
#include "SBMLparser.h"

char	*aff_compartment_id(char *str, int i)
{
  char	*result;
  char	temp[200];
  int	j;

  j = 0;
  while (str[i] && my_strncmp(&str[i], "species compartment=\"", 21) == 1)
    i--;
  i = i + 21;
  while (str[i] != '\"')
    {
      temp[j] = str[i];
      i++;
      j++;
    }
  temp[j] = '\0';
  if ((result = malloc(sizeof(char) * j)) == NULL)
    return (NULL);
  result[0] = '\0';
  my_strcat(result, temp);
  printf("%s", temp);
  return (result);
}

void	aff_compartment_name(char *str, int i, char *id)
{
  char	temp[200];
  int	j;

  j = 0;
  while (str[i])
    {
      if (my_strncmp(&str[i], "id=\"", 4) == 0 &&
          my_strncmp(&str[i + 4], id, my_strlen(id)) == 0)
        break;
      i--;
    }
  while (str[i] && my_strncmp(&str[i], "compartment name=\"", 18) == 1)
    i--;
  i = i + 18;
  while (str[i] != '\"')
    {
      temp[j] = str[i];
      i++;
      j++;
    }
  temp[j] = '\0';
  printf("%s", temp);
}

void	aff_compartment_in_json(char *str, int i)
{
  char	*comp_id;

  printf("\t\t{\n\t\t\t\"id\": \"");
  comp_id = aff_compartment_id(str, i);
  printf("\",\n\t\t\t\"name\": \"");
  aff_compartment_name(str, i, comp_id);
  free(comp_id);
  printf("\"\n\t\t}\n");
}
