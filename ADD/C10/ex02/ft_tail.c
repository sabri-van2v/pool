/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tail.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svan-de- <svan-de-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 19:54:21 by svan-de-          #+#    #+#             */
/*   Updated: 2024/02/13 16:53:55 by svan-de-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_tail.h"

void	gap(char *str, int byte)
{
	int	i;

	i = 0;
	while (i < byte)
	{
		str[i] = str[i + 1];
		i++;
	}
}

int	print_end_check(ssize_t reader, char *tail, int byte, int fd)
{
	while (reader > 0)
	{
		gap(tail, byte);
		reader = read(fd, &tail[byte], 1);
		if (reader < 0)
			return (free(tail), 0);
	}
	return (1);
}

int	print_end(int byte, int fd)
{
	char	*tail;
	int		reader;

	tail = malloc(byte + 1);
	if (!tail)
		return (0);
	reader = read(fd, tail, byte + 1);
	if (reader < 0)
		return (free(tail), 0);
	if (reader < byte + 1)
	{
		tail[reader] = '\0';
		print_tail(tail);
		free(tail);
		return (1);
	}
	if (!print_end_check(reader, tail, byte, fd))
		return (0);
	tail[byte] = '\0';
	print_tail(tail);
	free(tail);
	return (1);
}

int	ft_tail(int byte, char **argv)
{
	int	i;
	int	fd;

	i = 0;
	if (!argv[0])
		return (for_stdin(byte), 1);
	while (argv[i])
	{
		fd = open(argv[i], O_RDONLY);
		if (fd == -1)
			print_error(argv[i]);
		else
		{
			if (i != 0)
				write(1, "\n", 1);
			if (i != 0 || argv[i + 1])
				print_head(argv[i]);
			if (!print_end(byte, fd))
				return (0);
			close(fd);
		}
		i++;
	}
	return (1);
}

int	main(int argc, char **argv)
{
	int	byte;

	if (!check_args(argc, argv))
		return (0);
	byte = ft_atoi(&argv[1][2]);
	if (!ft_tail(byte, &argv[2]))
		return (1);
}
