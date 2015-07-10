/*
** my_getnbr.c for my_getnbr in /home/esse_a/rendu/Piscine_C_J07
** 
** Made by Nicolas Esse
** Login   <esse_a@epitech.net>
** 
** Started on  Tue Oct  7 14:41:00 2014 Nicolas Esse
** Last update Sat Oct 11 16:22:52 2014 francois guergadic
*/

int	is_pos(char *str)
{
  int	i;
  int	minus;

  i = 0;
  minus = 0;
  while ((str[i] > '9') || (str[i] > '0'))
    {
      if (str[i] == '-')
	minus++;
      i++;
    }
  return (minus % 2);
}

int	is_num(char c)
{
  if (c >= '0' && c <= '9')
    return (1);
  else
    return (0);
}

int	my_getnbr(char *str)
{
  int	i;
  int	nbr;

  nbr = 0;
  i = 0;
  while (is_num(str[i]) == 0)
    i++;
  while (is_num(str[i]) == 1)
    {
      nbr = nbr * 10 + str[i] - 48;
      i++;
    }
  if (is_pos(str) == 0)
    return (nbr);
  return (-nbr);
}
