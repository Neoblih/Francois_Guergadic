/*
** t_point.h for struct point in /home/guerga_a/Igraph/FDF/include
** 
** Made by francois guergadic
** Login   <guerga_a@epitech.net>
** 
** Started on  Mon Oct 27 19:51:04 2014 francois guergadic
** Last update Wed Mar  4 11:47:25 2015 francois guergadic
*/

#ifndef POINT_H_
# define POINT_H_

typedef struct s_point
{
  float	x;
  float	y;
  float	z;
} t_point;

typedef struct s_sphere
{
  float	x;
  float	y;
  float	z;
  float	r;
} t_sphere;

typedef struct s_inter
{
  int	i;
  float k1;
  float k2;
} t_inter;

typedef struct s_intertab
{
  float	*k_tab;
  int	*color_tab;
  t_point **P;
  t_point **N;
} t_intertab;
