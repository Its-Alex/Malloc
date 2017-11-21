/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malexand <malexand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 12:11:34 by malexand          #+#    #+#             */
/*   Updated: 2017/11/21 19:19:55 by malexand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <malloc.h>

t_page g_pages[3] = {
	{'1', NULL, NULL, NULL},
	{'1', NULL, NULL, NULL},
	{'1', NULL, NULL, NULL}
};

static void		*alloc_mmap(size_t size)
{
	void *tmp;

	tmp = (void *)mmap(NULL, size, PROT_READ | PROT_WRITE,
					   MAP_ANON | MAP_PRIVATE, -1, 0);
	printf("My_Malloc\n");
	return tmp;
}

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

void			*find_block()

void			*find_page(t_page *page, int type)
{
	if (page == NULL)
	{
		if ((page = (t_page *)alloc_mmap(getsize_page(size))) == NULL)
			return NULL;
		page.space_left = true;
		page.mem = page + sizeof(t_page) + 1;
		page.next = NULL;
	}
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
	return find_mem(type, g_pages[type], size);
}
