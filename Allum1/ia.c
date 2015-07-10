/*
** ia.c for ia in /home/guerga_a/B1/Prog_Elem/Allum1
** 
** Made by francois guergadic
** Login   <guerga_a@epitech.net>
** 
** Started on  Thu Feb  5 14:40:37 2015 francois guergadic
** Last update Sat Feb 21 11:24:09 2015 francois guergadic
*/

#include "allum1.h"

void	next_move(char **_tab, t_cursor *ia_c)
{
  int	i;
  int	j;

  i = -1;
  while (_tab[i++ + 1] && ia_c->select == 0)
    {
      j = -1;
      while (_tab[i][j++ + 1])
	{
	  if (_tab[i][j] == '|' && ia_c->select == 0)
	    {
	      ia_c->y = i;
	      ia_c->x = j;
	      ia_c->select = 1;
	    }
	  else if (_tab[i][j] == '|')
	    {
	      ia_c->l++;
	    }
	}
    }
}

int	ia_turn(char **_tab)
{
  t_cursor *ia_c;

  my_putstr("\n\n  **** IA TURN ****\n");
  if ((ia_c = malloc(sizeof(ia_c) * 2)) == NULL)
    return (1);
  ia_c->x = 0;
  ia_c->y = 0;
  ia_c->select = 0;
  ia_c->l = 0;
  next_move(_tab, ia_c);
  suppr(ia_c, _tab);
  free(ia_c);
  return (0);
}
