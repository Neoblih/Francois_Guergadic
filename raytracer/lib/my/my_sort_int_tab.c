/*
** my_sort_int_tab.c for sort in tab in /home/guerga_a/B1/Sys_Unix/PSU_2014_my_ls/lib
** 
** Made by francois guergadic
** Login   <guerga_a@epitech.net>
** 
** Started on  Sat Nov 29 12:41:24 2014 francois guergadic
** Last update Wed Dec  3 10:30:01 2014 francois guergadic
*/

int	my_swap(int *a, int *b);

void	my_sort_int_tab(int *tab, int size)
{
  int   i;
  int   sort;
  int   nb;

  nb = 0;
  sort = 0;
  while (sort == 0)
    {
      i = 0;
      sort = 1;
      while ((i + 1) < size)
        {
          if (tab[i] > tab[i + 1])
            {
              sort = 0;
              my_swap(&tab[i], &tab[i + 1]);
            }
          i = i + 1;
        }
      nb++;
    }
}
