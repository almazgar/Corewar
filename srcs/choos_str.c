/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   choos_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgarse <lgarse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/24 14:22:54 by almazg            #+#    #+#             */
/*   Updated: 2020/03/24 14:49:21 by almazg           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

//void	choos_str(t_parser *su, char **line, unsigned start, t_token *list)
//{
//	char	*end;
//	ssize_t	size;
//	char	*str;
//
//	list->column = start;
//	size = 1;
//	while (!(end = ft_strchr(&((*line)[start + 1]), '\"'))
//		   && (size = get_next_line(su->fd, &str)) > 0)
//		*line = connecting_people(line, &str);
//	move_posa(su, *line);
//	if (size == -1)
//		ft_putstr("ERR_READ_FILE");
//	if (size == 0)
//		error_lex(su);
//	if (!(list->content = ft_strsub(*line, start, end + 1 - &((*line)[start]))))
//		ft_putstr("ERR_STR_INIT");
//	if (end - su->column != *line)
//		refresh_line(line, end - su->column);
//	su->column++;
//	add_list(&su->list, list);
//}
