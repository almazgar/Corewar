/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compare_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avenonat <avenonat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/12 15:24:32 by avenonat          #+#    #+#             */
/*   Updated: 2020/03/13 22:50:00 by avenonat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

void 	compare_2(t_file *ssl, char *line, int j)
{
	char temp[0];

	if (ft_strncmp(&line[ssl->a - j], "ldi", j) == 0)
		*temp = 10;
	else if (ft_strncmp(&line[ssl->a - j], "sti", j) == 0)
		*temp = 11;
	else if (ft_strncmp(&line[ssl->a - j], "fork", j) == 0)
		*temp = 12;
	else if (ft_strncmp(&line[ssl->a - j], "lld", j) == 0)
		*temp = 13;
	else if (ft_strncmp(&line[ssl->a - j], "lldi", j) == 0)
		*temp = 14;
	else if (ft_strncmp(&line[ssl->a - j], "lfork", j) == 0)
		*temp = 15;
	else if (ft_strncmp(&line[ssl->a - j], "aff", j) == 0)
		*temp = 16;
	else
		write_error("WRONG OPERATION");
}