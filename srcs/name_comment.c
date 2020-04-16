/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   name_comment.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almazg <almazg@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/13 18:00:34 by almazg            #+#    #+#             */
/*   Updated: 2020/04/14 17:17:56 by almazg           ###   ########.fr       */
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
		while (line[ssl->a])
		{
			skip_probel(ssl, line);
			no_comment(ssl, line);
//			ft_bzero(n, 6);
//			ft_bzero(c, 9);
			ft_strncpy(n, &line[ssl->a], 5);
			ft_strncpy(c, &line[ssl->a], 8);
			if (line[ssl->a])
			{
				if (ft_strcmp(n, ".name") == 0 && !ssl->n)
				{
					check_name(line, ssl);
					break;
				}

				else if (ft_strcmp(c, ".comment") == 0 && !ssl->c)
				{
					check_comment(line, ssl);
					break;
				}

				else
					write_error("COMMENT AND NAME ERROR");
			}
		}
		ft_strdel(&line);
	}
}