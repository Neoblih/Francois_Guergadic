/*
** main.c for main in /home/guerga_a/B1/Sys_Unix/PSU_2014_my_ls
** 
** Made by francois guergadic
** Login   <guerga_a@epitech.net>
** 
** Started on  Fri Nov 28 15:25:14 2014 francois guergadic
** Last update Sun Nov 30 17:37:35 2014 francois guergadic
*/

#include <stdlib.h>
#include "./include/my_ls.h"
#include "./include/my.h"

int		main(int ac, char **av)
{
  char		**tab;

  if (ac > 1)
    {
      if ((tab = init_tab(av[1])) == NULL)
	{
	  error_access(av[1]);
	  return (1);
	}
      sort_tab(tab);
      if (ac == 2)
	aff_ls(tab);
      else if (ac > 2 && av[2][0] == '-' && av[2][1] == 'a' && av[2][2] == '\0')
	aff_ls_a(tab);
      else
	{
	  free_tab(tab);
	  error_invarg(av[2]);
	  return (1);
	}
    }
  return (0);
}
