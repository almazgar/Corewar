/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_exec.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avenonat <avenonat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/12 16:44:30 by avenonat          #+#    #+#             */
/*   Updated: 2020/04/02 10:23:27 by almazg           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

t_exec		*init_exec()
{
	t_exec *temp;

	temp = (t_exec *)malloc(sizeof(t_exec));
	temp->label = NULL;
	temp->code_type = 0;
	temp->inst = 0;
	temp->reg = NULL;
	temp->sym = 0;
	temp->direct_label = NULL;
	temp->sym1 = 0;
	temp->number = 0;
	temp->direct = 0;
	temp->line_byte = 0;
	temp->n_bytes = 0;
	temp->a1 = NULL;
	temp->ta1 = 0;
	temp->a2 = NULL;
	temp->ta2 = 0;
	temp->a3 = NULL;
	temp->ta3 = 0;
	temp->next = NULL;

	return (temp);
}
