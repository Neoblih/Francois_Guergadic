/*
** main.c for main in /home/guerga_a/Piscine/genealogie
**
** Made by francois guergadic
** Login   <guerga_a@epitech.net>
**
** Started on  Thu Jul  2 10:50:49 2015 francois guergadic
** Last update Fri Jul  3 12:20:57 2015 francois guergadic
*/

#include "genealogie.h"

char	*my_cat(char *dir_path, char *file_name)
{
  char	*result;

  if ((result = malloc(sizeof(char) *
		       (strlen(dir_path) + strlen(file_name) + 2))) == NULL)
    return (NULL);
  result[0] = '\0';
  strcpy(result, dir_path);
  strcat(result, "/");
  strcat(result, file_name);
  return (result);
}

void	aff_struct(t_individu **individu)
{
  t_individu *tmp;

  tmp = *individu;
  while (tmp != NULL)
    {
      printf("Name: %s\nDate: %s\nCode Postal: %i\n", tmp->prenom, tmp->date, tmp->cp);
      printf("Cv: %s\nSexe: %i\nSecu: %i\n\n", tmp->cv, tmp->sexe, tmp->secu);
      tmp = tmp->next;
    }
}

int		add_to_list(char *file_path, char *name, struct stat *buf, t_individu **individu)
{
  t_individu	*temp;

  buf = buf;
  if ((temp = malloc(sizeof(t_individu))) == NULL)
    return (1);
  temp->prenom = name;
  if ((temp->date = malloc(sizeof(char) * 12)) == NULL)
    return (1);
  strftime(temp->date, 12, "%d/%m/%Y", gmtime(&(buf->st_mtime)));
  temp->cp = buf->st_size % 100;
  temp->cv = my_read(file_path);
  if (buf->st_mode & S_IRGRP)
    temp->sexe = 1;
  else
    temp->sexe = 0;
  temp->secu = buf->st_ino % 1000000;
  temp->next = *individu;
  *individu = temp;
  return (0);
}

int		feed_individu(char *dir_path, char **tab, t_individu **individu)
{
  int		i;
  struct stat	buf;
  char		*file_path;

  i = 0;
  while (tab[i])
    {
      file_path = my_cat(dir_path, tab[i]);
      if ((stat(file_path, &buf)) == -1)
	return (1);
      if ((add_to_list(file_path, tab[i], &buf, individu)) == 1)
	return (1);
      free(file_path);
      i++;
    }
  return (0);
}

int		main(int ac, char **av)
{
  t_individu	*individu;
  char		**file;
  char		yolo[BUFF_SIZE];

  individu = NULL;
  if (ac != 3)
    {
      fprintf(stderr, "Usage: ./genealogie rep file\n");
      return (1);
    }
  if ((file = init_tab(av[1])) == NULL)
    {
      fprintf(stderr, "Bad argument, can't open dir or read file\n");
      return (1);
    }
  remove_point(file);
  feed_individu(av[1], file, &individu);
  if ((read(0, yolo, BUFF_SIZE)) == -1)
    return (1);
  if (yolo[0] == '1')
    part1(&individu);
  else if (yolo[0] == '2')
    part2(av[1], av[2], &individu);
  else if (yolo[0] == '3')
    part3(av[2], &individu);
  else if (yolo[0] == '4')
    part4()
  else if (yolo[0] == '6')
    printf("cousin(e)s : aucun\n");
  else if (yolo[0] == '7')
    printf("demi-frères et soeurs : aucun\n");
  else
    fprintf(stderr, "Bad number\n");
  return (0);
}
