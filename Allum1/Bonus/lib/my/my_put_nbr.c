/*
** my_put_nbr.c for put_nbr in /home/guerga_a/B1/Sys_Unix/PSU_2014_my_ls/lib
** 
** Made by francois guergadic
** Login   <guerga_a@epitech.net>
** 
** Started on  Sat Nov 29 12:40:27 2014 francois guergadic
** Last update Sat Nov 29 12:40:28 2014 francois guergadic
*/

int	is_pos(int n)
{
  if (n >= 0)
    return (1);
  else
    return (0);
}

int	my_put_nbr(int n)
{
  if (n == -2147483648)
    {
      my_put_nbr(-21474);
      my_put_nbr(83648);
    }
  else
    {
      if (is_pos(n) == 0)
	{
	  my_putchar('-');
	  n = 0 - n;
	}
      if (n > 9)
	{
	  my_put_nbr(n / 10);
	  my_put_nbr(n % 10);
	}
      else
	{
	  my_putchar(48 + n);
	}
    }
}
