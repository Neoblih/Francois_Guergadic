/*
** my_read.c for read in /home/guerga_a/colle-6-B41L0
** 
** Made by francois guergadic
** Login   <guerga_a@epitech.net>
** 
** Started on  Mon Jun  1 18:58:58 2015 francois guergadic
** Last update Wed Jun 17 15:30:21 2015 francois guergadic
*/

#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "SBMLparser.h"

int	my_strcmp(char *s1, char *s2)
{
  int	i;

  i = 0;
  while (s1[i] && s2[i])
    {
      if (s1[i] != s2[i])
	return (1);
      i++;
   }
  if (my_strlen(s1) != my_strlen(s2))
    return (1);
  return (0);
}

char	*my_strcat(char *dest, char *srcs)
{
  int	i;
  int	j;

  i = 0;
  j = 0;
  while (dest[i])
    i++;
  if (srcs != NULL)
    {
      while (srcs[j])
	{
	  dest[i + j] = srcs[j];
	  j++;
	}
      dest[i + j] = '\0';
    }
  return (dest);
}

int	my_strlen(char *str)
{
  int	i;

  i = 0;
  if (str[i])
    {
      while (str[i])
	i++;
      return (i);
    }
  return (0);
}

char	*my_realloc(char *dest, int nb)
{
  char	*result;

  if ((result = malloc(sizeof(char) * (my_strlen(dest) + nb))) == NULL)
    return (NULL);
  result[0] = '\0';
  result = my_strcat(result, dest);
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
      printf("Fichier incorrect\n");
      return (NULL);
    }
  if ((result = malloc(sizeof(char))) == 0)
    return (NULL);
  result[0] = '\0';
  while ((rd = read(fd, buffer, BUFF_SIZE)) > 0)
    {
      buffer[rd] = '\0';
      result = my_realloc(result, rd + 1);
      result = my_strcat(result, buffer);
    }
  return (result);
}
