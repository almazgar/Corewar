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

void	add_list(t_token **list, t_token *new)
{
	t_token	*current;

	if (list)
	{
		if (*list)
		{
			current = *list;
			while (current->next)
				current = current->next;
			if (current->type == NEW_LINE && new->type == NEW_LINE)
				ft_memdel((void **)&new);
			else
				current->next = new;
		}
		else
		{
			if (new->type == NEW_LINE)
				ft_memdel((void **)&new);
			else
				*list = new;
		}
	}
}
