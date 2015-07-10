/*
** reverse.c for reverse in /home/guerga_a/Piscine/FASTAtools/part4
**
** Made by francois guergadic
** Login   <guerga_a@epitech.net>
**
** Started on  Wed Jun 24 12:26:53 2015 francois guergadic
** Last update Thu Jun 25 15:49:40 2015 francois guergadic
*/

#include "FASTAtools.h"

void	aff_lol(char **tab)
{
  int	i;

  i = 0;
  while (tab[i])
    {
      printf("%s\n", tab[i]);
      i++;
    }
}

int	my_strstr(char *str)
{
  int	i;

  i = 0;
  while (str[i] && str[i + 1] && str[i + 2])
    {
      if (strncmp(&str[i], "TAA", 3) == 0 ||
	  strncmp(&str[i], "TGA", 3) == 0 ||
	  strncmp(&str[i], "TAG", 3) == 0)
	return (1);
      i+=3;
    }
  return (0);
}

int	my_aff(char *str, char **tab)
{
  int	i;
  int	tab_l;

  i = 0;
  if (strlen(str) < 6)
    return (1);
  if (my_strstr(str) == 0)
    return (1);
  if (strncmp(str, "ATG", 3) == 0)
    {
      tab_l = tab_len(tab);
      if ((tab[tab_l] = malloc(sizeof(char) * 200)) == NULL)
	return (1);
      tab[tab_l][0] = '\0';
      while (strncmp(&str[i], "TAA", 3) != 0 &&
	     strncmp(&str[i], "TGA", 3) != 0 &&
	     strncmp(&str[i], "TAG", 3) != 0)
	{
	  tab[tab_l][i] = str[i];
	  tab[tab_l][i + 1] = str[i + 1];
	  tab[tab_l][i + 2] = str[i + 2];
	  i+=3;
	}
      tab[tab_l][i] = '\0';
      tab[tab_l + 1] = NULL;
    }
  return (0);
}

void	aff_seq(char **tab)
{
  int	i;
  int	j;
  char	**res;

  if ((res = malloc(sizeof(char*) * 200)) == 0)
    exit(1);
  res[0] = NULL;
  i = 0;
  while (tab[i])
    {
      j = 0;
      while (tab[i][j])
	{
	  my_aff(&tab[i][j], res);
	  j++;
	}
      i++;
    }
  res = sort_tab(res);
  res = remove_double(res);
  aff_lol(res);
}

void	part_5()
{
  char	*str;
  char	**seq_tab;

  str = my_read();
  seq_tab = create_seq_tab(str);
  aff_seq(seq_tab);
  free(str);
  free_tab(seq_tab);
}
