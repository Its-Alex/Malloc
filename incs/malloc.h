/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malexand <malexand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 12:02:15 by malexand          #+#    #+#             */
/*   Updated: 2017/11/22 18:13:59 by malexand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MALLOC_H
# define MALLOC_H

# define _DEFAULT_SOURCE

# include <unistd.h>
# include <stdlib.h>
# include <sys/mman.h>

# include <libft.h>

# define TINY_PAGE_SIZE getpagesize() * 3
# define SMALL_PAGE_SIZE getpagesize() * 6
# define TINY_SIZE TINY_PAGE_SIZE - sizeof(t_page)
# define SMALL_SIZE SMALL_PAGE_SIZE - sizeof(t_page)
# define TINY (TINY_SIZE - 100 * sizeof(t_block)) / 100
# define SMALL (SMALL_SIZE - 100 * sizeof(t_block)) / 100

typedef struct		s_block
{
	char			empty;
	void			*mem;
	struct s_block	*next;
}					t_block;

typedef struct		s_page
{
	char			left;
	void			*mem;
	t_block			*block;
	struct s_page	*next;
}					t_page;

void				*alloc_mmap(size_t size);
t_page				*new_page(size_t size);
t_block				*new_block(void *start);

void				free(void *ptr);
void				*malloc(size_t size);
void				*realloc(void *ptr, size_t size);

#endif
