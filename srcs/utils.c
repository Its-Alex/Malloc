/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <alex@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 16:30:21 by malexand          #+#    #+#             */
/*   Updated: 2017/11/24 18:53:18 by alex             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <malloc.h>

size_t		size_alloc(size_t size)
{
	if (size <= TINY)
		return (TINY_SIZE);
	else if (size <= SMALL)
		return (SMALL_SIZE);
	else
		return (size);
}
