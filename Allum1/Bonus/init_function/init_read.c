/*
** init_read.c for init_read in /home/guerga_a/B1/Prog_Elem/Allum1/init_function
** 
** Made by francois guergadic
** Login   <guerga_a@epitech.net>
** 
** Started on  Fri Feb 13 21:44:32 2015 francois guergadic
** Last update Fri Feb 13 21:48:46 2015 francois guergadic
*/

#include "allum1.h"

void    init_read(struct termios *t)
{
  tcgetattr(0, t);
  t->c_lflag &= ~ICANON;
  t->c_cc[VMIN] = 1;
  if (tcsetattr(0, TCSANOW, t) == -1)
    write(2, "fail\n", 5);
}
