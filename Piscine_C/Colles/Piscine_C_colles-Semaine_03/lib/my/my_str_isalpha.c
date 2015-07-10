/*
** my_str_isalpha.c for my_str_isalpha in /home/guerga_a/rendu/Piscine_C_J06/ex_10
** 
** Made by francois guergadic
** Login   <guerga_a@epitech.net>
** 
** Started on  Mon Oct  6 11:32:16 2014 francois guergadic
** Last update Mon Oct  6 11:37:20 2014 francois guergadic
*/

int	my_str_isalpha(char *str)
{
  int   i;

  i = 0;
  while (str[i] != '\0')
    {
      if (((str[i] > 65) && (str[i] < 91)) || ((str[i] > 96) && (str[i] < 123)))
	i++;
      else
	return (0);
    }
  return (1);
}
