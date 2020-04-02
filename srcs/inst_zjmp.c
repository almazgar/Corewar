/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inst_zjmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgarse <algarse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/01 14:40:32 by almazg            #+#    #+#             *//*   Updated: 2020/04/01 15:09:09 by almazg           ###   ########.fr       */

/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

void	zjmp(t_file *ssl, char *line, t_exec *com)
{
	take_arg1(line, ssl, com);
	if (com->ta1 != 2 && com->ta1 != 3)
		write_error("ERROR_ARGUMENT_ZJMP_COMMAND");
	com->n_bytes = 3;
	com->inst = 9	;
	while (line[ssl->a] && is_whitespace(line[ssl->a]))
		ssl->a = ssl->a + 1;
	if (line[ssl->a] == '#' || line[ssl->a] == ';')
		while (line[ssl->a] && line[ssl->a] != '\n')
			ssl->a = ssl-> a + 1;
	else if (line[ssl->a] != '\n' && line[ssl->a] != '\0')
		write_error("ALLOW_ONLY_ONE_ARGUMENT_TO_ZJMP");
	ft_putnbr(ssl->line_byte);
	ft_putendl("____finish zjmp___");
}