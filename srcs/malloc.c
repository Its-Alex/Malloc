/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <alex@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 12:11:34 by malexand          #+#    #+#             */
/*   Updated: 2017/11/21 22:32:42 by alex             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <malloc.h>

t_page g_pages[3] = {
	{'1', NULL, NULL, NULL},
	{'1', NULL, NULL, NULL},
	{'1', NULL, NULL, NULL}
};

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

size_t			getsize_page(size_t size)
{
	if (size <= TINY)
		return (getpagesize() - sizeof(t_page)) * 2;
	else if (size <= SMALL)
		return (getpagesize() - sizeof(t_page)) * 4;
	else
		return size;
}
 
void			*find_block(t_page *page, int type, size_t size)
{
	(void)page;
	type = 0;
	size = 0;
	return NULL;
}

void			*find_page(t_page *page, int type, size_t size)
{
	if (page == NULL)
	{
		if ((page = new_page(getsize_page(size))) == NULL)
			return NULL;
	}
	else if (page->space_left == false)
	{
		if (page->next == NULL)
			if ((page->next = new_page(getsize_page(size))) == NULL)
				return NULL;
		return find_page(page->next, type, size);
	}
	return find_block(page, type, size);
}

void			*malloc(size_t size)
{
	int		type;

	type = init(size);
	if (g_pages[type].mem == NULL)
	{
		if ((g_pages[type].mem = alloc_mmap(getsize_page(size))) == NULL)
			return NULL;
	}
	return find_page(&g_pages[type], type, size);
}
