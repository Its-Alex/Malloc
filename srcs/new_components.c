/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_components.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malexand <malexand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 22:20:16 by alex              #+#    #+#             */
/*   Updated: 2017/11/23 16:42:05 by malexand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <malloc.h>

t_block			*new_block(void *start, unsigned int left_aft)
{
	t_block		*block;

	block = (t_block *)start;
	block->empty = true;
	block->size_left_aft = left_aft;
	block->mem = start + sizeof(t_block);
	block->next = NULL;
	return (block);
}

t_page			*new_page(int size)
{
	t_page		*page;

	if ((page = (t_page *)mmap(NULL, size, PROT_READ | PROT_WRITE,
							   MAP_ANON | MAP_PRIVATE, -1, 0)) == NULL)
		return (NULL);
	page->max_size_left = size - sizeof(t_page) - sizeof(t_block);
	page->block = new_block((void *)page + sizeof(t_page), page->max_size_left);
	page->next = NULL;
	return (page);
}
