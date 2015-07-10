/*
** my_strncpy.c for strncpy in /home/guerga_a/B1/Sys_Unix/PSU_2014_my_ls/lib
** 
** Made by francois guergadic
** Login   <guerga_a@epitech.net>
** 
** Started on  Sat Nov 29 12:47:54 2014 francois guergadic
** Last update Sat Nov 29 12:47:56 2014 francois guergadic
*/

char	*my_strncpy(char *dest, char *src, int n)
{
  int	i;

  i = 0;
  while (src[i] != '\0' || i <= n)
    {
      dest[i] = src[i];
      i++;
    }
  while (i <= n)
    {
      dest[i] = '\0';
      i++;
    }
  return (dest);
}
