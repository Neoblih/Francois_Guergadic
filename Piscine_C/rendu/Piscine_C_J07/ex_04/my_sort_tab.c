/*
** my_sort_tab.c for my_sort_tab in /home/guerga_a/rendu/Piscine_C_J07/ex_04
** 
** Made by francois guergadic
** Login   <guerga_a@epitech.net>
** 
** Started on  Tue Oct  7 14:01:59 2014 francois guergadic
** Last update Tue Oct  7 17:22:03 2014 francois guergadic
*/

char	*my_strcpy(char *dest, char *str);

void	my_void_swap(void *a, void *b)
{
  void	*tmp;

  tmp = *(void**)a;
  *(void**)a = *(void**)b;
  *(void**)b = tmp;
}

char	**my_sort_tab(char **tab, int size)
{
  int	i;

  i = 0;
  while (i < size - 1)
    {
      if (my_strcmp(tab[i],tab[i+1]) <= 0)
	{
	  i++;
	}
      else
	{
	  my_void_swap(&tab[i], &tab[i + 1]);
	  i = 0;
	}
    }
  return (tab);
}
