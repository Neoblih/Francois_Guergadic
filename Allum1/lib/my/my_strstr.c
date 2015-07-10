/*
** my_strstr.c for strstr in /home/guerga_a/B1/Sys_Unix/PSU_2014_my_ls/lib
** 
** Made by francois guergadic
** Login   <guerga_a@epitech.net>
** 
** Started on  Sat Nov 29 12:48:15 2014 francois guergadic
** Last update Sat Nov 29 12:48:17 2014 francois guergadic
*/

char	*my_strstr(char *str, char *to_find)
{
  int   i;
  int   j;

  i = 0;
  while (str[i] != '\0')
    {
      j = 0;
      if (str[i] == to_find[j])
	{
	  while (str[i] == to_find[j])
	    {
	      i++;
	      j++;
	    }
	  if (to_find[j] == '\0')
	    return (char*)&str[i - j];
	}
      i++;
    }
  return (char*)&str[i];
}
