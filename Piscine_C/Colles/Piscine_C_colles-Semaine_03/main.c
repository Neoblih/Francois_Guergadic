#include <unistd.h>
# define BUFF_SIZE (4096)

int	main(int ac, char* av[])
{
  char buff[BUFF_SIZE + 1];
  int len;
  char tab[20000];

  while ((len = read(0, buff, BUFF_SIZE)) > 0)
    {
      if (len != 0)
	{
	  buff[len] = 0;
	  my_strcat(tab, buff);
	}
    }
  what_is_this_glue(tab);
  my_putchar('\n');
}
