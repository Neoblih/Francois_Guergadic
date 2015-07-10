/*
** my_strncat.c for strncat in /home/guerga_a/B1/Sys_Unix/PSU_2014_my_ls/lib
** 
** Made by francois guergadic
** Login   <guerga_a@epitech.net>
** 
** Started on  Sat Nov 29 12:46:58 2014 francois guergadic
** Last update Wed Dec  3 10:47:44 2014 francois guergadic
*/

char *my_strncat(char *dest, char *src, int nb)
{
  int	i;
  int	j;

  j = 0;
  i = 0;
  while (dest[i] != '\0')
    i++;
  while (j < nb && src[j] != '\0')
    {
      dest[i] = src[j];
      j++;
      i++;
    }
  dest[i] = '\0';
  return (dest);
}
