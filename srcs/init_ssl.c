/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_ssl.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgarse <lgarse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/02 10:16:36 by almazg            #+#    #+#             */
/*   Updated: 2020/04/02 10:16:36 by almazg           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

t_file		*init_ssl(void)
{
	t_file *temp;

	temp = (t_file *)malloc(sizeof(t_file));
	*temp->name = 0;
	*temp->comment = 0;
	temp->a = 0;
	*temp->zero = 0;
	temp->fd = 0;
	temp->line_byte = 0;
	return (temp);
}