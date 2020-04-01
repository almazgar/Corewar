/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inst_and.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almazg <almazg@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/01 16:28:59 by almazg            #+#    #+#             */
/*   Updated: 2020/04/01 16:42:46 by almazg           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

void	and(t_file *ssl, char *line, t_exec *com)
{
	take_arg1(line, ssl, com);
	no_separator(ssl, line);
	take_arg2(line, ssl, com);
	no_separator(ssl, line);
	take_arg3(line, ssl, com);
	if (com->ta3 != 1)
		write_error("ERROR_TYPE_ARGUMENT_AND_COMMAND");
	com->inst = 6;
	com->n_bytes = 11;
	if (com->ta1 == 1)
		com->n_bytes = com->n_bytes - 3;
	if (com->ta2 == 1)
		com->n_bytes = com->n_bytes - 3;
	if (com->ta1 == 4 || com->ta1 == 5)
		com->n_bytes = com->n_bytes - 2;
	if (com->ta2 == 4 || com->ta1 == 5)
		com->n_bytes = com->n_bytes - 2;

//	ft_putstr("  ARG1 is ");
//	ft_putendl(com->a1);
//	ft_putstr("type arg1 is ");
//	ft_putnbr(com->ta1);
//	ft_putendl("  _______ ");
//
//	ft_putendl("__________Next argument 2 ");
//	ft_putstr("  ARG2 is ");
//	ft_putendl(com->a2);
//	ft_putstr("type arg2 is ");
//	ft_putnbr(com->ta2);
//	ft_putendl("  _______ ");
//
//	ft_putendl("__________Next argument 3 ");
//	ft_putstr("  ARG3 is ");
//	ft_putendl(com->a3);
//	ft_putstr("type arg3 is ");
//	ft_putnbr(com->ta3);
//	ft_putendl("  _______ ");
//

	while (line[ssl->a] && is_whitespace(line[ssl->a]))
		ssl->a = ssl->a + 1;
	if (line[ssl->a] == '#' || line[ssl->a] == ';')
		while (line[ssl->a] && line[ssl->a] != '\n')
			ssl->a = ssl-> a + 1;
	else if (line[ssl->a] != '\n' && line[ssl->a] != '\0')
		write_error("ALLOW_ONLY_THREE_ARGUMENT_TO_AND");
	write_error("FINISH");  // Это для проверки окончания команды
}
