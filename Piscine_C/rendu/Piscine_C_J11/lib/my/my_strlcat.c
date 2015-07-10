/*
** my_strlcat.c for my_strlcat in /home/guerga_a/rendu/Piscine_C_J07/ex_01
** 
** Made by francois guergadic
** Login   <guerga_a@epitech.net>
** 
** Started on  Tue Oct  7 17:17:52 2014 francois guergadic
** Last update Tue Oct  7 17:51:16 2014 francois guergadic
*/

char	*my_strlcat(char *dest, char *scr, int l)
{
  int    i;
  int	 j;

  i = 0;
  j = 0;
  while (dest[i] != '\0' && (i < l))
    {
      i++;
    }
  while (scr[j] != '\0' && i < l)
    {
      dest[i] = scr[j];
      j++;
      i++;
    }
  dest[i] = '\0';
  return (dest);
}
