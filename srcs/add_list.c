/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_list.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgarse <lgarse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/24 12:26:33 by almazg            #+#    #+#             */
/*   Updated: 2020/03/24 12:26:33 by almazg           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

void	add_list(t_label **list, t_label *new)
{
	t_label	*current;

	if (list)
	{
		if (*list)
		{
			current = *list;
			while (current->next)
				current = current->next;
			current->next = new;
		}
		else
			*list = new;
	}
}
