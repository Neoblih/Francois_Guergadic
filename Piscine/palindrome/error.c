/*
** error.c for error in /home/guerga_a/Piscine/palindrome
**
** Made by francois guergadic
** Login   <guerga_a@epitech.net>
**
** Started on  Sat Jun 27 17:04:26 2015 francois guergadic
** Last update Sat Jun 27 17:31:54 2015 francois guergadic
*/

#include "palindrome.h"

int	error(char **av)
{
  int	i;
  int	temp;

  i = 0;
  temp = -1;
  while (av[i] && temp != i)
    {
      temp = i;
      if (strcmp(av[i], "reverse") == 0)
	i++;
      else if (strncmp(av[i], "<=", 2) == 0 && strlen(av[i]) > 2)
	i++;
      else if (strncmp(av[i], ">=", 2) == 0 && strlen(av[i]) > 2)
	i++;
      else if (strncmp(av[i], "<", 1) == 0 && strlen(av[i]) > 1 &&
	       av[i][1] != '=')
	i++;
      else if (strncmp(av[i], ">", 1) == 0 && strlen(av[i]) > 1 &&
	       av[i][1] != '=')
	i++;
      if (temp == i)
	return (1);
    }
  return (0);
}
