/*
** my_find_prime_sup.c for my find prime sup in /home/guerga_a/rendu/Piscine_C_J05
** 
** Made by francois guergadic
** Login   <guerga_a@epitech.net>
** 
** Started on  Fri Oct 10 15:23:21 2014 francois guergadic
** Last update Fri Oct 10 15:37:43 2014 francois guergadic
*/

int	my_find_prime_sup(int nb)
{
  if (my_is_prime(nb) == 1)
    return (nb);
  else
    return (my_find_prime_sup(nb + 1));
}
