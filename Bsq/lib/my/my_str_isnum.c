/*
** my_str_isnum.c for str_isnum in /home/guerga_a/B1/Sys_Unix/PSU_2014_my_ls/lib
** 
** Made by francois guergadic
** Login   <guerga_a@epitech.net>
** 
** Started on  Sat Nov 29 12:45:10 2014 francois guergadic
** Last update Sat Nov 29 12:45:11 2014 francois guergadic
*/

int	my_str_isnum(char *str)
{
  int	i;

  i = 0;
  while (str[i] <= 57 && str[i] >= 48)
    i++;
  if (str[i] == '\0')
    return (1);
  return (0);
}
