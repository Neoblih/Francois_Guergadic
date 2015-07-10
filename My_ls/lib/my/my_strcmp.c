/*
** my_strcmp.c for strcmp in /home/guerga_a/B1/Sys_Unix/PSU_2014_my_ls/lib
** 
** Made by francois guergadic
** Login   <guerga_a@epitech.net>
** 
** Started on  Sat Nov 29 12:42:40 2014 francois guergadic
** Last update Sat Nov 29 12:42:42 2014 francois guergadic
*/

int	my_strcmp(char *s1, char *s2)
{
  int	i;

  i = 0;
  while (s1[i] == s2[i] || s1[i] == (s2[i] + 32)  || s1[i] == (s2[i] - 32))
    {
      if (s1[i] == '\0' && s2[i] == '\0')
	return (0);
      if (s1[i] == '\0')
	return (-1);
      if (s2[i]== '\0')
        return (1);
      i++;
    }
  if (s1[i] > s2[i] && s1[i] != (s2[i] + 32))
    return (1);
  else if (s1[i] < s2[i] && s1[i] != (s2[i] - 32))
    return (-1);
  return (0);
}
