/*
** tools.c for tools in /home/guerga_a/Piscine/SBMLparser/idflag
** 
** Made by francois guergadic
** Login   <guerga_a@epitech.net>
** 
** Started on  Tue Jun 16 09:51:24 2015 francois guergadic
** Last update Tue Jun 16 09:56:23 2015 francois guergadic
*/

#include <stdlib.h>
#include <stdio.h>
#include "SBMLparser.h"

void	aff_stoi(int i, char *str, int n)
{
  int	j;
  char	temp[200];

  while (str[i])
    {
      j = 0;
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
          if (n > 0)
            printf("+ ");
          printf("%i ", atoi(temp));
          break;
        }
      i--;
    }
}

int	aff_compound(char *str)
{
  int	i;
  int	j;
  char	temp[200];

  i = 9;
  j = 0;
  if (my_strncmp(str, "species=", 8) == 0)
    {
      while (str[i] != '\"')
        {
          temp[j] = str[i];
          j++;
          i++;
        }
      temp[j] = '\0';
      printf("%s ", temp);
      return (1);
    }
  return (0);
}

void	aff_arrow(char *str, int i)
{
  while (str[i])
    {
      if (my_strncmp(&str[i], "true", 4) == 0)
        {
          printf("<-> ");
          break;
        }
      else if (my_strncmp(&str[i], "false", 5) == 0)
        {
          printf("-> ");
          break;
        }
      i--;
    }
}

int	aff_smth(char *str)
{
  if (my_strncmp(str, "species=", 8) == 0)
    return (1);
  return (0);
}
