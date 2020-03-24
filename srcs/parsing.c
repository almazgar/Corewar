/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avenonat <avenonat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 14:35:28 by avenonat          #+#    #+#             */
/*   Updated: 2020/03/14 22:57:16 by avenonat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

void	parsing(char *line, t_file *ssl)
{
//	int		i;
	int		text;
//	t_file	*buffer;
	t_exec	*head;

//	i = 0;
//	head = NULL;
	if ((text = open(ssl->f_name, O_CREAT | O_TRUNC | O_WRONLY, 0644)) == -1)
		write_error("FILE DOESN'T CREAT");
	including_magic(text);
	check_name(text, line, ssl);
	write(text, ssl->zero, T_IND);
	write(text, ssl->zero, T_IND);
//	size_exec();
	check_comment(text, line, ssl);
//	write(text, ssl->zero, T_IND);
	head = check_exec(line, ssl);
	write(text, head->inst, 1);
	write(text, head->ted, 1);
//	while (line[i] != '\0')
//	{
//		buffer = init_struct();
//		if (ssl != NULL)
//		{
//			buffer = skip_box(ssl);
//			buffer->next = head;
//		}
//		else
//			ssl = head;
//		i++;
//	}
	close(text);
}