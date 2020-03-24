/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cne.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgarse <lgarse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/24 12:21:36 by almazg            #+#    #+#             */
/*   Updated: 2020/03/24 12:21:36 by almazg           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

t_token		*cne(t_parser *su, t_type type)
{
	t_token	*cell;

	if (!(cell = (t_token *)ft_memalloc(sizeof(t_token))))
		ft_putstr("ERR_TOKEN_INIT");
	cell->content = NULL;
	cell->type = type;
	cell->row = su->row;
	if (type == SEPARATOR || type == NEW_LINE)
		cell->column = su->column - 1;
	else
		cell->column = su->column;
	cell->next = NULL;
	return (cell);
}
