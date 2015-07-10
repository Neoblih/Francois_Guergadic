/*
** my_list.h for s_list in /home/guerga_a/rendu/Piscine_C_J12/include
** 
** Made by francois guergadic
** Login   <guerga_a@epitech.net>
** 
** Started on  Tue Oct 21 09:29:40 2014 francois guergadic
** Last update Tue Oct 21 10:51:26 2014 francois guergadic
*/

#ifndef MYLIST_H_
# define MYLIST_H_

typedef struct s_list
{
  void *data;
  struct s_list *next;
} t_list;

#endif /* !MYLIST_H_ */
