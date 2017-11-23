/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malexand <malexand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 12:11:34 by malexand          #+#    #+#             */
/*   Updated: 2017/11/23 16:30:08 by malexand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <malloc.h>

t_page g_pages[3] = {
	{TINY_PAGE_SIZE, NULL, NULL, NULL},
	{SMALL_PAGE_SIZE, NULL, NULL, NULL},
	{0, NULL, NULL, NULL}};

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
 
void			*find_block(t_page *page, int type, size_t size)
{
	int			count;
	t_block		*tmp;

	count = -1;
	size = 0;
	if (page == NULL || page->block == NULL)
		return NULL;
	tmp = page->block;
	while (++count < 100 && tmp != NULL)
	{
		if (tmp->empty == true)
			return tmp->mem;
		else
		{
			if (tmp->next == NULL)
			{
				if (type == 0)
					tmp->next = new_block(tmp + TINY - sizeof(t_block) + 1);
				if (type == 1)
					tmp->next = new_block(tmp + SMALL - sizeof(t_block) + 1);
				if (type == 2)
					return (NULL);
				tmp = tmp->next;
			}
			else 
				tmp = tmp->next;
		}
	}
	return NULL;
}

void			*find_page(t_page *page, int type, size_t size)
{
	if (page == NULL)
	{
		if ((page = new_page(size_alloc(size))) == NULL)
			return NULL;
	}
	else if (page->mem == NULL)
	{
		if ((page->mem = alloc_mmap(size_alloc(size))) == NULL)
			return NULL;
		page->block = new_block(page->mem);
		page->next = NULL;
	}
	else if (page->space_left == false)
	{
		if (page->next == NULL)
			if ((page->next = new_page(size_alloc(size))) == NULL)
				return NULL;
		return find_page(page->next, type, size);
	}
	return find_block(page, type, size);
}

void			*malloc(size_t size)
{
	int		type;

	type = init(size);
	return find_page(&g_pages[type], type, size);
}
