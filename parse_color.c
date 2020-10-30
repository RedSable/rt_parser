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

int		ft_atoi_hex(char *str);

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

	r = 0;
	g = 0;
	b = 0;
	if (str[0] == '0')
		set_color_int(color, ft_atoi_hex(str[2]));
	else if (str[0] == '{')
	{
		rgb = ft_strsplit(str, ',');
		r = get_float(rgb[0]);
		if (rgb[1] != NULL)
			g = get_float(rgb[1]);
		if (rgb[2] != NULL)
			b = get_float(rgb[2]);
		set_color_float(color, r, g, b);
	}
}

void	get_vector(char *str, void *vector)
{
	float	v[4];
	char	**xyz;

	if (str[0] == '{')
	{
		xyz = ft_strsplit(str, ',');
		v[0] = get_float(xyz[0]);
		if (xyz[1] != NULL)
			v[1] = get_float(xyz[1]);
		else
			v[1] = 0;
		if (xyz[2] != NULL)
			v[2] = get_float(xyz[2]);
		else
			v[2] = 0;
		v[3] = 0;
		vector = v;
	}
}
