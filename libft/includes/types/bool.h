/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bool.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbravo- <chbravo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/21 22:35:44 by chbravo-          #+#    #+#             */
/*   Updated: 2017/10/19 02:24:44 by jlasne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BOOL_H
# define BOOL_H

/*
**# if defined(_STDBOOL_H) || defined(__STDBOOL_H) || \
**	defined(__bool_true_false_are_defined)
**
**#  define BOOL bool
**# else
** TODO UNTIL CHRIS NORME IT
*/
# define BOOL t_bool

typedef enum	e_bool
{
	false = (1 == 0),
	true = (!false)
}				t_bool;

#endif
