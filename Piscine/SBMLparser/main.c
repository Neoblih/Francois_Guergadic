/*
** main.c for main in /home/guerga_a/Piscine/SBMLparser
** 
** Made by francois guergadic
** Login   <guerga_a@epitech.net>
** 
** Started on  Mon Jun 15 09:32:06 2015 francois guergadic
** Last update Wed Jun 17 16:17:03 2015 francois guergadic
*/

#include <stdio.h>
#include <stdlib.h>
#include "SBMLparser.h"

void	aff_tab(char **tab)
{
  int	i;

  i = 0;
  while (tab[i])
    {
      printf("%s\n", tab[i]);
      i++;
    }
}

int	arg_i(char **av)
{
  int	i;

  i = 0;
  while (av[i])
    {
      if (my_strcmp(av[i], "-i") == 0)
	{
	  if (av[i + 1] && my_strcmp(av[i + 1], "-e") == 1 &&
	      my_strcmp(av[i + 1], "-json") == 1)
	    return (i + 1);
	  else
	    return (-1);
	}
      i++;
    }
  return (0);
}

int	arg_json(char **av)
{
  int	i;

  i = 0;
  while (av[i])
    {
      if (my_strcmp(av[i], "-json") == 0)
        return (1);
      i++;
    }
  return (0);
}

int	arg_e(char **av)
{
  int	i;

  i = 0;
  while (av[i])
    {
      if (my_strcmp(av[i], "-e") == 0)
        {
	  if (arg_i(av) < 1)
	    return (-1);
	  else
	    return (1);
	}
      i++;
    }
  return (0);
}

int	main(int ac, char **av)
{
  char	**tab;
  char	*str;

  if (ac > 1)
    {
      all_flag(av);
      if ((str = my_read(av[1])) == NULL)
	return (1);
      if (arg_i(av) == 0 && arg_e(av) == 0)
	{
	  tab = get_pars_tab(str);
	  aff_parsing(tab);
	  free_tab(tab);
	}
      else if (arg_i(av) == -1 && arg_e(av) == 0)
	aff_any(str);
      else
	pars_id(av[arg_i(av)], str, arg_e(av), arg_json(av));
      free(str);
      return (0);
    }
  printf("Fichier incorrect\n");
  return (1);
}
