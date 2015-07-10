/*
** main.c for main in /home/guerga_a/Piscine/FASTAtools
**
** Made by francois guergadic
** Login   <guerga_a@epitech.net>
**
** Started on  Wed Jun 24 09:37:40 2015 francois guergadic
** Last update Thu Jun 25 09:36:38 2015 francois guergadic
*/

#include "FASTAtools.h"

void	free_tab(char **tab)
{
  int	i;

  i = 0;
  while (tab[i])
    free(tab[i++]);
  free(tab[i]);
  free(tab);
}

void	aff_fasta(char **id_tab, char **seq_tab)
{
  int	i;

  i = 0;
  while (id_tab[i] && seq_tab[i])
    {
      printf("%s\n%s\n", id_tab[i], seq_tab[i]);
      i++;
    }
}

int	main(int argc, char *argv[])
{
  int	opt;

  if (argc == 1)
    fprintf(stdout, "Usage: ./FASTAtools option [k]\n");
  else
    {
      opt = atoi(argv[1]);
      if (opt == 1)
	part_1();
      else if (opt == 2)
	part_2();
      else if (opt == 3)
	part_3();
      else if (opt == 4)
	{
	  if (argc > 2)
	    part_4(atoi(argv[2]));
	  else
	    fprintf(stdout, "Usage: ./FASTAtools option [k]\n");
	}
      else if (opt == 5)
	part_5();
      else if (opt == 6)
	part_6();
    }
  return 0;
}
