/*
** my_read.c for read in /home/guerga_a/colle-6-B41L0
**
** Made by francois guergadic
** Login   <guerga_a@epitech.net>
**
** Started on  Mon Jun  1 18:58:58 2015 francois guergadic
** Last update Sat Jun 20 12:47:01 2015 francois guergadic
*/

#include "projTester.h"

char	**get_all_test(char *str)
{
  char	**tab;

  tab = my_str_to_wordtab(remove_double(str), '\n');
  free(str);
  return (tab);
}

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
