/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_exec.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgarse <lgarse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/05 08:42:01 by almazg            #+#    #+#             */
/*   Updated: 2020/04/05 08:42:01 by almazg           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

void	free_exec(t_exec **com)
{
	t_exec *temp;
	t_exec	*t;

	while(*com)
	{
		t = *com;
		temp = t->next;
//		ft_strdel(&(t->kta));
		ft_strdel(&(t->a1));
		ft_strdel(&(t->a2));
		ft_strdel(&(t->a3));
		ft_memdel((void **)t);
		*com = temp;
		t = NULL;
	}
	com = NULL;
}
