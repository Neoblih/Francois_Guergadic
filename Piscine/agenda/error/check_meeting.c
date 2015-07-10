/*
** check_meeting.c for meeting in /home/guerga_a/Piscine/agenda/error
**
** Made by francois guergadic
** Login   <guerga_a@epitech.net>
**
** Started on  Mon Jun 29 11:48:33 2015 francois guergadic
** Last update Tue Jun 30 13:32:19 2015 francois guergadic
*/

#include "agenda.h"

int	check_new_meeting(char *str, t_meeting **meet_list)
{
  int	i;

  i = 5;
  if (count_word(str) < 6)
    return (0);
  if (strncmp(str, "new_meeting", 11) != 0)
    return (0);
  while (i <= count_word(str))
    {
      if (is_number(get_word(str, i)) == 0)
	return (0);
      i++;
    }
  create_meeting(str, meet_list);
  return (1);
}

int	check_invite_exclude(char *str)
{
  int	i;

  i = 2;
  if (count_word(str) < 3)
    return (0);
  if (strncmp(str, "invite", 6) != 0 &&
      strncmp(str, "exclude", 6) != 0)
    return (0);
  while (i <= count_word(str))
    {
      if (is_number(get_word(str, i)) == 0)
	return (0);
      i++;
    }
  return (1);
}

int	check_cancel(char *str)
{
  int	i;

  i = 2;
  if (count_word(str) < 2)
    return (0);
  if (strncmp(str, "cancel", 6) != 0)
    return (0);
  while (i <= count_word(str))
    {
      if (is_number(get_word(str, i)) == 0)
	return (0);
      i++;
    }
  return (1);
}

int	check_info_meeting(char	*str, t_meeting **meet_list)
{
  int	i;

  i = 3;
  if (count_word(str) < 3)
    return (0);
  if (strncmp(str, "info_meetings", 12) != 0)
    return (0);
  if (strncmp(get_word(str, 2), "sortByDate", 10) != 0 &&
      strncmp(get_word(str, 2), "sortByZip", 9) != 0 &&
      strncmp(get_word(str, 2), "sortById", 8) != 0)
    return (0);
  while (i <= count_word(str))
    {
      if (is_number(get_word(str, i)) == 0)
	return (0);
      i++;
    }
  aff_meeting(str, meet_list);
  return (1);
}

int	check_meeting(char *str, t_meeting **meet_list)
{
  return (check_cancel(str) + check_new_meeting(str, meet_list) +
	  check_info_meeting(str, meet_list) + check_invite_exclude(str));
}
