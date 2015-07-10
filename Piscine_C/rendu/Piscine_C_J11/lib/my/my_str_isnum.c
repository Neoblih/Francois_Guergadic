/*
** my_str_isnum.c for my_str_isnum in /home/guerga_a/rendu/Piscine_C_J06/ex_11
** 
** Made by francois guergadic
** Login   <guerga_a@epitech.net>
** 
** Started on  Mon Oct  6 11:38:37 2014 francois guergadic
** Last update Mon Oct  6 11:40:07 2014 francois guergadic
*/

int	my_str_isnum(char *str)
{
  int   i;

  i = 0;
  while (str[i] != '\0')
    {
      if ((str[i] > 47) && (str[i] < 58))
	i++;
      else
	return (0);
    }
  return (1);
}
