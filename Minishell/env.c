/*
** env.c for env in /home/guerga_a/B1/Sys_Unix/PSU_2014_minishell1
** 
** Made by francois guergadic
** Login   <guerga_a@epitech.net>
** 
** Started on  Thu Jan 22 12:14:59 2015 francois guergadic
** Last update Thu Jan 22 16:15:07 2015 francois guergadic
*/

#include "./include/mysh.h"

int	aff_env(char **env)
{
  int	i;

  i = 0;
  while (env[i])
    {
      my_putstr(env[i]);
      my_putchar('\n');
      i++;
    }
  return (1);
}

int	my_unsetenv(char **env, char *name)
{
  int	i;
  int	change;

  i = 0;
  change = 0;
  while (env[i])
    {
      if (my_strncmp(env[i], name, my_strlen(name) - 1) == 0)
	{
	  change = 1;
	}
      if (change == 1)
	env[i] = env[i + 1];
      i++;
    }
  return (1);
}
