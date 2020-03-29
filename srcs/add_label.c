/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_label.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgarse <lgarse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/27 10:36:22 by almazg            #+#    #+#             */
/*   Updated: 2020/03/29 13:13:01 by almazg           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

void	add_label(t_label **list, t_label *new)
{
	t_label	*current;

	if (list || new)
	{
		if (*list)
		{
			current = *list;
			while (current->next)
			{
				if (ft_strequ(current->name, new->name))
					write_error("Double lable");
				current = current->next;
			}
			if (ft_strequ(current->name, new->name))
				write_error("Double lable");
			current->next = new;
		}
		else
			*list = new;
	}
}