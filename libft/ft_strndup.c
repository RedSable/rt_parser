/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aapricot <aapricot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 02:30:06 by aapricot          #+#    #+#             */
/*   Updated: 2020/11/10 02:35:24 by aapricot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_strndup(const char *s1, size_t n)
{
	char			*p;
	char			*rp;

	if (!(p = ft_strnew(n + 1)))
		return (NULL);
	rp = p;
	while ((*p = *s1) && (size_t)(p - rp) < n)
	{
		p++;
		s1++;
	}
	ft_memset(p, 0, 1 + n - (p - rp));
	return (rp);
}
