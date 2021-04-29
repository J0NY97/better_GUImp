/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shape_button_init.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nneronin <nneronin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/13 16:55:56 by nneronin          #+#    #+#             */
/*   Updated: 2021/04/29 11:53:01 by jsalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../guimp.h"

static inline void	orb(t_info *info)
{
	t_xywh coord;

	coord = ui_init_coords(25, 25, 100, 50);
	info->orb_shape = bui_new_element(info->shape_menu, NULL, coord);
	bui_set_element_image(info->orb_shape, ELEMENT_ALL, info->shape_img.orb);
	add_to_list(&info->shapes, info->orb_shape, sizeof(t_bui_element));
	/* TODO:	
	info->shapes[0] = ui_create_button(info->toolbox->window,
			ui_init_coords(25, 25, 100, 50), info->shape_menu);
	ft_set_element_image(info->shapes[0], info->shape_img.orb);
	*/
}

static inline void	square(t_info *info)
{
	t_xywh coord;

	coord = ui_init_coords(150, 25, 100, 50);
	info->square_shape = bui_new_element(info->shape_menu, NULL, coord);
	bui_set_element_image(info->square_shape, ELEMENT_ALL, info->shape_img.square);
	add_to_list(&info->shapes, info->square_shape, sizeof(t_bui_element));
	/* TODO:	
	info->shapes[1] = ui_create_button(info->toolbox->window,
			ui_init_coords(150, 25, 100, 50), info->shape_menu);
	ft_set_element_image(info->shapes[1], info->shape_img.square);
	*/
}

static inline void	tube(t_info *info)
{
	t_xywh coord;

	coord = ui_init_coords(275, 25, 100, 50);
	info->tube_shape = bui_new_element(info->shape_menu, NULL, coord);
	bui_set_element_image(info->tube_shape, ELEMENT_ALL, info->shape_img.tube);
	add_to_list(&info->shapes, info->tube_shape, sizeof(t_bui_element));
	/* TODO:	
	info->shapes[2] = ui_create_button(info->toolbox->window,
			ui_init_coords(275, 25, 100, 50), info->shape_menu);
	ft_set_element_image(info->shapes[2], info->shape_img.tube);
	*/
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
