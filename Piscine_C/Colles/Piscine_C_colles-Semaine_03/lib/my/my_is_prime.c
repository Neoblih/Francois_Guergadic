/*
** my_is_prime.c for my_is_prime in /home/guerga_a/rendu/Piscine_C_J05
** 
** Made by francois guergadic
** Login   <guerga_a@epitech.net>
** 
** Started on  Fri Oct 10 15:14:19 2014 francois guergadic
** Last update Mon Oct 20 13:04:09 2014 francois guergadic
*/

int	my_is_prime(int nb)
{
  int	i;

  i = nb - 1;
  while (i > 1)
    {
      if (nb % i == 0)
	{
	  return (0);
	}
      i = i - 1;
    }
  return (1);
}
