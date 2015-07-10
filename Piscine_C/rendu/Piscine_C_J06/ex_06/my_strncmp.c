/*
** my_strncmp.c for my_strncmp in /home/guerga_a/rendu/Piscine_C_J06/ex_06
** 
** Made by francois guergadic
** Login   <guerga_a@epitech.net>
** 
** Started on  Mon Oct  6 10:52:17 2014 francois guergadic
** Last update Mon Oct  6 15:59:02 2014 francois guergadic
*/

int	my_strncmp(char *s1, char *s2, int n)
{
  int   count;

  count = 0;
  while ((s1[count] != '\0') && (s2[count] != '\0') && count < n)
    {
      if (s1[count] == s2[count])
	count++;
      else if (s1[count] > s2[count])
	return (1);
      else
	return (-1);
    }
  if (s1[count] == s2[count])
    return (0);
  else if (s1[count] > s2[count])
    return (1);
  else
    return (-1);
}
