/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   take_label2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almazg <almazg@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/18 14:56:15 by almazg            #+#    #+#             */
/*   Updated: 2020/04/18 15:00:10 by almazg           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

void		take_label2(char *line, t_file *ssl, int i, t_label **list)
{
	char	*name;

	if (!(name = ft_strsub(line, ssl->a, i)))
		write_error("ERROR_STR_LABEL");
	add_label(list, cnl(name, ssl->line_byte));
	ssl->a = ssl->a + i + 1;
}
