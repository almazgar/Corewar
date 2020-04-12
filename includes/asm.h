/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avenonat <avenonat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/07 15:22:03 by avenonat          #+#    #+#             */
/*   Updated: 2020/04/09 09:54:39 by almazg           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_H
# define ASM_H
# define FD_SIZE 900
# include "../libft/headers/libft.h"
# include "op.h"

typedef struct			s_file
{
	char				*f_name;
	char				name[PROG_NAME_LENGTH];
	char				comment[COMMENT_LENGTH];
	int					a;
	char				zero[T_IND];
	int 				fd;
	int 				line_byte;
	int 				text;
}						t_file;

typedef struct 			s_exec
{
	int 				inst;
	int 				dir_size;
	char		 		*kta;
	unsigned char		ta;
	int 				line_byte;
	int 				n_bytes;
	char				*a1;
	int					ta1;
	char				*a2;
	int					ta2;
	char				*a3;
	int					ta3;
	struct s_exec		*next;
}						t_exec;

typedef struct			s_label
{
	char				*name;
	int					line_byte;
	struct s_label		*next;
}						t_label;

int						main(int argc, char **argv);
void					parsing(char *line, t_file *ssl);
void					skolkovo(char *line, t_file *ssl);
t_file					*init_ssl(void);
t_exec					*init_exec(void);
void					check_name(char *line, t_file *ssl);
void					check_comment(char *line, t_file *ssl);
t_exec					*check_exec(char *line, t_file *ssl);
t_exec					*connecting_people(char *line, t_file *ssl);
char					*strncpy_dog(char *dst, const char *src, size_t len);
void					compare(t_file *ssl, char *line, int j, t_exec *com);
void 					compare_2(t_file *ssl, char *line, int j, t_exec *com);
void					live(t_file *ssl, char *line, t_exec *com);
void					ld(t_file *ssl, char *line, t_exec *com);
t_exec					*skip_box(t_exec *com);
void					including_magic(int text);
void					write_error(char *str);
int						decimal(const char *str);
__int128_t				ft_atoin(const char *str, int i);
int						is_registr(const char *a);
void					take_label(char *line, t_file *ssl, t_label **list, t_exec *co);
t_label					*cnl(char *name, int byte_c);
void					add_label(t_label **list, t_label *new);
t_label					*zero_label();
void					take_arg1(char *line, t_file *ssl, t_exec *com);
void					take_arg2(char *line, t_file *ssl, t_exec *com);
int						is_limit(int c);
void					skip_probel(t_file *ssl, const char *line);
int						is_whitespace(int c);
void					no_comment(t_file *ssl, const char *li);
void					no_separator(t_file *ssl, char *line);
void					aff(t_file *ssl, char *line, t_exec *com);
void					lfork(t_file *ssl, char *line, t_exec *com);
void					ft_fork(t_file *ssl, char *line, t_exec *com);
void					zjmp(t_file *ssl, char *line, t_exec *com);
void					lld(t_file *ssl, char *line, t_exec *com);
void					st(t_file *ssl, char *line, t_exec *com);
void					add(t_file *ssl, char *line, t_exec *com);
void					take_arg3(char *line, t_file *ssl, t_exec *com);
void					sub(t_file *ssl, char *line, t_exec *com);
void					and(t_file *ssl, char *line, t_exec *com);
void					ft_or(t_file *ssl, char *line, t_exec *com);
void					ft_xor(t_file *ssl, char *line, t_exec *com);
void					ldi(t_file *ssl, char *line, t_exec *com);
void					lldi(t_file *ssl, char *line, t_exec *com);
void					sti(t_file *ssl, char *line, t_exec *com);
void					add_comand(t_exec *list, t_exec *new);
void					label_change(t_label *list, t_exec **com);
void					label_search1(t_label **list, t_exec **com);
void					label_search2(t_label **list, t_exec **com);
void					label_search3(t_label **list, t_exec **com);
void					arg_add(t_exec **com);
void					kod_type_arg(t_exec **com);
void					add_kta(t_exec **com, int i);
void					free_label(t_label *list);
void					free_exec(t_exec *com);
void					free_t_file(t_file *ssl);
void					line_to_write(t_exec **com, t_file *ssl);
void					including_size(t_file *ssl);
#endif
