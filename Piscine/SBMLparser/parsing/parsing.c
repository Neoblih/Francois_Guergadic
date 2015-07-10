/*
** parsing.c for parsing in /home/guerga_a/Piscine/SBMLparser
** 
** Made by francois guergadic
** Login   <guerga_a@epitech.net>
** 
** Started on  Mon Jun 15 12:38:55 2015 francois guergadic
** Last update Wed Jun 17 12:47:35 2015 francois guergadic
*/

#include <stdlib.h>
#include <stdio.h>
#include "SBMLparser.h"

int	pars_n(char *str)
{
  int	i;
  int	j;
  char	*tmp;

  i = 0;
  j = 0;
  while (str[i])
    {
      if ((tmp = parsing(&str[i])) != NULL)
	{
	  free(tmp);
	  j++;
	}
      i++;
    }
  return (j);
}

char	**get_pars_tab(char *str)
{
  int	i;
  int	j;
  char	*tmp;
  char	**tab;

  if ((tab = malloc(sizeof(char*) * (pars_n(str) + 1))) == NULL)
    return (NULL);
  i = 0;
  j = 0;
  while (str[i])
    {
      if ((tmp = parsing(&str[i])) != NULL)
	{
	  if ((tab[j] = malloc(sizeof(char) * (my_strlen(sort_str(tmp)) + 1))) == NULL)
	    return (NULL);
	  tab[j][0] = '\0';
          my_strcat(tab[j++], sort_str(tmp));
	  free(tmp);
	}
      i++;
    }
  tab[j] = NULL;
  tab = sort_tab(tab);
  tab = remove_double(tab);
  return (tab);
}

char	*next_word(char *str)
{
  int	i;
  char	*buff;

  i = 0;
  if ((buff = malloc(sizeof(char) * 200)) == NULL)
    return (NULL);
  while (is_alph(str[i]) == 1)
    {
      buff[i] = str[i];
      i++;
    }
  buff[i] = '\0';
  return (buff);
}

char	*next_param(char *str)
{
  int	i;
  char	*buff;

  i = 0;
  if ((buff = malloc(sizeof(char) * 200)) == NULL)
    return (NULL);
  while (str[i])
    {
      if (is_alph(str[i]) == 0 && str[i] != '=')
	{
	  free(buff);
	  return (NULL);
	}
      buff[i] = str[i];
      if (str[i] == '=')
	{
	  buff[i] = '\0';
	  return (buff);
	}
      i++;
    }
  free(buff);
  return (NULL);
}

char	*parsing(char *str)
{
  int	i;
  char	*buff;
  char	*tmp;

  i = 0;
  if (str[0] == '<' && str[word_len(&str[1]) + 1] == ' ')
    {
      if ((buff = malloc(sizeof(char) * 200)) == NULL)
	return (NULL);
      buff[0] = '\0';
      tmp = next_word(&str[i + 1]);
      buff = my_strcat(buff, tmp);
      free(tmp);
      while (str[i++] != '>')
	if ((tmp = next_param(&str[i - 1])) != NULL)
	  {
	    buff = my_strcat(buff, " ");
	    buff = my_strcat(buff, tmp);
	    i = i + my_strlen(tmp);
	    free(tmp);
	  }
      return (buff);
    }
  return (NULL);
}
