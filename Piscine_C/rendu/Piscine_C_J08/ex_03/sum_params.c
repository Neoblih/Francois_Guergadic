/*
** sum_params.c for sum_params in /home/guerga_a/rendu/Piscine_C_J08/ex_03
** 
** Made by francois guergadic
** Login   <guerga_a@epitech.net>
** 
** Started on  Wed Oct  8 17:14:15 2014 francois guergadic
** Last update Wed Oct  8 18:03:40 2014 francois guergadic
*/

#include <stdlib.h>

char	*sum_params(int argc, char **argv)
{
  int	total_length;
  int	i;
  char	*dest;

  i = 0;
  total_length = 0;
  while (i < argc - 1)
    {
      total_length = total_length + my_strlen(argv[i]);
      i = i + 1;
    }
  total_length = total_length + (argc);
  dest = malloc (total_length);
  if (dest == NULL)
    return ("Allocation failed");
  i = 0;
  while (argv[i + 1] != '\0')
    {
      my_strcat(dest, argv[i]);
      my_strcat(dest, "\n");
      i = i + 1;
    }
  my_strcat(dest, argv[i]);
  return (dest);
}
