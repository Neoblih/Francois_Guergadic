/*
** prerequis.c for prerequis in /home/guerga_a/Piscine/FASTAtools
**
** Made by francois guergadic
** Login   <guerga_a@epitech.net>
**
** Started on  Wed Jun 24 09:17:36 2015 francois guergadic
** Last update Thu Jun 25 14:45:11 2015 francois guergadic
*/

#include <stdlib.h>

char	my_maj(char c)
{
  if (c >= 'a' && c <= 'z')
    return (c - 'a' + 'A');
  return (c);
}

char	my_min(char c)
{
  if (c >= 'A' && c <= 'Z')
    return (c - 'A' + 'a');
  return (c);
}

int	is_sep(char c)
{
  if (c >= 'a' && c <= 'z')
    return (0);
  if (c >= 'A' && c <= 'Z')
    return (0);
  if (c >= '0' && c <= '9')
    return (0);
  return (1);
}

char	*my_strcapitalize_synthese(char *str)
{
  int	i;

  i = 0;
  if (str == NULL)
    return (NULL);
  while (str[i] && str[i + 1])
    {
      if (is_sep(str[i]) == 1 && is_sep(str[i + 1]) == 0)
	str[i + 1] = my_maj(str[i + 1]);
      else if (i == 0)
	str[i] = my_maj(str[i]);
      else
	str[i + 1] = my_min(str[i + 1]);
      i++;
    }
  return (str);
}
