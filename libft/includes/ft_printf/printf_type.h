/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_type.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbravo- <chbravo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/18 03:32:59 by chbravo-          #+#    #+#             */
/*   Updated: 2017/05/13 15:24:24 by chbravo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_TYPE_H
# define PRINTF_TYPE_H

enum				e_flag
{
	zero,
	hh,
	h,
	l,
	ll,
	j,
	z
};

enum				e_conv
{
	zeroo,
	c,
	C,
	d,
	o,
	p,
	s,
	S,
	u,
	x,
	X,
	per,
	def
};

typedef struct		s_arg
{
	unsigned		alternate:1;
	unsigned		zero_pad:1;
	unsigned		left_pad:1;
	unsigned		blank_pos:1;
	unsigned		sign_pos:1;
	unsigned		deci_conv:1;
	unsigned		min_width;
	unsigned		precision:1;
	unsigned		preci_len;
	enum e_flag		len_modifier;
	enum e_conv		conversion;
	char			defchar;
}					t_args;

#endif
