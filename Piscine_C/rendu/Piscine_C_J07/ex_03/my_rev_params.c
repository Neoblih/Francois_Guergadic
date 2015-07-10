/*
** my_rev_params.c for my_rev_params in /home/guerga_a/rendu/Piscine_C_J07/ex_03
** 
** Made by francois guergadic
** Login   <guerga_a@epitech.net>
** 
** Started on  Tue Oct  7 12:24:31 2014 francois guergadic
** Last update Tue Oct  7 16:51:48 2014 francois guergadic
*/

int	main(int argc, char **argv)
{
  int	i;

  i = argc;
  while (i > 0)
    {
      my_putstr(argv[i-1]);
      my_putchar('\n');
      i--;
    }
}
