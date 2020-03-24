/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_posa.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgarse <lgarse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/24 14:41:57 by almazg            #+#    #+#             */
/*   Updated: 2020/03/24 14:42:16 by almazg           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

void	move_posa(t_parser *su, const char *line)
{
	unsigned i;

	i = ++(su->column);
	while (line[i] && line[i] != '\"')
	{
		if (line[i] == '\n')
		{
			su->row++;
			su->column = 0;
		}
		else
			su->column++;
		i++;
	}
}
