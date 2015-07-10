/*
** my_power_rec.c for my_power_rec in /home/guerga_a/rendu/Piscine_C_J05
** 
** Made by francois guergadic
** Login   <guerga_a@epitech.net>
** 
** Started on  Fri Oct  3 12:43:11 2014 francois guergadic
** Last update Fri Oct  3 12:47:36 2014 francois guergadic
*/

int	my_power_rec(int nb, int power)
{
  if (power < 0)
    {
      return (0);
    }
  else
    {
      while (power > 0)
	{
	  return ((my_power_rec(nb, power - 1) * nb));
	}
      return (1);
    }
}
