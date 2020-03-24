/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_exec.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avenonat <avenonat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/11 22:35:25 by avenonat          #+#    #+#             */
/*   Updated: 2020/03/14 22:10:52 by avenonat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

t_exec 	*check_exec(char *line, t_file *ssl)
{
	int			j;
	t_exec		*com;
//	t_exec		*temp;

	j = 0;
	(ssl->a)++;
//	while(line[ssl->a] != '\0')
	com = init_exec();
	while (line[ssl->a] == '\t' || line[ssl->a] == ' ' || line[ssl->a] == '\n')
		(ssl->a)++;
	printf("%c", line[ssl->a]);
	while (line[ssl->a] != ' ' && line[ssl->a] != '\t')
	{
		if (line[ssl->a] == ':')
		{
			ft_strncpy(com->label, &line[ssl->a - j], j);
			(ssl->a)++;
			while (line[ssl->a] == '\t' || line[ssl->a] == ' ' || line[ssl->a] == '\n')
				ssl->a++;
			j = 0;
		}
		(ssl->a)++;
		j++;
	}
	printf("%c", line[ssl->a]);
	compare(ssl, line, j, com);
	return (com);
}