/*
** genealogie.h for header in /home/guerga_a/Piscine/genealogie/include
**
** Made by francois guergadic
** Login   <guerga_a@epitech.net>
**
** Started on  Thu Jul  2 10:43:11 2015 francois guergadic
** Last update Thu Jul  2 17:52:46 2015 francois guergadic
*/

#ifndef GENEALOGIE_H_
# define GENEALOGIE_H_

# include <sys/stat.h>
# include <sys/types.h>
# include <fcntl.h>
# include <dirent.h>
# include <stdlib.h>
# include <string.h>
# include <stdio.h>
# include <time.h>
# include <unistd.h>

# define BUFF_SIZE 4096

typedef struct			s_individu
{
		char		*prenom;
		char		*date;
		int		cp;
		char		*cv;
		int		sexe;
		int		secu;
  struct	s_individu	*next;
}				t_individu;

void	remove_point(char **file_tab);
int	file_nb(char *dir_path);
char	**init_tab(char *dir_path);
void	part1(t_individu **individu);
int	part2(char *dir_path, char *prenom, t_individu **individu);
int	part3(char *prenom, t_individu **individu);
void	sort_individu(t_individu **individu);
char	*my_read(char *path);

#endif /* !GENEALOGIE_H_ */
