/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   skip_probel.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgarse <lgarse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/24 11:18:03 by almazg            #+#    #+#             */
/*   Updated: 2020/03/24 11:41:11 by almazg           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

void	skip_probel(t_file *ssl, const char *line)
{
	while (is_whitespace(line[ssl->a]))
		ssl->a++;
}
