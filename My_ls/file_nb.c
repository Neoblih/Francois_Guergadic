/*
** file_nb.c for file nb in /home/guerga_a/B1/Sys_Unix/PSU_2014_my_ls
** 
** Made by francois guergadic
** Login   <guerga_a@epitech.net>
** 
** Started on  Sat Nov 29 12:58:47 2014 francois guergadic
** Last update Sat Nov 29 14:44:12 2014 francois guergadic
*/

#include <sys/types.h>
#include <dirent.h>
#include <stdlib.h>

struct dirent   *readdir(DIR *dirp);

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
