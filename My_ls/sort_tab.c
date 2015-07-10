/*
** sort_tab.c for sort_tab in /home/guerga_a/B1/Sys_Unix/PSU_2014_my_ls
** 
** Made by francois guergadic
** Login   <guerga_a@epitech.net>
** 
** Started on  Sat Nov 29 12:57:25 2014 francois guergadic
** Last update Sat Nov 29 13:05:53 2014 francois guergadic
*/

#include "./include/my.h"

char    *rm_dot(char *str)
{
  if (str[0] == '.')
    return (&str[1]);
  else
    return (str);
}

void    sort_tab(char **tab)
{
  int   i;
  char  *temp;

  i = 0;
  while (tab[i] && tab[i + 1])
    {
      if (my_strcmp(rm_dot(tab[i]), rm_dot(tab[i + 1])) > 0)
        {
          temp = tab[i];
          tab[i] = tab[i + 1];
          tab[i + 1] = temp;
          i = 0;
        }
      else
        i++;
    }
}
