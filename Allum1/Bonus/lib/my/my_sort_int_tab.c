/*
** my_sort_int_tab.c for sort in tab in /home/guerga_a/B1/Sys_Unix/PSU_2014_my_ls/lib
** 
** Made by francois guergadic
** Login   <guerga_a@epitech.net>
** 
** Started on  Sat Nov 29 12:41:24 2014 francois guergadic
** Last update Tue Feb  3 13:28:52 2015 francois guergadic
*/

void	my_sort_int_tab(int *_tab, int size)
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
          if (_tab[i] > _tab[i + 1])
            {
              sort = 0;
              my_swap(&_tab[i], &_tab[i + 1]);
            }
          i = i + 1;
        }
      nb++;
    }
}
