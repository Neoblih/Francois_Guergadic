/*
** part3.c for part3 in /home/guerga_a/Piscine/genealogie
**
** Made by francois guergadic
** Login   <guerga_a@epitech.net>
**
** Started on  Thu Jul  2 17:17:33 2015 francois guergadic
** Last update Thu Jul  2 17:52:58 2015 francois guergadic
*/

#include "genealogie.h"

int		get_cp(char *prenom, t_individu **individu)
{
  t_individu	*tmp;

  tmp = *individu;
  while (tmp)
    {
      if (strcmp(tmp->prenom, prenom) == 0)
	return (tmp->cp);
      tmp = tmp->next;
    }
  fprintf(stderr, "Error: %s n'existe pas!\n", prenom);
  return (-1);
}

int		part3(char *prenom, t_individu **individu)
{
  t_individu	*tmp;
  int		cp;

  if ((cp = get_cp(prenom, individu)) == -1)
    return (1);
  sort_individu(individu);
  tmp = *individu;
  printf("personnes nées dans le %i : ", cp);
  while (tmp)
    {
      if (tmp->cp == cp)
	{
	  printf("%s", tmp->prenom);
	  tmp = tmp->next;
	  break;
	}
      tmp = tmp->next;
    }
  while (tmp)
    {
      if (tmp->cp == cp)
	printf(" / %s", tmp->prenom);
      tmp = tmp->next;
    }
  printf("\n");
  return (0);
}
