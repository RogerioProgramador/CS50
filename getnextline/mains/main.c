/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rogeriorslf <rogeriorslf@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/02 22:11:55 by rogeriorslf       #+#    #+#             */
/*   Updated: 2021/06/06 03:28:57 by rogeriorslf      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../get_next_line/get_next_line.h"
#include <fcntl.h>

void	ft_putendl_fd(char *s, int fd)
{
	if (s == NULL)
		return ;
	while (*s)
	{
		write(fd, s, 1);
		s++;
	}
}

int		main(int argc, char **argv)
{
	int		fd;
	char	*line;
	int		i;

	i = 0;
	if (argc == 1)
		fd = 0;
	else if (argc == 2)
		fd = open(argv[1], O_RDONLY);
	else
		return (2);

	while (get_next_line(fd, &line) == 1)
	{
		write(1, "|", 1);
		ft_putendl_fd(line, 1);
	 	write(1, "|", 1);
		free(line);
		 i++;
	}
	if (argc == 2)
		close(fd);
}
