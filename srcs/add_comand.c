/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_comand.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgarse <lgarse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/02 10:50:11 by almazg            #+#    #+#             */
/*   Updated: 2020/04/02 12:22:49 by almazg           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

void	add_comand(t_exec *list, t_exec *new)
{
	t_exec	*current;

	if (list || new)
	{
		if (list)
		{
			current = list;
			while (current->next)
				current = current->next;
			current->next = new;
		}
		else
			list = new;
	}
}
