/*
** game.c for game in /home/guerga_a/B1/Prog_Elem/Allum1/core_function
** 
** Made by francois guergadic
** Login   <guerga_a@epitech.net>
** 
** Started on  Fri Feb 13 21:24:58 2015 francois guergadic
** Last update Sat Feb 21 12:14:50 2015 francois guergadic
*/

#include "./allum1.h"

int     player_win(char **_tab)
{
  int   i;
  int   j;

  i = 0;
  while (_tab[i])
    {
      j = 0;
      while (_tab[i][j])
        {
          if (_tab[i][j] == '|')
            return (0);
          j++;
	}
      i++;
    }
  return (1);
}

void    end_game(char **_tab, t_cursor *cursor, char *name)
{
  if (player_win(_tab))
    {
      free_tab(_tab);
      free(cursor);
      my_putstr("Game just ended, ");
      my_putstr(name);
      my_putstr(" won this game.\n");
      exit(0);
    }
}

int	ligne(void)
{
  char	buff[2];

  *buff = '0';
  while (my_getnbr(buff) < 1 || my_getnbr(buff) > 4)
    {
      my_putstr("Entrez un numero de ligne [1, 4]: ");
      read(0, buff, 8);
    }
  return (my_getnbr(buff) - 1);
}

void	suppr_all(char **_tab, t_cursor *cursor)
{
  char	buff[2];
  int	x;

  *buff = '0';
  x = 0;
  while (_tab[cursor->y][x] != '|')
    x++;
  cursor->x = x;
  while (my_getnbr(buff) < 1 || my_getnbr(buff) > 7)
    {
      my_putstr("Entrez un nombre d'allumette a supprimer: ");
      read(0, buff, 8);
    }
  cursor->select = 1;
  cursor->l = my_getnbr(buff) - 1;
}

int			launch_game(char **_tab, t_cursor *cursor)
{
  int	played;

  my_clear();
  aff_tab(_tab);
  while (42)
    {
      played = 0;
      end_game(_tab, cursor, "Player");
      while (played == 0)
	{
	  cursor->y = ligne();
	  suppr_all(_tab, cursor);
	  played = suppr(cursor, _tab);
	}
      aff_tab(_tab);
      end_game(_tab, cursor, "IA");
      ia_turn(_tab);
      aff_tab(_tab);
    }
  return (0);
}
