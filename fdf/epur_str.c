/*
** epur_str.c for epur str in /home/guerga_a/Igraph/FDF
** 
** Made by francois guergadic
** Login   <guerga_a@epitech.net>
** 
** Started on  Tue Oct 28 17:18:53 2014 francois guergadic
** Last update Sun Dec  7 11:09:45 2014 francois guergadic
*/

#include <stdlib.h>

char    *epur_str(char *str)
{
  int   i;
  int   j;
  int   in_str;

  in_str = 0;
  i = 0;
  if (str == NULL)
    return (NULL);
  while (str[i])
    {
      if (in_str == 0)
        {
          if (str[i] == ' ')
            {
              j = i;
              while (str[j++] && str[j])
		str[j - 1] = str[j];
              str[j] = '\0';
              i = i - 1;
            }
          else
            in_str = 1;
        }
      if (str[i] == ' ' && (str[i + 1] == ' ' || str[i + 1] == '\0'))
        {
          j = i;
          while (str[j++] && str[j])
	    str[j - 1] = str[j];
          str[j] = '\0';
          i = i - 1;
        }
      i = i + 1;
    }
  return (str);
}
