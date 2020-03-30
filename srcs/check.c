/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avenonat <avenonat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 14:52:00 by avenonat          #+#    #+#             */
/*   Updated: 2020/03/11 00:08:17 by avenonat         ###   ########.fr       */
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
	printf("%s\n", ssl->comment);
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
}

void	check_name(int text, char *line, t_file *ssl)
{
	int j;

	j = 0;
	ft_bzero(ssl->name, PROG_NAME_LENGTH);
	while (line[ssl->a] != '.' && line[ssl->a])
		(ssl->a)++;
	ft_strncpy(ssl->name, &line[ssl->a], 5);
	ft_printf("%s\n", ssl->name);
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
//	name = (char *)malloc(sizeof (char) * (j));
	ft_strncpy(ssl->name, &line[ssl->a - j], j);
//	while (j-- > 0)
//	{
//		ssl->name[num] = name[num];
//		num++;
//	}
	write(text, ssl->name, PROG_NAME_LENGTH);
//	printf("%c", line[ssl->a]);
}
