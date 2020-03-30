/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recognize_1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgarse <lgarse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/24 10:52:22 by almazg            #+#    #+#             */
/*   Updated: 2020/03/27 14:42:41 by almazg           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

//void	recognize_1(t_parser *su)
//{
//	ssize_t	size;
//	char	*line;
//
//	while (++su->row && !(su->column = 0)
//		&& (size = get_next_line(su->fd, &line)) > 0)
//	{
//		while (line[su->column])
//		{
//			skip_probel(su, line);
//			no_comment(su, line);
//			if (line[su->column])
//				razborka(su, &line);
//		}
//		ft_strdel(&line);
//	}
//	if (size == -1)
//		ft_putstr("ERR_READ_FILE");
//	add_list(&(su->list), cne(su, END));
//}