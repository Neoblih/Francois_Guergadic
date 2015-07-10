/*
** my_strupcase.c for my_strupcase in /home/guerga_a/rendu/Piscine_C_J06/ex_07
** 
** Made by francois guergadic
** Login   <guerga_a@epitech.net>
** 
** Started on  Mon Oct  6 11:04:57 2014 francois guergadic
** Last update Mon Oct  6 16:47:32 2014 francois guergadic
*/

char	*my_strupcase(char *str)
{
  int    i;

  i=0;
  while (str[i] != '\0')
    {
      if ((str[i] < 123) && (str[i] > 96))
	{
	  str[i] = (str[i] - 32);
	}
      i++;
    }
  return (str);
}
