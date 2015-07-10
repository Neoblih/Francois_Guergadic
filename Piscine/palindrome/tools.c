/*
** tools.c for tools in /home/guerga_a/Piscine/palindrome
**
** Made by francois guergadic
** Login   <guerga_a@epitech.net>
**
** Started on  Fri Jun 26 14:14:31 2015 francois guergadic
** Last update Fri Jun 26 17:27:07 2015 francois guergadic
*/

#include "palindrome.h"

int	convert_base(int n, int base_from, int base_to)
{
  int	pow;
  int	result;

  pow = (result = 0);
  while (n)
    {
      result += n % base_to * my_power_rec(base_from, pow++);
      n /= base_to;
    }
  return (result);
}

int	my_base_add(int n1, int n2, int base)
{
  n1 = convert_base(n1, base, 10);
  n2 = convert_base(n2, base, 10);
  n1 = n1 + n2;
  n1 = convert_base(n1, 10, base);
  return (n1);
}

int	my_retourn(int n, int base)
{
  int	result;

  result = 0;
  while (n != 0)
    {
      result = result * 10;
      result = result + n % 10;
      n = n / 10;
    }
  if (result < 0)
    aff_error(ERR_OVERFLOW, 'e');
  base = base;
  return (result);
}

int	is_pal(int n, int base)
{
  if (n == my_retourn(n, base))
    return (1);
  else
    return (0);
}

int	do_return(int n, int base)
{
  return (my_base_add(n, my_retourn(n, base), base));
}
