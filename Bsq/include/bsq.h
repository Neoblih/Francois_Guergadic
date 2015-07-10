/*
** bsq.h for bsq in /home/guerga_a/B1/Prog_Elem/CPE_2015_bsq/include
** 
** Made by francois guergadic
** Login   <guerga_a@epitech.net>
** 
** Started on  Wed Jan 14 13:54:34 2015 francois guergadic
** Last update Sun Jan 18 18:53:27 2015 francois guergadic
*/

#ifndef BSQ_H_
# define BSQ_H_
char	**my_buff_to_tab(char *tab);
void	aff_tab(char **tab);
char	**recup_buff(char *file_name);
# define BUFF_SIZE (4096)
#endif /* !BSQ_H_ */
