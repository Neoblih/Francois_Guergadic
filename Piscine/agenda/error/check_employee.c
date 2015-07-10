/*
** check_employee.c for check_employee in /home/guerga_a/Piscine/agenda/error
**
** Made by francois guergadic
** Login   <guerga_a@epitech.net>
**
** Started on  Mon Jun 29 10:25:19 2015 francois guergadic
** Last update Tue Jun 30 13:19:36 2015 francois guergadic
*/

#include "agenda.h"

int	check_employee(char *str, t_employee **emp_list)
{
  return (check_new_employee(str, emp_list) + check_info_employee(str, emp_list) +
	  check_fire(str, emp_list));
}

int	check_new_employee(char *str, t_employee **emp_list)
{
  if (count_word(str) != 6)
    return (0);
  if (strncmp(str, "new_employee", 12) != 0)
    return (0);
  if (is_number(get_word(str, 5)) == 0)
    return (0);
  if (is_number(get_word(str, 6)) == 0)
    return (0);
  create_employee(str, emp_list);
  return (1);
}

int	check_info_employee(char *str, t_employee **emp_list)
{
  int	i;

  i = 3;
  if (count_word(str) < 3)
    return (0);
  if (strncmp(str, "info_employees", 14) != 0)
    return (0);
  if (strncmp(get_word(str, 2), "sortByName", 10) != 0 &&
      strncmp(get_word(str, 2), "sortByForeName", 14) != 0 &&
      strncmp(get_word(str, 2), "sortByJob", 9) != 0 &&
      strncmp(get_word(str, 2), "sortByZip", 9) != 0 &&
      strncmp(get_word(str, 2), "sortById", 8) != 0)
    return (0);
  while (i <= count_word(str))
    {
      if (is_number(get_word(str, i)) == 0)
	return (0);
      i++;
    }
  aff_list(str, emp_list);
  return (1);
}

int	check_fire(char *str, t_employee **emp_list)
{
  int	i;

  i = 2;
  if (count_word(str) < 2)
    return (0);
  if (strncmp(str, "fire", 4) != 0)
    return (0);
  while (i <= count_word(str))
    {
      if (is_number(get_word(str, i)) == 0)
	return (0);
      i++;
    }
  fire(str, emp_list);
  return (1);
}
