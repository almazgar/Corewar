/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msabre <msabre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/06 23:02:27 by msabre            #+#    #+#             */
/*   Updated: 2020/04/14 17:17:56 by almazg           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/libft.h"

char		*ft_strnew(size_t size)
{
	char	*str;
	size_t	i;

	i = 0;
	if (!(str = (char*)malloc(sizeof(char) * size + 1)))
		return (NULL);
	while (i <= size)
	{
		str[i] = '\0';
		i++;
	}
	return (str);
}
