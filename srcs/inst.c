/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inst.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avenonat <avenonat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/13 13:52:13 by avenonat          #+#    #+#             */
/*   Updated: 2020/04/01 10:07:52 by almazg           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

void	live(t_file *ssl, char *line, t_exec *com)
{
	int j;

	j = 0;
	take_arg1(line, ssl, com);

	ft_putstr("  ARG1 is ");
	ft_putendl(com->a1);
	ft_putstr("type arg1 is ");
	ft_putnbr(com->ta1);
	ft_putendl("  _______ ");

	if (com->ta1 != 2 && com->ta1 != 3)
		write_error("ERROR_ARGUMENT_LIVE_COMMAND");
	com->n_bytes = 5;
	com->inst = 1;
	while (line[ssl->a] && is_whitespace(line[ssl->a]))
		ssl->a = ssl->a + 1;
	if (line[ssl->a] == '#' || line[ssl->a] == ';')
		while (line[ssl->a] && line[ssl->a] != '\n')
			ssl->a = ssl-> a + 1;
	else if (line[ssl->a] != '\n' && line[ssl->a] != '\0')
		write_error("ALLOW_ONLY_ONE_ARGUMENT_TO_LIVE");
	write_error("FINISH");  // Это для проверки окончания команды

//	ft_putchar(line[ssl->a]);
//	ft_putendl("  ______ ");
//	no_separator(ssl, line);
//	ft_putchar(line[ssl->a]);
//	ft_putendl("  ______ ");

//	ft_putendl("__________Next argument 2 ");
//	take_arg1(line, ssl, com);
//	ft_putstr("  ARG2 is ");
//	ft_putendl(com->a1);
//	ft_putstr("type arg2 is ");
//	ft_putnbr(com->ta1);
//	ft_putendl("  _______ ");
//
//	no_separator(ssl, line);
//
//	ft_putendl("__________Next argument 3 ");
//	take_arg1(line, ssl, com);
//	ft_putstr("  ARG3 is ");
//	ft_putendl(com->a1);
//	ft_putstr("type arg3 is ");
//	ft_putnbr(com->ta1);
//	ft_putendl("  _______ ");
//	no_separator(ssl, line);


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
//		printf("%s\n", &line[ssl->a]);
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
//	int j;
//
//	j = 0;
	com->inst = 2;
	com->n_bytes = 7;

	take_arg1(line, ssl, com);



	if (com->ta1 < 2 || com->ta1 > 5)
		write_error("ERROR_TYPE_ARGUMENT_LD_COMMAND");

	no_separator(ssl, line);

	take_arg2(line, ssl, com);

	ft_putstr("  ARG1 is ");
	ft_putendl(com->a1);
	ft_putstr("type arg1 is ");
	ft_putnbr(com->ta1);
	ft_putendl("  _______ ");
	ft_putstr("  ARG2 is ");
	ft_putendl(com->a2);
	ft_putstr("type arg2 is ");
	ft_putnbr(com->ta2);
	ft_putendl("  _______ ");

	if (com->ta2 != 1)
		write_error("ERROR_TYPE_ARGUMENT_LD_COMMAND");

	com->n_bytes = 5;
	com->inst = 1;
	while (line[ssl->a] && is_whitespace(line[ssl->a]))
		ssl->a = ssl->a + 1;
	if (line[ssl->a] == '#' || line[ssl->a] == ';')
		while (line[ssl->a] && line[ssl->a] != '\n')
			ssl->a = ssl-> a + 1;
	else if (line[ssl->a] != '\n' && line[ssl->a] != '\0')
		write_error("ALLOW_ONLY_TWO_ARGUMENT_TO_LD");
	write_error("FINISH");  // Это для проверки окончания команды
}
//	while (line[ssl->a] == ' ' || line[ssl->a] == '\t')
//		(ssl->a)++;
//	if (line[ssl->a] == '%')
//	{
//		com->code_type = decimal("10010000");
//		(ssl->a)++;
//	}
//	else
//		com->code_type = decimal("11010000");
//	if (line[ssl->a] == ':')
//	{
//		while (line[ssl->a] == ',')
//		{
//			(ssl->a)++;
//			j++;
//		}
//		ft_strncpy(com->direct_label, &line[ssl->a - j], j);
//	}
//	else if (line[ssl->a] >= 48 && line[ssl->a] <= 57)
//	{
//		while (line[ssl->a] != ',')
//		{
//			if (line[ssl->a] >= 48 && line[ssl->a] <= 57)
//			{
//				(ssl->a)++;
//				j++;
//			}
//			else
//				write_error("UNCORRECTED ARGUMENT");
//		}
//		com->direct = ft_atoin(&line[ssl->a - j], j);
//	}
//	else
//		write_error("UNCORRECTED ARGUMENT");
//	while (line[ssl->a] != 'r')
//		(ssl->a)++;
//	(ssl->a)++;
//	j = 0;
//	while (line[ssl->a] >= 48 && line[ssl->a] <= 57)
//	{
//		printf("%s\n", &line[ssl->a]);
//		(ssl->a)++;
//		j++;
//	}
//	ft_strncpy(com->reg, &line[ssl->a - j], j);
//	printf("%s", com->reg);
//	ft_strncpy(com->ted, &line[ssl->a], 1);
//	ft_strncpy(com->ted, &line[ssl->a], 1);
//	printf("%s\n", com->ted);
//}







//void	live(t_file *ssl, char *line, t_exec *com)
//{
//	int j;
//
//	j = 0;
//	take_arg1(line, ssl, com);
//	ft_putstr("LINE");
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
//}

//void	ld()
//{
//
//}