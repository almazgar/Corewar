/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   skip_box.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msabre <msabre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 16:05:16 by avenonat          #+#    #+#             */
/*   Updated: 2020/03/13 20:40:42 by avenonat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

t_exec		*skip_box(t_exec *ssl)
{
	t_exec	*temp;

	temp = ssl;
//	while (temp->next != NULL)
//		temp = temp->next;
	return (temp);
}