/*
** json_reaction_tools.c for tools in /home/guerga_a/Piscine/SBMLparser/json
** 
** Made by francois guergadic
** Login   <guerga_a@epitech.net>
** 
** Started on  Tue Jun 16 15:24:39 2015 francois guergadic
** Last update Wed Jun 17 12:19:38 2015 francois guergadic
*/

#include <stdio.h>
#include <stdlib.h>
#include "SBMLparser.h"

int	nb_elem(char *str, char *id)
{
  int	i;
  int	count;

  i = 0;
  count = 0;
  while (str[i])
    {
      if (my_strncmp(&str[i], "id=\"", 4) == 0 &&
          my_strncmp(&str[i + 4], id, my_strlen(id)) == 0)
        i++;
      break;
    }
  while (str[i] && my_strncmp(&str[i], "/reaction", 9) != 0)
    {
      if (my_strncmp(&str[i], "species=\"", 9) == 0)
        count++;
      i++;
    }
  return (count);
}

int	get_idlen(char *str)
{
  int	i;

  i = 0;
  while (str[i] && str[i] != '\"')
    i++;
  return (i);
}

char	**species_tab(char *str, char *id)
{
  char	**tab;
  int	i;
  int	j;
  int	k;

  i = 0;
  j = 0;
  if ((tab = malloc(sizeof(char*) * (nb_elem(str, id) + 1))) == NULL)
    return (NULL);
  while (str[i] && my_strncmp(&str[i], "/reaction", 9) != 0)
    {
      k = 0;
      if (my_strncmp(&str[i], "species=\"", 9) == 0)
        {
          i = i + 9;
          if ((tab[j] = malloc(sizeof(char) * get_idlen(&str[i]))) == NULL)
            return (NULL);
          while (str[i] != '\"')
            tab[j][k++] = str[i++];
          tab[j++][k] = '\0';
        }
      i++;
    }
  tab[j] = NULL;
  return (tab);
}
