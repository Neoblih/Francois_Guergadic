/*
** comp_id.c for comp_id in /home/guerga_a/Piscine/SBMLparser/idflag
** 
** Made by francois guergadic
** Login   <guerga_a@epitech.net>
** 
** Started on  Mon Jun 15 16:16:19 2015 francois guergadic
** Last update Wed Jun 17 18:09:19 2015 francois guergadic
*/

#include <stdio.h>
#include "SBMLparser.h"

void	aff_p(char *str)
{
  int   i;
  int   j;
  char  temp[200];

  i = 0;
  while (str[i] && my_strncmp(&str[i], "<listOfProducts>", 16) == 1)
    i++;
  while (str[i] && my_strncmp(&str[i], "</listOfProducts>", 17) == 1)
    {
      j = 0;
      if (my_strncmp(&str[i], "species=", 8) == 0)
        {
          i = i + 9;
          while (str[i] != '\"')
            {
              temp[j] = str[i];
              j++;
              i++;
            }
          temp[j] = '\0';
          printf("----->%s\n", temp);
        }
      i++;
    }
}

void	aff_r(char *str)
{
  int	i;
  int	j;
  char	temp[200];

  i = 0;
  while (str[i] && my_strncmp(&str[i], "</listOfReactants>", 18) == 1)
    {
      j = 0;
      if (my_strncmp(&str[i], "species=", 8) == 0)
        {
          i = i + 9;
          while (str[i] != '\"')
            {
              temp[j] = str[i];
              j++;
              i++;
            }
          temp[j] = '\0';
          printf("----->%s\n", temp);
        }
      i++;
    }
}

void	aff_products(char *id, char *str)
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
          if (n == 1)
            printf("List of products of reaction %s\n", id);
          aff_p(&str[i + 4 + my_strlen(id)]);
          i = i + 4 + my_strlen(id);
        }
      i++;
    }
  if (n == 0)
    printf("Fichier incorrect\n");
}

void	aff_reactants(char *id, char *str)
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
          if (n == 1)
            printf("List of reactants of reaction %s\n", id);
          aff_r(&str[i + 4 + my_strlen(id)]);
          i = i + 4 + my_strlen(id);
        }
      i++;
    }
}

void	aff_reaction(char *id, char *str)
{
  aff_reactants(id, str);
  aff_products(id, str);
}
