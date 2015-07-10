/*
** my_strncmp.c for strncmp in /home/guerga_a/B1/Sys_Unix/PSU_2014_my_ls/lib
** 
** Made by francois guergadic
** Login   <guerga_a@epitech.net>
** 
** Started on  Sat Nov 29 12:47:25 2014 francois guergadic
** Last update Thu Jan 22 12:58:28 2015 francois guergadic
*/

int	my_strncmp(char *s1, char *s2, int n)
{
  int	i;

  i = 0;
  while (s1[i] == s2[i])
    {
      if (i + 1 > n)
	return (0);
      if (s1[i] == '\0' && s2[i] == '\0')
	return (0);
      if (s1[i] == '\0')
	return (-1);
      if (s2[i]== '\0')
        return (1);
      i++;
    }
  if (s1[i] > s2[i])
    return (1);
  if (s1[i] < s2[i])
    return (-1);
  return (0);
}
