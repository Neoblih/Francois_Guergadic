/*
** palindrome.h for header in /home/guerga_a/Piscine/palindrome/include
**
** Made by francois guergadic
** Login   <guerga_a@epitech.net>
**
** Started on  Fri Jun 26 11:15:59 2015 francois guergadic
** Last update Sat Jun 27 17:22:51 2015 francois guergadic
*/

#ifndef PALINDROME_H_
# define PALINDROME_H_

# define ERR_ARG "argument invalide"
# define ERR_OVERFLOW "overflow"
# define ERR_NOSOL "pas de solution"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct s_flag
{
  int	i_max;
  int	i_min;
  int	i_max_e;
  int	i_min_e;
}	t_flag;

void	aff_it(int n, int pal, int i, int base);
int	aff_error(char *str, char c);
int	my_power_rec(int nb, int p);
int	do_return(int n, int base);
int	is_pal(int n, int base);
int	get_pal(int n, int base);
int	get_it(int n, int base, t_flag *flag);
int	my_retourn(int n, int base);
int	my_base_add(int n1, int n2, int base);
int	convert_base(int n, int base_from, int base_to);
int	reverse_it(int n, int base, t_flag *flags);
int	reverse(int n, int base);
int	reverse_flag(char **av);
int	error(char **av);

#endif /* !PALINDROME_H_ */
