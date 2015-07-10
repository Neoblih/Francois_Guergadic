/*
** my_revstr.c for my_revstr in /home/guerga_a/rendu/Piscine_C_J06/ex_03
** 
** Made by francois guergadic
** Login   <guerga_a@epitech.net>
** 
** Started on  Mon Oct  6 09:08:59 2014 francois guergadic
** Last update Tue Oct  7 23:04:24 2014 francois guergadic
*/

char	*my_revstr(char *str)
{
  int   i;
  int   j;
  int	temp;
  int	length;

  i = 0;
  j = 0;
  while (str[i] != '\0')
    {
      i++;
    }
  length = i;
  while (j < length / 2)
    {
      temp = str[i];
      str[i] = str[j];
      str[j] = temp;
      i--;
      j++;
    }
  return (str);
}
