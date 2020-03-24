/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recognize_1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgarse <lgarse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/24 10:52:22 by almazg            #+#    #+#             */
/*   Updated: 2020/03/24 14:30:22 by almazg           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

void	recognize_1(t_parser *stru)
{
	ssize_t	size;
	char	*line;

	while (++stru->row
		&& !(stru->column = 0)
		&& (size = get_next_line(stru->fd, &line)) > 0)
	{
		while (line[stru->column])
		{
			skip_probel(stru, line);
			no_comment(stru, line);
			if (line[stru->column])
				razborka(stru, &line);
		}
		ft_strdel(&line);
	}
	if (size == -1)
		ft_putstr("ERR_READ_FILE");
	add_list(&(stru->tokens), cne(stru, END));
}