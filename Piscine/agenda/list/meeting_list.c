/*
** meeting_list.c for meeting_list in /home/guerga_a/Piscine/agenda/list
**
** Made by francois guergadic
** Login   <guerga_a@epitech.net>
**
** Started on  Tue Jun 30 12:23:32 2015 francois guergadic
** Last update Tue Jun 30 13:04:56 2015 francois guergadic
*/

#include "agenda.h"

int		create_meeting(char *str, t_meeting **meet_list)
{
  t_meeting	*meeting;
  char		**tab;

  tab = my_str_to_wordtab(str, ' ');
  if ((meeting = malloc(sizeof(t_meeting))) == NULL)
    return (1);
  meeting->id = atoi(tab[3]);
  meeting->day = tab[2];
  meeting->zip = atoi(tab[1]);
  meeting->employee = NULL;
  meeting->next = *meet_list;
  *meet_list = meeting;
  return (1);
}
