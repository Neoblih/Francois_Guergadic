/*
** my_power_rec.c for power_rec in /home/guerga_a/B1/Sys_Unix/PSU_2014_my_ls/lib
** 
** Made by francois guergadic
** Login   <guerga_a@epitech.net>
** 
** Started on  Sat Nov 29 12:39:58 2014 francois guergadic
** Last update Sat Nov 29 12:39:59 2014 francois guergadic
*/

int	my_power_rec(int nb, int power)
{
  if (power == 0)
    return (1);
  else
    return (nb * my_power_rec(nb, power - 1));
  if (nb >= 46341 && power > 1)
    return (0);
  if (power > 31 && nb > 1)
    return (0);
}
