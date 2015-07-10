/*
** FASTAtools.h for header file in /home/guerga_a/Piscine/FASTAtools/include
**
** Made by francois guergadic
** Login   <guerga_a@epitech.net>
**
** Started on  Wed Jun 24 09:40:39 2015 francois guergadic
** Last update Thu Jun 25 09:34:02 2015 francois guergadic
*/

#ifndef FASTAtools_H_
# define FASTAtools_H_

# define BUFF_SIZE 1024

# include <string.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>

/* main.c */
void	free_tab(char **tab);
void	aff_fasta(char **id_tab, char **seq_tab);

/* Prerequis.c */
char	my_maj(char c);

/* ### global ### */
/* my_read.c */
char	*my_read();

/* ### part1 ### */
/* my_split.c */
char	**create_id_tab(char *str);
char	**create_seq_tab(char *str);
int	id_number(char *str);
int	id_len(char *str);
int	seq_len(char *str);
/* tools.c */
int	my_select(char c);
void	part_1();

/* ### part2 ### */
/* my_split2.c */
char    **create_ARN_tab(char *str);
void	part_2();

/* ### part3 ### */
/* reverse.c */
void	part_3();

/* ### part4 ### */
/* part4.c */
void	part_4(int k);
int	tab_len(char **tab);
/* tab_sort.c */
char	**sort_tab(char **tab);
char	**remove_double(char **tab);

/* ### part5 ### */
/* part5.c  */
void	part_5();

/* ### part6 ### */
/* part6.c */
void	part_6();
/* aff.c  */
void	aff_acide(char *str);
char	my_aff_1(char *str);
char	my_aff_2(char *str);
char	my_aff_3(char *str);

#endif /* !FASTAtools_H_ */
