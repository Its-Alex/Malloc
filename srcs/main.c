/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malexand <malexand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 11:58:52 by malexand          #+#    #+#             */
/*   Updated: 2017/11/22 17:03:10 by malexand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <malloc.h>

int				main(void)
{
	char	*str;
	char	*str1;
	char	*str2;

	printf("Page size: %6d\nTINY: %9lu\nSMALL: %9lu\n",
		getpagesize(), TINY, SMALL);
	if ((str = (char *)malloc(5 + 1)) != NULL)
	{
		str[0] = 'S';
		str[1] = 'a';
		str[2] = 'l';
		str[3] = 'u';
		str[4] = 't';
		str[5] = '\0';
		ft_putstr(str);
		ft_putchar('|');
	}
	if ((str1 = (char *)malloc(5 + 1)) != NULL)
	{
		str1[0] = 'S';
		str1[1] = 'a';
		str1[2] = 'l';
		str1[3] = 'u';
		str1[4] = 't';
		str1[5] = '\0';
		ft_putstr(str1);
		ft_putchar('|');
	}
	if ((str2 = (char *)malloc(5 + 1)) != NULL)
	{
		str2[0] = 'S';
		str2[1] = 'a';
		str2[2] = 'l';
		str2[3] = 'u';
		str2[4] = 't';
		str2[5] = '\0';
		ft_putstr(str2);
		ft_putchar('|');
	}
	return (0);
}
