/*
** my_strcapitalize.c for my_strcapitalize in /home/guerga_a/rendu/Piscine_C_J06/ex_09
** 
** Made by francois guergadic
** Login   <guerga_a@epitech.net>
** 
** Started on  Mon Oct  6 11:18:03 2014 francois guergadic
** Last update Mon Oct  6 11:30:53 2014 francois guergadic
*/

char *my_strcapitalize (char *str)
{
  int i;
  int end_of_word;

  i = 0;
  end_of_word = 1;
  while (str[i] != '\0')
    {
      if ((str[i] > 96) && (str[i] <123) && (end_of_word == 1))
	str[i] = (str[i] - 32);
      if ((str[i] == ' ') || (str[i] == '+') || (str[i] == '-'))
	end_of_word = 1;
      else
	end_of_word = 0;
      i++;
    }
  return (str);
}
