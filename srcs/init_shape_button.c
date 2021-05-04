/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shape_button_init.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nneronin <nneronin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/13 16:55:56 by nneronin          #+#    #+#             */
/*   Updated: 2021/05/04 12:43:01 by jsalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../guimp.h"

static inline void	orb(t_info *info)
{
	t_xywh coord;
	int minim = min(100, 50); // aka w and h for the element

	coord = ui_init_coords(25, 25, 100, 50);
	info->orb_shape = bui_new_element(info->shape_menu, NULL, coord);
	bui_set_element_image(info->orb_shape, ELEMENT_ALL, info->shape_img.orb, &(t_xywh){coord.w / 2 - minim / 2, 0, minim, minim});
	add_to_list(&info->shapes, info->orb_shape, sizeof(t_bui_element));
}

static inline void	square(t_info *info)
{
	t_xywh coord;
	int minim = min(100, 50); // aka w and h for the element

	coord = ui_init_coords(150, 25, 100, 50);
	info->square_shape = bui_new_element(info->shape_menu, NULL, coord);
	bui_set_element_image(info->square_shape, ELEMENT_ALL, info->shape_img.square, &(t_xywh){coord.w / 2 - minim / 2, 0, minim, minim});
	add_to_list(&info->shapes, info->square_shape, sizeof(t_bui_element));
}

static inline void	tube(t_info *info)
{
	t_xywh coord;
	int minim = min(100, 50); // aka w and h for the element

	coord = ui_init_coords(275, 25, 100, 50);
	info->tube_shape = bui_new_element(info->shape_menu, NULL, coord);
	bui_set_element_image(info->tube_shape, ELEMENT_ALL, info->shape_img.tube, &(t_xywh){coord.w / 2 - minim / 2, 0, minim, minim});
	add_to_list(&info->shapes, info->tube_shape, sizeof(t_bui_element));
}

void	shape_buttons_init(t_info *info)
{
	info->active_shape = NULL;
	info->shapes = NULL;
	orb(info);
	square(info);
	tube(info);
	// TODO : info->shapes[0]->default_state = 1;
		/*
	int		i;

	i = -1;
	info->shapes_nbr = 3;
	while (++i < info->shapes_nbr)
	{
		info->shapes[i]->f = &ft_toggle_elem_group;
		info->shapes[i]->extra_info = info->shapes;
		((t_button *)info->shapes[i]->info)->extra = &info->shapes_nbr;
		info->shapes[i]->text.centered = 1;
		ft_update_element(info->shapes[i]);
	}
		*/
}
