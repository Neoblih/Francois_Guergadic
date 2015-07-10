/*
** my_square_root.c for my square root in /home/guerga_a/rendu/Piscine_C_J05
** 
** Made by francois guergadic
** Login   <guerga_a@epitech.net>
** 
** Started on  Fri Oct 10 15:31:43 2014 francois guergadic
** Last update Fri Oct 10 15:37:27 2014 francois guergadic
*/

int	my_square_root(int nb)
{
  int	i;
  while (my_power_rec(i, 2) < nb)
    {
      i = i + 1;
    }
  if (my_power_rec(i, 2) == nb)
    return (i);
  else
    return (0);
}
