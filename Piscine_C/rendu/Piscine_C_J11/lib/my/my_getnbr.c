/*
** my_getnbr.c for my_getnbr in /home/guerga_a/rendu/Piscine_C_J04
** 
** Made by francois guergadic
** Login   <guerga_a@epitech.net>
** 
** Started on  Thu Oct  2 13:34:05 2014 francois guergadic
** Last update Tue Oct 28 18:10:03 2014 francois guergadic
*/

int	my_getnbr(char *str)
{
  int	i;
  int	total;

  total = 0;
  i = 0;
  while (str[i])
    {
      if (str[i] > 47 && str[i] < 58)
	total = str[i] - 48;
      else
	return (total);
      i = i + 1;
    }
  return (total);
}
