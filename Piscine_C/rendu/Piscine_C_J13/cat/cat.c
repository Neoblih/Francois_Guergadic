/*
** cat.c for cat in /home/guerga_a/rendu/Piscine_C_J13/cat
** 
** Made by francois guergadic
** Login   <guerga_a@epitech.net>
** 
** Started on  Thu Oct 23 10:19:32 2014 francois guergadic
** Last update Thu Oct 23 10:27:25 2014 francois guergadic
*/

#include <sys/stat.h>
#include <fcntl.h>
#include "../include/my.h"

int	no_arg()
{
  int	n;
  char	buffer[10];

  while (1)
    {
      n = read(0, buffer, sizeof(buffer));
      write(1, buffer, n);
    }
}

int	cat(int fd)
{
  int	ret;
  char	buffer[20];

  ret = 1;
  while (ret >= 1)
    {
      ret = read(fd, buffer, 10);
      buffer[ret] = '\0';
      my_putstr(buffer);
    }
}

int	main(int argc, char **argv)
{
  int	i;
  int	fd;

  i = 1;
  if (argc == 1)
    no_arg();
  while (argv[i] != '\0')
    {
      fd = open (argv[i], O_RDONLY);
      if (fd == -1)
	{
	  my_putstr("cat: ");
	  my_putstr(argv[i]);
	  my_putstr(": Aucun fichier ou dossier de ce type\n");
	}
      else
	{
	  cat(fd);
	}
      close(fd);
      i = i + 1;
    }
}
