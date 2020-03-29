/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avenonat <avenonat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/07 15:22:03 by avenonat          #+#    #+#             */
/*   Updated: 2020/03/29 17:05:52 by almazg           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_H
# define ASM_H
# define FILE_NAME 20
# define FD_SIZE 900
# include "../libft/headers/libft.h"
# include "op.h"

# define MAX_STATEMENT_SIZE 14


typedef struct			s_file
{
	char				*f_name;
	char				name[PROG_NAME_LENGTH];
	char				comment[COMMENT_LENGTH];
	int					a;
	char				zero[T_IND];
	int 				cb_line;   // количество байт от начала (1)
	int 				fd;
}						t_file;

typedef struct 			s_exec
{
	char 				*label;
	char 				inst[0];
	char 				*reg;
	char 				*ted;
	char 				sym;
	char 				*direct_label;
	char 				sym1;
	int 				number;
	сhar				*a1;
	шnt					ta1;
	сhar				*a2;
	int					ta2;
	char				*a3;
	int					ta3;
	struct s_file		*next;
}						t_exec;

typedef struct	s_op
{
	char			*name;
	int				args_number;
	unsigned int	args[3];
	int				opcode;
	int				wait;
	char			*desc;
	int				is_argtype;
	int				is_tdir_2bytes;
}				t_op;

typedef enum
{
	COMMAND,
	STRING,
	LABEL,
	OPERATOR,
	REGISTER,
	DIRECT,
	DIRECT_LABEL,
	INDIRECT,
	INDIRECT_LABEL,
	SEPARATOR,
	NEW_LINE,
	END
}	t_type;

static char				*g_type[] = {
		"COMMAND",
		"STRING",
		"LABEL",
		"OPERATOR",
		"REGISTER",
		"DIRECT",
		"DIRECT_LABEL",
		"INDIRECT",
		"INDIRECT_LABEL",
		"SEPARATOR",
		"NEW_LINE",
		"END"
};

typedef struct			s_mention
{
	unsigned			row;
	unsigned			column;
	int32_t				pos;
	int32_t				op_pos;
	size_t				size;
	struct s_mention	*next;
}						t_mention;

typedef struct			s_token
{
	char				*content;
	t_type				type;
	unsigned			row;
	unsigned			column;
	struct s_token		*next;
}						t_token;

typedef struct			s_label
{
	char				*name;
	int32_t				op_pos;
	t_mention			*mentions;
	struct s_label		*next;
}						t_label;

typedef struct			s_parser
{
	int					fd;
	unsigned			row;
	unsigned			column;
	t_token				*list;
	int32_t				pos;
	int32_t				op_pos;
	char				*name;
	char				*comment;
	char				*code;
	int32_t				code_size;
	t_label				*labels;
}						t_parser;


int						main(int argc, char **argv);
void					parsing(char *line, t_file *ssl);
t_file					*init_struct(void);
t_exec					*init_exec(void);
void					check_name(int text, char *line, t_file *ssl);
void					check_comment(int text, char *line, t_file *ssl);
t_exec 					*check_exec(char *line, t_file *ssl);
char					*strncpy_dog(char *dst, const char *src, size_t len);
void					compare(t_file *ssl, char *line, int j, t_exec *com);
void 					compare_2(t_file *ssl, char *line, int j);
void					live(t_file *ssl, char *line, t_exec *com);
t_exec					*skip_box(t_exec *ssl);
void					including_magic(int text);
void					write_error(char *str);
t_parser				*zero_struct(int fd);
void					recognize_1(t_parser *su);
void					skip_probel(t_file *ssl, const char *line);
int						is_whitespace(int c);
void					no_comment(t_file *ssl, const char *li);
void					razborka(t_parser *su, char **line);
t_token					*cne(t_parser *su, t_type type);
void					add_list(t_token **list, t_token *new);
void					choos_a(t_parser *su, char *line, unsigned start,
						t_token *list);
char					*data_to_list(t_parser *su, const char *line,
						unsigned start);
int						is_limit(int c);
void					choos_dig(t_parser *su, char *line, unsigned start, t_token *list);
void					error_lex(t_parser *su);
void					choos_str(t_parser *su, char **line, unsigned start, t_token *list);
char					*connecting_people(char **s1, char **s2);
void					move_posa(t_parser *su, const char *line);
void					refresh_line(char **line, char *ptr);
int						is_registr(const char *a);
void					take_label(char *line, t_file *ssl, t_label **list, t_exec *com);
t_label					*cnl(char *name, int byte_c);
void					add_label(t_label **list, t_label *new);
t_label					*zero_label();

#endif

