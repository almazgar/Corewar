/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   choos_dig.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgarse <lgarse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/24 14:05:56 by almazg            #+#    #+#             */
/*   Updated: 2020/03/24 14:22:10 by almazg           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

void	choos_dig(t_parser *su, char *line, unsigned start, t_token *list)
{
	unsigned column;

	list->column = start;
	if (line[su->column] == '-')
		su->column++;
	column = su->column;
	while (ft_isdigit(line[su->column]))
		su->column++;
	if ((su->column - column)
		&& (list->type == DIRECT || is_limit(line[su->column])))
	{
		list->content = data_to_list(su, line, start);
		add_list(&su->list, list);
	}
	else if (list->type != DIRECT)
	{
		su->column = start;
		choos_a(su, line, start, list);
	}
	else
		error_lex(su);
}
