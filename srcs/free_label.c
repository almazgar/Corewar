/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_label.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgarse <lgarse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/04 19:16:48 by almazg            #+#    #+#             */
/*   Updated: 2020/04/04 20:20:20 by almazg           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

void	free_label(t_label *list)
{
	t_label	*t;

	while (list)
	{
		t = list;
		list = list->next;
		ft_memdel((void**)&(t->name));
		ft_memdel((void**)&t);
	}
}
