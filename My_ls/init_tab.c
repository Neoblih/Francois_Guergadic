/*
** init_tab.c for init tab in /home/guerga_a/B1/Sys_Unix/PSU_2014_my_ls
** 
** Made by francois guergadic
** Login   <guerga_a@epitech.net>
** 
** Started on  Sat Nov 29 13:00:00 2014 francois guergadic
** Last update Sat Nov 29 14:59:03 2014 francois guergadic
*/

#include <sys/types.h>
#include <dirent.h>
#include <stdlib.h>
#include "./include/my.h"
#include "./include/my_ls.h"

struct dirent   *readdir(DIR *dirp);

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
      if ((tab[i] = malloc(sizeof(char) * (my_strlen(dp->d_name) + 1))) == NULL)
        return (NULL);
      my_strcpy(tab[i], dp->d_name);
      i++;
    }
  tab[i] = NULL;
  closedir(dirp);
  return (tab);
}
