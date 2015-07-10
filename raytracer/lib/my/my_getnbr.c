/*
** my_getnbr.c for getnbr in /home/guerga_a/B1/Sys_Unix/PSU_2014_my_ls/lib
** 
** Made by francois guergadic
** Login   <guerga_a@epitech.net>
** 
** Started on  Sat Nov 29 12:38:37 2014 francois guergadic
** Last update Sat Nov 29 12:38:40 2014 francois guergadic
*/

int     my_result(int rang, int pos, int n_neg, char *str)
{
  int   pow;
  int   result;
  int   result_save;

  result = 0;
  pow = 1;
  while (rang > 0)
    {
      pos--;
      result_save = result;
      result = (result - ((str[pos] - 48) * pow));
      if (result % pow != result_save)
        return (0);
      pow = pow * 10;
      rang--;
    }
  if ((n_neg % 2) == 0)
    result = -result;
  return (result);
}

int     my_getnbr(char *str)
{
  int   n_neg;
  int   pos;
  int   rang;
  int   result_fin;

  result_fin = 0;
  n_neg = 0;
  rang = 0;
  pos = 0;
  while ((str[pos] == '-') || (str[pos] == '+'))
    {
      if (str[pos] == '-')
        n_neg++;
      pos++;
      n_neg++;
      pos++;
    }
  while ((str[pos] >= '0') && (str[pos] <= '9'))
    {
      rang++;
      pos++;
    }
  result_fin = my_result(rang, pos, n_neg, str);
  return (result_fin);
}
