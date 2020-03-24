/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avenonat <avenonat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/07 16:19:28 by avenonat          #+#    #+#             */
/*   Updated: 2020/03/12 16:44:28 by avenonat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

t_file		*init_struct(void)
{
	t_file *temp;

	temp = (t_file *)malloc(sizeof(t_file));
	temp->a = 0;
	*temp->zero = 0;
	return (temp);
}
