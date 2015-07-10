/*
** my_aff_comb.c for my_aff_comb in /home/guerga_a/rendu/Piscine_C_J03
** 
** Made by francois guergadic
** Login   <guerga_a@epitech.net>
** 
** Started on  Wed Oct  1 12:04:11 2014 francois guergadic
** Last update Wed Oct  1 22:12:15 2014 francois guergadic
*/

int	my_print(char c, char d, char u)
{
  my_putchar(c);
  my_putchar(d);
  my_putchar(u);
  if (c != '7' || d != '8' || u != '9')
    {
      my_putchar(',');
      my_putchar(' ');
    }
}

int	my_aff_comb()
{
  int i;
  int i2;
  int i3;

  i = 48;
  while (i < 56)
    {
      i2 = i + 1;
      while (i2 < 57)
	{
	  i3 = i2 + 1;
	  while (i3 < 58)
	    {
	      my_print(i, i2, i3);
	      i3++;
	    }
	  i2++;
	}
      i++;
    }
}
