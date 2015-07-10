/*
** env_function.c for mysh in /home/guerga_a/B1/Sys_Unix/PSU_2014_minishell1
** 
** Made by francois guergadic
** Login   <guerga_a@epitech.net>
** 
** Started on  Wed Jan 21 13:05:54 2015 francois guergadic
** Last update Mon Jan 26 13:20:01 2015 francois guergadic
*/

#include <stdlib.h>

char    **my_path_to_wordtab(char *str);

int     path_len(char *str)
{
  int   n;

  n = 0;
  while (str[n] != '\0' && str[n] != ':' && str[n] != '\n')
    n++;
  return (n);
}

int     path_count(char *str)
{
  int   cmp;
  int   nb;

  cmp = 0;
  nb = 0;
  while (str[nb] != '\0' && str[nb] != '\n')
    {
      if (str[nb] == ':' && str[nb + 1] != '\0')
        cmp++;
      nb++;
    }
  return (cmp);
}

char    **my_path_to_wordtab(char *str)
{
  char  **tab;
  int   i;
  int   j;
  int   k;

  i = 0;
  j = 0;
  k = 0;
  if ((tab = malloc(((path_count(str) + 2)) * sizeof(*tab))) == NULL)
    return (NULL);
  while (str[i] != '\0')
    {
      if (str[i] == ':')
        {
          i++;
          j++;
          k = 0;
        }
      if ((tab[j] = malloc(((path_len(str + i) + 1)) * sizeof(**tab))) == NULL)
        return (NULL);
      while (str[i] != ':' && str[i])
        tab[j][k++] = str[i++];
      tab[j][k] = '\0';
    }
  tab[j + 1] = NULL;
  return (tab);
}

char    **get_path(char **env)
{
  int   i;

  i = 0;
  while (env[i])
    {
      if (env[i][0] == 'P' && env[i][1] == 'A' &&
          env[i][2] == 'T' && env[i][3] == 'H')
        return (my_path_to_wordtab(&env[i][5]));
      i++;
    }
  return (NULL);
}

char	*get_home(char **env)
{
  int   i;

  i = 0;
  while (env[i])
    {
      if (env[i][0] == 'H' && env[i][1] == 'O' &&
          env[i][2] == 'M' && env[i][3] == 'E')
        return (&env[i][5]);
      i++;
    }
  return (NULL);
}
