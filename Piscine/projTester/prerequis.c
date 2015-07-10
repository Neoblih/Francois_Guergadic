/*
** prerequis.c for fork in /home/guerga_a/Piscine/projTester
** 
** Made by francois guergadic
** Login   <guerga_a@epitech.net>
** 
** Started on  Thu Jun 18 09:54:43 2015 francois guergadic
** Last update Fri Jun 19 17:07:30 2015 francois guergadic
*/

#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>

void	my_ps_synthese()
{
  pid_t	pid;

  if ((pid = fork()) == 0)
    {
      if ((execlp("ps", "ps", NULL)) == -1)
	exit(1);
    }
  else
    wait(0);
}
