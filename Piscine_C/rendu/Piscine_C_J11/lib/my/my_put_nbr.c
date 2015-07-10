/*
** my_put_nbr.c for my_put_nbr in /home/guerga_a/rendu/Piscine_C_J03
** 
** Made by francois guergadic
** Login   <guerga_a@epitech.net>
** 
** Started on  Wed Oct  1 15:38:46 2014 francois guergadic
** Last update Thu Oct  2 17:59:38 2014 francois guergadic
*/

int	pos(int n)
{
  if (n >= 0)
    {
      return (1);
    }
  else
    {
      return (0);
    }
}

int	my_put_nbr(int nb)
{
  if (nb == -2147483648)
    {
      my_put_nbr(-214748364);
      my_put_nbr(8);
    }
  else
    {
      if (pos(nb) == 0)
	{
	  my_putchar('-');
	  nb = 0 - nb;
	}
      if (nb > 9)
	{
	  my_put_nbr(nb / 10);
	  my_put_nbr(nb % 10);
	}
      else
	{
	  my_putchar(nb + 48);
	}
    }
}
