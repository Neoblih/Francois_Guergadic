/*
** mysh.h for mysh in /home/guerga_a/B1/Sys_Unix/PSU_2014_minishell1/include
** 
** Made by francois guergadic
** Login   <guerga_a@epitech.net>
** 
** Started on  Wed Jan 21 15:34:19 2015 francois guergadic
** Last update Fri Jan 30 12:26:14 2015 francois guergadic
*/

#ifndef MYSH_H_
# define MYSH_H_

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <sys/types.h>
# include <sys/wait.h>
# include "my.h"

int	my_tablen(char **tab);
char	**my_env_realloc(char **env, int len);
char	**my_env_dump(char **env);
void	aff_prompt(void);
void	my_puterr(char *s);
void	free_tab(char **tab);
char	**my_setenv(char **env, char *name, char *value, int overwrite);
char	**my_init_setenv(char **env, char *str);
int	my_unsetenv(char **env, char *name);
int	aff_env(char **env);
int	my_exe(char *str, char **path, char **env);
char    *get_arg(char *path, char *cmd);
int	cd_cmd(char *str, char *home);
int     tab_len(char **tab);
char    **my_str_to_wordtab(char *str);
char    **get_path(char **env);
char    *get_home(char **env);
void    free_str(char *str);
char    *epur_str(char *str);

#endif /* !MYSH_H_ */
