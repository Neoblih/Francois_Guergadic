/*
** my_revstr.c for revstr in /home/guerga_a/B1/Sys_Unix/PSU_2014_my_ls/lib
** 
** Made by francois guergadic
** Login   <guerga_a@epitech.net>
** 
** Started on  Sat Nov 29 12:41:06 2014 francois guergadic
** Last update Sat Nov 29 12:41:08 2014 francois guergadic
*/

char	*my_revstr(char *str)
{
  int	i;
  int	j;
  int	size_max;
  int	temp;

  i = 0;
  j = 0;
  while (str[i] != '\0')
    i++;
  i--;
  size_max = i;
  while (j <= size_max / 2)
    {
      temp = str[i];
      str[i] = str[j];
      str[j] = temp;
      i--;
      j++;
    }
  return (str);
}
