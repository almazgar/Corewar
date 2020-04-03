/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avenonat <avenonat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/07 15:22:00 by avenonat          #+#    #+#             */
/*   Updated: 2020/04/03 12:36:25 by almazg           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "asm.h"
# include <stdio.h>
# include <stdarg.h>
# include <unistd.h>
# include <wchar.h>
# include <stdlib.h>
# include <fcntl.h>

int		main(int argc, char **argv)
{
	int		i;
	int		j;
	int		fd;
	char    *line;
	t_file	*ssl;

	i = 1;
	j = 0;
	ssl = init_ssl();
	if (argc == 1 || argc > 5)
		return (1);
	while (argv[i][j])
		j++;
	while (j != -1 && argv[i][j] != '.')
		j--;
	if (argv[i][j] == '.' && argv[i][j + 1] == 's')
	{
		if (!(ssl->f_name = (char *) malloc(sizeof(char *) * (j + 4))))
			exit(0);
		ssl->f_name[j++] = '.';
		ssl->f_name[j++] = 'c';
		ssl->f_name[j++] = 'o';
		ssl->f_name[j++] = 'r';
		ssl->f_name[j] = '\0';
		j = j - 5;
		while (j != -1)
		{
			ssl->f_name[j] = argv[i][j];
			j--;
		}
	}
		ssl->fd = open(argv[i], O_RDONLY);
		if ((fd = open(argv[i], O_RDONLY)) == -1)
			write_error("DOESNT READ FILE");
		line = NULL;
		skolkovo(line, ssl);
		close(fd);


	return (0);
}
