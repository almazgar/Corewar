/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inst.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avenonat <avenonat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/13 13:52:13 by avenonat          #+#    #+#             */
/*   Updated: 2020/03/15 22:29:15 by avenonat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

void	live(t_file *ssl, char *line, t_exec *com)
{
	int j;

	j = 0;
	com->inst[0] = 1;
	printf("%s", &line[ssl->a]);
	while (line[ssl->a] != '%')
		(ssl->a)++;
	(ssl->a)++;
	while (line[ssl->a] != '\n')
	{
		printf("%s", &line[ssl->a]);
		(ssl->a)++;
		j++;
	}
	ssl->a -= j;
	if (!(com->ted = (char *)malloc(sizeof(char) + j)))
		exit (0);
//	printf("%lld", ft_atoi(&line[ssl->a]));
	ft_strncpy(com->ted, &line[ssl->a], 1);
	ft_strncpy(com->ted, &line[ssl->a], 1);
	printf("%s\n", com->ted);
	com->number = T_REG + (T_DIR * 2);
	printf("%d", com->number);
}

//void	ld()
//{
//
//}