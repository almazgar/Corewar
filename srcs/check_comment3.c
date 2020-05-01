/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_comment3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almazg <almazg@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/18 13:05:41 by almazg            #+#    #+#             */
/*   Updated: 2020/04/26 20:04:23 by almazg           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

int		check_comment3(char *line, t_file *ssl, int j, char *s)
{
	s[j++] = '\n';
	while (j < COMMENT_LENGTH && (get_next_line(ssl->fd, &line)) > 0)
	{
		ssl->a = 0;
		while (j < COMMENT_LENGTH && line[ssl->a] && line[ssl->a] != '"')
			s[j++] = line[(ssl->a)++];
		if (j >= COMMENT_LENGTH)
			write_error("VERY LONG COMMENT");
		if (line[ssl->a] == '"')
			break ;
		s[j++] = '\n';
		ft_strdel(&line);
	}
	if (j > COMMENT_LENGTH)
		write_error("VERY LONG COMMENT");
	if (line[ssl->a] != '"')
		write_error("ERROR NO FINISH COMMENT");
	return (j);
}
