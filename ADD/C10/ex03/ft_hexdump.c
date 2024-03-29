/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexdump.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svan-de- <svan-de-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 19:57:51 by svan-de-          #+#    #+#             */
/*   Updated: 2024/02/13 17:19:25 by svan-de-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_hexdump.h"

int	file_hexdump(t_data *data, int i)
{
	ssize_t	reader;

	data->input++;
	reader = 16;
	while (reader == 16)
	{
		reader = read(data->fd, &(data->str[data->link]), 16 - data->link);
		if (reader < 0)
			return (0);
		if (!data->files[i + 1] && reader + data->link != 16)
			data->str[reader] = '\0';
		if (reader < 16 && data->link)
		{
			reader = 16;
			data->link = 0;
		}
		if (reader < 16)
			data->link = reader;
		if ((!data->link || !data->files[i + 1]) && reader != 0)
		{
			result_management(data);
			data->octets += reader;
		}
	}
	return (1);
}

void	hexdump_while(t_data *data)
{
	int	i;

	i = 0;
	while (data->files[i])
	{
		data->fd = open(data->files[i], O_RDONLY);
		if (data->fd == -1)
		{
			print_error(data->files[i]);
			if (!data->files[i + 1] && data->input)
			{
				data->str[data->link] = '\0';
				result_management(data);
				data->octets += data->link;
			}
		}
		else
		{
			if (!file_hexdump(data, i))
				print_error(data->files[i]);
			close(data->fd);
		}
		i++;
	}
}

void	ft_hexdump(t_data *data)
{
	data->str[16] = '\0';
	if (data->stdin)
		return (for_stdin(data));
	hexdump_while(data);
	if (data->input)
	{
		display_number_octets(data->octets, data->option);
		ft_putchar('\n');
	}
	else
		print_error_input();
}

int	main(int argc, char **argv)
{
	t_data	data;

	set_data(&data);
	fill_data(&data, argc, argv);
	if (!data.str)
		return (1);
	ft_hexdump(&data);
	free(data.str);
}
