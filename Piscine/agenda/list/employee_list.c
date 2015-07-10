/*
** employee_list.c for employee list in /home/guerga_a/Piscine/agenda/list
**
** Made by francois guergadic
** Login   <guerga_a@epitech.net>
**
** Started on  Mon Jun 29 12:41:05 2015 francois guergadic
** Last update Tue Jun 30 10:52:11 2015 francois guergadic
*/

#include "agenda.h"

t_employee	*remove_in_list(t_employee *prev, t_employee *current)
{
  t_employee	*tmp;

  tmp = current;
  prev->next = tmp->next;
  return (prev);
}

int		fire(char *str, t_employee **emp_list)
{
  char		**tab;
  int		i;
  t_employee	*temp;
  t_employee	*prev;

  tab = my_str_to_wordtab(str, ' ');
  i = 1;
  while (tab[i])
    {
      temp = *emp_list;
      while (temp != NULL)
	{
	  if (temp->id == atoi(tab[i]))
	    {
	      if (temp == *emp_list)
		*emp_list = temp->next;
	      else
		remove_in_list(prev, temp);
	    }
	  prev = temp;
	  temp = temp->next;
	}
      i++;
    }
  return (0);
}

int		create_employee(char *str, t_employee **emp_list)
{
  t_employee	*employee;
  char		**tab;

  tab = my_str_to_wordtab(str, ' ');
  if ((employee = malloc(sizeof(t_employee))) == NULL)
    return (1);
  employee->id = atoi(tab[5]);
  employee->first_name = tab[2];
  employee->last_name = tab[1];
  employee->poste = tab[3];
  employee->zip = atoi(tab[4]);
  employee->meetings = NULL;
  employee->next = *emp_list;
  *emp_list = employee;
  return (0);
}
