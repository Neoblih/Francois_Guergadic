/*
** my_strcat.c for my_strcat in /home/guerga_a/rendu/Piscine_C_J07/ex_01
** 
** Made by francois guergadic
** Login   <guerga_a@epitech.net>
** 
** Started on  Tue Oct  7 17:09:28 2014 francois guergadic
** Last update Tue Oct  7 17:35:51 2014 francois guergadic
*/

char	*my_strcat(char *dest, char *src)
{
  int i;
  int j;

  i = 0;
  j = 0;
  while (dest[i] != '\0')
    {
      i++;
    }
  while (src[j] != '\0')
    {
      dest[i + j] = src[j];
      j++;
    }
  dest[i+j] = '\0';
  return (dest);
}
