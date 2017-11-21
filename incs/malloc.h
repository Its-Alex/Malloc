/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <alex@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 12:02:15 by malexand          #+#    #+#             */
/*   Updated: 2017/11/21 23:36:35 by alex             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MALLOC_H
# define MALLOC_H

# define _DEFAULT_SOURCE

# include <unistd.h>
# include <stdlib.h>
# include <sys/mman.h>

# include <libft.h>

# define TINY ((getpagesize() * 2) - sizeof(t_page) - 100 * sizeof(t_block)) / 100
# define SMALL ((getpagesize() * 4) - sizeof(t_page) - 100 * sizeof(t_block)) / 100

typedef struct		s_block
{
	char			empty;
	void			*mem;
	struct s_block	*next;
}					t_block;

typedef struct		s_page
{
	char			space_left;
	void			*mem;
	t_block			*block;
	struct s_page	*next;
}					t_page;

void				*alloc_mmap(size_t size);
t_page				*new_page(size_t size);

void				free(void *ptr);
void				*malloc(size_t size);
void				*realloc(void *ptr, size_t size);

#endif
