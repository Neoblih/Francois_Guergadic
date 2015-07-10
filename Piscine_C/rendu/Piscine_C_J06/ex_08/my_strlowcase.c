/*
** my_strlowcase.c for my_strlowcase in /home/guerga_a/rendu/Piscine_C_J06/ex_08
** 
** Made by francois guergadic
** Login   <guerga_a@epitech.net>
** 
** Started on  Mon Oct  6 11:09:47 2014 francois guergadic
** Last update Mon Oct  6 16:17:47 2014 francois guergadic
*/

char	*my_strlowcase(char *str)
{
  int    i;

  i = 0;
  while (str[i] != '\0')
    {
      if ((str[i] < 91) && (str[i] > 64))
	{
	  str[i] = (str[i] + 32);
	}
      i++;
    }
  return (str);
}
