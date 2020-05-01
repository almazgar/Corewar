/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   order_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almazg <almazg@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/17 17:43:35 by almazg            #+#    #+#             */
/*   Updated: 2020/04/18 10:06:32 by almazg           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

int	order_arg(t_exec *com, char **a, int ta, int n)
{
	if (n == 1)
	{
		*a = com->a1;
		ta = com->ta1;
	}
	else if (n == 2)
	{
		*a = com->a2;
		ta = com->ta2;
	}
	else
	{
		*a = com->a3;
		ta = com->ta3;
	}
	return (ta);
}
