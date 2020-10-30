/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsylvana <lsylvana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/26 16:40:36 by lsylvana          #+#    #+#             */
/*   Updated: 2020/02/05 02:34:37 by lsylvana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_get_num(char c)
{
	int		n;
	char	*radix;

	n = 0;
	radix = "0123456789ABCDEF";
	while (ft_toupper(c) != radix[n])
		n++;
	return (n);
}

static int	ft_atoi_base(char *str, int base)
{
	int		n;
	int		i;

	n = 0;
	i = 2;
	if (base < 0 || base > 16)
		return (0);
	while (str[i])
		if ((str[i] >= '0' && str[i] <= '9') ||
		(str[i] >= 'A' && str[i] <= 'F') ||
		(str[i] >= 'a' && str[i] <= 'f'))
			n = n * base + ft_get_num(str[i++]);
		else
			break ;
	return (n);
}

int			ft_atoi_hex(char *str)
{
	return (ft_atoi_base(str, 16));
}
