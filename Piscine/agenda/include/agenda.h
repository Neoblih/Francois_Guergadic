/*
** agenda.h for header in /home/guerga_a/Piscine/agenda/include
**
** Made by francois guergadic
** Login   <guerga_a@epitech.net>
**
** Started on  Mon Jun 29 09:46:34 2015 francois guergadic
** Last update Tue Jun 30 13:33:11 2015 francois guergadic
*/

#ifndef AGENDA_H_
# define AGENDA_H_

# define BUFF_SIZE 4096
# define ERR_COM "commande incorrecte"

# include <unistd.h>
# include <string.h>
# include <stdio.h>
# include <stdlib.h>

typedef struct		s_list
{
	void		*data;
	struct s_list	*next;
}			t_list;

typedef struct	s_employee
{
	int	id;
	char	*first_name;
	char	*last_name;
	char	*poste;
	int	zip;
	t_list	*meetings;
  struct	s_employee *next;
}		t_employee;

typedef struct	s_meeting
{
	int	id;
	char	*day;
	char	*hour;
	int	zip;
	t_list	*employee;
  struct	s_meeting *next;
}		t_meeting;

int		check_new_employee(char *str, t_employee **emp_list);
int		check_info_employee(char *str, t_employee **emp_list);
int		check_fire(char *str, t_employee **emp_list);
int		check_employee(char *str, t_employee **emp_list);
int		check_meeting(char *str, t_meeting **meet_list);
int		count_word(char *str);
char		*get_word(char *str, int n);
int		is_number(char *str);
char		*remove_newline(char *str);
void		print_error(char *str);
int		my_put_in_list(t_list **list, void *data);
int		create_employee(char *str, t_employee **list);
int		create_meeting(char *str, t_meeting **list);
char		**my_str_to_wordtab(char *str, char sep);
int		fire(char *str, t_employee **list);
void		aff_list(char *str, t_employee **list);
void		aff_meeting(char *str, t_meeting **list);

#endif /* !AGENDA_H_ */
