/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsalmi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/23 12:56:35 by jsalmi            #+#    #+#             */
/*   Updated: 2021/04/29 17:01:54 by jsalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../guimp.h"

typedef struct	s_coords
{
	int x;
	int y;
}				t_coords;

void	dummy(void *dum, size_t dom)
{
}

void	push_list(t_list **lst, void *content, size_t content_size)
{
	t_list *new;

	new = ft_lstnew(content, content_size);
	if (lst)
		ft_lstadd(lst,  new);
	else
		*lst = new;
//	printf("c2: %d %d\n", ((t_coords *)content)->x, ((t_coords *)content)->y);
//	printf("p2: %d %d\n", ((t_coords *)new->content)->x, ((t_coords *)new->content)->y);
//	printf("l: %d %d %zu\n", ((t_coords *)(*lst)->content)->x, ((t_coords *)(*lst)->content)->y, (*lst)->content_size);
}

void	*pop_list(t_list **lst)
{
	void	*content;
	t_list *temp;

	if (!(content = (void *)malloc(sizeof((*lst)->content_size))))
		exit (0);
//	printf("pop: %d %d %zu\n", ((t_coords *)(*lst)->content)->x, ((t_coords *)(*lst)->content)->y, (*lst)->content_size);
	content = ft_memcpy(content, (*lst)->content, (*lst)->content_size);
//	printf("%d %d\n", ((t_coords *)content)->x, ((t_coords *)content)->y);
	temp = (*lst)->next;
	ft_lstdelone(lst, &dummy);
	*lst = temp;
	return (content);
}

void	flood_fill(SDL_Surface *surface, Uint32 targetColor, Uint32 replaceColor, int x, int y)
{
	t_list	*pix;
	t_xywh *content;
	t_xywh coord;
	int iter = 1;
	int ix;
	int iy;
	int	spanAbove;
	int spanBelow;

	if (targetColor == replaceColor)
		return;
	coord = new_xywh(x, y, 0, 0);
	push_list(&pix, &coord, sizeof(t_coords));
	while (iter != 0 && (content = pop_list(&pix)) != NULL)
	{
		iter--;
		ix = ((t_xywh *)content)->x;
		iy = ((t_xywh *)content)->y;
		free(content);
		while (ix > 0 && get_color(surface, ix - 1, iy) == targetColor)
			ix--;
		spanAbove = 0;
		spanBelow = 0;
		while(ix < surface->w && get_color(surface, ix, iy) == targetColor)
		{
			set_pixel(surface, ix, iy, replaceColor);
			if(spanAbove == 0 && iy > 0 && get_color(surface, ix, iy - 1) == targetColor)
			{
				coord = new_xywh(ix, iy - 1, 0, 0);
				push_list(&pix, &coord, sizeof(t_xywh));
				iter++;
	            spanAbove = 1;
	        }
			else if (spanAbove == 1 && iy > 0 && get_color(surface, ix, iy - 1) != targetColor)
				spanAbove = 0;
			if (spanBelow == 0 && iy < surface->h - 1 && get_color(surface, ix, iy + 1) == targetColor)
			{
				coord = new_xywh(ix, iy + 1, 0, 0);
				push_list(&pix, &coord, sizeof(t_xywh));
				iter++;
	            spanBelow = 1;
	        }
	        else if (spanBelow == 1 && iy < surface->h - 1 && get_color(surface, ix, iy + 1) != targetColor)
	            spanBelow = 0;
	        ix++;
	    }
	}
}
