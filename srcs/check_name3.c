/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_name3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almazg <almazg@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/18 13:24:04 by almazg            #+#    #+#             */
/*   Updated: 2020/04/18 13:28:58 by almazg           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

int		check_name3(char *line, t_file *ssl, int j, char *s)
{
	s[j++] = '\n';
	while ((get_next_line(ssl->fd, &line)) > 0)
	{
		ssl->a = 0;
		while ((j < PROG_NAME_LENGTH) && line[ssl->a] && line[ssl->a] != '"')
			s[j++] = line[(ssl->a)++];
		if (j >= PROG_NAME_LENGTH)
			write_error("VERY LONG NAME");
		if (line[ssl->a] == '"')
			break ;
		s[j++] = '\n';
		ft_strdel(&line);
	}
	if (line[ssl->a] != '"')
		write_error("ERROR NO FINISH NAME");
	return (j);
}
