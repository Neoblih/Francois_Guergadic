/*
** game.c for game in /home/guerga_a/B1/Prog_Elem/Allum1/core_function
** 
** Made by francois guergadic
** Login   <guerga_a@epitech.net>
** 
** Started on  Fri Feb 13 21:24:58 2015 francois guergadic
** Last update Fri Feb 13 21:47:45 2015 francois guergadic
*/

#include "./allum1.h"

void    select(t_cursor *cursor)
{
  if (cursor->select == 1)
    {
      cursor->select = 0;
      cursor->l = 0;
    }
  else
    cursor->select = 1;
}

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
      my_clear();
      free_tab(_tab);
      free(cursor);
      my_putstr("Game just ended, ");
      my_putstr(name);
      my_putstr(" won this game.\n");
      exit(0);
    }
}

void	aff_rules(int r)
{
  my_clear();
  my_putstr_blue("         Welcome in Allum1 game!\n\n");
  my_putstr_blue("You are playing with ");
  my_put_nbr_blue(r);
  my_putstr_blue(" raws of allums\n\n");
  my_putstr_blue("To win, you have to NOT pick the last allum\n");
  my_putstr_blue("You can pick between one allum and an entire raw\n\n");
  my_putstr_blue("\rGame launching in 5..");
  usleep(1000000);
  my_putstr_blue("\rGame launching in 4..");
  usleep(1000000);
  my_putstr_blue("\rGame launching in 3..");
  usleep(1000000);
  my_putstr_blue("\rGame launching in 2..");
  usleep(1000000);
  my_putstr_blue("\rGame launching in 1..");
  usleep(1000000);
}

int			launch_game(char **_tab, int r, t_cursor *cursor)
{
  struct termios	t;
  char			buff[1024];
  int			played;

  played = 0;
  cursor_init(cursor);
  aff_tab(_tab, cursor);
  while (42)
    {
      if (played == 1)
        {
          end_game(_tab, cursor, "IA");
          ia_turn(_tab, r);
          aff_tab(_tab, cursor);
          end_game(_tab, cursor, "Player");
        }
      init_read(&t);
      read(0, buff, 1024);
      played = move_cursor(cursor, r, buff, _tab);
      aff_tab(_tab, cursor);
    }
  return (0);
}
