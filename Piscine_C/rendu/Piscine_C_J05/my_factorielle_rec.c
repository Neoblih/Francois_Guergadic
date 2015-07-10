/*
** my_factorielle_rec.c for my_factorielle_rec.c in /home/guerga_a/rendu/Piscine_C_J05
** 
** Made by francois guergadic
** Login   <guerga_a@epitech.net>
** 
** Started on  Fri Oct  3 10:48:24 2014 francois guergadic
** Last update Fri Oct  3 11:29:57 2014 francois guergadic
*/

int	my_factorielle_rec(int nb)
{
  if (nb < 0 || nb > 12)
    {
      return (0);
    }
  else
    {
      while (nb > 1)
	{
	  return ((my_factorielle_rec(nb - 1)) * nb);
	}
      return (1);
    }
}
