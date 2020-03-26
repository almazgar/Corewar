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
	t_parser	*su;

	if (!(su = (t_parser *)ft_memalloc(sizeof(t_parser))))
		ft_putstr("ERR_PARSER_INIT");
	su->fd = fd;
	su->row = 0;
	su->column = 0;
	su->pos = 0;
	su->op_pos = 0;
	su->name = NULL;
	su->comment = NULL;
	su->code = NULL;
	su->code_size = 0;
	su->labels = NULL;
	return (su);
}
