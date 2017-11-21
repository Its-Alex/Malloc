/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malexand <malexand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 11:58:52 by malexand          #+#    #+#             */
/*   Updated: 2017/11/21 19:02:06 by malexand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <malloc.h>

int				main(void)
{
	char	*str;

	mprintf(1, "%d\n%d\n", TINY, SMALL);
	if ((str = (char *)malloc(5 + 1)) != NULL)
		ft_putstr(str);
	return (0);
}
