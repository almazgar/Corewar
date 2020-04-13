/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   skolkovo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almazg <almazg@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/03 11:09:33 by almazg            #+#    #+#             */
/*   Updated: 2020/04/09 11:28:23 by almazg           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/asm.h"

void	skolkovo(char *line, t_file *ssl)
{
	int		text;
	t_exec	*head;

	if ((text = open(ssl->f_name, O_CREAT | O_TRUNC | O_WRONLY, 0644)) == -1)
		write_error("FILE DOESN'T CREAT");
	ssl->text = text;
	including_magic(text);
	while ((get_next_line(ssl->fd, &line)) > 0)
	{
		ssl->a = 0;
        while (line[ssl->a] && is_whitespace(line[ssl->a]))
            (ssl->a)++;
		if (line[ssl->a] && (line[ssl->a] == '#' || line[ssl->a] == ';'))
        {
            ft_strdel(&line);
            continue;
        }
		else if (line[ssl->a] && line[ssl->a] == '.')
        {
            check_name(line, ssl);
            write(ssl->text, ssl->zero, T_IND);
            ft_strdel(&line);
            break;
        }
	}
	while ((get_next_line(ssl->fd, &line)) > 0)
	{
		ssl->a = 0;
        while (line[ssl->a] && is_whitespace(line[ssl->a]))
            (ssl->a)++;
        if (line[ssl->a] && (line[ssl->a] == '#' || line[ssl->a] == ';'))
        {
            ft_strdel(&line);
            continue;
        }
        else if (line[ssl->a] && line[ssl->a] == '.')
        {
            check_comment(line, ssl);
            ft_strdel(&line);
            break;
        }
	}
	if (ft_strlen(ssl->comment) == 0)
        write_error("DOESN'T HAVE COMMENT2\n");
	head  = connecting_people(line, ssl);
	close(text);
	free_exec(head);
}