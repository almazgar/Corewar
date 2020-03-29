/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_exec.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avenonat <avenonat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/11 22:35:25 by avenonat          #+#    #+#             */
/*   Updated: 2020/03/29 13:51:32 by almazg           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

t_exec 	*check_exec(char *line, t_file *ssl)
{
	int			j;
	int 		read;
	t_exec		*com;
//	t_exec		*temp;
	t_label		*list;

	j = 0;
	list = NULL;
	(ssl->a)++;
//	while(line[ssl->a] != '\0')
	com = init_exec();
	while ((read = get_next_line(ssl->fd, &line)) > 0)
	{
		ssl->a = 0;
		while (line[ssl->a])
		{
			skip_probel(ssl, line);
			no_comment(ssl, line);
			if (line[ssl->a])
				take_label(line, ssl, &list, com);
			ssl->a++;
		}
		ft_strdel(&line);
	}

//
//	if (size == -1)
//		ft_putstr("ERR_READ_FILE");


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
//	ft_printf("%c", line[ssl->a]);
	compare(ssl, line, j, com);
	return (com);
}