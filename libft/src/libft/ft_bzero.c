/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msabre <msabre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 17:30:58 by msabre            #+#    #+#             */
/*   Updated: 2020/02/28 20:22:13 by msabre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/libft.h"

void	ft_bzero(void *s, size_t n)
{
	int i;

	i = 0;
	while (n > 0)
	{
		*((char*)s) = '\0';
		s++;
		n--;
	}
}
