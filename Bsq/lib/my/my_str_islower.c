/*
** my_str_islower.c for str_islower in /home/guerga_a/B1/Sys_Unix/PSU_2014_my_ls/lib
** 
** Made by francois guergadic
** Login   <guerga_a@epitech.net>
** 
** Started on  Sat Nov 29 12:44:36 2014 francois guergadic
** Last update Sat Nov 29 12:44:39 2014 francois guergadic
*/

int	my_str_islower(char *str)
{
  int   i;

  i = 0;
  while (str[i] <= 97 && str[i] >= 122)
    i++;
  if (str[i] == '\0')
    return (1);
  return (0);
}
