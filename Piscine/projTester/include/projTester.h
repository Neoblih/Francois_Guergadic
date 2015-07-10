/*
** projTester.h for header in /home/guerga_a/Piscine/projTester/include
** 
** Made by francois guergadic
** Login   <guerga_a@epitech.net>
** 
** Started on  Thu Jun 18 09:08:06 2015 francois guergadic
** Last update Fri Jun 19 19:23:45 2015 francois guergadic
*/

#ifndef PROJTESTER_H_
# define PROJTESTER_H_
# define BUFF_SIZE 1024

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <sys/stat.h>
# include <fcntl.h>

typedef	struct	s_test
{
  int	OK;
  int	KO;
}		t_test;

int	get_stats(char **av);
char	*get_entree(char *str);
char	**get_args(char *binaire, char *str);
char	*get_sortie(char **av);
char	*get_result(char **tab);
char	*remove_double(char *str);
int	my_compare(char *path, char *str1, t_test *test);
void	check_file(char **tab);
char	*my_read(char *path);
int	my_exec(char *binaire, char **args, char *str1, t_test *test);
char	**my_str_to_wordtab(char *str, char c);
char	**get_all_test(char *str);
t_test	*init_struct(void);
void	aff_stats(t_test *test);

#endif /* !PROJTESTER_H_ */
