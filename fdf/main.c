/*
** main.c for FDF in /home/guerga_a/Igraph
** 
** Made by francois guergadic
** Login   <guerga_a@epitech.net>
** 
** Started on  Mon Oct 27 14:43:46 2014 francois guergadic
** Last update Sun Dec  7 10:35:38 2014 francois guergadic
*/

#include <unistd.h>
#include <stdlib.h>
#include "mlx.h"
#include "fdf.h"
#include "point.h"
#include "my.h"

int		recup_buff(void *mlx, void *win)
{
  char		buff[BUFF_SIZE + 1];
  int		len;
  char		tab[200000];
  char		**recup_tab;
  t_point	**point_tab;

  *tab = '\0';
  while ((len = read(0, buff, BUFF_SIZE)) > 0)
    {
      if (len != 0)
	{
	  buff[len] = 0;
	  my_strcat(tab, buff);
	}
    }
  recup_tab = my_buff_to_tab(buff);
  point_tab = fdf(recup_tab, mlx, win);
  aff_result(point_tab, mlx, win, tab_height(tab));
  free_tab(recup_tab);
  free_point(point_tab);
  return (0);
}

int	main()
{
  void	*mlx;
  void	*win;

  mlx = mlx_init();
  win = mlx_new_window(mlx, 1920, 1080, "FDF");
  recup_buff(mlx, win);
  mlx_loop(mlx);
  return (0);
}

void	aff_result(t_point **tab, void *mlx, void *win, int len)
{
  int	i;
  int	j;

  i = 0;
  while (i < len)
    {
      j = 0;
      while (j < len)
	{
	  if (j + 1 < len)
	    aff_ligne(mlx, win, tab[i][j], tab[i][j + 1]);
	  if (i + 1 < len)
	    aff_ligne(mlx, win, tab[i][j], tab[i + 1][j]);
	  j = j + 1;
	}
      i = i + 1;
    }
}
