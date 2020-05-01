/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   take_arg2_dv.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almazg <almazg@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/18 16:51:34 by almazg            #+#    #+#             */
/*   Updated: 2020/04/18 16:51:42 by almazg           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

void	take_arg2_dv(char *line, t_file *ssl, t_exec *com, int i)
{
	while (line[ssl->a + i] && ft_strchr(LABEL_CHARS, line[ssl->a + i]))
		i++;
	if ((i > 1) && is_limit(line[ssl->a + i]))
	{
		if (!(com->a2 = ft_strsub(line, ssl->a + 1, i - 1)))
			write_error("ERROR_ARGUMENT_INIT");
	}
	else
		write_error("WRONG_LABEL_NAME");
	com->ta2 = 5;
	ssl->a = ssl->a + i;
}
