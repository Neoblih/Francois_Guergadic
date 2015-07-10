/*
** my_sort_params.c for my_sort_params in /home/guerga_a/rendu/Piscine_C_J07/ex_04
** 
** Made by francois guergadic
** Login   <guerga_a@epitech.net>
** 
** Started on  Tue Oct  7 14:17:03 2014 francois guergadic
** Last update Tue Oct  7 16:52:36 2014 francois guergadic
*/

char	**my_sort_double_tab(char **tab, int size);

int	main(int argc, char **argv)
{
  int i;

  i = 0;
  my_sort_tab(argv, argc);
  while (i < argc)
    {
      my_putstr(argv[i]);
      my_putchar('\n');
      i++;
    }
}
