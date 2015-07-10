/*
** my_free.c for free tab in /home/guerga_a/Piscine/SBMLparser/global
** 
** Made by francois guergadic
** Login   <guerga_a@epitech.net>
** 
** Started on  Tue Jun 16 13:21:51 2015 francois guergadic
** Last update Tue Jun 16 14:14:24 2015 francois guergadic
*/

#include <stdlib.h>

void	free_tab(char **tab)
{
  int	i;

  i = 0;
  while (tab[i])
    {
      free(tab[i]);
      i++;
    }
  free(tab[i]);
  free(tab);
}
