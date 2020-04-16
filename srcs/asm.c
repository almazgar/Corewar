/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avenonat <avenonat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/07 15:22:00 by avenonat          #+#    #+#             */
/*   Updated: 2020/04/15 15:08:52 by almazg           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/asm.h"
# include <stdio.h>
# include <stdarg.h>
# include <unistd.h>
# include <wchar.h>
# include <stdlib.h>
# include <fcntl.h>

int		main(int argc, char **argv)
{
	int		j;
	int		fd;
	char    *line;
	t_file	*ssl;

	j = 0;
	ssl = init_ssl();
	if (argc > 1)
	{
		while (argv[argc - 1][j])
			j++;
		while (j != -1 && argv[argc - 1][j] != '.')
			j--;
		if (argv[argc - 1][j] == '.' && argv[argc - 1][j + 1] == 's')
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
				ssl->f_name[j] = argv[argc - 1][j];
				j--;
			}
		}
		ssl->fd = open(argv[argc - 1], O_RDONLY);
		if ((fd = open(argv[argc - 1], O_RDONLY)) == -1)
			write_error("DOESNT READ FILE_CHECK NAME\n");
		line = NULL;
		skolkovo(line, ssl);
		close(fd);
		free_t_file(ssl);
		ft_strdel(&line);
	}
	else
		ft_putstr("Usage: ./asm <sourcefile.s>\n");
	return (0);
}
