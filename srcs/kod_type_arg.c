/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   kod_type_arg.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgarse <lgarse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/04 11:46:05 by almazg            #+#    #+#             */
/*   Updated: 2020/04/04 13:40:39 by almazg           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

void	kod_type_arg(t_exec **com)
{
	char *temp;
	t_exec	*c;

	c = *com;
	temp = ft_strnew(1);
	c->kta = ft_strnew(1);
	add_kta(&c, 1);
	add_kta(&c, 2);
	add_kta(&c, 3);
	temp = ft_strjoin(c->kta, "00");
	ft_strdel(&(c->kta));
	c->kta = temp;
}