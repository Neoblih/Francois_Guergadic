/*
** file_nb.c for prerequis in /home/guerga_a/Piscine/genealogie
**
** Made by francois guergadic
** Login   <guerga_a@epitech.net>
**
** Started on  Thu Jul  2 09:44:31 2015 francois guergadic
** Last update Fri Jul  3 09:11:58 2015 francois guergadic
*/

#include <sys/types.h>
#include <dirent.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

struct dirent   *readdir(DIR *dirp);

void	remove_point(char **tab)
{
  int	i;

  i = 0;
  while (tab[i])
    {
      if (tab[i][0] == '.')
	{
	  while (tab[i] && tab[i + 1])
	    {
	      tab[i] = tab[i + 1];
	      i++;
	    }
	  tab[i] = NULL;
	  i = -1;
	}
      i++;
    }
}

void	aff_tab(char **tab)
{
  int	i;

  i = 0;
  while (tab[i])
    {
      printf("%s\n", tab[i]);
      i++;
    }
}

int             file_nb(char *name)
{
  DIR           *dirp;
  struct dirent *dp;
  int           file_nb;

  file_nb = 0;
  if ((dirp = opendir(name)) == NULL)
    return (0);
  while ((dp = readdir(dirp)) != NULL)
    file_nb++;
  closedir(dirp);
  return (file_nb);
}

char            **init_tab(char *name)
{
  char          **tab;
  DIR           *dirp;
  struct dirent *dp;
  int           i;
  int		file_num;

  if ((file_num = file_nb(name)) == 0)
    return (NULL);
  i = 0;
  if ((tab = malloc(sizeof(char*) * (file_num + 1))) == NULL)
    return (NULL);
  if ((dirp = opendir(name)) == NULL)
    return (NULL);
  while ((dp = readdir(dirp)) != NULL)
    {
      if ((tab[i] = malloc(sizeof(char) * (strlen(dp->d_name) + 1))) == NULL)
        return (NULL);
      strcpy(tab[i], dp->d_name);
      i++;
    }
  tab[i] = NULL;
  closedir(dirp);
  return (tab);
}

char    *rm_dot(char *str)
{
  if (str[0] == '.')
    return (&str[1]);
  else
    return (str);
}

void    sort_tab(char **tab)
{
  int   i;
  char  *temp;

  i = 0;
  while (tab[i] && tab[i + 1])
    {
      if (strcmp(rm_dot(tab[i]), rm_dot(tab[i + 1])) > 0)
        {
          temp = tab[i];
          tab[i] = tab[i + 1];
          tab[i + 1] = temp;
          i = 0;
        }
      else
        i++;
    }
}

int	my_files_synthese(char *str)
{
  char	**tab;

  if ((tab = init_tab(str)) == NULL)
    return (1);
  sort_tab(tab);
  remove_point(tab);
  aff_tab(tab);
  return (0);
}
