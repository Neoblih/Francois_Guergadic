/*
** main.c for main in /home/guerga_a/Piscine/agenda
**
** Made by francois guergadic
** Login   <guerga_a@epitech.net>
**
** Started on  Mon Jun 29 10:04:33 2015 francois guergadic
** Last update Tue Jun 30 13:32:58 2015 francois guergadic
*/

#include "agenda.h"

int	my_tabcontain(char **tab, int n)
{
  int	i;

  i = 0;
  while (tab[i])
    {
      if (atoi(tab[i]) == n)
	return (1);
      i++;
    }
  return (0);
}

void		aff_list(char *str, t_employee **list)
{
  t_employee	*temp;
  char		**tab;

  tab = my_str_to_wordtab(str, ' ');
  temp = *list;
  while (temp != NULL)
    {
      if (my_tabcontain(&tab[2], temp->id) == 1)
	{
	  printf("*****************************\n");
	  printf("%s %s\nposte: %s\nville: %i\n", temp->first_name,
		 temp->last_name, temp->poste, temp->zip);
	}
      temp = temp->next;
    }
}

void	aff_meeting(char *str, t_meeting **list)
{
  t_meeting	*temp;
  char		**tab;

  tab = my_str_to_wordtab(str, ' ');
  temp = *list;
  while (temp != NULL)
    {
      if (my_tabcontain(&tab[2], temp->id) == 1)
	{
	  printf("*****************************\n");
	  printf("REUNION\n");
	  printf("date: %s\n", temp->day);
	  printf("lieu: %i\n", temp->zip);
	}
      temp = temp->next;
    }
}

int	check_str(char	*str, t_employee **emp_list, t_meeting **meet_list)
{
  if (check_employee(str, emp_list) + check_meeting(str, meet_list) == 0)
    {
      print_error(ERR_COM);
      return (1);
    }
  return (0);
}

void	clear_str(char	*str)
{
  int	i;

  i = 0;
  while (str[i])
    str[i++] = '\0';
}

int		main(void)
{
  char		*yolo;
  t_employee	*emp_list;
  t_meeting	*meet_list;
  size_t	s_buff;

  emp_list = NULL;
  meet_list = NULL;
  while ((getline(&yolo, &s_buff, stdin)) != -1 && strcmp(remove_newline(yolo), "END") != 0)
    {
      check_str(yolo, &emp_list, &meet_list);
      clear_str(yolo);
    }
  return (0);
}
