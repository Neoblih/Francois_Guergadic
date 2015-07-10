/*
** tools.c for tools in /home/guerga_a/Piscine/projTester
** 
** Made by francois guergadic
** Login   <guerga_a@epitech.net>
** 
** Started on  Fri Jun 19 19:22:02 2015 francois guergadic
** Last update Fri Jun 19 19:31:17 2015 francois guergadic
*/

#include "projTester.h"

t_test		*init_struct(void)
{
  t_test	*test;

  if ((test = malloc(sizeof(test) * 4)) == NULL)
    return (NULL);
  test->OK = 0;
  test->KO = 0;
  return (test);
}

void	aff_stats(t_test *test)
{
  dup2(1, 1);
  printf("***************************************\n");
  printf("tests valides : %i\n", test->OK);
  printf("tests non valides : %i\n", test->KO);
  printf("***************************************\n");
}
