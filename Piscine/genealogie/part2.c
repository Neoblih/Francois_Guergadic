/*
** part2.c for part2 in /home/guerga_a/Piscine/genealogie
**
** Made by francois guergadic
** Login   <guerga_a@epitech.net>
**
** Started on  Thu Jul  2 16:22:07 2015 francois guergadic
** Last update Thu Jul  2 17:13:44 2015 francois guergadic
*/

#include "genealogie.h"

char	*last_name(char *dir_path)
{
  int	i;
  int	j;
  char	*result;

  j = (i = 0);
  if ((result = malloc(sizeof(char) * (strlen(dir_path) + 1))) == NULL)
    return (NULL);
  while (dir_path[i])
    {
      if (dir_path[i] != '.' && dir_path[i] != '/' && dir_path[i] >= 'A')
	{
	  result[j] = dir_path[i];
	  j++;
	}
      i++;
    }
  result[j] = '\0';
  return (result);
}

int	get_day(char *str)
{
  char	temp[3];

  temp[0] = str[0];
  temp[1] = str[1];
  temp[2] = '\0';
  return (atoi(temp));
}

char	*get_month(char *str)
{
  char	*result;

  if ((result = malloc(sizeof(char) * 10)) == NULL)
    return (NULL);
  if (strncmp(&str[3], "01", 2) == 1)
    strcpy(result, "janvier");
  else if (strncmp(&str[3], "02", 2) == 1)
    strcpy(result, "fevrier");
  else if (strncmp(&str[3], "03", 2) == 1)
    strcpy(result, "mars");
  else if (strncmp(&str[3], "04", 2) == 1)
    strcpy(result, "avril");
  else if (strncmp(&str[3], "05", 2) == 1)
    strcpy(result, "mai");
  else if (strncmp(&str[3], "06", 2) == 1)
    strcpy(result, "juin");
  else if (strncmp(&str[3], "07", 2) == 1)
    strcpy(result, "juillet");
  else if (strncmp(&str[3], "08", 2) == 1)
    strcpy(result, "aout");
  else if (strncmp(&str[3], "09", 2) == 1)
    strcpy(result, "septembre");
  else if (strncmp(&str[3], "10", 2) == 1)
    strcpy(result, "octobre");
  else if (strncmp(&str[3], "11", 2) == 1)
    strcpy(result, "novembre");
  else if (strncmp(&str[3], "12", 2) == 1)
    strcpy(result, "décembre");
  return (result);
}

int		part2(char *dir_path, char *prenom, t_individu **individu)
{
  t_individu	*temp;

  temp = *individu;
  while (temp)
    {
      if (strcmp(temp->prenom, prenom) == 0)
	{
	  printf("%s %s\n", prenom, last_name(dir_path));
	  printf("né le %i %s %i (%i)\n", get_day(temp->date),
		 get_month(temp->date), atoi(&temp->date[6]), temp->cp);
	  if (temp->sexe == 0)
	    printf("de sexe masculin\n");
	  else
	    printf("de sexe feminin\n");
	  printf("%i %s%c%c %i %i\n", temp->sexe + 1, &temp->date[8], temp->date[3],
		 temp->date[4], temp->cp, temp->secu);
	  printf("%s", temp->cv);
	  return (0);
	}
      temp = temp->next;
    }
  fprintf(stderr, "Erreur: Il n'y a pas de %s dans la famille %s!\n",
	  prenom, last_name(dir_path));
  return (1);
}
