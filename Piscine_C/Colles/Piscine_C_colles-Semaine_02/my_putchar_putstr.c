/*
** my_putchar_putstr.c for my_putchar and my_putstr in /home/guerga_a/rendu/Piscine_C_colles-Semaine_02
** 
** Made by francois guergadic
** Login   <guerga_a@epitech.net>
** 
** Started on  Sat Oct 11 14:56:34 2014 francois guergadic
** Last update Sat Oct 11 16:22:09 2014 francois guergadic
*/

void    my_putchar(char c)
{
  write(1, &c, 1);
}

void    my_putstr(char *str)
{
  int   i;

  i = 0;
  while (str[i])
    {
      my_putchar(str[i]);
      i++;
    }
}
