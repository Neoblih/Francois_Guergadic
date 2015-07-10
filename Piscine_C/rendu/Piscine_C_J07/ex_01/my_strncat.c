/*
** my_strncat.c for my_strncat in /home/guerga_a/rendu/Piscine_C_J07/ex_01
** 
** Made by francois guergadic
** Login   <guerga_a@epitech.net>
** 
** Started on  Tue Oct  7 17:13:42 2014 francois guergadic
** Last update Tue Oct  7 17:46:23 2014 francois guergadic
*/

char	*my_strncat(char *dest, char *scr, int n)
{
  int	 i;
  int	j;

  i = 0;
  j = 0;
  while (dest[i] != '\0')
    {
      i++;
    }
  while (scr[j] != '\0' && j < n)
    {
      dest[i + j] = scr[j];
      j++;
    }
  dest[i+j] = '\0';
  return (dest);
}
