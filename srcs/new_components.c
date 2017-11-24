/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_components.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <alex@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 22:20:16 by alex              #+#    #+#             */
/*   Updated: 2017/11/24 18:56:47 by alex             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <malloc.h>

t_block			*new_block(void *start, t_page *page, unsigned int size,
	unsigned int left_aft)
{
	t_block		*block;

	block = (t_block *)((char*)start + size + sizeof(t_block));
	block->size_left_aft = left_aft;
	block->size = 0;
	block->mem = block + sizeof(t_block);
	block->page = page;
	block->next = NULL;
	return (block);
}

t_page			*new_page(int size)
{
	t_page		*page;

	if ((page = (t_page *)mmap(NULL, size_alloc(size), PROT_READ | PROT_WRITE,
								MAP_ANON | MAP_PRIVATE, -1, 0)) == NULL)
		return (NULL);
	page->max_size_left = size_alloc(size) - sizeof(t_page) - sizeof(t_block);
	page->block = new_block((char *)page + sizeof(t_page), page, size, page->max_size_left);
	page->next = NULL;
	return (page);
}
