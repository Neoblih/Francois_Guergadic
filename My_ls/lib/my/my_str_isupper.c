/*
** my_str_isupper.c for str_isupper in /home/guerga_a/B1/Sys_Unix/PSU_2014_my_ls/lib
** 
** Made by francois guergadic
** Login   <guerga_a@epitech.net>
** 
** Started on  Sat Nov 29 12:46:00 2014 francois guergadic
** Last update Sat Nov 29 12:46:03 2014 francois guergadic
*/

int	my_str_isupper(char *str)
{
  int   i;

  i = 0;
  while (str[i] <= 90 && str[i] >= 65)
    i++;
  if (str[i] == '\0')
    return (1);
  return (0);
}
