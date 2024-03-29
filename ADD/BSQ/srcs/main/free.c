/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svan-de- <svan-de-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 15:09:34 by svan-de-          #+#    #+#             */
/*   Updated: 2024/02/10 16:58:19 by svan-de-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

void	free_split(char **split)
{
	int	i;

	i = 0;
	if (split)
	{
		while (split[i])
			i++;
		i--;
		while (i >= 0)
		{
			free(split[i]);
			i--;
		}
		free(split);
	}
}

void	free_map(t_data *data)
{
	set_chars(&data->chars);
	if (data->file)
	{
		free(data->file);
		data->file = NULL;
	}
	if (data->map)
	{
		free_split(data->map);
		data->map = NULL;
	}
}

void	free_all(t_data *data)
{
	int	i;

	i = 0;
	if (data->fds)
	{
		while (data->fds[i])
			close(data->fds[i++]);
		free(data->fds);
	}
	free_map(data);
}
