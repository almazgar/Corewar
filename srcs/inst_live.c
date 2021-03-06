/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inst_live.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgarse <lgarse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/01 14:34:54 by almazg            #+#    #+#             */
/*   Updated: 2020/04/21 11:52:42 by almazg           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

void	live(t_file *ssl, char *line, t_exec *com)
{
	take_arg1(line, ssl, com);
	if (com->ta1 != 2 && com->ta1 != 3)
		write_error("ERROR_ARGUMENT_LIVE_COMMAND");
	com->n_bytes = 5;
	com->inst = 1;
	com->dir_size = 4;
	while (line[ssl->a] && is_whitespace(line[ssl->a]))
		ssl->a = ssl->a + 1;
	if (line[ssl->a] == '#' || line[ssl->a] == ';')
		while (line[ssl->a] && line[ssl->a] != '\n')
			ssl->a = ssl->a + 1;
	else if (line[ssl->a] != '\n' && line[ssl->a] != '\0')
		write_error("ALLOW_ONLY_ONE_ARGUMENT_TO_LIVE");
}
