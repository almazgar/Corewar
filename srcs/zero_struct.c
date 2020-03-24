/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zero_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgarse <lgarse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/24 10:19:42 by almazg            #+#    #+#             */
/*   Updated: 2020/03/24 10:42:53 by almazg           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

t_parser	*zero_struct(int fd)
{
	t_parser	*stru;

	if (!(stru = (t_parser *)ft_memalloc(sizeof(t_parser))))
		ft_putstr("ERR_PARSER_INIT");
	stru->fd = fd;
	stru->row = 0;
	stru->column = 0;
	stru->pos = 0;
	stru->op_pos = 0;
	stru->name = NULL;
	stru->comment = NULL;
	stru->code = NULL;
	stru->code_size = 0;
	stru->labels = NULL;
	return (stru);
}
