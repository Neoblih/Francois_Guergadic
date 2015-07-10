/*
** free_tab.c for free tab in /home/guerga_a/B1/Sys_Unix/PSU_2014_my_ls
** 
** Made by francois guergadic
** Login   <guerga_a@epitech.net>
** 
** Started on  Sat Nov 29 14:20:18 2014 francois guergadic
** Last update Sun Dec  7 10:58:30 2014 francois guergadic
*/

#include <stdlib.h>
#include "mlx.h"
#include "fdf.h"
#include "point.h"
#include "my.h"

void	free_tab(char **tab)
{
  int	i;

  i = 0;
  while (tab[i])
    {
      free(tab[i]);
      i++;
    }
  free(tab[i]);
  free(tab);
}

void	free_point(t_point **tab)
{
  int	i;

  i = 0;
  while (tab[i])
    {
      free(tab[i]);
      i++;
    }
  free(tab[i]);
  free(tab);
}
