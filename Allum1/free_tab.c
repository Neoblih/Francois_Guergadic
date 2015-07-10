/*
** free_tab.c for free tab in /home/guerga_a/B1/Prog_Elem/Allum1/init_function
** 
** Made by francois guergadic
** Login   <guerga_a@epitech.net>
** 
** Started on  Fri Feb 13 21:43:34 2015 francois guergadic
** Last update Fri Feb 13 21:44:04 2015 francois guergadic
*/

#include "allum1.h"

void    free_tab(char **_tab)
{
  int   i;

  i = 0;
  while (_tab[i])
    {
      free(_tab[i]);
      i++;
    }
  free(_tab[i]);
  free(_tab);
}
