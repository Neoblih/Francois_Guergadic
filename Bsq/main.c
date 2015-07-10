/*
** main.c for bsq in /home/guerga_a/B1/Prog_Elem/CPE_2015_bsq
** 
** Made by francois guergadic
** Login   <guerga_a@epitech.net>
** 
** Started on  Tue Jan 13 12:15:02 2015 francois guergadic
** Last update Sun Jan 18 18:56:26 2015 francois guergadic
*/

#include <stdlib.h>
#include <unistd.h>
#include "./include/point.h"
#include "./include/my.h"
#include "./include/bsq.h"

int	check_tab(char **tab, int x, int y, int n)
{
  int	i;
  int	j;

  i = 0;
  j = 0;
  while (j < n)
    {
      if (tab[x + n - 1][y + j] != '.')
	return (1);
      j++;
    }
  j = 0;
  while (i < n)
    {
      if (tab[x + i][y + n - 1] != '.')
	return (1);
      i++;
    }
  return (0);
}

int	tab_size(char **tab, int x, int y)
{
  int	i;

  i = 0;
  while (tab[x + i] && check_tab(tab, x, y, i + 1) == 0)
    i++;
  return (i);
}

t_point		check_full_tab(char **tab)
{
  t_point	point;
  int		i;
  int		j;

  point.x = 0;
  point.y = 0;
  point.size = 0;
  i = 0;
  j = 0;
  while (tab[i])
    {
      j = 0;
      while (tab[i][j])
	{
	  if (tab_size(tab, i, j) > point.size)
	    {
	      point.x = j;
	      point.y = i;
	      point.size = tab_size(tab, i, j);
	    }
	  j++;
	}
      i++;
    }
  return (point);
}

char	**replace_tab(char **tab, t_point point)
{
  int	i;
  int	j;

  i = point.y;
  while (tab[i] && i < point.y + point.size)
    {
      j = point.x;
      while (tab[i][j] && j < point.x + point.size)
	{
	  tab[i][j] = 'X';
	  j++;
	}
      i++;
    }
  return (tab);
}

int		main(int argc, char **argv)
{
  t_point	point;
  char		**tab;

  if (argc == 2)
    {
      tab = recup_buff(argv[1]);
      if (tab != NULL)
	{
	  aff_tab(tab);
	  point = check_full_tab(tab);
	  my_putstr("\n\n");
	  aff_tab(replace_tab(tab, point));
	  free(tab);
	}
      else
	{
	  my_putstr("Impossible d'ouvrir le fichier ");
	  my_putstr(argv[1]);
	  my_putchar('\n');
	}
    }
  return (0);
}
