/*
** prompt.c for prompt in /home/guerga_a/B1/Sys_Unix/PSU_2014_minishell1
** 
** Made by francois guergadic
** Login   <guerga_a@epitech.net>
** 
** Started on  Mon Jan 26 13:58:23 2015 francois guergadic
** Last update Mon Jan 26 14:00:24 2015 francois guergadic
*/

#include "./include/mysh.h"

void    my_color_putchar2(char c)
{
  write(1, "\033[1;33m", 8);
  write(1, &c, 1);
  write(1, "\033[0m", 5);
}

void    my_color_putstr2(char *s)
{
  int   i;

  i = 0;
  while (s[i])
    {
      my_color_putchar2(s[i]);
      i++;
    }
}

void    my_color_putchar(char c)
{
  write(1, "\033[1;36m", 8);
  write(1, &c, 1);
  write(1, "\033[0m", 5);
}

void    my_color_putstr(char *s)
{
  int   i;

  i = 0;
  while (s[i])
    {
      my_color_putchar(s[i]);
      i++;
    }
}

void    aff_prompt(void)
{
  my_color_putstr("-[");
  my_color_putstr2("Minishell1");
  my_color_putstr("]-> ");
}
