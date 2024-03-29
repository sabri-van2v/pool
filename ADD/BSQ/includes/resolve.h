/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolve.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svan-de- <svan-de-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 15:20:09 by svan-de-          #+#    #+#             */
/*   Updated: 2024/02/09 15:21:29 by svan-de-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RESOLVE_H
# define RESOLVE_H

# include "bsq.h"

void		print_map(char *str);

void		fill_grey(char **map, t_coordinate stock, t_coordinate barrier,
				char barrier_char);

int			check_line_and_column(char **map, t_coordinate current,
				t_coordinate stock, t_chars *chars);
t_square	calcul_square(char **map, t_coordinate current, t_chars *chars);

void		fill_square(t_square *square);
t_square	resolve_loop(t_chars *chars, t_square biggest, char **map);
void		resolve(t_data *data);

#endif