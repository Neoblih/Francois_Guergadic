/*
** colle3.c for colle3 in /home/guerga_a/Colles/Piscine_C_colles-Semaine_03
** 
** Made by francois guergadic
** Login   <guerga_a@epitech.net>
** 
** Started on  Sat Oct 25 16:08:44 2014 francois guergadic
** Last update Sun Oct 26 15:08:23 2014 francois guergadic
*/

#include "./include/my.h"
#include "./include/mycolle.h"

t_colle t_colle1();
t_colle t_colle2();
t_colle t_colle3();
t_colle t_colle4();
t_colle t_colle5();
void	aff_result(int match, int i, int height, int length);
void	double_result();
void	no_result();

int     tab_length(char *tab)
{
  int   i;
  
  i = 0;
  while (tab[i] && tab[i] != '\n')
    i = i + 1;
  return (i);
}

int	tab_height(char *tab)
{
  int   i;
  int	count;
  
  count = 0;
  i = 0;
  while (tab[i])
    {
      if (tab[i] == '\n')
	count = count + 1;
      i = i + 1;
    }
  return (count);
}

t_colle	recup_colle(int i)
{
  struct s_colle colle;

  if (i == 1)
    colle = t_colle1();
  if (i == 2)
    colle = t_colle2();
  if (i == 3)
    colle = t_colle3();
  if (i == 4)
    colle = t_colle4();
  if (i == 5)
    colle = t_colle5();
  return (colle);
}

int	what_is_this_glue(char *buff)
{
  int	i;
  int	total;
  int	ref;

  i = 1;
  while (i <= 5)
    {
      total = total + match(recup_colle(i), str_to_tab(buff, tab_height(buff), tab_length(buff)),
			    tab_height(buff), tab_length(buff)), i, tab_height(buff), tab_length(buff);
      i = i + 1;
    }
  if (total == 0)
    no_result();
  i = 1;
  while (i <= 5)
    {
      ref = total;
      aff_result(match(recup_colle(i), str_to_tab(buff, tab_height(buff), tab_length(buff)),
		       tab_height(buff), tab_length(buff)), i, tab_height(buff), tab_length(buff));
      total = total - match(recup_colle(i), str_to_tab(buff, tab_height(buff), tab_length(buff)),
                            tab_height(buff), tab_length(buff)), i, tab_height(buff), tab_length(buff);
      if (total != ref && total != 0)
	double_result();
      i = i + 1;
    }
}
