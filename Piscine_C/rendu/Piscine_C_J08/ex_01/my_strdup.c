/*
** my_strdup.c for strdup in /home/guerga_a/rendu/Piscine_C_J08/ex_01
** 
** Made by francois guergadic
** Login   <guerga_a@epitech.net>
** 
** Started on  Wed Oct  8 10:17:44 2014 francois guergadic
** Last update Wed Oct  8 18:10:33 2014 francois guergadic
*/

#include <stdlib.h>

char	*my_strdup(char *src)
{
  int	i;
  char	*dest;

  i = 0;
  while (src[i])
    {
      i = i + 1;
    }
  dest = malloc(i + 1);
  if (dest == NULL)
    return ("Malloc Failed");
  i = 0;
  while (src[i])
    {
      dest[i] = src[i];
      i = i + 1;
    }
  dest[i] = '\0';
  return (dest);
}
