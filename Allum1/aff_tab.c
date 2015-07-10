/*
** aff_tab.c for aff_tab.c in /home/guerga_a/B1/Prog_Elem/Allum1
** 
** Made by francois guergadic
** Login   <guerga_a@epitech.net>
** 
** Started on  Tue Feb  3 13:41:03 2015 francois guergadic
** Last update Sat Feb 21 11:04:23 2015 francois guergadic
*/

#include "allum1.h"

int     my_putint(int c)
{
  write(1, &c, 1);
  return (0);
}

void    my_clear(void)
{
  if (tgetent(0, "xterm") != 1)
    my_putstr("Error while loeading terminal\n");
  tputs(tgetstr("cl", 0), 1, &my_putint);
}

void    aff_tab(char **_tab)
{
  int   i;

  i = 0;
  while (_tab[i])
    {
      my_putstr(_tab[i]);
      my_putchar('\n');
      i++;
    }
}
