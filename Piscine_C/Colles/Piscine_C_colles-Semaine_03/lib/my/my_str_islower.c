/*
** my_str_islower.c for my_str_islower in /home/guerga_a/rendu/Piscine_C_J06/ex_12
** 
** Made by francois guergadic
** Login   <guerga_a@epitech.net>
** 
** Started on  Mon Oct  6 11:41:05 2014 francois guergadic
** Last update Mon Oct  6 11:42:33 2014 francois guergadic
*/

int	my_str_islower(char *str)
{
  int   i;

  i = 0;
  while (str[i] != '\0')
    {
      if ((str[i] > 96) && (str[i] < 123))
	i++;
      else
	return (0);
    }
  return (1);
}
