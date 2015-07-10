/*
** SMBLparser.h for  in /home/guerga_a/Piscine/SBMLparser/include
** 
** Made by francois guergadic
** Login   <guerga_a@epitech.net>
** 
** Started on  Mon Jun 15 09:40:24 2015 francois guergadic
** Last update Wed Jun 17 15:57:27 2015 francois guergadic
*/

#ifndef SBMLPARSER_H_
# define SBMLPARSER_H_

# define BUFF_SIZE 1024

void	all_flag(char **av);
void	free_tab(char **tab);
char	**my_strtowordtab_synthese(char *str);
char	*my_read(char *str);
int	my_strcmp(char *s1, char *s2);
int	my_strlen(char *str);
int	is_alph(char c);
int	word_len(char *str);
char	*my_strcat(char *dest, char *srcs);
char	*parsing(char *str);
char	**sort_tab(char **tab);
char	**remove_double(char **tab);
char	*sort_str(char *str);
int	my_strrealcmp(char *s1, char *s2);
void	aff_parsing(char **tab);
char	**get_pars_tab(char *str);
void	pars_id(char *id, char *str, int e, int json);
void	aff_compartment(char *id, char *str);
void	aff_species(char *id, char *str);
void	aff_reaction(char *id, char *str);
void	aff_reaction_e(char *id, char *str);
int	my_strncmp(char *s1, char *s2, int n);
void	aff_stoi(int i, char *str, int n);
int	aff_compound(char *str);
void	aff_arrow(char *str, int i);
int	aff_smth(char *str);
void	json_compound(char *str, char *id);
void	json_reaction(char *str, char *id);
void	aff_compartment_in_json(char *str, int i);
char	*aff_compartment_id(char *str, int i);
void	aff_species_in_json(char *str, int i);
void	aff_reaction_in_json(char *str, int i);
char	**species_tab(char *str, char *id);
char	*feed_comp(char *str, char *dest);
int	get_comp_len(char *str);
void	aff_any(char *str);

#endif /* !SBMLPARSER_H_ */
