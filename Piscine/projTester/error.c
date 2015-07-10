/*
** error.c for error in /home/guerga_a/Piscine/projTester
**
** Made by francois guergadic
** Login   <guerga_a@epitech.net>
**
** Started on  Thu Jun 18 12:10:15 2015 francois guergadic
** Last update Sat Jun 20 12:46:47 2015 francois guergadic
*/

#include "projTester.h"

void	check_file(char **tab)
{
  int	i;

  i = 0;
  while (tab[i])
    {
      if (strncmp(tab[i], "ARGS:", 5) != 0)
	{
	  if (i == 0 || strncmp(tab[i - 1], "ARGS:", 5) != 0 ||
	      strncmp(tab[i], "ENTREE:", 7) != 0 ||
	      !tab[i][7])
	    {
	      if ((i == 0 || strncmp(tab[i - 1], "ARGS:", 5) != 0 ||
		   strncmp(tab[i], "RES:", 4) != 0) &&
		  (i == 0 || strncmp(tab[i - 1], "ENTREE:", 7) != 0 ||
		   strncmp(tab[i], "RES:", 4) != 0))
		{
		  fprintf(stdout, "! Fichier mal formaté !\n");
		  exit(1);
		}
	    }
	}
      i++;
    }
}
