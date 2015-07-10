/*
** alloc_env.c for env malloc in /home/guerga_a/B1/Sys_Unix/PSU_2014_minishell1
** 
** Made by francois guergadic
** Login   <guerga_a@epitech.net>
** 
** Started on  Fri Jan 30 12:20:55 2015 francois guergadic
** Last update Fri Jan 30 12:29:56 2015 francois guergadic
*/

#include "./include/mysh.h"

int	my_tablen(char **tab)
{
  int   i;

  i = 0;
  while (tab[i])
    i++;
  return (i);
}

char	**my_env_realloc(char **env, int len)
{
  char  **new_env;
  int   i;

  i = 0;
  if ((new_env = malloc(sizeof(char*) * (my_tablen(env) + 2))) == NULL)
    return (NULL);
  while (env[i])
    {
      if ((new_env[i] = malloc(sizeof(char) * (my_strlen(env[i]) + 1))) == NULL)
        return (NULL);
      my_strcpy(new_env[i], env[i]);
      i++;
    }
  if ((new_env[i] = malloc(sizeof(char) * (len + 1))) == NULL)
    return (NULL);
  new_env[i][0] = '\0';
  new_env[i + 1] = NULL;
  free_tab(env);
  return (new_env);
}

char    **my_env_dump(char **env)
{
  char  **new_env;
  int   i;

  i = 0;
  if ((new_env = malloc(sizeof(char*) * (my_tablen(env) + 1))) == NULL)
    return (NULL);
  while (env[i])
    {
      if ((new_env[i] = malloc(sizeof(char) * (my_strlen(env[i]) + 1))) == NULL)
        return (NULL);
      my_strcpy(new_env[i], env[i]);
      i++;
    }
  new_env[i] = NULL;
  return (new_env);
}
