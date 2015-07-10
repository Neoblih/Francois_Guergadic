/*
** my_putstr.c for my_putstr in /home/guerga_a/rendu/Piscine_C_J04
** 
** Made by francois guergadic
** Login   <guerga_a@epitech.net>
** 
** Started on  Thu Oct  2 11:23:23 2014 francois guergadic
** Last update Fri Oct  3 22:43:32 2014 francois guergadic
*/

int	my_putstr(char *str)
{
  int i;

  i=0;
  while (str[i] != '\0')
    {
      my_putchar(str[i]);
      i++;
    }
}
