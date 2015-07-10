/*
** my_factorielle_it.c for my_factorielle_it in /home/guerga_a/rendu/Piscine_C_J05
** 
** Made by francois guergadic
** Login   <guerga_a@epitech.net>
** 
** Started on  Fri Oct  3 09:58:46 2014 francois guergadic
** Last update Mon Oct  6 17:12:59 2014 francois guergadic
*/

int	my_factorielle_it(int nb)
{
  int   count;
  int   nb_fact;

  if (nb < 0 || nb > 12)
    {
      return (0);
    }
  else
    {
      nb_fact=1;
      count=nb;
      while (count > 0)
	{
	  nb_fact = nb_fact * count;
	  count--;
	}
      return (nb_fact);
    }
}
