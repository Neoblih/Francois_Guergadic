/*
** my_strlowcase.c for my_strlowcase in /home/guerga_a/B1/Sys_Unix/PSU_2014_my_ls/lib
** 
** Made by francois guergadic
** Login   <guerga_a@epitech.net>
** 
** Started on  Sat Nov 29 12:46:38 2014 francois guergadic
** Last update Sat Nov 29 12:46:39 2014 francois guergadic
*/

char	*my_strlowcase(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    {
      if ((str[i] >= 65) && (str[i] <= 90))
	str[i] = str[i] + 32;
      i++;
    }
  return (str);
}
