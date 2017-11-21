/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <alex@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 11:58:52 by malexand          #+#    #+#             */
/*   Updated: 2017/11/22 00:10:41 by alex             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <malloc.h>

int				main(void)
{
	char	*str;

	printf("Page size: %6d\nTINY: %9lu\nSMALL: %9lu\n", getpagesize(), TINY, SMALL);
	if ((str = (char *)malloc(5 + 1)) != NULL)
		ft_putstr(str);
	return (0);
}
