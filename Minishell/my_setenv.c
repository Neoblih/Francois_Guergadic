/*
** my_setenv.c for setenv in /home/guerga_a/B1/Sys_Unix/PSU_2014_minishell1
** 
** Made by francois guergadic
** Login   <guerga_a@epitech.net>
** 
** Started on  Thu Jan 22 16:14:17 2015 francois guergadic
** Last update Fri Jan 30 12:34:30 2015 francois guergadic
*/

#include "./include/mysh.h"

char	**insert_newval(char **env, char *name, char *value)
{
  int	i;

  i = my_tablen(env);
  if ((env = my_env_realloc(env, (my_strlen(name) +
				  my_strlen(value) + 2))) == NULL)
    return (NULL);
  my_strcpy(env[i], name);
  my_strcat(env[i], "=");
  my_strcat(env[i], value);
  return (env);
}

int	smth_to_do(char **env, char *name, int overwrite)
{
  int   i;

  i = 0;
  while (env[i])
    {
      if (my_strncmp(env[i], name, my_strlen(name) - 1) == 0 &&
          overwrite == 0)
        {
          my_putstr("Can't overwrite \"");
          my_putstr(name);
          my_putstr("\" because overwrite value is equal to '0'.");
	  my_putstr(" Please change overwrite value.\n");
          return (0);
        }
      i++;
    }
  return (1);
}

int	name_alrdy_exists(char **env, char *name)
{
  int   i;

  i = 0;
  while (env[i])
    {
      if (my_strncmp(env[i], name, my_strlen(name) - 1) == 0)
        return (i);
      i++;
    }
  return (0);
}

char	**my_setenv(char **env, char *name, char *value, int overwrite)
{
  int   i;

  if (smth_to_do(env, name, overwrite) == 1)
    {
      i = name_alrdy_exists(env, name);
      if (i == 0)
        {
	  return (insert_newval(env, name, value));
        }
      else
        {
          free_str(env[i]);
          my_strcat(env[i], name);
          my_strcat(env[i], "=");
          my_strcat(env[i], value);
        }
    }
  return (env);
}

char	**my_init_setenv(char **env, char *str)
{
  char  **params;
  char	**new_env;

  params = my_str_to_wordtab(str);
  if (params[0] && params[1] && params[2])
    new_env = my_setenv(env, params[0], params[1], my_getnbr(params[2]));
  free_tab(params);
  return (new_env);
}
