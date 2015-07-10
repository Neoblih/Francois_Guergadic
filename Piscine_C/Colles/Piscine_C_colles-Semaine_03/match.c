/*
** match.c for match functs in /home/guerga_a/Colles/Piscine_C_colles-Semaine_03
** 
** Made by francois guergadic
** Login   <guerga_a@epitech.net>
** 
** Started on  Sat Oct 25 18:29:15 2014 francois guergadic
** Last update Sat Oct 25 22:36:02 2014 francois guergadic
*/

#include "./include/mycolle.h"

int	match(struct s_colle colle, char **tab, int height, int length)
{
  int	i;

  i = 0;
  if (height == 1 && length == 1)
    {
      if (tab[0][0] != colle.case_one)
	return (0);
    }
  while (tab[i + 1])
    {
      if (i == 0)
	{
	  if (check_first_line(colle, tab[i], length) == 0)
	    return (0);
	}
      else if (i == length)
	{
	  if (check_last_line(colle, tab[i], length) == 0)
	    return (0);
	}
      else
	{
	  if (check_column(colle, tab[i], length) == 0)
	    return (0);
	}
      i = i + 1;
    }
  return (1);
}

int	check_first_line(struct s_colle colle, char *str, int length)
{
  int	i;

  i = 1;
  if (str[0] != colle.left_up)
    return (0);
  if (str[length - 1] != colle.right_up)
    return (0);
  while (i < length - 1)
    {
      if (str[i] != colle.lign)
	return (0);
      i = i + 1;
    }
  return (1);
}

int	check_last_line(struct s_colle colle, char *str, int length)
{
  int	i;

  i = 1;
  if (str[0] != colle.left_down)
    return (0);
  if (str[length - 1] != colle.right_down)
    return (0);
  while (i < length - 1)
    {
      if (str[i] != colle.lign)
	return (0);
      i = i + 1;
    }
  return (1);
}

int	check_column(struct s_colle colle, char *str, int length)
{
  int	i;

  i = 1;
  if (str[0] != colle.colomn)
    return (0);
  if (str[length -1 ] != colle.colomn)
    return (0);
  while (i < length - 1)
    {
      if (str[i] != ' ')
        return (0);
      i = i + 1;
    }
  return (1);
}
