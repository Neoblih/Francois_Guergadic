/*
** my_aff_chiffre.c for my_aff_chiffre in /home/guerga_a/rendu/Piscine_C_J03
** 
** Made by francois guergadic
** Login   <guerga_a@epitech.net>
** 
** Started on  Wed Oct  1 10:53:37 2014 francois guergadic
** Last update Thu Oct  2 18:00:31 2014 francois guergadic
*/

int     my_aff_chiffre()
{
  int i;

  i = 48;
  while (i < 58)
    {
      my_putchar(i);
      i = i + 1;
    }
}
