/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_registr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgarse <lgarse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/29 13:51:39 by almazg            #+#    #+#             */
/*   Updated: 2020/03/29 13:51:39 by almazg           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

t_label		*cnl(char *name, int byte_c)
{
	t_label	*temp;

	if (!(temp = (t_label *)ft_memalloc(sizeof(t_label))))
		write_error("ERROR_LABEL_INIT");
	temp->name = name;
	temp->op_pos = byte_c;
	temp->mentions = NULL;
	temp->next = NULL;
	return (temp);
}