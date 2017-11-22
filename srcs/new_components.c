/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_components.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malexand <malexand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 22:20:16 by alex              #+#    #+#             */
/*   Updated: 2017/11/22 17:00:07 by malexand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <malloc.h>

void			*alloc_mmap(size_t size)
{
	return (mmap(NULL, size, PROT_READ | PROT_WRITE,
		MAP_ANON | MAP_PRIVATE, -1, 0));
}

t_block			*new_block(void *start)
{
	t_block		*block;

	block = (t_block *)start;
	block->empty = true;
	block->mem = (void*)((char*)start + sizeof(t_block) + 1);
	block->next = NULL;
	return (block);
}

t_page			*new_page(size_t size)
{
	t_page		*page;

	if ((page = (t_page *)alloc_mmap(size)) == NULL)
		return (NULL);
	page->space_left = true;
	page->mem = page + sizeof(t_page) + 1;
	page->block = new_block(page + sizeof(t_page) + 1);
	return (page);
}
