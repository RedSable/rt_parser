/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_first_values.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aapricot <aapricot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 00:10:21 by aapricot          #+#    #+#             */
/*   Updated: 2020/11/03 22:04:58 by aapricot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "offset.h"

float		ft_atofloat(char *str) //функция говно, нужна другая
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

void		get_color(char *str, int offset, void *data)
{
	t_color		*color;
	char	**rgb;
	unsigned char	*v;

	v = (unsigned char *)data + offset;
	color = (t_color *)v;
	color->r = 0.0f;
	color->g = 0.0f;
	color->b = 0.0f;
	if (str[0] == '0' && str[1] == 'x')
		set_color_int(color, ft_atoi_hex(str[2]));
	else if (str[0] == '{')
	{
		rgb = ft_strsplit(str, ',');
		if (rgb[0] == NULL)
			return ;
		else
			color->r = ft_atofloat(rgb[0]);
		if (rgb[1] == NULL)
			return ;
		else
			color->g = ft_atofloat(rgb[1]);
		if (rgb[2] != NULL)
			color->b = ft_atofloat(rgb[2]);
	}
}

void		get_vector(char *str, int offset, void *data)
{
	unsigned char	*v;
	cl_float4		*vec_ptr;
	char			**split;

	v = (unsigned char *)data + offset;
	vec_ptr = (cl_float4 *)v;
	vec_ptr->x = 0.0f;
	vec_ptr->y = 0.0f;
	vec_ptr->z = 0.0f;
	split = ft_strsplit(str, ',');
	if (split[0] == NULL)
		return ;
	else
		vec_ptr->x = ft_atofloat(split[0]);
	if (split[1] == NULL)
		return ;
	else
		vec_ptr->y = ft_atofloat(split[1]);
	if (split[2] != NULL)
		vec_ptr->z = ft_atofloat(split[2]);
}

void		get_float(char *str, int offset, void *data)
{
	unsigned char	*v;
	cl_float		*ptr;

	v = (unsigned char *)data + offset;
	ptr = (cl_float *)v;
	*ptr = ft_atofloat(str);
}

void		get_uchar(char *str, int offset, void *data)
{
	unsigned char	*v;
	cl_uchar		*c;

	v = (unsigned char *)data + offset;
	c = (cl_uchar *)v;
	c = 'A';
}

void		get_int(char *str, int offset, void *data)
{
	unsigned char	*v;
	cl_int			*num;

	v = (unsigned char *)data + offset;
	num = (cl_int *)v;
	*num = ft_atoi(str);
}
