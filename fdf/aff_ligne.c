/*
** aff_ligne.c for aff ligne in /home/guerga_a/Igraph
** 
** Made by francois guergadic
** Login   <guerga_a@epitech.net>
** 
** Started on  Mon Oct 27 14:05:43 2014 francois guergadic
** Last update Sun Dec  7 11:04:17 2014 francois guergadic
*/

#include "mlx.h"
#include "point.h"

int	aff_ligne(void *mlx_ptr, void *win_ptr, t_point a, t_point b)
{
  int	dx;
  int	dy;
  int	x;
  int	y;

  dx = b.x - a.x;
  dy = b.y - a.y;
  x = a.x;
  while (x < b.x)
    {
      y = a.y + dy * (x - a.x) / dx;
      mlx_pixel_put(mlx_ptr, win_ptr, x, y, 0x00FFFFFF);
      x = x + 1;
    }
  return (0);
}
