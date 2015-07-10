/*
** my_other_putchar.c for other write in /home/guerga_a/B1/Sys_Unix/PSU_2014_minishell1
** 
** Made by francois guergadic
** Login   <guerga_a@epitech.net>
** 
** Started on  Mon Jan 26 13:27:34 2015 francois guergadic
** Last update Fri Jan 30 12:34:44 2015 francois guergadic
*/

#include "./include/mysh.h"

void	my_err_putchar(char c)
{
  write(2, &c, 1);
}

void	my_puterr(char *s)
{
  int	i;

  i = 0;
  while (s[i])
    {
      my_err_putchar(s[i]);
      i++;
    }
}
