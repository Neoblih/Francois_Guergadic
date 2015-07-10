/*
** my_put_nbr.c for put nbr in blue in /home/guerga_a/B1/Prog_Elem/Allum1
** 
** Made by francois guergadic
** Login   <guerga_a@epitech.net>
** 
** Started on  Fri Feb 13 21:09:25 2015 francois guergadic
** Last update Fri Feb 13 21:16:21 2015 francois guergadic
*/

#include "allum1.h"

int	is_pos_b(int n)
{
  if (n >= 0)
    return (1);
  else
    return (0);
}

int	my_put_nbr_blue(int n)
{
  if (n == -2147483648)
    {
      my_put_nbr_blue(-21474);
      my_put_nbr_blue(83648);
    }
  else
    {
      if (is_pos_b(n) == 0)
	{
	  my_pc_b('-');
	  n = 0 - n;
	}
      if (n > 9)
	{
	  my_put_nbr_blue(n / 10);
	  my_put_nbr_blue(n % 10);
	}
      else
	{
	  my_pc_b(48 + n);
	}
    }
  return (0);
}
