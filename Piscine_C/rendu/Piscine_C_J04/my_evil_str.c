/*
** my_evil_str.c for my_evil_str in /home/guerga_a/rendu/Piscine_C_J04
** 
** Made by francois guergadic
** Login   <guerga_a@epitech.net>
** 
** Started on  Thu Oct  2 12:05:55 2014 francois guergadic
** Last update Fri Oct 10 16:08:05 2014 francois guergadic
*/

#include <stdlib.h>

char	*my_evil_str(char *str)
{
  int i;
  int j;
  char str2[1];

  i=0;
  while (str[i] != '\0')
    {
      i++;
    }
  i = i - 1;
  j=0;
  while (j < i)
    {
      my_swap(str[i], str[j]);
      i++;
      j--;
    }
  return (str);
}
