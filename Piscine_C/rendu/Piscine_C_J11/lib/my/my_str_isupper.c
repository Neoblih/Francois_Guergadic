/*
** my_str_isupper.c for my_str_isupper in /home/guerga_a/rendu/Piscine_C_J06/ex_13
** 
** Made by francois guergadic
** Login   <guerga_a@epitech.net>
** 
** Started on  Mon Oct  6 11:43:19 2014 francois guergadic
** Last update Mon Oct  6 11:44:07 2014 francois guergadic
*/

int	my_str_isupper(char *str)
{
  int   i;

  i = 0;
  while (str[i] != '\0')
    {
      if ((str[i] > 64) && (str[i] < 91))
	i++;
      else
	return (0);
    }
  return (1);
}
