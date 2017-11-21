/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_components.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <alex@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 22:20:16 by alex              #+#    #+#             */
/*   Updated: 2017/11/21 23:38:31 by alex             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <malloc.h>

void			*alloc_mmap(size_t size)
{
	return mmap(NULL, size, PROT_READ | PROT_WRITE,
					   MAP_ANON | MAP_PRIVATE, -1, 0);
}

t_page			*new_page(size_t size)
{
	t_page	*page;

	if ((page = (t_page *)alloc_mmap(size)) == NULL)
			return NULL;
	page->space_left = true;
	page->mem = page + sizeof(t_page) + 1;
	page->next = NULL;
	return page;
}
