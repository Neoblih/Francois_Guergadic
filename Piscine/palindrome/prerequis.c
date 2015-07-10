/*
** prerequis.c for prerequis in /home/guerga_a/Piscine/palindrome
**
** Made by francois guergadic
** Login   <guerga_a@epitech.net>
**
** Started on  Fri Jun 26 09:09:39 2015 francois guergadic
** Last update Thu Jul  2 15:40:32 2015 francois guergadic
*/

int	my_factrec_synthese(int nb)
{
  if (nb > 12 || nb < 0)
    return (0);
  if (nb == 0)
    return (1);
  else
    return (nb * my_factrec_synthese(nb - 1));
}

int	my_squareroot_synthese(int nb)
{
  int	i;

  if (nb == 0 || nb == 1)
    return (nb);
  if (nb < 4)
    return (-1);
  i = 0;
  while (i * i < nb)
    i++;
  if (i * i == nb)
    return (i);
  return (-1);
}
