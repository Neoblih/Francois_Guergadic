/*
** my_ls.h for header in /home/guerga_a/B1/Sys_Unix/PSU_2014_my_ls/include
** 
** Made by francois guergadic
** Login   <guerga_a@epitech.net>
** 
** Started on  Sat Nov 29 12:51:14 2014 francois guergadic
** Last update Sat Nov 29 14:57:46 2014 francois guergadic
*/

#ifndef MY_LS_H_
# define MY_LS_H_

int             file_nb(char *name);
char            **init_tab(char *name);
void            sort_tab(char **tab);
void            aff_ls(char **tab);
void            aff_ls_a(char **tab);
char            *rm_dot(char *str);
void		free_tab(char **tab);
void		error_invarg(char *arg);
void		error_access(char *path);

#endif /* !MY_LS_H_ */
