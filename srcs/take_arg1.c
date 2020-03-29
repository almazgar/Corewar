/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   take_arg1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgarse <lgarse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/29 19:06:48 by almazg            #+#    #+#             */
/*   Updated: 2020/03/29 19:07:11 by almazg           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

void	take_arg1(char *line, t_file *ssl, t_exec *com)
{
	int i;

	i = 0;
	skip_probel(ssl, line);

//		4 -непрямой T_IND с указанием на число (5). Начинается сразу с числа
// если отрицательное число
	if (line[ssl->a] == '-')
	{
		i++;
		while (ft_isdigit(line[ssl->a + i]))
			i++;
		if ((i) && is_limit(line[ssl->a + i]))
		{
			if (!(com->a1 = ft_strsub(line, ssl->a, i)))
				write_error("ERROR_ARGUMENT_INIT");
			com->ta1 = 4;
		}
		else
			write_error("WRONG_NUMBER_ARGUMENT");
	}
//	если положительное число
	if (ft_isdigit(line[ssl->a]) && ++i)
	{
		while (ft_isdigit(line[ssl->a + i]))
			i++;
		if ((i) && is_limit(line[ssl->a + i]))
		{
			if (!(com->a1 = ft_strsub(line, ssl->a, i)))
				write_error("ERROR_ARGUMENT_INIT");
			com->ta1 = 4;
		}
		else
			write_error("WRONG_NUMBER_ARGUMENT");
	}

//		1 - регистр T_REG.  Вида R1-R16 тип аргумента - регистр
	else if (line[ssl->a] == 'r')
	{
		i = 1;
		while (ft_isdigit(line[ssl->a + i]))
			i++;
		if (1 < i && i < 4)
		{
			com->ta1 = 1;
			if (!(com->a1 = ft_strsub(line, ssl->a + 1, i - 1)))
				write_error("ERROR_ARGUMENT_INIT");
		}
		else
			write_error("WRONG_NUMBER_REGISTR");
	}
//		5 - непрямой T_IND с указанием на метку (:label). Начинается сразу с метки
	else if (line[ssl->a] == ':')
	{
		while (line[ssl->a + i] && ft_strchr(LABEL_CHARS, line[ssl->a + i]))
			i++;
		if ((i) && is_limit(line[ssl->a + i]))
		{
			if (!(com->a1 = ft_strsub(line, ssl->a + 1, i - 1)))
				write_error("ERROR_ARGUMENT_INIT");
			com->ta1 = 5;
		}
	}
	else if (line[ssl->a] == '%')
	{
		i = 2;
//		3 - прямой T_DIR  с указание на метку (%:label). После этого следует знак разделения
		if (line[ssl->a + 1] == ':')
		{
			while (line[ssl->a + i] && ft_strchr(LABEL_CHARS, line[ssl->a + i]))
				i++;
			if ((i > 2) && is_limit(line[ssl->a + i]))
			{
				if (!(com->a1 = ft_strsub(line, ssl->a + 2, i - 2)))
					write_error("ERROR_ARGUMENT_INIT");
				com->ta1 = 3;
			}
			else
				write_error("WRONG_LABEL_ARGUMENT");
		}
//		2 - прямой T_DIR  с указание на число (%5) . Начинается с % потом следует число
		// если отрицательное число
		else if (line[ssl->a] == '-')
		{
			i++;
			while (ft_isdigit(line[ssl->a + i]))
				i++;
			if ((i) && is_limit(line[ssl->a + i]))
			{
				if (!(com->a1 = ft_strsub(line, ssl->a, i)))
					write_error("ERROR_ARGUMENT_INIT");
				com->ta1 = 2;
			}
			else
				write_error("WRONG_NUMBER_ARGUMENT");
		}
		//	если положительное число
		if (ft_isdigit(line[ssl->a]) && ++i)
		{
			while (ft_isdigit(line[ssl->a + i]))
				i++;
			if ((i) && is_limit(line[ssl->a + i]))
			{
				if (!(com->a1 = ft_strsub(line, ssl->a, i)))
					write_error("ERROR_ARGUMENT_INIT");
				com->ta1 = 4;
			}
			else
				write_error("WRONG_NUMBER_ARGUMENT");
		}
	else
		write_error("WRONG_NUMBER_ARGUMENT");
	}
}
