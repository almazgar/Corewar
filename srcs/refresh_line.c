/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   refresh_line.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgarse <lgarse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/24 14:47:19 by almazg            #+#    #+#             */
/*   Updated: 2020/03/24 14:47:19 by almazg           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

void	refresh_line(char **line, char *ptr)
{
	char *new;

	if (!(new = ft_strdup(ptr)))
		ft_putstr("ERR_STR_INIT");
	ft_strdel(line);
	*line = new;
}
