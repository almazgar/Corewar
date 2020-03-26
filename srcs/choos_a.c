/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   choos_a.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgarse <lgarse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/24 12:31:59 by almazg            #+#    #+#             */
/*   Updated: 2020/03/24 14:29:32 by almazg           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

void	choos_a(t_parser *su, char *line, unsigned start, t_token *list)
{
	unsigned column;

	list->column = start;
	column = su->column;
	while (line[su->column] && ft_strchr(LABEL_CHARS, line[su->column]))
		su->column++;
	if ((su->column - column) && line[su->column] == ':' && ++su->column)
	{
		list->content = data_to_list(su, line, start);
		list->type = LABEL;
		add_list(&su->list, list);
	}
	else if ((su->column - column) && is_limit(line[su->column]))
	{
		list->content = data_to_list(su, line, start);
		if (list->type == INDIRECT)
			list->type = (is_registr(list->content)) ? REGISTER : OPERATOR;
		add_list(&su->list, list);
	}
	else
		error_lex(su);
}