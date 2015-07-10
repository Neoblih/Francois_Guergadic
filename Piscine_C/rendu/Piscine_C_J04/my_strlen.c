/*
** my_strlen.c for my_strlen in /home/guerga_a/rendu/Piscine_C_J04
** 
** Made by francois guergadic
** Login   <guerga_a@epitech.net>
** 
** Started on  Thu Oct  2 11:56:28 2014 francois guergadic
** Last update Fri Oct 10 15:46:41 2014 francois guergadic
*/

int	my_strlen(char *str)
{
  int i;

  i=0;
  while (str[i] != '\0')
    {
      i++;
    }
  return (i);
}
