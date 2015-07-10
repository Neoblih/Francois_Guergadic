/*
** check_tools.c for tools in /home/guerga_a/Piscine/agenda/error
**
** Made by francois guergadic
** Login   <guerga_a@epitech.net>
**
** Started on  Mon Jun 29 10:27:52 2015 francois guergadic
** Last update Mon Jun 29 10:46:09 2015 francois guergadic
*/

#include "agenda.h"

int	count_word(char *str)
{
  int	i;
  int	count;

  i = 0;
  count = 1;
  while (str[i] && str[i + 1])
    {
      if (str[i] == ' ' && str[i + 1] != ' ')
	count++;
      i++;
    }
  return (count);
}

char	*get_word(char *str, int n)
{
  int	i;
  int	count;

  i = 0;
  count = 1;
  if (n == 1)
    return (str);
  while (str[i])
    {
      if (str[i] == ' ' && str[i + 1] != ' ')
	{
	  count++;
	  if (count == n)
	    return (&str[i + 1]);
	}
      i++;
    }
  return (NULL);
}

int	is_number(char *str)
{
  int	i;

  i = 0;
  while (str[i] && str[i] != ' ' && str[i] != '\n')
    {
      if (str[i] < '0' || str[i] > '9')
	return (0);
      i++;
    }
  return (1);
}

char	*remove_newline(char *str)
{
  int	i;

  i = 0;
  while (str[i])
    {
      if (str[i] == '\n')
	{
	  str[i] = '\0';
	  return (str);
	}
      i++;
    }
  return (str);
}
