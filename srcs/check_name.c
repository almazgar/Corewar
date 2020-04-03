/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_name.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgarse <lgarse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/03 12:44:35 by almazg            #+#    #+#             */
/*   Updated: 2020/04/03 13:12:43 by almazg           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

void	check_name(int text, char *line, t_file *ssl)
{
	int j;

	j = 0;
	ft_bzero(ssl->name, PROG_NAME_LENGTH);
	while (line[ssl->a] && line[ssl->a] != '.')
		(ssl->a)++;
	ft_strncpy(ssl->name, &line[ssl->a], 5);
	ft_putstr(ssl->name);
	ft_putstr("___");
	if (line[ssl->a] == '.' && ft_strcmp(ssl->name, ".name") == 0)
	{
		ssl->a += 4;
		while (line[ssl->a] && line[ssl->a] != '"')
			(ssl->a)++;
	}
	else
		write_error("CHAMPION DOESN'T HAVE NAME\n");
	(ssl->a)++;
	while (line[ssl->a] && line[ssl->a] != '"')
	{
		(ssl->a)++;
		j++;
		if (j > PROG_NAME_LENGTH)
			write_error("VERY LONG NAME\n");
	}
	ft_strncpy(ssl->name, &line[ssl->a - j], j);
	write(text, ssl->name, PROG_NAME_LENGTH);
	ft_putendl(ssl->name);
}