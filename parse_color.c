/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_color.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsylvana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 18:49:08 by lsylvana          #+#    #+#             */
/*   Updated: 2020/10/30 18:49:09 by lsylvana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "parser.h"
#include "color.h"

float	get_float(char *str)
{
	char	**arr;
	float	res;
	int		i;
	int		k;

	i = 1;
	res = 0.0;
	arr = ft_strsplit(str, '.');
	if (arr[0][0] == '-' && arr[0][1] == '0')
		i = -1;
	res += ft_atoi(arr[0]);
	if (arr[1] != NULL)
	{
		k = ft_atoi(arr[1]);
		res += (float)(k / pow(10, len_word(arr[1])));
	}
	res *= i;
	free_tab(arr);
	return (res);
}

void	get_color(char *str, t_color *color)
{
	float	r;
	float	g;
	float	b;
	char	**rgb;

	if (str[0] == '0')
		set_color_int(color, ft_atoi(str[2]));
	else if (str[0] == '{')
	{
		rgb = ft_strsplit(str, ',');
		r = get_float(rgb[0]);
		if (rgb[1] != NULL) g = get_float(rgb[1]);
		if (rgb[2] != NULL) b = get_float(rgb[2]);
		set_color_float(color, r, g, b);
	}
}
