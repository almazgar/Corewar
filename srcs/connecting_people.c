/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   connecting_people.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgarse <lgarse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/24 14:38:12 by almazg            #+#    #+#             */
/*   Updated: 2020/04/17 12:08:05 by almazg           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

t_exec			*connecting_people(char *line, t_file *ssl)
{
	t_exec		*com;
	t_exec		*t;
	t_label		*list;

	com = init_exec();
	list = NULL;
	while ((get_next_line(ssl->fd, &line)) > 0)
	{
		ssl->a = 0;
		while (line[ssl->a])
		{
			skip_probel(ssl, line);
			no_comment(ssl, line);
			if (line[ssl->a])
				take_label(line, ssl, &list, com);
		}
		ft_strdel(&line);
		com->line_byte = com->line_byte + com->n_bytes;
	}
	t = com;
	com = com->next;
	ft_memdel((void**)&t);
	c_data(ssl, com, list);
	return (com);
}
