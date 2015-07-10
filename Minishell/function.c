/*
** function.c for function in /home/guerga_a/B1/Sys_Unix/PSU_2014_minishell1
** 
** Made by francois guergadic
** Login   <guerga_a@epitech.net>
** 
** Started on  Wed Jan 21 15:31:55 2015 francois guergadic
** Last update Thu Jan 29 14:22:20 2015 francois guergadic
*/

#include "./include/mysh.h"

int     tab_len(char **tab)
{
  int   i;

  i = 0;
  if (tab != NULL)
    {
      while (tab[i])
	i++;
      return (i);
    }
  return (0);
}

int     cd_cmd(char *str, char *home)
{
  if (*str == '\0')
    {
      if ((chdir(home)) == -1)
        return (2);
      return (1);
    }
  if ((chdir(str)) == -1)
    {
      my_puterr("mysh: cd: ");
      my_puterr(str);
      my_puterr(": Aucun dossier de ce type\n");
      return (2);
    }
  return (1);
}

char    *get_arg(char *path, char *cmd)
{
  char  *arg;

  if ((arg = malloc(sizeof(char) *
                    (my_strlen(path) + my_strlen(cmd) + 2))) == NULL)
    return (NULL);
  *arg = '\0';
  my_strcpy(arg, path);
  my_strcat(arg, "/\0");
  my_strcat(arg, cmd);
  return (arg);
}

int	can_access(char **path, char **cmd)
{
  int	i;
  char	*arg;

  i = 0;
  while (i < tab_len(path))
    {
      arg = get_arg(path[i], cmd[0]);
      if ((access(arg, X_OK)) == 0)
	{
	  free(arg);
	  return (i);
	}
      free(arg);
      i++;
    }
  return (-1);
}

int     my_exe(char *str, char **path, char **env)
{
  char  **cmd;
  pid_t pid;
  int   i;

  cmd = my_str_to_wordtab(str);
  i = can_access(path, cmd);
  if (i != -1 && (pid = fork()) == 0)
    if ((execve(get_arg(path[i], cmd[0]), cmd, env)) == -1)
      {
	exit(pid);
	free_tab(cmd);
	return (-1);
      }
  if (i == -1)
    {
      my_puterr(cmd[0]);
      my_puterr(": Command not found.\n");
      free_tab(cmd);
      return (-1);
    }
  free_tab(cmd);
  if ((waitpid(pid, NULL, 0)) == -1)
    return (-1);
  return (0);
}
