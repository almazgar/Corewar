/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_to_write2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgarse <lgarse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/18 12:00:53 by almazg            #+#    #+#             */
/*   Updated: 2020/04/18 12:00:53 by almazg           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

void	line_to_write2(int k, t_file *ssl, int i, unsigned char *s)
{
	if (i == k)
		write(ssl->text, s, i);
	else
		write_error("ERROR_CONVERTING_ARGUMENTS");
}
