/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   no_comment.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgarse <lgarse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/24 11:33:18 by almazg            #+#    #+#             */
/*   Updated: 2020/03/24 11:33:52 by almazg           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

void	no_comment(t_parser *su, const char *li)
{
	if (li[su->column] == COMMENT_CHAR
		|| li[su->column] == ALT_COMMENT_CHAR)
		while (li[su->column] && li[su->column] != '\n')
			su->column++;
}
