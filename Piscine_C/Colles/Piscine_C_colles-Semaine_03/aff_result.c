/*
** aff_result.c for aff_result in /home/guerga_a/Colles/Piscine_C_colles-Semaine_03
** 
** Made by francois guergadic
** Login   <guerga_a@epitech.net>
** 
** Started on  Sat Oct 25 21:13:00 2014 francois guergadic
** Last update Sat Oct 25 22:20:59 2014 francois guergadic
*/

#include "./include/my.h"

void	aff_result(int match, int i, int length, int height)
{
  if (match == 1)
    {
      my_putstr("[Colle1-");
      my_put_nbr(i);
      my_putstr("] [");
      my_put_nbr(height);
      my_putstr("] [");
      my_put_nbr(length);
      my_putstr("]");
    }
}

void	double_result()
{
  my_putstr(" || ");
}

void	no_result()
{
  my_putstr("aucune");
}
