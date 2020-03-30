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

void	no_comment(t_file *ssl, const char *li)
{
	if (li[ssl->a] == COMMENT_CHAR || li[ssl->a] == ALT_COMMENT_CHAR)
		while (li[ssl->a] && li[ssl->a] != '\n')
			ssl->a++;
}
