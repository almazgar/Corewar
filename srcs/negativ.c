/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   negativ.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almazg <almazg@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/12 13:52:30 by almazg            #+#    #+#             */
/*   Updated: 2020/04/12 13:52:30 by almazg           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

long long	negativ(long long nb, int b)
{
	long long	max;

	if (b == 4)
		nb = nb % (256L * 256L * 256L * 256L);
	else if (b == 2)
		nb = nb % (256L * 256L);
	max = 256L * 256L;
	if (b == 4)
		max = 256L * 256L * 256L * 256L;
	return (max - nb);
}
