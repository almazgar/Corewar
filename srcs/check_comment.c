/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_comment.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgarse <lgarse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/03 12:52:44 by almazg            #+#    #+#             */
/*   Updated: 2020/04/03 13:12:43 by almazg           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

void	check_comment(int text, char *line, t_file *ssl)
{
	int j;

	j = 0;
	ft_bzero(ssl->comment, COMMENT_LENGTH);
	while (line[ssl->a] != '.')
		(ssl->a)++;
	ft_strncpy(ssl->comment, &line[ssl->a], 8);
	ft_putstr(ssl->comment);
	ft_putstr("___");
	if (line[ssl->a] == '.' && ft_strcmp(ssl->comment, ".comment") == 0)
	{
		ssl->a += 6;
		while (line[ssl->a] && line[ssl->a] != '"')
			ssl->a++;
	}
	else
		write_error("DOESN'T HAVE COMMENT1\n");
	(ssl->a)++;
	while (line[ssl->a] && line[ssl->a] != '"')
	{
		(ssl->a)++;
		j++;
		if (j > COMMENT_LENGTH)
			write_error("VERY LONG COMMENT\n");
	}
	strncpy_dog(ssl->comment, &line[ssl->a - j], j);
	write(text, ssl->comment, COMMENT_LENGTH);
	ft_putendl(ssl->comment);
}
