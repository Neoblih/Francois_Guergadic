/*
** my_power_it.c for my_power_it in /home/guerga_a/rendu/Piscine_C_J05
** 
** Made by francois guergadic
** Login   <guerga_a@epitech.net>
** 
** Started on  Fri Oct  3 12:16:03 2014 francois guergadic
** Last update Fri Oct  3 12:32:55 2014 francois guergadic
*/

int	my_power_it(int nb, int power)
{
  int count;
  int nb_power;

  nb_power=1;
  if (power < 0)
    {
      return (0);
    }
  else
    {
      count=power;
      while (count > 0)
	{
	  nb_power = nb_power * nb;
	  count--;
	}
      return (nb_power);
    }
}
