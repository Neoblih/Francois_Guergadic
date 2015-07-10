/*
** my_read.c for read in /home/guerga_a/colle-6-B41L0
**
** Made by francois guergadic
** Login   <guerga_a@epitech.net>
**
** Started on  Mon Jun  1 18:58:58 2015 francois guergadic
** Last update Wed Jun 24 09:57:52 2015 francois guergadic
*/

#include "FASTAtools.h"

char	*my_realloc(char *dest, int nb)
{
  char	*result;

  if ((result = malloc(sizeof(char) * (strlen(dest) + nb))) == NULL)
    return (NULL);
  result[0] = '\0';
  result = strcat(result, dest);
  free(dest);
  return (result);
}

char	*my_read()
{
  char	*result;
  char	buffer[BUFF_SIZE + 1];
  int	rd;

  if ((result = malloc(sizeof(char))) == 0)
    return (NULL);
  result[0] = '\0';
  while ((rd = read(0, buffer, BUFF_SIZE)) > 0)
    {
      buffer[rd] = '\0';
      result = my_realloc(result, rd + 1);
      result = strcat(result, buffer);
    }
  return (result);
}
