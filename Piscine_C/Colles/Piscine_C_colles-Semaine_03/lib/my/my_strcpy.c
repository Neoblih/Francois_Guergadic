/*
** my_strcpy.c for my_strcpy in /home/guerga_a/rendu/Piscine_C_J06
** 
** Made by francois guergadic
** Login   <guerga_a@epitech.net>
** 
** Started on  Mon Oct  6 08:50:16 2014 francois guergadic
** Last update Mon Oct  6 12:54:43 2014 francois guergadic
*/

char	*my_strcpy(char *dest, char *scr)
{
  int    count;

  count = 0;
  while (scr[count] != '\0')
    {
      dest[count] = scr[count];
      count++;
    }
    dest[count] = '\0';
  return (dest);
}
