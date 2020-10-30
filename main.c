/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aapricot <aapricot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 19:43:24 by aapricot          #+#    #+#             */
/*   Updated: 2020/10/19 20:00:39 by aapricot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int		main(int ac, char **av)
{
	int		numerror;

	numerror = 0;
	if (ac != 2)
		die("Bad arguments.", -1);
	if (numerror = parser(av[1]) < 0)
		die("", numerror);
	return (0);
}