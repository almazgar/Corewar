/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   name_comment.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almazg <almazg@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/13 18:00:34 by almazg            #+#    #+#             */
/*   Updated: 2020/04/17 11:48:21 by almazg           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

void	name_comment(char *line, t_file *ssl)
{
	char	*n;
	char	*c;

	n = ft_strnew(5);
	c = ft_strnew(8);
	while (!(ssl->n && ssl->c) && (get_next_line(ssl->fd, &line)) > 0)
	{
		ssl->a = 0;
		choose_n_c(line, ssl, n, c);
		ft_strdel(&line);
	}
	ft_memdel((void**)&n);
	ft_memdel((void**)&c);
}
