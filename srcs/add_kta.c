/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_kta.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgarse <lgarse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/04 13:23:11 by almazg            #+#    #+#             */
/*   Updated: 2020/04/08 16:07:37 by almazg           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

void		add_kta(t_exec **com, int i)
{
	char	*temp;
	t_exec	*c;
	int		j;

	c = *com;
	if (i == 1)
		j = c->ta1;
	else if (i == 2)
		j = c->ta2;
	else
		j = c->ta3;
	if (j == 1)
		temp = ft_strjoin(c->kta, "01");
	else if (j == 2)
		temp = ft_strjoin(c->kta, "10");
	else if (j == 4)
		temp = ft_strjoin(c->kta, "11");
	else
		temp = ft_strjoin(c->kta, "00");
	ft_strdel(&(c->kta));
	c->kta = temp;
}
