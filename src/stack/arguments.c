/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arguments.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camarcos <camarcos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 11:55:24 by camarcos          #+#    #+#             */
/*   Updated: 2024/12/03 17:18:45 by camarcos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	sort_two(t_stack *a)
{
	if (a->top->value > a->top->next->value)
		sa(a);
}
//cuando hay solo dos argumentos

void	sort_three(t_stack *a)
{
	int	f;
	int	s;
	int	t;

	f = a->top->value;
	s = a->top->next->value;
	t = a->top->next->next->value;
	if (f > s && s < t && f < t)
		sa(a);
	else if (f > s && s > t)
	{
		sa(a);
		rra(a);
	}
	else if (f > s && s < t && f > t)
		ra(a);
	else if (f < s && s > t && f < t)
	{
		sa(a);
		ra(a);
	}
	else if (f < s && s > t && f > t)
		rra(a);
	//print_stack(a);				
}
//cuando hay tres argumentos

void	sort_small_stack(t_stack *a, t_stack *b)
{
    while (a->size > 3)
        pb(a, b);
    if (a->size == 3)
        sort_three(a);
    while (b->size > 0)
    {
        pa(a, b);
        if (a->top->value > a->top->next->value)
            sa(a);
    }
    if (a->size == 4)
    {
        if (a->top->value > a->top->next->value)
            sa(a);
        if (a->top->next->value > a->top->next->next->value)
        {
            ra(a);
            sa(a);
            rra(a);
        }
        if (a->top->value > a->top->next->value)
            sa(a);
    }
    else if (a->size == 5)
    {
        if (a->top->value > a->top->next->value)
            sa(a);
        if (a->top->next->value > a->top->next->next->value)
        {
            ra(a);
            sa(a);
            rra(a);
        }
        if (a->top->next->next->value > a->top->next->next->next->value)
        {
            ra(a);
            ra(a);
            sa(a);
            rra(a);
            rra(a);
        }
        if (a->top->value > a->top->next->value)
            sa(a);
    }
}
//para contolar con pocos argumentos

void	process_bits(t_stack *a, t_stack *b, int i)
{
	int	size;
	int	j;

	size = a->size;
	j = 0;
	while (j < size)
	{
		if (((a->top->value >> i) & 1) == 0)
			pb(a, b);
		else
			ra(a);
		j++;
	}
	while (b->size > 0)
		pa(a, b);
}
//verifica si el bit es 0 o 1 para cada número de A
//si el bit es 0 lo mueve a B y si es 1 lo deja en A

void	sort_large_stack(t_stack *a, t_stack *b)
{
	// int	max_num;
	// int	max_bits;
	//int	i;

	// max_num = find_max(a);
	// max_bits = calculate_max_bits(max_num);
	//i = 0;
	// while (i < max_bits)
	// {
		radix(a, b);
	// 	i++;
	// }
	//print_stack(a);
	if (!is_sorted(a))
		error_exit("Error: no se ordenó correctamente.\n");
}
//funcion principal
