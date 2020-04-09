/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strncpy_dog.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avenonat <avenonat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/11 17:47:50 by avenonat          #+#    #+#             */
/*   Updated: 2020/03/11 17:47:50 by avenonat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

char		*strncpy_dog(char *dst, const char *src, size_t len)
{
	size_t i;
	size_t j;

	i = 0;
	j = 0;
//	dst[i++] = '@';
	while (j < len)
	{
		if (src[j] == '\0')
		{
			while (j < len)
			{
				dst[i] = '\0';
				i++;
				j++;
			}
			return (dst);
		}
		dst[i] = src[j];
		i++;
		j++;
	}
	return (dst);
}
