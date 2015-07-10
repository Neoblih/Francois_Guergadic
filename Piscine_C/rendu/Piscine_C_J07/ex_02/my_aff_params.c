/*
** my_aff_params.c for my_aff_params in /home/guerga_a/rendu/Piscine_C_J07/ex_02
** 
** Made by francois guergadic
** Login   <guerga_a@epitech.net>
** 
** Started on  Tue Oct  7 12:16:08 2014 francois guergadic
** Last update Tue Oct  7 16:51:18 2014 francois guergadic
*/

int	main(int argc, char **argv)
{
  int	i;

  i = 0;
  while (i < argc)
    {
      my_putstr(argv[i]);
      my_putchar('\n');
      i++;
    }
}
