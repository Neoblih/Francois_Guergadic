/*
** my_putchar.c for putchar in /home/guerga_a/B1/Sys_Unix/PSU_2014_my_ls/lib
** 
** Made by francois guergadic
** Login   <guerga_a@epitech.net>
** 
** Started on  Sat Nov 29 12:40:11 2014 francois guergadic
** Last update Sun Nov 30 19:39:02 2014 francois guergadic
*/

#include <unistd.h>

void	my_putchar(char c)
{
  write(1, &c, 1);
}
