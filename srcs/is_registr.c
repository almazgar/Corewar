/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_registr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgarse <lgarse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/24 14:57:00 by almazg            #+#    #+#             */
/*   Updated: 2020/03/24 14:57:20 by almazg           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

int	is_registr(const char *a)
{
	int	i;

	i = 0;
	if (ft_strlen(a) >= 2 && ft_strlen(a) <= 3 && a[i] == 'r')
	{
		i++;
		while (ft_isdigit(a[i]))
			i++;
		return (!a[i] && ft_atoi(&a[1]) > 0);
	}
	return (0);
}
