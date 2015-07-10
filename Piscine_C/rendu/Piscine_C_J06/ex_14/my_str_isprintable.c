/*
** my_str_isprintable.c for my_str_isprintable in /home/guerga_a/rendu/Piscine_C_J06/ex_14
** 
** Made by francois guergadic
** Login   <guerga_a@epitech.net>
** 
** Started on  Mon Oct  6 12:07:19 2014 francois guergadic
** Last update Mon Oct  6 12:10:24 2014 francois guergadic
*/

int	my_str_isprintable(char *str)
{
  int   i;

  i = 0;
  while (str[i] != '\0')
    {
      if ((str[i] > 30) && (str[i] < 127))
	i++;
      else
	return (0);
    }
  return (1);

}
