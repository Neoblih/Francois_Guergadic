/*
** aff.c for aff in /home/guerga_a/B1/Sys_Unix/PSU_2014_my_ls
** 
** Made by francois guergadic
** Login   <guerga_a@epitech.net>
** 
** Started on  Sat Nov 29 12:53:45 2014 francois guergadic
** Last update Sat Nov 29 14:23:55 2014 francois guergadic
*/

#include "./include/my.h"
#include "./include/my_ls.h"

void    aff_ls_a(char **tab)
{
  int   i;

  i = 0;
  while (tab[i] && tab[i + 1])
    {
      my_putstr(tab[i]);
      my_putchar(' ');
      my_putchar(' ');
      i = i + 1;
    }
  my_putstr(tab[i]);
  free_tab(tab);
  my_putchar('\n');
}

void    aff_ls(char **tab)
{
  int   i;

  i = 0;
  while (tab[i] && tab[i + 1])
    {
      if (tab[i][0] != '.')
        {
          my_putstr(tab[i]);
          my_putchar(' ');
          my_putchar(' ');
        }
      i = i + 1;
    }
  if (tab[i][0] != '.')
    my_putstr(tab[i]);
  free_tab(tab);
  my_putchar('\n');
}
