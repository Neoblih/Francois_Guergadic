/*
** my_strncpy.c for my_strncpy in /home/guerga_a/rendu/Piscine_C_J06/ex_02
** 
** Made by francois guergadic
** Login   <guerga_a@epitech.net>
** 
** Started on  Mon Oct  6 09:00:39 2014 francois guergadic
** Last update Mon Oct  6 13:04:00 2014 francois guergadic
*/

char	*my_strncpy(char *dest, char *src, int n)
{
  int    count;

  count=0;
  while (count < n)
    {
      dest[count] = src[count];
      count++;
    }
  dest[count] = '\0';
  return (dest);
}
