/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avenonat <avenonat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/07 19:01:10 by avenonat          #+#    #+#             */
/*   Updated: 2020/03/08 15:10:07 by avenonat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

void	read_file(char *argv)
{
	int				fd;
	int				text;
	unsigned int	magic;
	unsigned char	buffer[PROG_NAME_LENGTH + 1];
	size_t 			i;

	if ((text = read(fd, &buffer, PROG_NAME_LENGTH)) == -1)
		write_error("ERROR WITH THE READING A FILE");
	if (text > PROG_NAME_LENGTH)
		write_error("INVALID SIZE");



}