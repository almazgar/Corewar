/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_exec.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avenonat <avenonat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/11 22:35:25 by avenonat          #+#    #+#             */
/*   Updated: 2020/04/02 13:28:08 by almazg           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

t_exec		*check_exec(char *line, t_file *ssl)
{
	int			j;
	t_exec		*com;
//	t_exec		*temp;
//	t_exec 		*buffer;
	t_label		*list;

	com = init_exec();
	j = 0;
	list = NULL;
//	(ssl->a)++;
	while ((get_next_line(ssl->fd, &line)) > 0)
	{
		ssl->a = 0;
//		skip_probel(ssl, line);
//		no_comment(ssl, line);

		while (line[ssl->a])
		{
			skip_probel(ssl, line);
			no_comment(ssl, line);
			if (line[ssl->a])
				take_label(line, ssl, &list, com);
		}
		ft_strdel(&line);
		com->line_byte = com->line_byte + com->n_bytes;
	}

//	while(line[ssl->a] != '\0')
//	{
//		j = 0;
//		if (!(temp = malloc(sizeof(t_exec))))
//			write_error("PROBLEM WITH MEMORY");
//		temp = init_exec();
//		while (line[ssl->a] == '\t' || line[ssl->a] == ' ' || line[ssl->a] == '\n')
//			(ssl->a)++;
//		printf("%c", line[ssl->a]);
//		while (line[ssl->a] != ' ' && line[ssl->a] != '\t')
//		{
//			if (line[ssl->a] == ':')
//			{
//				ft_strncpy(temp->label, &line[ssl->a - j], j);
//				(ssl->a)++;
//				while (line[ssl->a] == '\t' || line[ssl->a] == ' ' || line[ssl->a] == '\n')
//					(ssl->a)++;
//				j = 0;
//			}
//			(ssl->a)++;
//			j++;
//		}
//		printf("%c", line[ssl->a]);
//		compare(ssl, line, j, temp);
//		if (com != NULL)
//		{
//			buffer = skip_box(com);
//			buffer->next = temp;
//		}
//		else
//			com = temp;
//	}
//


//
//	com = init_exec();
//	while (line[ssl->a] == '\t' || line[ssl->a] == ' ' || line[ssl->a] == '\n')
//		(ssl->a)++;
//	printf("%c", line[ssl->a]);
//	while (line[ssl->a] != ' ' && line[ssl->a] != '\t')
//	{
//		if (line[ssl->a] == ':')
//		{
//			ft_strncpy(com->label, &line[ssl->a - j], j);
//			(ssl->a)++;
//			while (line[ssl->a] == '\t' || line[ssl->a] == ' ' || line[ssl->a] == '\n')
//				ssl->a++;
//			j = 0;
//		}
//		(ssl->a)++;
//		j++;
//	}
//	printf("%c", line[ssl->a]);

//	compare(ssl, line, j, com);
	return (com);
}