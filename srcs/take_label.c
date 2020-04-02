/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   take_label.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgarse <lgarse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/27 09:52:44 by almazg            #+#    #+#             */
/*   Updated: 2020/04/02 12:07:32 by almazg           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

void	take_label(char *line, t_file *ssl, t_label **list, t_exec *co)
{
	int i;
	char *name;
	t_exec *com;

	com = NULL;
// каждая новая строка начинается с метки и если ее нет, то с оператора
// Поэтому мы вначале проверяем это метка ? а потом это оператор?
// если не метка и не оператор то ошибка  - пока это отключено в последней строке
// если оператор то вызываем программу для нахождения типа и имени оператора
// в зависимости от оператора мы распознаем первый аргумент, его тип
// если у оператора есть другие аргументы (2 и/или 3) то мы их тоже распознаем
// если есть в строке лишние аргументы то ошибка или просто игноририм?
// после того как распознали строку считаем ее длину и пишем структуру
// добавляем счетчик байтов на метку
// текущий счетчик + длина строоки  -> записываем значение начало следущей строки

	i = 0;
	while (line[ssl->a + i] && ft_strchr(LABEL_CHARS, line[ssl->a + i]))
		i++;
	if ((i) && line[ssl->a + i] == ':')  // Это метка + надо записать в структуру
	{
		// запись имени метки и байт от начала в лист меток и дубликат
		if (!(name = ft_strsub(line, ssl->a, i)))
			write_error("ERROR_STR_LABEL");
		add_label(list, cnl(name, ssl->line_byte));
		ssl->a = ssl->a + i + 1;
		ft_putstr("label_name is ");
		ft_putendl(name);
		ft_putnbr(ssl->line_byte);
		write(1, "\n",1);
	}
	else if ((i) && is_limit(line[ssl->a + i]))  // Это команда + надо записать в структуру
	{
		if (!(name = ft_strsub(line, ssl->a, i)))
			write_error("ERROR_STR_OPERATOR");
		ssl->a = ssl->a + i;
		if (!(is_registr(name)) && 1 < i && i < 6) // это не регистр ?
			// вызов распознавания команды (оператора) i - длина команды от 2 до 5 символов
		{
			com = init_exec();
			com->line_byte = ssl->line_byte;
			compare(ssl, line, i, com);
			ssl->line_byte = ssl->line_byte + com->n_bytes;
		}
		else
			write_error("WRONG_OPERATOR");
		add_comand(co, com);
	}
//	else   // это ошибка поскольку не метка и не команда
//		write_error("WRONG_STRING");
}