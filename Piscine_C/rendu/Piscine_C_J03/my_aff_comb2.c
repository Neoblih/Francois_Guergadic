/*
** my_aff_comb2.c for my_aff_comb2 in /home/guerga_a/rendu/Piscine_C_J03
** 
** Made by francois guergadic
** Login   <guerga_a@epitech.net>
** 
** Started on  Wed Oct  1 13:55:52 2014 francois guergadic
** Last update Wed Oct  1 16:26:34 2014 francois guergadic
*/

int     my_aff_comb2()
{
  int nombreg;
  int nombred;

  nombreg = 0;
  nombred = 0;
  while (nombreg < 99)
    {
      nombred = nombreg + 1;
      while (nombred < 100)
	{
	  my_putchar(((nombreg / 10) + 48));
	  my_putchar(((nombreg % 10) + 48));
	  my_putchar(' ');
	  my_putchar(((nombred / 10) + 48));
          my_putchar(((nombred % 10) + 48));
	  if (nombreg != 98 || nombred != 99)
	    {
	      my_putchar(',');
	      my_putchar(' ');
	    }
	  nombred++;
	}
      nombreg++;
    }
}
