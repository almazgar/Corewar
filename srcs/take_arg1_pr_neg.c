/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   take_arg1_pr_neg.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almazg <almazg@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/18 17:24:59 by almazg            #+#    #+#             */
/*   Updated: 2020/04/18 17:24:59 by almazg           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

void	take_arg1_pr_neg(char *line, t_file *ssl, t_exec *com, int i)
{
	i++;
	while (ft_isdigit(line[ssl->a + i]))
		i++;
	if ((i > 2) && is_limit(line[ssl->a + i]))
	{
		if (!(com->a1 = ft_strsub(line, ssl->a + 1, i - 1)))
			write_error("ERROR_ARGUMENT_INIT");
	}
	else
		write_error("WRONG_NUMBER_ARGUMENT");
	com->ta1 = 2;
	ssl->a = ssl->a + i;
}
