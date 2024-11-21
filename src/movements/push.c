/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camarcos <camarcos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 17:42:05 by camarcos          #+#    #+#             */
/*   Updated: 2024/11/20 18:44:15 by camarcos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	push(t_stack *from, t_stack *to)
{
	t_node	*temp;

	if (from->size == 0)
		return ;
	temp = from->top;
	from->top = from->top->next;
	temp->next = to->top;
	to->top = temp;
	from->size--;
	to->size++;
}

void	pa(t_stack *a, t_stack *b)
{
	push(b, a);
}

void	pb(t_stack *a, t_stack *b)
{
	push(a, b);
}
