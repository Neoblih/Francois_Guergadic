/*
** aff.c for aff in /home/guerga_a/Piscine/FASTAtools/part6
**
** Made by francois guergadic
** Login   <guerga_a@epitech.net>
**
** Started on  Thu Jun 25 09:04:54 2015 francois guergadic
** Last update Thu Jun 25 09:39:46 2015 francois guergadic
*/

#include "FASTAtools.h"

char	my_aff_1(char *str)
{
  if (strncmp(str, "GCT", 3) == 0 || strncmp(str, "GCC", 3) == 0 ||
      strncmp(str, "GCA", 3) == 0 || strncmp(str, "GCG", 3) == 0)
    return ('A');
  if (strncmp(str, "TGT", 3) == 0 || strncmp(str, "TGC", 3) == 0)
    return ('C');
  if (strncmp(str, "GAT", 3) == 0 || strncmp(str, "GAC", 3) == 0)
    return ('D');
  if (strncmp(str, "GAA", 3) == 0 || strncmp(str, "GAG", 3) == 0)
    return ('E');
  if (strncmp(str, "TTT", 3) == 0 || strncmp(str, "TTC", 3) == 0)
    return ('F');
  if (strncmp(str, "GGT", 3) == 0 || strncmp(str, "GGC", 3) == 0 ||
      strncmp(str, "GGA", 3) == 0 || strncmp(str, "GGG", 3) == 0)
    return ('G');
  if (strncmp(str, "ATT", 3) == 0 || strncmp(str, "ATC", 3) == 0 ||
      strncmp(str, "ATA", 3) == 0)
    return ('I');
  if (strncmp(str, "AAA", 3) == 0 || strncmp(str, "AAG", 3) == 0)
    return ('K');
  if (strncmp(str, "TTA", 3) == 0 || strncmp(str, "TTG", 3) == 0 ||
      strncmp(str, "CTC", 3) == 0 || strncmp(str, "CTT", 3) == 0 ||
      strncmp(str, "CTA", 3) == 0 || strncmp(str, "CTG", 3) == 0)
    return ('L');
  return (my_aff_2(str));
}

char	my_aff_2(char *str)
{
  if (strncmp(str, "CAT", 3) == 0 || strncmp(str, "CAC", 3) == 0)
    return ('H');
  if (strncmp(str, "ATG", 3) == 0)
    return ('M');
  if (strncmp(str, "AAT", 3) == 0 || strncmp(str, "AAC", 3) == 0)
    return ('N');
  if (strncmp(str, "CCT", 3) == 0 || strncmp(str, "CCA", 3) == 0 ||
      strncmp(str, "CCC", 3) == 0 || strncmp(str, "CCG", 3) == 0)
    return ('P');
  if (strncmp(str, "CAA", 3) == 0 || strncmp(str, "CAG", 3) == 0)
    return ('Q');
  if (strncmp(str, "AGA", 3) == 0 || strncmp(str, "CGT", 3) == 0 ||
      strncmp(str, "CDG", 3) == 0 || strncmp(str, "CGC", 3) == 0 ||
      strncmp(str, "CGA", 3) == 0 || strncmp(str, "AGA", 3) == 0)
    return ('R');
  if (strncmp(str, "TCT", 3) == 0 || strncmp(str, "TCG", 3) == 0 ||
      strncmp(str, "TCC", 3) == 0 || strncmp(str, "AGT", 3) == 0 ||
      strncmp(str, "TCA", 3) == 0 || strncmp(str, "AGC", 3) == 0)
    return ('S');
  if (strncmp(str, "ACT", 3) == 0 || strncmp(str, "ACC", 3) == 0 ||
      strncmp(str, "ACG", 3) == 0 || strncmp(str, "ACA", 3) == 0)
    return ('T');
  return (my_aff_3(str));
}

char	my_aff_3(char *str)
{
  if (strncmp(str, "GTT", 3) == 0 || strncmp(str, "GTC", 3) == 0 ||
      strncmp(str, "GTG", 3) == 0 || strncmp(str, "GTA", 3) == 0)
    return ('V');
  if (strncmp(str, "TGG", 3) == 0)
    return ('W');
  if (strncmp(str, "TAT", 3) == 0 || strncmp(str, "TAC", 3) == 0)
    return ('Y');
  if (str[0] == 'N' || str[1] == 'N' || str[2] == 'N')
    return ('X');
  return ('z');
}

void	aff_acide(char *str)
{
  if ((my_aff_1(str)) != 'z')
    printf("%c", my_aff_1(str));
}
