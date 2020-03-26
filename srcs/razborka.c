/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   razborka.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgarse <lgarse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/24 11:58:20 by almazg            #+#    #+#             */
/*   Updated: 2020/03/24 14:13:10 by almazg           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

void	razborka(t_parser *su, char **line)
{
	if (*(*line + su->column) == ',' && ++su->column)
		add_list(&su->list, cne(su, SEPARATOR));
	else if (*(*line + su->column) == '\n' && ++su->column)
		add_list(&su->list, cne(su, NEW_LINE));
	else if (*(*line + su->column) == '.')
		choos_a(su, *line, su->column++, cne(su, COMMAND));
	else if (*(*line + su->column) == '%' && ++su->column)
	{
		if (*(*line + su->column) == ':' && ++su->column)
			choos_a(su, *line, su->column - 2, cne(su, DIRECT_LABEL));
		else
			choos_dig(su, *line, su->column - 1, cne(su, DIRECT));
	}
	else if (*(*line + su->column) == '\"')
		choos_str(su, line, su->column, cne(su, STRING));
	else if (*(*line + su->column) == ':')
		choos_a(su, *line, su->column++, cne(su, INDIRECT_LABEL));
	else
		choos_dig(su, *line, su->column, cne(su, INDIRECT));
}