/*
** aff_erroc.c for error output in /home/guerga_a/B1/Sys_Unix/PSU_2014_my_ls
** 
** Made by francois guergadic
** Login   <guerga_a@epitech.net>
** 
** Started on  Sat Nov 29 14:06:26 2014 francois guergadic
** Last update Sun Nov 30 17:38:03 2014 francois guergadic
*/

#include <unistd.h>

void	my_putchar_err(char c)
{
  write(2, &c, 1);
}

void	my_puterr(char *s)
{
  int	i;

  i = 0;
  while (s[i])
    {
      my_putchar_err(s[i]);
      i = i + 1;
    }
}

void	error_access(char *path)
{
  my_puterr("./my_ls: cannot access ");
  my_puterr(path);
  my_puterr(": Aucun fichier ou dossier de ce type\n");
}

void	error_invarg(char *arg)
{
  my_puterr("./my_ls : option invalide -- '");
  my_puterr(arg);
  my_puterr("'\n");
  my_puterr("Usage: ./my_ls path [-a]\n");
}
