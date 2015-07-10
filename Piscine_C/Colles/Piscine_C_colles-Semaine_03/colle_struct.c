/*
** check_colle.c for check colle in /home/guerga_a/Colles/Piscine_C_colles-Semaine_03
** 
** Made by francois guergadic
** Login   <guerga_a@epitech.net>
** 
** Started on  Sat Oct 25 16:51:17 2014 francois guergadic
** Last update Sat Oct 25 19:11:55 2014 francois guergadic
*/

#include "./include/mycolle.h"

t_colle     t_colle1()
{
  struct s_colle colle1;

  colle1.left_up = 'o';
  colle1.right_up = 'o';
  colle1.left_down = 'o';
  colle1.right_down = 'o';
  colle1.colomn = '|';
  colle1.lign = '-';
  colle1.case_one = 'o';
  return (colle1);
}

t_colle     t_colle2()
{
  struct s_colle colle2;

  colle2.left_up = '\\';
  colle2.right_up = '/';
  colle2.left_down = '\\';
  colle2.right_down = '/';
  colle2.colomn = '*';
  colle2.lign = '*';
  colle2.case_one = '*';
  return (colle2);
}

t_colle     t_colle3()
{
  struct s_colle colle3;

  colle3.left_up = 'A';
  colle3.right_up = 'A';
  colle3.left_down = 'C';
  colle3.right_down = 'C';
  colle3.colomn = 'B';
  colle3.lign = 'B';
  colle3.case_one = 'B';
  return (colle3);
}

t_colle     t_colle4()
{
  struct s_colle colle4;

  colle4.left_up = 'A';
  colle4.right_up = 'C';
  colle4.left_down = 'A';
  colle4.right_down = 'C';
  colle4.colomn = 'B';
  colle4.lign = 'B';
  colle4.case_one = 'B';
  return (colle4);
}

t_colle     t_colle5()
{
  struct s_colle colle5;

  colle5.left_up = 'A';
  colle5.right_up = 'C';
  colle5.left_down = 'C';
  colle5.right_down = 'A';
  colle5.colomn = 'B';
  colle5.lign = 'B';
  colle5.case_one = 'B';
  return (colle5);
}
