/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   take_arg2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgarse <lgarse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/01 10:03:44 by almazg            #+#    #+#             */
/*   Updated: 2020/04/14 17:17:56 by almazg           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

void	take_arg2(char *line, t_file *ssl, t_exec *com)
{
	int i;

	i = 0;
	skip_probel(ssl, line);
//	no_comment(ssl, line);

	//		1 - регистр T_REG.  Вида r1-r16 тип аргумента - регистр
	if (line[ssl->a] == 'r')
	{
		while (ft_isdigit(line[ssl->a + i + 1]))
			i++;
//		if (0 < i && i < 3 && ft_atoi(&line[ssl->a + 1]) > 0)
		if (0 < i && i < 3)
		{
			if (!(com->a2 = ft_strsub(line, ssl->a + 1, i)))
				write_error("ERROR_ARGUMENT_INIT");
		}
		else
			write_error("WRONG_NUMBER_REGISTR");
		com->ta2 = 1;
		ssl->a = ssl->a + i + 1;
	}

		//	прямой T_DIR
	else if (line[ssl->a] == '%' && line[ssl->a + 1] && line[ssl->a + 1] != ':')
	{
		i = 1;
		//		2 - прямой T_DIR  с указание на число (%5 или %-5) . Начинается с % потом следует число
		// если отрицательное число
		if (line[ssl->a + i] == '-')
		{
			i++;
			while (ft_isdigit(line[ssl->a + i]))
				i++;
			if ((i > 2) && is_limit(line[ssl->a + i]))
			{
				if (!(com->a2 = ft_strsub(line, ssl->a + 1, i - 1)))
					write_error("ERROR_ARGUMENT_INIT");
			}
			else
				write_error("WRONG_NUMBER_ARGUMENT");
			com->ta2 = 2;
			ssl->a = ssl->a + i;
		}
			//	если положительное число
		else if (ft_isdigit(line[ssl->a + i]) && ++i)
		{
			while (ft_isdigit(line[ssl->a + i]))
				i++;
			if ((i > 1) && is_limit(line[ssl->a + i]))
			{
				if (!(com->a2 = ft_strsub(line, ssl->a + 1, i - 1)))
					write_error("ERROR_ARGUMENT_INIT");
			}
			else
				write_error("WRONG_NUMBER_ARGUMENT");
			com->ta2 = 2;
			ssl->a = ssl->a + i;
		}
		else
			write_error("WRONG_NUMBER_ARGUMENT");
	}
		//		3 - прямой T_DIR  с указание на метку (%:label). После этого следует знак разделения
	else if (line[ssl->a + 1] && line[ssl->a + 1] == ':')
	{
		i = 2;
		while (line[ssl->a + i] && ft_strchr(LABEL_CHARS, line[ssl->a + i]))
			i++;
		if ((i > 2) && is_limit(line[ssl->a + i]))
		{
			if (!(com->a2 = ft_strsub(line, ssl->a + 2, i - 2)))
				write_error("ERROR_ARGUMENT_INIT");
		}
		else
			write_error("WRONG_LABEL_ARGUMENT");
		com->ta2 = 3;
		ssl->a = ssl->a + i;
	}
		//		4 - непрямой T_IND с указанием на число (5 или -5). Начинается сразу с числа
		//	если положительное число
	else if (ft_isdigit(line[ssl->a]) && ++i)
	{
		while (ft_isdigit(line[ssl->a + i]))
			i++;
		if (is_limit(line[ssl->a + i]))
		{
			if (!(com->a2 = ft_strsub(line, ssl->a, i)))
				write_error("ERROR_ARGUMENT_INIT");
		}
		else
			write_error("WRONG_NUMBER_ARGUMENT");
		com->ta2 = 4;
		ssl->a = ssl->a + i;
	}
		// если отрицательное число
	else if (line[ssl->a] == '-')
	{
		i++;
		while (ft_isdigit(line[ssl->a + i]))
			i++;
		if ((i > 1) && is_limit(line[ssl->a + i]))
		{
			if (!(com->a2 = ft_strsub(line, ssl->a, i)))
				write_error("ERROR_ARGUMENT_INIT");
		}

		else
			write_error("WRONG_NUMBER_ARGUMENT");
		com->ta2 = 4;
		ssl->a = ssl->a + i;
	}
//		5 - непрямой T_IND с указанием на метку (:label). Начинается сразу с метки
	else if (line[ssl->a] == ':')
	{
		i = 1;
		while (line[ssl->a + i] && ft_strchr(LABEL_CHARS, line[ssl->a + i]))
			i++;
		if ((i > 1) && is_limit(line[ssl->a + i]))
		{
			if (!(com->a2 = ft_strsub(line, ssl->a + 1, i - 1)))
				write_error("ERROR_ARGUMENT_INIT");
		}
		else
			write_error("WRONG_LABEL_NAME");
		com->ta2 = 5;
		ssl->a = ssl->a + i;
	}
	else
		write_error("WRONG_ARGUMENT");
}