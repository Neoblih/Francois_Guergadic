/*
** main.c for main in /home/guerga_a/Piscine/palindrome
**
** Made by francois guergadic
** Login   <guerga_a@epitech.net>
**
** Started on  Fri Jun 26 10:36:41 2015 francois guergadic
** Last update Sat Jun 27 17:26:48 2015 francois guergadic
*/

#include "palindrome.h"

t_flag		*feed_struct(t_flag *flag, char **av)
{
  int	i;

  i = 0;
  while (av[i])
    {
      if (strncmp(av[i], "<=", 2) == 0)
	flag->i_max_e = atoi(&av[i][2]);
      else if (av[i][0] == '<')
	flag->i_max = atoi(&av[i][1]);
      else if (strncmp(av[i], ">=", 2) == 0)
	flag->i_min_e = atoi(&av[i][2]);
      else if (av[i][0] == '>')
	flag->i_min = atoi(&av[i][1]);
      i++;
    }
  return (flag);
}

t_flag		*init_flag()
{
  t_flag	*flag;

  if ((flag = malloc(sizeof(flag) * 4)) == NULL)
    return (NULL);
  flag->i_min = -1;
  flag->i_max = -1;
  flag->i_max_e = -1;
  flag->i_min_e = -1;
  return (flag);
}

int	get_it(int n, int base, t_flag *flag)
{
  int	i;

  n = convert_base(n, 10, base);
  i = 0;
  while (is_pal(n, base) == 0 && i >= 0)
    {
      n = do_return(n, base);
      i++;
    }
  if (i < 0)
    aff_error(ERR_OVERFLOW, 'e');
  if (flag->i_min_e != -1 && i < flag->i_min_e)
      aff_error(ERR_NOSOL, 'e');
  else if (flag->i_min != -1 && i <= flag->i_min)
      aff_error(ERR_NOSOL, 'e');
  if (flag->i_max_e != -1 && i > flag->i_max_e)
      aff_error(ERR_NOSOL, 'e');
  else if (flag->i_max != -1 && i >= flag->i_max)
      aff_error(ERR_NOSOL, 'e');
  return (i);
}

int	get_pal(int n, int base)
{
  int	i;

  i = 0;
  n = convert_base(n, 10, base);
  while (is_pal(n, base) == 0)
    {
      n = do_return(n, base);
      i++;
    }
  if (i < 0)
    return (0);
  return (convert_base(n, base, 10));
}

int		main(int ac, char **av)
{
  int		nb;
  int		base;
  t_flag	*flag;

  if (ac > 2)
    {
      if (error(&av[3]) == 1)
	return (aff_error(ERR_ARG, 'r'));
      flag = init_flag();
      flag = feed_struct(flag, &av[3]);
      nb = atoi(av[1]);
      base = atoi(av[2]);
      if (base < 2 || base > 10)
	return (aff_error(ERR_ARG, 'r'));
      if (nb == -1)
	return (aff_error(ERR_ARG, 'r'));
      if (reverse_flag(&av[3]) == 1)
	aff_it(reverse(nb, base), reverse_it(nb, base, flag), nb, base);
      else
	aff_it(nb, get_it(nb, base, flag), get_pal(nb, base), base);
    }
  else
    return (aff_error(ERR_ARG, 'r'));
  return (0);
}
