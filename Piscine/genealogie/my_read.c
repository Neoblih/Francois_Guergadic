/*
** my_read.c for read in /home/guerga_a/Piscine/genealogie
**
** Made by francois guergadic
** Login   <guerga_a@epitech.net>
**
** Started on  Thu Jul  2 16:18:32 2015 francois guergadic
** Last update Thu Jul  2 16:19:17 2015 francois guergadic
*/

#include "genealogie.h"

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

char	*my_read(char *path)
{
  int	fd;
  char	*result;
  char	buffer[BUFF_SIZE + 1];
  int	rd;

  if ((fd = open(path, O_RDONLY)) < 0)
    {
      printf("! Fichier mal formaté !\n");
      return (NULL);
    }
  if ((result = malloc(sizeof(char))) == 0)
    return (NULL);
  result[0] = '\0';
  while ((rd = read(fd, buffer, BUFF_SIZE)) > 0)
    {
      buffer[rd] = '\0';
      result = my_realloc(result, rd + 1);
      result = strcat(result, buffer);
    }
  return (result);
}
