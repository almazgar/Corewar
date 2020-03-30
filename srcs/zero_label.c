/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zero_label.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgarse <lgarse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/28 10:22:58 by almazg            #+#    #+#             */
/*   Updated: 2020/03/28 10:22:58 by almazg           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

t_label	*zero_label()
{
	t_label	*temp;

	if (!(temp = (t_label *)ft_memalloc(sizeof(t_label))))
		write_error("ERROR_LABEL_INIT");
	temp->name = NULL;
	temp->op_pos = 0;
	temp->mentions = NULL;
	temp->next = NULL;
	return (temp);
}