/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camarcos <camarcos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 17:42:32 by camarcos          #+#    #+#             */
/*   Updated: 2024/11/26 16:25:58 by camarcos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	reverse_rotate(t_stack *stack, int print, const char *move)
{
	t_node	*second_last;
	t_node	*last;

	if (stack->size < 2)
		return ;
	while (last->next)
	{
		second_last = last;
		last = last->next;
	}
	second_last->next = NULL;
	last->next = stack->top;
	stack->top = last;
	if (print)
		write(1, move, strlen(move));
}

void	rra(t_stack *a)
{
	reverse_rotate(a, 1, "rra\n");
}

void	rrb(t_stack *b)
{
	reverse_rotate(b, 1, "rrb\n");
}

void	rrr(t_stack *a, t_stack *b)
{
	reverse_rotate(a, 0, NULL);
	reverse_rotate(b, 0, NULL);
	write(1, "rrr\n", 4);
}
