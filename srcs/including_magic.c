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

//void	including_name(int text, t_file *ssl)
//{
//	int i;
//	char str[PROG_NAME_LENGTH];
//	i = 0;
//	if (ssl->file[ssl->b] == '.')
//	{
//		ssl->file[ssl->b++] = 'n';
//		ssl->file[ssl->b++] = 'a';
//		ssl->file[ssl->b++] = 'm';
//		ssl->file[ssl->b++] = 'e';
//		while (ssl->file[ssl->b] && ssl->file[ssl->b] != '"')
//            (ssl->b)++;
//	}
//	else
//		write_error("CHAMPION DOESN'T HAVE NAME");
//	if (ssl->file[ssl->b] == '"')
//	{
//        (ssl->b)++;
//		while (ssl->file[ssl->b] && ssl->file[ssl->b] != '"')
//		{
//			str[i] = ssl->file[ssl->b] >> (8 * (PROG_NAME_LENGTH - 1 - i));
//			(ssl->b)++;
//			i++;
//		}
//	ft_memcpy()
//		if (i < PROG_NAME_LENGTH)
//		{
//			while (i != PROG_NAME_LENGTH)
//			{
//                str[i] = 0x0 >> (8 * (PROG_NAME_LENGTH - 1 - i));
//				i++;
//			}
//		}
//		else
//			write_error("VERY LONG NAME");
//	}
//	else
//		write_error("CHAMPION DOESN'T HAVE NAME");
//	write(text, str, 128);
//}

void	including_magic(int text)
{
	int i;
	unsigned char	buffer[4];

	i = 0;
	while (i < 4)
	{
		buffer[i] = COREWAR_EXEC_MAGIC >> (8 * (3 - i));
		i++;
	}
	write(text, buffer, 4);
}
