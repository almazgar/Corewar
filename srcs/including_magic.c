/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   including_magic.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avenonat <avenonat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/11 17:40:27 by avenonat          #+#    #+#             */
/*   Updated: 2020/04/09 09:16:05 by almazg           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

void				including_magic(int text)
{
	int				i;
	unsigned char	buffer[4];

	i = 0;
	while (i < 4)
	{
		buffer[i] = COREWAR_EXEC_MAGIC >> (8 * (3 - i));
		i++;
	}
	write(text, buffer, 4);
}
