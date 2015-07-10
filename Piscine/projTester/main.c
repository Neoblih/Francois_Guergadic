/*
** main.c for main in /home/guerga_a/Piscine/projTester
**
** Made by francois guergadic
** Login   <guerga_a@epitech.net>
**
** Started on  Thu Jun 18 09:07:20 2015 francois guergadic
** Last update Sat Jun 20 11:39:14 2015 francois guergadic
*/

#include "projTester.h"

t_test	*exec_fun(char *binaire, char **tab, t_test *test, char *sortie, int stats)
{
  char	**args;
  int	fd;

  args = get_args(binaire, tab[0]);
  if (args != NULL)
    {
      if (get_entree(tab[1]) != NULL)
	{
	  if ((fd = open(get_entree(tab[1]), O_RDONLY)) < 0)
	    exit(1);
	  dup2(fd, 0);
	}
      if ((my_exec(binaire, args, get_result(tab), test)) != 0)
	{
	  fprintf(stdout, "Error with binary: %s\n", binaire);
	  free(args);
	  return (NULL);
	}
      free(args);
    }
  if (sortie == NULL && stats == 1 && tab[1] == NULL)
    aff_stats(test);
  return (test);
}

void	my_sortie(char *sortie)
{
  int	fd;

  if (sortie != NULL)
    {
      if ((fd = open(sortie, O_RDWR | O_APPEND | O_CREAT, S_IRWXU)) < 0)
	exit(1);
      dup2(fd, 1);
    }
}

void	update_stats(char *sortie, t_test *test)
{
  char	*str;
  int	i;

  i = 0;
  str = my_read(sortie);
  while (str[i])
    {
      if (strncmp(&str[i], "OK", 2) == 0)
	test->OK++;
      if (strncmp(&str[i], "KO", 2) == 0)
	test->KO++;
      i++;
    }
}

void		do_work(char *binaire, char **tab, char *sortie, int stats)
{
  int		i;
  t_test	*test;
  pid_t		pid;

  i = 0;
  test = init_struct();
  if ((pid = fork()) == 0)
    {
      my_sortie(sortie);
      while (tab[i])
	{
	  if ((exec_fun(binaire, &tab[i], test, sortie, stats)) == NULL)
	    break;
	  i++;
	}
    }
  else
    {
      waitpid(pid, NULL, 0);
      if (stats == 1 && sortie != NULL)
	{
	  update_stats(sortie, test);
	  aff_stats(test);
	}
    }
}

int	main(int ac, char **av)
{
  char	**tab;

  if (ac > 2)
    {
      tab = get_all_test(remove_double(my_read(av[2])));
      if (tab != NULL)
	{
	  check_file(tab);
	  do_work(av[1], tab, get_sortie(&av[2]), get_stats(&av[2]));
    	}
    }
  else
    fprintf(stdout, "Missing arguments\n");
  return (0);
}
