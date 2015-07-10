/*
** my_strstr.c for my_strstr in /home/guerga_a/rendu/Piscine_C_J06/ex_04
** 
** Made by francois guergadic
** Login   <guerga_a@epitech.net>
** 
** Started on  Mon Oct  6 09:51:51 2014 francois guergadic
** Last update Mon Oct  6 15:31:08 2014 francois guergadic
*/

char	*my_strstr(char *str, char *to_find)
{
  int    count;
  int    rec;

  count = 0;
  while (str[count] != '\0')
    {
      rec = 0;
      if (str[count] == to_find[rec])
	{
	  while (str[count] == to_find[rec])
	    {
	      count++;
	      rec++;
	    }
	  if (to_find[rec] == '\0')
	    {
	      return (char*)&str[count - rec];
	    }
	}
      count++;
    }
    return (char*)&str[count];
}
