/*
** main.c for Wolf3d in /home/guerga_a/Igraph
** 
** Made by francois guergadic
** Login   <guerga_a@epitech.net>
** 
** Started on  Mon Oct 27 14:43:46 2014 francois guergadic
** Last update Wed Mar  4 11:48:24 2015 francois guergadic
*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <math.h>
#include "mlx.h"
#include "my.h"
#include "color.h"
#include "point.h"

float sqrtf(float x);

void	aff_tab(float *tab)
 {
   int	i;

   i = 0;
   while (tab[i] != -4321)
     printf("%.3f / ", tab[i++]);
   printf(" [%i]\n", i);
} 

int	luminosite(int color, t_point *P, t_point *N, t_point *S);
{
  t_point L;
  float		scalaire;
  float		normeN;
  float		normeL;
  float		cosa;

  L->x = S->x - P->x;
  L->y = S->y - P->y;
  L->z = S->z - P->z;
  scalaire = N->x * L->x + N->y * L->y + N->z * L->z;
  normeN = sqrtf(N->x * N->x + N->y * N->y + N->z * N->z);
  normeL = sqrtf(L->x * L->x + L->y * L->y + L->z * L->z);
  cosa = scalaire / (normeN * normeL);
  if (cosa < 0)
    cosa = 0;
  (color & 0xFF0000) >> 16 = ((color & 0xFF0000) >> 16) * cosa;
  (color & 0xFF00) >> 8 = ((color & 0xFF00) >> 8) * cosa;
  (color & 0xFF) >> 0 = ((color & 0xFF) >> 0) * cosa;
  return (color);
}

void	put_pixel_to_img(void *img, int x, int y, int color)
{
  int	bpp;
  int	sizeline;
  int	endian;
  char	*data;
  unsigned char r;
  unsigned char g;
  unsigned char b;

  r = (color & 0xFF0000) >> 16;
  g = (color & 0xFF00) >> 8;
  b = (color & 0xFF) >> 0;
  data = mlx_get_data_addr(img, &bpp, &sizeline, &endian);
  data[(bpp / 8 * x) + (sizeline * y)] = b;
  data[(bpp / 8 * x) + (sizeline * y) + 1] = g;
  data[(bpp / 8 * x) + (sizeline * y) + 2] = r;
}

void	add_float(float *tab, float add)
{
  int   i;

  i = 0;
  while (tab[i] != -4321)
    i++;
  tab[i] = add;
  tab[i + 1] = -4321;
}

void    add_int(int *tab, int add)
{
  int   i;

  i = 0;
  while (tab[i] != -4321)
    i++;
  tab[i] = add;
  tab[i + 1] = -4321;
}

int	inter_plan(t_point *oeil, t_point *V, t_intertab *intertab)
{
  double	k;

  if (V->z == 0)
    return (0);
  k = - (oeil->z / V->z);
  if (k >= 0.00001)
    {
      add_float(intertab->k_tab, k);
      add_int(intertab->color_tab, 0x0070DE);
      return (1);
    }
  return (0);
}

int	inter_sphere(t_point *oeil, t_point *V, int r, t_intertab *intertab)
{
  float a;
  float b;
  float c;
  float d;

  a = (V->x * V->x) + (V->y * V->y) + (V->z * V->z);
  b = 2 * (oeil->x * V->x + oeil->y * V->y + oeil->z * V->z);
  c = (oeil->x * oeil->x) + (oeil->y * oeil->y) + (oeil->z * oeil->z) - (r * r);
  d = (b * b) - (4 * a * c);
  if (d >= 0)
    {
      add_float(intertab->k_tab, ((-b + sqrtf(d)) / (2 * a)));
      add_int(intertab->color_tab, 0xC41F3B);
      add_float(intertab->k_tab, ((-b - sqrtf(d)) / (2 * a)));
      add_int(intertab->color_tab, 0xC41F3B);
      return (1);
    }
  return (0);
}

void	sort_k(t_intertab *intertab)
{
  int	i;
  int	itemp;
  float ftemp;

  i = 0;
  if (intertab->k_tab[0] != -4321)
    {
      while (intertab->k_tab[i + 1] != -4321)
	{
	  if (intertab->k_tab[i] > intertab->k_tab[i + 1])
	    {
	      ftemp = intertab->k_tab[i];
	      intertab->k_tab[i] = intertab->k_tab[i + 1];
	      intertab->k_tab[i + 1] = ftemp;
	      itemp = intertab->color_tab[i + 1];
	      intertab->color_tab[i + 1] = intertab->color_tab[i];
	      intertab->color_tab[i] = itemp;
	      i = - 1;
	    }
	  i++;
	}
    } 
}

int	get_color(t_intertab *intertab)
{
  int	i;
  float compare;
  
  compare = 0.001;
  i = 0;
  sort_k(intertab);
  while (intertab->k_tab[i] != -4321)
    {
      if (intertab->k_tab[i] > compare)
	return (intertab->color_tab[i]);
      i++;
    }
  return (0x30FF30);
}

int	calc(int x, int y)
{
  t_point *oeil;
  t_point *V;
  t_point *S;
  t_intertab *intertab;
  int	color;

  intertab = malloc(sizeof(intertab) * 8);
  intertab->k_tab = malloc(sizeof(float) * 6);
  intertab->color_tab = malloc(sizeof(int) * 6);
  intertab->P = malloc(sizeof(*t_point) * 8);
  intertab->N = malloc(sizeof(*t_point) * 8);
  intertab->k_tab[0] = -4321;
  intertab->color_tab[0] = -4321;
  oeil = malloc(sizeof(oeil) * 8);
  V = malloc(sizeof(V) * 8);
  S = malloc(sizeof(S) * 8);
  V->x = 100;
  V->y = (WIN_L/2) - x;
  V->z = (WIN_H/2) - y;
  oeil->x = -150;
  oeil->y = 0;
  oeil->z = 25;
  inter_sphere(oeil, V, 70, intertab);;
  inter_plan(oeil, V, intertab);
  color = get_color(intertab);
  color = luminosite(color, P, N, S);
  return (color);
}

void	remplis_image(void *img)
{
  int	i;
  int	j;

  i = 0;
  while (i < WIN_H)
    {
      j = 0;
      while (j < WIN_L)
	{
	  put_pixel_to_img(img, i, j, calc(i, j));
	  j++;
	}
      i++;
    }
}

int     main()
{
  void  *mlx;
  void  *img;
  void  *win;

  mlx = mlx_init();
  img = mlx_new_image(mlx, WIN_L, WIN_H);
  remplis_image(img);
  win = mlx_new_window(mlx, WIN_L, WIN_H, "rt1");
  mlx_put_image_to_window(mlx, win, img, 0, 0);
  mlx_loop(mlx);
  return (0);
} 

