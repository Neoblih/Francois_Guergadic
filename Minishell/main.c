/*
** main.c for minishell1 in /home/guerga_a/B1/Sys_Unix/PSU_2014_minishell1
** 
** Made by francois guergadic
** Login   <guerga_a@epitech.net>
** 
** Started on  Mon Jan 19 14:13:14 2015 francois guergadic
** Last update Fri Jan 30 12:36:02 2015 francois guergadic
*/

#include "./include/mysh.h"

void	free_tab(char **tab)
{
  int	i;

  i = 0;
  if (tab != NULL)
    {
      while (tab[i])
	{
	  free(tab[i]);
	  i++;
	}
      free(tab[i]);
      free(tab);
    }
}

void	free_str(char *str)
{
  int	i;

  i = 0;
  while (str[i])
    {
      str[i] = '\0';
      i++;
    }
}

char	*epur_str(char *str)
{
  int	i;

  i = 0;
  while (str[i])
    {
      if (str[i] == '\n')
	{
	  str[i] = '\0';
	  return (str);
	}
      i++;
    }
  return (str);
}

char	**do_cmd(char *str, char **env)
{
  char	**path;

  if (str[0])
    {
      if (my_strcmp(str, "exit") == 0)
	{
	  free(str);
	  free_tab(env);
	  exit(0);
	}
      else if (my_strncmp(str, "cd", 1) == 0)
	cd_cmd(&str[3], get_home(env));
      else if (my_strncmp(str, "env", 2) == 0)
	aff_env(env);
      else if (my_strncmp(str, "unsetenv ", 8) == 0)
	my_unsetenv(env, &str[9]);
      else if (my_strncmp(str, "setenv ", 6) == 0)
	return (my_init_setenv(env, &str[7]));
      else
	{
	  path = get_path(env);
	  my_exe(str, path, env);
	  free_tab(path);
	}
    }
  return (env);
}

int	main(int argc, char **argv, char **env)
{
  char	*str;
  char	**new_env;

  if (argc == 1)
    {
      new_env = my_env_dump(env);
       if ((str = malloc(sizeof(char) * 4096)) == NULL)
       	return (1);
      while (42)
	{
	  aff_prompt();
	  if ((read(0, str, 4096)) > 0)
	    new_env = do_cmd(epur_str(str), new_env);
	  else
	    {
	      my_putchar('\n');
	      free_tab(new_env);
	      free_str(str);
	      break;
	    }
	  free_str(str);
	}
    }
  else
    {
      my_puterr(argv[0]);
      my_puterr(" does not need any argument\n");
    }
  return (0);
}
