/*
** get.c for get in /home/guerga_a/Piscine/projTester
**
** Made by francois guergadic
** Login   <guerga_a@epitech.net>
**
** Started on  Thu Jun 18 10:04:59 2015 francois guergadic
** Last update Sat Jun 20 12:46:34 2015 francois guergadic
*/

#include "projTester.h"

char	*get_entree(char *str)
{
  if (str == NULL)
    return (NULL);
  if (strncmp(str, "ENTREE:", 7) == 0)
    return (&str[7]);
  return (NULL);
}

char	*get_result(char **tab)
{
  int	i;

  i = 0;
  while (tab[i] && i < 3)
    {
      if (strncmp(tab[i], "RES:", 4) == 0)
	return (&tab[i][4]);
      i++;
    }
  return (NULL);
}

char	*get_sortie(char **av)
{
  int	i;

  i = 0;
  while (av[i])
    {
      if (strcmp(av[i], "-o") == 0)
	{
	  if (av[i + 1] == NULL)
	    {
	      fprintf(stdout, "! Fichier mal formaté !\n");
	      exit(1);
	    }
	  return (av[i + 1]);
	}
      i++;
    }
  return (NULL);
}

int	get_stats(char **av)
{
  int	i;

  i = 0;
  while (av[i])
    {
      if (strcmp(av[i], "-stats") == 0)
	return (1);
      i++;
    }
  return (0);
}

char	**get_args(char	*bin, char *str)
{
  char	*temp;
  char	**tab;

  if ((temp = malloc(sizeof(char) * (strlen(bin) + strlen(str) - 3))) == NULL)
    return (NULL);
  temp[0] = '\0';
  if (strncmp(str, "ARGS:", 5) == 0)
    {
      temp = strcat(temp, bin);
      temp = strcat(temp, ":");
      temp = strcat(temp, &str[5]);
      tab = my_str_to_wordtab(temp, ':');
      free(temp);
      return (tab);
    }
  else
    return (NULL);
}
