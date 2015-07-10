/*
** aff_tab.c for aff_tab in /home/guerga_a/B1/Prog_Elem/CPE_2015_bsq
** 
** Made by francois guergadic
** Login   <guerga_a@epitech.net>
** 
** Started on  Sun Jan 18 18:49:04 2015 francois guergadic
** Last update Sun Jan 18 18:55:59 2015 francois guergadic
*/

#include <unistd.h>
#include <fcntl.h>
#include "./include/bsq.h"
#include "./include/my.h"

void	aff_tab(char **tab)
{
  int	i;

  i = 0;
  while (tab[i])
    {
      my_putstr(tab[i]);
      my_putchar('\n');
      i++;
    }
}

char	**recup_buff(char *file_name)
{
  char	buff[BUFF_SIZE + 1];
  char	**recup_tab;
  int	fd;

  fd = open(file_name, O_RDONLY);
  read(fd, buff, BUFF_SIZE);
  recup_tab = my_buff_to_tab(buff);
  return (recup_tab);
}
