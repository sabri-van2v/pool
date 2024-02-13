/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   good_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svan-de- <svan-de-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 17:51:43 by svan-de-          #+#    #+#             */
/*   Updated: 2024/02/13 17:51:55 by svan-de-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

int	good_line(char *str)
{
	int	i;

	i = 0;
	if (!(str[i] >= '0' && str[i] <= '9'))
		return (0);
	while (str[i] >= '0' && str[i] <= '9')
		i++;
	while (str[i] == ' ')
		i++;
	if (str[i] != ':')
		return (0);
	while (str[i] == ' ')
		i++;
	if (!str[i])
		return (0);
	return (1);
}