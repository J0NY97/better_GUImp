/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gfx_distance.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsalmi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/27 16:32:36 by jsalmi            #+#    #+#             */
/*   Updated: 2021/07/27 16:32:42 by jsalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libgfx.h"

double	gfx_distance(t_vector v1, t_vector v2)
{
	double	result;

	result = sqrt(ft_pow(v1.x - v2.x, 2)
			+ ft_pow(v1.y - v2.y, 2)
			+ ft_pow(v1.z - v2.z, 2));
	if (result < 0)
		result *= -1;
	return (result);
}
