/*
** args.c for args in /home/guerga_a/Piscine/projTester
**
** Made by francois guergadic
** Login   <guerga_a@epitech.net>
**
** Started on  Thu Jun 18 10:04:59 2015 francois guergadic
** Last update Sat Jun 20 11:23:15 2015 francois guergadic
*/

#include "projTester.h"

char	*my_dotslash(char *bin)
{
  char	*tmp;

  if ((tmp = malloc(sizeof(char) * (strlen(bin) + 3))) == NULL)
    return (NULL);
  tmp[0] = '\0';
  tmp = strcat(tmp, "./");
  tmp = strcat(tmp, bin);
  return (tmp);
}

int	my_exec(char *binaire, char **args, char *str, t_test *test)
{
  pid_t	pid;
  char	*tmp;
  int	error;
  int	fd;

  error = 0;
  tmp = my_dotslash(binaire);
  if ((pid = fork()) == 0)
    {
      if (str != NULL)
	{
	  if ((fd = open("temp", O_RDWR | O_APPEND | O_CREAT, S_IRWXU)) < 0)
	    exit (1);
	  dup2(fd, 1);
	}
      if ((execvp(tmp, args)) == -1 && (execvp(binaire, args)) == -1)
	error++;
    }
  else
    waitpid(pid, NULL, 0);
  my_compare("temp", str, test);
  free(tmp);
  return (error);
}
