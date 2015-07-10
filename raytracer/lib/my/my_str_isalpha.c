/*
** my_str_isalpha.c for str_isaplpha in /home/guerga_a/B1/Sys_Unix/PSU_2014_my_ls/lib
** 
** Made by francois guergadic
** Login   <guerga_a@epitech.net>
** 
** Started on  Sat Nov 29 12:43:37 2014 francois guergadic
** Last update Wed Dec  3 10:31:17 2014 francois guergadic
*/

int	my_str_isalpha(char *str)
{
  int	i;

  i = 0;
  if (str[i] == '\0')
    return (0);
  while (((str[i] <= 122) && (str[i] >= 97))
	 || ((str[i] <= 90) && (str[i] >= 65)))
    {
      if (str[i + 1] == '\0')
	return (1);
      i++;
    }
  return (0);
}
