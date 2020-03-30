/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avenonat <avenonat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/07 15:22:03 by avenonat          #+#    #+#             */
/*   Updated: 2020/03/29 18:59:31 by almazg           ###   ########.fr       */
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
}						t_file;

typedef struct 			s_exec
{
	char 				*label;
	int 				code_type;
	char 				inst;
	char 				*reg;
	char 				*direct_label;
	int 				direct;
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
	int32_t				op_pos;
	struct s_label		*next;
}						t_label;

int						main(int argc, char **argv);
void					parsing(char *line, t_file *ssl);
t_file					*init_struct(void);
t_exec					*init_exec(void);
void					check_name(int text, char *line, t_file *ssl);
void					check_comment(int text, char *line, t_file *ssl);
t_exec					*check_exec(char *line, t_file *ssl);
char					*strncpy_dog(char *dst, const char *src, size_t len);
void					compare(t_file *ssl, char *line, int j, t_exec *com);
void 					compare_2(t_file *ssl, char *line, int j);
void					live(t_file *ssl, char *line, t_exec *com);
void					ld(t_file *ssl, char *line, t_exec *com);
t_exec					*skip_box(t_exec *com);
void					including_magic(int text);
void					write_error(char *str);
int						decimal(const char *str);
__int128_t				ft_atoin(const char *str, int i);
int						is_registr(const char *a);
void					take_label(char *line, t_file *ssl, t_label **list, t_exec *com);
t_label					*cnl(char *name, int byte_c);
void					add_label(t_label **list, t_label *new);
t_label					*zero_label();
void					take_arg1(char *line, t_file *ssl, t_exec *com);
int						is_limit(int c);
void					skip_probel(t_file *ssl, const char *line);
int						is_whitespace(int c);
void					no_comment(t_file *ssl, const char *li);
#endif
