/*
** part1.c for part1 in /home/guerga_a/Piscine/genealogie
**
** Made by francois guergadic
** Login   <guerga_a@epitech.net>
**
** Started on  Thu Jul  2 12:52:35 2015 francois guergadic
** Last update Thu Jul  2 15:12:27 2015 francois guergadic
*/

#include "genealogie.h"

t_individu	*get_prevnd(t_individu *head, t_individu *a)
{
  t_individu	*temp;
  t_individu	*pre_a;

  temp = head;
  if (temp == a)
    return (NULL);
  while (temp && temp != a)
    {
      pre_a = temp;
      temp = temp->next;
    }
  return (pre_a);
}

void		swap(t_individu **tete, t_individu **a, t_individu **b)
{
  t_individu*	pre_a;
  t_individu*	pre_b;
  t_individu*	tmp;

  tmp = NULL;
  pre_a = get_prevnd(*tete, *a);
  pre_b = get_prevnd(*tete, *b);
  if (pre_a)
    pre_a->next = *b;
  if (pre_b)
    pre_b->next = *a;
  tmp = (*a)->next;
  (*a)->next = (*b)->next;
  (*b)->next = tmp;
  if (*tete == *a)
    *tete = *b;
  else if (*tete == *b)
    *tete = *a;
}

int	date_cmp(char *date1, char *date2)
{
  char	temp1[10];
  char	temp2[10];

  if (strlen(date1) < 10 || strlen(date2) < 10)
    return (0);
  temp1[0] = '\0';
  strcpy(temp1, &date1[6]);
  strncat(temp1, &date1[3], 2);
  strncat(temp1, date1, 2);
  temp2[0] = '\0';
  strcpy(temp2, &date2[6]);
  strncat(temp2, &date2[3], 2);
  strncat(temp2, date2, 2);
  if (atoi(temp1) > atoi(temp2))
    return (1);
  return (0);
}

void	sort_individu(t_individu **individu)
{
  t_individu *current;
  t_individu *next;

  current = *individu;
  while (current != NULL && current->next != NULL)
    {
      next = current->next;
      if (date_cmp(current->date, next->date) == 1)
	{
	  swap(individu, &current, &next);
	  current = *individu;
	}
      else
	current = current->next;
    }
}

void	part1(t_individu **individu)
{
  t_individu *tmp;

  sort_individu(individu);
  tmp = *individu;
  if (tmp)
    {
      printf("%s", tmp->prenom);
      tmp = tmp->next;
    }
  while (tmp)
    {
      printf(" / %s", tmp->prenom);
      tmp = tmp->next;
    }
  printf("\n");
}
