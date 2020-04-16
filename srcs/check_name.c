/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_name.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgarse <lgarse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/03 12:44:35 by almazg            #+#    #+#             */
/*   Updated: 2020/04/15 12:50:53 by almazg           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

void	check_name(char *line, t_file *ssl)
{
	int j;
	char *s;

	j = 0;
	s = ft_strnew(PROG_NAME_LENGTH);
//	ft_bzero(ssl->name, PROG_NAME_LENGTH);
//	while (line[ssl->a] && line[ssl->a] != '.')
//		(ssl->a)++;
//	ft_strncpy(ssl->name, &line[ssl->a], 5);
//	if (line[ssl->a] == '.' && ft_strcmp(ssl->name, ".name") == 0)
//	{
	ssl->a += 5;
	while (line[ssl->a] && is_whitespace(line[ssl->a]))
		(ssl->a)++;
	if (line[ssl->a] != '"')
	{
		while (line[ssl->a] != '"' && (get_next_line(ssl->fd, &line)) > 0)
		{
			ssl->a = 0;
			while (line[ssl->a] && is_whitespace(line[ssl->a]))
				(ssl->a)++;
			if (line[ssl->a] && line[ssl->a] != '"')
				write_error("ERROR NAME");
		}
		ft_strdel(&line);
	}
	(ssl->a)++;
	while (line[ssl->a] && line[ssl->a] != '"')
	{
		s[j++] = line[(ssl->a)++];
//		(ssl->a)++;
//		j++;
//		if (j > PROG_NAME_LENGTH)
//			write_error("VERY LONG NAME\n");
	}
	if (line[ssl->a] != '"')
	{
		s[j++] = '\n';
		while ((get_next_line(ssl->fd, &line)) > 0)
		{
			ssl->a = 0;
			while (line[ssl->a] && line[ssl->a] != '"')
			{
				s[j++] = line[(ssl->a)++];
//				j++;
//				(ssl->a)++;
			}
			if (line[ssl->a] == '"')
				break;
			s[j++] = '\n';
			ft_strdel(&line);
		}
	}
	if (line[ssl->a] != '"')
		write_error("ERROR NO FINISH NAME");
	if (j > PROG_NAME_LENGTH)
		write_error("VERY LONG NAME");
	ft_bzero(ssl->name, PROG_NAME_LENGTH);
	ft_strncpy(ssl->name, s, j);
	ssl->n = 1;
	ft_memdel((void **)&s);

}