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
	take_arg1(line, ssl, com);
	ft_putstr("LINE");


//
//	int j;
//
//	j = 0;
//	com->inst = 1;
//	printf("%s", &line[ssl->a]);
//	while (line[ssl->a] != '%')
//		(ssl->a)++;
//	(ssl->a)++;
//	while (line[ssl->a] != '\n')
//	{
////		printf("%s\n", &line[ssl->a]);
//		(ssl->a)++;
//		j++;
//	}
//	com->direct = ft_atoi(&line[ssl->a - j]);
//	printf("%d", com->direct);
//	com->n_bytes = 5;
//	printf("%d", com->n_bytes);
}

void	ld(t_file *ssl, char *line, t_exec *com)
{
	int j;

	j = 0;
	com->inst = 2;
	com->n_bytes = 7;
	while (line[ssl->a] == ' ' || line[ssl->a] == '\t')
		(ssl->a)++;
	if (line[ssl->a] == '%')
	{
		com->code_type = decimal("10010000");
		(ssl->a)++;
	}
	else
		com->code_type = decimal("11010000");
	if (line[ssl->a] == ':')
	{
		while (line[ssl->a] == ',')
		{
			(ssl->a)++;
			j++;
		}
		ft_strncpy(com->direct_label, &line[ssl->a - j], j);
	}
	else if (line[ssl->a] >= 48 && line[ssl->a] <= 57)
	{
		while (line[ssl->a] != ',')
		{
			if (line[ssl->a] >= 48 && line[ssl->a] <= 57)
			{
				(ssl->a)++;
				j++;
			}
			else
				write_error("UNCORRECTED ARGUMENT");
		}
		com->direct = ft_atoin(&line[ssl->a - j], j);
	}
	else
		write_error("UNCORRECTED ARGUMENT");
	while (line[ssl->a] != 'r')
		(ssl->a)++;
	(ssl->a)++;
	j = 0;
	while (line[ssl->a] >= 48 && line[ssl->a] <= 57)
	{
//		printf("%s\n", &line[ssl->a]);
		(ssl->a)++;
		j++;
	}
	ft_strncpy(com->reg, &line[ssl->a - j], j);
	printf("%s", com->reg);
//	ft_strncpy(com->ted, &line[ssl->a], 1);
//	ft_strncpy(com->ted, &line[ssl->a], 1);
//	printf("%s\n", com->ted);
}







void	live(t_file *ssl, char *line, t_exec *com)
{
	int j;

	j = 0;
	take_arg1(line, ssl, com);
	ft_putstr("LINE");
//	com->inst[0] = 1;
//	ft_putstr("operator_live_begin");
//	while (line[ssl->a] != '%')
//		(ssl->a)++;
//	(ssl->a)++;
//	while (line[ssl->a] != '\n')
//	{
//		printf("%s", &line[ssl->a]);
//		(ssl->a)++;
//		j++;
//	}
//	ssl->a -= j;
//	if (!(com->ted = (char *)malloc(sizeof(char) + j)))
//		exit (0);
//	printf("%lld", ft_atoi(&line[ssl->a]));
//	ft_strncpy(com->ted, &line[ssl->a], 1);
//	ft_strncpy(com->ted, &line[ssl->a], 1);
//	printf("%s\n", com->ted);
//	com->number = T_REG + (T_DIR * 2);
//	printf("%d", com->number);
}

//void	ld()
//{
//
//}