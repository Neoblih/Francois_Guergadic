/*
** colle2-1.c for colle 1 - 2eme semaine in /home/guerga_a/rendu/Piscine_C_colles-Semaine_02
** 
** Made by francois guergadic
** Login   <guerga_a@epitech.net>
** 
** Started on  Sat Oct 11 12:56:13 2014 francois guergadic
** Last update Tue Feb  3 12:20:24 2015 francois guergadic
*/

#include <stdlib.h>

char	*recup(char *str, int n)
{
  int	size;
  int	i;
  char	*dest;
  int	j;

  j = 0;
  i = n;
  size = my_strlen(str);
  dest = malloc(n);
  while (i > 0)
    {
      dest[j] = str[size - i + 1];
      i = i - 1;
      j = j + 1;
    }
  return (dest);
}

char    *recup2(char *str, int n)
{
  char  *dest;
  int   i;

  i = 0;
  dest = malloc(n + 1);
  // Verifier le malloc
  while (i < n)
    {
      dest[i] = str[i];
      i = i + 1;
    }
  dest[i] = '\0';
  return (dest);
}

void	my_first_case(char *str, int speed)
{
  int	i;
  char	*temp;

  i = 0;
    while (str[i])
    {
      temp = recup(str + 1, i + 1),
      my_putchar('\r');
      my_putstr(temp);
      free(temp);
      usleep(speed);
      i = i + 1;
    }
    temp = recup(str, i + 1),
    my_putchar('\r');
    my_putstr(temp);
    free(temp);
    usleep(speed);
}

void	affichage_espace(int size)
{
  int	i;

  i = 0;
  while (i < size)
    {
      my_putchar(' ');
      i = i + 1;
    }
}

void	my_second_case(char *str, int speed)
{
  int	j;
  char	*temp;
  int	k;

  j = 0;
  my_putchar('\r');
  affichage_espace(my_strlen(str));
  while (str[j])
    {
      k = j;
      temp = recup2(str, j + 1);
      while (k >= 0)
	{
	  my_putchar('\b');
	  k--;
	}
      my_putstr(temp);
      free(temp);
      usleep(speed);
      j = j + 1;
    }
}
