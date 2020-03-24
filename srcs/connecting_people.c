/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   connecting_people.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgarse <lgarse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/24 14:38:12 by almazg            #+#    #+#             */
/*   Updated: 2020/03/24 14:38:12 by almazg           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

char	*connecting_people(char **s1, char **s2)
{
	char *result;

	if (!(result = ft_strjoin(*s1, *s2)))
		ft_putstr("ERR_STR_INIT");
	ft_strdel(s1);
	ft_strdel(s2);
	return (result);
}
