/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_comment2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almazg <almazg@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/18 13:00:44 by almazg            #+#    #+#             */
/*   Updated: 2020/04/18 13:00:44 by almazg           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

void		check_comment2(char *line, t_file *ssl)
{
	while (line[ssl->a] != '"' && (get_next_line(ssl->fd, &line)) > 0)
	{
		ssl->a = 0;
		while (line[ssl->a] && is_whitespace(line[ssl->a]))
			(ssl->a)++;
		if (line[ssl->a] && line[ssl->a] != '"')
			write_error("ERROR COMMENT");
		ft_strdel(&line);
	}
}
