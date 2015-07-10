/*
** allum1.h for header in /home/guerga_a/B1/Prog_Elem/Allum1/include
** 
** Made by francois guergadic
** Login   <guerga_a@epitech.net>
** 
** Started on  Mon Feb  2 13:39:14 2015 francois guergadic
** Last update Sat Feb 21 11:16:40 2015 francois guergadic
*/

#ifndef ALLUM1_H_
# define ALLUM1_H_

# include <stdlib.h>
# include <unistd.h>
# include <termios.h>
# include <ncurses/curses.h>
# include <term.h>
# include <my.h>
# include <cursor.h>

int	usleep(int usec);
void	my_putstr_blue(char *s);
void	my_pc_b(char c);
int	my_put_nbr_blue(int n);
void	aff_rules(int r);
int	launch_game(char **_tab, t_cursor *cursor);
void	free_tab(char **_tab);
void	init_read(struct termios *t);
int	ia_turn(char **_tab);
void	aff_tab(char **_tab);
void	my_clear(void);
char    **init_tab(int r);
void    my_putstr_pos(char *s, t_cursor *cursor);
void	my_putstr_normal(char *s);
int	move_cursor(t_cursor *cursor, int r, char *buff, char **_tab);
void	cursor_init(t_cursor *cursor);
void	select(t_cursor *cursor);
int	suppr(t_cursor *cursor, char **_tab);

#endif /* !ALLUM1_H_ */
