/*
** fdf.h for fdf header in /home/guerga_a/Igraph
** 
** Made by francois guergadic
** Login   <guerga_a@epitech.net>
** 
** Started on  Mon Oct 27 15:36:52 2014 francois guergadic
** Last update Sun Dec  7 10:57:32 2014 francois guergadic
*/

#ifndef FDF_H_
# define FDF_H_
# include "point.h"
# define BUFF_SIZE (4096)
int		aff_ligne(void *mlx_ptr, void *win_ptr, t_point a, t_point b);
void		aff_result(t_point **tab, void *mlx, void *win, int len);
int		get_word_number(char *str);
int		get_next_word_len(char *str);
char		**my_str_to_tab(char *str);
int		tab_length(char *tab);
int		tab_height(char *tab);
char		**buff_to_tab(char *str, int height, int length);
char		**my_buff_to_tab(char *str);
int		my_show_wordtab(char **tab);
int		recup_buff(void *mlx, void *win);
struct s_point	**fdf(char **tab, void *mlx, void *win);
struct s_point	*put_coord(char **str, void *mlx, void *win, int xr, int yr, int len);
char		*epur_str(char *str);
void		free_tab(char **tab);
void		free_point(t_point **tab);
#endif /* !FDF_H_ */
