/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rogeriorslf <rogeriorslf@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/05 23:35:10 by rogeriorslf       #+#    #+#             */
/*   Updated: 2021/06/06 03:18:18 by rogeriorslf      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdlib.h>
#include <unistd.h>

int	check_nl(char buffer[])
{
	size_t	count;

	count = -1;
	while (buffer[++count])
		if (buffer[count] == '\n')
			return (count);
	return (0);
}

size_t	ft_strlen(const char *s)
{
	size_t	size;

	size = 0;
	while (s[size])
		size++;
	return (size);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		a;
	int		b;
	char	*pointer;

	a = 0;
	b = 0;
	if (s1 == NULL || s2 == NULL)
		return (NULL);
	pointer = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!(pointer))
		return (NULL);
	while (s1[a])
	{
		pointer[a] = s1[a];
		a++;
	}
	while (s2[b])
	{
		pointer[a] = s2[b];
		b++;
		a++;
	}
	pointer[a] = '\0';
	return (pointer);
}

char	*ft_strdup(char *s1, char c)
{
	char	*dest;
	char	*dest2;

	if (c == 0)
	{
		dest = malloc(ft_strlen(s1) + 1);
		if (!dest)
			return (NULL);
		dest2 = dest;
		while (*s1)
			*dest++ = *s1++;
	}
	if (c == '\n')
	{
		dest = malloc(ft_strlen(s1) - check_nl(s1) + 1);
		if (!dest)
			return (NULL);
		dest2 = dest;
		dest[ft_strlen(dest)] = 0;
		while (dest != 0)
			*dest++ = *s1++;
	}
	*dest = 0;
	dest = dest2;
	return (dest);
}

int	leftover(char *pointer[], char buffer[], int i[])
{
	while (buffer[i[3]] != '\n')
		i[3]++;
	pointer[0] = (char *)malloc(sizeof(char) * i[3] + 1);
	if (!pointer[0])
		return (-1);
	pointer[i[3]] = 0;
	while (i[4] < i[3])
	{
		pointer[0][i[4]] = buffer[i[4]];
		i[4]++;
	}
	i[4]++;
	i[3] = -1;
	pointer[1] = (char *)malloc(sizeof(char) * ft_strlen(buffer) - i[4] + 1);
	if (!pointer[1])
		return (-1);
	pointer[1][ft_strlen(pointer[1])] = 0;
	while (buffer[i[4]])
		pointer[1][++i[3]] = buffer[i[4]++];
	return (1);
}

int habemus_leftover(char *pointer[], int i[])
{
	char *toleftover;
	if (check_nl(pointer[1]))
	{
		toleftover = ft_strdup(pointer[1], 0);
		free(pointer[1]);
		leftover(pointer, toleftover, i);
	}
	free(toleftover);
	if (ft_strlen(pointer[1]) == 0)
		return (1);
	return (-2);
}


int	catenate(char *pointer[], char buffer[], int i[])
{
	if (check_nl(buffer))
	{
		i[2] = leftover(pointer, buffer, i);
		if(i[2] == -1)
			return (-1);
		return (1);
	}
	else
	{
		if (!pointer[0])
		{
			pointer[0] = ft_strdup(buffer, 0);
			if (!pointer[0])
				return (-1);
		}
		else
		{
			pointer[0] = ft_strjoin(pointer[0], buffer);
		}
		return (1);
	}
}

int	get_line(char *pointer[], int fd, char buffer[], int i[], int x)
{
	while (x > 0 && !check_nl(buffer) )
	{
		x = read(fd, buffer, BUFFER_SIZE);
		if (x == -1)
			return(0);
		buffer[x] = 0;
		i[1] = catenate(pointer, buffer, i);
		if (i[1] == -1)
			return (-1);
	}
	if (x == 0 && ft_strlen(pointer[1]) > 0)
		x = -2;
	return (x);
}

int	get_next_line(int fd, char **line)
{
	int			i[5];
	static int	x;
	char		*buffer;
	static char	*pointer[2];

	x = 1;
	i[0] = 0;
	i[1] = 0;
	i[2] = 0;
	i[3] = 0;
	i[4] = 0;
	if (x ==-2)
	{
		free(pointer[0]);
		x = habemus_leftover(pointer, i);
		if (x == -2)
			i[0] = 1;
		if (x == 1)
			i[0] = 1;

	}
	else
	{
		buffer = (char *)malloc(BUFFER_SIZE +1);
		x = get_line(pointer, fd, buffer, i, x);
		if (x== -2)
			i[0] = 1;
		if(x == -1)
			return (-1);
	}
	*line = pointer[0];
	return(i[0]);
}
