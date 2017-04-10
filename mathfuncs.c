/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mathfuncs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfontain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/10 07:54:54 by tfontain          #+#    #+#             */
/*   Updated: 2017/04/10 10:35:01 by tfontain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./filler.h"

/*
** calculate a good approximation of sqrt
** note : this is black magic
*/

float			q_sqrt(const float x)
{
	const float	xhalf = 0.5f * x;
	t_sqrt		u;

	u.x = x;
	u.i = 0x5f3759df - (u.i >> 1);
	return (x * u.x * (1.5f - xhalf * u.x * u.x));
}

/*
** calculate the distance between two points
*/

float			distance(t_size a, t_size b)
{
	const int d1 = a.x - b.x;
	const int d2 = a.y - b.y;

	return (q_sqrt(d1 * d1 + d2 * d2));
}
