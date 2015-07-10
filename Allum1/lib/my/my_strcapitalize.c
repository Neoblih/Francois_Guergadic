/*
** my_strcapitalize.c for strcapitalize in /home/guerga_a/B1/Sys_Unix/PSU_2014_my_ls/lib
** 
** Made by francois guergadic
** Login   <guerga_a@epitech.net>
** 
** Started on  Sat Nov 29 12:42:00 2014 francois guergadic
** Last update Sat Nov 29 12:42:02 2014 francois guergadic
*/

char	*my_strcapitalize(char *str)
{
  int	i;

  if (str[0] == '\0')
    return (str);
  if (str[0] <= 122 && str[0] >= 97)
    str[0] = str[0] - 32;
  if (str[1] == '\0')
    return (str);
  i = 1;
  while (str[i] != '\0')
    {
      if (str[i] == '\0')
	return (str);
      if (str[i - 1] < 65 || str[i - 1] > 122)
	if (str[i] <= 122 && str[i] >= 97)
	  str[i] = str[i] - 32;
      if ((str[i - 1] > 90 && str[i - 1] < 97))
	if (str[i] <= 122 && str[i] >= 97)
	  str[i] = str[i] - 32;
      i++;
    }
  return (str);
}
