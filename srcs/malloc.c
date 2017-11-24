/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <alex@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 12:11:34 by malexand          #+#    #+#             */
/*   Updated: 2017/11/24 18:59:07 by alex             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <malloc.h>

t_page g_pages[3] = {
	{0, NULL, NULL},
	{0, NULL, NULL},
	{0, NULL, NULL}};

int				init(size_t size)
{
	int		type;

	if (size <= TINY)
		type = 0;
	else if (size <= SMALL)
		type = 1;
	else
		type = 2;
	return (type);
}
 
void			*find_block(t_block *block, int type, size_t size)
{
	if (block == NULL)
		return NULL;
	else if (block->size == 0 && block->size_left_aft >= size)
	{
		block->size = size;
		block->page->max_size_left -= size;
		return block->mem;
	}
	if (block->size_left_aft == 0)
	{
		if (block->next == NULL) {
			block->page->max_size_left -= sizeof(t_block) + size;
			if ((block->next = new_block(block, block->page, size, block->page->max_size_left)) == NULL)
				return NULL;
			block->size_left_aft = 0;
		} else {
			return find_block(block->next, type, size);
		}
	}
	return block->mem;
}

void			*find_page(t_page *page, int type, size_t size)
{
	if (page->max_size_left < size + sizeof(t_block))
	{
		if (page->next == NULL)
			if ((page->next = new_page(size)) == NULL)
				return NULL;
		return find_page(page->next, type, size);
	}
	return find_block(page->block, type, size);
}

void			*malloc(size_t size)
{
	int		type;

	if (size == 0)
		return NULL;
	type = init(size);
	if (type == 0 && g_pages[type].max_size_left == 0)
		g_pages[type].max_size_left = TINY_SIZE;
	if (type == 1 && g_pages[type].max_size_left == 0)
		g_pages[type].max_size_left = SMALL_SIZE;
	if (type == 2 && g_pages[type].max_size_left == 0)
		return NULL;
	return find_page(&g_pages[type], type, size);
}
