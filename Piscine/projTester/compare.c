/*
** compare.c for compare in /home/guerga_a/Piscine/projTester
** 
** Made by francois guergadic
** Login   <guerga_a@epitech.net>
** 
** Started on  Fri Jun 19 11:09:05 2015 francois guergadic
** Last update Fri Jun 19 14:55:34 2015 francois guergadic
*/

#include "projTester.h"

int	my_compare(char *file, char *str1, t_test *test)
{
  char	*str;

  if (str1 == NULL)
    return (1);
  str = my_read(file);
  if (strstr(str, str1) != NULL)
    {
      printf("TEST OK\n");
      test->OK++;
      unlink(file);
      return (0);
    }
  printf("TEST KO\n");
  test->KO++;
  unlink(file);
  return (0);
}
