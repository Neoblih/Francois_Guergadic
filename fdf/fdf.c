/*
** fdf.c for fdf in /home/guerga_a/Igraph
** 
** Made by francois guergadic
** Login   <guerga_a@epitech.net>
** 
** Started on  Mon Oct 27 15:50:53 2014 francois guergadic
** Last update Sun Dec  7 11:28:03 2014 francois guergadic
*/

#include <stdlib.h>
#include "mlx.h"
#include "fdf.h"
#include "point.h"
#include "my.h"

t_point		**fdf(char **tab, void *mlx, void *win)
{
  int		i;
  int		len;
  t_point	**point_tab;
  char		**strtab;

  len = get_word_number(epur_str(tab[0]));
  i = 0;
  if ((point_tab = malloc((len + 2) * sizeof(struct s_point*))) == NULL)
    return (NULL);
  while (tab[i])
    {
      if ((point_tab[i] = malloc((len + 1) * sizeof(struct s_point))) == NULL)
	return (NULL);
      strtab = my_str_to_tab(epur_str(tab[i]));
      point_tab[i] = put_coord(strtab, mlx, win,
			       (100 + (900 * i / len)), (500 + (500 * i / len)), len);
      free_tab(strtab);
      i = i + 1;
    }
  point_tab[i] = NULL;
  return (point_tab);
}

t_point		*put_coord(char **str, void *mlx, void *win, int xr, int yr, int len)
{
  int		i;
  int		x;
  int		y;
  t_point	*tab;
  t_point	point;

  x = xr;
  y = yr;
  i = 0;
  if ((tab = malloc(len * sizeof(struct s_point))) == NULL)
    return (NULL);
  while (str[i])
    {
      x = (xr + (900 * i / len));
      y = (yr - (500 * i / len));
      y = y - (my_getnbr(str[i]) * 6);
      point.x = x;
      point.y = y;
      tab[i] = point;
      mlx_pixel_put(mlx, win, x, y, 0x00FFFFFF);
      i = i + 1;
    }
  mlx_pixel_put(mlx, win, x, y, 0x00FFFFFF);
  return (tab);
}
