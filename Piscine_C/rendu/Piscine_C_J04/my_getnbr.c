/*
** my_getnbr.c for my_getnbr in /home/guerga_a/rendu/Piscine_C_J04
** 
** Made by francois guergadic
** Login   <guerga_a@epitech.net>
** 
** Started on  Thu Oct  2 13:34:05 2014 francois guergadic
** Last update Fri Oct  3 22:43:14 2014 francois guergadic
*/

int	catch_sign(char c, int actual)
{
  if (c == '-')
    {
      if (actual == 1)
	{
	  return (0);
	}
      else
	{
	  return (1);
	}
    }
  else
    {
      return (actual);
    }
}

int	my_getnbr(char *str)
{
  int count;
  int ispos;

  count=1;
  while (str[count] != '\0')
    {
      if (str[count] < 48 || str[count] > 57)
	{
	  ispos=catch_sign(str[count], ispos);
	}
      count++;
    }
}
