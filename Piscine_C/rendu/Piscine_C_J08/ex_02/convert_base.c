/*
** convert_base.c for convert base in /home/guerga_a/rendu/Piscine_C_J08/ex_02
** 
** Made by francois guergadic
** Login   <guerga_a@epitech.net>
** 
** Started on  Wed Oct  8 11:22:19 2014 francois guergadic
** Last update Thu Oct  9 23:05:19 2014 francois guergadic
*/

#include <stdlib.h>

int	return_int(char *nbr, char *base_from)
{
  int	base_length;
  int	nbr_length;
  int	i;
  int	nb;
  int	j;

  j = 0;
  nb = 0;
  base_length = my_strlen(base_from);
  nbr_length = my_strlen(nbr);
  while (nbr_length > 0)
    {
      i = 0;
      while (nbr[nbr_length - 1] != base_from[i])
	{
	  i = i + 1;
	}
      nb = nb + (my_power_rec(base_length, j) * i);
      nbr_length = nbr_length - 1;
      j = j + 1;
    }
  return (nb);
}

int	get_power(int nb, int base_length)
{
  int power;

  power = 0;
  while (nb >= (my_power_rec(base_length, power)))
    {
      power = power + 1;
    }
  power = power- 1;
  return (power);
}

char	*return_char_str(int nb, char *base_to)
{
  int	base_length;
  int	power;
  int	i;
  int	nb_remain;
  char	*result;
  int	j;

  nb_remain = nb;
  base_length = my_strlen(base_to);
  power = get_power(nb, base_length);
  i = power;
  result = malloc(power + 1);
  while (i >= 0)
    {
      j = 0;
      while (nb_remain >= my_power_rec(base_length, i) && j < base_length - 1)
	{
	  nb_remain = nb_remain - my_power_rec(base_length, i);
	  j = j + 1;
	}
      result[power - i] = base_to[j];
      i = i - 1;
    }
  result[power + 1] = '\0';
  return (result);
}

char	*convert_base(char *nbr, char *base_from, char *base_to)
{
  int	entier;

  if (my_strlen(base_from) < 2 || my_strlen(base_to) < 2)
    {
      return (base_from);
    }
  else
    {
      entier = return_int(nbr,base_from);
      return (return_char_str(entier, base_to));
    }
}
