/*
** reverse.c for reverse in /home/guerga_a/Piscine/FASTAtools/part4
**
** Made by francois guergadic
** Login   <guerga_a@epitech.net>
**
** Started on  Wed Jun 24 12:26:53 2015 francois guergadic
** Last update Thu Jun 25 12:51:54 2015 francois guergadic
*/

#include "FASTAtools.h"

void	aff_tab(char **tab)
{
  int	i;

  i = 0;
  while (tab[i])
    {
      printf("%s\n", tab[i]);
      i++;
    }
}

int	sub_tab_len(char **tab)
{
  int	i;
  int	len;

  i = (len = 0);
  while (tab[i])
    len = len + strlen(tab[i++]);
  return (len);
}

int	tab_len(char **tab)
{
  int	i;

  i = 0;
  while (tab[i])
    {
      i++;
    }
  return (i);
}

char	*get_k(char *str, int n)
{
  int	i;
  char	*result;

  i = 0;
  if ((result = malloc(sizeof(char) * (n + 1))) == NULL)
    return (NULL);
  while (i < n)
    {
      result[i] = str[i];
      i++;
    }
  result[i] = '\0';
  return (result);
}

char		**make_k(char **tab, int n)
{
  int	 	i;
  unsigned int	j;
  int		k;
  int		size;
  char		**result;

  size = sub_tab_len(tab) - (n - 1);
  if (size < 0)
    return (NULL);
  if ((result = malloc(sizeof(char*) * (size + 1))) == NULL)
    return (NULL);
  i = (k = 0);
  while (tab[i])
    {
      j = 0;
      while (tab[i][j] && (j + n - 1 < strlen(tab[i])))
	{
	  result[k] = get_k(&tab[i][j], n);
	  k++;
	  j++;
	}
      i++;
    }
  result[k] = NULL;
  return (result);
}

void	part_4(int k)
{
  char	*str;
  char	**seq_tab;
  char	**tab;

  str = my_read();
  seq_tab = create_seq_tab(str);
  free(str);
  tab = make_k(seq_tab, k);
  if (tab == NULL || tab[0] == NULL)
    {
      fprintf(stdout, "Usage: ./FASTAtools option [k]\n");
      exit(1);
    }
  free_tab(seq_tab);
  tab = sort_tab(tab);
  tab = remove_double(tab);
  aff_tab(tab);
  free_tab(tab);
}
