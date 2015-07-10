/*
** error.c for error in /home/guerga_a/Piscine/SBMLparser/global
** 
** Made by francois guergadic
** Login   <guerga_a@epitech.net>
** 
** Started on  Wed Jun 17 15:52:28 2015 francois guergadic
** Last update Wed Jun 17 18:13:49 2015 francois guergadic
*/

#include <stdio.h>
#include <stdlib.h>
#include "SBMLparser.h"

void	verif_file(char *path)
{
  if (my_strcmp(&path[my_strlen(path) - 5], ".sbml") != 0)
    {
      printf("Fichier incorrect\n");
      exit(1);
    }
}

void	all_flag(char **av)
{
  int	i;

  i = 0;
  verif_file(av[1]);
  while (av[i])
    {
      if (av[i][0] == '-'
	  && my_strcmp(av[i], "-i") != 0
	  && my_strcmp(av[i], "-e") != 0
	  && my_strcmp(av[i], "-json") != 0)
	{
	  printf("Fichier incorrect\n");
	  exit(1);
	}
      i++;
    }
}
