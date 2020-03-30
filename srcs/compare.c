/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compare.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avenonat <avenonat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/12 00:00:01 by avenonat          #+#    #+#             */
/*   Updated: 2020/03/14 00:02:47 by avenonat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

void	compare(t_file *ssl, char *line, int j, t_exec *com)
{
	char		temp[0];
	printf("%d\n", j);
	ft_putstr(&line[ssl->a - j]);
	if (ft_strncmp(&line[ssl->a - j], "live", j) == 0)
		live(ssl, line, com);
//		*temp = 1;
	else if (ft_strncmp(&line[ssl->a - j], "ld", j) == 0)
		*temp = 2;
	else if (ft_strncmp(&line[ssl->a - j], "st", j) == 0)
		*temp = 3;
	else if (ft_strncmp(&line[ssl->a - j], "add", j) == 0)
		*temp = 4;
	else if (ft_strncmp(&line[ssl->a - j], "sub", j) == 0)
		*temp = 5;
	else if (ft_strncmp(&line[ssl->a - j], "and", j) == 0)
		*temp = 6;
	else if (ft_strncmp(&line[ssl->a - j], "or", j) == 0)
		*temp = 7;
	else if (ft_strncmp(&line[ssl->a - j], "xor", j) == 0)
		*temp = 8;
	else if (ft_strncmp(&line[ssl->a - j], "zjmp", j) == 0)
		*temp = 9;
	else
		compare_2(ssl, line, j);
}